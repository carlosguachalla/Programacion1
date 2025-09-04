// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 04/09/2025
// Número de ejercicio: 25
#include<iostream>
using namespace std;
int main(){
    int num=0, tabla=0, numtabla=0;
    char contin='s';
    while(contin=='s'){//con esto comprobamos el caracter introducido si es n este bucle parara
        cout<<"Introduce un numero: ";
        cin>>num;
        for(tabla=1;tabla<=10;tabla++){//con este for hacemos la tabla de una sola vez y no se hace uno por uno la multiplicacion
            cout<<tabla<<"x"<<num<<"="<<tabla*num<<endl;
        }  
        cout<<"Desea calcular otra tabla (s/n): ";
        cin>>contin; //con esto te dan la opcion de continuar o acabar el bucle
    }
    cout<<"Fin del programa";
}