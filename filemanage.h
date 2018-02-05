
using namespace std;
/// \file filemanage.h
/// \brief filemanage.h rassemble toutes les fonctions traitant de l'utilisation des flux
namespace
{
    /** \fn FileToVectUnsigned
     *  \author Marc Laporte Modifications : Yannick Gosset
	 *  \file filemanage.h
     *  \brief  FileToVectUnsigned convertit le contenu du fichier texte passé en paramètre, en un vecteur
     *          d'unsigned (le fichier txt doit contenir uniquement des chiffres.)
     */
    CVUInt_t FileToVectUnsigned (const string & FileName)
    {
         ifstream ifs (FileName);
         CVUInt_t VScore;
         for (string ScoreLine; getline (ifs, ScoreLine);)
             VScore.push_back(stoul(ScoreLine,nullptr,10));
         return VScore;
    }// FileToVectUnsigned()

    /** \fn FileToVectString
	 * \file filemanage.h
     *  \author Marc Laporte
     *  \brief FileToVectString convertit le contenu du fichier texte passé en paramètre, en un vecteur de string
     *        (le fichier txt doit contenir uniquement des chaines de caractères.)
     */
    CVString_t FileToVectString (const string & FileName)
    {
            ifstream ifs (FileName);
            CVString_t VString;
            for (string Line; getline (ifs, Line);)
                VString.push_back(Line);
            return VString;
    }// FileToVectString

    /** \fn EditVec
	 * \file filemanage.h
     * \author Marc Laporte Modifications : Yannick Gosset
     * \brief EditVec permet d'afficher le contenu d'un élément d'un vecteur
     */
    template <typename T>
    void EditVec (const vector<T> & VScore, const unsigned & Line)
    {
         cout <<VScore[Line]<<endl;
    }// EditVec()


    /** \fn VectToFile
	 * \file filemanage.h
     *  \author Marc Laporte
     *  \brief VectToFile permet de mettre le contenu d'un vecteur dans un fichier texte a raison d'un élément par ligne.
     */

    template <typename T>
    void VectToFile (const vector<T> & VScore, const string & FileName)
    {
        ofstream ofs (FileName);
        for (T Score : VScore)
            ofs << Score << endl;

    }// VectToFile()

    /** \fn DeleteLine
	 * \file filemanage.h
     *  \author Yannick Gosset
     *  \brief  DeleteLine supprime la ligne passée en paramètre dans le vecteur passé en paramètre,
     *          et redimmensionne le vecteur (réduction d'1 case)(Recupération TP SmallEditor)
     */
    void DeleteLine (CVUInt_t & VScore, unsigned LineNumber)
    {
        for (unsigned i = LineNumber - 1; i < VScore.size() - 1; ++i)
        {
            VScore[i] = VScore[i + 1];
        }
        VScore.pop_back();
    }// DeleteLine()


    /** \fn InsertLine
	 *  \file filemanage.h
     *  \author Yannick Gosset
     *  \brief InsertLine s'occupe d'insérer une ligne qu'on lui aura rentré en paramètre,
     *         à la postion et dans le vecteur rentré en paramètre (Recupération TP SmallEditor)
     */
    void InsertLine (CVUInt_t & VScore, unsigned LineNumber,
                     unsigned Score)
    {
        VScore.resize(VScore.size() + 1);
        for (unsigned i =  VScore.size() - 1 ; i> LineNumber - 1 && i != 0 ; --i)
        {
            VScore[i] = VScore[i-1];
        }
        VScore[LineNumber] = Score;

    }//InsertLine()

    /** \fn HighScore
	*   \file filemanage.h
    *   \author Yannick Gosset
    *   \brief HighScore affiche un tableau des 10 meilleurs scores stockés dans un fichier texte,
    *          si le score est apte a rentrer dans le fichier, il s'insère a la position a laquelle il devrait être.
    *   \bug Les scores affichés ne sont pas dépendants du niveau de difficulté
    */
    void HighScore(unsigned & Score)
    {

        string FileName = "../Fichier_texte/Score.txt";
        CVUInt_t VScore;
        VScore =  FileToVectUnsigned(FileName);
        unsigned Cpt = 0;
        for (unsigned i(0); i < VScore.size(); ++i)
        {
            if (Score > VScore[i])
            {
                 InsertLine (VScore, i, Score);
                 DeleteLine (VScore, VScore.size());
                 ++Cpt;
            }
            if (1 == Cpt)break;

        }
        for (unsigned i = 0; i < VScore.size(); ++i)
        {
            cout << i+1 << " : ";
            EditVec(VScore,i);
        }
        VectToFile(VScore, FileName);

    }//HighScore()

    /** \fn ShowFile
     *  \author Yannick Gosset
     * \brief ShowFile Tout comme highscore, s'occupe de l'affichage d un fichier texte, en le convertissant en un vecteur de string.
    */
    void ShowFile (const string & FileName)
    {
        CVString_t VString;
        VString = FileToVectString (FileName);
        unsigned Line = 0;
        for (string i : VString)
        {
            EditVec(VString,Line++);
        }


    } //ShowFile()

    /** \fn HomeScreen
	 * \file filemanage.h
     * \author Antoine Guillory
     * \brief HomeScreen affiche un Ascii art, c'est un écran d'acceuil
     */
    void HomeScreen(const string & FileName) // A appeler une fois au début
    {
        //ClearScreen();
        Couleur(KGreen);
        ShowFile (FileName);
        Couleur(KYellow);
        cout <<"SPACE INV."<< endl;
        cout <<" PRESS 5  "<< endl;
        char CaractHome;
        while (CaractHome != '5')
        {
            cin >> CaractHome;
            if ('5' != CaractHome)
                cout << "Wrong touch."<< endl;
        }
    } // HomeScreen()
}
