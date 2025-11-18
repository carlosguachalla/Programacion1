#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAX_NOMBRE = 20;
const int MAX_TIPO = 15;
const int MAX_TAMANO = 15;

struct Pizza {
    int codigo;
    char nombre[MAX_NOMBRE];
    char tipo[MAX_TIPO];
    char tamano[MAX_TAMANO];
    float precio;
};

const string ARCHIVO_PRODUCTOS = "PRODUCTO.BIN";
const string ARCHIVO_VENTAS = "VENTAS.TXT";

void mostrarMenu();
void adicionarPizza();
void listarPizzas();
void modificarPrecio();
void eliminarPizza();
void adicionarVenta();

int main() {
    int opcion;

    do {
        mostrarMenu();
        cout << "Ingrese su opcion: ";
        if (!(cin >> opcion)) {
            cout << "Entrada invalida. Por favor, ingrese un numero." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            opcion = -1;
            continue;
        }

        switch (opcion) {
            case 1: adicionarPizza(); break;
            case 2: listarPizzas(); break;
            case 3: modificarPrecio(); break;
            case 4: eliminarPizza(); break;
            case 5: adicionarVenta(); break;
            case 0: cout << "Saliendo del programa. ¡Hasta luego!" << endl; break;
            default: cout << "Opcion no valida. Intente de nuevo." << endl; break;
        }
        cout << "\n----------------------------------------\n";
    } while (opcion != 0);

    return 0;
}

void mostrarMenu() {
    cout << "\n========== MENU PIZZERIA ELIS ==========\n";
    cout << "1. Adicionar Pizza\n";
    cout << "2. Listado de Pizzas\n";
    cout << "3. Modificar el precio de la Pizza segun el codigo\n";
    cout << "4. Eliminar una Pizza\n";
    cout << "5. Adicionar Venta de Pizzas\n";
    cout << "0. Salir\n";
    cout << "========================================\n";
}

void adicionarPizza() {
    Pizza p;
    cout << "\n--- Adicionar Nueva Pizza ---\n";

    cout << "Codigo: ";
    cin >> p.codigo;
    cin.ignore();

    cout << "Nombre: ";
    string temp_nombre;
    getline(cin, temp_nombre);
    strncpy(p.nombre, temp_nombre.c_str(), MAX_NOMBRE - 1);
    p.nombre[MAX_NOMBRE - 1] = '\0';

    string temp_tipo;
    do {
        cout << "Tipo (TRADICIONAL/ESPECIAL): ";
        getline(cin, temp_tipo);
    } while (temp_tipo != "TRADICIONAL" && temp_tipo != "ESPECIAL");
    strncpy(p.tipo, temp_tipo.c_str(), MAX_TIPO - 1);
    p.tipo[MAX_TIPO - 1] = '\0';

    cout << "Tamanos disponibles: XS, Mediana, Grande, Familiar, Interminable.\n";
    cout << "Tamano: ";
    string temp_tamano;
    getline(cin, temp_tamano);
    strncpy(p.tamano, temp_tamano.c_str(), MAX_TAMANO - 1);
    p.tamano[MAX_TAMANO - 1] = '\0';

    cout << "Precio Base (Bs): ";
    cin >> p.precio;

    if (temp_tipo == "ESPECIAL") {
        p.precio *= 1.10;
    }

    ofstream archivo(ARCHIVO_PRODUCTOS, ios::binary | ios::app);
    if (!archivo) {
        cerr << "ERROR: No se pudo abrir el archivo " << ARCHIVO_PRODUCTOS << endl;
        return;
    }

    archivo.write(reinterpret_cast<const char*>(&p), sizeof(Pizza));
    archivo.close();
    cout << "Pizza '" << p.nombre << "' (Codigo " << p.codigo << ") agregada exitosamente. Precio final: " 
         << fixed << setprecision(2) << p.precio << " Bs.\n";
}

void listarPizzas() {
    ifstream archivo(ARCHIVO_PRODUCTOS, ios::binary);
    if (!archivo) {
        cout << "El catalogo de pizzas (" << ARCHIVO_PRODUCTOS << ") no existe o esta vacio." << endl;
        return;
    }

    Pizza p;
    cout << "\n========== LISTADO DE PIZZAS ==========\n";
    cout << left << setw(8) << "CODIGO" << setw(22) << "NOMBRE" << setw(15) << "TIPO"
         << setw(15) << "TAMAÑO" << right << setw(10) << "PRECIO (Bs)" << endl;
    cout << setfill('-') << setw(70) << "-" << setfill(' ') << endl;

    while (archivo.read(reinterpret_cast<char*>(&p), sizeof(Pizza))) {
        cout << left << setw(8) << p.codigo << setw(22) << p.nombre << setw(15) << p.tipo
             << setw(15) << p.tamano << right << setw(10) << fixed << setprecision(2) << p.precio << endl;
    }

    archivo.close();
    cout << setfill('-') << setw(70) << "-" << setfill(' ') << endl;
}

void modificarPrecio() {
    int codigo_buscado;
    float nuevo_precio_base;
    bool encontrado = false;

    cout << "\n--- Modificar Precio por Codigo ---\n";
    cout << "Ingrese el Codigo de la pizza a modificar: ";
    cin >> codigo_buscado;
    cout << "Ingrese el NUEVO Precio BASE (Bs): ";
    cin >> nuevo_precio_base;

    fstream archivo(ARCHIVO_PRODUCTOS, ios::binary | ios::in | ios::out);
    if (!archivo) {
        cerr << "ERROR: No se pudo abrir el archivo " << ARCHIVO_PRODUCTOS << endl;
        return;
    }

    Pizza p;
    while (archivo.read(reinterpret_cast<char*>(&p), sizeof(Pizza))) {
        if (p.codigo == codigo_buscado) {
            float nuevo_precio = nuevo_precio_base;

            if (strcmp(p.tipo, "ESPECIAL") == 0) {
                nuevo_precio *= 1.10;
            }

            p.precio = nuevo_precio;

            archivo.seekp(-static_cast<streamoff>(sizeof(Pizza)), ios::cur);
            archivo.write(reinterpret_cast<const char*>(&p), sizeof(Pizza));

            cout << "Precio de la pizza '" << p.nombre << "' (Cod " << p.codigo << ") modificado a "
                 << fixed << setprecision(2) << p.precio << " Bs." << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "ERROR: Pizza con Codigo " << codigo_buscado << " no encontrada." << endl;
    }

    archivo.close();
}

void eliminarPizza() {
    int codigo_a_eliminar;
    bool encontrado = false;

    cout << "\n--- Eliminar Pizza por Codigo ---\n";
    cout << "Ingrese el Codigo de la pizza a eliminar: ";
    cin >> codigo_a_eliminar;

    ifstream archivo_in(ARCHIVO_PRODUCTOS, ios::binary);
    if (!archivo_in) {
        cout << "El catalogo de pizzas (" << ARCHIVO_PRODUCTOS << ") no existe." << endl;
        return;
    }

    ofstream archivo_out("TEMP.BIN", ios::binary);
    if (!archivo_out) {
        cerr << "ERROR: No se pudo crear el archivo temporal." << endl;
        archivo_in.close();
        return;
    }

    Pizza p;
    while (archivo_in.read(reinterpret_cast<char*>(&p), sizeof(Pizza))) {
        if (p.codigo != codigo_a_eliminar) {
            archivo_out.write(reinterpret_cast<const char*>(&p), sizeof(Pizza));
        } else {
            encontrado = true;
        }
    }

    archivo_in.close();
    archivo_out.close();

    if (remove(ARCHIVO_PRODUCTOS.c_str()) != 0) {
        cerr << "ERROR: No se pudo eliminar el archivo original." << endl;
        return;
    }
    if (rename("TEMP.BIN", ARCHIVO_PRODUCTOS.c_str()) != 0) {
        cerr << "ERROR: No se pudo renombrar el archivo temporal." << endl;
        return;
    }

    if (encontrado) {
        cout << "Pizza con Codigo " << codigo_a_eliminar << " eliminada exitosamente." << endl;
    } else {
        cout << "ERROR: Pizza con Codigo " << codigo_a_eliminar << " no encontrada." << endl;
    }
}
void adicionarVenta() {
    cout << "\n--- Adicionar Venta de Pizzas (Desde " << ARCHIVO_VENTAS << ") ---\n";

    ifstream archivo_ventas(ARCHIVO_VENTAS);
    if (!archivo_ventas) {
        cerr << "ERROR: No se pudo abrir el archivo de ventas " << ARCHIVO_VENTAS 
             << ". Asegurese de que exista en el directorio de ejecucion." << endl;
        return;
    }

    cout << setfill(' ') << left << setw(15) << "CARNET" << setw(8) << "CODIGO" << setw(20) << "NOMBRE PIZZA"
         << setw(10) << "PRECIO" << setw(10) << "CANTIDAD" << right << setw(10) << "TOTAL (Bs)" << endl;
    cout << setfill('-') << setw(73) << "-" << setfill(' ') << endl;

    string linea;
    float total_general = 0.0;
    int contador_ventas = 0;

    while (getline(archivo_ventas, linea)) {
        stringstream ss(linea);
        string segmento;
        string carnet, tamano_venta;
        int codigo_venta = -1;
        int cantidad = 0;

        try {
            if (getline(ss, carnet, ';') &&
                getline(ss, segmento, ';') && (codigo_venta = stoi(segmento), true) &&
                getline(ss, tamano_venta, ';') &&
                getline(ss, segmento, ';') && (cantidad = stoi(segmento), true)) 
            {
                ifstream archivo_productos(ARCHIVO_PRODUCTOS, ios::binary);
                Pizza p;
                bool pizza_encontrada = false;

                while (archivo_productos.read(reinterpret_cast<char*>(&p), sizeof(Pizza))) {
                    if (p.codigo == codigo_venta) {
                        pizza_encontrada = true;
                        break;
                    }
                }
                archivo_productos.close();

                if (pizza_encontrada) {
                    float total_venta = p.precio * cantidad;
                    total_general += total_venta;
                    contador_ventas++;
                    
                    cout << left << setw(15) << carnet << setw(8) << codigo_venta << setw(20) << p.nombre
                         << fixed << setprecision(2) << setw(10) << p.precio << setw(10) << cantidad 
                         << right << setw(10) << total_venta << endl;
                } else {
                    cout << "ADVERTENCIA: Codigo de pizza " << codigo_venta << " de la venta (Cliente " << carnet << ") NO encontrado en el catalogo." << endl;
                }
            } else {
                cerr << "ERROR: Formato de linea de venta incorrecto: " << linea << endl;
            }
        } catch (const std::exception& e) {
            cerr << "ERROR: Fallo en la conversion numerica en la linea: " << linea << endl;
        }
    }

    archivo_ventas.close();
    
    cout << setfill('-') << setw(73) << "-" << setfill(' ') << endl;
    if (contador_ventas > 0) {
        cout << right << setw(63) << "TOTAL GENERAL DE VENTAS: " << fixed << setprecision(2) << total_general << " Bs." << endl;
    } else {
        cout << "No se procesaron ventas validas." << endl;
    }
}