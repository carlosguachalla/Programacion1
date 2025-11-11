// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 10/11/2025
// Número de ejercicio: 6
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
using namespace std;
struct RegistroTemperatura {
    string ciudad;
    double temperatura;
};
void filtrarTemperaturas() {
    ifstream archivoEntrada("temperaturas.txt");
    ofstream archivoSalida("altas_temperaturas.txt", ios::out | ios::trunc);
    double umbralN = 0.0;
    string linea;
    string ciudadTemporal;
    double tempTemporal;
    vector<RegistroTemperatura> altasTemperaturas;
    cout << "Ingrese el valor N de temperatura umbral para filtrar: ";
    if (!(cin >> umbralN)) {
        cout << "Entrada invalida, Ingrese un numero." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    if (archivoEntrada.fail()) {
        cout << "Error, No se pudo abrir el archivo temperaturas.txt para lectura." << endl;
        return;
    }
    if (archivoSalida.fail()) {
        cout << "Error, No se pudo crear o abrir altas_temperaturas.txt para escritura." << endl;
        return;
    }
    while (getline(archivoEntrada, linea)) {
        stringstream ss(linea);
        if (ss >> ciudadTemporal >> tempTemporal) {
            if (tempTemporal > umbralN) {
                altasTemperaturas.push_back({ciudadTemporal, tempTemporal});
            }
        }
    }
    archivoEntrada.close();
    for (const auto& registro : altasTemperaturas) {
        archivoSalida << registro.ciudad << " " << registro.temperatura << endl;
    }
    archivoSalida.close();
    if (altasTemperaturas.empty()) {
        cout << "No se encontraron temperaturas superiores a " << umbralN << " grados." << endl;
    } else {
        cout << "Filtrado completado, Se guardaron " << altasTemperaturas.size() << " registros en altas_temperaturas.txt" << endl;
    }
}
void crearArchivoEjemplo() {
    ofstream archivo("temperaturas.txt", ios::out | ios::trunc);
    if (archivo.fail()) {
        cout << "Error critico al crear el archivo temperaturas.txt." << endl;
        return;
    }
    archivo << "Madrid 32.5" << endl;
    archivo << "Barcelona 28.3" << endl;
    archivo << "Sevilla 34.2" << endl;
    archivo << "Valencia 31.0" << endl;
    archivo << "Vitoria 15.1" << endl;
    archivo << "Bilbao 21.0" << endl;
    archivo.close();
    cout << "Archivo temperaturas.txt creado con datos de ejemplo." << endl;
}
void salirPrograma() {
    cout << "Saliendo del programa, Adios." << endl;
}
int main() {
    crearArchivoEjemplo();
    int opcion;
    bool salir = false;
    while (!salir) {
        cout << endl;
        cout << "--- Menu de Filtrado de Temperaturas ---" << endl;
        cout << "1. Filtrar temperaturas y generar altas_temperaturas.txt" << endl;
        cout << "2. Salir del programa" << endl;
        cout << "Seleccione una opcion: ";
        if (!(cin >> opcion)) {
            cout << "Entrada invalida, Ingrese un numero." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch (opcion) {
            case 1:
                filtrarTemperaturas();
                break;
            case 2:
                salirPrograma();
                salir = true;
                break;
            default:
                cout << "Opcion no valida, Intente de nuevo." << endl;
                break;
        }
    }
    return 0;
}
/*
La estructura RegistroTemperatura define una entrada con la ciudad y su temperatura asociada.
La función filtrarTemperaturas solicita un umbral N, lee registros de "temperaturas.txt" y escribe en "altas_temperaturas.txt" solo aquellas ciudades cuya temperatura supera dicho umbral.
La función crearArchivoEjemplo inicializa o sobrescribe "temperaturas.txt" con un conjunto de datos de ciudades y sus temperaturas para fines de prueba.
La función salirPrograma imprime un mensaje de despedida y se invoca al finalizar el programa.
El programa principal (main) inicia creando un archivo de ejemplo y luego presenta un menú de opciones que permite al usuario filtrar las temperaturas o salir.
*/