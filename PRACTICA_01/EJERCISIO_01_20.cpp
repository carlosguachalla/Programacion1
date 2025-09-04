// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 04/09/2025
// Número de ejercicio: 20
#include<iostream>
using namespace std;
int main(){
    int num=0, contador=0;
    cout<<"Introduce un numero entero: ";
    cin>>num;
    while (num!=0){ 
        num=num/10;//diviendo entre 10 quitamos el ultimo numero
        contador=contador+1;//asi que vamos contando cuantos numeros tenemos que quitar hasta llegar a 0
    }
    cout<<"El numero introducido tiene: "<<contador<<" digitos";
    
}