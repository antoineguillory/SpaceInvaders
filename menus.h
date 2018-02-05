

using namespace std;
/// \file menu.h
/// \brief menu.h regroupe les différents menus
namespace
{
    /** \fn Level
	 * \file menus.h
     * \author Antoine Guillory Modifications : Axel Houlès
     * \brief Level permet d'afficher un menu permettant de choisir la difficulté
     */
    void Level()
    {
       Couleur(KGreen);
       cout << "1. Easy" <<endl;
       Couleur(KCyan);
       cout << "2. Normal" <<endl;
       Couleur(KYellow);
       cout << "3. Hard" <<endl;
       Couleur(KRed);
       Couleur(KClignote);
       cout << "666. HELL" <<endl;
       Couleur(KReset);
       cout << "Votre choix : ";
       unsigned ChoixJoueur;
       while ((ChoixJoueur != 1) && (ChoixJoueur != 2) && (ChoixJoueur != 3) &&
              (ChoixJoueur != 4) && (ChoixJoueur != 666) )
       {
           cin >> ChoixJoueur;
           if (ChoixJoueur > 5)
           {
               cout << endl << "Rentrez une valeur Comprise entre";
               Couleur(KRed);
               Couleur(KClignote);
               cout << " 1 ET 3 (OU 666) !"<<endl;
               Couleur(KReset);
           }
       }
       switch(ChoixJoueur)
       {
           case 1:
             Difficulty = 1;
             break;
           case 2:
             Difficulty = 2;
             break;
           case 3:
             Difficulty = 3;
             break;
           case 666:
             Difficulty = 4;
             InvadersSize = 5;

             InvaderLNB = 4;
             break;
           default:
             cout << endl << "Erreur..." << endl;

       }
    } //Level

    /** \fn Menu
	 * \file space.h
     *  \author Rachel Glaise Antoine Guillory Modifications : Axel Houlès Idée:Jérôme Malaval
     *  \brief Menu affiche des menus pour parametrer le jeu
     */
    void Menu (string & MyColor, string & InvadersColor,  string & BackColor, bool & StopVal)
    {

       char ChoixMenu;
       string MainFile = "../Fichier_texte/MainMenu.txt";
       string ModeFile = "../Fichier_texte/MenuMode.txt";
       string SetFile = "../Fichier_texte/SetMenu.txt";
       for (;;)
       {
           ClearScreen();
           ShowFile(MainFile);
           cout << "  > Your choice :";

           cin  >> ChoixMenu;
           if (ChoixMenu == 'c'  || ChoixMenu == 'C' ) break;

           while ((ChoixMenu != 'a') && (ChoixMenu != 'b') &&
                  (ChoixMenu != 'c') && (ChoixMenu != 'd') &&
                  (ChoixMenu != 'A') && (ChoixMenu != 'B') &&
                  (ChoixMenu != 'C') && (ChoixMenu != 'D'))
           {
               cout << endl << "It's not an available choice." << endl;
               cout << "  > Your choice : ";
               cin  >> ChoixMenu;
           }
           ClearScreen();
           switch (ChoixMenu)
           {
               case 'A' : case 'a' :
                 char ChoixMode;
                 ShowFile(ModeFile);
                 cout << "  > Your choice : ";
                 cin  >> ChoixMode;
                 cin.ignore(numeric_limits<streamsize>::max(), '\n');
                 while ((ChoixMode != '1') && (ChoixMode != '2') && (ChoixMode != '3'))
                 {
                     cout << endl << "It's not an available choice." << endl;
                     cout << "  > Your choice : ";
                     cin  >> ChoixMode;
                 }
                 switch (ChoixMode)
                 {
                   case '1' :
                     ArcadeMode = true;
                     EliminationMode = false;
                     Level();
                     break;
                   case '2':
                     EliminationMode = true;
                     ArcadeMode = false;
                     Level();
                     break;
                   case '3':
                     PokemonMode = true;
                     EliminationMode = false;
                     ArcadeMode = false;
                     Level();
                     break;
                   default :
                     cout << "Wrong choice." << endl;
                     break;

                 } // switch ChoixMode
               break;

               case 'B' :case 'b' :
               char ChoixParam;
               ShowFile(SetFile);
               cout << "  > Your choice : ";
               cin  >> ChoixParam ;
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
               while (ChoixParam != '1' && ChoixParam != '2' &&
                      ChoixParam != '3' )
               {
                   cout << endl << " Wrong choice." << endl;
                   cout << "  > Your choice: ";
                   cin  >> ChoixParam ;
               }

               switch (ChoixParam)
               {
                 case '1':
                   char Choix;
                   ClearScreen();
                   cout << " B A C K G R O U N D    C O L O R" << endl
                        << " ___________________________ " << endl
                        << "|\033[" << KReset   <<"m"<< "1. Black                    "<< "\033[" <<KReset  <<"m" << "|" << endl
                        << "|\033[" << KRed     <<"m"<< "2. Red                      "<< "\033[" <<KReset  <<"m" << "|" << endl
                        << "|\033[" << KGreen   <<"m"<< "3. Green                    "<< "\033[" <<KReset  <<"m" << "|" << endl
                        << "|\033[" << KYellow  <<"m"<< "4. Yellow                   "<< "\033[" <<KReset  <<"m" << "|" << endl
                        << "|\033[" << KBlue    <<"m"<< "5. Blue                     "<< "\033[" <<KReset  <<"m" << "|" << endl
                        << "|\033[" << KMagenta <<"m"<< "6. Magenta                  "<< "\033[" <<KReset  <<"m" << "|" << endl
                        << "|\033[" << KCyan    <<"m"<< "7. Cyan                     "<< "\033[" <<KReset  <<"m" << "|" << endl
                        << "|___________________________|\033[" <<KReset  <<"m" << endl;
                   cin >> Choix;
                   cin.ignore(numeric_limits<streamsize>::max(), '\n');
                   switch (Choix)
                   {
                     case '1' :
                       BackColor = KBackBlack;
                       break;
                     case '2' :
                       BackColor = KBackRed;
                       break;
                     case '3' :
                       BackColor = KBackGreen;
                       break;
                     case '4' :
                       BackColor = KBackYellow;
                       break;
                     case '5' :
                       BackColor = KBackBlue;
                       break;
                     case '6' :
                       BackColor = KBackMagenta;
                       break;
                     case '7' :
                       BackColor = KBackCyan;
                       break;
                      default :
                       cout << "Wrong choice" << endl;
                       break;
                   }
                   break;

                 case '2':
                   char ChoixM;
                   ClearScreen();
                   cout << "If you choose the same color as the "
                        << "background, it won't be allowed." << endl;
                   cout << " P L A Y E R    C O L O R" << endl
                        << " ___________________________ " << endl
                        << "|\033[" << KReset   <<"m"<< "1. Black                    "<< "\033[" <<KReset  <<"m" << "|" << endl
                        << "|\033[" << KRed     <<"m"<< "2. Red                      "<< "\033[" <<KReset  <<"m" << "|" << endl
                        << "|\033[" << KGreen   <<"m"<< "3. Green                    "<< "\033[" <<KReset  <<"m" << "|" << endl
                        << "|\033[" << KYellow  <<"m"<< "4. Yellow                   "<< "\033[" <<KReset  <<"m" << "|" << endl
                        << "|\033[" << KBlue    <<"m"<< "5. Blue                     "<< "\033[" <<KReset  <<"m" << "|" << endl
                        << "|\033[" << KMagenta <<"m"<< "6. Magenta                  "<< "\033[" <<KReset  <<"m" << "|" << endl
                        << "|\033[" << KCyan    <<"m"<< "7. Cyan                     "<< "\033[" <<KReset  <<"m" << "|" << endl
                        << "|___________________________|\033[" <<KReset  <<"m" << endl;
                   cin >> ChoixM;
                   cin.ignore(numeric_limits<streamsize>::max(), '\n');
                   switch (ChoixM)
                   {
                     case '1' :
                       if (Choix == ChoixM) break;
                       MyColor = KBlack;
                       break;
                     case '2' :
                       if (Choix == ChoixM) break;
                       MyColor = KRed;
                       break;
                     case '3' :
                       if (Choix == ChoixM) break;
                       MyColor = KGreen;
                       break;
                     case '4' :
                       if (Choix == ChoixM) break;
                       MyColor = KYellow;
                       break;
                     case '5' :
                       if (Choix == ChoixM) break;
                       MyColor = KBlue;
                       break;
                     case '6' :
                       if (Choix == ChoixM) break;
                       MyColor = KMagenta;
                       break;
                     case '7' :
                       if (Choix == ChoixM) break;
                       MyColor = KCyan;
                       break;
                    default :
                       cout << "Wrong choice" << endl;
                       break;
                   }
                   break;
                 case '3' :
                   char ChoixI;
                   ClearScreen();
                   cout << "If you choose the same color as the "
                        << "background, it won't be allowed." << endl;
                   cout << " E N N E M I S      C O L O R S" << endl
                        << " ___________________________ " << endl
                        << "|\033[" << KReset   <<"m"<< "1. Black                    "<< "\033[" <<KReset  <<"m" << "|" << endl
                        << "|\033[" << KRed     <<"m"<< "2. Red                      "<< "\033[" <<KReset  <<"m" << "|" << endl
                        << "|\033[" << KGreen   <<"m"<< "3. Green                    "<< "\033[" <<KReset  <<"m" << "|" << endl
                        << "|\033[" << KYellow  <<"m"<< "4. Yellow                   "<< "\033[" <<KReset  <<"m" << "|" << endl
                        << "|\033[" << KBlue    <<"m"<< "5. Blue                     "<< "\033[" <<KReset  <<"m" << "|" << endl
                        << "|\033[" << KMagenta <<"m"<< "6. Magenta                  "<< "\033[" <<KReset  <<"m" << "|" << endl
                        << "|\033[" << KCyan    <<"m"<< "7. Cyan                     "<< "\033[" <<KReset  <<"m" << "|" << endl
                        << "|___________________________|\033["                          <<KReset<<   "m"   << endl;
                   cin >> ChoixI;
                   cin.ignore(numeric_limits<streamsize>::max(), '\n');
                   switch (ChoixI)
                  {
                    case '1' :
                      if (Choix == ChoixI) break;
                      InvadersColor = KBlack;
                      break;
                    case '2' :
                      if (Choix == ChoixI) break;
                      InvadersColor = KRed;
                      break;
                    case '3' :
                      if (Choix == ChoixI) break;
                      InvadersColor = KGreen;
                      break;
                    case '4' :
                      if (Choix == ChoixI) break;
                      InvadersColor = KYellow;
                      break;
                    case '5' :
                      if (Choix == ChoixI) break;
                      InvadersColor = KBlue;
                      break;
                    case '6' :
                      if (Choix == ChoixI) break;
                      InvadersColor = KMagenta;
                      break;
                    case '7' :
                      if (Choix == ChoixI) break;
                      InvadersColor = KCyan;
                      break;
                    default :
                      cout << "Wrong choice" << endl;
                      break;
                  }
                   break;
                 default :
                   cout << "Wrong choice." <<endl;
                   break;
              }
              break;

               case 'C' : case 'c' :
                 break;


               case 'D' : case 'd' :

                 break;

               default :
                  cout << "Wrong choice." << endl;
            } // Switch ChoixMenu
        } // for not play
    } // Menu
}
