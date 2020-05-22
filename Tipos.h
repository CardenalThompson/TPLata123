#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

struct Fecha
{
    int dia, mes, anio;
};

struct Clientes
{
    int ID;
    char Apellido[50];
    char Nombre[50];
    char Mail[50];
    char Domicilio[100];
    struct Fecha FechaNac;
    int CP;
    bool Estado;
};

struct Plato
{
    int ID;
    char Nombre[50];
    float Costo;
    float Precio;
    int Tiempo;
    int IDr;
    int comision;
    int IDcat;
    bool Estado;
};

struct Pedidos
{

    int ID;
    int IDCliente;
    int IDPlato;
    int Cantidad;
    float PrecioUnitario;
    struct Fecha FechaPed;
    float Valoracion;
    int Estado;

};


#endif // TIPOS_H_INCLUDED
