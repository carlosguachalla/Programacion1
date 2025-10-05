// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 1/10/2025
// Número de ejercicio: 1
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
//Generar 100 voltajes (20.00 V a 220.00 V)
void generarVoltajes(vector<double>&voltajes){
    double v;
    for(int i=0;i<100;i++){
        v=20+(rand()%(20001))/100.0;
        voltajes.push_back(v);
    }
}
//Generar 50 temperaturas (0.00 a 100.00)
void generarTemperaturas(vector<double>&temperaturas){
    double t;
    for(int i=0;i<50;i++){
        t=(rand()%(10001))/100.0;
        temperaturas.push_back(t);
    }
}
//Generar 30 caracteres alfanuméricos
void generarCaracteres(vector<char>&caracteres){
    string alfanum = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";//Esta variables tiene los carcteres alfanumericos
    char c;
    for(int i=0;i<30;i++){
        c=alfanum[rand()%alfanum.size()];//y con este random agarra algun caracter de la variale con todos los valores
        caracteres.push_back(c);
    }
}
//Generar 100 años (1990 a 2025)
void generarAnos(vector<int>&anos){
    int ano;
    for(int i=0;i<100;i++){
        ano=1990+rand()%(2025-1990+1);
        anos.push_back(ano);
    }
}
//Generar 32 velocidades (10.00 a 300.00)
void generarVelocidades(vector<double>&velocidades){
    double v;
    for(int i=0;i<32;i++){
        v=10+(rand()%(29001))/100.0;
        velocidades.push_back(v);
    }
}
//Generar 1000 distancias (1.00 a 1000.00)
void generarDistancias(vector<double>&distancias){
    double d;
    for(int i=0;i<1000;i++){
        d=1+(rand()%(100000))/100.0;
        distancias.push_back(d);
    }
}
int main(){
    srand(time(0));
    vector<double> voltajes;
    vector<double> temperaturas;
    vector<char> caracteres;
    vector<int> anos;
    vector<double> velocidades;
    vector<double> distancias;
    generarVoltajes(voltajes);
    generarTemperaturas(temperaturas);
    generarCaracteres(caracteres);
    generarAnos(anos);
    generarVelocidades(velocidades);
    generarDistancias(distancias);
    cout<<"Primeros 10 voltajes:"<<endl;
    for(int i=0;i<10;i++){
        cout<<voltajes[i]<<" ";
    }
    cout<<endl;
    cout<<"Primeras 10 temperaturas:"<<endl;
    for(int i=0;i<10;i++){ cout<<temperaturas[i]<<" "; }
    cout<<endl;
    cout<<"Primeros 10 caracteres alfanumericos:"<<endl;
    for(int i=0;i<10;i++){ cout<<caracteres[i]<<" "; }
    cout<<endl;
    cout<<"Primeros 10 años:"<<endl;
    for(int i=0;i<10;i++){ cout<<anos[i]<<" "; }
    cout<<endl;
    cout<<"Primeras 10 velocidades:"<<endl;
    for(int i=0;i<10;i++){ cout<<velocidades[i]<<" "; }
    cout<<endl;
    cout<<"Primeras 10 distancias:"<<endl;
    for(int i=0;i<10;i++){ cout<<distancias[i]<<" "; }
    cout<<endl;
    return 0;
}
