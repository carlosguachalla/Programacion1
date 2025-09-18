// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 13/09/2025
// Número de ejercicio: 2
#include <iostream>
#include <cmath>
using namespace std;
double CalcularVolumen(int &radio, int &altura){
    double pi=3.14159265, VolumenCilindro=0;
    VolumenCilindro=pi*pow(radio,2)*altura;//formula para halar el volumen de un cilindro
    return VolumenCilindro;//devuelve el valor del volumen cuando llamen a la funcion
}
int main() {
    int altura=10, radio=0;//como el valor de la altura por defecto es 10 no pediremos este valor
    cout<<"FUNCION PARA HALLAR EL VOLUMEN DE UN CILINDRO(valor por defecto de la altura 10m)"<<endl;
    cout<<"Ingresar un radio en m: "<<endl;
    cin>>radio;
    cout<<"El volumen del cilindro altura 10m y radio "<<radio<<"m es: "<<CalcularVolumen(radio,altura)<<"[m^3]";//llamado de funcion
}