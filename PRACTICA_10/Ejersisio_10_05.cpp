// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 10/11/2025
// Número de ejercicio: 5
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
using namespace std;
struct Producto {
    int id;
    string nombre;
    double precio;
};
string formatPrecio(double precio) {
    long long entero = (long long)(precio * 100 + 0.5);
    long long parteEntera = entero / 100;
    long long parteDecimal = entero % 100;
    stringstream ss;
    ss << parteEntera << ".";
    if (parteDecimal < 10) {
        ss << "0";
    }
    ss << parteDecimal;
    return ss.str();
}
int obtenerSiguienteID() {
    ifstream archivoEntrada("productos.txt");
    string linea;
    int ultimoID = 0;
    if (archivoEntrada.fail()) {
        return 1;
    }
    while (getline(archivoEntrada, linea)) {
        if (linea.rfind("Producto(", 0) == 0) {
            size_t posInicio = linea.find('(');
            size_t posFin = linea.find(')');
            if (posInicio != string::npos && posFin != string::npos && posFin > posInicio) {
                try {
                    string idStr = linea.substr(posInicio + 1, posFin - posInicio - 1);
                    int idActual = stoi(idStr);
                    if (idActual > ultimoID) {
                        ultimoID = idActual;
                    }
                } catch (const std::exception& e) {
                }
            }
        }
    }
    archivoEntrada.close();
    return ultimoID + 1;
}
void registrarNuevoProducto() {
    string nombreNuevo;
    double precioNuevo;
    int nuevoID = obtenerSiguienteID();
    cout << "ID asignado: " << nuevoID << endl;
    cout << "Ingrese el nombre del nuevo producto: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nombreNuevo);
    cout << "Ingrese el precio del nuevo producto: ";
    while (!(cin >> precioNuevo) || precioNuevo < 0) {
        cout << "Precio invalido. Ingrese un numero positivo: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    ofstream archivoSalida("productos.txt", ios::app);
    if (archivoSalida.fail()) {
        cout << "Error al abrir productos.txt para registro." << endl;
        return;
    }
    archivoSalida << "Producto(" << nuevoID << ") " << nombreNuevo << " Precio:" << formatPrecio(precioNuevo) << endl;
    archivoSalida.close();
    cout << "Producto " << nombreNuevo << " registrado con exito." << endl;
}
void actualizarPrecio() {
    vector<Producto> listaProductos;
    ifstream archivoEntrada("productos.txt");
    string linea;
    if (archivoEntrada.fail()) {
        cout << "Error, No se pudo abrir el archivo productos.txt para lectura." << endl;
        return;
    }
    while (getline(archivoEntrada, linea)) {
        if (linea.rfind("Producto(", 0) == 0) {
            Producto prod;
            size_t posIDFin = linea.find(')');
            size_t posNombreInicio = posIDFin + 2;
            size_t posPrecioInicio = linea.find(" Precio:");
            if (posIDFin != string::npos && posPrecioInicio != string::npos && posPrecioInicio > posNombreInicio) {
                try {
                    prod.id = stoi(linea.substr(9, posIDFin - 9));
                    prod.nombre = linea.substr(posNombreInicio, posPrecioInicio - posNombreInicio);
                    prod.precio = stod(linea.substr(posPrecioInicio + 8));
                    listaProductos.push_back(prod);
                } catch (const std::exception& e) {
                    cout << "Error de formato en una linea del archivo." << endl;
                }
            }
        }
    }
    archivoEntrada.close();
    if (listaProductos.empty()) {
        cout << "El archivo esta vacio o el formato es incorrecto." << endl;
        return;
    }
    string nombreBuscar;
    double nuevoPrecio;
    cout << "Ingrese el nombre del producto a actualizar: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nombreBuscar);
    cout << "Ingrese el nuevo precio para " << nombreBuscar << ": ";
    while (!(cin >> nuevoPrecio) || nuevoPrecio < 0) {
        cout << "Precio invalido. Ingrese un numero positivo: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    bool encontrado = false;
    for (auto& prod : listaProductos) {
        if (prod.nombre == nombreBuscar) {
            prod.precio = nuevoPrecio;
            encontrado = true;
            break;
        }
    }
    if (encontrado) {
        ofstream archivoSalida("productos.txt", ios::out | ios::trunc);
        if (archivoSalida.fail()) {
            cout << "Error critico al reescribir productos.txt." << endl;
            return;
        }
        for (const auto& prod : listaProductos) {
            archivoSalida << "Producto(" << prod.id << ") " << prod.nombre << "     Precio:" << formatPrecio(prod.precio) << endl;
        }
        archivoSalida.close();
        cout << "Precio del producto " << nombreBuscar << " actualizado con exito." << endl;
    } else {
        cout << "El producto " << nombreBuscar << " no se encuentra en la lista." << endl;
    }
}
void salirPrograma() {
    cout << "Saliendo del programa, Adios." << endl;
}
int main() {
    int opcion;
    bool salir = false;
    while (!salir) {
        cout << endl;
        cout << "--- Menu de Productos ---" << endl;
        cout << "1. Registrar un nuevo producto" << endl;
        cout << "2. Actualizar el precio de un producto" << endl;
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
                registrarNuevoProducto();
                break;
            case 2:
                actualizarPrecio();
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
La estructura Producto define los campos para almacenar la información de cada artículo.
La función formatPrecio da formato de dos decimales a los valores double para una presentación consistente del precio.
La función obtenerSiguienteID lee el archivo "productos.txt" para determinar el ID más alto registrado y devuelve el siguiente número disponible.
La función registrarNuevoProducto solicita el nombre y el precio de un nuevo producto y lo añade, con un ID único, al archivo "productos.txt".
La función actualizarPrecio lee todos los productos del archivo, pide al usuario el nombre del producto y su nuevo precio, modifica el dato internamente y reescribe todo el archivo con el precio actualizado.
El programa principal (main) gestiona un menú que permite al usuario registrar nuevos productos, modificar el precio de los existentes o salir de la aplicación.
*/