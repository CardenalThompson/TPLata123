#ifndef PEDIDOS_H_INCLUDED
#define PEDIDOS_H_INCLUDED



const char *PATH_PEDIDOS = "Pedidos.dat";
const char *PATH_BKP_PEDIDOS = "Pedidos.bkp";

/// implementaciones

bool BackUpPedidos(Pedidos *vec)

{
    bool val= false, escribio;


    FILE * P;

    P= fopen(PATH_PLATOS, "rb");

    if(P == NULL)

        return 0;

    fseek(P, 0, SEEK_END);

    int cant= ftell(P)/sizeof(Pedidos);



    vec= (Pedidos *) malloc(cant *sizeof(Pedidos));

    if(vec==NULL)

        return 0;

    fseek(P, 0, SEEK_SET);

    fread(&vec[0], sizeof(Pedidos), cant, P);

    fclose(P);



    FILE * P1;

    P1 = fopen(PATH_BKP_PEDIDOS,"wb");

    if(P1 == NULL)

    {

        free(vec);

        return 0;

    }

    escribio = fwrite(&vec[0], sizeof(Pedidos), cant, P1);

    if(escribio==true)

        val= escribio;

    fclose(P1);

    free(vec);

    return val;

}

bool RestaurarPedidos(Pedidos *vec){

    bool val= false, escribio;


    FILE * P;

    P= fopen(PATH_BKP_PEDIDOS, "rb");

    if(P == NULL)

        return 0;

    fseek(P, 0, SEEK_END);

    int cant= ftell(P)/sizeof(Pedidos);



    vec= (Pedidos *) malloc(cant *sizeof(Pedidos));

    if(vec==NULL)

        return 0;

    fseek(P, 0, SEEK_SET);

    fread(&vec[0], sizeof(Pedidos), cant, P);

    fclose(P);


    FILE * P1;

    P1 = fopen(PATH_PEDIDOS,"wb");

    if(P1 == NULL)

    {

        free(vec);

        return 0;

    }

    escribio = fwrite(&vec[0], sizeof(Pedidos), cant, P1);

    if(escribio==true)

        val= escribio;

    fclose(P1);

    free(vec);

    return val;

}


bool GuardarPedidos(Pedidos reg, bool EsBackUp)
{
    bool guardado;
    FILE *P;
    if (EsBackUp)
    {
        P = fopen(PATH_BKP_PEDIDOS, "ab");
    }
    else
    {
        P = fopen(PATH_PEDIDOS, "ab");
    }

    if (P == NULL)
    {
        return false;
    }
    guardado = fwrite(&reg, sizeof(Pedidos), 1, P);
    fclose(P);
    return guardado;
}

void NuevoPedido()
{
    cls();
    setColor(BLUE);
    cout << "<<<>>>";
    setColor(MAGENTA);
    cout <<" CARGAR UN NUEVO PEDIDO ";
    setColor(BLUE);
    cout << "<<<>>>" << endl;
    cout<<endl;
    setColor(WHITE);

    Pedidos reg;

    if (CargarPedidos(&reg))
    {
        if (GuardarPedidos(reg, false))
        {
            cout<< "PEDIDO CARGADO CORRECTAMENTE"<<endl;
            cout<< "Presione cualquier tecla para continuar"<<endl;
            anykey();
        }
        else
        {
            cls();
            cout<< "ERROR AL INTENTAR GUARDAR EL PEDIDO EN EL ARCHIVO"<<endl;
            cout<< "Presione cualquier tecla para continuar"<<endl;
            anykey();
        }

    }
    else
    {
        cout<< "ERROR AL CARGAR EL PEDIDO"<<endl;
        cout<< "Presione cualquier tecla para continuar"<<endl;
        anykey();
    }
}

int CantidadPedidos()
{
    int bytes, cantidad;
    FILE *P;
    P = fopen(PATH_PEDIDOS, "rb");
    if (P == NULL)
    {
        return 0;
    }
    fseek(P, 0, SEEK_END);
    bytes = ftell(P);
    cantidad = bytes / sizeof(Pedidos);
    fclose(P);
    return cantidad;
}

bool CargarPedidos(Pedidos *P)
{
    int id = CantidadPedidos();
    P->ID = id + 1;

    cout<< "ID Cliente: ";
    bool validado = ValidarEnteroPos(&(P -> IDCliente));
    if (!validado)
    {
        cout << "El ID ingresado no es valido"<<endl;
        return false;
    }
    if (BuscarCliente(P->IDCliente)<0)
    {
        cout << "El Cliente no exite"<<endl;
        return false;
    }

    cout<<"ID Plato: ";
    validado = ValidarEnteroPos(&(P->IDPlato));
    if (!validado)
    {
        cout << "El ID ingresado no es valido"<<endl;
        return false;
    }
    float precio = ObtenerPrecio(P->IDPlato);
    if (precio==-1)
    {
        return false;
    }
    P->PrecioUnitario = precio;
    cout<<"CANTIDAD: ";
    validado = ValidarEnteroPos(&(P->Cantidad));
    if (!validado)
    {
        cout << "La Cantidad no es valida"<<endl;
        return false;
    }
    cout<<"FECHA DE PEDIDO"<<endl;
    cout<< "DÍA: ";
    cin>>P->FechaPed.dia;

    cout<< "MES: ";
    cin>>P->FechaPed.mes;

    cout<< "AÑO: ";
    cin>>P->FechaPed.anio;

    bool correcta = FechaValida(P->FechaPed.anio, P->FechaPed.mes, P->FechaPed.dia);

    if(!correcta || !CompararFecha(P->FechaPed.anio, P->FechaPed.mes, P->FechaPed.dia))
    {
        cout << "Fecha invalida" << endl;
        anykey();
        return 0;
    }
    cout<< "VALORACION: ";
    validado = ValidarVal(&(P->Valoracion));
    if (!validado){
        cout << "Formato no valido"<<endl;
        return false;
    }
    P->Estado = 1;
    return true;
}

float ObtenerPrecio(int idBus)
{
    Plato reg;
    float i=0;
    FILE *p;
    p = fopen(PATH_PLATOS, "rb");
    if (p == NULL)
    {
        return -2;
    }
    while (fread(&reg, sizeof(Plato), 1, p))
    {
        if (reg.ID == idBus && reg.Estado==true)
        {
            fclose(p);
            return reg.Precio;
        }
        i++;
    }
    fclose(p);
    return -1;
}

bool ListarPedidos()
{
    {
        cls();
        Pedidos reg;
        int i=0;
        FILE *P;
        P = fopen(PATH_PEDIDOS,"rb");
        if (P == NULL)
            return false;

        while (fread(&reg, sizeof(Pedidos), 1, P))
        {
            cls();
            setColor(BLUE);
            cout << "<<<>>>";
            setColor(MAGENTA);
            cout <<" LISTAR PEDIDOS ";
            setColor(BLUE);
            cout << "<<<>>>" << endl;
            cout<<endl;
            setColor(WHITE);
            ListarPedido(reg);
            setColor(YELLOW);
            cout<<endl;
            cout<< "Siguiente Pedido --->"<<endl;
            anykey();
            cls();
            setColor(WHITE);
            i++;
        }

        fclose(P);
        cout << "Presione cualquier tecla para continuar";
        anykey();
        return true;
    }
}
void ListarPedido(Pedidos reg)
{
    if(reg.Estado == 1){
        setColor(WHITE);
    }
        if(reg.Estado == 2){
        setColor(GREEN);
    }
        if(reg.Estado == 3){
        setColor(RED);
    }
    cls();
    locate(1,20);
            cout<<" 1 - Pedido en curso"<<endl;
            setColor(GREEN);
            cout<<" 2 - Pedido completado"<<endl;
            setColor(RED);
            cout<<" 3 - Pedido cancelado"<<endl;
            setColor(WHITE);
            locate(2,2);
    cout<< "ID: "<< reg.ID<<endl;
    cout << "CLIENTE: "<<reg.IDCliente<<endl;
    cout << "PLATO: "<<reg.IDPlato<<endl;
    cout << "CANTIDAD: "<<reg.Cantidad<<endl;
    cout << "PRECIO X UNITARIO: "<<reg.PrecioUnitario<<endl;
    cout<< "FECHA PEDIDO:"<<reg.FechaPed.dia<<"/"<<reg.FechaPed.mes<<"/"<<reg.FechaPed.anio<<endl;
    cout << "VALORACIÓN: "<<reg.Valoracion<<endl;
    cout << "ESTADO: "<<reg.Estado<<endl;
setColor(WHITE);
}

void ModificarEstado()
{
    cls();
    setColor(BLUE);
    cout << "<<<>>>";
    setColor(MAGENTA);
    cout <<" MODIFICAR PEDIDO ";
    setColor(BLUE);
    cout << "<<<>>>" << endl;
    cout<<endl;
    setColor(WHITE);

    Pedidos reg;
    int Id;
    cout<<"NUMERO DE PEDIDO: ";
    if(!ValidarEnteroPos(&Id))
    {
        cout<< "ID no valido"<<endl;
        cout<< "Presione una tecla para continuar";
        anykey();
        return;
    }
    int pos=BuscarPedido(Id);
    if(pos==-1)
    {
        cout<<"NO EXISTE EL PEDIDO"<<endl;
        return;
    }
    reg=LeerPedido(pos);
    cout<< "ESTADO DEL PEDIDO: ";
    cin>>reg.Estado;
    if(reg.Estado == 1 || reg.Estado == 2 || reg.Estado == 3){

    if(ModificarPedido(reg, pos)==true)
    {
        cls();
        cout<<"DATOS MODIFICADOS"<<endl;
        cout<<"Presione una tecla para continuar";
        anykey();
    }
    else
    {
        cout<<"NO SE PUDO MODIFICAR"<<endl;
        cout<<"Presione una tecla para continuar";
        anykey();
    }
    }
    else{
        cout<< "OPCION INCORRECTA"<<endl;
        cout<<"Presione una tecla para continuar";
        anykey();
        return;
    }
}

bool ModificarPedido(Pedidos reg, int pos)
{
    FILE * P;
    P = fopen(PATH_PEDIDOS,"rb+");
    if (P == NULL)
        return false;
    fseek( P, pos * sizeof (Pedidos),0 );

    fwrite(&reg, sizeof (Pedidos),1,P);

    fclose(P);
    return true;
}

void ListarPedidoXid()
{
    cls();
    setColor(BLUE);
    cout << "<<<>>>";
    setColor(MAGENTA);
    cout <<" LISTAR PEDIDO X ID ";
    setColor(BLUE);
    cout << "<<<>>>" << endl;
    cout<<endl;
    setColor(WHITE);

    int idB, pos;
    cout << "ID a buscar: ";
    if(!ValidarEnteroPos(&idB))
    {
        cout<< "ID no valido"<<endl;
        cout<< "Presione una tecla para continuar";
        anykey();
        return;
    }
    pos = BuscarPedido(idB);
    if (pos >= 0)
    {
        Pedidos reg = LeerPedido(pos);
        ListarPedido(reg);
        anykey();
    }
    else
    {
        cout << "PEDIDO INEXISTENTE"<<endl;
        cout<< endl;
        cout<< "Presione una tecla para continuar";
        anykey();
    }
}

Pedidos LeerPedido(int pos)
{
    Pedidos reg;
    FILE *p;
    p = fopen(PATH_PEDIDOS, "rb");
    if (p == NULL)
    {
        reg.ID = -1;
        return reg;
    }
    fseek(p, pos * sizeof(Pedidos),SEEK_SET);
    fread(&reg, sizeof(Pedidos), 1, p);
    fclose(p);
    return reg;
}

int BuscarPedido(int idBus)
{
    Pedidos reg;
    int i=0;
    FILE *p;
    p = fopen(PATH_PEDIDOS, "rb");
    if (p == NULL)
    {
        return -2;
    }
    while (fread(&reg, sizeof(Pedidos), 1, p))
    {
        if (reg.ID == idBus)
        {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}

#endif // PEDIDOS_H_INCLUDED
