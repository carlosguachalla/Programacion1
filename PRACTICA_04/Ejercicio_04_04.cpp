// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 13/09/2025
// Número de ejercicio: 4
#include <iostream>
using namespace std;
float ConvertirCelsiusAFahrenheit(float celsious){//covierte de celsious a farenheit por formula matematica
    float fahrenheit;
    fahrenheit=(1.8)*celsious+32;
    return fahrenheit;
}
int MayorTemperatura(int fahrenheit1, int fahrenheit2){//ve cual de la dos temperaturas nuevas es superior
    if (fahrenheit1>fahrenheit2)
        return fahrenheit1;
    if (fahrenheit1<fahrenheit2)
        return fahrenheit2;
    if (fahrenheit1==fahrenheit2)
        return fahrenheit1;
    else
        return 0;
}
int main() {
    float temperaturaC1=0 ,temperaturaC2=0 ,temperaturaF1=0 ,temperaturaF2=0;
    cout<<"Ingresar el valor de temperatura 1 en celsious: ";
    cin>>temperaturaC1;
    cout<<"Ingresar el valor de temperatura 2 en celsious: ";
    cin>>temperaturaC2;
    temperaturaF1=ConvertirCelsiusAFahrenheit(temperaturaC1);
    temperaturaF2=ConvertirCelsiusAFahrenheit(temperaturaC2);
    cout<<"El valor de temperatura 1 en celsious en fahrenheit es: "<<temperaturaF1<<endl;
    cout<<"El valor de temperatura 2 en celsious en fahrenheit es: "<<temperaturaF2<<endl;
    cout<<"El mayor temperatura ingresada es: "<<MayorTemperatura(temperaturaF1,temperaturaF2)<<endl;
}