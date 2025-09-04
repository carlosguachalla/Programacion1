// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 04/09/2025
// Número de ejercicio: 22
#include<iostream>
using namespace std;
int main(){
    int num1=0, num2=0, resultado=0;
    cout<<"Introduce dos numeros enteros: "<<endl;
    cin>>num1;
    cin>>num2;
    if(num1>num2){//todo este if y el siguiente verifica cual de los dos es mayor o menor para ver a cual dividir y ver si tiene multiplo
        if(num1%num2==0){
            cout<<num2<<" es multiplo de "<<num1;
        }
        else{
            cout<<"ninguno de los dos es multiplo del otro";
        }
    }
    else if (num1<num2){//este hace lo mismo que el otro if pero al reves
        if(num2%num1==0){
            cout<<num1<<" es multiplo de "<<num2;
        }
        else{
            cout<<"ninguno de los dos es multiplo del otro";
        }
    }
    else if(num1==num2){
        cout<<"ambos numeros son iguales por lo que son multiplos de si mismo";
    }
}