#ifndef PLATOS_H_INCLUDED
#define PLATOS_H_INCLUDED



const char *PATH_PLATOS = "Platos.dat";
const char *PATH_BKP_PLATOS = "Platos.bkp";

///  DEFINICIONES

void ModificarCostoyTiempo()
{
    cls();
    setColor(BLUE);
    cout << "<<<>>>";
    setColor(MAGENTA);
    cout <<" MODIFICAR PLATO ";
    setColor(BLUE);
    cout << "<<<>>>" << endl;
    cout<<endl;
    setColor(WHITE);

    Plato reg;
    int Id;
    cout<<"INGRESE EL PLATO QUE DESEA MODIFICAR: ";
    if(!ValidarEnteroPos(&Id))
    {
        cout<< "ID no valido"<<endl;
        cout<< "Presione una tecla para continuar";
        anykey();
        return;
    }

    int pos=BuscarPlato(Id);
    if(pos==-1)
    {
        cout<<"NO EXISTE EL PLATO"<<endl;
        return;
    }
    reg=LeerPlato(pos);
    cout<< "NUEVO COSTO: ";
    cin>>reg.Costo;
    cout<< "NUEVO TIEMPO DE PREPARACIÓN: ";
    cin>>reg.Tiempo;
    if(ModificarPlato(reg,pos)==true)
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

bool ModificarPlato(Plato reg, int pos)
{
    FILE * p;
    p = fopen(PATH_PLATOS,"rb+");
    if (p == NULL)
        return false;
    fseek( p, pos * sizeof (Plato),0 );

    fwrite(&reg, sizeof (Plato),1,p);

    fclose(p);
    return true;
}

void ListarPlato(Plato reg)
{
    if(reg.Estado==true)
    {
        cout << "ID: ";
        setColor(BLUE);
        cout<<reg.ID<<endl;

        setColor(WHITE);
        cout << "NOMBRE: "<<reg.Nombre<<endl;

        cout << "COSTO: "<<reg.Costo<<endl;

        cout << "PRECIO: "<<reg.Precio<<endl;

        cout << "TIEMPO DE PREPARACIÓN:"<<reg.Tiempo<<endl;

        cout<<"IDRestaurante:"<<reg.IDr<<endl;

        cout<<"Comisión restaurante: "<<reg.comision<<endl;

        cout<<"IDCategoría: "<<reg.IDcat<<endl;
    }

}

int BuscarPlato(int idBus)
{
    Plato reg;
    int i=0;
    FILE *p;
    p = fopen(PATH_PLATOS, "rb");
    if (p == NULL)
    {
        p = fopen(PATH_PLATOS, "wb");
        fclose(p);
        return -1;
    }
    while (fread(&reg, sizeof(Plato), 1, p))
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

bool ListarPlatos()
{
    cls();
    Plato reg;
    int i=0;
    FILE * p;
    p = fopen(PATH_PLATOS,"rb");
    if (p == NULL)
        return false;

    while (fread(&reg, sizeof(Plato), 1, p))
    {
        if (reg.Estado == true)
        {
            cls();
            setColor(BLUE);
            cout << "<<<>>>";
            setColor(MAGENTA);
            cout <<" LISTAR PLATOS ";
            setColor(BLUE);
            cout << "<<<>>>" << endl;
            cout<<endl;
            setColor(WHITE);

            ListarPlato(reg);
            setColor(YELLOW);
            cout<<endl;
            cout<< "Siguiente Plato --->"<<endl;
            anykey();
            cls();
            setColor(WHITE);
        }
        i++;

    }

    fclose(p);
    cout << "Presione cualquier tecla para continuar";
    anykey();
    return true;
}
bool CargarPlato(Plato *p)
{

    cout<< "ID: ";
    bool validado = ValidarEnteroPos(&(p -> ID));
    if (!validado)
    {
        cout << "El ID ingresado no es valido"<<endl;
        return false;
    }
    if (BuscarPlato(p->ID)!=-1)
    {
        cout << "El Plato ya exite"<<endl;
        return false;
    }
    cout<< "NOMBRE: ";
    cin.ignore();
    cin.getline(p->Nombre, 50);
    if(strlen(p->Nombre)<=0)
    {
        cout<< "Debe completar este campo";
        return false;
    }
    cout<< "COSTO DE PREPARACIÓN: $ ";
    validado = ValidarReal(&(p->Costo));
    if (!validado)
    {
        cout << "El Costo ingresado no es valido"<<endl;
        return false;
    }
    cout<< "PRECIO DE VENTA: $ ";
    validado = ValidarReal(&(p->Precio));
    if (!validado)
    {
        cout << "El Precio de venta ingresado no es valido"<<endl;
        return false;
    }
    if(p->Precio <= p->Costo)
    {
        cout << "El Precio de venta debe ser mayor al costo de fabricación"<<endl;
        return false;
    }
    cout<< "TIEMPO DE PREPARACIÓN: ";
    validado = ValidarEnteroPos(&(p->Tiempo));
    if (!validado)
    {
        cout << "El Tiempo de preparación ingresado no es valido"<<endl;
        return false;
    }

    cout<< "ID RESTAURANT: ";
    validado = ValidarEnteroPos(&(p -> IDr));
    if (!validado)
    {
        cout << "El Restaurant ingresado no es valido"<<endl;
        return false;
    }

    cout<< "COMISIÓN: ";
    validado = ValidarEnteroPos(&(p->comision));
    if (!validado || p->comision<0 || p->comision>100)
    {
        cout << "El ID ingresado no es valido"<<endl;
        return false;
    }
    cout<< "CATEGORIA: ";
    validado = ValidarEnteroPos(&(p->IDcat));
    if (!validado)
    {
        cout << "Categoria invalida "<<endl;
        return false;
    }
    p->Estado = true;
    return true;
}

void NuevoPlato()
{

    cls();
    setColor(BLUE);
    cout << "<<<>>>";
    setColor(MAGENTA);
    cout <<" CARGAR NUEVO PLATO ";
    setColor(BLUE);
    cout << "<<<>>>" << endl;
    cout<<endl;
    setColor(WHITE);

    Plato reg;
    if (CargarPlato(&reg))
    {
        if (GuardarPlato(reg, false))
        {
            cout << "PLATO CARGADO CORRECTAMENTE"<<endl;
            cout<< "Presione cualquier tecla para continuar";
            anykey();
        }
        else
        {
            cout << "ERROR AL INTENTAR GUARDAR EL PLATO EN EL ARCHIVO";
            cout<< "Presione cualquier tecla para continuar";
            anykey();
        }
    }
    else
    {
        cout << "ERROR AL CARGAR EL PLATO";
        cout<< "Presione cualquier tecla para continuar";
        anykey();
    }
}

bool BackUpPlatos(Plato *vec)
{

    bool val= false, escribio;


    FILE * P;

    P= fopen(PATH_PLATOS, "rb");

    if(P == NULL)

        return 0;

    fseek(P, 0, SEEK_END);

    int cant= ftell(P)/sizeof(Plato);



    vec= (Plato *) malloc(cant *sizeof(Plato));

    if(vec==NULL)

        return 0;

    fseek(P, 0, SEEK_SET);

    fread(&vec[0], sizeof(Plato), cant, P);

    fclose(P);



    FILE * P1;

    P1 = fopen(PATH_BKP_PLATOS,"wb");

    if(P1 == NULL)

    {

        free(vec);

        return 0;

    }

    escribio = fwrite(&vec[0], sizeof(Plato), cant, P1);

    if(escribio==true)

        val= escribio;

    fclose(P1);

    free(vec);

    return val;

}


bool GuardarPlato(Plato reg, bool EsBackup)
{
    bool guardado;
    FILE *p;
    if(EsBackup)
    {
        p = fopen(PATH_BKP_PLATOS, "ab");
    }
    else
    {
        p = fopen(PATH_PLATOS, "ab");
    }
    if (p == NULL)
    {
        return false;
    }
    guardado = fwrite(&reg, sizeof(Plato), 1, p);
    fclose(p);
    return guardado;
}

void EliminarPlato()
{
    cls();
    setColor(BLUE);
    cout << "<<<>>>";
    setColor(MAGENTA);
    cout <<" LISTAR PLATO X ID ";
    setColor(BLUE);
    cout << "<<<>>>" << endl;
    cout<<endl;
    setColor(WHITE);

    Plato reg;
    int Id;
    cout<<"INGRESE EL PLATO QUE DESEA ELIMINAR: ";
    if(!ValidarEnteroPos(&Id))
    {
        cout<< "ID no valido"<<endl;
        cout<< "Presione una tecla para continuar";
        anykey();
        return;
    }
    int pos=BuscarPlato(Id);
    if(pos==-1)
    {
        cout<<"NO EXISTE EL PLATO"<<endl;
        anykey();
        cls();
        return;
    }
    reg=LeerPlato(pos);
    if(reg.Estado== false)
    {
        cout<<"NO EXISTE EL PLATO"<<endl;
        anykey();
        cls();
        return;
    }
    reg.Estado=false;
    if(ModificarPlato(reg,pos)==true)
    {
        cout<<"PLATO ELIMINADO CON EXITO"<<endl;
    }
    else
    {
        cout<<"NO SE PUDO DAR LA BAJA"<<endl;
    }
    anykey();
}

int CantidadPlatos()
{
    int bytes, cantidad;
    FILE *p;
    p = fopen(PATH_PLATOS, "rb");
    if (p == NULL)
    {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    cantidad = bytes / sizeof(Plato);
    fclose(p);
    return cantidad;
}

void ListarXId()
{
    cls();
    setColor(BLUE);
    cout << "<<<>>>";
    setColor(MAGENTA);
    cout <<" LISTAR PLATO X ID ";
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
    pos = BuscarPlato(idB);
    if (pos >= 0)
    {
        Plato reg = LeerPlato(pos);
        ListarPlato(reg);
        setColor(YELLOW);
        cout<<endl;
        cout<< "Siguiente Plato --->"<<endl;
        anykey();
        cls();
        setColor(WHITE);
    }
    else
    {
        cout << "NO EXISTE EL PLATO"<<endl;
        cout<< endl;
        cout<< "Presione una tecla para continuar";
        anykey();
    }
}

Plato LeerPlato(int pos)
{
    Plato reg;
    FILE *p;
    p = fopen(PATH_PLATOS, "rb");
    if (p == NULL)
    {
        reg.ID = -1;
        return reg;
    }
    fseek(p, pos * sizeof(Plato),SEEK_SET);
    fread(&reg, sizeof(Plato), 1, p);
    fclose(p);
    return reg;
}

void ListarXResr()
{
    cls();
    setColor(BLUE);
    cout << "<<<>>>";
    setColor(MAGENTA);
    cout <<" LISTAR PLATO X RESTAURANT ";
    setColor(BLUE);
    cout << "<<<>>>" << endl;
    cout<<endl;
    setColor(WHITE);

    int idBus;
    cout<< "Ingrese el restorant: ";
    cin>>idBus;
    int Encontro = -1;
    Plato reg;
    int i=0;
    FILE *p;
    p = fopen(PATH_PLATOS, "rb");
    if (p == NULL)
    {
        cout<< "No se encontro el Archivo";
        return;
    }
    while (fread(&reg, sizeof(Plato), 1, p))
    {
        if (reg.IDr == idBus)
        {
            Encontro = 0;
            ListarPlato(reg);
            setColor(YELLOW);
            cout<< endl;
            cout<< "Proximo Plato --->"<<endl;
            anykey();
            cls();
            setColor(WHITE);
        }
        i++;
    }
    fclose(p);
    if (Encontro== -1)
    {
        cout<< "No se encontro Restaurant"<<endl;

    }
    cout<< "Presione una tecla para volver al menu ";
    anykey();
}

bool RestaurarPlatos(Plato * vec)

{

    bool val= false, escribio;


    FILE * P;

    P= fopen(PATH_BKP_PLATOS, "rb");

    if(P == NULL)

        return 0;

    fseek(P, 0, SEEK_END);

    int cant= ftell(P)/sizeof(Plato);



    vec= (Plato *) malloc(cant *sizeof(Plato));

    if(vec==NULL)

        return 0;

    fseek(P, 0, SEEK_SET);

    fread(&vec[0], sizeof(Plato), cant, P);

    fclose(P);



    FILE * P1;

    P1 = fopen(PATH_PLATOS,"wb");

    if(P1 == NULL)

    {

        free(vec);

        return 0;

    }

    escribio = fwrite(&vec[0], sizeof(Plato), cant, P1);

    if(escribio==true)

        val= escribio;

    fclose(P1);

    free(vec);

    return val;

}

#endif // PLATOS_H_INCLUDED
