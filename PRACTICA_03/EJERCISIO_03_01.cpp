// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Fecha creación: 07/09/2025
// Número de ejercicio: 1
#include <iostream>
using namespace std;
string esParOImpar(int numero){//con esta funcion determinamos si el numero es par, impar o cero
    if (numero==0){
        return ("cero");
    }
    else if (numero%2==0){
        return ("par");
    }
    else if (numero%2!=0){
        return ("impar");
    }
    else{
        return("indefinido");
    }
}
int main() {
    int numero;
    cout<<"Ingresa un numero: ";
    cin>>numero;
    cout<<"El número es: "<<esParOImpar(numero)<<endl;//aqui se muestra el resultado enviado de la funcion
    return 0;
}