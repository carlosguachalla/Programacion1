// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatronica
// Fecha creación: 27/08/2025
// Número de ejercicio: 9
#include <iostream>
using namespace std;
int main() {
    int edad=0;
    cout<<"Ingrese su edad: ";
    cin>>edad;
    if(edad<=12)//este if sucede cuando la edad esta en el rango de 0 a 12 años
        cout<<"eres un niño"<<endl;
    if(edad<=18&&edad>12)//este if sucede cuando la edad esta en el rango de 13 a 18 años
        cout<<"eres un adolecente"<<endl;
    if(edad<60&&edad>18)//este if sucede cuando la edad esta en el rango de 19 a 59 años
        cout<<"eres un mayor de edad"<<endl;
    if(edad>=60)//este if sucede cuando la edad esta en el rango de 60 años para arriba
        cout<<"eres un adulto mayor"<<endl;
    return 0;
}