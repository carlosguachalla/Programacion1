// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 14/09/2025
// Número de ejercicio: 6
#include <iostream>
using namespace std;
int sumadedigitos(int numero){//saca el ultimo numero utilizando el residuo de una divison entre 10
    int total=0;
    while (numero!=0){
        total+=numero%10;
        numero=numero/10;
    }
    return total;
}
bool numprimo(int suma){//revisa si la suma de digitos da un numero primo
    int cprimo=0;
    for (int i=1; i<=suma; i++){
        if (suma%i==0){
            cprimo++;
        }   
    }
    if (cprimo==2){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int numero=0, suma=0;
    cout<<"Ingrese un numero: ";
    cin>>numero;
    suma=sumadedigitos(numero);
    cout<<"Total de suma: "<<suma<<endl;
    if (numprimo(suma)){
        cout<<"Este numero es primo";
    }
}
