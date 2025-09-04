// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 04/09/2025
// Número de ejercicio: 18
#include<iostream>
using namespace std;
int main(){
    int contador=0,num=2;
    while(contador<100){
        bool esprimo=true;
        for(int conta2=2;conta2*conta2<=num;conta2++){//con este for evitamos hacer el repaso de ver si es primo o no dos veces
            if(num%conta2==0){
                esprimo=false;
            }
        }
        if(esprimo){
            cout<<num<<endl;
            contador++;//con este contador verificaremos que tendremos 100 numero primos
        }
        num++;
    }
    cout<<endl;
    return 0;
}