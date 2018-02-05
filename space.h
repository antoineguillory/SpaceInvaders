
using namespace std;
/// \file space.h
/// \brief space.h gère l'affichage
namespace
{
    /** \fn InitSpace
	 * \file space.h
     * \author Axel Houlès
     * \brief InitSpace Initialise la matrice
     */

    void InitSpace (CVString_t & Space)
    {
        string KInvadersForm (InvadersSize, KInsideInvader);  // forme de l'envahisseur

            for (unsigned i = 0; i < InvaderLNB; ++i)
            {
                Space [i] = KEmptyLine.substr (0, KBegInvader) +
                        KInvadersForm + KEmptyLine.substr
                        (0,KSizeLine - KBegInvader  - InvadersSize);
            }
            Space [Space.size () - 1] = KEmptyLine.substr (0, BegMe)
                                        + KMyForm + KEmptyLine.substr
                                        (0, KSizeLine-BegMe-KMySize);

    } // InitSpace()

    void ClearScreen ()
    {
        cout << "\033[H\033[2J";
    }//ClearScreen

    void ChangeFond (const string & coul)
    {
        cout << "\033[" << coul <<"m";
    }



    void Couleur (const string & coul)
    {
        cout << "\033[" << coul <<"m";
    }//Couleur

    /** \fn DisplaySpace
    * \author Tout le groupe
	* \file space.h
    * \brief DisplaySpace Affiche la matrice
    *		     avec les positions par défaut du joueur / envahisseur
    */
    void  DisplaySpace (const CVString_t & Space,
                        const string CouleurFond,
                        const string & KMyColor,
                        const string & KInvadersColor,
                        const unsigned & Score)
    {
        ClearScreen();
        for (const string & ALine : Space) //lignes
        {
            cout << '|';
            for (char Cel : ALine) //colonnes
            {

                switch (Cel)
                {
                  case KInsideMe :
                    ChangeFond(CouleurFond);
                    Couleur(KMyColor);
                    cout << setw(2)<< Cel;
                    break;
                  case KInsidePokemon :
                    ChangeFond(CouleurFond);
                    Couleur(KYellow);
                    cout << setw(2) << Cel;
                    break;
                  case KPokeball :
                    ChangeFond(CouleurFond);
                    Couleur(KRed);
                    cout << setw(2) << Cel;
                    break;
                  case KTorpedo :
                    ChangeFond(CouleurFond);
                    Couleur(KMyColor);
                    cout << setw(2)<< Cel;
                    break;
                  case KInsideInvader :
                    ChangeFond(CouleurFond);
                    Couleur(KInvadersColor);
                    cout << setw(2)<< Cel;
                    break;
                  case KMissile :
                    ChangeFond(CouleurFond);
                    Couleur(KInvadersColor);
                    cout << setw(2)<< Cel;
                    break;
                  case KEmpty :
                    ChangeFond(CouleurFond);
                    cout << setw(2)<< Cel;
                    break;
                  default :
                    ChangeFond(CouleurFond);
                    cout << setw(2) << ' ';
                } // switch
            } // for
            Couleur(KReset);
            cout << '|';
            cout << endl;
        } // for
        cout << "Difficulty : " << Difficulty << endl;
        cout << "Your score : " << Score << endl;
        if (ArcadeMode)
            cout << "Current Wave : " << Wave + 1 << endl;
    } // DisplaySpace

    /** \fn Remove
	 * \file space.h
     * \author Rachel Glaise Jérôme Malaval
     * \brief Remove permet de supprimer les envahisseurs quand ils meurent
     */

    void Remove (CVString_t & Space, const unsigned & Line, const unsigned & Column)
    {
        Space[Line][Column] = KEmpty;
    } //Remove ()

    /** \fn RecomputeSpace
	 * \file space.h
     * \author Marc Laporte Modifications : Jérôme Malaval Rachel Glaise
     * \brief RecomputeSpace permet de faire progresser les tirs
     * \bug Lorsque un missile et une torpille se rencontrent, un seul des deux disparaît au lieu du missile.
     *      La torpille part une case trop haut
     *	    Le tir du joueur se décale de temps en temps (si le joueur "spamme" le tir)
     */

    void RecomputeSpace (CVString_t & Space, bool & Win, bool & Lost, unsigned & Score)
       {
           for (Size_t i (0); i < KSizeSpace; ++i)
           {
               for (Size_t j (0); j < KSizeLine; ++j)
               {
                   if (KTorpedo == Space [i][j] || KPokeball == Space [i][j])
                   {

                       if (i != 0)
                       {
                           if (KInsideInvader == Space [i-1][j])
                           {

                               if (PokemonMode)
                               {
                                   for (unsigned k = 1; k < KSizeLine; ++k)
                                   {
                                       if(Space[Space.size() - 3][k] == KEmpty)
                                       {
                                           Space[Space.size() - 3][k] = 'M';
                                           break;
                                       }
                                   }



                                   Remove (Space, i -1, j);
                               }
                               else
                               {
                                   Remove (Space, i -1, j);
                               }
                               Win = true;
                               Score = Score + 10;
                           }
                           else if (KMissile == Space [i - 1][j])
                           {
                               Space [i - 1][j] = KMissile;
                           }
                           else
                           {
                               if(PokemonMode)
                                   Space [i - 1][j] = KPokeball;
                               else
                                   Space [i - 1][j] = KTorpedo;
                           }
                           Space [i][j]     = KEmpty;
                       }
                       else
                       {
                           Space [i][j] = KEmpty;
                       }
                   }
                   else if (KMissile == Space [i][j])
                   {
                       /* le probleme est de ne pas faire avancer le missile de plus d'un */
                       if (i != KSizeSpace - 1)
                       {

                           if (KInsideMe == Space [i + 1][j])
                           {
                               Remove (Space, i +1, j);
                               Lost = true;
                               Space [i][j]     = KEmpty;
                           }

                           else if (KTorpedo == Space [i + 1][j] || KPokeball == Space [i + 1][j] )
                           {
                               Space [i + 1][j] = KEmpty;
                               Space [i][j]     = KEmpty;
                           }
                           else
                           {
                               if (i > 0 && KMissile == Space[i - 1][j])
                               {
                                   Space [i - 1][j] = KEmpty;
                               }
                               else if(Space[i + 1][j] == KInsidePokemon)
                               {
                                   Space [i][j] = KEmpty;
                                   Space [i + 1][j] = KEmpty;
                               }
                               else
                               {
                                   Space [i + 1][j] = KMissile;
                               }
                           }
                       }
                       else if (KMissile == Space [i - 1][j])
                       {
                           Space [i - 1][j] = KEmpty;
                       }
                       else
                       {
                           Space [i][j] = KEmpty;
                       }
                   }

               }
           }
       } // RecomputeSpace()

}
