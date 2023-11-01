#include <iostream>

using namespace std;

// écrire la fonction plus_petite_lettre(str) qui retourne
// le plus petite caractère (au sens du code ASCII) de la chaine
// str. Si cette lettre apparait plusieurs fois c'est la
// dernière instance qui doit être retournée.
char& plus_petite_lettre(string& str){
    int pos_ppl = 0;
    for (int i = 0; i < str.length(); ++i){
        str[i];
        if(str[i] <= str[pos_ppl]){
            pos_ppl = i;
        }
    }
    return str[pos_ppl];
}
int main() {

   string s{"wisigoth"};
   plus_petite_lettre(s) = '*';
   cout << s << endl;
   // affiche wisi*oth

   s = "abraracourcix";
   plus_petite_lettre(s) = '*';
   cout << s << endl;
   // affiche abrar*courcix
}