// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 14/09/2025
// Número de ejercicio: 9
#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
float sueldoplus(int valor){
    return ((1000*valor)*0.1);
}
int main() {
    int numvendedoras=0, valor=0, sueldo=1000, totalapagar=0;
    srand(time(0)); // ponemos una semilla
    cout<<"Ingrese la cantidad de vendedoras en la empresa: ";
    cin>>numvendedoras;
    cout<<"Sueldo mensual: 1000"<<endl;
    for (int i=1; i<=numvendedoras; i++){
        valor=rand()%(12-8+1)+8; // Genera un número entre 8 y 12, essto lo hice porque en promedio se cada una vende 10 productos mes
        cout<<"Vendedora: "<<i<<"    Productos vendidos: "<<valor<<"    Extra de 10% por producto: "<<sueldoplus(valor)<<"     Sueldo a paga total:"<<1000+sueldoplus(valor)<<endl;
        totalapagar+=sueldoplus(valor)+1000;
    }
    cout<<"Cantidad a pagar en total entre todos: "<<totalapagar<<endl;
}
