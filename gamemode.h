
using namespace std;
/// \file gamemode.h
/// \brief gamemode.h contient les deux fonctions traitant des différents modes de jeu
namespace
{
    /** \fn ArcadeFunction
	 * \file gamemode.h
     * \author Antoine Guillory
     * \brief ArcadeFunction fait en sorte que l'on ajoute tout les certains nombre
     *        de vagues, en fonction de la difficulté, on ajoute soit une ligne d'envahisseur, un envahisseur par colonne, un tour d'envahisseur.
     */
    void ArcadeFunction (unsigned Wave)
    {
        if (Difficulty == 1)
        {
            if (Wave % 13 == 0 && Wave != 1 && Wave !=0 && InvaderLNB < 6)
            {
                ++InvaderLNB;
            }
            if (Wave % 9 == 0 && Wave != 1 && Wave !=0 && InvadersSize < 7)
            {
                ++InvadersSize;
                --RatioMeInvaders;
            }

            ++Wave;
        }
        if (Difficulty == 2)
        {
            if (Wave % 5 == 0 && Wave != 1 && Wave !=0 && InvaderLNB < 6)
            {
                ++InvaderLNB;
            }
            if (Wave % 5 == 0 && Wave != 1 && Wave !=0 && InvadersSize < 7)
            {
                ++InvadersSize;
                --RatioMeInvaders;
            }

            ++Wave;
        }
        if (Difficulty == 3)
        {

            if (Wave % 3 == 0 && Wave != 1 && Wave !=0 && InvaderLNB < 6)
            {
                ++InvaderLNB;
            }
            if (Wave % 3 == 0 && Wave != 1 && Wave !=0 && InvadersSize < 7)
            {
                ++InvadersSize;
                --RatioMeInvaders;
            }

            ++Wave;
        }
        if (Difficulty == 4)
        {
            if (Wave % 1 == 0 && Wave != 1 && Wave !=0 && InvaderLNB < 6)
            {
                ++InvaderLNB;
            }
            if (Wave % 2 == 0 && Wave != 1 && Wave !=0 && InvadersSize < 7)
            {
                ++InvadersSize;
                --RatioMeInvaders;
            }

            ++Wave;
        }

    } //Arcade Function()

    /** \fn EliminationFunction
	 * \file gamemode.h
     * \author Antoine Guillory
     * \brief EliminationFunction permet de ne génerer qu'une seule vague
     *        d'ennemis
     */
    void EliminationFunction ()
    {
        if (Difficulty == 1)
        {
            InvaderLNB = 2;
            InvadersSize = 4;
            RatioMeInvaders = 4;
        }
        if (Difficulty == 2)
        {
            InvaderLNB = 3;
            InvadersSize = 4;
            RatioMeInvaders = 3;
        }
        if (Difficulty == 3)
        {
            InvaderLNB = 5;
            InvadersSize = 5;
            RatioMeInvaders = 2;
        }
        if (Difficulty == 4)
        {
            InvaderLNB = 5;
            InvadersSize = 6;
            RatioMeInvaders = 1;
        }


    } //EliminationFunction()



}
