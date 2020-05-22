#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


void DibujarConfiguracion(){
        cls();
        setBackgroundColor(BLUE);
        cout<<"                                   "<<endl;
        cout<<"        ";
        setColor(LIGHTCYAN);
        cout<<"MENÚ CONFIGURACION  ";
        cout<<"       "<<endl;
        cout<<"                                   "<<endl;
        setBackgroundColor(BLACK);
        setColor(WHITE);
        cout<<endl;
        cout<<"- 1 - REALIZAR COPIA DE SEGURIDAD  "<<endl;
        cout<<"- 2 - RESTAURAR COPIA DE SEGURIDAD "<<endl;
        cout<<"-----------------------------------"<<endl;
        cout<<"- 0 - VOLVER AL MENÚ PRINCIPAL     "<<endl;
        cout<<"-----------------------------------"<<endl;
        cout<<endl;
        setBackgroundColor(BLUE);
        setColor(LIGHTCYAN);
        cout<<"- 0 - VOLVER AL MENÚ PRINCIPAL     "<<endl;
        setBackgroundColor(BLACK);
        cout<<endl;
        setColor(WHITE);
        cout << "- SELECCIONE UNA OPCION: ";
}

void DibMPedidos(){
        cls();
        setBackgroundColor(BLUE);
        cout<<"                                   "<<endl;
        cout<<"           ";
        setColor(LIGHTCYAN);
        cout<<"MENÚ PEDIDOS  ";
        cout<<"          "<<endl;
        cout<<"                                   "<<endl;
        setBackgroundColor(BLACK);
        setColor(WHITE);
        cout<<endl;
        cout<<"- 1 - NUEVO PEDIDO                 "<<endl;
        cout<<"- 2 - MODIFICAR PEDIDO             "<<endl;
        cout<<"- 3 - LISTAR PEDIDO POR ID         "<<endl;
        cout<<"- 4 - LISTAR TODOS LOS PEDIDOS     "<<endl;
        cout<<endl;
        setBackgroundColor(BLUE);
        setColor(LIGHTCYAN);
        cout<<"- 0 - VOLVER AL MENÚ PRINCIPAL     "<<endl;
        setBackgroundColor(BLACK);
        cout<<endl;
        setColor(WHITE);
        cout << "- SELECCIONE UNA OPCION: ";
}

void DibujarMClientes(){
        cls();
       setBackgroundColor(BLUE);
        cout<<"                                   "<<endl;
        cout<<"           ";
        setColor(LIGHTCYAN);
        cout<<"MENÚ CLIENTES ";
        cout<<"          "<<endl;
        cout<<"                                   "<<endl;
        setBackgroundColor(BLACK);
        setColor(WHITE);
        cout<<endl;
        cout<< "- 1 - NUEVO CLIENTE                "<<endl;
        cout<< "- 2 - MODIFICAR CLIENTE            "<<endl;
        cout<< "- 3 - LISTAR CLIENTE POR ID        "<<endl;
        cout<< "- 4 - LISTAR TODOS LOS CLIENTES    "<<endl;
        cout<< "- 5 - ELIMINAR CLIENTE             "<<endl;
        cout<<endl;
        setBackgroundColor(BLUE);
        setColor(LIGHTCYAN);
        cout<<"- 0 - VOLVER AL MENÚ PRINCIPAL     "<<endl;
        setBackgroundColor(BLACK);
        cout<<endl;
        setColor(WHITE);
        cout << "- SELECCIONE UNA OPCION: ";
}

void DibujarMain(){
        cls();
        setBackgroundColor(BLUE);
        cout<<"                                   "<<endl;
        cout<<"           ";
        setColor(LIGHTCYAN);
        cout<<"MENÚ PRINCIPAL";
        cout<<"          "<<endl;
        cout<<"                                   "<<endl;
        setBackgroundColor(BLACK);
        setColor(WHITE);
        cout<<endl;
        cout << "- 1 - PLATOS                       "<<endl;
        cout << "- 2 - CLIENTES                     "<<endl;
        cout << "- 3 - PEDIDOS                      "<<endl;
        cout << "- 4 - REPORTES                     "<<endl;
        cout << "- 5 - CONFIGURACIÓN                "<<endl;
        cout<<endl;
        setBackgroundColor(BLUE);
        setColor(LIGHTCYAN);
        cout<<"- 0 - VOLVER AL MENÚ PRINCIPAL     "<<endl;
        setBackgroundColor(BLACK);
        cout<<endl;
        setColor(WHITE);
        cout << "- SELECCIONE UNA OPCION: ";
}
void DibujarPlato(){
        cls();
        setBackgroundColor(BLUE);
        cout<<"                                   "<<endl;
        cout<<"            ";
        setColor(LIGHTCYAN);
        cout<<"MENÚ PLATOS  ";
        cout<<"          "<<endl;
        cout<<"                                   "<<endl;
        setBackgroundColor(BLACK);
        setColor(WHITE);
        cout<<endl;
        cout<< "- 1 - NUEVO PLATO                  "<<endl;
        cout<< "- 2 - MODIFICAR PLATO              "<<endl;
        cout<< "- 3 - LISTAR PLATO POR ID          "<<endl;
        cout<< "- 4 - PLATOS POR RESTAURANT        "<<endl;
        cout<< "- 5 - LISTAR TODOS LOS PLATOS      "<<endl;
        cout<< "- 6 - ELIMINAR PLATO               "<<endl;
        cout<<endl;
        setBackgroundColor(BLUE);
        setColor(LIGHTCYAN);
        cout<<"- 0 - VOLVER AL MENÚ PRINCIPAL     "<<endl;
        setBackgroundColor(BLACK);
        cout<<endl;
        setColor(WHITE);
        cout << "- SELECCIONE UNA OPCION: ";
}
bool ValidarInM(int *num)
{
    if (cin >> *num )
    {
        return true;
    }
    else
    {
        cin.clear();
        cin.ignore();
        return false;
    }
}

bool ValidarEnteroPos(int *num)
{
    if (cin >> *num )
    {
        if(*num<=0)
        {
            return false;
        }
        return true;
    }
    else
    {
        cin.clear();
        cin.ignore();
        return false;
    }
}

bool ValidarReal(float *real)
{
    if (cin >> *real )
    {
        if(*real<=0)
        {
            return false;
        }
        return true;
    }

    else
    {
        cin.clear();
        cin.ignore();
        return false;
    }
}

bool ValidarVal(float *real)
{
    if (cin >> *real )
    {
        if(*real<0)
        {
            return false;
        }
        return true;
    }

    else
    {
        cin.clear();
        cin.ignore();
        return false;
    }

}

bool ValidarMail(char *mail)
{
    bool flagArroba = false;
    bool flagPunto = false;

    cin.getline(mail,50);

    int i=0;
    while(mail[i]!='\0')
    {
        if(mail[i]== ' ')
        {
            cout<<"FORMATO INVALIDO"<<endl;
            cout<< "El campo e-mail no puede contener espacios";
            anykey();
            cls();
            return false;
        }

        if (mail[0] == '@' || mail[0] == '.')
        {
            cout<<"FORMATO INVALIDO"<<endl;
            cout << "El campo e-mail no puede comenzar con @ o punto";
            anykey();
            cls();
            return false;
        }

        if (mail[i] == '@')
        {
            if (flagArroba == false)
            {
                flagArroba = true;
            }
            else
            {
                cout<<"FORMATO INVALIDO"<<endl;
                cout << "El campo e-mail admite un solo @";
                anykey();
                cls();
                return false;
            }
        }
        if(mail[i] == '.')
        {
            flagPunto = true;
        }
        if(mail[i]== '.' && mail[i-1]== '.')
        {
            cout<<"FORMATO INVALIDO"<<endl;
            cout<< "El campo e-mail no admite dos puntos consecutivos";
            anykey();
            cls();
            return false;
        }

        i++;
    }

    if (mail[i-1] == '.'|| mail[i-1] == '@' )
    {
        cout<<"FORMATO INVALIDO"<<endl;
        cout << "El campo e-mail no puede terminar en punto o @";
        anykey();
        cls();
        return false;
    }
    if(flagArroba == false|| flagPunto == false)
    {
        cout<<"FORMATO INVALIDO"<<endl;
        cout<< "El campo e-mail debe contener al menos un punto y un @";
        anykey();
        cls();
        return false;
    }
    return true;
}

Fecha Hoy()
{
    time_t t;
    t = time(NULL);
    struct tm *f;
    f = localtime(&t);
    Fecha Aux;
    Aux.anio = f->tm_year + 1900;
    Aux.mes = f->tm_mon +1;
    Aux.dia = f ->tm_mday;
    return Aux;
}

bool CompararFecha(int a, int m, int d)
{
    Fecha Actual;
    Actual = Hoy();
    if (Actual.anio <= a && Actual.mes <= m && Actual.dia < d)
    {
        return false;
    }
    return true;
}

bool FechaValida(int a, int m, int d)
{

    int dias_mes[] = {31, 28, 31, 30,31, 30, 31, 31, 30, 31, 30, 31};

    if((a%4 == 0 && a%100 != 0) || a%400 == 0)
    {
        dias_mes[1]++;
    }

    if(m < 1 || m > 12)
        return false;

    m = m-1;
    if(d <= 0 || d > dias_mes[m])
        return false;

    return true;
}

void BackUpSistema()
{
    char op;
    cout<< "¿Desea realizar un back up del sistema?: Y/N"<<endl;
    cin>>op;
    if(op == 'Y' || op == 'y')
    {
        Plato vP;
        BackUpPlatos(&vP);
        Clientes vC;
        BackUpClientes(&vC);
        Pedidos vPe;
        BackUpPedidos(&vPe);
    }
    else if (op == 'N' || op == 'n')
    {
        cout<< "NO SE PUDO HACER EL BACK UP";
        return;
    }
    else
    {
        cls();
        anykey();
        cout<< "Opcion no valida";
    }
}

void RestaurarBackUpSistema()
{
    char op;
    cout<< "¿Desea restaurar el sistema?: Y/N"<<endl;
    cin>>op;
    if(op == 'Y' || op == 'y')
    {
        Plato regP;
        RestaurarPlatos(&regP);
        Clientes regC;
        RestaurarClientes(&regC);
        Pedidos regPe;
        RestaurarPedidos(&regPe);
    }
    else if (op == 'N' || op == 'n')
    {
        cout<< "NO SE PUDO RESTAURAR";
        return;
    }
    else
    {
        cls();
        anykey();
        cout<< "Opcion no valida";
    }
}
#endif // FUNCIONES_H_INCLUDED
