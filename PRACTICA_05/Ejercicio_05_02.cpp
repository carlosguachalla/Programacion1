// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 1/10/2025
// Número de ejercicio: 2
#include <iostream>
#include <vector>
using namespace std;
int main(){
    double vol;
    vector<double> voltios;
    for (int i=0; i<9; i++){
        cout<<"Ingrese valor de voltios: ";
        cin>>vol;
        voltios.push_back(vol);//con esto se mueve un espacio dentro del vector
    }
    cout<<voltios[0]<<" "<<voltios[1]<<" "<<voltios[2]<<endl;
    cout<<voltios[3]<<" "<<voltios[4]<<" "<<voltios[5]<<endl;
    cout<<voltios[6]<<" "<<voltios[7]<<" "<<voltios[8]<<endl;
}