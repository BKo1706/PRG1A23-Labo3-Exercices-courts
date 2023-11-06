#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// écrire une fonction nb_char_in_file(filename, c) qui compte le nombre
// de fois que la caractère c apparait dans le fichier. Il doit retourner
// une valeur négative en cas d'impossibilité d'ouvrir le fichier
int nb_char_in_file(string const& filename, int c){
    ifstream file(filename);
    if (!file)
        return -1;
    int cnt = 0;
    char d;
    while(file.get(d)){
        if(d==c)
            ++cnt;
    }
    return cnt;
}
int main() {
    ofstream file_out("test.txt", ios::out);
    file_out << "premiere ligne avec c comme test\n";
    file_out.close();
   cout << "Entrez le nom du fichier : " << flush;
   string filename; cin >> filename;
   cout << "Entrez le caractère : " << flush;
   char c; cin >> c;

   auto n = nb_char_in_file(filename,c);
   if(n >= 0)
      cout << "Le fichier contient " << n << " fois le caractère " << c << endl;
   else
      cout << "Le fichier est illisible";
}