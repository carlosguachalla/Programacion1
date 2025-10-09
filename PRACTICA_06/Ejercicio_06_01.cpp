// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 8/10/2025
// Número de ejercicio: 1
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
int main(){
    vector<int> edad;
    vector<double> desviacionmedia;
    double valor, media=0, varianza;
    cout<<"Ingrese edades (para terminar coloque -1): ";
    do{
        cin>>valor;
        if(valor!=-1){//si es distinto a -1 aumenta un valor mas al vector
            edad.push_back(valor);
        }
    }while(valor!=-1);
    cout<<"Edades ingresadas: ";
    for(int i=0; i<edad.size(); i++){
        cout<<edad[i]<<" ";
        media+=edad[i];
    }
    media =media/edad.size();
    cout<<endl<<"La media es: "<<media<<endl;
    for(int j=0; j<edad.size(); j++){
        desviacionmedia.push_back(pow(edad[j] - media, 2));
    }
    cout<<"Desviacion respecto a la media al cuadrado: ";
    for(int k=0; k<desviacionmedia.size(); k++){
        cout<<desviacionmedia[k]<<" ";
        varianza+=desviacionmedia[k];
    }
    varianza=varianza/(desviacionmedia.size()-1);//.size para saber cuandos valores hay dentor del vector
    cout<<endl<<"La desviacion tipica es: "<<pow(varianza,0.5);
    return 0;
}
