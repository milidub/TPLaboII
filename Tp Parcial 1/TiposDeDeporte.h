#ifndef TIPOSDEDEPORTE_H_INCLUDED
#define TIPOSDEDEPORTE_H_INCLUDED

class TipoDeDeporte{
private:
    int idDeTipo;
    char nombre[30];
    int nivelDificultad;
    bool estado;
public:
    TipoDeDeporte(){}

    ///SETS
    void setIdDeTipo(int id){idDeTipo=id;}
    void setNombre(const char *n){strcpy(nombre,n);}
    bool setNivelDificultad(int n){
    if(n>=1&&n<=8){
        nivelDificultad=n;
        return true;
    }
    else return false;
    }
    void setEstado(bool e){estado=e;}

    ///GETS
    int getIdDeTipo(){return idDeTipo;}
    const char *getNombre(){return nombre;}
    int getNivelDificultad(){return nivelDificultad;}
    bool getEstado(){return estado;}

    void cargar(){
        cout<<"AGREGAR TIPO DE EQUIPO"<<endl;
        cout<<"-------------------"<<endl;
        cout<<"Id de tipo: ";
        cin>>idDeTipo;
        cout<<"Nombre: ";
        cargarCadena(nombre,30);
        cout<<"Nivel de dificultad(1 al 8): ";
        cin>>nivelDificultad;
        estado=true;
    }

    void mostrar(){
        if(estado==true){
        cout<<"-------------------"<<endl;
        cout<<"Id de tipo: "<<idDeTipo<<endl;
        cout<<"Nombre: "<<nombre<<endl;
        cout<<"Nivel: "<<nivelDificultad<<endl;
        cout<<"-------------------"<<endl;
        }
    }
};

class ArchivoTipodeDeporte{
private:
    char nombre[30];
public:
    ArchivoTipodeDeporte(const char *n){strcpy(nombre,n);}

    const char *getNombre(){return nombre;}

    ///AGREGAR TIPO EQUIPO
    bool agregarTipo(){
    TipoDeDeporte reg;
    FILE *p;
    p=fopen(nombre,"ab");
    if(p==NULL){
    return false;
    }
    cout<<"Ingresar Equipo: "<<endl;
    reg.cargar();
    fwrite(&reg,sizeof(TipoDeDeporte),1,p);
    fclose(p);
    return true;

    }

    ///LISTAR EQUIPO POR ID
    bool listarTipoPorId(int id){
    TipoDeDeporte reg;
    FILE *p;
    int pos=0;
    p=fopen(nombre,"rb");
    if(p==NULL){
    return -2;
    }
    while(fread(&reg,sizeof (TipoDeDeporte),1,p)==1){
    if(id==reg.getIdDeTipo()){
    reg.mostrar();
    fclose(p);
    return pos;
    }
    pos++;
    }

    fclose(p);
    return -1;

    }

    ///LISTAR TODOS LOS TIPOS DE DEPORTES
    bool listarTodosLosDeportes(){
    TipoDeDeporte reg;
     FILE *p;
     p=fopen(nombre,"rb");
     if(p==NULL){
     return false;
     }
     while(fread(&reg, sizeof(TipoDeDeporte), 1, p)==1){
     reg.mostrar();
     cout<<endl;
     }

     fclose(p);
     return true;
    }

    ///MODIFICAR NOMBRE
    bool modificarNivelDeDificultad(){
    TipoDeDeporte reg;
    int id;
    cout<<"Ingrese ID del nombre a cambiar: ";
    cin>>id;

    int pos=buscarID(id);

    if(pos==-1){
        cout<<"No existe el registro con ese DNI";
        return false;
    }
    reg=leerRegistro(pos);

    int nivel;
    cout<<"Ingrese el nuevo nivel de dificultad: ";
    cin>>nivel;
    reg.setNivelDificultad(nivel);
     bool sobreescribio=modificarDisco(reg,pos);
     return sobreescribio;
    }

    ///ELIMINAR REGISTRO DE DEPORTE-  BAJA LOGICA
    bool eliminarRegistroDeDeporte(){
    TipoDeDeporte reg;
    int id;
    cout<<"Ingresar ID a dar de baja: ";
    cin>>id;

    int pos=buscarID(id);

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
    TipoDeDeporte leerRegistro(int pos){
    TipoDeDeporte reg;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
    return reg;
    }
    fseek(p,sizeof(TipoDeDeporte)*pos,0);
    fread(&reg,sizeof(TipoDeDeporte),1,p);
    fclose(p);
    return reg;
    }

    ///CONTAR REGISTRO
    int contarRegistro(){
    TipoDeDeporte reg;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
    return false;
    }
    fseek(p,0,2);
    int bytes=ftell(p);
    return bytes/sizeof(TipoDeDeporte);
    }

    ///MODIFICAR EN DISCO
    bool modificarDisco(TipoDeDeporte reg,int pos){
    FILE *p;
    p=fopen(nombre,"rb+");
    if(p==NULL){
    return false;
    }

    fseek(p,sizeof(TipoDeDeporte)*pos,0);

    bool modifico=fwrite(&reg,sizeof(TipoDeDeporte),1,p);

    fclose(p);

    return modifico;

    }

    ///BUSCAR ID
    bool buscarID(int id){
    TipoDeDeporte reg;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){return -2;}
    int pos=0;
        while(fread(&reg,sizeof(TipoDeDeporte),1,p)==1){
        if(id==reg.getIdDeTipo()){
            fclose(p);
            return pos;
        }
        pos++;
       }
        fclose(p);
       return -1;

    }
};

#endif // TIPOSDEDEPORTE_H_INCLUDED
