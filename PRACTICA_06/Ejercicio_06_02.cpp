// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 8/10/2025
// Número de ejercicio: 2
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    vector<string> material(6);
    string tempMat, buscado;
    vector<double> produccion(6);
    double tempProd;
    bool encontrado = false;//inicia como false
    for (int i = 0; i < 6; i++) {
        cout<<"Ingrese material: ";
        cin>>material[i];
        cout<<"Ingrese su produccion en toneladas metricas: ";
        cin>>produccion[i];
    }
    for (int i = 0; i < 6 - 1; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (produccion[i]<produccion[j]){//con estos ifs y for nos encargamos de verificar que toddos esten en orden de mayora a menor el proceso se repite hasta acabar
                tempProd=produccion[i];
                produccion[i]=produccion[j];
                produccion[j]=tempProd;
                tempMat=material[i];
                material[i]=material[j];
                material[j]=tempMat;
            }
        }
    }
    cout<<"Material y produccion:"<<endl;
    for (int j = 0; j < 6; j++) {
        cout<<material[j]<<"        "<<produccion[j]<<endl;
    }
    cout<<"Ingrese el nombre del material que desea buscar: ";
    cin>>buscado;
    for (int i = 0; i < 6; i++) {
        if (material[i] == buscado) {//con esto busca el material por su nombre en el vector de nombres ymuestra su valor en produciion
            cout << "La produccion de " << material[i] << " es " << produccion[i] << " toneladas metricas." << endl;
            encontrado = true;
        }
    }
    return 0;
}
