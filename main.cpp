
/// \file main.cpp
/// \brief main.cpp est le programme principal
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <limits>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "const.h"
#include "manage.h"
#include "space.h"
#include "filemanage.h"
#include "menus.h"
#include "gamemode.h"


using namespace std;



namespace
{
    /** \fn SpaceInvader
	 * \file main.cpp
     * \author Antoine Guillory Modifications : Axel Houlès
     * \brief SpaceInvaders est le programme principal qui appelle les
     *        autres fonctions.
     */
    void SpaceInvaders ()
    {
        string MyColor = KGreen;
        string InvadersColor = KYellow;
        string BackColor = KBlack;
        string NameFile = "../Fichier_texte/HomeScreen.txt";
        bool Quit = true;
        HomeScreen(NameFile);
        Couleur(KReset);
        Menu (MyColor, InvadersColor, BackColor, Quit);
        unsigned Score = 0;

        for(;;)
        {
            if(EliminationMode)
                EliminationFunction();
            CVString_t Space (KSizeSpace, KEmptyLine);
            //  Initialisation of Space

            int Direction = 1;
            Size_t CurrentLine (0);
            Size_t PosInvader (KBegInvader);
            Size_t PosMe      (BegMe);


            bool IWin           = false;
            bool ILoose         = false;
            bool InvadersShoots = false;
            InitSpace(Space);

            DisplaySpace (Space, BackColor, MyColor, InvadersColor, Score);
            string Exit;

            for (;;)
            {
                for (unsigned i (max (1u, RatioMeInvaders)); i-- > 0; )
                {
                    if (!ManageMe (Space, PosMe, ILoose) && ! ILoose)
                    {
                        RecomputeSpace (Space, IWin, ILoose, Score);

                    }

                    DisplaySpace (Space, BackColor, MyColor, InvadersColor,
                                  Score);


                    if (ILoose || Victoire(Space)) break;
                }
                if (ILoose|| Victoire(Space)) break;
                ILoose = ManageInvader (Direction, CurrentLine, PosInvader,
                                        InvadersShoots, IWin, Space);
                if (! Victoire(Space) && ! ILoose)
                    RecomputeSpace (Space, IWin, ILoose, Score);

                DisplaySpace (Space, BackColor, MyColor, InvadersColor,
                              Score);

                if (ILoose || Victoire(Space)) break;


            }
            Couleur(KReset);
            ClearScreen();

            string Str;
            if (Victoire(Space) && ArcadeMode)
            {
                ArcadeFunction(Wave);
                ++Wave;
                Score = Score +10;
                continue;
            }
            else if (Victoire(Space) && EliminationMode)
            {
                Str = "../Fichier_texte/EcranWin.txt";
                ShowFile(Str);
                Score = 0;
                Wave = 0;
                HighScore(Score);

            }
            else if(ILoose)
            {
                cout<<"You have : "<< Score  << " points." << endl;
                cout << "You survived : " << Wave << " waves." << endl;
                Str = "../Fichier_texte/EcranLose.txt";
                ShowFile(Str);
                cout <<"\nBest Scores" << endl;
                HighScore(Score);
                Score = 0;
                BegMe = KSizeLine / 2;
                RatioMeInvaders = 3;
                Wave = 0;
                InvadersSize = 4;
                InvaderLNB = 2;
            }
            cin >> Exit; //Pour rejouer
            if (Exit == "yes" || Exit == "YES") continue;
            if (Exit == "no" ||Exit == "NO") break;
            {
                Score = 0;
                BegMe = KSizeLine / 2;
                RatioMeInvaders = 3;
                InvadersSize = 4;
                InvaderLNB = 2;
                Menu (MyColor, InvadersColor, BackColor, Quit);
            }
            if (Quit) break;
        }//for entier

    } // SpaceInvaders()
}
int main ()
{
    SpaceInvaders();
    return 0;


}
