#ifndef MENUES_H_INCLUDED
#define MENUES_H_INCLUDED

void menuJugadores();
void menuDeportes();
void menuReportes();
void menuConfiguracion();
void menuEquipo();
void menuTiposDeDeporte();

void menuJugadores()
{
    ArchivoJugadores archivoJ("Jugadores.dat");
    int opc,dni;
    while (true)
    {
        system("cls");
        cout<<"MENU JUGADORES"<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout<<"1) AGREGAR JUGADOR"<<endl;
        cout<<"2) LISTAR JUGADOR POR DNI"<<endl;
        cout<<"3) LISTAR TODOS LOS JUGADORES"<<endl;
        cout<<"4) MODIFICAR FECHA DE INSCRIPCION"<<endl;
        cout<<"5) ELIMINAR REGISTRO DE JUGADOR "<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout<<"0) SALIR"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opc;
        system("cls");

        switch (opc)
        {
        case 1:
            archivoJ.agregarJugador();
            break;
        case 2:
            cout<<"Ingrese Dni: ";
            cin>>dni;
            archivoJ.listarJugadorPorDni(dni);
            break;
        case 3:
            archivoJ.listarTodosLosJugadores();
            break;
        case 4:
            archivoJ.modificarFechaDeInscripcion();
            break;
        case 5:
            archivoJ.eliminarRegistroDeJugador();
            break;
        case 0:
            return;
            break;
        default:
            cout<<"Error, vuelve a ingresar un numero";
            break;
        }
        system ("pause");
    }
}

void menuDeportes()
{
    ArchivoDeporte archivoD("Deporte.dat");
    int opc;
    int id;
    while (true)
    {
        system("cls");
        cout<<"MENU DEPORTES"<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout<<"1) AGREGAR DEPORTE"<<endl;
        cout<<"2) LISTAR DEPORTE POR DNI"<<endl;
        cout<<"3) LISTAR TODO"<<endl;
        cout<<"4) MODIFICAR AÑO DE ORIGEN"<<endl;
        cout<<"5) ELIMINAR REGISTRO"<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opc;
        system("cls");

        switch (opc)
        {
        case 1:
            archivoD.agregarJugador();
            break;
        case 2:
            cout<<"Ingresar ID: ";
            cin>>id;
            archivoD.listarDeportePorId(id);
            break;
        case 3:
            archivoD.listarTodo();
            break;
        case 4:
            archivoD.modificarAnioDeOrigen();
            break;
        case 5:
            archivoD.eliminarRegistroDeDeporte();
            break;
        case 0:
            return;
            break;
        default:
            cout<<"Error, vuelve a ingresar un numero";
            break;
        }
        system ("pause");
    }
}

void menuReportes()
{
    int opc;
    while (true)
    {
        system("cls");
        cout<<"MENU REPORTES"<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout<<"1) PUNTO 1"<<endl;
        cout<<"2) PUNTO 2"<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opc;
        system("cls");

        switch (opc)
        {
        case 1:
            break;
        case 2:
            break;
        case 0:
            return;
            break;
        default:
            cout<<"Error, vuelve a ingresar un numero";
            break;
        }
        system ("pause");
    }
}

void menuConfiguracion ()
{
    int opc;
    while (true)
    {
        system("cls");
        cout<<"MENU CONFIGURACIÓN"<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout<<"1) COPIA DE SEGURIDAD DEL ARCHIVO DE JUGADORES"<<endl;
        cout<<"2) COPIA DE SEGURIDAD DEL ARCHIVO DE DEPORTES"<<endl;
        cout<<"3) COPIA DE SEGURIDAD DEL ARCHIVO DE EQUIPOS"<<endl;
        cout<<"4) COPIA DE SEGURIDAD DEL ARCHIVO DE TIPO DE DEPORTES"<<endl;
        cout<<"5) RESTAURAR EL ARCHIVO DE JUGADORES"<<endl;
        cout<<"6) RESTAURAR EL ARCHIVO DE DEPORTES"<<endl;
        cout<<"7) RESTAURAR EL ARCHIVO DE EQUIPOS"<<endl;
        cout<<"8) RESTAURAR EL ARCHIVO DE TIPO DE DEPORTES"<<endl;
        cout<<"9) ESTABLECER DATOS DE INICIO"<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opc;
        system("cls");

        switch (opc)
        {
        case 1:
            copiaSeguridadJugadores();
            break;
        case 2:
            copiaSeguridadDeportes();
            break;
        case 3:
            copiaSeguridadEquipo();
            break;
        case 4:
            copiaSeguridadTipoDeportes();
            break;
        case 5:
            restaurarJugadores();
            break;
        case 6:
            restaurarDeportes();
            break;
        case 7:
            restaurarEquipo();
            break;
        case 8:
            restaurarTipoDeportes();
            break;
        case 9:
            establecerDatosInicio();
            break;
        case 0:
            return;
            break;
        default:
            cout<<"Error, vuelve a ingresar un numero";
            break;
        }
        system ("pause");
    }
}

void menuEquipo ()
{
    ArchivoEquipos archivoE("equipos.dat");
    int opc,id;
    while (true)
    {
        system("cls");
        cout<<"MENU EQUIPO"<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout<<"1) AGREGAR EQUIPO"<<endl;
        cout<<"2) LISTAR EQUIPO POR ID"<<endl;
        cout<<"3) LISTAR TODO"<<endl;
        cout<<"4) MODIFICAR NOMBRE"<<endl;
        cout<<"5) ELIMINAR REGISTRO"<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opc;
        system("cls");

        switch (opc)
        {
        case 1: archivoE.agregarEquipo();
            break;
        case 2:
            cout<<"Ingrese id: ";
            cin>>id;
            archivoE.listarEquipoPorId(id);
            break;
        case 3: archivoE.listarTodosLosEquipos();
            break;
        case 4: archivoE.modificarNombre();
            break;
        case 5: archivoE.eliminarRegistroDeEquipo();
            break;
        case 0:
            return;
            break;
        default:
            cout<<"Error, vuelve a ingresar un numero";
            break;
        }
        system ("pause");
    }
}

void menuTiposDeDeporte ()
{
    ArchivoTipodeDeporte archivoT("TipodeDeporte.dat");
    int opc,id;
    while (true)
    {
        system("cls");
        cout<<"MENU TIPOS DE DEPORTE"<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout<<"1) AGREGAR TIPO"<<endl;
        cout<<"2) LISTAR TIPO POR ID"<<endl;
        cout<<"3) LISTAR TODO"<<endl;
        cout<<"4) MODIFICAR NIVEL DE DIFICULTAD"<<endl;
        cout<<"5) ELIMINAR REGISTRO"<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opc;
        system("cls");

        switch (opc)
        {
        case 1: archivoT.agregarTipo();
            break;
        case 2:
            cout<<"Ingrese id: ";
            cin>>id;
            archivoT.listarTipoPorId(id);
            break;
        case 3: archivoT.listarTodosLosDeportes();
            break;
        case 4: archivoT.modificarNivelDeDificultad();
            break;
        case 5: archivoT.eliminarRegistroDeDeporte();
            break;
        case 0:
            return;
            break;
        default:
            cout<<"Error, vuelve a ingresar un numero";
            break;
        }
        system ("pause");
    }
}

#endif // MENUES_H_INCLUDED
