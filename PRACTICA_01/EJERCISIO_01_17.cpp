// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatronica
// Fecha creación: 28/08/2025
// Número de ejercicio: 17
#include <iostream>
using namespace std;
int main() {
    int num, sumaDivisoresNum = 0, contador = 1, buscador = 1, sumaDivisoresI = 0, contador2 = 1;
    bool encontrado = false;//esto hace que solo pueda tener dos valores verdadero o flaso
    cout<<"Ingrese un numero para ver si tiene amigo: ";
    cin>>num;
    while (contador < num) {
        if (num % contador == 0) {
            sumaDivisoresNum += contador;
        }
        contador++;//colocar contador++ hace que su valor aumente en 1 cada vez que se ejecuta
    }
    while (buscador<=10000&&!encontrado) {
        if (buscador==num){// Hace que no se compare consigo mismo asi no da que es su propio amigo
            buscador++;
            continue;
        }
        sumaDivisoresI = 0; // Se reinicia para cada nuevo número
        contador2 = 1;      // Se reinicia para cada nuevo número
        while (contador2 < buscador) {
            if(buscador%contador2==0) {
                sumaDivisoresI += contador2;
            }
            contador2++;
        }
        if (sumaDivisoresNum==buscador&&sumaDivisoresI==num) {// Condición para verificar si son numeros amigos
            cout<<"El numero amigo de "<<num<<" es "<<buscador<< endl;
            encontrado=true;
        }
        buscador++;
    }
    if (!encontrado) {
        cout<<"No se encontro un numero amigo para "<<num<<" en el rango de busqueda de 10000"<< endl;
    }
    return 0;
}