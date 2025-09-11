//Materia:Programación I, Paralelo 4
//Autor:Carlos Adrian Guachalla Quispe
//Fecha creación:07/09/2025
//Número de ejercicio:9
#include<iostream>
using namespace std;
int calcular(int minutos){//solo resta ek tiempo trabajado con el que debia trabajra
    int jornada=480;
    return minutos-jornada;
}
int main(){
    int tiempo=0, resultado=0;
    cout<<"Ingrese minutos trabajados:";
    cin>>tiempo;
    resultado=calcular(tiempo);
    if(resultado>0){//este if ve cuanto trabajo ectra,menos o lo adecuado
        cout<<"Tiempo extra de trabajo:"<<resultado<<" minutos"<<endl;
    }
    else if(resultado<0){
        cout<<"Tiempo que le flato para completar jornad:"<<-resultado<<" minutos"<<endl;
    }
    else {
        cout<<"Trabajo exactamente la jornada"<<endl;
    }
    return 0;
}
