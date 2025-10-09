// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 8/10/2025
// Número de ejercicio: 13
#include <iostream>
#include <string>
using namespace std;
string primeraMayuscula(string texto) {
    int i;
    bool inicioPalabra = true;
    for(i=0;i<texto.size();i++){
        if(texto[i]==' '){
            inicioPalabra=true;
        } else {
            if(inicioPalabra && texto[i] >= 'a' && texto[i] <= 'z'){
                texto[i]=texto[i] - 32;
            }
            inicioPalabra=false;//si es false no es inicio de palabra
        }
    }
    return texto;
}
int main() {
    string texto;
    cout<<"Ingrese un texto: ";
    getline(cin, texto);//getline es para obtener la cadena
    texto=primeraMayuscula(texto);
    cout<<"Texto con primeras letras en mayuscula: "<<texto<<endl;
    return 0;
}
