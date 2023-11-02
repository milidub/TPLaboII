#ifndef DEPORTES_H_INCLUDED
#define DEPORTES_H_INCLUDED

class Deporte{
private:
    int id, tipoDeporte, anioOrigen;
    char nombre[30];
    bool estado;
public:
    Deporte(){}

    ///SETS
    bool setTipoDeporte(int _tipoDeporte){
    if(_tipoDeporte>0&&_tipoDeporte<22){
        tipoDeporte=_tipoDeporte;
        return true;
    }else return false;
    } /// validar que el deporte exista en id de tipo deporte
    void setAnioOrigen(int _anioOrigen){
    fecha hoy=hoy.hoy();
    anioOrigen=_anioOrigen;
    }
    void setNombre(const char *_nombre){strcpy(nombre,_nombre);}
    void setEstado(bool _estado){estado=_estado;}

    ///GETS
    int getId(){return id;}
    int getTipoDeporte(){return tipoDeporte;}
    int getAnioOrigen(){return anioOrigen;}
    const char *getNombre(){return nombre;}
    bool getEstado(){return estado;}

    void cargar(){
    cout<<"Agregar Deporte"<<endl;
    cout<<"-------------------"<<endl;
    cout<<"Id de deporte: ";
    cin>>id;
    cout<<"Nombre: ";
    cin>>nombre;
    cout<<"Tipo de deporte: ";
    cin>>tipoDeporte;
    cout<<"Anio de origen: ";
    cin>>anioOrigen;
    estado=true;

    }


    void mostrar(){
    if(estado==true){
    cout<<"-------------------"<<endl;
    cout<<"Id de deporte: "<<id<<endl;
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Tipo de deporte: "<<tipoDeporte<<endl;
    cout<<"Anio de origen: "<<anioOrigen<<endl;
    cout<<"-------------------"<<endl;
    }
    }


};

///ARCHIVO DE DEPORTE

class ArchivoDeporte{
private:
 char nombre[30];
public:
    ArchivoDeporte(const char* n){strcpy(nombre,n);}

    const char *getNombre(){return nombre;}

    ///AGREGAR DEPORTE-PUNTO 1
    bool agregarJugador(){
    Deporte reg;
    FILE *p;
    p=fopen(nombre,"ab");
    if(p==NULL){
    return false;
    }
    cout<<"Ingresar datos de Jugador: "<<endl;
    reg.cargar();
    fwrite(&reg,sizeof(Deporte),1,p);
    fclose(p);
    return true;

    }

    ///LISTAR DEPORTE POR ID-PUNTO 2
    bool listarDeportePorId(int id){
    Deporte reg;
    FILE *p;
    int pos=0;
    p=fopen(nombre,"rb");
    if(p==NULL){
    return -2;
    }
    while(fread(&reg,sizeof (Deporte),1,p)==1){
    if(id==reg.getId()){
    reg.mostrar();
    fclose(p);
    return pos;
    }
    pos++;
    }

    fclose(p);
    return -1;

    }

    ///LISTAR TODO-PUNTO 3
    bool listarTodo(){
    Deporte reg;
     FILE *p;
     p=fopen(nombre,"rb");
     if(p==NULL){
     return false;
     }
     while(fread(&reg, sizeof(Deporte), 1, p)==1){
     reg.mostrar();
     cout<<endl;
     }

     fclose(p);
     return true;
    }


    ///MODIFICAR AÑO DE ORIGEN-PUNTO 4
    bool modificarAnioDeOrigen(){
    Deporte reg;
    int id,pos,anio;
    cout<<"ingrese el ID a modificar: "<<endl;
    cin>>id;
    pos=buscarId(id);
    if(pos==-1){
        cout<<"no se encontro dni"<<endl;
        return false;
    }
    reg=leerRegistro(pos);
    cout<<"Ingrese nuevo anio: "<<endl;
    cin>>anio;
    reg.setAnioOrigen(anio);
    bool reescribio=modificarDisco(reg,pos);
    return reescribio;
    }

    ///ELIMINAR REGISTRO-PUNTO 5
    bool eliminarRegistroDeDeporte(){
    Deporte reg;
    int id;
    cout<<"Ingresar ID a dar de baja: ";
    cin>>id;

    int pos=buscarId(id);

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
    Deporte leerRegistro(int pos){
    Deporte reg;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
    return reg;
    }
    fseek(p,sizeof(Deporte)*pos,0);
    fread(&reg,sizeof(Deporte),1,p);
    fclose(p);
    return reg;
    }

    ///CONTAR REGISTRO
    int contarRegistro(){
    Deporte reg;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
    return false;
    }
    fseek(p,0,2);
    int bytes=ftell(p);
    return bytes/sizeof(Deporte);
    }

    ///MODIFICAR EN DISCO
    bool modificarDisco(Deporte reg, int pos){
    FILE *p;
    p=fopen(nombre,"rb+");
    if(p==NULL){
    return false;
    }

    fseek(p,sizeof(Deporte)*pos,0);

    bool modifico=fwrite(&reg,sizeof(Deporte),1,p);

    fclose(p);

    return modifico;

    }

    ///BUSCAR ID
    bool buscarId(int id){
    Deporte  reg;
        FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                return -2;
            }
    int pos=0;
        while( fread(&reg,sizeof(Deporte),1,p)==1){
        if(id==reg.getId()){
            fclose(p);
            return pos;
        }
        pos++;
       }
        fclose(p);
       return -1;

    }

};

#endif // DEPORTES_H_INCLUDED
