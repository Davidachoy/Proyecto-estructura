#include <iostream>

using namespace std;

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
