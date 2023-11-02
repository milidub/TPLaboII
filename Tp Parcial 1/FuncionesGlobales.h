#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED

void cargarCadena(char *palabra, int tamano){

    int i=0;

    fflush(stdin);

    for (i=0; i<tamano; i++){

        palabra[i]=cin.get();

        if (palabra[i]=='\n'){

            break;

        }

    }

    palabra[i]='\0';

    fflush(stdin);

}

void mostrarJugadores(){
    int y=2;
    gotoxy(1,y);
    cout<<"DNI";
    gotoxy(7,y);
    cout<<"NOMBRE";
    gotoxy(16,y);
    cout<<"APELLIDO";
    gotoxy(27,y);
    cout<<"EMAIL";
    gotoxy(48,y);
    cout<<"TELEFONO";
    gotoxy(58,y);
    cout<<"CLAUSTRO";
    gotoxy(68,y);
    cout<<"ID DEPORTE";
    gotoxy(79,y);
    cout<<"NRO DE EQUIPO";
    gotoxy(93,y);
    cout<<"FECHA INSCRIPCION";
    gotoxy(111,y);
    cout<<"MATRICULA";
}


#endif // FUNCIONESGLOBALES_H_INCLUDED
