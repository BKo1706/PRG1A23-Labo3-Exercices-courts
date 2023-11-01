#include <iostream>

using namespace std;

// écrire la fonction sous_chaine(str,pos,len) qui
// retourne la sous-chaine de la chaine str qui commence
// a l'indice pos et compte len caractères. Si la longueur
// demandée est trop longue et dépasse de la chaine str,
// seule la partie de l'indice pos à la fin est retournée
//
// Vous pouvez uniquement utiliser la méthode length() et les
// opérateurs [] et += de la classe string.

string sous_chaine(string str, int pos, int len){
    string s_c;
    char c = str[pos];
    if (pos > str.length()){
        s_c = "";
        return s_c;
    }
    if (len > str.length()) {
        len = str.length() - pos;
    }
    for(int i = 0; i < len; ++i ){
        char c1 = str[pos+i];
        s_c += c1;
    }
    return s_c;
}
int main() {

   cout << sous_chaine("hello",1,3) << endl;
   // affiche ell

   cout << sous_chaine("abcdef",3,2) << endl;
   // affiche de

   cout << sous_chaine("abcdef",2,7) << endl;
   // affiche cdef

   cout << sous_chaine("abcdef",20,7) << endl;
   // affiche une chaine vide
}