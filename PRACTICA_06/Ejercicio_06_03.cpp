// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 8/10/2025
// Número de ejercicio: 3
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
int main() {
    srand(time(0)); // ponemos una semilla
    int n;
    cout<<"Ingrese el numero de repeticiones: ";
    cin>>n;//pide un numero de n der repeticiones
    vector<string> nombres = {"Pipo","Avril","Kevin","Maite","Pablo","Nicolas","Wara","Adriana","Mateo","Dilan"};
    vector<string> apellidos = {"Gomez","Loayza","Valencia","Canaviri","Torres","Mendoza","Borda","Cutile","Chavez","Rosales"};
    vector<int> edad = {8, 13, 22, 28, 31, 37, 50, 65, 67, 72};
    for (int i = 0; i < n; i++){
        cout<<nombres[rand() % 9]<<"        "<<apellidos[rand() % 9]<<"       "<<edad[rand() % 9]<<endl;//escoge un numero entre 1 al 9
    }//y de ahi combina
}