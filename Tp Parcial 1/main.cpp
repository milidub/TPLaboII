#include <iostream>
#include <cstring>
#include <time.h>
#include "rlutil.h"

using namespace std;

#include "FuncionesGlobales.h"
#include "Fecha.h"
#include "Jugadores.h"
#include "Deportes.h"
#include "Configuracion.h"
#include "Reportes.h"
#include "Equipos.h"
#include "TiposDeDeporte.h"
#include "Menues.h"

int main()
{
        int opc;
     rlutil::setBackgroundColor(rlutil::CYAN);
     rlutil::setColor(rlutil::WHITE);

    while (true)
    {
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout<<"1) MENU JUGADORES"<<endl;
        cout<<"2) MENU DEPORTES"<<endl;
        cout<<"3) MENU EQUIPOS"<<endl;
        cout<<"4) MENU TIPOS DE DEPORTE"<<endl;
        cout<<"5) REPORTES"<<endl;
        cout<<"6) CONFIGURACION"<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout<<"0) FIN DEL PROGRAMA"<<endl;
        cout<<endl;
        cout<<"SELECCIONE UNA DE LAS OPCIONES:  ";
        cin>>opc;
        rlutil::cls();

        switch (opc)
        {
        case 1: menuJugadores();
            break;
        case 2: menuDeportes();
            break;
        case 3: menuEquipo();
            break;
        case 4: menuTiposDeDeporte();
            break;
        case 5: menuReportes();;
            break;
        case 6: menuConfiguracion();
            break;
        case 0: return 0;
            break;
        default:
            break;
        }
    }

    return 0;

}
