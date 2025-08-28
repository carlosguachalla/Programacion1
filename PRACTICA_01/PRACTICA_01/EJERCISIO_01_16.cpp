// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatronica
// Fecha creación: 28/08/2025
// Número de ejercicio: 16
#include <iostream>
using namespace std;
int main() {
    int numero=0, numdivisible=0, contador=0;
    cout<<"Ingrese un numero: ";
    cin>>numero;
    while (contador!=numero){//con esto vamos a ir numero por numero hasta llegar al numero indicado
        contador=contador+1;
        if ((numero%contador)==0){//aqui vemos si cuando lo dividimos sale como residuo 0 ccombrobando que es multiplo
            numdivisible=numdivisible+1;
        }
    }
    if (numdivisible==2){//como los primos deben ser divisibles por uno y por si mismos minimo, entonces es primo si solo se puede divir entre ellos dando resultado 2
       cout<<"Es un numero primo: "; 
    }
    else{
        cout<<"Este numero no es primo";
    }
    return 0;
}