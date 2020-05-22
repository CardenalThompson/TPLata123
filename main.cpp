#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <clocale>
#include <ctime>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "Tipos.h"
#include "Prototipos.h"
#include "Submenu.h"
#include "Platos.h"
#include "Clientes.h"
#include "Funciones.h"
#include "Pedidos.h"

int main()
{
    setBackgroundColor(BLACK);
    setlocale (LC_ALL, "spanish");
    int opcion;
    while(true)
    {
        DibujarMain();
        cin>>opcion;
        cls();
        switch(opcion)
        {
        case 1:
            MenuPlatos();
            break;
        case 2:
            MenuClientes();
            break;
        case 3:
            MenuPedidos();
            break;
        case 4:
            break;
        case 5:
            MenuConfiguracion();
            break;

        case 0:
            return 0;
            break;
        default:
            setColor(RED);
            cout<<" OPCION INCORRECTA"<<endl;
            anykey();
            break;
        }
    }
}


