#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

///Prototipos

// Estructuras

struct Clientes;
struct Fecha;
struct Plato;
struct Pedidos;

///Platos

bool RestaurarPlatos(Plato *);
bool BackUpPlatos(Plato *);
void ListarXResr();
void ModificarCostoyTiempo();
void ListarPlato();
void NuevoPlato();
int BuscarPlato(int);
struct Plato LeerPlato(int);
bool GuardarPlato(Plato, bool);
bool CargarPlato(Plato *);
void EliminarPlato();
bool ListarPlatos();
int CantidadPlatos();
void ListarXId();
bool ModificarPlato(Plato, int);

///PEDIDOS

void ModificarEstado();
bool ModificarPedido(Pedidos, int);
struct Pedidos LeerPedido(int);
int BuscarPedido(int);
void ListarPedidoXid();
float ObtenerPrecio(int);
void NuevoPedido();
bool GuardarPedidos(Pedidos,bool);
bool CargarPedidos(Pedidos *P);
void ListarPedido(Pedidos reg);
bool ListarPedidos();
bool RestaurarPedidos(Pedidos *);
bool BackUpPedidos(Pedidos *);

/// Funciones

void DibujarConfiguracion();
void DibMPedidos();
void DibujarMClientes();
void DibujarPlato();
void DibujarMain();
bool ValidarVal(float *);
void RestaurarBackUpSistema();
void BackUpSistema();
Fecha Hoy();
bool FechaValida(int a, int m, int d);
bool ValidarCadena(char *cad);
bool ValidarEnteroPos(int *);
bool ValidarFloatPos(float *);
bool ValidarReal(float *);
bool ValidarInM(int *);
bool CompararFecha(int a, int m, int d);

/// Clientes

bool RestaurarClientes(Clientes *);
bool BackUpClientes(Clientes *);
void OrdenarClientes(Clientes *, int);
void EliminarCliente();
int CantidadClientes();
void ListarCXId();
bool ModificarCliente(Clientes, int);
int BuscarCliente(int);
struct Clientes LeerCliente(int);
void ModificarDomicilio();
bool ValidarMail(char *);
void NuevoCliente();
bool GuardarCliente(Clientes, bool);
bool CargarClientes(Clientes *);
void ListarCliente(Clientes reg);
void ListarClientes();
void BackUpClientes();
void MenuConfiguracion();

#endif // PROTOTIPOS_H_INCLUDED
