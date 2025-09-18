// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 13/09/2025
// Número de ejercicio: 3
#include <iostream>
using namespace std;
void ModificarValores(int valor, int &referencia) {
    valor = valor * 2;//Esto solo afecta dentro de la función
    referencia = referencia + 10;//Esto sí afecta la variable original
}
int main() {
    int valor=0, referencia=0;
    cout<<"Ingresar el numero que pasara por valor: ";
    cin>>valor;
    cout<<"Ingresar el numero que pasara por referencia: ";
    cin>>referencia;
    cout<<"Antes de llamar a la función:"<<endl;
    cout<<"a = "<<valor<<" (pasado por valor)"<<endl;
    cout<<"b = "<<referencia<<" (pasado por referencia)"<<endl;
    ModificarValores(valor, referencia);
    cout<<"Después de llamar a la función:"<<endl;
    cout<<"a = "<<valor<<" (no cambia)"<<endl;//al ser un valor ingresado por valor este no cambia
    cout<<"b = "<<referencia<<" (se incrementa en 10)"<<endl;//por otro lado este que fue ingresado por referencia cambia
}
