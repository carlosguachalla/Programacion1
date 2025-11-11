// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 10/11/2025
// Número de ejercicio: 1
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;
void intnombres(){
    int n;
    string nom; 
    ofstream nombre;
    nombre.open("nombres.txt",ios::app);
    if (nombre.fail()){
        cout<<"No se pudo abrir el archivo";
        return;
    }
    cout << "Ingrese la cantidad de nombres a introducir: ";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    for (int i = 0; i < n; i++){
        cout<<"Introduce el nombre " << i + 1 << " :"; 
        getline(cin, nom); 
        nombre<<nom<<endl;
    }
    nombre.close();
    cout << "Nombres guardados con éxito en nombres.txt" << endl;
}
void verNombres() {
    ifstream archivo;
    string linea;
    archivo.open("nombres.txt", ios::in); 
    if (archivo.fail()) {
        cout << "\nERROR: No se pudo abrir el archivo 'nombres.txt'." << endl;
        return;
    }
    cout << "\n--- LISTA DE NOMBRES EN nombres.txt ---" << endl;
    bool hayContenido = false;
    while (getline(archivo, linea)) {
        cout << linea << endl;
        hayContenido = true;
    }
    if (!hayContenido) {
        cout << "El archivo está vacío." << endl;
    }
    cout << "---------------------------------------" << endl;
    archivo.close();
}
void borrarNombres() {
    ofstream archivo;
    archivo.open("nombres.txt", ios::out); 
    if (archivo.fail()) {
        cout << "\nERROR: No se pudo abrir el archivo 'nombres.txt' para borrarlo." << endl;
        return;
    }
    archivo.close();
    cout << "\nContenido de 'nombres.txt' borrado con éxito." << endl;
}
int main() {
    intnombres();
    int opcion;
    bool salir = false;
    while (!salir) {
        cout << "\n--- Opciones de Archivo ---" << endl;
        cout << "1. Ver la lista de nombres en consola" << endl;
        cout << "2. Borrar todo el contenido del archivo" << endl;
        cout << "3. Salir del programa" << endl;
        cout << "Seleccione una opción (1, 2 o 3): ";
        cin>>opcion;
        switch (opcion) {
            case 1:
                verNombres();
                break;
            case 2:
                borrarNombres();
                break;
            case 3:
                cout << "\nSaliendo del programa" << endl;
                salir = true;
                break;
            default:
                cout << "\nOpción no válida. Intente de nuevo." << endl;
                break;
        }
    }
    return 0;
}
/*
La función intnombres solicita al usuario una cantidad de nombres y los añade al archivo "nombres.txt".
La función verNombres lee y muestra el contenido completo del archivo "nombres.txt" en la consola.
La función borrarNombres borra todo el contenido del archivo "nombres.txt" abriéndolo en modo de truncado.
El programa principal (main) inicia la entrada de nombres y luego presenta un menú de opciones para ver, borrar o salir.
*/