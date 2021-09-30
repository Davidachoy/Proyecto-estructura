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
    string tipo;
    Semestre*sig,*ant;
    //structs
    struct Charla*sublistaCharla; // conecta con la estructura de charla
    struct ConexionCurso*enlaceConexionCurso;//conecta con un auxiliar

    Semestre(int unAnno, int unNumSemestre, string tipoSemestre){
    tipo = tipoSemestre;
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

    Evaluacion(string name, int day, int month, int a, int idAct){
    nombre      = name;
    dia         = day;
    mes         = month;
    year        = a;
    id          = idAct;

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
    int cantidadEstudiantes;
    Charla*sig;

    Charla(string type, int idC,int day,int month,int year){
        tipoCharla = type;
        numCharla  = idC;
        dia = day;
        mes = month;
        anno = year;
        cantidadEstudiantes = 0;

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
void imprimirEvaluacion(int codCurso, int numGrupo);
void imprimirEvaluacion3(int codCurso,int numGrupo);

//Metodos de buscar
bool buscarEstudiante(int num);
bool buscarProfesor(int ced);
bool buscarSemestreBool(int year, int numS);
Curso* buscarCurso(int codigo);
Grupo*buscarGrupo(int codigo, Curso*puntero);
Estudiante*buscarEstudianteReturn(int carnet);
Profesor*buscarProfesor2(int ced);
Semestre*buscarSemestre(int year, int numS);
Charla*buscarCharla(int year, int numS, int numCharla);

//punto **D** inserta y modificar semestres     falta modificar
//E: anno y numsemestre
//S: semestre creado de forma ordenada en lista doble
Semestre* insertarSemestreOrdenado(int anno,int numSemestre,string tipo){

        Semestre *newSemestre = new Semestre(anno,numSemestre,tipo);

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

bool borrarCurso(int codigo){


  Curso*tempC = primerCurso;
    if (tempC == NULL)
        return false;
    Curso*tempC2 = buscarCurso(codigo);
    if (tempC2 == NULL)
        return false;



    if (tempC->codigo==codigo && tempC->sig == tempC){

    primerCurso = NULL;

    return true;
    }



    if (primerCurso->codigo==codigo){
        Curso*cursoBorrar = primerCurso;
        primerCurso = primerCurso->sig;
        while(tempC->sig != cursoBorrar){

            tempC= tempC->sig;

        }
        tempC->sig = primerCurso;
        return true;
    }else{

        Curso*tempCursoAnt = NULL;


        while (tempC ->codigo !=codigo ){

            tempCursoAnt = tempC;
            tempC = tempC->sig;


        }

        tempCursoAnt->sig = tempC->sig;
        return true;
    }
}

bool modificarCurso(string tipo,string nombre,int creditos,int codigo){ //si no se modifica se pone x valor solo para llenar campo

    Curso*tempC = buscarCurso(codigo);
    if(tempC == NULL)
        return false;
    if (tipo == "Nombre"){
        tempC->nomCurso = nombre;
        return true;
    }else if(tipo == "Creditos"){
        tempC->creditos = creditos;
        return true;
    }
    else{
        tempC->nomCurso = nombre;
        tempC->creditos = creditos;
        return true;
    }
}

void imprimirCursos(){
    Curso*tempC = primerCurso;
    do{
        cout<<tempC->nomCurso<<endl;
        tempC = tempC->sig;

    }while(tempC != primerCurso);



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

bool eleminarProfesoresGrupo(int ced, int codigoCurso, int numGrupo){

    Profesor*tempP= buscarProfesor2(ced);
    if(tempP == NULL)
        return false;

    Curso*tempC = buscarCurso(codigoCurso);
    if(tempC == NULL)
        return false;

    if(tempP->suGrupo->enlaceG->numGrupo == numGrupo){
    tempP->suGrupo = tempP->suGrupo->sig;
    cout<<"\n\tSe dejo de relacion dicho profesor con el grupo "<<numGrupo<<"\n";
    return true;

    }else{
        conexionGrupo*tempCg = tempP->suGrupo;
        conexionGrupo*tempCgAnt = NULL;
        while(tempCg != NULL){
            if(tempCg->enlaceG->numGrupo == numGrupo){
                tempCgAnt->sig = tempCg->sig;
                cout<<"\n\tSe dejo de relacion dicho profesor con el grupo "<<numGrupo<<"\n";

                return true;
            }
            tempCgAnt = tempCg;
            tempCg = tempCg->sig;
        }
    }
    cout<<"\n\tNO se dejo de relacion dicho profesor con el grupo "<<numGrupo<<"\n";
    return false;
}

void imprimirProfesorGrupos(int ced, int codigoCurso){

    Profesor*tempP = buscarProfesor2(ced);
    if(tempP == NULL){
        cout<<"Profesor no encontrado...\n";
        return;
    }
    Curso*i = buscarCurso(codigoCurso);
    if(i == NULL){
        cout<<"Curso no encontrado...\n";
        return;
    }

    cout<<"\n ------ Informe profesor -----\n";
    cout<<"Nombre: "<<tempP->nombre<<"\nCedula: "<<tempP->cedula<<"\nEdad: "<<tempP->edad;
    conexionGrupo*tempG = tempP->suGrupo;
    cout<<"\nGrupos que imparte el curso de "<<i->nomCurso<<": ";
    while(tempG != NULL){
        cout<<"\n\t"<<tempG->enlaceG->numGrupo;
        tempG = tempG->sig;
    }
    cout<<"\n-----------------------------------\n";
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

bool borrarRelacionEstudiantesGrupo(int carnet, int numGrupo){

    Estudiante*tempE = buscarEstudianteReturn(carnet);
    if (tempE == NULL)
        return false;
    ReporteEstudiante*tempReporte = tempE->enlaceReporte;
    if (tempReporte == NULL)
        return false;
    if (tempReporte->enlaceGrupo->numGrupo == numGrupo ){
        tempE->enlaceReporte = tempReporte->sig;
        return true;

    }else{
        ReporteEstudiante*tempReporteAnt =NULL;
        while (tempReporte != NULL){

            if (tempReporte->enlaceGrupo->numGrupo == numGrupo){
                tempReporteAnt->sig == tempReporte->sig;
                return true;
            }
            tempReporteAnt = tempReporte;
            tempReporte= tempReporte->sig;
        }


        return false;

    }

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

//Punto "J"
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

bool asignarAsignaciones(string tipo, int idAct, string nom, int dia, int mes, int year, int codCurso, int numGrupo, int cedula){
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
                    Evaluacion*nuevaEvaluacion = new Evaluacion(nom,dia,mes,year,idAct);
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
   Charla*tempChar = tempS->sublistaCharla;

   if(tempS->sublistaCharla == NULL){
        tempS->sublistaCharla = newCharla;
        return true;
   }

   if(tempChar->mes == newCharla->mes && tempChar->dia > newCharla->dia){
    newCharla->sig = tempChar;
    tempS->sublistaCharla = newCharla;
    return true;
   }

    if(tempChar->mes > newCharla->mes){
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
        if(tempChar->anno == newCharla->anno){
            if(tempChar->mes > newCharla->mes){
                break;
            }
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
return false;
}

bool modificarCharla(int IDcharla, int anSemestre, int numSemn, string nuevoName){//Modifica el nombre de la charla //No funciona del todo

    Charla*tempC = buscarCharla(anSemestre,numSemn,IDcharla);
    if(tempC == NULL)
        return false;

    else{
    while(tempC != NULL){
        if(tempC->numCharla == IDcharla){
            tempC->tipoCharla = nuevoName;
            return true;
            }
        tempC = tempC->sig;
        }
    }
    return false;
}

bool borrarCharla(int numC, int anSemestre, int numSem){//No funciona del todo
    cout<<"Llego hasta aquí...1\n";
    Semestre*tempS = buscarSemestre(anSemestre,numSem);
    cout<<"Llego hasta aquí...2\n";
    if(tempS == NULL){
        cout<<"Llego hasta aquí...3\n";
        return false;
    }
    cout<<"Llego hasta aquí...4\n";
    Charla*tempC = tempS->sublistaCharla;
    cout<<"Llego hasta aquí...5\n";
    if(tempC == NULL){
        cout<<"Llego hasta aquí...6\n";
        return false;

    }
    cout<<"Llego hasta aquí...\n";

    if(tempS->sublistaCharla->numCharla == numC){
        tempS->sublistaCharla = tempS->sublistaCharla->sig;
        cout<<"\n\tSe dejo de relacionar dicho semestre con la charla "<<numC<<"\n";
        return true;
    }else{
        Charla* tempCharla = tempS->sublistaCharla;
        Charla* tempCharlaAnt = NULL;
        while(tempCharla != NULL){
            if(tempCharla->numCharla == numC){
                tempCharlaAnt->sig = tempCharla->sig;
                cout<<"\n\tSe dejo de relacionar dicho semestre con la charla "<<numC<<"\n";
                return true;
            }
            tempCharlaAnt = tempCharla;
            tempCharla = tempCharla->sig;
        }
    }
    cout<<"NO se pudo borrar dicha Charla...\n";
    return false;
}

//punto **L**
bool buscarCalificacion(ReporteEstudiante*lista , int idActividad){
    Calificaciones*tempC = lista->enlaceEvaluaciones;

    while (tempC!=NULL){
        if (tempC->enlaceEvaluaciones->id == idActividad)
            return true;
        tempC= tempC->sig;


    }
    return false;

}

Evaluacion*buscarEvaluacion(int codigoCurso, int idGrupo, string tipo,int idActividad)
{
    Curso*tempC = buscarCurso(codigoCurso);
    if (tempC == NULL)
        return NULL;
    Grupo*tempG = buscarGrupo(idGrupo,tempC);
    if (tempG == NULL)
        return NULL;

    if (tipo == "Proyecto")
    {
        Evaluacion*tempE = tempG->tempP;
        if (tempE == NULL)
            return NULL;
        while (tempE != NULL)
        {
            if (tempE->id == idActividad)
            {

                return tempE;
            }


            tempE= tempE->sig;


        }

        return NULL;


    }
    else if(tipo=="Tarea")
    {
        Evaluacion*tempE = tempG->tempTC;
        if (tempE == NULL)
            return NULL;
        while (tempE != NULL)
        {
            if (tempE->id == idActividad)
                return tempE;

            tempE= tempE->sig;


        }

        return NULL;


    }
    else if(tipo == "Examen")
    {
        Evaluacion*tempE = tempG->tempExa;
        if (tempE == NULL)
            return NULL;
        while (tempE != NULL)
        {
            if (tempE->id == idActividad)
                return tempE;

            tempE= tempE->sig;


        }

        return NULL;


    }
    else if(tipo == "Giras")
    {
        Evaluacion*tempE = tempG->tempG;
        if (tempE == NULL)
            return NULL;
        while (tempE != NULL)
        {
            if (tempE->id == idActividad)
                return tempE;

            tempE= tempE->sig;


        }

        return NULL;


    }
    else
    {
        return NULL;
    }

    cout<<"llego hasta el punto 4 "<<endl;






}

bool registrarActividad(int carnet, int codigoCurso, int idGrupo,int idActividad, string tipo){
    Estudiante*tempE = buscarEstudianteReturn(carnet);
    if(tempE == NULL)
        return false;
    ReporteEstudiante*tempReporte = tempE->enlaceReporte;
    if (tempReporte == NULL)
        return false;

    while(tempReporte != NULL){
        if(tempReporte->enlaceGrupo->numGrupo == idGrupo){
            if(tempReporte->enlaceGrupo->enlaceCurso->codigo == codigoCurso){
                Grupo*tempGrupo = tempReporte->enlaceGrupo;
                break;

            }else{
            return false;
            }
        }else{
        return false;}

        tempReporte = tempReporte->sig;

    }
    Evaluacion*tempEvaluacion = buscarEvaluacion(codigoCurso,idGrupo , tipo ,idActividad);



    Calificaciones*nuevaCalificacion = new Calificaciones();
    if(tempReporte->enlaceEvaluaciones == NULL){

        tempReporte->enlaceEvaluaciones = nuevaCalificacion;
        nuevaCalificacion->enlaceEvaluaciones = tempEvaluacion;
        return true;

    }
    if(buscarCalificacion(tempReporte, idActividad) == true )
        return false;

    Calificaciones*tempCalificaciones =tempReporte->enlaceEvaluaciones;
    Calificaciones*tempCalificacionesAnterior = NULL;
    //cout<<"llega hasta aqui"<<endl;

    while (tempCalificaciones != NULL){
        tempCalificacionesAnterior = tempCalificaciones;
        tempCalificaciones = tempCalificaciones->sig;
    }

    tempCalificacionesAnterior->sig = nuevaCalificacion;

    nuevaCalificacion->enlaceEvaluaciones = tempEvaluacion;

    return true;
}

//punto "m"
bool registrarAsistenciaCharla(int cedEst, int idChar, int anno, int numS){

    Estudiante*tempE = buscarEstudianteReturn(cedEst);
    if(tempE == NULL)
        return false;

    Charla*tempC = buscarCharla(anno,numS,idChar);
    if(tempC == NULL)
        return false;

    ReporteCharla*newReporteAsistencia = new ReporteCharla();
    AsistenciaCharla*confirmarA = new AsistenciaCharla();

    newReporteAsistencia->sig = tempE->enlaceCharla;
    tempE->enlaceCharla = newReporteAsistencia;
    confirmarA->sig = newReporteAsistencia->enlaceAsistenciaCharla;
    newReporteAsistencia->enlaceAsistenciaCharla = confirmarA;
    newReporteAsistencia->enlaceAsistenciaCharla->enlaceCharla = buscarCharla(anno,numS,idChar);
    return true;
}

bool imprimirAsistenciaCharla(int cedEst, int year, int numSem, int numC){

    Estudiante*tempE = buscarEstudianteReturn(cedEst);
    if(tempE == NULL)
        return false;

    ReporteCharla*tempR = tempE->enlaceCharla;

    AsistenciaCharla*tempAsis = tempR->enlaceAsistenciaCharla;

    //Charla*tempC = tempAsis->enlaceCharla;

    //if(tempC == NULL)
      //  return false;

    cout<<"\n----------------------------------------\n";
    cout<<"Nombre: "<<tempE->nombre<<"\nCedula: "<<tempE->carnet<<"\nCarrera: "<<tempE->carrera<<"c\n";


    while(tempAsis != NULL){
        cout<<"\tTipo de charla: "<<tempAsis->enlaceCharla->tipoCharla<<endl;
        tempAsis = tempAsis->sig;
        //return true;
    }
    //cout<<"\t\nTipo de charla: "<<tempC->tipoCharla<<endl;
    return NULL;
}

///Reportes
string returnMes(int mes);
string returnDia(int anno,int mes, int day);

void reporte1(int cedPro,int anno, int numS){

    Profesor*tempP = buscarProfesor2(cedPro);
    if(tempP == NULL){
        cout<<"El profesor no se encuentra..\n\n";
        return;
    }
    Semestre*tempS = buscarSemestre(anno,numS);
    if(tempS == NULL){
        cout<<"El semestre no se encuentra..\n\n";
        return;
    }
    cout<<"--------------------------------------\n";
    cout<<"\nNombre del profesor: "<<tempP->nombre;
    cout<<"\nCedula: "<<tempP->cedula;
    cout<<"\nEdad: "<<tempP->edad;
    conexionGrupo*tempConex = tempP->suGrupo;

    Grupo*tempG = tempConex->enlaceG;

    Evaluacion*tempEva = tempG->tempP;

    Curso*tempC = tempG->enlaceCurso;
    cout<<"\n------------- Reporte ---------------\n";
    while(tempConex != NULL){
        cout<<"\nCurso: "<<tempConex->enlaceG->enlaceCurso->nomCurso<<"\tGrupo: "<<tempConex->enlaceG->numGrupo<<"\n\n";
        imprimirEvaluacion3(tempConex->enlaceG->enlaceCurso->codigo,tempConex->enlaceG->numGrupo);
        cout<<"\n--------------------------------------\n";
        tempConex = tempConex->sig;
    }

}

void reporte2(int cedPro, int anno, int numS){



    Profesor*tempP = buscarProfesor2(cedPro);
    if(tempP == NULL){
        cout<<"El profesor no se encuentra..\n\n";
        return;
    }
    Semestre*tempS = buscarSemestre(anno,numS);
    if(tempS == NULL){
        cout<<"El semestre no se encuentra..\n\n";
        return;
    }
    cout<<"--------------------------------------\n";
    cout<<"\nNombre del profesor: "<<tempP->nombre;
    cout<<"\nCedula: "<<tempP->cedula;
    cout<<"\nEdad: "<<tempP->edad;
    conexionGrupo*tempConex = tempP->suGrupo;

    Grupo*tempG = tempConex->enlaceG;

    Evaluacion*tempEva = tempG->tempP;

    Curso*tempC = tempG->enlaceCurso;
    cout<<"\n------------- Reporte ---------------\n";
    while(tempConex != NULL){
        cout<<"\nCurso: "<<tempConex->enlaceG->enlaceCurso->nomCurso<<"\tGrupo: "<<tempConex->enlaceG->numGrupo<<"\n\n";
        imprimirEvaluacion(tempConex->enlaceG->enlaceCurso->codigo,tempConex->enlaceG->numGrupo);
        cout<<"\n--------------------------------------\n";
        tempConex = tempConex->sig;
    }
}

void reporte3(int codCurso){

    Estudiante*tempE = primerEstudiante;
    if (tempE == NULL) {
        cout<<"No hay estudiantes"<<endl;
        return;
    }

    Curso*tempC = buscarCurso(codCurso);
    if(tempC == NULL){
        cout<<"Curso no encontrado"<<endl;
        return;
    }

    while( tempC->sublistaGrupos != NULL ){
        //cout<<tempC->sublistaGrupos->numGrupo<<endl;
        while(tempC->sublistaGrupos->tempTC != NULL){
            cout<<tempC->sublistaGrupos->tempTC->id<<endl;
            //llamarEst();
            while(tempE != NULL){
                //cout<<"Llego aquí...1\n";
                while(tempE->enlaceReporte != NULL){
                    //cout<<"Llego aquí...2\n";
                    ReporteEstudiante*tempRe = tempE->enlaceReporte;
                    while(tempRe != NULL){
                        //cout<<"Llego aquí...3\n";
                        while(tempRe->enlaceEvaluaciones != NULL){
                                cout<<"Nombre: "<<tempE->nombre<<endl;
                                cout<<"Tarea entregada: "<<tempE->enlaceReporte->enlaceEvaluaciones->enlaceEvaluaciones->id<<endl;
                                //cout<<"Llego aquí...4\n";
                                if( tempC->sublistaGrupos->tempTC->id == tempRe->enlaceEvaluaciones->enlaceEvaluaciones->id ){

                                    cout<<tempE->nombre<<" entrego la tarea "<<tempE->enlaceReporte->enlaceEvaluaciones->enlaceEvaluaciones->nombre<<endl;
                                    //break;
                                    //tempRe->enlaceEvaluaciones->enlaceEvaluaciones = tempRe->enlaceEvaluaciones->enlaceEvaluaciones->sig;
                                }else if(tempC->sublistaGrupos->tempTC->id != tempRe->enlaceEvaluaciones->enlaceEvaluaciones->id){
                                    //cout<<tempE->nombre<<" no entrego la tarea "<<tempC->sublistaGrupos->tempTC->nombre<<endl;
                                }
                            tempRe->enlaceEvaluaciones = tempRe->enlaceEvaluaciones->sig;
                        }
                        tempRe = tempRe->sig;
                    }
                    tempE->enlaceReporte = tempE->enlaceReporte->sig;
                }
                tempE = tempE->sig;
            }
            tempC->sublistaGrupos->tempTC = tempC->sublistaGrupos->tempTC->sig;
        }
        tempC->sublistaGrupos = tempC->sublistaGrupos->sig;
    }
}

//reporte 5
void imprimirReporte5Aux(Grupo*tempG) {
    Evaluacion*tempEvaluacionExamen = tempG->tempExa;
    Evaluacion*tempEvaluacionTarea = tempG->tempTC;
    Evaluacion*tempEvaluacionGiras = tempG->tempG;
    Evaluacion*tempEvaluacionProyecto = tempG->tempP;

    if (tempEvaluacionExamen != NULL) {
        while(tempEvaluacionExamen != NULL) {
            string dia = returnDia(tempEvaluacionExamen->year,tempEvaluacionExamen->mes,tempEvaluacionExamen->dia);
            string mes = returnMes(tempEvaluacionExamen->mes);
            cout<<"\t\t\t"<<tempEvaluacionExamen->nombre<<" del "<<dia<<" "<<tempEvaluacionExamen->dia <<" de "<< mes<<endl;
            tempEvaluacionExamen = tempEvaluacionExamen->sig;
        }
    }
    if (tempEvaluacionTarea != NULL) {
        while(tempEvaluacionTarea != NULL) {
            string dia = returnDia(tempEvaluacionTarea->year,tempEvaluacionTarea->mes,tempEvaluacionTarea->dia);
            string mes = returnMes(tempEvaluacionTarea->mes);
            cout<<"\t\t\t"<<tempEvaluacionTarea->nombre<<" del "<<dia<<" "<<tempEvaluacionTarea->dia <<" de "<< mes<<endl;
            tempEvaluacionTarea = tempEvaluacionTarea->sig;

        }}
        if (tempEvaluacionGiras != NULL) {
            while(tempEvaluacionGiras != NULL) {
            string dia = returnDia(tempEvaluacionGiras->year,tempEvaluacionGiras->mes,tempEvaluacionGiras->dia);
            string mes = returnMes(tempEvaluacionGiras->mes);
            cout<<"\t\t\t"<<tempEvaluacionGiras->nombre<<" del "<<dia<<" "<<tempEvaluacionGiras->dia <<" de "<< mes<<endl;
                tempEvaluacionGiras = tempEvaluacionGiras->sig;

            }}
            if (tempEvaluacionProyecto != NULL) {
                while(tempEvaluacionProyecto != NULL) {
            string dia = returnDia(tempEvaluacionProyecto->year,tempEvaluacionProyecto->mes,tempEvaluacionProyecto->dia);
            string mes = returnMes(tempEvaluacionProyecto->mes);
            cout<<"\t\t\t"<<tempEvaluacionProyecto->nombre<<" del "<<dia<<" "<<tempEvaluacionProyecto->dia <<" de "<< mes<<endl;
                    tempEvaluacionProyecto = tempEvaluacionProyecto->sig;

                }
            }
        }

void imprimirAsignacionExamen(Evaluacion*tempEvaluacionExamen,ReporteEstudiante*tempReporte){
    while(tempEvaluacionExamen != NULL){
        Calificaciones*tempCalificaciones = tempReporte->enlaceEvaluaciones;
        while(tempCalificaciones != NULL){
            if(tempEvaluacionExamen->id == tempCalificaciones->enlaceEvaluaciones->id){
                break;
                }
           tempCalificaciones = tempCalificaciones->sig;

        }
        if(tempCalificaciones == NULL){
            string dia = returnDia(tempEvaluacionExamen->year,tempEvaluacionExamen->mes,tempEvaluacionExamen->dia);
            string mes = returnMes(tempEvaluacionExamen->mes);
            cout<<"\t\t\t"<<tempEvaluacionExamen->nombre<<" del "<<dia<<" "<<tempEvaluacionExamen->dia <<" de "<< mes<<endl;
        }

    tempEvaluacionExamen = tempEvaluacionExamen->sig;
    }

}

void imprimirAsignacionTarea(Evaluacion*tempEvaluacionTarea,ReporteEstudiante*tempReporte){
    while(tempEvaluacionTarea != NULL){
        Calificaciones*tempCalificaciones = tempReporte->enlaceEvaluaciones;
        while(tempCalificaciones != NULL){
            if(tempEvaluacionTarea->id == tempCalificaciones->enlaceEvaluaciones->id){
                break;
                }
           tempCalificaciones = tempCalificaciones->sig;

        }
        if(tempCalificaciones == NULL){
            string dia = returnDia(tempEvaluacionTarea->year,tempEvaluacionTarea->mes,tempEvaluacionTarea->dia);
            string mes = returnMes(tempEvaluacionTarea->mes);
            cout<<"\t\t\t"<<tempEvaluacionTarea->nombre<<" del "<<dia<<" "<<tempEvaluacionTarea->dia <<" de "<< mes<<endl;
        }

    tempEvaluacionTarea = tempEvaluacionTarea->sig;
    }

}

void imprimirAsignacionGiras(Evaluacion*tempEvaluacionGiras,ReporteEstudiante*tempReporte){
    while(tempEvaluacionGiras != NULL){
        Calificaciones*tempCalificaciones = tempReporte->enlaceEvaluaciones;
        while(tempCalificaciones != NULL){
            if(tempEvaluacionGiras->id == tempCalificaciones->enlaceEvaluaciones->id){
                break;
                }
           tempCalificaciones = tempCalificaciones->sig;

        }
        if(tempCalificaciones == NULL){
            string dia = returnDia(tempEvaluacionGiras->year,tempEvaluacionGiras->mes,tempEvaluacionGiras->dia);
            string mes = returnMes(tempEvaluacionGiras->mes);
            cout<<"\t\t\t"<<tempEvaluacionGiras->nombre<<" del "<<dia<<" "<<tempEvaluacionGiras->dia <<" de "<< mes<<endl;
        }

    tempEvaluacionGiras = tempEvaluacionGiras->sig;
    }

}

void imprimirAsignacionProyecto(Evaluacion*tempEvaluacionProyecto,ReporteEstudiante*tempReporte){
    while(tempEvaluacionProyecto != NULL){
        Calificaciones*tempCalificaciones = tempReporte->enlaceEvaluaciones;
        while(tempCalificaciones != NULL){
            if(tempEvaluacionProyecto->id == tempCalificaciones->enlaceEvaluaciones->id){
                break;
                }
           tempCalificaciones = tempCalificaciones->sig;

        }
        if(tempCalificaciones == NULL){
            string dia = returnDia(tempEvaluacionProyecto->year,tempEvaluacionProyecto->mes,tempEvaluacionProyecto->dia);
            string mes = returnMes(tempEvaluacionProyecto->mes);
            cout<<"\t\t\t"<<tempEvaluacionProyecto->nombre<<" del "<<dia<<" "<<tempEvaluacionProyecto->dia <<" de "<< mes<<endl;
        }

    tempEvaluacionProyecto = tempEvaluacionProyecto->sig;
    }

}

bool imprimirReporte5(Estudiante*tempE,Grupo*tempG,int numCurso, int numGrupo) {
    if (tempE->enlaceReporte == NULL)
        return false;

    if (tempE->enlaceReporte->enlaceGrupo->numGrupo == numGrupo){
            if (tempE->enlaceReporte->enlaceGrupo->enlaceCurso->codigo == numCurso){
                cout<<"\t\t"<<tempE->nombre<<" no ha entregado o participado en:"<<endl;
                ReporteEstudiante*tempReporte = tempE->enlaceReporte;
                Evaluacion*tempEvaluacionExamen = tempG->tempExa;
                Evaluacion*tempEvaluacionTarea = tempG->tempTC;
                Evaluacion*tempEvaluacionGiras = tempG->tempG;
                Evaluacion*tempEvaluacionProyecto = tempG->tempP;
                if (tempReporte->enlaceEvaluaciones == NULL){
                    imprimirReporte5Aux(tempG);                           // imprime todas las asignaciones
                    return true;
                }
                if (tempEvaluacionExamen != NULL){
                    imprimirAsignacionExamen(tempEvaluacionExamen,tempReporte);
                }
                if (tempEvaluacionTarea != NULL){
                    imprimirAsignacionTarea(tempEvaluacionTarea,tempReporte);

                }
                if (tempEvaluacionGiras != NULL){
                    imprimirAsignacionGiras(tempEvaluacionGiras,tempReporte);

                }
                if (tempEvaluacionProyecto != NULL){
                    imprimirAsignacionProyecto(tempEvaluacionProyecto,tempReporte);

                }

                return true;


            }

    }

    return false;


}

void reporte5(int cedulaProf, int numCurso, int numGrupo) {
    Profesor*tempP = buscarProfesor2(cedulaProf);
    if (tempP == NULL) {
        cout<<"El profesor no existe"<<endl;
        return;
    }
    conexionGrupo*tempC= tempP->suGrupo;
    if(tempC == NULL) {
        cout<<"El profesor no tiene grupos asignados"<<endl;
        return;
    }
    while(tempC!=NULL) {
        if (tempC->enlaceG->numGrupo == numGrupo) {
            if (tempC->enlaceG->enlaceCurso->codigo == numCurso) {
                cout<<"Profes@r: "<<tempP->nombre<<endl;
                cout<<"\t"<<tempC->enlaceG->enlaceCurso->nomCurso<<endl;
                Grupo*tempG = tempC->enlaceG;
                Estudiante*tempE = primerEstudiante;
                while(tempE != NULL) {
                    imprimirReporte5(tempE,tempG,numCurso,numGrupo);
                    tempE = tempE->sig;
                }
                return;
            } else {
                cout<<"el numero del grupo no coincide con el numero de curso"<<endl;
                return;
            }
        }
        tempC = tempC->sig;
    }
    return;
}

//reporte 6


//reporte 7
bool reporte7() {
    cout<<"Reporte de estudiantes que no han entregado ninguna asignacion"<<endl;
    Estudiante*tempE = primerEstudiante;
    if (tempE == NULL) {
        cout<<"No hay estudiantes"<<endl;
        return false;
    }
    while (tempE != NULL) {
        if (tempE->enlaceReporte != NULL) {
            ReporteEstudiante*tempRe = tempE->enlaceReporte;
            while (tempRe != NULL) {
                if(tempRe->enlaceEvaluaciones == NULL) {
                    cout<<"\t"<<tempE->nombre<<" no ha entregado nada en: "<<tempE->enlaceReporte->enlaceGrupo->enlaceCurso->nomCurso<<endl;
                    tempRe = tempRe->sig;
                } else {
                    tempRe = tempRe->sig;
                }
            }
        }
        tempE = tempE->sig;
    }
}




//reporte 8                                                         /////////////////////////////////////////////////////////////////////////////////////////////////////////////trabajando aqui
void borrarCantidadCharla(Charla*tempCharla){
    while(tempCharla!= NULL){

        tempCharla->cantidadEstudiantes = 0;
        tempCharla = tempCharla->sig;

    }
}

void reporte8(int anno,int numSem) {
    Semestre*tempS = buscarSemestre(anno,numSem);
    if (tempS==NULL) {
        cout<<"El semestre ingresado no existe"<<endl;
        return;
    }
    Charla*tempCharla = tempS->sublistaCharla;
    if (tempCharla == NULL) {
        cout<<"El semestre no tiene charlas"<<endl;
    }
    borrarCantidadCharla(tempCharla);
    while(tempCharla!= NULL) {
        Estudiante*tempEstudiante = primerEstudiante;
        while (tempEstudiante != NULL) {
            if(tempEstudiante->enlaceCharla->enlaceAsistenciaCharla->enlaceCharla->numCharla == tempCharla->numCharla) {
                tempCharla->cantidadEstudiantes += 1;
                tempEstudiante = tempEstudiante->sig;
            }
            tempEstudiante = tempEstudiante->sig;





        }
        tempCharla= tempCharla->sig;
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
        cout<<" 9 - Reporte 7 \n";
        cout<<" 10- Reporte 8  \n";
        cout<<" 0 - Volver a menu principal\n\n";
        cout<<" Opcion: ";
        cin>>choiceAdmin;

        switch(choiceAdmin){

    case 1://punto "b"
        int choiceProf;
        while(choiceProf != 5){
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

    case 2://punto "c"
        int choiceEst;
        while(choiceEst != 5){
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

    case 3://punto "d"
        int choiceSem;
        while(choiceSem != 3){//falta modificar semestre
            cout<<"\n ----------- Acciones semestres -----------\n\n";
            cout<<" 1 - Ingresar un semestre\n";
            cout<<" 2 - Modificar un semestre\n";
            cout<<" 3 - Volver a menu administrador\n\n";
            cout<<" Opcion: ";
            cin>>choiceSem;
            if(choiceSem == 1){
                cout<<"Ingrese los datos que se le solicitan \n\n";
                cout<<"Año: ";
                int anno;
                cin>>anno;

                cout<<"Numero de semestre: ";
                int numSem;
                cin>>numSem;
                cout<<"tipo de semestre(Presencial o Virtual): ";
                string tipo;
                cin>>tipo;

                if(insertarSemestreOrdenado(anno,numSem,tipo) != NULL){
                    cout<<"Semestre insertado exitosamente...\n";
                }else{cout<<"El semestre NO se puedo insertar...\n";}
            }
            else if(choiceSem == 2){
                cout<<"Ingrese los datos que se le solicitan \n\n";
            }
            else if(choiceSem == 3){
                menuAdmin();
            }else{
            cout<<"\n+++++++++++++++++++++++++++++++++++++++++++";
            cout<<"\n+   Por favor ingrese una opcion valida   +";
            cout<<"\n+++++++++++++++++++++++++++++++++++++++++++\n\n";
            }
        }
        menuAdmin();
        break;

    case 4://punto "e"  falta modificar
        int choiceCurso;
        while(choiceCurso != 4){
            cout<<"\n ----------- Acciones cursos -----------\n\n";
            cout<<" 1 - Ingresar un curso\n";
            cout<<" 2 - Modificar un curso\n";
            cout<<" 3 - Borrar un curso\n";
            cout<<" 4 - Imprimir cursos\n";
            cout<<" 5 - Volver a menu administrador\n\n";
            cout<<" Opcion: ";
            cin>>choiceCurso;

            if(choiceCurso == 1){
                cout<<"\n";
                cout<<"Ingrese los datos que se le solicitan para validar la existencia del curso\n\n";
                cout<<"Ingrese el ID del curso: ";
                int IDcurso;
                cin>>IDcurso;

                if(buscarCurso(IDcurso) != NULL){
                    cout<<"Ingrese los datos que se le solicitan del curso a ingresar\n\n";
                    cout<<"Numero de creditos: ";
                    int numCre;
                    cin>>numCre;

                    cout<<"Nombre del curso: ";
                    string nomCurso;
                    cin>>nomCurso;

                    insertarCurso(numCre,nomCurso,IDcurso);
                }else{cout<<"Ese código de curso ya existe...\n\n";}

            }else if(choiceCurso == 2){

                cout<<"Ingrese los datos que se le solicitan \n\n";
                cout<<"";

            }else if(choiceCurso == 3){
                cout<<"Ingrese los datos que se le solicitan \n\n";
                cout<<"Codigo del curso a borrar: ";
                int codCurso;
                cin>>codCurso;

                if(borrarCurso(codCurso) == true){
                    cout<<"Curso borrardo exitosamente...\n";
                }else{cout<<"El curso NO se pudo borrar...\n";}
            }else if(choiceCurso == 4){
                imprimirCursos();
            }else if(choiceCurso == 5){
                menuAdmin();
            }else{cout<<"Opcion no valida...\n";}}
        menuAdmin();
        break;

    case 5://punto "f"
        int choiceGrupoCurso;
        while(choiceGrupoCurso != 2){
            cout<<"\n ----------- Acciones grupo con cursos -----------\n\n";
            cout<<" 1 - Ingresar un grupo y relacionarlos con los cursos\n";
            cout<<" 2 - Volver a menu administrador\n\n";
            cout<<" Opcion: ";
            cin>>choiceGrupoCurso;

            if(choiceGrupoCurso == 1){
                cout<<"Ingrese los datos que se le solicitan para validar la existencia del grupo y su relacion con el curso\n\n";
                cout<<"Numero del grupo: ";
                int numG;
                cin>>numG;

                cout<<"ID del curso a relacionar: ";
                int IDcurso;
                cin>>IDcurso;

                if(insertarGrupo(numG,IDcurso)==true){
                    cout<<"\n\tGrupo insertado exitosamente...\n";
                }else{cout<<"\n\tEl grupo no se pudo insertar...\n";}
            }else if(choiceGrupoCurso == 2){
                menuAdmin();
            }else{cout<<"\nOpcion no valida...\n";}
        }
        menuAdmin();
        break;

    case 6://punto "g"
        int choiceProGru;
        while(choiceProGru != 4){
            cout<<"\n ----------- Acciones profesores con los grupos -----------\n\n";
            cout<<" 1 - Relacionar profesor con un grupo de x curso\n";
            cout<<" 2 - Borrar un profesor con un grupo de x curso\n";
            cout<<" 3 - Imprimir datos de las relaciones\n";
            cout<<" 4 - Volver a menu administrador\n\n";
            cout<<" Opcion: ";
            cin>>choiceProGru;
            if(choiceProGru == 1){
                cout<<"Ingrese los datos que se le solicitan...\n\n";
                cout<<"Cedula del profesor: ";
                int ced;
                cin>>ced;

                cout<<"Codigo del curso: ";
                int codCurso;
                cin>>codCurso;

                cout<<"Numero del grupo: ";
                int numG;
                cin>>numG;
                relacionarProfesoresGrupo(ced,codCurso,numG);
            }else if(choiceProGru == 2){
                cout<<"Ingrese los datos que se le solicitan...\n\n";
                cout<<"Cedula del profesor: ";
                int ced;
                cin>>ced;

                cout<<"Codigo del curso: ";
                int codCurso;
                cin>>codCurso;

                cout<<"Numero del grupo: ";
                int numG;
                cin>>numG;

                eleminarProfesoresGrupo(ced,codCurso,numG);
            }else if(choiceProGru == 3){
                cout<<"Ingrese los datos que se le solicitan...\n\n";
                cout<<"Cedula del profesor: ";
                int ced;
                cin>>ced;

                cout<<"Codigo del curso: ";
                int codCurso;
                cin>>codCurso;

                cout<<endl;
                imprimirProfesorGrupos(ced,codCurso);
            }else if(choiceProGru == 4){
            menuAdmin();
            }else{cout<<"\nOpcion no valida...\n";}
        }
        break;

    case 7://punto "h"
        int choiceEstGrupo;
        while(choiceEstGrupo != 3){
            cout<<"\n ----------- Acciones profesores con los grupos -----------\n\n";
            cout<<" 1 - Relacionar un estudiante a un grupo de x cursos\n";
            cout<<" 2 - Borrar un estudiante a un grupo de x cursos\n";
            cout<<" 4 - Volver a menu administrador\n\n";
            cout<<" Opcion: ";
            cin>>choiceEstGrupo;
            if(choiceEstGrupo == 1){
                cout<<"Ingrese los datos que se le solicitan...\n\n";
                cout<<"Numero de carne: ";
                int carne;
                cin>>carne;

                cout<<"Codigo del curso a relacionar: ";
                int codCurso;
                cin>>codCurso;

                cout<<"Numero del grupo a matricular: ";
                int numG;
                cin>>numG;

                if(relacionarEstudiantesGrupo(carne,codCurso,numG) == true){
                    cout<<"Curso matriculado exitosamente...\n";
                }else{cout<<"El curso no se pudo matricular...\n";}
            }else if(choiceEstGrupo == 2){
                cout<<"Ingrese los datos que se le solicitan...\n\n";
                cout<<"Numero de carne: ";
                int carnet;
                cin>>carnet;

                cout<<"Numero del grupo: ";
                int numG;
                cin>>numG;

                if(borrarRelacionEstudiantesGrupo(carnet,numG) == true){
                    cout<<"Curso borrado exitosamente...\n";
                }else{cout<<"El curso NO se pudo borrar...\n";}

            }else if(choiceEstGrupo == 3){
                menuAdmin();
            }else{cout<<"\nOpcion no valida...\n";}
        }
        break;

    case 8://punto "i"
        int choiceSemCurso;
        while(choiceSemCurso != 2){
            cout<<"\n ----------- Acciones semestre con cursos -----------\n\n";
            cout<<" 1 - Relacionar un semestre con un cursos\n";
            cout<<" 2 - Volver a menu administrador\n\n";
            cout<<" Opcion: ";
            cin>>choiceSemCurso;
            if(choiceSemCurso == 1){
                cout<<"Ingrese los datos que se le solicitan\n\n";
                cout<<"Año: ";
                int anno;
                cin>>anno;

                cout<<"Numero de semestre: ";
                int numSem;
                cin>>numSem;

                cout<<"Codigo del curso a relacionar: ";
                int codCurso;
                cin>>codCurso;

                if(relacionarSemestresCursos(anno,numSem,codCurso) == true){
                    cout<<"Curso relacionado exitosamente...\n";
                }else{cout<<"El curso NO se pudo relacionar...\n";}
            }else if(choiceSemCurso == 2){
                menuAdmin();
            }else{cout<<"Opcion no valida\n";}
        }
        break;

    case 9://reporte 7
        reporte7();
        break;

    case 10://reporte 8//////////////////////////////////////////////////////////////////////////////////////////////////////trabajando aqui
        cout<<"Ingrese los datos que se le solicitan\n\n";
        cout<<"Año del semestre: ";
        int anno;
        cin>>anno;
        cout<<"Numero de semestre: ";
        int numSem;
        cin>>numSem;
        reporte8(anno,numSem);
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

    case 1://punto "j"
        int actCurco;
        while(actCurco != 4){//falta modificar y borrar
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

    case 2://punto "k"
        int choiceCharla;
        while(choiceCharla != 4){//falta insertar y borrar
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

                    if(insertarCharlas(numC,nombreC,numSem,anno,day,month) == true){
                        cout<<"La charla se inserto correctamente...\n";
                    }else{cout<<"La charla NO se logro insertar..\n";}
                }else{
                    cout<<"\nNo se pudo crear la charla debido a que no\n";
                    cout<<"existe ese semestre o el anno del semestre\n";
                }
            }else if(choiceCharla == 2){
                cout<<"Ingrese los datos que se le solicitan\n\n";
                cout<<"Numero de la charla: ";
                int IDcharla;
                cin>>IDcharla;

                cout<<"Año: ";
                int anno;
                cin>>anno;

                cout<<"Numero del semestre: ";
                int numSem;
                cin>>numSem;

                cout<<"Ingrese el nuevo nombre de la charla: ";
                string nombre;
                cin>>nombre;

                if(modificarCharla(IDcharla,anno,numSem,nombre)== true ){
                    cout<<"Charla modificada correctamente...\n";
                    imprimirCharlas();
                }else{cout<<"La charla NO se pudo modificar...\n";}

            }else if(choiceCharla == 3){
                cout<<"Ingrese los datos que se le solicitan\n\n";
                cout<<"Numero de la charla: ";
                int IDcharla;
                cin>>IDcharla;

                cout<<"Año: ";
                int anno;
                cin>>anno;

                cout<<"Numero del semestre: ";
                int numSem;
                cin>>numSem;

                if(borrarCharla(IDcharla,anno,numSem) == true){
                    cout<<"Charla borrado exitosamente...\n";
                }else{cout<<"La charla NO se pudo borrar...\n";}

            }else if(choiceCharla == 4){
                menuProfe();
                break;
            }
        }
        break;

    case 3://Reportes
        int choiceReporte;
        while(choiceReporte!=1){
            cout<<"----------- Menu de reportes de Profesor -----------\n\n";
            cout<<" 1 - Reporte 1 \n";
            cout<<" 2 - Reporte 2 \n";
            cout<<" 3 - Reporte 3 \n";
            cout<<" 4 - Reporte 4 \n";
            cout<<" 5 - Reporte 5 de estudiantes que no han entregado asignaciones\n\n";
            cout<<" 6 - Volver a menú profesor\n\n";
            cout<<"\tOpcion: ";
            cin>>choiceReporte;

            if(choiceReporte == 1){

            }
            else if(choiceReporte == 2){//reporte 2
                cout<<"Ingrese los datos que se le solicitan\n\n";
                cout<<"Cedula del profesor: ";
                int cedProfe;
                cin>>cedProfe;

                cout<<"Año: ";
                int anno;
                cin>>anno;

                cout<<"Numero de semestre: ";
                int numSem;
                cin>>numSem;

                reporte2(cedProfe,anno,numSem);
            }
            else if(choiceReporte == 3){

            }
            else if(choiceReporte == 4){

            }
            else if(choiceReporte == 5){
                cout<<"Ingrese los datos que se le solicitan\n\n";

                cout<<"Cedula del profesor: ";
                int cedProfe;
                cin>>cedProfe;

                cout<<"Curso que imparte: ";
                int numCurso;
                cin>>numCurso;

                cout<<"Numero de grupo: ";
                int numGrupo;
                cin>>numGrupo;

                reporte5(cedProfe,numCurso,numGrupo);

            }
            else if(choiceReporte == 6){
                menuProfe();
            }else{cout<<"Opcion no valida\n";}
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
        cout<<"Numero de carnet: ";
        int cedEst;
        cin>>cedEst;

        cout<<"Numero de la charla: ";
        int numC;
        cin>>numC;

        cout<<"Año del semestre: ";
        int anno;
        cin>>anno;

        cout<<"Numero de semestre: ";
        int numS;
        cin>>numS;

        if(registrarAsistenciaCharla(cedEst,numC,anno,numS) == true){
            cout<<"Asistencia confirmada...\n";
            imprimirAsistenciaCharla(cedEst,anno,numS,numC);
        }else{cout<<"NO se pudo registrar la asistencia...\n";}

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
string returnMes(int mes){

    switch(mes)
{
    case 1: return "Enero";
    break;
    case 2: return "Febrero";
    break;
    case 3: return "Marzo";
    break;
    case 4:  return "Abril";
    break;
    case 5: return "Mayo";
    break;
    case 6: return "Junio";
    break;
    case 7:  return "Julio";
    break;
    case 8:  return "Agosto";
    break;
    case 9: return "Septiembre";
    break;
    case 10: return "Octubre";
    break;
    case 11:  return "Noviembre";
    break;
    case 12:  return "Diciembre";
    break;
}



}

string returnDia(int anno,int mes, int day){

    int a = (14-mes)/12;
    int y = anno - a;
    int m = mes + 12*a - 2;
    int d = (day + y+ y/4 - y/100 + (31*m)/12)%7;

    if(d == 1)
        return "Lunes";
    else if(d == 2)
        return "Martes";
    else if(d == 3)
        return "Miercoles";
    else if(d == 4)
       return "Jueves";
    else if(d == 5)
        return "Viernes";
    else if(d == 6)
        return "Sabado";
    else if(d == 0)
        return "Domingo";

}
void dia(int anno,int mes, int day){

    int a = (14-mes)/12;
    int y = anno - a;
    int m = mes + 12*a - 2;
    int d = (day + y+ y/4 - y/100 + (31*m)/12)%7;

    if(d == 1)
        cout<<"   Lunes:\n";
    else if(d == 2)
        cout<<"   Martes:\n";
    else if(d == 3)
        cout<<"   Miercoles:\n";
    else if(d == 4)
        cout<<"   Jueves:\n";
    else if(d == 5)
        cout<<"   Viernes:\n";
    else if(d == 6)
        cout<<"   Sabado:\n";
    else if(d == 0)
        cout<<"   Domingo:\n";

}

void imprimirEvaluacion3(int codCurso,int numGrupo){
    Curso*tempC = buscarCurso(codCurso);
    Grupo*tempG = buscarGrupo(numGrupo,tempC);

    Evaluacion*Proyecto = tempG->tempP;
    Evaluacion*Tarea = tempG->tempTC;
    Evaluacion*Examen = tempG->tempExa;
    Evaluacion*Giras = tempG->tempG;

    int day = 30 + 7;
    int month = 4;
    int monthMayor = month + 1;
    int dayMayor = day + 7;
    int cont = 0;
    int contDay = 30 + 7;
    if(day >= 30){
        day -= 30;
        dayMayor -= 30;
        month += 1;
        monthMayor += 1;
        contDay -= 30;
    }
    if(cont == 0)
        cout<<"   Lunes:\n";
    if(cont == 1)
        cout<<"   Martes:\n";
    if(cont == 2)
        cout<<"   Miercoles:\n";
    if(cont == 3)
        cout<<"   Jueves:\n";
    if(cont == 4)
        cout<<"   Viernes:\n";
    if(cont == 5)
        cout<<"   Sabado:\n";
    if(cont == 6)
        cout<<"   Domingo:\n";

    cout<<"Day: "<<day<<endl;
    cout<<"Month: "<<month<<endl;

    while(Proyecto != NULL){
        if(Proyecto->dia >= day && Proyecto->mes >= month && Proyecto->dia <= dayMayor && Proyecto->mes < monthMayor ){
            if(contDay == Proyecto->dia){
                cout<<"Proyecto: "<<Proyecto->nombre<<endl;
                cont += 1;
            }
        }
        Proyecto = Proyecto->sig;
    }
    while(Tarea != NULL){
        if(Tarea->dia >= day && Tarea->mes >= month && Tarea->dia <= dayMayor && Tarea->mes < monthMayor){

            cout<<"Tarea: "<<Tarea->nombre<<endl;
        }
        Tarea = Tarea->sig;
    }
    while(Examen != NULL){
        if(Examen->dia > day && Examen->mes >= month && Examen->dia <= dayMayor && Examen->mes < monthMayor){

        cout<<"Examen: "<<Examen->nombre<<endl;
        }
        Examen = Examen->sig;
    }
    while(Giras != NULL){
        if(Giras->dia > day && Giras->mes >= month && Giras->dia <= dayMayor && Giras->mes < monthMayor){
        cout<<"Gira: "<<Giras->nombre<<endl;
        }
        Giras = Giras->sig;
    }

}

void imprimirEvaluacion2(){
    Curso*tempC = buscarCurso(1520);
    Grupo*tempG = buscarGrupo(53,tempC);
    Evaluacion*tempE = tempG->tempP;
    while(tempE != NULL){
        cout<<tempE->id<<endl;
        tempE = tempE->sig;
    }
}

void imprimirEvaluacion(int codCurso,int numGrupo){
    Curso*tempC = buscarCurso(codCurso);
    Grupo*tempG = buscarGrupo(numGrupo,tempC);

    Evaluacion*Proyecto = tempG->tempP;
    Evaluacion*Tarea = tempG->tempTC;
    Evaluacion*Examen = tempG->tempExa;
    Evaluacion*Giras = tempG->tempG;

    while(Proyecto != NULL){
        cout<<"Proyecto: "<<Proyecto->nombre<<endl;
        Proyecto = Proyecto->sig;
    }
    while(Tarea != NULL){
        cout<<"Tarea: "<<Tarea->nombre<<endl;
        Tarea = Tarea->sig;
    }
    while(Examen != NULL){
        cout<<"Examen: "<<Examen->nombre<<endl;
        Examen = Examen->sig;
    }
    while(Giras != NULL){
        cout<<"Gira: "<<Giras->nombre<<endl;
        Giras = Giras->sig;
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

void imprimirCalificacion(){
    Estudiante*tempE = buscarEstudianteReturn(2019053336);
    ReporteEstudiante*tempRe= tempE->enlaceReporte;
    Calificaciones*tempC= tempRe->enlaceEvaluaciones;
    do{
        cout<<tempC->enlaceEvaluaciones->nombre<<endl;
        tempC = tempC->sig;


    }while(tempC != NULL);




}



void baseDeDatos(){

    //Semestres insertados
    insertarSemestreOrdenado(2019,2, "Presencial");
    insertarSemestreOrdenado(2020,2, "Virtual");
    insertarSemestreOrdenado(2020,1, "Presencial");
    insertarSemestreOrdenado(2021,1, "Virtual");
    insertarSemestreOrdenado(2021,2, "Presencial");

    //Administradores insertados
    insertarAdmin("Admin1");
    insertarAdmin("Admin2");
    insertarAdmin("Admin3");
    insertarAdmin("Admin4");
    insertarAdmin("Admin5");

    //insertar profesores
    insertarInicio("Hilary"   ,1001,45);
    insertarInicio("David"   , 702900638, 37);
    insertarInicio("Sofia"   , 645900638, 25);
    insertarInicio("Juan"    , 204500638, 27);
    insertarInicio("Fabiola" , 514000638, 32);
    insertarInicio("Frank"   , 852040638, 45);

    //insertar estudiantes
    InsertaEst("Maria" ,2020053336 ,"Ing. computacion");
    InsertaEst("Jimmy" ,2021053336 ,"Ing. industrial");
    InsertaEst("Felipe",2020053874 ,"Ing. computacion");
    InsertaEst("Amanda",2019053336 ,"Ing. mecanica");
    InsertaEst("Andres",2020054897 ,"Ing. mecanica");

    //insertar cursos
    insertarCurso(5,"Mate Discreta", 1520);
    insertarCurso(2,"Programacion basica", 1535);
    insertarCurso(5,"Dibujo tecnico", 1545);
    insertarCurso(5,"Comunicacion escrita", 1512);
    insertarCurso(5,"Deporte", 1510);

    //borrarCurso(1545);
    //imprimirCursos();


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
    relacionarProfesoresGrupo(1001,1545,02);
    relacionarProfesoresGrupo(1001,1535,15);
    //imprimirInformeMatricula(1001);

    //Relaciona los semestres con los cursos
    relacionarSemestresCursos(2020,1,1520);
    relacionarSemestresCursos(2020,1,1535);
    relacionarSemestresCursos(2020,1,1545);

    //imprimirInformeMatricula(2020,1);

    //Asignacion de evaluaciones
    asignarAsignaciones("Proyecto",53,"Proyecto de estructura I",12,9,2020,1520,53,1001);

    asignarAsignaciones("Proyecto",109,"Proyecto de estructura segundo",10,05,2020,1520,53,1001);
    asignarAsignaciones("Proyecto",503,"Proyecto de estructura primero",7,05,2020,1520,53,1001);
    asignarAsignaciones("Tarea",123,"TC#2",30,05,2020,1520,53,1001);
    asignarAsignaciones("Examen",135,"Parcial 2",01,06,2020,1520,53,1001);
    asignarAsignaciones("Examen",136,"Parcial 3",01,06,2020,1520,53,1001);

    asignarAsignaciones("Tarea",124,"TC#1",30,05,2020,1520,53,1001);
    asignarAsignaciones("Proyecto",125,"Proyecto de estructura IcccII",8,04,2020,1545,02,1001);
    asignarAsignaciones("Examen",126,"Laboratorio II",8,04,2020,1545,02,1001);
    //asignarAsignaciones("Proyecto",123,"Proyecto de estructura bbbbb",8,04,2020,1520,53,1001);
   // imprimirEvaluaciones(53,1520);
   // imprimirEvaluacion2();

    //insertar charlas
    insertarCharlas(0,"Nuevo ultimo",2,2019,5,07);
    insertarCharlas(1,"Ultimo",2,2019,1,05);
    insertarCharlas(5,"Nuevo primero",2,2019,2,04);
    insertarCharlas(4,"Segundo",2,2019,11,04);
    insertarCharlas(2,"Primero",2,2019,10,04);
    insertarCharlas(3,"tercero",2,2019,12,04);


    //imprimirCharlas();

    //registrarAsistenciaCharla(2019053336,1,2019,2);
    registrarAsistenciaCharla(2019053336,2,2019,2);
    //imprimirAsistenciaCharla(2019053336,2019,2,1);


    relacionarEstudiantesGrupo(2019053336,1520,53);
    relacionarEstudiantesGrupo(2020053336,1520,51);
    relacionarEstudiantesGrupo(2020053874,1510,35);
    relacionarEstudiantesGrupo(2021053336,1520,53);


// amanda 2019053336
// jimmy 2021053336

    registrarActividad(2021053336,1520,53,109,"Proyecto");
    registrarActividad(2021053336,1520,53,124,"Tarea");
    registrarActividad(2021053336,1520,53,123,"Tarea");
    registrarActividad(2019053336,1520,53,123,"Tarea");
    registrarActividad(2019053336,1520,53,136,"Examen");
    registrarActividad(2019053336,1520,53,124,"Tarea");


    //imprimirCalificacion();
    //reporte1(1001,2019,2);
    //reporte5(1001,1520,53);
    //reporte2(1001,2019,2);
    //reporte7();
    reporte3(1520);
}

int main(){
    baseDeDatos();

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

Charla*buscarCharla(int year, int numS,int numC){
    Semestre*tempS = buscarSemestre(year,numS);
    if(tempS == NULL)
        return NULL;
    Charla*tempC = tempS->sublistaCharla; //primerSemestre->sublistaCharla;

    while(tempC != NULL){
        if(tempC->numCharla == numC )
            return tempC;
        tempC = tempC->sig;
    }
return NULL;
}
