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
//ReporteEstudiante*

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
