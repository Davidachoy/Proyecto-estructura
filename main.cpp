#include <iostream>
//Nicole Tencio y David Achoy
//Iniciamos: Jueves 02 sept
//Tarea corta#2

using namespace std;


struct Administrador{//Simple list del adiminstrador
    string nomUsuario;
    Administrador * sig;

    Administrador(string nom){
    nomUsuario = nom;
    sig  = NULL;
    }
};

struct Profesor{//Double list del profesor
    string nombre;
    int cedula;
    int edad;
    Profesor *sig;
    Profesor *ant;
    struct conexionGrupo * suGrupo;//conecta con un auxiliar

    Profesor(string nom,int ced, int unEdad){

    nombre = nom;
    cedula = ced;
    edad   = unEdad;
    sig = NULL;
    ant=NULL;
    suGrupo = NULL;
    }
};

struct Estudiante{//Simple list del estuditante
    string nombre;
    int carnet;
    string carrera;
    Estudiante* sig;
    struct ReporteEstudiante*enlaceReporte;// conecta con un auxiliar

    Estudiante(string nom, int unCarnet, string carr){

    nombre = nom;
    carnet = unCarnet;
    carrera= carr;
    sig  = NULL;
    }


};

struct Semestre{//Double list
    int anno;
    int numSemestre;
    Semestre*sig,*ant;
    //structs
    struct Charla*enlaceCharla; // conecta con la estructura de charla
    struct ConexionCurso*enlaceConexionCurso;//conecta con un auxiliar

    Semestre(int unAnno, int unNumSemestre){
    anno = unAnno;
    numSemestre  = unNumSemestre;
    //structs
    enlaceCharla = NULL;
    enlaceConexionCurso = NULL;
    //punteros
    sig = NULL;
    ant = NULL;
    }
};
//auxialiar de la estrctura Profesor.
// Conecta a profesor con un grupo
struct conexionGrupo{
    conexionGrupo*sig;
    struct Grupo* enlaceG;

    conexionGrupo(){
    sig = NULL;
    enlaceG = NULL;

    }

};

struct ConexionCurso{//Conecta a semestre con curso
    ConexionCurso*sig;// lista simple
    struct Curso* enlaceCurso;
    ConexionCurso(){
    sig = NULL;
    enlaceCurso = NULL;
    }
};

struct Curso{ //Circular list de curso

    int creditos;
    string nomCurso;
    int codigo;
    Curso*sig;
    struct Grupo*sublistaGrupos;//Conecta con los grupos

    Curso(int c,string nom,int cod){
    creditos = c;
    nomCurso = nom;
    codigo   = cod;
    sig  = NULL;
    sublistaGrupos = NULL;
    }
};

struct Grupo{//Simple list del grupo

    int numGrupo;
    struct Grupo*sig;
    struct Curso*enlaceCurso;//Conecta con los cursos
    struct Evaluacion*tempTC,*tempP,*tempExa,*tempG;//conecta con las evaluaciones
    Grupo(){

    sig  = NULL;
    //curso
    enlaceCurso = NULL;
    //Evaluaciones
    tempTC = NULL;
    tempP = NULL;
    tempExa = NULL;
    tempG = NULL;
  }
};
struct Evaluacion{//Simple list de evaluaciones
    string nombre;
    int dia;
    int mes;
    int year;
    string horaEntrega;
    Evaluacion*sig;

    Evaluacion(string name, int day, int month, int a, string hour){
    nombre      = name;
    dia         = day;
    mes         = month;
    year        = a;
    horaEntrega = hour;

    sig   = NULL;

    }

};

struct ReporteEstudiante{//Simple list de parte de estudiante

    ReporteEstudiante*sig;
    struct AsistenciaCharla*enlaceAsistenciaCharla;
    struct Grupo*enlaceGrupo;
    struct Calificaciones*enlaceEvaluaciones;
    ReporteEstudiante(){

    sig = NULL;
    enlaceEvaluaciones = NULL;
    enlaceGrupo  = NULL;
    enlaceAsistenciaCharla = NULL;
    }


};

struct Calificaciones{ //Lista simple
    Calificaciones* sig;
    Evaluacion*enlaceEvaluaciones;

    Calificaciones(){
    enlaceEvaluaciones= NULL;
    sig = NULL;
    }
};

struct AsistenciaCharla{//Simple lista

    AsistenciaCharla*sig;
    struct Charla*enlaceCharla;

    AsistenciaCharla(){
    sig = NULL;
    enlaceCharla = NULL;
    }
};

struct Charla{//Simple list de Charlas
    int dia;
    int mes;
    int year;
    string tipoCharla;
    int numCharla;
    Charla*sig;

    Charla(int day, int month, int a, string type, int idC){
        dia = day;
        mes = month;
        year= a;
        tipoCharla = type;
        numCharla  = idC;

        sig = NULL;
    }

};

//Punteros globales
Profesor*primerProfesor;
Semestre*primerSemestre;
Administrador*primerAdministrador;
Estudiante*primerEstudiante;
Curso*primerCurso;

//Login user    punto "a"
Administrador* insertarAdmin(string user){
    Administrador*newuser  = new Administrador(user);
    newuser->sig = primerAdministrador;
    primerAdministrador = newuser;
    return primerAdministrador;
}

bool buscarAdmin(){
    cout<<" \nIngrese el usuario: ";
    string user;
    cin>>user;
    struct Administrador*local = primerAdministrador;
    while(local != NULL){
        if(local->nomUsuario == user){//Verifica si es igual al que se desea buscar
                cout<<"\n--------- Bienvenido ---------\n";
                return true;
        }
        local=local->sig;
    }
    return false;
}


//Punto "b"... Acciones de Admin con profe
Profesor*insertarInicio(string nom, int id,int edad){//Insertar al inicio lista doble

        Profesor*newProf = new Profesor(nom,id,edad);
        newProf->sig = primerProfesor;

        if(primerProfesor != NULL)
            primerProfesor->ant = newProf;

        primerProfesor = newProf;

return primerProfesor;
}

Profesor*eliminarProfe(int id){
    if(primerProfesor == NULL)//Lista vacia
        cout<<"\nLista vacia...";
    else if(primerProfesor->cedula == id){//Sí se encuentra de primero
            primerProfesor->suGrupo = NULL;//Deja de apuntar al grupo
            primerProfesor = primerProfesor->sig;
            if(primerProfesor != NULL)
            primerProfesor->ant = NULL;
    }
    else{
        Profesor*temp = primerProfesor;
        Profesor*tempAnt = NULL;

        while(temp != NULL){
            if(temp->cedula == id){
                temp->suGrupo = NULL;//Deja de apuntar al grupo
                tempAnt->sig = temp->sig;
                if(temp->sig != NULL)
                    temp->sig->ant = tempAnt;
                break;
            }
            else{
                cout<<"\n Id de profesor NO encontrado\n";
            }
            tempAnt = temp;
            temp = temp->sig;
        }
    }
return primerProfesor;
}

//Menus
void menuAdmin(){
    bool repetir = true;
    do{
        if(buscarAdmin() == true){
            int choiceAdmin;
            cout<<"\n ----------- Menu administrador -----------\n\n";
            cout<<" 1 - Acciones con los profesores\n";
            cout<<" 2 - Accines con los estudiantes\n";
            cout<<" 3 - Acciones con los semestres\n";
            cout<<" 4 - Acciones con los cursos\n";
            cout<<" 5 - Insertar los grupos\n";
            cout<<" 6 - Relacionar y borrar profesores con los grupos de los cursos respectivos \n";
            cout<<" 7 - Relacionar y borrar estudiantes con los grupos de los cursos\n";
            cout<<" 8 - Relacionar los semestres con los cursos, insertar y modificar\n";
            cout<<" 9 - Volver a menu principal\n\n";
            cout<<" Opcion: ";
            cin>>choiceAdmin;

            switch(choiceAdmin){

        case 1:
            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            break;

        case 6:
            break;

        case 7:
            break;

        case 8:
            break;

        case 9:
            repetir = false;
            break;
            }
        }
    else{
        repetir = false;
        cout<<" --- Nombre de usuario no encontrado\n --- ";
    }

    }while(repetir);

}

void menuProfe(){
    bool acceso = true;
    do{
        cout<<"----------- Menu de profesores -----------\n\n";
        cout<<" 1 - Insertar, modoficar o borrar actividades relacionadas con los cursos\n";
        cout<<" 2 - Insertar charla\n";
        cout<<" 3 - Reportes\n";
        cout<<" 4 - Salir\n\n";
        cout<<" Opcion: ";

        int choiceProf;
        cin>>choiceProf;

        switch(choiceProf){
    case 1:
        break;

    case 2:
        break;

    case 3:
        break;

    case 4:
        acceso = false;
        break;
        }

    }while(acceso);
}

void menuEst(){
    bool repetir = true;
    do{
        cout<<"----------- Menu de estudiantes -----------\n\n";
        cout<<" 1 - Registrar actividad cumplida\n";
        cout<<" 2 - Registrar asistencia en alguna charla\n";
        cout<<" 3 - Reportes\n";
        cout<<" 4 - Salir\n\n";
        cout<<" Opcion: ";

        int choiceEst;
        cin>>choiceEst;

        switch(choiceEst){
    case 1:
        break;

    case 2:
        break;

    case 3:
        break;

    case 4:
        repetir = false;
        break;

        }
    }while(repetir);
};

void menuUsuarios(){
    bool repetir = false;
    do{
        int choiceUser;
        cout<<"----------- Menu de usuarios -----------\n\n";
        cout<<" 1 - Ingresar como estudiante\n";
        cout<<" 2 - Ingresar como profesor\n";
        cout<<" 3 - Volver a menu principal\n";
        cout<<" Opcion: ";
        cin>> choiceUser;

        switch(choiceUser){
    case 1:
        menuEst();
        break;


    case 2:
        menuProfe();
        break;

    case 3:
        repetir = false;
        break;
        }
    }while(repetir);
}


int main()
{
    //Inserción de los usuarios de los administradores
    primerAdministrador = insertarAdmin("Admin1");
    primerAdministrador = insertarAdmin("Admin2");
    primerAdministrador = insertarAdmin("Admin3");

    bool repetir = true;

    do{
        int choice;
        cout<<"----------- Menu principal -----------\n\n";
        cout<<" 1 - Seccion administrador\n";
        cout<<" 2 - Seccion de usuarios (Profesores y estudiantes)\n";
        cout<<" 3 - Salir\n\n";
        cout<<" Opcion: ";
        cin>>choice;

        switch(choice){

    case 1:
        menuAdmin();
        break;

    case 2:
        menuUsuarios();
        break;

    case 3:
        repetir = false;
        break;
        }
    }while(repetir);

    return 0;
}
