#ifndef SUBMENU_H_INCLUDED
#define SUBMENU_H_INCLUDED

///SubMenus

void MenuPlatos()
{
    int opc;
    while(opc!=0)
    {
        DibujarPlato();;

        bool validado = (ValidarInM(&opc));
        if (!validado)
        {
            cout << "Opcion no valida"<<endl;
            cout << "Presione cualquier tecla para continuar";
            anykey();
            return ;
        }
        switch(opc)
        {
        case 1:
            NuevoPlato();
            break;
        case 2:
            ModificarCostoyTiempo();
            break;
        case 3:
            ListarXId();
            break;
        case 4:
            ListarXResr();
            break;
        case 5:
            ListarPlatos();
            break;
        case 6:
            EliminarPlato();
            break;
        case 0:
            return;
            break;
        default:
            cls();
            cout<<" OPCION INCORRECTA";
            anykey();
            break;
        }
    }
}


void MenuClientes()
{
    int opc;
    while(opc!=0)
    {
        DibujarMClientes();

        bool validado = (ValidarInM(&opc));
        if (!validado)
        {
            cout << "Opcion no valida"<<endl;
            cout << "Presione cualquier tecla para continuar";
            anykey();
            return ;
        }
        switch(opc)
        {
        case 1:
            NuevoCliente();
            break;
        case 2:
            ModificarDomicilio();
            break;
        case 3:
            ListarCXId();
            break;
        case 4:
            ListarClientes();
            break;
        case 5:
            EliminarCliente();
            break;
        case 0:
            return;
            break;
        default:
            cls();
            cout<<" OPCION INCORRECTA";
            anykey();
            break;
        }
    }
}

void MenuPedidos()
{

    int opc;
    while(opc!=0)
    {
        DibMPedidos();
        bool validado = (ValidarInM(&opc));
        if (!validado)
        {
            cout << "Opcion no valida"<<endl;
            cout << "Presione cualquier tecla para continuar";
            anykey();
            return ;
        }
        switch(opc)
        {
        case 1:
            NuevoPedido();
            break;
        case 2:
            locate(1,20);
            cout<<" 1 - Pedido en curso"<<endl;
            setColor(GREEN);
            cout<<" 2 - Pedido completado"<<endl;
            setColor(RED);
            cout<<" 3 - Pedido cancelado"<<endl;
            setColor(WHITE);
            locate(2,2);
            ModificarEstado();
            break;
        case 3:
            ListarPedidoXid();
            break;
        case 4:
            ListarPedidos();
            break;
        case 0:
            return;
            break;
        default:
            cls();
            cout<<" OPCION INCORRECTA";
            break;
        }
    }
}

void MenuConfiguracion()
{

    int opc;
    while(opc!=0)
    {
        DibujarConfiguracion();

        bool validado = (ValidarInM(&opc));
        if (!validado)
        {
            cout << "Opcion no valida"<<endl;
            cout << "Presione cualquier tecla para continuar";
            anykey();
            return ;
        }
        switch(opc)
        {
        case 1:
            cls();
            setColor(BLUE);
            cout << "<<<>>>";
            setColor(MAGENTA);
            cout << " REALIZAR BACK UP DEL SISTEMA ";
            setColor(BLUE);
            cout << "<<<>>>" << endl;
            cout<<endl;
            setColor(WHITE);

            BackUpSistema();
            break;
        case 2:
            cls();
            setColor(BLUE);
            cout << "<<<>>>";
            setColor(MAGENTA);
            cout << " RESTAURAR EL SISTEMA ";
            setColor(BLUE);
            cout << "<<<>>>" << endl;
            cout<<endl;
            setColor(WHITE);

            RestaurarBackUpSistema();
            break;
        case 0:
            break;
        default:
            cls();
            cout<<" OPCION INCORRECTA";
            break;
        }
    }
}

#endif // SUBMENU_H_INCLUDED
