#ifndef EQUIPOS_H_INCLUDED
#define EQUIPOS_H_INCLUDED

class Equipos{
private:
    int idDeEquipo;
    char nombre[30];
    int nivel;
    bool estado;
public:
    Equipos(){}

    ///SETS
    void setIdDeEquipo(int id){idDeEquipo=id;}
    void setNombre(const char *n){strcpy(nombre,n);}
    bool setNivel(int n){
    if(n>=1&&n<=3){
        nivel=n;
        return true;
    }
    else return false;
    }
    void setEstado(bool e){estado=e;}

    ///GETS
    int getIdDeEquipo(){return idDeEquipo;}
    const char *getNombre(){return nombre;}
    int getNivel(){return nivel;}
    bool getEstado(){return estado;}

    void cargar(){
        cout<<"AGREGAR EQUIPO"<<endl;
        cout<<"-------------------"<<endl;
        cout<<"Id de equipo: ";
        cin>>idDeEquipo;
        cout<<"Nombre: ";
        cargarCadena(nombre,30);
        cout<<"Nivel (1:Principiante, 2:Intermedio, 3:Avanzado): ";
        cin>>nivel;
        estado=true;
    }

    void mostrar(){
        if(estado==true){
        cout<<"-------------------"<<endl;
        cout<<"Id de equipo: "<<idDeEquipo<<endl;
        cout<<"Nombre: "<<nombre<<endl;
        cout<<"Nivel: "<<nivel<<endl;
        cout<<"-------------------"<<endl;
        }
    }
};

class ArchivoEquipos{
private:
    char nombre[30];
public:
    ArchivoEquipos(const char *n){strcpy(nombre,n);}

    const char *getNombre(){return nombre;}

    ///AGREGAR EQUIPO
    bool agregarEquipo(){
    Equipos reg;
    FILE *p;
    p=fopen(nombre,"ab");
    if(p==NULL){
    return false;
    }
    cout<<"Ingresar Equipo: "<<endl;
    reg.cargar();
    fwrite(&reg,sizeof(Equipos),1,p);
    fclose(p);
    return true;

    }

    ///LISTAR EQUIPO POR ID
    bool listarEquipoPorId(int id){
    Equipos reg;
    FILE *p;
    int pos=0;
    p=fopen(nombre,"rb");
    if(p==NULL){
    return -2;
    }
    while(fread(&reg,sizeof (Equipos),1,p)==1){
    if(id==reg.getIdDeEquipo()){
    reg.mostrar();
    fclose(p);
    return pos;
    }
    pos++;
    }

    fclose(p);
    return -1;

    }

    ///LISTAR TODOS LOS EQUIPOS
    bool listarTodosLosEquipos(){
    Equipos reg;
     FILE *p;
     p=fopen(nombre,"rb");
     if(p==NULL){
     return false;
     }
     while(fread(&reg, sizeof(Equipos), 1, p)==1){
     reg.mostrar();
     cout<<endl;
     }

     fclose(p);
     return true;
    }

    ///MODIFICAR NOMBRE
    bool modificarNombre(){
    Equipos reg;
    int id;
    cout<<"Ingrese ID del nombre a cambiar: ";
    cin>>id;

    int pos=buscarID(id);

    if(pos==-1){
        cout<<"No existe el registro con ese DNI";
        return false;
    }
    reg=leerRegistro(pos);

    char nombre[30];
    cout<<"Ingrese el nuevo nombre: ";
    cargarCadena(nombre,30);
    reg.setNombre(nombre);
     bool sobreescribio=modificarDisco(reg,pos);
     return sobreescribio;
    }

    ///ELIMINAR REGISTRO DE EQUIPO-  BAJA LOGICA
    bool eliminarRegistroDeEquipo(){
    Equipos reg;
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
    Equipos leerRegistro(int pos){
    Equipos reg;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
    return reg;
    }
    fseek(p,sizeof(Equipos)*pos,0);
    fread(&reg,sizeof(Equipos),1,p);
    fclose(p);
    return reg;
    }

    ///CONTAR REGISTRO
    int contarRegistro(){
    Equipos reg;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
    return false;
    }
    fseek(p,0,2);
    int bytes=ftell(p);
    return bytes/sizeof(Equipos);
    }

    ///MODIFICAR EN DISCO
    bool modificarDisco(Equipos reg,int pos){
    FILE *p;
    p=fopen(nombre,"rb+");
    if(p==NULL){
    return false;
    }

    fseek(p,sizeof(Equipos)*pos,0);

    bool modifico=fwrite(&reg,sizeof(Equipos),1,p);

    fclose(p);

    return modifico;

    }

    ///BUSCAR ID
    bool buscarID(int id){
    Equipos reg;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){return -2;}
    int pos=0;
        while(fread(&reg,sizeof(Equipos),1,p)==1){
        if(id==reg.getIdDeEquipo()){
            fclose(p);
            return pos;
        }
        pos++;
       }
        fclose(p);
       return -1;

    }
};

#endif // EQUIPOS_H_INCLUDED
