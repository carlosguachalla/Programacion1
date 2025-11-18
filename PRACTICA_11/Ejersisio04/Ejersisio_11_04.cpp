#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAX_NOMBRE = 20;
const int MAX_APELLIDO = 20;
const int MAX_MATERIA = 30;

struct Estudiante {
    int carnet;
    char nombres[MAX_NOMBRE];
    char apellidos[MAX_APELLIDO];
    char materia[MAX_MATERIA];
    int paralelo;
    float notaHabilitacion;
};

const string ARCHIVO_ESTUDIANTES = "ESTUDIANTES.BIN";

void mostrarMenu();
void adicionarEstudiante();
void listarEstudiantes();
void eliminarEstudiante();
void adicionarNotasHabilitacion();

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
            case 1: adicionarEstudiante(); break;
            case 2: listarEstudiantes(); break;
            case 3: eliminarEstudiante(); break;
            case 4: adicionarNotasHabilitacion(); break;
            case 0: cout << "Saliendo del programa. ¡Hasta luego!" << endl; break;
            default: cout << "Opcion no valida. Intente de nuevo." << endl; break;
        }
        cout << "\n----------------------------------------\n";
    } while (opcion != 0);

    return 0;
}

void mostrarMenu() {
    cout << "\n========== MENU NOTAS UCAB ==========\n";
    cout << "1. Adicionar Estudiante\n";
    cout << "2. Listado de Estudiantes Habilitados\n";
    cout << "3. Eliminar un Estudiante\n";
    cout << "4. Adicionar notas habilitacion\n";
    cout << "0. Salir\n";
    cout << "=====================================\n";
}

void adicionarEstudiante() {
    Estudiante e;
    cout << "\n--- Adicionar Nuevo Estudiante ---\n";

    cout << "Carnet Identidad: ";
    cin >> e.carnet;
    cin.ignore();

    cout << "Nombres: ";
    string temp_nombres;
    getline(cin, temp_nombres);
    strncpy(e.nombres, temp_nombres.c_str(), MAX_NOMBRE - 1);
    e.nombres[MAX_NOMBRE - 1] = '\0';

    cout << "Apellidos: ";
    string temp_apellidos;
    getline(cin, temp_apellidos);
    strncpy(e.apellidos, temp_apellidos.c_str(), MAX_APELLIDO - 1);
    e.apellidos[MAX_APELLIDO - 1] = '\0';

    cout << "Materia: ";
    string temp_materia;
    getline(cin, temp_materia);
    strncpy(e.materia, temp_materia.c_str(), MAX_MATERIA - 1);
    e.materia[MAX_MATERIA - 1] = '\0';

    cout << "Paralelo: ";
    cin >> e.paralelo;
    
    e.notaHabilitacion = 0.0;

    ofstream archivo(ARCHIVO_ESTUDIANTES, ios::binary | ios::app);
    if (!archivo) {
        cerr << "ERROR: No se pudo abrir el archivo " << ARCHIVO_ESTUDIANTES << endl;
        return;
    }

    archivo.write(reinterpret_cast<const char*>(&e), sizeof(Estudiante));
    archivo.close();
    cout << "Estudiante (Carnet " << e.carnet << ") agregado exitosamente.\n";
}

void listarEstudiantes() {
    ifstream archivo(ARCHIVO_ESTUDIANTES, ios::binary);
    if (!archivo) {
        cout << "El archivo de estudiantes (" << ARCHIVO_ESTUDIANTES << ") no existe o esta vacio." << endl;
        return;
    }

    Estudiante e;
    float suma_habilitacion = 0.0;
    int contador_habilitados = 0;

    cout << "\n========== LISTADO DE ESTUDIANTES HABILITADOS ==========\n";
    cout << left << setw(8) << "CARNET" << setw(15) << "NOMBRES" << setw(15) << "APELLIDOS"
         << setw(25) << "MATERIA" << setw(10) << "PARALELO" << setw(10) << "NOTA" 
         << right << setw(15) << "ESTADO" << endl;
    cout << setfill('-') << setw(100) << "-" << setfill(' ') << endl;

    while (archivo.read(reinterpret_cast<char*>(&e), sizeof(Estudiante))) {
        string estado;
        if (e.notaHabilitacion >= 60.0) {
            estado = "HABILITADO";
            suma_habilitacion += e.notaHabilitacion;
            contador_habilitados++;
        } else {
            estado = "NO HABILITADO";
        }

        cout << left << setw(8) << e.carnet << setw(15) << e.nombres << setw(15) << e.apellidos
             << setw(25) << e.materia << setw(10) << e.paralelo << setw(10) << fixed << setprecision(1) << e.notaHabilitacion 
             << right << setw(15) << estado << endl;
    }

    archivo.close();
    cout << setfill('-') << setw(100) << "-" << setfill(' ') << endl;

    if (contador_habilitados > 0) {
        float promedio = suma_habilitacion / contador_habilitados;
        cout << "PROMEDIO DE NOTAS DE HABILITACION (de estudiantes >= 60.0): " 
             << fixed << setprecision(1) << promedio << endl;
    } else {
        cout << "No hay estudiantes con nota de habilitacion mayor o igual a 60.0 para calcular promedio." << endl;
    }
}

void eliminarEstudiante() {
    int carnet_a_eliminar;
    bool encontrado = false;

    cout << "\n--- Eliminar Estudiante por Carnet ---\n";
    cout << "Ingrese el Carnet del estudiante a eliminar: ";
    cin >> carnet_a_eliminar;

    ifstream archivo_in(ARCHIVO_ESTUDIANTES, ios::binary);
    if (!archivo_in) {
        cout << "El archivo de estudiantes (" << ARCHIVO_ESTUDIANTES << ") no existe." << endl;
        return;
    }

    ofstream archivo_out("TEMP.BIN", ios::binary);
    if (!archivo_out) {
        cerr << "ERROR: No se pudo crear el archivo temporal." << endl;
        archivo_in.close();
        return;
    }

    Estudiante e;
    while (archivo_in.read(reinterpret_cast<char*>(&e), sizeof(Estudiante))) {
        if (e.carnet != carnet_a_eliminar) {
            archivo_out.write(reinterpret_cast<const char*>(&e), sizeof(Estudiante));
        } else {
            encontrado = true;
        }
    }

    archivo_in.close();
    archivo_out.close();

    if (remove(ARCHIVO_ESTUDIANTES.c_str()) != 0) {
        cerr << "ERROR: No se pudo eliminar el archivo original." << endl;
        return;
    }
    if (rename("TEMP.BIN", ARCHIVO_ESTUDIANTES.c_str()) != 0) {
        cerr << "ERROR: No se pudo renombrar el archivo temporal." << endl;
        return;
    }

    if (encontrado) {
        cout << "Estudiante con Carnet " << carnet_a_eliminar << " eliminado exitosamente." << endl;
    } else {
        cout << "ERROR: Estudiante con Carnet " << carnet_a_eliminar << " no encontrado." << endl;
    }
}

void adicionarNotasHabilitacion() {
    int carnet_buscado;
    bool encontrado = false;
    string notas_str;

    cout << "\n--- Adicionar Notas de Habilitacion ---\n";
    cout << "Ingrese el Carnet del estudiante: ";
    cin >> carnet_buscado;
    cin.ignore();

    cout << "Ingrese las notas separadas por punto y coma (ej: 80;33.33;75;33.34): ";
    getline(cin, notas_str);

    stringstream ss(notas_str);
    string segmento;
    float nota_sumada = 0.0;
    int cantidad_notas = 0;
    float nota_menor_a_60 = -1.0; 
    bool todas_mayores_a_60 = true;

    try {
        while (getline(ss, segmento, ';')) {
            float nota = stof(segmento);
            nota_sumada += nota;
            cantidad_notas++;
            if (nota < 60.0) {
                todas_mayores_a_60 = false;
                if (nota_menor_a_60 == -1.0 || nota < nota_menor_a_60) {
                    nota_menor_a_60 = nota;
                }
            }
        }
    } catch (const std::exception& e) {
        cerr << "ERROR: Formato de notas invalido. Asegurese de usar ';'" << endl;
        return;
    }

    if (cantidad_notas == 0) {
        cout << "No se ingresaron notas validas." << endl;
        return;
    }

    float nueva_nota_habilitacion = todas_mayores_a_60 ? nota_sumada / cantidad_notas : (nota_menor_a_60 != -1.0 ? nota_menor_a_60 : 0.0);
    
    if (todas_mayores_a_60) {
        cout << "PROMEDIO CALCULADO: " << fixed << setprecision(1) << nueva_nota_habilitacion << endl;
    } else {
        cout << "NOTA MENOR A 60 ENCONTRADA: " << fixed << setprecision(1) << nota_menor_a_60 << endl;
        cout << "NOTA DE HABILITACION ASIGNADA: " << fixed << setprecision(1) << nueva_nota_habilitacion << endl;
    }

    fstream archivo(ARCHIVO_ESTUDIANTES, ios::binary | ios::in | ios::out);
    if (!archivo) {
        cerr << "ERROR: No se pudo abrir el archivo " << ARCHIVO_ESTUDIANTES << endl;
        return;
    }

    Estudiante e;
    while (archivo.read(reinterpret_cast<char*>(&e), sizeof(Estudiante))) {
        if (e.carnet == carnet_buscado) {
            e.notaHabilitacion = nueva_nota_habilitacion;

            archivo.seekp(-static_cast<streamoff>(sizeof(Estudiante)), ios::cur);
            archivo.write(reinterpret_cast<const char*>(&e), sizeof(Estudiante));

            cout << "Nota de habilitacion para el estudiante (Carnet " << e.carnet << ") actualizada a "
                 << fixed << setprecision(1) << e.notaHabilitacion << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "ERROR: Estudiante con Carnet " << carnet_buscado << " no encontrado." << endl;
    }

    archivo.close();
}