#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <iomanip>
#include <sstream>
#include <limits>

using namespace std;

struct structProducto
{
 int codigo;
 char nombre[30];
 int cantidadInicial;
 float precioUnitario;
 int cantidadVendida;
 float totalVendido;
};

struct structVenta
{
 char ciCliente[10];
 char nombreCliente[30];
 int codigoProducto;
 int cantidad;
};

void mostrarMenu()
{
 cout << "\n--- MENU FARMACIAS CHAVEZ ---" << endl;
 cout << "1. Adicionar Producto." << endl;
 cout << "2. Listado de Productos." << endl;
 cout << "3. Buscar un producto por codigo." << endl;
 cout << "4. Modificar un producto." << endl;
 cout << "5. Adicionar ventas del producto." << endl;
 cout << "6. Salir." << endl;
 cout << "Ingrese su opcion: ";
}

void adicionarProducto()
{
 structProducto nuevoProducto = {};
 cout << "\n--- ADICIONAR PRODUCTO ---" << endl;
 cout << "Codigo Producto: ";
 cin >> nuevoProducto.codigo;
 fstream archivoIn("PRODUCTOS.BIN", ios::binary | ios::in | ios::out);
 structProducto tempProducto;
 bool duplicado = false;
 if (archivoIn.is_open())
 {
  while (archivoIn.read((char*)&tempProducto, sizeof(structProducto)))
  {
   if (tempProducto.codigo == nuevoProducto.codigo)
   {
    duplicado = true;
    break;
   }
  }
  archivoIn.close();
 }
 if (duplicado)
 {
  cout << "ERROR: El producto con codigo " << nuevoProducto.codigo << " ya esta registrado." << endl;
  return;
 }
 cout << "Nombre Producto (max 29 caracteres): ";
 cin.ignore(numeric_limits<streamsize>::max(), '\n');
 cin.getline(nuevoProducto.nombre, 30);
 cout << "Cantidad Inicial: ";
 cin >> nuevoProducto.cantidadInicial;
 cout << "Precio Unitario: ";
 cin >> nuevoProducto.precioUnitario;
 nuevoProducto.cantidadVendida = 0;
 nuevoProducto.totalVendido = 0.0f;
 ofstream archivoOut("PRODUCTOS.BIN", ios::binary | ios::app);
 if (archivoOut.is_open())
 {
  archivoOut.write((char*)&nuevoProducto, sizeof(structProducto));
  archivoOut.close();
  cout << "Producto registrado con exito." << endl;
 }
 else
 {
  cout << "ERROR: No se pudo abrir el archivo de productos para escritura." << endl;
 }
}

void listarProductos()
{
 cout << "\n--- LISTADO DE PRODUCTOS ---" << endl;
 ifstream archivoIn("PRODUCTOS.BIN", ios::binary);
 if (!archivoIn.is_open())
 {
  cout << "ADVERTENCIA: No se encontro el archivo de productos ('PRODUCTOS.BIN')." << endl;
  return;
 }
 structProducto producto;
 cout << left << setw(8) << "CODIGO" << setw(30) << "NOMBRE PRODUCTO" << setw(18) << "CANTIDAD INICIAL" << setw(10) << "PRECIO" << setw(18) << "CANTIDAD VENDIDA" << setw(10) << "TOTAL" << endl;
 cout << "-------------------------------------------------------------------------------------------------------" << endl;
 while (archivoIn.read((char*)&producto, sizeof(structProducto)))
 {
  cout << fixed << setprecision(2);
  cout << left << setw(8) << producto.codigo << setw(30) << producto.nombre << setw(18) << producto.cantidadInicial << setw(10) << producto.precioUnitario << setw(18) << producto.cantidadVendida << setw(10) << producto.totalVendido << endl;
 }
 archivoIn.close();
}

void buscarProducto()
{
 int codigoBuscado;
 cout << "\n--- BUSCAR PRODUCTO POR CODIGO ---" << endl;
 cout << "Ingrese el codigo del producto a buscar: ";
 cin >> codigoBuscado;
 ifstream archivoIn("PRODUCTOS.BIN", ios::binary);
 if (!archivoIn.is_open())
 {
  cout << "ADVERTENCIA: No se encontro el archivo de productos ('PRODUCTOS.BIN')." << endl;
  return;
 }
 structProducto producto;
 bool encontrado = false;
 while (archivoIn.read((char*)&producto, sizeof(structProducto)))
 {
  if (producto.codigo == codigoBuscado)
  {
   encontrado = true;
   break;
  }
 }
 archivoIn.close();
 if (encontrado)
 {
  cout << "\n--- PRODUCTO ENCONTRADO ---" << endl;
  cout << left << setw(20) << "Codigo:" << producto.codigo << endl;
  cout << left << setw(20) << "Nombre:" << producto.nombre << endl;
  cout << left << setw(20) << "Cantidad Inicial:" << producto.cantidadInicial << endl;
  cout << fixed << setprecision(2);
  cout << left << setw(20) << "Precio Unitario:" << producto.precioUnitario << endl;
  cout << left << setw(20) << "Cantidad Vendida:" << producto.cantidadVendida << endl;
  cout << left << setw(20) << "Total Vendido:" << producto.totalVendido << endl;
 }
 else
 {
  cout << "Producto con codigo " << codigoBuscado << " no encontrado." << endl;
 }
}

void modificarProducto()
{
 int codigoModificar;
 cout << "\n--- MODIFICAR PRODUCTO ---" << endl;
 cout << "Ingrese el codigo del producto a modificar: ";
 cin >> codigoModificar;
 fstream archivo("PRODUCTOS.BIN", ios::binary | ios::in | ios::out);
 if (!archivo.is_open())
 {
  cout << "ADVERTENCIA: No se encontro el archivo de productos ('PRODUCTOS.BIN')." << endl;
  return;
 }
 structProducto producto;
 bool encontrado = false;
 long int posicionRegistro = 0;
 while (archivo.read((char*)&producto, sizeof(structProducto)))
 {
  if (producto.codigo == codigoModificar)
  {
   encontrado = true;
   break;
  }
  posicionRegistro = archivo.tellg();
 }
 if (encontrado)
 {
  cout << "\nProducto actual: " << producto.nombre << ", Cantidad Inicial: " << producto.cantidadInicial << ", Precio: " << producto.precioUnitario << endl;
  cout << "Nuevo Nombre (max 29 caracteres): ";
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cin.getline(producto.nombre, 30);
  cout << "Nueva Cantidad Inicial: ";
  cin >> producto.cantidadInicial;
  cout << "Nuevo Precio Unitario: ";
  cin >> producto.precioUnitario;
  archivo.seekp(posicionRegistro);
  archivo.write((char*)&producto, sizeof(structProducto));
  cout << "Producto modificado con exito." << endl;
 }
 else
 {
  cout << "Producto con codigo " << codigoModificar << " no encontrado." << endl;
 }
 archivo.close();
}

structVenta parseLineaVenta(const string& linea)
{
 structVenta venta = {};
 stringstream ss(linea);
 string campo;
 getline(ss, campo, ';');
 if (campo.length() > 0) strncpy(venta.ciCliente, campo.c_str(), 9);
 venta.ciCliente[9] = '\0';
 getline(ss, campo, ';');
 if (campo.length() > 0) strncpy(venta.nombreCliente, campo.c_str(), 29);
 venta.nombreCliente[29] = '\0';
 getline(ss, campo, ';');
 try { venta.codigoProducto = stoi(campo); } catch (...) { venta.codigoProducto = -1; }
 getline(ss, campo, ';');
 try { venta.cantidad = stoi(campo); } catch (...) { venta.cantidad = 0; }
 return venta;
}

void adicionarVentas()
{
 cout << "\n--- ADICIONAR VENTAS DEL PRODUCTO (Desde VENTAS.txt) ---" << endl;
 ifstream archivoVentas("VENTAS.txt");
 if (!archivoVentas.is_open())
 {
  cout << "ERROR: No se pudo abrir el archivo de ventas ('VENTAS.txt')." << endl;
  return;
 }
 fstream archivoProductos("PRODUCTOS.BIN", ios::binary | ios::in | ios::out);
 if (!archivoProductos.is_open())
 {
  cout << "ADVERTENCIA: No se encontro el archivo de productos ('PRODUCTOS.BIN'). No se procesaran ventas." << endl;
  archivoVentas.close();
  return;
 }
 string linea;
 int ventasProcesadas = 0;
 while (getline(archivoVentas, linea))
 {
  structVenta venta = parseLineaVenta(linea);
  if (venta.codigoProducto == -1 || venta.cantidad <= 0)
  {
   cout << "ADVERTENCIA: Linea de venta ignorada por formato invalido o cantidad no positiva: " << linea << endl;
   continue;
  }
  archivoProductos.seekg(0, ios::beg);
  structProducto producto;
  bool encontrado = false;
  long int posicionRegistro = 0;
  while (archivoProductos.read((char*)&producto, sizeof(structProducto)))
  {
   if (producto.codigo == venta.codigoProducto)
   {
    encontrado = true;
    break;
   }
   posicionRegistro = archivoProductos.tellg();
  }
  if (encontrado)
  {
   if (venta.cantidad > producto.cantidadInicial)
   {
    cout << "ADVERTENCIA: Venta de " << venta.cantidad << " unidades de " << producto.nombre << " ignorada (Supera el stock inicial de " << producto.cantidadInicial << "). Linea: " << linea << endl;
   }
   else
   {
    producto.cantidadVendida += venta.cantidad;
    producto.totalVendido += (float)venta.cantidad * producto.precioUnitario;
    archivoProductos.seekp(posicionRegistro);
    archivoProductos.write((char*)&producto, sizeof(structProducto));
    ventasProcesadas++;
   }
  }
  else
  {
   cout << "ADVERTENCIA: Producto con codigo " << venta.codigoProducto << " no encontrado en 'PRODUCTOS.BIN'. Linea: " << linea << endl;
  }
 }
 archivoVentas.close();
 archivoProductos.close();
 cout << "Proceso de ventas finalizado. Se procesaron " << ventasProcesadas << " transacciones exitosamente." << endl;
}

int main()
{
 int opcion;
 do
 {
  mostrarMenu();
  if (!(cin >> opcion))
  {
   cin.clear();
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
   opcion = 0;
  }
  switch (opcion)
  {
   case 1:
    adicionarProducto();
    break;
   case 2:
    listarProductos();
    break;
   case 3:
    buscarProducto();
    break;
   case 4:
    modificarProducto();
    break;
   case 5:
    adicionarVentas();
    break;
   case 6:
    cout << "Saliendo del programa. ¡Hasta pronto!" << endl;
    break;
   default:
    cout << "Opcion invalida. Intente de nuevo." << endl;
  }
 } while (opcion != 6);
 return 0;
}