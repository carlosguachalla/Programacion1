// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 13/09/2025
// Número de ejercicio: 1
#include <iostream>
using namespace std;
void IntercambiarValores(int &valor1, int &valor2){//COLOCAR EL & delante de cada variable hace que cuando su valor cambie este tambien lo haga en el main
    int guardado1=0;
    guardado1=valor1;//guardamos el valor 1 porque lo cambiaremos en la siguiente linea
    valor1=valor2;
    valor2=guardado1;//le damos el valor guardado a la segundo variable
}
int main() {
    int valor1=0, valor2=0;
    cout<<"Ingresar dos valores: "<<endl;
    cin>>valor1;
    cin>>valor2;
    cout<<"Valor de 1 antes de la funcion: "<<valor1<<endl;
    cout<<"Valor de 2 antes de la funcion: "<<valor2<<endl;
    IntercambiarValores(valor1,valor2);//llamado de la funcion para actuar
    cout<<"Valor de 1 despues de la funcion: "<<valor1<<endl;
    cout<<"Valor de 2 despues de la funcion: "<<valor2<<endl;
}