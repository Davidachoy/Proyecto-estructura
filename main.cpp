#include <iostream>

using namespace std;

struct Administrador{
    string nomUsuario;
    Administrador * sig;

    Administrador(string nom){
    nomUsuario = nom;
    sig  = NULL;
    }
};

struct Profesor{
    string nombre;
    int cedula;
    int edad;
    Profesor *sig;
    Profesor *ant;
    struct conexionGrupo * suGrupo;

    Profesor(string nom,int ced, int unEdad){

    nombre = nom;
    cedula = ced;
    edad   = unEdad;
    sig = NULL;
    ant=NULL;
    suGrupo = NULL;
    }





};

struct Estudiante{
    string nombre;
    int carnet;
    string carrera;
    Estudiante* sig;

    Estudiante(string nom, int unCarnet, string carr){

    nombre = nom;
    carnet = unCarnet;
    carrera= carr;
    sig  = NULL;
    }


};

struct Semestre{
    int anno;
    int numSemestre;

    Semestre(int unAnno, int unNumSemestre){

    anno = unAnno;
    numSemestre = unNumSemestre;



    }



};
// Conecta a profesor con un grupo
struct conexionGrupo{
    conexionGrupo*sig;
    struct Grupo* enlaceG;

    conexionGrupo(){
    sig = NULL;
    enlaceG = NULL;

    }

};


struct Curso{

    int creditos;
    string nomCurso;
    int codigo;
    Curso*sig;
    struct Grupo*sublistaGrupos;

    Curso(int c,string nom,int cod){
    creditos = c;
    nomCurso = nom;
    codigo   = cod;

    sig  = NULL;
    punG = NULL;

    }
};

struct Grupo{
    int numGrupo;
    Grupo*sig;
    struct Curso*enlaceCurso,*enlaceCursoFinal;
    struct Evaluacion*tempTC,*tempP,*tempExa,*tempG;

    Grupo(int num){
    numGrupo = num;
    sig  = NULL;
    enlaceCurso = NULL;
    enlaceCursoFinal = NULL;
    tempTC = NULL;
    tempP = NULL;
    tempExa = NULL;
    tempG = NULL;
    }

};

struct Evaluacion{
    string tipo;
    int dia;
    int mes;
    int year;
    string horaEntrega;
    Evaluacion*sig;

    Evaluacion(string type, int day, int month, int a, string hour){
    tipo        = type;
    dia         = day;
    mes         = month;
    year        = a;
    horaEntrega = hour;

    sig   = NULL;

    }

};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
