// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 4/11/2025
// Número de ejercicio: 7
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
struct Producto {
    string nombre;
    string codigo;
    double precio;
    int cantidad_en_inventario;
    string observaciones;
};
int main() {
    int N;
    cout << "--- Registro de Inventario de Productos ---" << endl;
    cout << "Ingrese el número de productos (N) a registrar: ";
    if (!(cin >> N) || N <= 0) {
        cerr << "Número de productos inválido." << endl;
        return 1;
    }
    cin.ignore(256, '\n');
    vector<Producto> inventario;
    for (int i = 0; i < N; ++i) {
        Producto nuevoProducto;
        cout << "\n--- Datos del Producto #" << i + 1 << " ---" << endl;
        cout << "Nombre: ";
        getline(cin, nuevoProducto.nombre);
        cout << "Código: ";
        getline(cin, nuevoProducto.codigo);
        cout << "Precio (decimal): ";
        while (!(cin >> nuevoProducto.precio) || nuevoProducto.precio < 0) {
            cerr << "Precio inválido. Intente de nuevo: ";
            cin.clear();
            cin.ignore(256, '\n');
        }
        cout << "Cantidad en Inventario (entero): ";
        while (!(cin >> nuevoProducto.cantidad_en_inventario) || nuevoProducto.cantidad_en_inventario < 0) {
            cerr << "Cantidad inválida. Intente de nuevo: ";
            cin.clear();
            cin.ignore(256, '\n');
        }
        if (nuevoProducto.cantidad_en_inventario < 5) {
            nuevoProducto.observaciones = "PRUDUCTO CON BAJA CANTIDAD DE INVENTARIO";
        } else {
            nuevoProducto.observaciones = "";
        }
        cin.ignore(256, '\n');
        inventario.push_back(nuevoProducto);
    }
    if (inventario.empty()) {
        cout << "\nEl inventario está vacío." << endl;
        return 0;
    }
    Producto productoMasCaro = inventario[0];
    int cantidadTotal = 0;
    for (const auto& p : inventario) {
        if (p.precio > productoMasCaro.precio) {
            productoMasCaro = p;
        }
        cantidadTotal += p.cantidad_en_inventario;
    }
    cout << "\n=============================================" << endl;
    cout << "        RESUMEN DEL INVENTARIO" << endl;
    cout << "=============================================" << endl;
    cout << " PRODUCTO MÁS CARO:" << endl;
    cout << "  Nombre: " << productoMasCaro.nombre << endl;
    cout << "  Código: " << productoMasCaro.codigo << endl;
    cout << "  Precio: " << productoMasCaro.precio << endl;
    cout << "  Cantidad: " << productoMasCaro.cantidad_en_inventario << endl;
    cout << "  Observaciones: " << productoMasCaro.observaciones << endl;
    cout << "\n CANTIDAD TOTAL DE PRODUCTOS:" << endl;
    cout << "  Total de unidades en inventario: " << cantidadTotal << endl;
    cout << "=============================================" << endl;
    return 0;
}