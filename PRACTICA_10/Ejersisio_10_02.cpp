// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 10/11/2025
// Número de ejercicio: 2
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void prepararArchivo() {
    ofstream archivoSalida("texto.txt", ios::out);
    string frase;
    cout<<"Escribe la frase: ";
    getline(cin, frase);
    if (archivoSalida.fail()) {
        cout<<"Error al crear o limpiar el archivo texto.txt"<<endl;
        return;
    }
    archivoSalida<<frase<<endl;
    archivoSalida.close();
    cout<<"Archivo texto.txt creado y preparado"<<endl;
}
void contarPalabras() {
    ifstream archivoEntrada("texto.txt");
    string palabra;
    int contador = 0;
    if (archivoEntrada.fail()) {
        cout<<"No pude abrir el archivo texto.txt"<<endl;
        return;
    }
    while (archivoEntrada>>palabra) {
        contador++;
    }
    archivoEntrada.close();
    cout<<"El archivo texto.txt contiene "<<contador<<" palabras."<<endl;
}
int main() {
    prepararArchivo();
    contarPalabras();
    return 0;
}
/*
La función prepararArchivo solicita una frase al usuario y la escribe en "texto.txt", limpiando el contenido anterior.
La función contarPalabras lee "texto.txt" palabra por palabra e imprime el número total de palabras contadas.
El programa principal (main) prepara el archivo solicitando la frase y luego procede a contar las palabras dentro del mismo.
*/