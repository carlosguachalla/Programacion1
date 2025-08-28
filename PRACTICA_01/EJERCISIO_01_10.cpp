// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatronica
// Fecha creación: 27/08/2025
// Número de ejercicio: 10
#include <iostream>
using namespace std;
int main() {
    int nota=0;
    cout<<"Ingrese su nota de 0 a 100: ";
    cin>>nota;
    if(nota>=51){//este if verifica que la nota sea igual o mayor a 51
        if(nota<60){
            cout<<"Calificacion: C"<<endl;
        }
        else if (nota<70){
            cout<<"Calificacion: C+"<<endl;
        }
        else if (nota<80){
            cout<<"Calificacion: B"<<endl;
        }
        else if (nota<90){
            cout<<"Calificacion: B+"<<endl;
        }
        else if (nota<95){
            cout<<"Calificacion: A"<<endl;
        }
        else if (nota==100){
            cout<<"Calificacion: A+"<<endl;
        }
    }
    else{
        cout<<"Estas reprobado"<<endl;
    }
    return 0;
}
//IMPORTANTE.- Hay un problema con este programa, en tod caso con la instruccion. En el problema se puede ver que
//dice A+ igual a 100 y A menor a 95, esto quiere decir que en el rango de 95 a 99 no mostrara nada