// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Fecha creación: 07/09/2025
// Número de ejercicio: 4
#include <iostream>
using namespace std;
float imc(float peso,float altura) {
    return(peso/(altura*altura));
}
int main() {
    float peso=0, altura=0;
    cout<<"Ingresa un peso en kilogramos: ";
    cin>>peso;
    cout<<"Ingresa una altura en metros: ";
    cin>>altura;
    cout<<"Indice de masa corporal: "<<imc(peso,altura)<<endl;
    if(imc(peso,altura)<18.5){
        cout<<"Peso bajo";
    }
    else if(imc(peso,altura)>=18.5&&imc(peso,altura)<25.0){
        cout<<"Peso normal";
    }
    else if(imc(peso,altura)>=25.0&&imc(peso,altura)<30.0){
        cout<<"Sobrepeso";
    }
    else if(imc(peso,altura)>=30.0){
        cout<<"Obesidad";
    }
}