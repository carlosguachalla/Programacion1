// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 11/11/2025
// Número de ejercicio: 9
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;
const int DESPLAZAMIENTO = 3;
char cifrarCaracter(char caracter) {
    if (caracter >= 'a' && caracter <= 'z') {
        return (caracter - 'a' + DESPLAZAMIENTO) % 26 + 'a';
    } else if (caracter >= 'A' && caracter <= 'Z') {
        return (caracter - 'A' + DESPLAZAMIENTO) % 26 + 'A';
    } else {
        return caracter;
    }
}
void cifrarMensaje() {
    ifstream archivoEntrada("mensaje.txt");
    ofstream archivoSalida("mensaje_cifrado.txt", ios::out | ios::trunc);
    string linea;
    if (archivoEntrada.fail()) {
        cout << "Error, No se pudo abrir mensaje.txt para lectura." << endl;
        return;
    }
    if (archivoSalida.fail()) {
        cout << "Error, No se pudo crear o abrir mensaje_cifrado.txt." << endl;
        return;
    }
    cout << "Cifrando mensaje, Por favor espere." << endl;
    while (getline(archivoEntrada, linea)) {
        string lineaCifrada = "";
        for (char& caracter : linea) {
            lineaCifrada += cifrarCaracter(caracter);
        }
        archivoSalida << lineaCifrada << endl;
    }
    archivoEntrada.close();
    archivoSalida.close();
    cout << "Cifrado completado, El resultado esta en mensaje_cifrado.txt" << endl;
}
void crearOReescribirMensaje() {
    ofstream archivoSalida("mensaje.txt", ios::out | ios::trunc);
    string nuevoMensaje;
    cout << "Ingrese el nuevo mensaje que desea cifrar, presione Enter para terminar: " << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nuevoMensaje);
    if (archivoSalida.fail()) {
        cout << "Error critico al crear o reescribir mensaje.txt" << endl;
        return;
    }
    archivoSalida << nuevoMensaje << endl;
    archivoSalida.close();
    cout << "Archivo mensaje.txt actualizado con el nuevo texto." << endl;
}
void salirPrograma() {
    cout << "Saliendo del programa" << endl;
}
int main() {
    int opcion;
    bool salir = false;
    while (!salir) {
        cout << endl;
        cout << "--- Menu Cifrador Cesar ---" << endl;
        cout << "1. Crear o reescribir el archivo mensaje.txt" << endl;
        cout << "2. Cifrar mensaje.txt (Desplazamiento 3)" << endl;
        cout << "3. Salir del programa" << endl;
        cout << "Seleccione una opcion: ";
        if (!(cin >> opcion)) {
            cout << "Entrada invalida, Ingrese un numero." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch (opcion) {
            case 1:
                crearOReescribirMensaje();
                break;
            case 2:
                cifrarMensaje();
                break;
            case 3:
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
La constante DESPLAZAMIENTO define el valor (3) utilizado para el cifrado César.
La función cifrarCaracter aplica la lógica de desplazamiento César a un único carácter, manejando letras minúsculas, mayúsculas y dejando otros caracteres sin modificar.
La función cifrarMensaje lee línea por línea el contenido de "mensaje.txt", aplica el cifrado a cada carácter y guarda el resultado en un nuevo archivo llamado "mensaje_cifrado.txt".
La función crearOReescribirMensaje solicita al usuario un nuevo mensaje y lo escribe en el archivo "mensaje.txt", sobrescribiendo cualquier contenido anterior.
La función salirPrograma imprime un mensaje de finalización.
El programa principal (main) presenta un menú de opciones que permite al usuario crear o modificar el mensaje de entrada, realizar la operación de cifrado, o salir de la aplicación.
*/