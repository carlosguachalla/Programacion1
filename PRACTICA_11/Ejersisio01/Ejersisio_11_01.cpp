#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;
// Estructura para los datos del estudiante
struct structEstudiante
{
 char ci[10];
 char nombres[30];
 char apellidos[30];
};
// Estructura para las notas
struct structNotas
{
 char ci[10];
 char materia[30];
 int nota;
};
// Función para mostrar el menú
void mostrarMenu()
{
 cout << "\n--- MENU PRINCIPAL ---" << endl;
 cout << "1. Ingreso de datos estudiantes." << endl;
 cout << "2. Ingreso de materias y notas." << endl;
 cout << "3. Reporte de estudiantes y notas ingresadas." << endl;
 cout << "4. Salir." << endl;
 cout << "Ingrese su opcion: ";
}
// Opcion 1: Ingreso de datos estudiantes
void ingresoEstudiante()
{
 structEstudiante nuevoEstudiante;
 cout << "\n--- INGRESO DE ESTUDIANTE ---" << endl;
 
 cout << "CI (max 9 caracteres): ";
 cin >> nuevoEstudiante.ci;
 
 // Verificar si el estudiante ya existe
 ifstream archivoIn("Estudiantes.bin", ios::binary);
 structEstudiante tempEstudiante;
 bool duplicado = false;
 
 if (archivoIn.is_open())
 {
  while (archivoIn.read((char*)&tempEstudiante, sizeof(structEstudiante)))
  {
   if (strcmp(tempEstudiante.ci, nuevoEstudiante.ci) == 0)
   {
    duplicado = true;
    break;
   }
  }
  archivoIn.close();
 }
 
 if (duplicado)
 {
  cout << "ERROR: El estudiante con CI " << nuevoEstudiante.ci << " ya esta registrado." << endl;
  return;
 }
 // Si no es duplicado, pedir el resto de los datos y guardar
 cout << "Nombres (max 29 caracteres): ";
 cin.ignore();
 cin.getline(nuevoEstudiante.nombres, 30);
 
 cout << "Apellidos (max 29 caracteres): ";
 cin.getline(nuevoEstudiante.apellidos, 30);
 ofstream archivoOut("Estudiantes.bin", ios::binary | ios::app);
 if (archivoOut.is_open())
 {
  archivoOut.write((char*)&nuevoEstudiante, sizeof(structEstudiante));
  archivoOut.close();
  cout << "Estudiante registrado con exito." << endl;
 }
 else
 {
  cout << "ERROR: No se pudo abrir el archivo de estudiantes para escritura." << endl;
 }
}
// Opcion 2: Ingreso de materias y notas
void ingresoNotas()
{
 structNotas nuevaNota;
 cout << "\n--- INGRESO DE NOTAS ---" << endl;
 cout << "CI del estudiante (max 9 caracteres): ";
 cin >> nuevaNota.ci;
 // 1. Verificar si el estudiante existe
 ifstream archivoEstudiantes("Estudiantes.bin", ios::binary);
 bool existeEstudiante = false;
 structEstudiante tempEstudiante;
 if (archivoEstudiantes.is_open())
 {
  while (archivoEstudiantes.read((char*)&tempEstudiante, sizeof(structEstudiante)))
  {
   if (strcmp(tempEstudiante.ci, nuevaNota.ci) == 0)
   {
    existeEstudiante = true;
    break;
   }
  }
  archivoEstudiantes.close();
 }
 if (!existeEstudiante)
 {
  cout << "ERROR: El estudiante con CI " << nuevaNota.ci << " no existe." << endl;
  return;
 }
 cout << "Materia (max 29 caracteres): ";
 cin.ignore();
 cin.getline(nuevaNota.materia, 30);
 // 2. Verificar si la nota para esa materia y CI ya existe (no duplicar)
 ifstream archivoNotasIn("Notas.bin", ios::binary);
 structNotas tempNota;
 bool notaDuplicada = false;
 if (archivoNotasIn.is_open())
 {
  while (archivoNotasIn.read((char*)&tempNota, sizeof(structNotas)))
  {
   if (strcmp(tempNota.ci, nuevaNota.ci) == 0 && strcmp(tempNota.materia, nuevaNota.materia) == 0)
   {
    notaDuplicada = true;
    break;
   }
  }
  archivoNotasIn.close();
 }
 if (notaDuplicada)
 {
  cout << "ERROR: La nota para la materia '" << nuevaNota.materia << "' del estudiante " << nuevaNota.ci << " ya ha sido ingresada." << endl;
  return;
 }
 // 3. Ingresar la nota y guardar
 cout << "Nota (entero): ";
 cin >> nuevaNota.nota;
 ofstream archivoNotasOut("Notas.bin", ios::binary | ios::app);
 if (archivoNotasOut.is_open())
 {
  archivoNotasOut.write((char*)&nuevaNota, sizeof(structNotas));
  archivoNotasOut.close();
  cout << "Nota registrada con exito." << endl;
 }
 else
 {
  cout << "ERROR: No se pudo abrir el archivo de notas para escritura." << endl;
 }
}
// Opcion 3: Reporte de estudiantes y notas
void reporte()
{
 cout << "\n--- REPORTE DE ESTUDIANTES Y NOTAS ---" << endl;
 // Lectura de estudiantes
 ifstream archivoEstudiantes("Estudiantes.bin", ios::binary);
 if (!archivoEstudiantes.is_open())
 {
  cout << "ADVERTENCIA: No se encontro el archivo de estudiantes ('Estudiantes.bin')." << endl;
  return;
 }
 structEstudiante estudiante;
 vector<structEstudiante> listaEstudiantes;
 while (archivoEstudiantes.read((char*)&estudiante, sizeof(structEstudiante)))
 {
  listaEstudiantes.push_back(estudiante);
 }
 archivoEstudiantes.close();
 
 if (listaEstudiantes.empty())
 {
  cout << "No hay estudiantes registrados." << endl;
  return;
 }
 // Lectura de notas
 ifstream archivoNotas("Notas.bin", ios::binary);
 vector<structNotas> listaNotas;
 structNotas nota;
 
 if (archivoNotas.is_open())
 {
  while (archivoNotas.read((char*)&nota, sizeof(structNotas)))
  {
   listaNotas.push_back(nota);
  }
  archivoNotas.close();
 }

 // Generar reporte
 for (const auto& est : listaEstudiantes)
 {
  cout << "\n------------------------------------------------------------" << endl;
  cout << "CI: " << est.ci << endl;
  cout << "Nombre: " << est.nombres << " " << est.apellidos << endl;
  cout << "Notas:" << endl;
  
  bool tieneNotas = false;
  cout << left << setw(30) << "Materia" << "Nota" << endl;
  cout << "---------------------------------" << endl;
  
  for (const auto& n : listaNotas)
  {
   if (strcmp(est.ci, n.ci) == 0)
   {
    cout << left << setw(30) << n.materia << n.nota << endl;
    tieneNotas = true;
   }
  }

  if (!tieneNotas)
  {
   cout << "   (No tiene notas asignadas)" << endl;
  }
 }
 cout << "\n------------------------------------------------------------" << endl;
}
int main()
{
 int opcion;
 
 do
 {
  mostrarMenu();
  cin >> opcion;
  
  switch (opcion)
  {
   case 1:
    ingresoEstudiante();
    break;
   case 2:
    ingresoNotas();
    break;
   case 3:
    reporte();
    break;
   case 4:
    cout << "Saliendo del programa. ¡Hasta pronto!" << endl;
    break;
   default:
    cout << "Opcion invalida. Intente de nuevo." << endl;
  }
 } while (opcion != 4);
 
 return 0;
}