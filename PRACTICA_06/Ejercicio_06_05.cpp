// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 8/10/2025
// Número de ejercicio: 5
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    vector<string> empresa1, empresa2, comunes;
    int n1, n2;
    string nombre;
    cout << "Cantidad de clientes de la empresa 1: ";
    cin >> n1;
    cout << "Ingrese los nombres de la empresa 1:" << endl;
    for(int i=0; i<n1; i++){
        cin >> nombre;
        empresa1.push_back(nombre);//coloca n veces las repeticiones
    }
    cout << "Cantidad de clientes de la empresa 2: ";
    cin >> n2;
    cout << "Ingrese los nombres de la empresa 2:" << endl;
    for(int i=0;i<n2;i++){
        cin>>nombre;
        empresa2.push_back(nombre);
    }
    for(int i=0;i<empresa1.size();i++){
        for(int j=0; j<empresa2.size(); j++){
            if(empresa1[i]==empresa2[j]){//con este if cuenta si los valores de dos y va uno por uno comparando nombres
                comunes.push_back(empresa1[i]);
            }
        }
    }
    if(comunes.empty()){//ve si esta vacio
        cout<<endl<<"No hay clientes en común." << endl;
    }
    else{
        cout<<"Clientes en común:" << endl;
        for(int i=0; i<comunes.size(); i++){
            cout<<comunes[i] << endl;
        }
        cout<<"Total de clientes en común: "<<comunes.size()<<endl;
    }
    return 0;
}
