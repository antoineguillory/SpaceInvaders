
/// \file manage.h
/// \brief manage.h permet de gérer les joueurs et ce qui est à l'écran


using namespace std;
namespace
{
    unsigned GenerRandom(const unsigned & Min, const unsigned & Max)
    {
        srand (time(NULL));
        unsigned Random = rand() %(Max-Min) + Min;
        return Random;
    }// GenerRandom ()

    /** \fn DownShift
	  * \file manage.h
      * \author Tout le groupe
      * \brief DownShift permet de faire descendre l'envahisseur d'une ligne
      */

    void DownShift (CVString_t & Space, unsigned CurrentLine)
    {
        for (unsigned i =  Space.size() - 2 ; i> CurrentLine - 1
             && i != 0 ; --i)
        {
            Space[i] = Space[i-1];
            Space[i-1] = KEmptyLine;
        }
    } // DownShift()

    /** \fn IsDead
	 *  \file manage.h
     *  \author Tout le groupe
     * \brief IsDead vérifie si un joueur est mort
     */
    bool IsDead (const CVString_t & Space, const unsigned & Line,
                 unsigned Column, const char & Who)
    {
        if ((Space[Line][Column] == KInsideMe || Space[Line][Column] ==
             KInsideInvader) && Space[Line][Column] != Who)return true;
        else return false;
    } // IsDead()

    /** \fn Shoot
	 * \file manage.h
     * \author Tout le groupe
     * \brief Shoot positionne le tir
     */

    bool Shoot (CVString_t & Space, unsigned Line, unsigned Middle,
                const char & Projectile, char Who)
    {
        if (IsDead(Space, Line, Middle, Who))return true;
        Space [Line][Middle] = Projectile;

        return false;
    } // Shoot ()

    /** \fn ManageMe
	 *  \file manage.h
     *  \author Yannick Gosset
     *  \brief ManageMe permet de faire jouer le joueur.
     *         Il va choisir ce qu'il va faire.
     *  \bug Il faut toujours appuyer sur entrée après avoir fait une action
     */

    bool ManageMe (CVString_t & Space, Size_t & Pos, bool & Lost)
    {

        char Cel;
        cout << "Play!";
        cin >> Cel;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (Cel)
        {
          case KRight :
            if (Pos == Space.size()-1)
            {
                Pos = 0;
                Space[Space.size()-1][Pos] = KInsideMe;
                Space[Space.size()-1][Space.size()-1] = KEmpty;
            }
            else
            {
                Space[Space.size()-1][++Pos] = KInsideMe;
                Space[Space.size()-1][Pos - 1] = KEmpty;
            }
            break;
          case KLeft :
            if (Pos == 0)
            {
                Pos = Space.size()-1;
                Space[Space.size()-1][Pos] = KInsideMe;
                Space[Space.size()-1][0] = KEmpty;
            }
            else
            {
                Space[Space.size()-1][--Pos] = KInsideMe;
                Space[Space.size()-1][Pos + 1] = KEmpty;
            }
            break;
          case KShoot :
            if (PokemonMode)
                Shoot(Space, Space.size()-2, Pos, KPokeball,KInsideMe);
            else
                Shoot(Space, Space.size()-2, Pos, KTorpedo,KInsideMe);
                break;
        } // switch

        if (Shoot(Space, 9, Pos, KMissile, KInsideInvader))
        {
            BegMe = Pos;
            Lost = false;
            return Lost;
        }

    } // ManageMe()

    /** \fn ManageInvader
	 *  \file manage.h
     * \author Marc Laporte Modifications : Axel Houlès Jérôme Malaval
     * \brief  ManageInvader permet de faire jouer l'envahisseur
     * \bug Si un tir se trouve a coté d'un ennemi au moment ou celui ci doit se déplacer il
     *      descend d'une ligne au lieu de se déplacer horizontalement
     */

    bool ManageInvader (int & Increment, Size_t & CurrentLine,
                           Size_t & Beg, bool & ToShoot,
                           bool & Win, CVString_t & Space)
    {

       if ((Increment > 0 &&
              (Beg + InvadersSize == KSizeLine ||
               Space [CurrentLine][Beg + InvadersSize] != KEmpty))
          ||
           (Increment < 0 &&
              (Beg  == 0 ||
               Space [CurrentLine][Beg - 1] != KEmpty)))
       {
           ++CurrentLine;
           for (Size_t j (Beg); j < Beg + InvadersSize; ++j)
           {
               if (KTorpedo == Space [CurrentLine][j])
               {
                   Win = true;
                   Space [CurrentLine] = KEmptyLine;
                   return false;
               }
           }

           Increment *= -1;
           DownShift (Space, CurrentLine);
           if (Space.size () - 1 <= CurrentLine)
               return true;
       }
       else
       {
           for (unsigned i = 0; i < InvaderLNB; ++i)
           {
               string ToShift (Space [CurrentLine + i].
                                 substr (Increment > 0 ? 0 : 1,
                                         KSizeLine - 1));
               Space [CurrentLine + i] = (Increment > 0) ? ' ' + ToShift
                                 : ToShift + ' ';

           }
       }
       Beg +=Increment;
       ToShoot = true;
       srand (time(NULL));
       unsigned Random = rand() %(1- 0) + 0;


       if (ToShoot)
       {
           return Shoot (Space, CurrentLine +InvaderLNB,
                         Beg + KInvadersMiddle + Random, KMissile, KInsideInvader);
       }

       return false;

    } // ManageInvaders()

    /** \fn Victoire
	 * \file manage.h
     * \author Rachel Glaise
     * \brief Victoire parcourt la grille en cherchant des ennemis.
     *       renvoie true si aucun ennemi n'est trouvé
     */
    bool Victoire(const CVString_t & Space)
    {
        unsigned Cpt = 0;
        for (Size_t i (0); i < KSizeSpace; ++i)
        {
            for (Size_t j (0); j < KSizeLine; ++j)
            {
                if (KInsideInvader == Space [i][j])
                    ++Cpt;
            }
        }
        if (Cpt == 0) return true;
    } //Victoire


}
