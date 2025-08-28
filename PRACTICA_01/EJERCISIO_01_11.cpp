// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatronica
// Fecha creación: 27/08/2025
// Número de ejercicio: 11
#include <iostream>
using namespace std;
int main() {
    int mes=0;
    cout<<"Ingrese un numero de mes: ";
    cin>>mes;
    if(mes>=1&&mes<=12){//este if comprueba si el valor de la variable esta entre 1 y 12
        switch (mes){//con switch podemos comparar los valores de una variable sin tener que colocar varios if
            case 1: cout<<"Enero";
                    break;
            case 2: cout<<"Febrero";
                    break;
            case 3: cout<<"Marzo";
                    break;
            case 4: cout<<"Abril";
                    break;
            case 5: cout<<"Mayo";
                    break;
            case 6: cout<<"Junio";
                    break;
            case 7: cout<<"Julio";
                    break;
            case 8: cout<<"Agosto";
                    break;
            case 9: cout<<"Septiembre";
                    break;
            case 10: cout<<"Octubre";
                    break;
            case 11: cout<<"Noviembre";
                    break;
            case 12: cout<<"Diciembre";
                    break;
        }
    }
    else{
        cout<<"Mes invalido"<<endl;
    }
    return 0;
}