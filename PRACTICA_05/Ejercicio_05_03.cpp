// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 2/10/2025
// Número de ejercicio: 3
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N;
    double promedio, suma, sumaDesv2, varianza;
    cout<<"Ingrese la cantidad de calificaciones: ";
    cin>>N;
    vector<int> calificaciones(N);
    vector<double> desviacion(N);
    for(int i=0;i<N;i++){//ingresa el numero de calificaciones y este for lo repite aumentando en el vector
        cout<<"Calificacion "<<i+1<<": ";
        cin>>calificaciones[i];
        suma+=calificaciones[i];
    }
    promedio=suma/N;
    cout<<"Suma total: "<<suma<<endl;
    cout<<"Promedio: "<<promedio<<endl;
    sumaDesv2=0;
    cout<<"Calificacion Desviacion"<<endl;
    for(int i=0;i<N;i++){
        desviacion[i]=calificaciones[i]-promedio;
        sumaDesv2+=desviacion[i]*desviacion[i];
        cout<<calificaciones[i]<<" "<<desviacion[i]<<endl;
    }
    varianza=sumaDesv2/N;
    cout<<"Varianza: "<<varianza<<endl;
    return 0;
}
