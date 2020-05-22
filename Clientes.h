#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED


const char *PATH_BKP_CLIENTES = "Clientes.bkp";
const char *PATH_CLIENTES = "Clientes.dat";

// IMPLEMENTACIONES

void NuevoCliente()
{
    cls();
    setColor(BLUE);
    cout << "<<<>>>";
    setColor(MAGENTA);
    cout <<" NUEVO CIENTE ";
    setColor(BLUE);
    cout << "<<<>>>" << endl;
    cout<<endl;
    setColor(WHITE);

    Clientes reg;

    if (CargarClientes(&reg))
    {
        if (GuardarCliente(reg, false))
        {
            cout << "CLIENTE CARGADO CORRECTAMENTE";
            cout<< "Presione cualquier tecla para continuar";
            anykey();
        }
        else
        {
            cout << "ERROR AL INTENTAR GUARDAR EL CLIENTE EN EL ARCHIVO";
            anykey();
        }
    }
    else
    {
        cout << "ERROR AL CARGAR EL CLIENTE";
        anykey();
    }
}

bool GuardarCliente(Clientes reg, bool EsBackUp)
{
    bool guardado;
    FILE *p;
    if(EsBackUp)
    {
        p = fopen(PATH_BKP_CLIENTES, "ab");
    }
    else
    {
        p = fopen(PATH_CLIENTES,"ab");
    }
    if (p == NULL)
    {
        return false;
    }
    guardado = fwrite(&reg, sizeof(Clientes), 1, p);
    fclose(p);
    return guardado;
}
bool CargarClientes(Clientes *C)
{
    int id = CantidadClientes();
    C->ID = id + 1;
    cout<< "APELLIDO: ";
    cin.ignore();
    cin.getline(C->Apellido, 50);
    if(strlen(C->Apellido)<=0)
    {
        cout<< "Debe completar este campo";
        return false;
    }
    cout<<"NOMBRES: ";
    cin.getline(C->Nombre, 50);
    if(strlen(C->Nombre)<=0)
    {
        cout<< "Debe completar este campo";
        return false;
    }
    cout<<"E-MAIL: ";
    bool Validado = ValidarMail(C->Mail);
    if (!Validado)
        return false;

    cout<<"DOMICILIO: ";
    cin.getline(C->Domicilio, 100);
    if(strlen(C->Domicilio)<=0)
    {
        cout<< "Debe completar este campo";
        return false;
    }
    cout<<"CP: ";
    bool validado = ValidarEnteroPos(&(C->CP));
    if(!validado ||(C->CP<1000 || C->CP>9999 ))
    {
        cout<< "Codigo Postal invalido"<<endl;
        return false;
    }
    cout<<"FECHA DE NACIMIENTO"<<endl;
    cout<< "DÍA: ";
    cin>>C->FechaNac.dia;
    cout<< "MES: ";
    cin>>C->FechaNac.mes;
    cout<< "AÑO: ";
    cin>>C->FechaNac.anio;
    bool correcta = FechaValida(C->FechaNac.anio, C->FechaNac.mes, C->FechaNac.dia);
    if(!correcta || !CompararFecha(C->FechaNac.anio, C->FechaNac.mes, C->FechaNac.dia))
    {
        cout << "Fecha invalida" << endl;
        anykey();
        return 0;
    }
    C->Estado = true;
    return true;
}

void ListarCliente(Clientes reg)
{

    if(reg.Estado==true)
    {
        cout << "ID: "<<reg.ID<<endl;

        cout<< "APELLIDO: "<< reg.Apellido<<endl;

        cout << "NOMBRE: "<<reg.Nombre<<endl;

        cout << "MAIL: "<<reg.Mail<<endl;

        cout << "DOMICILIO: "<<reg.Domicilio<<endl;

        cout << "CP: "<<reg.CP<<endl;

        cout<<"FECHA DE NACIMIENO: "<<reg.FechaNac.dia<<"/"<<reg.FechaNac.mes<<"/"<<reg.FechaNac.anio<<endl;
    }
}
void ModificarDomicilio()
{
    cls();
    setColor(BLUE);
    cout << "<<<>>>";
    setColor(MAGENTA);
    cout <<" MODIFICAR CIENTE ";
    setColor(BLUE);
    cout << "<<<>>>" << endl;
    cout<<endl;
    setColor(WHITE);

    Clientes reg;
    cout<<endl;
    cout<<"INGRESE EL CLIENTE QUE DESEA MODIFICAR: ";
    int Id;
    if(!ValidarEnteroPos(&Id))
    {
        cout<< "ID no valido"<<endl;
        cout<< "Presione una tecla para continuar";
        anykey();
        return;
    }
    int pos=BuscarCliente(Id);
    if(pos==-1)
    {
        cout<<"NO EXISTE EL CLIENTE"<<endl;
        anykey();
        return;
    }
    reg=LeerCliente(pos);
    cout<< "NUEVO DOMICILIO: ";
    cin.ignore();
    cin.getline(reg.Domicilio, 100);
    if(strlen(reg.Domicilio)<=0)
    {
        cout<< "Debe completar este campo";
        cout << "Presione cualquier tecla para continuar";
        anykey();
        return;
    }
    if(ModificarCliente(reg,pos)==true)
    {
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

bool ModificarCliente(Clientes reg, int pos)
{
    FILE * p;
    p = fopen(PATH_CLIENTES,"rb+");
    if (p == NULL)
        return false;
    fseek( p, pos * sizeof (Clientes),0 );

    fwrite(&reg, sizeof (Clientes),1,p);

    fclose(p);
    return true;
}

int BuscarCliente(int idBus)
{
    Clientes reg;
    int i=0;
    FILE *p;
    p = fopen(PATH_CLIENTES, "rb");
    if (p == NULL)
    {
        cout<<"NO SE PUEDE LEER EL ARCHIVO";
        cout<< "Presione una tecla para continuar";
        anykey();
        return -2;
    }
    while (fread(&reg, sizeof(Clientes), 1, p))
    {
        if (reg.ID == idBus && reg.Estado==true)
        {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}

Clientes LeerCliente(int pos)
{
    Clientes reg;
    FILE *p;
    p = fopen(PATH_CLIENTES, "rb");
    if (p == NULL)
    {
        reg.ID = -1;
        return reg;
    }
    fseek(p, pos * sizeof(Clientes),SEEK_SET);
    fread(&reg, sizeof(Clientes), 1, p);
    fclose(p);
    return reg;
}

void ListarCXId()
{
    cls();
    setColor(BLUE);
    cout << "<<<>>>";
    setColor(MAGENTA);
    cout <<" LISTAR CLIENTE X ID ";
    setColor(BLUE);
    cout << "<<<>>>" << endl;
    cout<<endl;
    int idB, pos;
    cout << "ID a buscar: ";
    if(!ValidarEnteroPos(&idB))
    {
        cout<< "ID no valido"<<endl;
        cout<< "Presione una tecla para continuar";
        anykey();
        return;
    }
    pos = BuscarCliente(idB);
    if (pos >= 0)
    {
        Clientes reg = LeerCliente(pos);
        ListarCliente(reg);
        anykey();
    }
    else
    {
        cout << "CLIENTE INEXISTENTE"<<endl;
        cout<< endl;
        cout<< "Presione una tecla para continuar";
        anykey();
    }
}

int CantidadClientes()
{
    int bytes, cantidad;
    FILE *c;
    c = fopen(PATH_CLIENTES, "rb");
    if (c == NULL)
    {
        return 0;
    }
    fseek(c, 0, SEEK_END);
    bytes = ftell(c);
    cantidad = bytes / sizeof(Clientes);
    fclose(c);
    return cantidad;
}

void EliminarCliente()
{
    cls();
    setColor(BLUE);
    cout << "<<<>>>";
    setColor(MAGENTA);
    cout <<" ELIMINAR CLIENTE ";
    setColor(BLUE);
    cout << "<<<>>>" << endl;
    cout<<endl;
    setColor(WHITE);

    Clientes reg;
    int Id;
    cout<<"INGRESE EL CLIENTE QUE DESEA ELIMINAR: ";
    if(!ValidarEnteroPos(&Id))
    {
        cout<< "ID no valido"<<endl;
        cout<< "Presione una tecla para continuar";
        anykey();
        return;
    }
    int pos=BuscarCliente(Id);
    if(pos==-1)
    {
        cout<<"NO EXISTE EL CLIENTE"<<endl;
        anykey();
        cls();
        return;
    }
    reg=LeerCliente(pos);
    if(reg.Estado== false)
    {
        cout<<"NO EXISTE EL CLIENTE"<<endl;
        anykey();
        cls();
        return;
    }
    reg.Estado=false;
    if(ModificarCliente(reg,pos)==true)
    {
        cout<<"CLIENTE ELIMINADO CON EXITO"<<endl;
    }
    else
    {
        cout<<"NO SE PUDO DAR LA BAJA"<<endl;
    }
    anykey();
}

void OrdenarClientes(Clientes *vec, int tam)
{
    int i, j, pos;
    Clientes aux;

    for(i=0; i<tam-1; i++)
    {
        pos = i;
        for(j= i+1; j<tam; j++)
        {

            if (strcmp(vec[j].Apellido, vec[pos].Apellido)<0)
            {
                pos = j;
            }
        }
        aux = vec[i];
        vec[i] = vec[pos];
        vec[pos] = aux;
    }
}
void ListarClientes()
{
    cls();

    int cant = CantidadClientes(), i;
    if (cant == 0)
    {
        cout << "No hay productos";
        return;
    }
    Clientes *vec;
    vec = (Clientes *) malloc(cant * sizeof(Clientes));
    if (vec == NULL)
    {
        cout << "No hay memoria para continuar...";
        return;
    }
    FILE *C;
    C = fopen(PATH_CLIENTES, "rb");
    if (C == NULL)
    {
        free(vec);
        cout << "No existe el archivo...";
        return;
    }
    fread(&vec[0], sizeof(Clientes), cant, C);
    fclose(C);

    OrdenarClientes(vec, cant);

    for(i=0; i<cant; i++)
    {
        cls();
        setColor(BLUE);
        cout << "<<<>>>";
        setColor(MAGENTA);
        cout <<" LISTAR CIENTES ";
        setColor(BLUE);
        cout << "<<<>>>" << endl;
        cout<<endl;
        setColor(WHITE);
        ListarCliente(vec[i]);
        setColor(YELLOW);
        cout << endl;
        cout<< "Proximo Cliente --->"<<endl;
        anykey();
        cls();
        setColor(WHITE);
    }
    free (vec);
}

bool BackUpClientes(Clientes *vec)
{

    bool val= false, escribio;

    FILE * C;
    C= fopen(PATH_CLIENTES, "rb");

    if(C == NULL)
    {

        return 0;
    }
    fseek(C, 0, SEEK_END);

    int cant= ftell(C)/sizeof(Clientes);

    vec= (Clientes *) malloc(cant *sizeof(Clientes));

    if(vec==NULL)

        return 0;

    fseek(C, 0, SEEK_SET);

    fread(&vec[0], sizeof(Clientes), cant, C);
    fclose(C);


    FILE * C1;

    C1 = fopen(PATH_BKP_CLIENTES,"wb");

    if(C1 == NULL)
    {
        free(vec);
        return 0;
    }

    escribio = fwrite(&vec[0], sizeof(Clientes), cant, C1);

    if(escribio==true)

        val= escribio;

    fclose(C1);
    free(vec);

    return val;

}

bool RestaurarClientes(Clientes *vec)
{

    bool val= false, escribio;

    FILE * C;
    C= fopen(PATH_BKP_CLIENTES, "rb");

    if(C == NULL)
    {

        return 0;
    }
    fseek(C, 0, SEEK_END);

    int cant= ftell(C)/sizeof(Clientes);

    vec= (Clientes *) malloc(cant *sizeof(Clientes));

    if(vec==NULL)

        return 0;

    fseek(C, 0, SEEK_SET);

    fread(&vec[0], sizeof(Clientes), cant, C);
    fclose(C);


    FILE * C1;

    C1 = fopen(PATH_CLIENTES,"wb");

    if(C1 == NULL)
    {
        free(vec);
        return 0;
    }

    escribio = fwrite(&vec[0], sizeof(Clientes), cant, C1);

    if(escribio==true)

        val= escribio;

    fclose(C1);
    free(vec);

    return val;

}

#endif // CLIENTES_H_INCLUDED
