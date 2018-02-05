
/// \file const.h
/// \brief const.h déclare les constantes du programme
using namespace std;

namespace
{
    typedef vector <string> CVString_t;
                // c'est le type de l'écran (l'espace, la matrice)
    typedef vector <unsigned> CVUInt_t;
    typedef CVString_t::size_type Size_t;
    const string KBackReset   ("0");
    const string KBackBlack   ("40");
    const string KBackRed     ("41");
    const string KBackGreen   ("42");
    const string KBackYellow  ("43");
    const string KBackBlue    ("44");
    const string KBackMagenta ("45");
    const string KBackCyan    ("46");

    const string KReset   ("0");
    const string KBlack   ("30");
    const string KRed     ("31");
    const string KGreen   ("32");
    const string KYellow  ("33");
    const string KBlue    ("34");
    const string KMagenta ("35");
    const string KCyan    ("36");
    const string KClignote ("5");

    const char KEmpty      = ' ';  // case vide de l'écran
    const char KRight      = '6';  // déplacement vers la droite
    const char KLeft       = '4';  // Déplacement vers la gauche
    const char KShoot      = '5';  // Lancé de torpille

    const char KInsideInvader   = 'W';  // caractèrere de l'envahisseur
    const char KMissile         = 'T';  // missile

    const string KMyColor (KGreen);
    const char KInsideMe            = 'A';
    const char KTorpedo             = '|';


    // Constantes liées au joueur

    const unsigned KMySize          = 1;
    const unsigned KMyMiddle        = KMySize / 2;
    const string KMyForm (KMySize, KInsideMe);


    const unsigned KSizeLine   = 10;   // Nombre de lignes de l'écran
    const unsigned KSizeSpace  = 10;   // Nombre de colonnes de l'écran
    const unsigned KBegInvader = 0;    // Numéro de colonne où commence
                                       //l'envahisseur

    // Constantes liées à l'espace
    const string KEmptyLine (KSizeLine, KEmpty);  // Une ligne vide de la matrice

    // Constantes liées au mode de jeu pokémon

    const char KInsidePokemon = 'M';
    const char KPokeball = 'o';
    //  Constantes liées à l'envahisseur


    unsigned InvaderLNB         = 2;
    unsigned InvadersSize       = 4;   // nombre de caractères
                                       //qui forment l'envahisseur
    unsigned KInvadersMiddle  = InvadersSize / 2;



    // Constantes liées à l'espace (l'écran)

    unsigned BegMe             = KSizeLine / 2;  // Numéro de colonne
                                                 //où commence le joueur



    unsigned RatioMeInvaders = 3;    // Nombre de fois où c'est le tour du joueur pour un tour de l'envahisseur

    // Constantes liées au mode de jeu
    bool ArcadeMode = false;
    bool EliminationMode = false;
    bool PokemonMode = false;
    unsigned Wave = 0;
    unsigned Difficulty = 0;

}
