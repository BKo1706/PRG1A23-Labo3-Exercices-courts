#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// écrire une fonction caractere_le_plus_frequent(string const& filename)
// qui retourne une structure ou une paire (voir chapitre 7) qui
// contient le caractère (hors espace ' ') le plus fréquent dans ce fichier,
// ainsi que le nombre de fois qu'il apparait. Ce nombre est négatif
// si le fichier est illisible.
int nb_char_in_file(string const& filename, char c) {
    ifstream file(filename);
    int cnt{};
    char d;
    while(file.get(d))
        if(c == d)
            ++cnt;
    return cnt;
}
pair<char, int>caractere_le_plus_frequent(string const& filename){
    ifstream file(filename);
    if (!file)
        return {0, -1};
    char r = -1;
    int cnt_r = 0;
    for (int c = 0 ; c < 256; ++c){
        if(c == 32) continue;
        int cnt_c = nb_char_in_file(filename, c);
        if (cnt_c > cnt_r){
            cnt_r = cnt_c;
            r = c;
        }
    }
    return{r, cnt_r};
}

int main() {
    ofstream file_out("test.txt", ios::out);
    file_out << "premiere ligne avec c comme test\n";
    file_out.close();
   cout << "Entrez le nom du fichier : " << flush;
   string filename;
   cin >> filename;

   auto [c, n] = caractere_le_plus_frequent(filename);
   if (n >= 0)
      cout << "Le caractère " << c
           << " est le plus fréquent et apparait " << n
           << " fois dans le fichier " << filename << endl;
   else
      cout << "Le fichier est illisible";
}