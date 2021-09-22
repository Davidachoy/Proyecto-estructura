#include <iostream>

using namespace std;

/*
Primer proyecto de estructuras de datos

Estudiantes: Nicole Tencio y David Achoy

Fecha de inicio: Jueves 02 sept
*/

//Estructuras a usar
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

struct Estudiante{//Simple list del estudiante
    string nombre;
    int carnet;
    string carrera;
    Estudiante* sig;
    struct ReporteEstudiante*enlaceReporte;// conecta con un auxiliar
    struct ReporteCharla*enlaceCharla;

    Estudiante(string nom, int unCarnet, string carr){

    nombre = nom;
    carnet = unCarnet;
    carrera= carr;
    sig  = NULL;
    enlaceReporte = NULL;
    enlaceCharla = NULL;
    }


};

struct Semestre{//Double list
    int anno;
    int numSemestre;
    Semestre*sig,*ant;
    //structs
    struct Charla*sublistaCharla; // conecta con la estructura de charla
    struct ConexionCurso*enlaceConexionCurso;//conecta con un auxiliar

    Semestre(int unAnno, int unNumSemestre){
    anno = unAnno;
    numSemestre  = unNumSemestre;
    //structs
    sublistaCharla = NULL;
    enlaceConexionCurso = NULL;
    //punteros
    sig = NULL;
    ant = NULL;
    }
};

struct conexionGrupo{// Conecta a profesor con un grupo   //auxialiar de la estrctura Profesor.
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

struct Curso{ //Circular list de curso creditos(int)-nombre(string)-codigo(int)

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
    Grupo(int unNum){
    numGrupo = unNum;
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
    int id;
    Evaluacion*sig;

    Evaluacion(string name, int day, int month, int a, int id){
    nombre      = name;
    dia         = day;
    mes         = month;
    year        = a;
    id          = id;

    sig   = NULL;

    }

};

struct ReporteCharla{

    struct AsistenciaCharla*enlaceAsistenciaCharla;
    ReporteCharla*sig;

    ReporteCharla(){

    sig = NULL;
    enlaceAsistenciaCharla = NULL;

    }

};

struct ReporteEstudiante{//Simple list de parte de estudiante

    ReporteEstudiante*sig;
    struct Grupo*enlaceGrupo;
    struct Calificaciones*enlaceEvaluaciones;
    ReporteEstudiante(){

    sig = NULL;
    enlaceEvaluaciones = NULL;
    enlaceGrupo  = NULL;
    //enlaceAsistenciaCharla = NULL;
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
    string tipoCharla;
    int numCharla;
    int dia;
    int mes;
    int anno;
    Charla*sig;

    Charla(string type, int idC,int day,int month,int year){
        tipoCharla = type;
        numCharla  = idC;
        dia = day;
        mes = month;
        anno = year;

        sig = NULL;
    }

};

//Punteros globales
Profesor*primerProfesor;
Semestre*primerSemestre;
Administrador*primerAdministrador;
Estudiante*primerEstudiante;
Curso*primerCurso;

//punto "a"
Administrador* insertarAdmin(string user){//Inserta los usuarios
    Administrador*newuser  = new Administrador(user);
    newuser->sig = primerAdministrador;
    primerAdministrador = newuser;
return primerAdministrador;
}

bool buscarAdmin(){//Login user
    cout<<" \nIngrese el usuario: ";
    string user;
    cin>>user;
    struct Administrador*local = primerAdministrador;
    while(local != NULL){
        if(local->nomUsuario == user){//Verifica si es igual al que se desea buscar
                cout<<"\n+++++++++++++++++++++++++++++++++++++++++++";
                cout<<"\n+               Bienvenid@                +";
                cout<<"\n+++++++++++++++++++++++++++++++++++++++++++\n";
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

bool modificarProfesor(int ced, string nom){

    if(primerEstudiante == NULL)
        cout<<"Lista de profesores vacia...\n";

    Profesor* temp = primerProfesor;
    while(temp != NULL){
        if(temp->cedula == ced){
            temp->nombre = nom;
            return true;
        }
        temp = temp->sig;
    }
    return false;
}

bool eliminarProfe(int id){
    if(primerProfesor == NULL)//Lista vacia
        cout<<"\nLista vacia...";
    else if(primerProfesor->cedula == id){//Sí se encuentra de primero
            primerProfesor->suGrupo = NULL;//Deja de apuntar al grupo
            primerProfesor = primerProfesor->sig;
            if(primerProfesor != NULL)
            primerProfesor->ant = NULL;
            return true;
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
                    return true;
                return true;
                break;
            }
            tempAnt = temp;
            temp = temp->sig;
        }
    }
return false;
}

//Punto "c"... Insertar, modificar y borrar estudiantes (inserción ordenada por carnet en lista simple)

Estudiante*InsertaEst(string nombre, int num, string carrera){//Insertar a los estudiantes

    Estudiante* newEst = new Estudiante(nombre,num,carrera);
    //newEst->carnet = num;
    newEst->sig = NULL;//nullptr;

    if(primerEstudiante == NULL||num < primerEstudiante->carnet){
        newEst->sig = primerEstudiante;
        primerEstudiante = newEst;
        //cout<<"  Estudiante agregado salisfactoriamente\n";
    }
    else{
        Estudiante*temp = primerEstudiante;
        while(temp->sig != NULL && temp->sig->carnet < num){
            newEst->sig = primerEstudiante;
            temp = temp->sig;
            //cout<<"  Estudiante agregado salisfactoriamente\n";

        }
        if(temp->sig != NULL){
            newEst->sig = temp->sig;
            //cout<<"  Estudiante agregado salisfactoriamente\n";

        }
        temp->sig = newEst;

    return primerEstudiante;
    }
return primerEstudiante;
}

bool modificarEstudiante(int id, string carreraNueva){//Modifica la carrera del estudiante

    Estudiante*temp = primerEstudiante;

    while(temp != NULL){
        if(temp->carnet == id){
            temp->carrera = carreraNueva;
            cout<<"\tEstudiante modificado exitosamente...\n";
            return true;
        }
        temp = temp->sig;
    }
    return false;
}

void borrarEst(int num){//Borra a un estudiante por su número de carnet
    if (primerEstudiante == NULL){
        cout<<"\n+++++++++++++++++++++++++++++++++++++++++++";
        cout<<"\n+ Aun no se han ingresado los estudiantes +";
        cout<<"\n+++++++++++++++++++++++++++++++++++++++++++\n";
    }
    else if(primerEstudiante->carnet == num){
        primerEstudiante = primerEstudiante->sig;
        cout<<"\tEstudiante borrado exitosamente...\n";
    }
    else{
        Estudiante*temp = primerEstudiante;
        Estudiante*tempAnt = primerEstudiante;

        while(temp!= NULL){

            if(temp->carnet == num){
                tempAnt->sig = temp->sig;
                cout<<"\tEstudiante borrado exitosamente...\n";
            }
            tempAnt = temp;
			temp = temp->sig;
        }
        if(temp == NULL){
        }
    }
}

//Metodos de impresion
void imprimirEstudiante();
void imprimirProfesor();
void imprimirCharlas();

//Metodos de buscar
bool buscarEstudiante(int num);
bool buscarProfesor(int ced);
bool buscarSemestreBool(int year, int numS);
Curso* buscarCurso(int codigo);
Grupo*buscarGrupo(int codigo, Curso*puntero);
Estudiante*buscarEstudianteReturn(int carnet);
Profesor*buscarProfesor2(int ced);
Semestre*buscarSemestre(int year, int numS);

//punto **D** inserta y modificar semestres     falta modificar
//E: anno y numsemestre
//S: semestre creado de forma ordenada en lista doble
Semestre* insertarSemestreOrdenado(int anno,int numSemestre){

        Semestre *newSemestre = new Semestre(anno,numSemestre);

        if(primerSemestre == NULL)
            primerSemestre = newSemestre;
        else if(anno == primerSemestre->anno && numSemestre<primerSemestre->numSemestre ){
                newSemestre->sig = primerSemestre;
                primerSemestre->ant = newSemestre;
                primerSemestre = newSemestre;
            }
        else if(anno < primerSemestre->anno){
                newSemestre->sig = primerSemestre;
                primerSemestre->ant = newSemestre;
                primerSemestre = newSemestre;
            }
     else{

        Semestre*temp = primerSemestre;
        Semestre*tempAnt =NULL;


        while(temp != NULL){
                if(temp->anno ==  newSemestre->anno){
                    if(temp->numSemestre > newSemestre->numSemestre){
                    break;
                    }}


                tempAnt = temp;
                temp = temp->sig;


        }//
        if(temp ==NULL){//el numero a insertar es mayor a todos
               tempAnt->sig = newSemestre;
               newSemestre->ant =  tempAnt;
        }





        else{// insertar en medio
            newSemestre->sig = temp;
            newSemestre->ant = tempAnt;
            tempAnt->sig = newSemestre;
            temp->ant = newSemestre;
        }
     }

return primerSemestre;
}

//punto **E** insertar curso lista circular final        falta borrar y modificar
//E: creditos, nombre, codigo
Curso* insertarCurso(int creditos, string nombre, int codigo){

    Curso* newCurso = new Curso(creditos,nombre,codigo);

    if(primerCurso == NULL){

        primerCurso = newCurso;
        newCurso->sig = newCurso;// aqui se apunta asi mismo

    }
    else{
        newCurso->sig = primerCurso;
        Curso* temp = primerCurso;
        while(temp->sig != primerCurso)
            temp = temp->sig;

        temp->sig = newCurso;
}return newCurso;
}


//punto **F** insertar grupo relacionandolo con los cursos
//E:Recibe un numero de grupo
//S: True si lo asocia, false si no lo asosia
bool insertarGrupo(int unNum, int codigo){
    Curso*tempC = buscarCurso(codigo);
    if (tempC == NULL)
        return false;
    Grupo* newGrupo = new Grupo(unNum);
    if (tempC->sublistaGrupos == NULL){
        tempC->sublistaGrupos = newGrupo;
        newGrupo->enlaceCurso= tempC;
        return true;
    }
    Grupo*tempGrupo = tempC->sublistaGrupos;
    if(tempGrupo->numGrupo>newGrupo->numGrupo){
        tempC->sublistaGrupos = newGrupo;
        newGrupo->enlaceCurso= tempC;
        newGrupo->sig = tempGrupo;
        return true;
    }
    Grupo*tempGrupoAnt = NULL;
    //Doble*temp = lista;
    //Doble*tempAnt =NULL;
    while((tempGrupo != NULL) && (unNum > tempGrupo->numGrupo)){
                tempGrupoAnt = tempGrupo;
                tempGrupo = tempGrupo->sig;
        }
        if(tempGrupo ==NULL){//el grupo a insertar es mayor a todos
               tempGrupoAnt->sig = newGrupo;
               return true;
        }
        else{// insertar en medio
            newGrupo->sig = tempGrupo;
            tempGrupoAnt->sig = newGrupo;
            return true;
        }




}
/* imprimir los grupos
void imprimirGrupos(int codigo){

        Curso *tempC = buscarCurso(codigo);

        if(tempC== NULL){
            cout<<"No se encuentra el curso";
            return;
        }
         cout<<"\n--------------------------INFORME DE MATRICULA ---------------------------------------\n";

        cout<<"\nLos grupos de: "<<tempC->nomCurso<<" es: "<<endl;
        Grupo *tempG = tempC->sublistaGrupos;

        while(tempG != NULL){

            cout<<"\t"<<tempG->numGrupo<<endl;
            tempG = tempG->sig;
        }

        cout<<"\n--------------------------ULTIMA LINEA ---------------------------------------\n";

}*/

//Punto "G"
bool relacionarProfesoresGrupo(int ced, int codigoCurso,int numGrupo){

    Profesor*tempP = buscarProfesor2(ced);
    if(tempP == NULL)
        return false;

    Curso*tempC = buscarCurso(codigoCurso);
    if(tempC == NULL)
        return false;

    Grupo*tempG = buscarGrupo(numGrupo, tempC);
    if(tempG == NULL)
        return false;

    conexionGrupo*newConexion = new conexionGrupo();
    newConexion->enlaceG = tempG;
    newConexion->sig = tempP->suGrupo;
    tempP->suGrupo = newConexion;//
    return true;

}

//punto **H** relacionar y borrar estudiantes de los grupos
bool relacionarEstudiantesGrupo(int carnet,int codigoCurso, int numGrupo){
    Estudiante*tempE = buscarEstudianteReturn(carnet);
    if (tempE == NULL)
        return false;
    Curso*tempC = buscarCurso(codigoCurso);
    if (tempC == NULL)
        return false;
    Grupo*tempG = buscarGrupo(numGrupo, tempC);
    if (tempG==NULL)
        return false;
    ReporteEstudiante*newReporte = new ReporteEstudiante();
    newReporte->enlaceGrupo = tempG;
    newReporte->sig = tempE->enlaceReporte;
    tempE ->enlaceReporte = newReporte;// inserta al inicio de la sublista de matricula
    return true;
}

//Punto "i"
bool relacionarSemestresCursos(int year, int numS, int codC){

    Semestre*tempS = buscarSemestre(year,numS);
    if(tempS == NULL)
        return false;

    Curso*tempC = buscarCurso(codC);
    if(tempC == NULL)
        return false;


    ConexionCurso* newConexion = new ConexionCurso();
    newConexion->enlaceCurso = tempC;
    newConexion->sig = tempS->enlaceConexionCurso;
    tempS->enlaceConexionCurso = newConexion;
    return true;

}

void imprimirInformeMatricula(int year, int numS){

        Semestre*tempE = buscarSemestre(year,numS);

        if(tempE== NULL){
            cout<<"No se encuentra el estudiante";
            return;
        }
         cout<<"\n--------------------------INFORME DE MATRICULA ---------------------------------------\n";

        cout<<"\nYear : "<<tempE->anno<<" numS: "<<tempE->numSemestre<<endl;
        ConexionCurso*tempR = tempE->enlaceConexionCurso;

        while(tempR != NULL){

            cout<<"\t"<<tempR->enlaceCurso->nomCurso<<endl;
            tempR = tempR->sig;
        }

        cout<<"\n--------------------------ULTIMA LINEA ---------------------------------------\n";

};

//Inserción de las evaluaciones
bool insertarProyecto(Evaluacion*nuevaEvaluacion, Grupo*grupo){
    if( grupo->tempP == NULL){
        grupo->tempP = nuevaEvaluacion;
        return true;
    }
    Evaluacion*tempEvaluacion = grupo->tempP;

    if (tempEvaluacion->year>nuevaEvaluacion->year){
        nuevaEvaluacion ->sig = tempEvaluacion;
        grupo->tempP = nuevaEvaluacion;
         return true;
    }

    if (tempEvaluacion->year == nuevaEvaluacion->year && tempEvaluacion->mes>nuevaEvaluacion->mes){
        nuevaEvaluacion ->sig = tempEvaluacion;
        grupo->tempP = nuevaEvaluacion;
            return true;
        }
    if (tempEvaluacion->year == nuevaEvaluacion->year && tempEvaluacion->mes == nuevaEvaluacion->mes && tempEvaluacion->dia>nuevaEvaluacion->dia){
        nuevaEvaluacion ->sig = tempEvaluacion;
        grupo->tempP = nuevaEvaluacion;
        return true;
            }


    Evaluacion*tempEvaluacionAnt = NULL;
    while(tempEvaluacion!=NULL){
            if(tempEvaluacion->year == nuevaEvaluacion->year){
                if(tempEvaluacion->mes == nuevaEvaluacion->mes){
                    if (tempEvaluacion->dia> nuevaEvaluacion->dia)
                        break;
                }
            }
            if(tempEvaluacion->year == nuevaEvaluacion->year){
                if(tempEvaluacion->mes > nuevaEvaluacion->mes){
                    break;
                }
            }
                tempEvaluacionAnt = tempEvaluacion;
                tempEvaluacion = tempEvaluacion->sig;
}

    if (tempEvaluacion==NULL){

        tempEvaluacionAnt->sig = nuevaEvaluacion;
        return true;

    }else{
        nuevaEvaluacion->sig = tempEvaluacion;
        tempEvaluacionAnt->sig = nuevaEvaluacion;
        return true;
    }

return true;

}

bool insertarExamen(Evaluacion*nuevaEvaluacion, Grupo*grupo){
    if( grupo->tempExa == NULL){
        grupo->tempExa = nuevaEvaluacion;
        return true;
    }
    Evaluacion*tempEvaluacion = grupo->tempExa;

    if (tempEvaluacion->year>nuevaEvaluacion->year){
        nuevaEvaluacion ->sig = tempEvaluacion;
        grupo->tempExa = nuevaEvaluacion;
         return true;
    }

    if (tempEvaluacion->year == nuevaEvaluacion->year && tempEvaluacion->mes>nuevaEvaluacion->mes){
        nuevaEvaluacion ->sig = tempEvaluacion;
        grupo->tempExa = nuevaEvaluacion;
            return true;
        }
    if (tempEvaluacion->year == nuevaEvaluacion->year && tempEvaluacion->mes == nuevaEvaluacion->mes && tempEvaluacion->dia>nuevaEvaluacion->dia){
        nuevaEvaluacion ->sig = tempEvaluacion;
        grupo->tempExa = nuevaEvaluacion;
        return true;
            }

    Evaluacion*tempEvaluacionAnt = NULL;
    while(tempEvaluacion!=NULL){
            if(tempEvaluacion->year == nuevaEvaluacion->year){
                if(tempEvaluacion->mes == nuevaEvaluacion->mes){
                    if (tempEvaluacion->dia> nuevaEvaluacion->dia)
                        break;
                }
            }
            if(tempEvaluacion->year == nuevaEvaluacion->year){
                if(tempEvaluacion->mes > nuevaEvaluacion->mes){
                    break;
                }
            }
                tempEvaluacionAnt = tempEvaluacion;
                tempEvaluacion = tempEvaluacion->sig;
}

    if (tempEvaluacion==NULL){

        tempEvaluacionAnt->sig = nuevaEvaluacion;
        return true;

    }else{
        nuevaEvaluacion->sig = tempEvaluacion;
        tempEvaluacionAnt->sig = nuevaEvaluacion;
        return true;
    }
return true;
}

bool insertarTarea(Evaluacion*nuevaEvaluacion, Grupo*grupo){
    if( grupo->tempTC == NULL){
        grupo->tempTC = nuevaEvaluacion;
        return true;
    }
    Evaluacion*tempEvaluacion = grupo->tempTC;

    if (tempEvaluacion->year>nuevaEvaluacion->year){
        nuevaEvaluacion ->sig = tempEvaluacion;
        grupo->tempTC = nuevaEvaluacion;
         return true;
    }

    if (tempEvaluacion->year == nuevaEvaluacion->year && tempEvaluacion->mes>nuevaEvaluacion->mes){
        nuevaEvaluacion ->sig = tempEvaluacion;
        grupo->tempTC = nuevaEvaluacion;
            return true;
        }
    if (tempEvaluacion->year == nuevaEvaluacion->year && tempEvaluacion->mes == nuevaEvaluacion->mes && tempEvaluacion->dia>nuevaEvaluacion->dia){
        nuevaEvaluacion ->sig = tempEvaluacion;
        grupo->tempTC = nuevaEvaluacion;
        return true;
            }


    Evaluacion*tempEvaluacionAnt = NULL;
    while(tempEvaluacion!=NULL){
            if(tempEvaluacion->year == nuevaEvaluacion->year){
                if(tempEvaluacion->mes == nuevaEvaluacion->mes){
                    if (tempEvaluacion->dia> nuevaEvaluacion->dia)
                        break;
                }
            }
            if(tempEvaluacion->year == nuevaEvaluacion->year){
                if(tempEvaluacion->mes > nuevaEvaluacion->mes){
                    break;
                }
            }
                tempEvaluacionAnt = tempEvaluacion;
                tempEvaluacion = tempEvaluacion->sig;
}

    if (tempEvaluacion==NULL){

        tempEvaluacionAnt->sig = nuevaEvaluacion;
        return true;

    }else{
        nuevaEvaluacion->sig = tempEvaluacion;
        tempEvaluacionAnt->sig = nuevaEvaluacion;
        return true;
    }

return true;

}

bool insertarGiras(Evaluacion*nuevaEvaluacion, Grupo*grupo){
    if( grupo->tempG == NULL){
        grupo->tempG = nuevaEvaluacion;
        return true;
    }
    Evaluacion*tempEvaluacion = grupo->tempG;

    if (tempEvaluacion->year>nuevaEvaluacion->year){
        nuevaEvaluacion ->sig = tempEvaluacion;
        grupo->tempG = nuevaEvaluacion;
         return true;
    }

    if (tempEvaluacion->year == nuevaEvaluacion->year && tempEvaluacion->mes>nuevaEvaluacion->mes){
        nuevaEvaluacion ->sig = tempEvaluacion;
        grupo->tempG = nuevaEvaluacion;
            return true;
        }
    if (tempEvaluacion->year == nuevaEvaluacion->year && tempEvaluacion->mes == nuevaEvaluacion->mes && tempEvaluacion->dia>nuevaEvaluacion->dia){
        nuevaEvaluacion ->sig = tempEvaluacion;
        grupo->tempG = nuevaEvaluacion;
        return true;
            }

    Evaluacion*tempEvaluacionAnt = NULL;
    while(tempEvaluacion!=NULL){
            if(tempEvaluacion->year == nuevaEvaluacion->year){
                if(tempEvaluacion->mes == nuevaEvaluacion->mes){
                    if (tempEvaluacion->dia> nuevaEvaluacion->dia)
                        break;
                }
            }
            if(tempEvaluacion->year == nuevaEvaluacion->year){
                if(tempEvaluacion->mes > nuevaEvaluacion->mes){
                    break;
                }
            }
                tempEvaluacionAnt = tempEvaluacion;
                tempEvaluacion = tempEvaluacion->sig;
}

    if (tempEvaluacion==NULL){

        tempEvaluacionAnt->sig = nuevaEvaluacion;
        return true;

    }else{
        nuevaEvaluacion->sig = tempEvaluacion;
        tempEvaluacionAnt->sig = nuevaEvaluacion;
        return true;
    }

return true;

}

//Punto "j"
bool asignarAsignaciones(string tipo, int id, string nom, int dia, int mes, int year, int codCurso, int numGrupo, int cedula)
{
    Profesor*tempProfesor = buscarProfesor2(cedula);
    if (tempProfesor == NULL){
        return false;
    }
    conexionGrupo*tempConexion = tempProfesor->suGrupo;
    if (tempConexion == NULL){
        return false;
    }
    while (tempConexion != NULL){

        if (tempConexion->enlaceG->numGrupo == numGrupo ){

            if (tempConexion->enlaceG->enlaceCurso->codigo == codCurso){

                    Grupo*tempGrupo = tempConexion->enlaceG;

                    Evaluacion*nuevaEvaluacion = new Evaluacion(nom,dia,mes,year,id);
                    if (tipo == "Proyecto"){

                            insertarProyecto(nuevaEvaluacion,tempGrupo);
                            return true;

                    }else if(tipo == "Tarea"){


                            insertarTarea(nuevaEvaluacion,tempGrupo);
                            return true;

                    }else if(tipo == "Examen"){


                            insertarExamen(nuevaEvaluacion,tempGrupo);
                            return true;

                    }else if(tipo == "Giras"){


                            insertarGiras(nuevaEvaluacion,tempGrupo);
                            return true;

                    }
                    else{
                        cout<<"El tipo de asignacion no existe";
                        return false;

                    }
            }else{
            return false;
            }
        }else{
            tempConexion = tempConexion->sig;
        }
    }return false;

}

//Punto "k"
bool insertarCharlas(int id, string nomCharla, int numSem, int anSemestre, int day, int month){//Relaciona los semestres con las charlas
   Charla*newCharla = new Charla(nomCharla,id,day,month,anSemestre);

   Semestre*tempS = primerSemestre;

   if(tempS->anno == anSemestre && tempS->numSemestre == numSem){
    if(tempS->sublistaCharla == NULL){
    tempS->sublistaCharla = newCharla;
    return true;
   }

   Charla*tempChar = tempS->sublistaCharla;
   if(tempChar->mes > newCharla->mes){
    newCharla->sig = tempChar;
    tempS->sublistaCharla = newCharla;
    return true;
   }

   if(tempChar->mes == newCharla->mes && tempChar->dia > newCharla->dia){
    newCharla->sig = tempChar;
    tempS->sublistaCharla = newCharla;
    return true;
   }

   Charla*tempCharlaAnt = NULL;
   while(tempChar != NULL){
        if(tempChar->mes == newCharla->mes){
            if(tempChar->dia > newCharla->dia)
                break;
        }
        tempCharlaAnt = tempChar;
        tempChar = tempChar->sig;
   }
   if(tempChar == NULL){
    tempCharlaAnt->sig = newCharla;
    return true;

   }else{

    newCharla->sig = tempChar;
    tempCharlaAnt->sig = newCharla;
    return true;

   }

return true;
   }

return true;
}

bool modificarCharla(int id, int anSemestre, int numSem){//MOdifica el nombre de la charla

    //cout<<"Que se desea modificar: "
    Semestre*tempS = buscarSemestre(anSemestre,numSem);
    Charla*tempC = tempS->sublistaCharla;
    while(tempC->sig != NULL){
        if(tempC->numCharla == id){
            cout<<"Ingrese el nuevo nombre de la charla: ";
            string nombre;
            cin>>nombre;
            tempC->tipoCharla = nombre;
        }
        tempC = tempC->sig;
    }


}

//Menus
void menuAdmin(){
    bool repetir = true;
    do{
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
        cout<<" 9 - Reporte 7\n";
        cout<<" 10- Reporte 8  \n";
        cout<<" 0 - Volver a menu principal\n\n";
        cout<<" Opcion: ";
        cin>>choiceAdmin;

        switch(choiceAdmin){

    case 1:
        int choiceProf;
        while (choiceProf != 5){
            cout<<"\n ----------- Acciones profesor -----------\n\n";
            cout<<" 1 - Ingresar un profesor\n";
            cout<<" 2 - Modificar un profesor\n";
            cout<<" 3 - Borrar un profesor\n";
            cout<<" 4 - Imprimir datos de los profesores ingresados\n";
            cout<<" 5 - Volver a menu administrador\n\n";
            cout<<" Opcion: ";
            cin>>choiceProf;

            if(choiceProf == 1){


                cout<<"\n";
                cout<<"Ingrese los datos que se le solicitan del profesor a ingresar\n\n";
                cout<<"Nombre: ";
                string nom;
                cin>>nom;

                cout<<" Cedula: ";
                int ced;
                cin>>ced;

                cout<<"Edad: ";
                int age;
                cin>>age;

                if(buscarProfesor(ced) == true){
                    primerProfesor = insertarInicio(nom,ced,age);
                    cout<<"Profesor agregado correctamente...\n";
                }else{cout<<"Ya se encuentra registrado ese numero de cedula...\n\t¡Vuelvalo a intentar!\n";}
            }
            else if(choiceProf == 2){
                cout<<"\n";
                cout<<"Ingrese los datos que se le solicitan del profesor a modificar\n";
                cout<<"**    Solo se modificara el nombre del profesor    **\n\n";
                cout<<"Cedula: ";
                int ced;
                cin>>ced;

                cout<<"Nuevo nombre: ";
                string nom;
                cin>>nom;
                if(modificarProfesor(ced,nom) == true){
                    cout<<"\tProfesor modificado correctamente...\n";
                }else{cout<<"\tEl profesor que se desea moficicar, no se encuentra...\n";}
            }

            else if(choiceProf == 3){

                cout<<"\n";
                cout<<"Ingrese los datos que se le solicitan del profesor a borrar\n\n";
                cout<<" Cedula: ";
                int ced;
                cin>>ced;
                if(eliminarProfe(ced)  == true){
                    cout<<"\tProfesor borrado exitosamente...\n";
                }else{cout<<"Profesor no encontrado...\n";}
            }
            else if(choiceProf == 4){
                imprimirProfesor();
            }

            else if(choiceProf == 5){
                menuAdmin();
            }else{
            cout<<"\n+++++++++++++++++++++++++++++++++++++++++++";
            cout<<"\n+   Por favor ingrese una opcion valida   +";
            cout<<"\n+++++++++++++++++++++++++++++++++++++++++++\n\n";
            }

        }
        break;

    case 2:
        int choiceEst;
        while (choiceEst != 5){
            cout<<"\n ----------- Acciones estudiantes -----------\n\n";
            cout<<" 1 - Ingresar estudiantes\n";
            cout<<" 2 - Modificar\n";
            cout<<" 3 - Borrar un estudiante\n";
            cout<<" 4 - Imprimir datos de los estudiantes ingresados\n";
            cout<<" 5 - Volver a menu administrador\n\n";
            cout<<" Opcion: ";
            cin>>choiceEst;
            if(choiceEst == 1){
                cout<<"\n";
                cout<<"Ingrese los datos que se le solicitan \n\n";
                string nombre;
                cout<<" Nombre: ";
                cin>>nombre;

                int id;
                cout<<" Carne: ";
                cin>> id;

                string carrera;
                cout<<" Carrera: ";
                cin>>carrera;

                if(buscarEstudiante(id) == true){
                    primerEstudiante = InsertaEst(nombre,id,carrera);
                    cout<<"\n\tEstudiante insertado exitosamente...\n";
                }else{
                    cout<<"\n\tDicho carne ya esta ocupado...\n";
                }
            }
            else if(choiceEst == 2){
                cout<<"Ingrese los datos que se le solicitan \n";
                cout<<"** Solo se puede cambiar de carrera **\n\n";
                int id;
                cout<<"Carnet del estudiante: ";
                cin>>id;

                string nuevoNombre;
                cout<<"Nueva carrera: ";
                cin>>nuevoNombre;
                cout<<"\n";
                if(modificarEstudiante(id,nuevoNombre) == false){
                    cout<<"\tEl estudiante a modificar no se encuentra...\n";
                }
            }
            else if(choiceEst == 3){
                int idBorrar;
                cout<<"\tIngrese el numero de carnet del estudiante que se desea borrar: ";
                cin>>idBorrar;
                cout<<"\n";
                borrarEst(idBorrar);
            }
            else if(choiceEst == 4){
                imprimirEstudiante();
            }
            else if(choiceEst == 5){
                menuAdmin();
            }
            else{
                cout<<"\n+++++++++++++++++++++++++++++++++++++++++++";
                cout<<"\n+   Por favor ingrese una opcion valida   +";
                cout<<"\n+++++++++++++++++++++++++++++++++++++++++++\n";
            }
        }
        menuAdmin();
        break;

    case 3:
        int choiceSem;
        while(choiceSem != 5){
            cout<<"\n ----------- Acciones semestres -----------\n\n";
            cout<<" 1 - Ingresar un semestre\n";
            cout<<" 2 - Modificar un semestre\n";
            cout<<" 3 - Borrar un semestres\n";
            cout<<" 4 - Imprimir datos de los semestres\n";
            cout<<" 5 - Volver a menu administrador\n\n";
            cout<<" Opcion: ";
            cin>>choiceSem;
            if(choiceSem == 1){

            }
            else if(choiceSem == 2){

            }
            else if(choiceSem == 3){

            }
            else if(choiceSem == 4){

            }
            else if(choiceSem == 5){
                menuAdmin();
            }else{
            cout<<"\n+++++++++++++++++++++++++++++++++++++++++++";
            cout<<"\n+   Por favor ingrese una opcion valida   +";
            cout<<"\n+++++++++++++++++++++++++++++++++++++++++++\n\n";
            }
        }
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
        break;

    case 10:
        break;

    case 0:
        repetir = false;
        break;
        }
    }while(repetir);

}

void menuProfe(){
    bool acceso = true;
    do{
        cout<<"----------- Menu de profesores -----------\n\n";
        cout<<" 1 - Insertar, modoficar o borrar actividades relacionadas con los cursos\n";
        cout<<" 2 - Insertar charla, modoficar o borrar\n";
        cout<<" 3 - Reportes\n";
        cout<<" 4 - Salir\n\n";
        cout<<" Opcion: ";

        int choiceProf;
        cin>>choiceProf;

        switch(choiceProf){
    case 1:
        int actCurco;
        while(actCurco != 4){
            cout<<"----------- Actividades relacionadas con los cursos -----------\n\n";
            cout<<" 1 - Insertar una evaluacion\n";
            cout<<" 2 - Modificar evaluacion\n";
            cout<<" 3 - Borrar evaluacion\n";
            cout<<" 4 - Volver  menu profesor\n\n";
            cout<<"Opcion: ";
            cin>>actCurco;

            if(actCurco == 1){
                cout<<"Ingrese los datos que se le solicitan\n\n";
                cout<<"Que tipo de evaluacion desea ingresar...\n";
                cout<<" Se pueden ingresar: Proyecto, Tarea, Examen, Gira\n";
                cout<<"Se tiene que escribir con la primera letra en Mayuscula...\n\n";
                cout<<"Tipo: ";
                string type;
                cin>>type;

                cout<<"ID de la evaluacion: ";
                int ID;
                cin>>ID;

                cout<<"Nombre de la evaluacion: ";
                string nomEv;
                cin>>nomEv;

                cout<<"Dia: ";
                int day;
                cin>>day;

                cout<<"Mes: ";
                int month;
                cin>>month;

                cout<<"Anno: ";
                int year;
                cin>>year;

                cout<<"ID del curso a ingresar la evaluacion: ";
                int idCurso;
                cin>>idCurso;

                cout<<"Numero del grupo a ingresar: ";
                int numG;
                cin>>numG;

                cout<<"Numero de cedula del profesor encargado del grupo: ";
                int cedP;
                cin>>cedP;

                if(asignarAsignaciones(type,ID,nomEv,day,month,year,idCurso,numG,cedP)== true){
                    cout<<"\tEvaluacion registrada...\n\n";
                }else{cout<<"\tEvaluacion NO registrada...\n\n";}
            }
        else if(actCurco == 2){

        }
        else if(actCurco == 3){

        }
        else if(actCurco == 4){
            menuProfe();
        }else{cout<<"Opcion no valida...\n";}}
        break;

    case 2:

        int choiceCharla;
        while(choiceCharla != 4){
            cout<<"----------- Menu de Charlas -----------\n\n";
            cout<<" 1 - Insertar charla\n";
            cout<<" 2 - Modificar nombre de una charla\n";
            cout<<" 3 - Eliminar una charla\n";
            cout<<" 4 - Volver a menu profesor\n\n";
            cout<<" Opcion: ";
            cin>>choiceCharla;

            if(choiceCharla == 1){
                cout<<"\n";
                cout<<"Ingrese los datos que se le solicitan para verificar la existencia del semestre\n\n";

                cout<<"Anno: ";
                int anno;
                cin>>anno;

                cout<<"Numero de semestre: ";
                int numSem;
                cin>>numSem;

                if(buscarSemestreBool(anno,numSem) == true){
                    cout<<"Ingrese los datos que se le solicitan de la charla a ingresar\n\n";
                    cout<<"ID de la charla: ";
                    int numC;
                    cin>>numC;

                    cout<<"Nombre de la charla: ";
                    string nombreC;
                    cin>>nombreC;

                    cout<<"Día: ";
                    int day;
                    cin>>day;

                    cout<<"Mes: ";
                    int month;
                    cin>>month;

                    insertarCharlas(numC,nombreC,numSem,anno,day,month);
                }else{
                    cout<<"\nNo se pudo crear la charla debido a que no\n";
                    cout<<"existe ese semestre o el anno del semestre\n";
                }
            }else if(choiceCharla == 2){

            }else if(choiceCharla == 3){

            }else if(choiceCharla == 4){
                break;
            }
        }
        break;

    case 3:
        int choiceReporte;//cambiar por un do while
        while(choiceReporte!=1){
            cout<<"----------- Menu de reportes -----------\n\n";
            cout<<" 1 - Reporte 1 \n";
            cout<<" 2 - Reporte 2 \n";
            cout<<" 3 - Reporte 3 \n";
            cout<<" 4 - Reporte 4 \n";
            cout<<" 5 - Reporte 5 \n\n";
            cout<<" 6 - Volver a menú profesor\n\n";
            cout<<"\tOpcion: ";
            cin>>choiceReporte;
        }

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
        cout<<" 3 - Reporte 6\n";
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

void imprimirEvaluacion(){
    Curso*tempC = buscarCurso(1520);
    Grupo*tempG = buscarGrupo(53,tempC);
    Evaluacion*tempE = tempG->tempP;
    while(tempE != NULL){
        cout<<tempE->nombre<<endl;
        tempE = tempE->sig;
    }
}

void imprimirCharlas(){

    Semestre*tempS = buscarSemestre(2019,2);
    Charla*tempC = tempS->sublistaCharla;
    while(tempC->sig != NULL){
        cout<<tempC->tipoCharla<<endl;
        tempC = tempC->sig;
    }
    cout<<tempC->tipoCharla<<endl;

}

void baseDeDatos(){

    //Semestres insertados
    primerSemestre      = insertarSemestreOrdenado(2019,2);
    primerSemestre      = insertarSemestreOrdenado(2020,2);
    primerSemestre      = insertarSemestreOrdenado(2020,1);
    primerSemestre      = insertarSemestreOrdenado(2021,1);
    primerSemestre      = insertarSemestreOrdenado(2021,2);

    //Administradores insertados
    primerAdministrador = insertarAdmin("Admin1");
    primerAdministrador = insertarAdmin("Admin2");
    primerAdministrador = insertarAdmin("Admin3");
    primerAdministrador = insertarAdmin("Admin4");
    primerAdministrador = insertarAdmin("Admin5");

    //insertar profesores
    primerProfesor     =  insertarInicio("Hilary",1001,45);
    primerProfesor     =  insertarInicio("David"   , 702900638, 37);
    primerProfesor     =  insertarInicio("Sofia"   , 645900638, 25);
    primerProfesor     =  insertarInicio("Juan"    , 204500638, 27);
    primerProfesor     =  insertarInicio("Fabiola" , 514000638, 32);
    primerProfesor     =  insertarInicio("Frank"   , 852040638, 45);

    //insertar estudiantes
    primerEstudiante   =  InsertaEst("Maria" ,2020053336 ,"Ing. computacion");
    primerEstudiante   =  InsertaEst("Jimmy" ,2021053336 ,"Ing. industrial");
    primerEstudiante   =  InsertaEst("Felipe",2020053874 ,"Ing. computacion");
    primerEstudiante   =  InsertaEst("Amanda",2019053336 ,"Ing. mecanica");
    primerEstudiante   =  InsertaEst("Andres",2020054897 ,"Ing. mecanica");

    //insertar cursos
    primerCurso        =  insertarCurso(5,"Mate Discreta", 1520);
    primerCurso        =  insertarCurso(2,"Programacion basica", 1535);
    primerCurso        =  insertarCurso(5,"Dibujo tecnico", 1545);
    primerCurso        =  insertarCurso(5,"Comunicacion escrita", 1512);
    primerCurso        =  insertarCurso(5,"Deporte", 1510);

    //insertar Grupos
    insertarGrupo(53,1520);
    insertarGrupo(51,1520);
    insertarGrupo(52,1520);
    insertarGrupo(40,1512);
    insertarGrupo(35,1510);
    insertarGrupo(02,1545);
    insertarGrupo(15,1535);

    //insertar profesor con grupos
    relacionarProfesoresGrupo(1001,1520,53);
    //imprimirInformeMatricula(1001);

    //Relaciona los semestres con los cursos
    relacionarSemestresCursos(2020,1,1520);
    relacionarSemestresCursos(2020,1,1535);
    relacionarSemestresCursos(2020,1,1545);

    //imprimirInformeMatricula(2020,1);

    //Asignacion de evaluaciones
    //asignarAsignaciones("Proyecto",53,"Proyecto de estructura I",12,9,2020,1520,53,1001);
    asignarAsignaciones("Proyecto",109,"Proyecto de estructura segundo",10,05,2020,1520,53,1001);
    asignarAsignaciones("Proyecto",503,"Proyecto de estructura primero",7,05,2020,1520,53,1001);
    asignarAsignaciones("Proyecto",123,"Proyecto de estructura ultimo",01,06,2020,1520,53,1001);
    asignarAsignaciones("Proyecto",124,"Proyecto de estructura penultimo",30,05,2020,1520,53,1001);
    asignarAsignaciones("Proyecto",123,"Proyecto de estructura IcccII",8,04,2020,1520,53,1001);
  //  asignarAsignaciones("Proyecto",123,"Proyecto de estructura jjjj",7,04,2020,1520,53,1001);
  //  asignarAsignaciones("Proyecto",123,"Proyecto de estructura bbbbb",8,04,2020,1520,53,1001);
   // imprimirEvaluaciones(53,1520);
    //imprimirEvaluacion();

    //insertar charlas
    insertarCharlas(1,"Ultimo",2,2019,1,05);
    insertarCharlas(2,"Primero",2,2019,10,04);
    insertarCharlas(3,"Medio",2,2019,11,04);
    insertarCharlas(4,"Nuevo primero",2,2019,2,04);
    //imprimirCharlas();

}

int main()
{
    baseDeDatos();

    //relacionarEstudiantesGrupo(2020053336,1520,53);
    //imprimirInformeMatricula(2020053336);

    bool repetir = true;

    do{
        int choice;
        cout<<"\n----------- Menu principal -----------\n\n";
        cout<<" 1 - Seccion administrador\n";
        cout<<" 2 - Seccion de usuarios (Profesores y estudiantes)\n";
        cout<<" 3 - Salir\n\n";
        cout<<" Opcion: ";
        cin>>choice;

        switch(choice){

    case 1:
        if(buscarAdmin()==true){
            menuAdmin();
        }else{
            cout<<"\n+++++++++++++++++++++++++++++++++++++++++++";
            cout<<"\n+          Usuario no registrado          +";
            cout<<"\n+++++++++++++++++++++++++++++++++++++++++++\n\n";
        }
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

//Metodos de impresion
void imprimirEstudiante(){

    cout<<"\n ------------- Imprimiendo estudiantes ------------- \n\n";
    if(primerEstudiante == NULL){
        cout<<"\n+++++++++++++++++++++++++++++++++++++++++++";
        cout<<"\n+ Aun no se han ingresado los estudiantes +";
        cout<<"\n+++++++++++++++++++++++++++++++++++++++++++\n";
    }else{
        Estudiante* temp = primerEstudiante;
        while(temp != NULL){
            cout<<"\n------ Datos ------\n"<<"\nNombre: "<<temp->nombre<<"\nCarne: "<<temp->carnet<<"\nCarrera: "<<temp->carrera;
            temp = temp->sig;
            cout<<"\n-------------------------------------------\n";
        }
        system("pause>nul");
    };
}

void imprimirProfesor(){

    if(primerProfesor == NULL)
        cout<<"\nNo hay lista ";
    else{
        Profesor * temp = primerProfesor;
        while(temp->sig != NULL){
            cout<<"---- Datos ----\n";
            cout<<"Nombre: "<<temp->nombre<<"\nCedula: "<<temp->cedula<<"\nEdad:   "<<temp->edad<<"\n";
            temp = temp->sig;
        }
        cout<<"Nombre: "<<temp->nombre<<"\nCedula: "<<temp->cedula<<"\nEdad:   "<<temp->edad<<"\n";//Imprime el ultimo
        }

}

/*void imprimirCharlas(){
    if(primerSemestre == NULL)
        cout<<"Lista vacia";
    else{
        Semestre*temp = primerSemestre;
        while(temp->enlaceCharla->sig != NULL){
            cout<<"\n\nCharlas...\nTipo de charla: "<<temp->enlaceCharla->tipoCharla;
            cout<<"\nID de la charla: "<<temp->enlaceCharla->numCharla;
            temp = temp->sig;
        }
    cout<<"\n\nCharlas...\nTipo de charla: "<<temp->enlaceCharla->tipoCharla;
    cout<<"\nID de la charla: "<<temp->enlaceCharla->numCharla;
    }
}*/


//Metodos de buscar
bool buscarEstudiante(int num){

    Estudiante * i = primerEstudiante;
    while(i != NULL){
        if(i->carnet == num){
            return false;
        }
        i = i ->sig;
    }
    return true;
};

bool buscarProfesor(int ced){

    Profesor*i = primerProfesor;
    while(i != NULL){
        if(i->cedula == ced){
            return false;
        }
        i = i->sig;
    }
    return true;
}
Profesor* buscarProfesor2(int ced){
    Profesor*i = primerProfesor;
    while(i != NULL){
        if(i->cedula == ced)
            return i;
        i = i->sig;
    }
    return NULL;
}

//funcion para buscar curso
Curso* buscarCurso(int codigo){

    if(primerCurso == NULL)
        return NULL;
    struct Curso*temp = primerCurso;
    do{
        if(codigo == temp->codigo)
            return temp;
        temp= temp->sig;
    }while(temp != primerCurso);
    return NULL;

}
Grupo*buscarGrupo(int codigo, Curso*puntero){

    if(puntero->sublistaGrupos == NULL)
        return NULL;
    Grupo*tempG = puntero->sublistaGrupos;
    while (tempG!= NULL){
        if(tempG->numGrupo == codigo)
            return tempG;
        tempG = tempG->sig;
    }
    return NULL;
}
Estudiante*buscarEstudianteReturn(int num){

    Estudiante * i = primerEstudiante;
    while(i != NULL){
        if(i->carnet == num){
            return i;
        }
        i = i ->sig;
    }
    return NULL;


}

Semestre*buscarSemestre(int year, int numS){
    Semestre*tempS = primerSemestre;

    while(tempS != NULL){
        if(tempS->anno == year && tempS->numSemestre == numS)
            return tempS;
        tempS = tempS->sig;
    }
    return NULL;
}

bool buscarSemestreBool(int year, int numS){
    Semestre*tempS = primerSemestre;

    while(tempS != NULL){
        if(tempS->anno == year && tempS->numSemestre == numS)
            return true;
        tempS = tempS->sig;
    }
    return false;
}
