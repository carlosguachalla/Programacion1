// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Fecha creación: 07/09/2025
// Número de ejercicio: 2
#include <iostream>
using namespace std;
float CelsiusAFahrenheit(float numero){//esta funcion se encarga de ejecutar la formula de conversion de centigrados a fahrenheit
    return(numero*(9.0/5.0)+32);
}
int main() {
    float numero;
    cout<<"Ingresa un valor en grados celsious: ";
    cin>>numero;
    cout<<"La conversion a grados fahrenheit es: "<<CelsiusAFahrenheit(numero)<<endl;//resultado de la funcion
    return 0;
}