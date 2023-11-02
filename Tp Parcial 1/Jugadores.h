#ifndef JUGADORES_H_INCLUDED
#define JUGADORES_H_INCLUDED

class Jugadores{
private:
    int dni,claustro,deporte,numeroEquipo;
    char nombre[30],apellido[30],email[30],telefono[20];
    fecha fechaInscripcion;
    float matricula;
    bool estado;
public:
    Jugadores() {}

    ///SETS
    bool setDni(int _dni){
        dni=_dni;
        return true;
    }
    bool setClaustro(int _claustro){
        if(_claustro>0&&_claustro<5){
            claustro=_claustro;
            return true;
        }
        else{return false;}
    }
    bool setDeporte(int _deporte){
    if (_deporte>0&&_deporte<11){
            deporte=_deporte;
            return true;
        }//validar que el reporte exista en archivos
        else{return false;}
    }
    void setNumeroEquipo(int _numeroEquipo){numeroEquipo=_numeroEquipo;}
    void setNombre(const char *_nombre){strcpy(nombre,_nombre);}
    void setEmail(const char *_email){strcpy(email,_email);}
    void setApellido(const char *_apellido){strcpy(apellido,_apellido);}
    void setTelefono(const char *_telefono){strcpy(telefono,_telefono);}
    bool setFechaInscripcion(fecha _fechaInscripcion)
    {
        fecha fechaHoy=fechaHoy.hoy();
        if(_fechaInscripcion.getDia()<1||_fechaInscripcion.getDia()>31){return false;}
        if(_fechaInscripcion.getMes()<1||_fechaInscripcion.getMes()>12){return false;}
        if(_fechaInscripcion.getAnio()>fechaHoy.getAnio()){return false;}
        if(_fechaInscripcion.getDia()>fechaHoy.getDia()&&_fechaInscripcion.getMes()>=fechaHoy.getMes()&&_fechaInscripcion.getAnio()>=fechaHoy.getAnio()){return false;}
        if(_fechaInscripcion.getMes()==2&&_fechaInscripcion.getDia()>28){return false;}
        fechaInscripcion=_fechaInscripcion;
        return true;
    }
    bool setMatricula(float _matricula){
        if(_matricula>=0){
            matricula=_matricula;
            return true;
        }
        else{return false;}
    }
    void setEstado(bool _estado){estado=_estado;}

    ///GETS
    int getDni(){return dni;}
    int getClaustro(){return claustro;}
    int getDeporte(){return deporte;}
    int getNumeroEquipo(){return numeroEquipo;}
    const char *getNombre(){return nombre;}
    const char *getApellido(){return apellido;}
    const char *getEmail(){return email;}
    const char *getTelefono(){return telefono;}
    fecha getFechaInscripcion(){return fechaInscripcion;}
    float getMatricula(){return matricula;}
    bool getEstado(){return estado;}

    bool cargar(){
    cout<<"Agregar Jugador"<<endl;
    cout<<"-------------------"<<endl;
    cout<<"dni: ";
    cin>>dni;
    cout<<"nombre: ";
    cargarCadena(nombre,30);
    cout<<"apellido: ";
    cargarCadena(apellido,30);
    cout<<"email: ";
    cargarCadena(email,30);
    cout<<"Telefono: ";
    cargarCadena(telefono,20);
    cout<<"Claustro(1: docente; 2 alumno; 3 no docente; 4 graduado) : ";
    cin>>claustro;
    cout<<"ID de deporte: ";
    cin>>deporte;
    cout<<"Numero de equipo: ";
    cin>>numeroEquipo;
    cout<<"Fecha de inscripcion";
    fechaInscripcion.Cargar();
    cout<<"matricula: ";
    cin>>matricula;
    estado=true;
    cout<<"-------------------"<<endl;
    }

    void mostrar(int y){
    if(estado==true){
    gotoxy(1,y);
    cout<<dni<<endl;
    gotoxy(7,y);
    cout<<nombre<<endl;
    gotoxy(16,y);
    cout<<apellido<<endl;
    gotoxy(27,y);
    cout<<email<<endl;
    gotoxy(48,y);
    cout<<telefono<<endl;
    gotoxy(58,y);
    cout<<claustro<<endl;
    gotoxy(68,y);
    cout<<deporte<<endl;
    gotoxy(79,y);
    cout<<numeroEquipo<<endl;
    gotoxy(93,y);
    fechaInscripcion.Mostrar();
    gotoxy(111,y);
    cout<<matricula<<endl;
        }
    }

};

///ARCHIVO DE JUGADORES

class ArchivoJugadores{
private:
    char nombre[30];
public:
    ArchivoJugadores(const char *n){strcpy(nombre,n);}

    const char *getNombre(){return nombre;}

    ///AGREGAR JUGADOR-PUNTO 1
    bool agregarJugador(){
    Jugadores obj;
    FILE *p;
    p=fopen(nombre,"ab");
    if(p==NULL){
    return false;
    }
    cout<<"Ingresar datos de Jugador: "<<endl;
    obj.cargar();
    fwrite(&obj,sizeof(Jugadores),1,p);
    fclose(p);
    return true;

    }

    ///LISTAR JUGADOR POR DNI-PUNTO2
    bool listarJugadorPorDni(int dni){
    Jugadores reg;
    FILE *p;
    int pos=0;
    p=fopen(nombre,"rb");
    if(p==NULL){
    return -2;}
    int y=3;
    mostrarJugadores();
    while(fread(&reg,sizeof (Jugadores),1,p)==1){
    if(dni==reg.getDni()){
            pos++;
    reg.mostrar(y);
    fclose(p);
    return pos;
    }
    pos++;
    }

    fclose(p);
    return -1;

    }

    ///LISTAR TODOS LOS JUGADORES-PUNTO 3
    bool listarTodosLosJugadores(){
        int pos;
    Jugadores obj;
     FILE *p;
     p=fopen(nombre,"rb");
     if(p==NULL){
     return false;
     }
     int y=3;
     mostrarJugadores();
     while(fread(&obj, sizeof(Jugadores), 1, p)==1){
     obj.mostrar(y);
     y++;
     cout<<endl;
     }

     fclose(p);
     return true;
    }

    ///MODIFICAR FECHA DE INSCRIPCION-PUNTO 4
    bool modificarFechaDeInscripcion(){
    Jugadores reg;
    int dni,pos;
    fecha nuevaFecha;
    cout<<"ingrese dni de jugador: "<<endl;
    cin>>dni;
    pos=buscarDni(dni);
    if(pos==-1){
        cout<<"no se encontro dni"<<endl;
        return false;
    }
    reg=leerRegistro(pos);
    cout<<"ingrese nueva fecha: "<<endl;
    nuevaFecha.Cargar();
    reg.setFechaInscripcion(nuevaFecha);
    bool reescribio=modificarDisco(reg,pos);
    return reescribio;

    }

    ///ELIMINAR REGISTRO DE JUGADOR-PUNTO 5  BAJA
    bool eliminarRegistroDeJugador(){
    Jugadores reg;
    int dni;
    cout<<"Ingresar DNI a dar de baja: ";
    cin>>dni;

    int pos=buscarDni(dni);

    if(pos==-1){
        cout<<"No existe el registro con ese DNI";
        return false;
    }

    reg=leerRegistro(pos);

    reg.setEstado(false);

    bool sobreescribir=modificarDisco(reg,pos);


    return sobreescribir;

    }


    ///----------------------------------------

    ///FUNCIONES ADICIONALES

    ///LEER EN DISCO
    Jugadores leerRegistro(int pos){
    Jugadores reg;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
    return reg;
    }
    fseek(p,sizeof(Jugadores)*pos,0);
    fread(&reg,sizeof(Jugadores),1,p);
    fclose(p);
    return reg;
    }

    ///CONTAR REGISTRO
    int contarRegistro(){
    Jugadores reg;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
    return false;
    }
    fseek(p,0,2);
    int bytes=ftell(p);
    return bytes/sizeof(Jugadores);
    }

    ///MODIFICAR EN DISCO
    bool modificarDisco(Jugadores obj,int pos){
    FILE *p;
    p=fopen(nombre,"rb+");
    if(p==NULL){
    return false;
    }

    fseek(p,sizeof(Jugadores)*pos,0);

    bool modifico=fwrite(&obj,sizeof(Jugadores),1,p);

    fclose(p);

    return modifico;

    }

    ///BUSCAR DNI
    bool buscarDni(int dni){
    Jugadores  regJugadores;
        FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                return -2;
            }
    int pos=0;
        while( fread(&regJugadores,sizeof(Jugadores),1,p)==1){
        if(dni==regJugadores.getDni()){
            fclose(p);
            return pos;
        }
        pos++;
       }
        fclose(p);
       return -1;

    }

};


#endif // JUGADORES_H_INCLUDED
