// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 11/11/2025
// Número de ejercicio: 7
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
using namespace std;
struct EstudianteCalificaciones {
    string nombre;
    double c1, c2, c3, c4;
    double promedio;
};
void calcularYGuardarPromedios() {
    ifstream archivoEntrada("calificaciones.txt");
    ofstream archivoSalida("promedios.txt", ios::out | ios::trunc);  
    string linea;
    vector<EstudianteCalificaciones> resultados;
    if (archivoEntrada.fail()) {
        cout << "Error, No se pudo abrir el archivo calificaciones.txt para lectura." << endl;
        return;
    }
    if (archivoSalida.fail()) {
        cout << "Error, No se pudo crear o abrir promedios.txt para escritura." << endl;
        return;
    }
    while (getline(archivoEntrada, linea)) {
        stringstream ss(linea);
        EstudianteCalificaciones actual;
        if (ss >> actual.nombre >> actual.c1 >> actual.c2 >> actual.c3 >> actual.c4) {
            actual.promedio = (actual.c1 + actual.c2 + actual.c3 + actual.c4) / 4.0;
            resultados.push_back(actual);
        } else {
            cout << "Advertencia, Linea con formato incorrecto omitida: " << linea << endl;
        }
    }
    archivoEntrada.close();
    for (const auto& resultado : resultados) {
        archivoSalida << resultado.nombre << " " << resultado.promedio << endl;
    }
    archivoSalida.close();
    cout << "Calculo de promedios completado, Resultados guardados en promedios.txt" << endl;
}
void crearArchivoCalificaciones() {
    ofstream archivo("calificaciones.txt", ios::out | ios::trunc);
    if (archivo.fail()) {
        cout << "Error critico al crear el archivo calificaciones.txt." << endl;
        return;
    }
    archivo << "Juan 7.5 8.0 9.5 6.5" << endl;
    archivo << "Ana 8.0 7.5 9.0 8.5" << endl;
    archivo << "Luis 6.0 6.5 7.0 5.5" << endl;
    archivo.close();
    cout << "Archivo calificaciones.txt creado con datos de ejemplo." << endl;
}
void salirPrograma() {
    cout << "Saliendo del programa, Adios." << endl;
}
int main() {
    crearArchivoCalificaciones();
    int opcion;
    bool salir = false;
    while (!salir) {
        cout << endl;
        cout << "--- Menu de Promedios ---" << endl;
        cout << "1. Calcular y guardar promedios" << endl;
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
                calcularYGuardarPromedios();
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
La estructura EstudianteCalificaciones define los campos para almacenar el nombre del alumno, sus cuatro calificaciones y el promedio calculado.
La función calcularYGuardarPromedios lee los datos del archivo "calificaciones.txt", calcula el promedio de cada estudiante y guarda los nombres junto con sus promedios resultantes en el archivo "promedios.txt".
La función crearArchivoCalificaciones inicializa o sobrescribe el archivo "calificaciones.txt" con un conjunto de datos de ejemplo para fines de prueba.
La función salirPrograma imprime un mensaje de despedida.
El programa principal (main) crea el archivo de calificaciones de ejemplo y luego presenta un menú de opciones para que el usuario pueda calcular los promedios o salir.
*/