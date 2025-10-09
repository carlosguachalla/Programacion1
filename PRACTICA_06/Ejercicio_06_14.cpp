// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 8/10/2025
// Número de ejercicio: 14
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cout << "Ingrese texto: ";
    getline(cin, s);
    int a=0,e=0,i=0,o=0,u=0;
    for (int k = 0; k < s.size(); k++) {//verifica las vocales y depencdiendo de cual encuentre se suma 
        char c = tolower(s[k]);
        if (c == 'a') a++;
        if (c == 'e') e++;
        if (c == 'i') i++;
        if (c == 'o') o++;
        if (c == 'u') u++;
    }
    cout << "a: " << a << endl;
    cout << "e: " << e << endl;
    cout << "i: " << i << endl;
    cout << "o: " << o << endl;
    cout << "u: " << u << endl;
}