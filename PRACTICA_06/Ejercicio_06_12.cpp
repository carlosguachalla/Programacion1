// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 8/10/2025
// Número de ejercicio: 12
#include <iostream>
#include <string>
using namespace std;
bool esPalindromo(string texto) {
    string limpio="";
    int i, fin, inicio;
    for(i=0;i<texto.size();i++){
        if(texto[i] != ' '){
            if(texto[i] >= 'A' && texto[i] <= 'Z'){
                limpio += texto[i] + 32; // convertir a minúscula
            } else {
                limpio += texto[i];
            }
        }
    }
    fin=limpio.size()-1;
    while(inicio<fin){
        if(limpio[inicio]!=limpio[fin]){
            return false;
        }
        inicio++;
        fin--;
    }
    return true;
}
int main() {
    string texto;
    cout<<"Ingrese un texto: ";
    getline(cin, texto);//getline para texto al azar
    if(esPalindromo(texto)){
        cout<<"Es palindromo"<<endl;
    } else {
        cout<<"No es palindromo"<<endl;
    }
    return 0;
}