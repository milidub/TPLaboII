#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED

void copiaSeguridadJugadores();
void copiaSeguridadDeportes();
void copiaSeguridadEquipo();
void copiaSeguridadTipoDeportes();
void restaurarJugadores();
void restaurarDeportes();
void restaurarEquipo();
void restaurarTipoDeportes();
void establecerDatosInicio();

///COPIA DE SEGURIDAD DEL ARCHIVO DE JUGADORES

void copiaSeguridadJugadores() {
    FILE *archivoEntrada = fopen("jugadores.dat", "rb");
    FILE *archivoSalida = fopen("jugadores.bkp", "wb");

    if (archivoEntrada == NULL || archivoSalida == NULL) {
        cout << "Error al abrir los archivos." <<endl;
        return;
    }

   int byte;
    while ((byte = fgetc(archivoEntrada)) != EOF) {
        fputc(byte, archivoSalida);
    }


    fclose(archivoEntrada);
    fclose(archivoSalida);

    cout << "COPIA DE SEGURIDAD REALIZADA" <<endl;
}

///COPIA DE SEGURIDAD DEL ARCHIVO DE DEPORTE

void copiaSeguridadDeportes() {
    FILE *archivoEntrada = fopen("deportes.dat", "rb");
    FILE *archivoSalida = fopen("deportes.bkp", "wb");

     if (archivoEntrada == NULL || archivoSalida == NULL) {
        cout << "Error al abrir los archivos." <<endl;
        return;
    }
    int byte;
    while ((byte = fgetc(archivoEntrada)) != EOF) {
        fputc(byte, archivoSalida);
    }


    fclose(archivoEntrada);
    fclose(archivoSalida);
    cout << "COPIA DE SEGURIDAD REALIZADA" <<endl;
}

///COPIA DE SEGURIDAD DEL ARCHIVO DE EQUIPO

void copiaSeguridadEquipo() {
    FILE *archivoEntrada = fopen("equipos.dat", "rb");
    FILE *archivoSalida = fopen("equipos.bkp", "wb");

     if (archivoEntrada == NULL || archivoSalida == NULL) {
        cout << "Error al abrir los archivos." <<endl;
        return;
    }
    int byte;
    while ((byte = fgetc(archivoEntrada)) != EOF) {
        fputc(byte, archivoSalida);
    }


    fclose(archivoEntrada);
    fclose(archivoSalida);
    cout << "COPIA DE SEGURIDAD REALIZADA" <<endl;
}

///COPIA DE SEGURIDAD DEL ARCHIVO DE TIPO DE DEPORTE

void copiaSeguridadTipoDeportes() {
    FILE *archivoEntrada = fopen("TipodeDeporte.dat", "rb");
    FILE *archivoSalida = fopen("TipodeDeporte.bkp", "wb");

     if (archivoEntrada == NULL || archivoSalida == NULL) {
        cout << "Error al abrir los archivos." <<endl;
        return;
    }
    int byte;
    while ((byte = fgetc(archivoEntrada)) != EOF) {
        fputc(byte, archivoSalida);
    }


    fclose(archivoEntrada);
    fclose(archivoSalida);
    cout << "COPIA DE SEGURIDAD REALIZADA" <<endl;
}

///RESTAURAR DEL ARCHIVO DE JUGADORES

void restaurarJugadores() {
 remove("jugadores.dat");
rename("jugadores.bkp", "jugadores.dat");
    cout << "RESTAURACION REALIZADA" << endl;

}

///RESTAURAR DEL ARCHIVO DE DEPORTES

void restaurarDeportes() {
 remove("deportes.dat");
rename("deportes.bkp", "deportes.dat");
    cout << "RESTAURACION REALIZADA" << endl;

}

///RESTAURAR DEL ARCHIVO DE EQUIPO

void restaurarEquipo() {
 remove("equipos.dat");
rename("equipos.bkp", "equipos.dat");
    cout << "RESTAURACION REALIZADA" << endl;

}

///RESTAURAR DEL ARCHIVO DE TIPO DE DEPORTE

void restaurarTipoDeportes() {
 remove("TipodeDeporte.dat");
rename("TipodeDeporte.bkp", "TipodeDeporte.dat");
    cout << "RESTAURACION REALIZADA" << endl;

}

///ESTABLECER DATOS DE INICIO

void establecerDatosInicio () {


}

#endif // CONFIGURACION_H_INCLUDED
