// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Fecha creación: 07/09/2025
// Número de ejercicio: 3

#include <iostream>
using namespace std;

bool esCapicua(int numero) {
    int original=numero;
    int inverso=0, digito=0;
    while (numero!=0) {
        digito=numero%10;
        inverso=inverso*10+digito;
        numero/=10;
    }
    return original==inverso;
}
int main() {
    int numero;
    cout<<"Ingresa un numero entero: ";
    cin>>numero;
    if (esCapicua(numero)) {
        cout<<"El numero "<<numero<<" es capicua."<<endl;
    } else {
        cout<<"El numero "<<numero<<" no es capicua."<<endl;
    }
    return 0;
}