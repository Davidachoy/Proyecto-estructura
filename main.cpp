#include <iostream>

using namespace std;

/*
Primer proyecto de estructuras de datos

Estudiantes: Nicole Tencio y David Achoy

Fecha de inicio: Jueves 02 sept y Fecha final: 30 de septiembre
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
    struct ReporteCharla*enlaceCharla; //conecta con un auxiliar de charlas

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

struct ReporteCharla{//Conecta los estudiantes con las charlas

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
Profesor*primerProfesor;//lista de profesores
Semestre*primerSemestre;//Lista de semestres
Administrador*primerAdministrador;// lista de administradores
Estudiante*primerEstudiante; // lista de estudiantes
Curso*primerCurso; //lista de cursos

//punto "a"
Administrador* insertarAdmin(string user){//Inserta los usuarios //recibe como parametro al nombre de usuario a ingresar
    Administrador*newuser  = new Administrador(user);//Crea el user del admin
    newuser->sig = primerAdministrador;
    primerAdministrador = newuser;
return primerAdministrador;
}

bool buscarAdmin(){//Login user //Valida que el usuario ingresado sea existente
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
Profesor*buscarProfesor2(int ced);

Profesor*insertarInicio(string nom, int id,int edad){//Insertar al inicio lista doble  //Recibe como parametro el nombre,

        Profesor*tempP = buscarProfesor2(id);//Valida que exista el profe a ingresar
        if(tempP != NULL)
            return NULL;

        Profesor*newProf = new Profesor(nom,id,edad);//Lo crea
        newProf->sig = primerProfesor;

        if(primerProfesor != NULL)
            primerProfesor->ant = newProf;

        primerProfesor = newProf;

return primerProfesor;
}

bool modificarProfesor(int ced, string nom){//MOdifica el nombre del profesor //Recibe el ID y el nuevo nombre

    if(primerProfesor == NULL)
        cout<<"Lista de profesores vacia...\n";

    Profesor* temp = buscarProfesor2(ced);//Busca al profesor a modificar con el ID
    if(temp == NULL)
        return false;

    temp->nombre = nom;//Lo modifica
    return true;
}

bool eliminarProfe(int id){//Elimina a X profesor //Recibe el ID de dicho profesor
    if(primerProfesor == NULL)//Lista vacia
        cout<<"\nLista vacia...";
    else if(primerProfesor->cedula == id){//S? se encuentra de primero
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

//Punto "c"... Insertar, modificar y borrar estudiantes (inserci?n ordenada por carnet en lista simple)

Estudiante*buscarEstudianteReturn(int num);

Estudiante*InsertaEst(string nombre, int num, string carrera){//Insertar a los estudiantes en orden por el num de carne //Recibe el nombre, el carne y la carrera del estudiante

    Estudiante*tempBB = buscarEstudianteReturn(num);//Valida la existencia de num
    if(tempBB != NULL)
        return NULL;

    Estudiante* newEst = new Estudiante(nombre,num,carrera);//Lo crea
    newEst->sig = NULL;

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

bool modificarEstudiante(int id, string carreraNueva){//Modifica la carrera del estudiante //Recibe el ID del estudiante y la carrera a modificar

    Estudiante*temp = primerEstudiante;

    while(temp != NULL){//Recorre todos los estudiantes para buscarlo
        if(temp->carnet == id){
            temp->carrera = carreraNueva;//Lo mofifica
            cout<<"\tEstudiante modificado exitosamente...\n";
            return true;
        }
        temp = temp->sig;
    }
    return false;
}

void borrarEst(int num){//Borra a un estudiante por su n?mero de carnet //Recibe el ID del estudiante

    if (primerEstudiante == NULL){//Valida que la lista no este vacia
        cout<<"\n+++++++++++++++++++++++++++++++++++++++++++";
        cout<<"\n+ Aun no se han ingresado los estudiantes +";
        cout<<"\n+++++++++++++++++++++++++++++++++++++++++++\n";
    }
    //lo borra
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

//punto **D** inserta y modificar semestre
//E: anno y numsemestre
//S: semestre creado de forma ordenada en lista doble
Semestre* insertarSemestreOrdenado(int anno,int numSemestre,string tipo){//Recibe el a?o, numero de semestre y el tipo de modalidad del semestre //Inserta al semestre de forma ordenada

        Semestre*tempSS = buscarSemestre(anno,numSemestre);//Valida la existencia de dicho semestre
        if(tempSS != NULL)
            return NULL;

        Semestre *newSemestre = new Semestre(anno,numSemestre,tipo);//Lo crea

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
        }
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

bool modificarSemestre(int NEWanno,int NEWnumSemestre,string newtipo){//Modifica el tipo de modalidad //recibe el numero de semestre y el a?o a modificar y el nuevo tipo de modalidad

    Semestre*tempS = buscarSemestre(NEWanno,NEWnumSemestre);//Valida la existencia
    if( tempS == NULL)
        return false;

    tempS->tipo = newtipo;//Lo modifica
    return true;
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
        while(temp->sig != primerCurso){
            temp = temp->sig;
            temp->sig = newCurso;
        }

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

bool modificarCurso(string tipo,int codigo){ //si no se modifica se pone x valor solo para llenar campo

    Curso*tempC = buscarCurso(codigo);
    if(tempC == NULL)
        return false;

    tempC->nomCurso == tipo;
    return true;

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

bool relacionarProfesoresGrupo(int ced, int codigoCurso,int numGrupo){//Relaciona los profesores con los grupos de los cursos
    //Recibe la cedula del profesor, el codigo de curso y el n?mero del grupo a relacionar

    Profesor*tempP = buscarProfesor2(ced);//Valida la existencia del profe
    if(tempP == NULL)
        return false;

    Curso*tempC = buscarCurso(codigoCurso);//Valida la existencia del Curso
    if(tempC == NULL)
        return false;

    Grupo*tempG = buscarGrupo(numGrupo, tempC);//Valida la existencia del grupo
    if(tempG == NULL)
        return false;

    //Los relaciona
    conexionGrupo*newConexion = new conexionGrupo();
    newConexion->enlaceG = tempG;
    newConexion->sig = tempP->suGrupo;
    tempP->suGrupo = newConexion;//
    return true;

}

bool eleminarProfesoresGrupo(int ced, int codigoCurso, int numGrupo){//Deja de relacionar x profe con x grupo del curso //
    //Recibe la cedula del profesor, el codigo de curso y el n?mero del grupo a borrar

    Profesor*tempP= buscarProfesor2(ced);//Valida la existencia del profe
    if(tempP == NULL)
        return false;

    Curso*tempC = buscarCurso(codigoCurso);//Valida la existencia del Curso
    if(tempC == NULL)
        return false;

    Grupo*tempG = buscarGrupo(numGrupo, tempC);//Valida la existencia del grupo
    if(tempG == NULL)
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

void imprimirProfesorGrupos(int ced, int codigoCurso){//Imprime un informe del profe con sus respectivos grupos //Recibe la cedula del profe y el codigo del curso

    Profesor*tempP = buscarProfesor2(ced);//valida la existencia del profe
    if(tempP == NULL){
        cout<<"Profesor no encontrado...\n";
        return;
    }
    Curso*i = buscarCurso(codigoCurso);//Valida la existencia del curso
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
// Borra la relacion de estudiante con el Grupo
bool borrarRelacionEstudiantesGrupo(int carnet, int numGrupo){//Recibe carnet de estudiante y numero de Grupo

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
bool relacionarSemestresCursos(int year, int numS, int codC){//Relaciona los semestres con los cursos
    //Recibe el a?o y el n?mero del semestre y el codigo del curso a relacionar

    Semestre*tempS = buscarSemestre(year,numS);//Valida la existencia del semestre
    if(tempS == NULL)
        return false;

    Curso*tempC = buscarCurso(codC);//Valida la existencia del curso
    if(tempC == NULL)
        return false;

    //los relaciona
    ConexionCurso* newConexion = new ConexionCurso();
    newConexion->enlaceCurso = tempC;
    newConexion->sig = tempS->enlaceConexionCurso;
    tempS->enlaceConexionCurso = newConexion;
    return true;

}

void imprimirInformeMatricula(int year, int numS){//imprime los cursos relacionados con dicho semestre //Recibe el a?o y el n?mero del semestre

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
//Inserci?n de las evaluaciones
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
//Inserta evaluacion tipo Examen
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
//inserta Evaluacion tipo Tarea
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
// inserta Evaluacuin tipo giras
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
// inserta Evaluacion tipo Proyecto
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

Charla*buscarCharla(int year,int numSem, int numC);

bool insertarCharlas(int id, string nomCharla, int numSem, int anSemestre, int day, int month){//Relaciona los semestres con las charlas
    //Recibe el ID, el nombre de la charla, el a?o y el n?mero del semestre a relacionar y la fecha de la charla

   Charla*tempCC = buscarCharla(anSemestre,numSem,id);//valida la existencia de la charla
   if(tempCC != NULL)
        return false;

   Charla*newCharla = new Charla(nomCharla,id,day,month,anSemestre);//lo crea

   //Lo inserta dependiendo de su fecha
   Semestre*tempS = buscarSemestre(anSemestre,numSem);
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

bool modificarCharla(int IDcharla, int anSemestre, int numSemn, string nuevoName){//Modifica el nombre de la charla
    //recibe el ID de la charla, el a?o y el numero del semestre relacionado y el nuevo nombre de la charla

    Charla*tempC = buscarCharla(anSemestre,numSemn,IDcharla);//Valida la existencia
    if(tempC == NULL)
        return false;

    tempC->tipoCharla = nuevoName;//Lo cambia
    return true;
}

bool borrarCharla(int numC, int anSemestre, int numSem){//Borrar X charla
    //Recibe el ID de la charla y el a?o y numero del semestre relacionado

    Semestre*tempS = buscarSemestre(anSemestre,numSem);//Valida la existencia del semestre
    if(tempS == NULL){
        return false;
    }
    Charla*tempC = tempS->sublistaCharla;//valida la sublista de charlas
    if(tempC == NULL){
        return false;

    }

    //La borra
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
//funcion que busca la evaluacion
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
//Funcion que Registra cuando un estuidante hace una actividad Recibe carnet / codigo Curso/ numGrupo / y la id de actividad.
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

void puntoL(){

    cout<<"Ingrese los datos que se le solicitan\n\n";
    int carnet, codCurso, idGrupo, idAct;
    string tipo;

    cout<<"Carnet de estudiante: ";
    cin>>carnet;

    cout<<"Codigo del curso: ";
    cin>>codCurso;

    cout<<"Numero del grupo: ";
    cin>>idGrupo;

    cout<<"ID de la actividad: ";
    cin>>idAct;

    cout<<"Tipos de actividades: Examen - Tarea - Proyecto - Giras\n";
    cout<<"Tipo a modificar: ";
    cin>>tipo;

    if(registrarActividad(carnet,codCurso,idGrupo,idAct,tipo) == true){
        cout<<"Actividad registrada exitosamente...\n";
        }else{cout<<"La actividad NO se pudo ingresar...\n";}

}

//punto "m"
bool registrarAsistenciaCharla(int cedEst, int idChar, int anno, int numS){//Registra la asistencia a la charla de X estudiante
    //recibe el ID del estudiante, el iD de la charla y el a?o y numero del semestre

    Estudiante*tempE = buscarEstudianteReturn(cedEst);//Valida la existencia del estudiante
    if(tempE == NULL)
        return false;

    Charla*tempC = buscarCharla(anno,numS,idChar);//Valida la existencia de la charla
    if(tempC == NULL)
        return false;

    //los relaciona
    ReporteCharla*newReporteAsistencia = new ReporteCharla();
    AsistenciaCharla*confirmarA = new AsistenciaCharla();

    newReporteAsistencia->sig = tempE->enlaceCharla;
    tempE->enlaceCharla = newReporteAsistencia;
    confirmarA->sig = newReporteAsistencia->enlaceAsistenciaCharla;
    newReporteAsistencia->enlaceAsistenciaCharla = confirmarA;
    newReporteAsistencia->enlaceAsistenciaCharla->enlaceCharla = buscarCharla(anno,numS,idChar);
    return true;
}

bool imprimirAsistenciaCharla(int cedEst){//imprime las charlas asistidas

    //Recibe el ID del estudiante
    Estudiante*tempE = buscarEstudianteReturn(cedEst);//Valida la existencia del est
    if(tempE == NULL)
        return false;

    ReporteCharla*tempR = tempE->enlaceCharla;

    AsistenciaCharla*tempAsis = tempR->enlaceAsistenciaCharla;

    cout<<"\n----------------------------------------\n";
    cout<<"Nombre: "<<tempE->nombre<<"\nCedula: "<<tempE->carnet<<"\nCarrera: "<<tempE->carrera<<"c\n";


    while(tempAsis != NULL){
        cout<<"\tTipo de charla: "<<tempAsis->enlaceCharla->tipoCharla<<endl;
        tempAsis = tempAsis->sig;
    }
    return NULL;
}

void puntoM(){//imprime el punto "m" en el menu del est

    cout<<"Ingrese los datos que se le solicitan\n\n";
    cout<<"Numero de carnet: ";
    int cedEst;
    cin>>cedEst;

    cout<<"Numero de la charla: ";
    int numC;
    cin>>numC;

    cout<<"A?o del semestre: ";
    int anno;
    cin>>anno;

    cout<<"Numero de semestre: ";
    int numS;
    cin>>numS;

    if(registrarAsistenciaCharla(cedEst,numC,anno,numS) == true){
        cout<<"Actividad registrada exitosamente...\n";
        imprimirAsistenciaCharla(cedEst);
    }else{cout<<"NO se pudo registrar la actividad...\n";}

}
///Reportes
//funciones que retorna el dia segun una fecha
string returnMes(int mes);
string returnDia(int anno,int mes, int day);


//funciones para el reporte 1
void dia(int anno,int mes, int day){//Verifica que d?a dela semana cae x asignacion //recibe la fecha

    int a = (14-mes)/12;
    int y = anno - a;
    int m = mes + 12*a - 2;
    int d = (day + y+ y/4 - y/100 + (31*m)/12)%7;

    if(d == 1)
        cout<<"   Lunes:  ";
    else if(d == 2)
        cout<<"   Martes: ";
    else if(d == 3)
        cout<<"   Miercoles: ";
    else if(d == 4)
        cout<<"   Jueves: ";
    else if(d == 5)
        cout<<"   Viernes: ";
    else if(d == 6)
        cout<<"   Sabado: ";
    else if(d == 0)
        cout<<"   Domingo: ";

}

void imprimirEvaluacion3(int codCurso,int numGrupo, int diaDeHoy, int mesDeHoy, int anoDeHoy){
    //imprime las asignaciones de todos los curso para la proxima semana
    //recibe la fecha ingresada por el usuario, el numero del grupo y el codigo del curso
    Curso*tempC = buscarCurso(codCurso);
    Grupo*tempG = buscarGrupo(numGrupo,tempC);

    //Punteros para las listas
    Evaluacion*Proyecto = tempG->tempP;
    Evaluacion*Tarea = tempG->tempTC;
    Evaluacion*Examen = tempG->tempExa;
    Evaluacion*Giras = tempG->tempG;

    //Validaci?n de fechas
    int day = diaDeHoy + 7;
    int month = mesDeHoy;
    int monthMayor = month + 1;
    int dayMayor = day + 7;
    int anno = anoDeHoy;
    if(day > 30){
        day -= 30;
        dayMayor -= 30;
        month += 1;
        monthMayor += 1;
    }
    if(month > 12){
            month -= 12;
            monthMayor -= 12;
            anno += 1;
        }

    while(Proyecto != NULL){//imprime los proyectos
            if(Proyecto->dia >= day && Proyecto->mes >= month && Proyecto->dia <= dayMayor && Proyecto->mes < monthMayor && Proyecto->year == anno ){//Valida
                dia(Proyecto->year,Proyecto->mes,Proyecto->dia);
                cout<<Proyecto->nombre<<endl;
                //cout<<"Dia del proyecto: "<<Proyecto->dia<<endl;

            }
        Proyecto = Proyecto->sig;

    }

    while(Tarea != NULL){//Imprime las tareas
        if(Tarea->dia >= day && Tarea->mes >= month && Tarea->dia <= dayMayor && Tarea->mes < monthMayor){
            dia(Tarea->year,Tarea->mes,Tarea->dia);
            cout<<Tarea->nombre<<endl;
        }
        Tarea = Tarea->sig;
    }
    while(Examen != NULL){//imprime los examenes
        if(Examen->dia > day && Examen->mes >= month && Examen->dia <= dayMayor && Examen->mes < monthMayor){
            dia(Examen->year,Examen->mes,Examen->dia);
            cout<<Examen->nombre<<endl;
        }
        Examen = Examen->sig;
    }
    while(Giras != NULL){//Imprime las giras
        if(Giras->dia > day && Giras->mes >= month && Giras->dia <= dayMayor && Giras->mes < monthMayor){
            dia(Giras->year,Giras->mes,Giras->dia);
            cout<<Giras->nombre<<endl;
        }
        Giras = Giras->sig;
    }

}

void reporte1(int cedPro, int anno, int numS){///Reporte 1
    //Recibe la edula del profesor y el a?o y numero de X semestre
    Profesor*tempP = buscarProfesor2(cedPro);//Valida la existencia del profe
    if(tempP == NULL){
        cout<<"El profesor no se encuentra..\n\n";
        return;
    }
    Semestre*tempS = buscarSemestre(anno,numS);//Valida la existencia del semestre
    if(tempS == NULL){
        cout<<"El semestre no se encuentra..\n\n";
        return;
    }
    cout<<"--------------------------------------\n";//Info del profesor
    cout<<"\nNombre del profesor: "<<tempP->nombre;
    cout<<"\nCedula: "<<tempP->cedula;
    cout<<"\nEdad: "<<tempP->edad;
    conexionGrupo*tempConex = tempP->suGrupo;

    cout<<"\n------------- Reporte 1 ---------------\n";
    cout<<"\nIngrese la fecha del d?a de hoy\nDia: ";//Inserci?n de la fecha actual
    int diaDeHoy,mesDeHoy,anoDeHoy;
    cin>>diaDeHoy;

    cout<<"Mes: ";
    cin>>mesDeHoy;

    cout<<"A?o: ";
    cin>>anoDeHoy;

    while(tempConex != NULL){

        cout<<"\nCurso: "<<tempConex->enlaceG->enlaceCurso->nomCurso<<"\tGrupo: "<<tempConex->enlaceG->numGrupo<<"\n\n";//info Curso
        imprimirEvaluacion3(tempConex->enlaceG->enlaceCurso->codigo,tempConex->enlaceG->numGrupo,diaDeHoy,mesDeHoy,anoDeHoy);//Imprime las asignaciones para la proxima semanna

        tempConex = tempConex->sig;
    }
}

void reporte2(int cedPro, int anno, int numS){///Reporte 2
    ////Recibe la edula del profesor y el a?o y numero de X semestre
    Profesor*tempP = buscarProfesor2(cedPro);
    if(tempP == NULL){
        cout<<"El profesor no se encuentra..\n\n";//Valida la existencia del profesor
        return;
    }
    Semestre*tempS = buscarSemestre(anno,numS);//Valida la existencia del semestre
    if(tempS == NULL){
        cout<<"El semestre no se encuentra..\n\n";
        return;
    }
    cout<<"--------------------------------------\n";//info profe
    cout<<"\nNombre del profesor: "<<tempP->nombre;
    cout<<"\nCedula: "<<tempP->cedula;
    cout<<"\nEdad: "<<tempP->edad;
    conexionGrupo*tempConex = tempP->suGrupo;

    cout<<"\n ------------------------------ Reporte 2 ------------------------------ \n";
    cout<<"                       Semestre "<<tempS->numSemestre<<"\tA?o "<<tempS->anno<<endl;//info semestre
    while(tempConex != NULL){

        Curso*tempC = buscarCurso(tempConex->enlaceG->enlaceCurso->codigo);//busca al curso con ese semestre
        Grupo*tempG = buscarGrupo(tempConex->enlaceG->numGrupo,tempC);//busca el grupo al cual el profe esta relacionado

        //Punteros para recorrerlas listas
        Evaluacion*Proyecto = tempG->tempP;
        Evaluacion*Tarea = tempG->tempTC;
        Evaluacion*Examen = tempG->tempExa;
        Evaluacion*Giras = tempG->tempG;

        //imprime todas las actividades de este semestre de todos los curso
        while(Proyecto != NULL){//imprime proyectos
            cout<<"\t"<<Proyecto->nombre<<" de "<<tempConex->enlaceG->enlaceCurso->nomCurso<<" del grupo "<<tempConex->enlaceG->numGrupo<<endl;
            Proyecto = Proyecto->sig;
        }
        while(Tarea != NULL){//Imprime tareas
            cout<<"\t"<<Tarea->nombre<<" de "<<tempConex->enlaceG->enlaceCurso->nomCurso<<" del grupo "<<tempConex->enlaceG->numGrupo<<endl;
            Tarea = Tarea->sig;
        }
        while(Examen != NULL){//imprime examenes
            cout<<"\t"<<Examen->nombre<<" de "<<tempConex->enlaceG->enlaceCurso->nomCurso<<" del grupo "<<tempConex->enlaceG->numGrupo<<endl;
            Examen = Examen->sig;
        }
        while(Giras != NULL){//improme giras
            cout<<"\t"<<Giras->nombre<<" de "<<tempConex->enlaceG->enlaceCurso->nomCurso<<" del grupo "<<tempConex->enlaceG->numGrupo<<endl;
            Giras = Giras->sig;
        }

        tempConex = tempConex->sig;
    }
    cout<<"\n------------------------------------------------------------------------ \n";

}

void reporte3(int codCurso){///Reporte 3
        //recibe el codigo del curso

    Curso*tempC = buscarCurso(codCurso);//valida la existencia del curso
    if(tempC == NULL){
        cout<<"Curso no encontrado"<<endl;
        return;
    }

    cout<<"\n ---------------- Reporte 3 ---------------- \n";

    while( tempC->sublistaGrupos != NULL ){//recorre las grupos
        while(tempC->sublistaGrupos->tempTC != NULL){//recorre las asinaciones
            cout<<endl<<tempC->sublistaGrupos->tempTC->nombre<<" del "<<tempC->sublistaGrupos->tempTC->dia<<"/"<<tempC->sublistaGrupos->tempTC->mes<<"/"<<tempC->sublistaGrupos->tempTC->year;
            cout<<" en el curso "<<tempC->nomCurso<<" del grupo "<<tempC->sublistaGrupos->numGrupo<<endl;
            Estudiante*tempE = primerEstudiante;
            if (tempE == NULL) {
                cout<<"No hay estudiantes"<<endl;
                return;
            }

            while(tempE != NULL){//recorre a los estudiantes
                ReporteEstudiante*tempRe = tempE->enlaceReporte;
                while(tempRe != NULL){
                    Calificaciones*tempCali = tempRe->enlaceEvaluaciones;

                    while(tempCali != NULL){
                        if( tempC->sublistaGrupos->numGrupo == tempRe->enlaceGrupo->numGrupo){//valida que sea del mismo grupo

                                if(tempCali->enlaceEvaluaciones->nombre == tempC->sublistaGrupos->tempTC->nombre){//valida que sea del mismo tipo
                                    cout<<"\t"<<tempE->nombre<<" si presento la tarea "<<tempCali->enlaceEvaluaciones->nombre<<endl;
                                }
                        }
                        tempCali = tempCali->sig;
                    }

                    tempRe = tempRe->sig;
                }
                tempE = tempE->sig;
            }
            tempC->sublistaGrupos->tempTC = tempC->sublistaGrupos->tempTC->sig;
        }

        tempC->sublistaGrupos = tempC->sublistaGrupos->sig;
    }
}

//funciones para el reporte 5 consulta que estudiantes no han entregado asignaciones en un Curso
//imprime todas las evaluaciones en caso de que no haya participado en nada
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
// imprime los examenes que no ha hecho
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
// imprime las tareas que no ha hecho
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
// imprime los Giras que no ha hecho
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
// imprime los Proyecto que no ha hecho
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

void reporte5(int cedulaProf, int numCurso, int numGrupo) {///Reporte 5
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


bool reporte7() {//reporte 7 imprime los estudiantes que no han hecho nada
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

//reporte 8      verifica si un estudante ha participado en una charla y le suma uno
void verificarCharla(Estudiante*tempEstud, Charla*tempCharla){
    ReporteCharla*tempReporte = tempEstud->enlaceCharla;
    while (tempReporte!= NULL){
            AsistenciaCharla*tempAsistencia = tempReporte->enlaceAsistenciaCharla;
            while(tempAsistencia != NULL){
                if (tempAsistencia->enlaceCharla->numCharla ==tempCharla->numCharla){
                    tempCharla->cantidadEstudiantes += 1;
                    return;
                }else{
                    tempAsistencia= tempAsistencia->sig;
                }
            }
            tempReporte = tempReporte->sig;
        }

        return;
    }
//vacia la cantidad de estudiantes por charla
void borrarCantidadCharla(Charla*tempCharla){
    while(tempCharla!= NULL){

        tempCharla->cantidadEstudiantes = 0;
        tempCharla = tempCharla->sig;

    }
}
//Funcion para imprimir las 3 mejores charlas de X semestre R: num semestre y anno semestre
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
            if (tempEstudiante->enlaceCharla == NULL) {
                tempEstudiante = tempEstudiante->sig;
            }


            verificarCharla(tempEstudiante, tempCharla);
            tempEstudiante = tempEstudiante->sig;





            }
            tempCharla= tempCharla->sig;
        }


    Charla*mayorAMenorCharla = NULL;
    Charla*tempCharlaLista = tempS->sublistaCharla;
    while(tempCharlaLista != NULL) {
        Charla*newCharla = new Charla(tempCharlaLista->tipoCharla,tempCharlaLista->numCharla, tempCharlaLista->dia,tempCharlaLista->mes,tempCharlaLista->anno);
        newCharla->cantidadEstudiantes = tempCharlaLista->cantidadEstudiantes;
        if(mayorAMenorCharla == NULL) {
            mayorAMenorCharla = newCharla;
        } else if(newCharla->cantidadEstudiantes > mayorAMenorCharla->cantidadEstudiantes) {
            newCharla->sig = mayorAMenorCharla;
            mayorAMenorCharla = newCharla;
        } else {

            Charla*temp = mayorAMenorCharla;
            Charla*tempAnt =NULL;
            while((temp != NULL) && (newCharla->cantidadEstudiantes<= temp->cantidadEstudiantes)) {
                tempAnt = temp;
                temp = temp->sig;
            }//
            if(temp ==NULL) { //el numero a insertar es mayor a todos
                tempAnt->sig = newCharla;
            } else { // insertar en medio
                newCharla->sig = temp;
                tempAnt->sig = newCharla;
            }
        }
        tempCharlaLista = tempCharlaLista->sig;
    }
    Charla*imprimirChar2 = mayorAMenorCharla;
    while(imprimirChar2!= NULL) {
        imprimirChar2= imprimirChar2->sig;
    }
    int contador = 0;
    Charla*imprimirChar = mayorAMenorCharla;
    cout<<"Para el "<<tempS->numSemestre<<" semestre "<<tempS->anno<<endl;
    while (contador != 3) {
        if (imprimirChar == NULL) {
            break;
        }
        cout<<"\tCharla #"<<imprimirChar->numCharla<< " con "<<imprimirChar->cantidadEstudiantes<< " estudiante"<<endl;
        imprimirChar = imprimirChar->sig;
        contador += 1;
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
                }else{cout<<"Ya se encuentra registrado ese numero de cedula...\n\t?Vuelvalo a intentar!\n";}
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
        while(choiceSem != 3){
            cout<<"\n ----------- Acciones semestres -----------\n\n";
            cout<<" 1 - Ingresar un semestre\n";
            cout<<" 2 - Modificar un semestre\n";
            cout<<" 3 - Volver a menu administrador\n\n";
            cout<<" Opcion: ";
            cin>>choiceSem;
            if(choiceSem == 1){
                cout<<"Ingrese los datos que se le solicitan \n\n";
                cout<<"A?o: ";
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
                cout<<"A?o: ";
                int anno;
                cin>>anno;

                cout<<"Numero de semestre: ";
                int numSem;
                cin>>numSem;
                cout<<"Tipo de semestre por el cual va a asignar(Presencial o Virtual): ";
                string tipo;
                cin>>tipo;
                if(modificarSemestre(anno,numSem,tipo) == true){
                    cout<<"El semestre se modifico correctamente...\n";
                }else{cout<<"El semestre NO se modifico...\n";}
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

    case 4://punto "e"
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

                if(buscarCurso(IDcurso) == NULL){//insertar
                    cout<<"Ingrese los datos que se le solicitan del curso a ingresar\n\n";
                    cout<<"Numero de creditos: ";
                    int numCre;
                    cin>>numCre;

                    cout<<"Nombre del curso: ";
                    string nomCurso;
                    cin>>nomCurso;

                    insertarCurso(numCre,nomCurso,IDcurso);
                    cout<<"Insertado exitosamente..\n";
                }else{cout<<"Ese c?digo de curso ya existe...\n\n";}

            }else if(choiceCurso == 2){//modificar

                cout<<"Ingrese los datos que se le solicitan \n\nCodigo del curso: ";
                int codCurso;
                cin>>codCurso;

                cout<<"Nuevo nombre: ";
                string tipo;
                cin>>tipo;

                if(modificarCurso(tipo,codCurso) == true){
                    cout<<"Modificado correctamente...\n";
                }else{cout<<"NO se puedo modificar el curso...\n";}

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
                cout<<"A?o: ";
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

    case 10://reporte 8
        cout<<"Ingrese los datos que se le solicitan\n\n";
        cout<<"A?o del semestre: ";
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

void menuProfe(){///Menu para el profesor
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
        else if(actCurco == 2){//modificar


        }
        else if(actCurco == 3){

        }
        else if(actCurco == 4){
            menuProfe();
        }else{cout<<"Opcion no valida...\n";}}
        break;

    case 2://punto "k"
        int choiceCharla;
        while(choiceCharla != 4){
            cout<<"----------- Menu de Charlas -----------\n\n";
            cout<<" 1 - Insertar charla\n";
            cout<<" 2 - Modificar nombre de una charla\n";
            cout<<" 3 - Eliminar una charla\n";
            cout<<" 4 - Volver a menu profesor\n\n";
            cout<<" Opcion: ";
            cin>>choiceCharla;

            if(choiceCharla == 1){//insertar
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

                    cout<<"D?a: ";
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

                cout<<"A?o: ";
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
                    //imprimirCharlas();
                }else{cout<<"La charla NO se pudo modificar...\n";}

            }else if(choiceCharla == 3){
                cout<<"Ingrese los datos que se le solicitan\n\n";
                cout<<"Numero de la charla: ";
                int IDcharla;
                cin>>IDcharla;

                cout<<"A?o: ";
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
        while(choiceReporte!=6){
            cout<<"----------- Menu de reportes de Profesor -----------\n\n";
            cout<<" 1 - Reporte 1 \n";
            cout<<" 2 - Reporte 2 \n";
            cout<<" 3 - Reporte 3 \n";
            cout<<" 4 - Reporte 4 \n";
            cout<<" 5 - Reporte 5 \n";
            cout<<" 6 - Volver a men? profesor\n\n";
            cout<<"Opcion: ";
            cin>>choiceReporte;

            if(choiceReporte == 1){//reporte 1
                cout<<"Ingrese los datos que se le solicitan\n\n";
                int cedProfe,anno,numSem;
                cout<<"Cedula del profesor: ";
                cin>>cedProfe;
                cout<<"A?o: ";
                cin>>anno;
                cout<<"Numero de semestre: ";
                cin>>numSem;

                reporte1(cedProfe,anno,numSem);

            }
            else if(choiceReporte == 2){//reporte 2
                cout<<"Ingrese los datos que se le solicitan\n\n";
                cout<<"Cedula del profesor: ";
                int cedProfe;
                cin>>cedProfe;

                cout<<"A?o: ";
                int anno;
                cin>>anno;

                cout<<"Numero de semestre: ";
                int numSem;
                cin>>numSem;

                reporte2(cedProfe,anno,numSem);
            }
            else if(choiceReporte == 3){//reporte 3
                cout<<"Ingrese los datos que se le solicitan\n\n";
                int codCurso;
                cin>>codCurso;

                reporte3(codCurso);
            }
            else if(choiceReporte == 4){//reporte 4
            ///No se hizo
            }
            else if(choiceReporte == 5){//reporte 5
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
            else if(choiceReporte == 6){//salir
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

void menuEst(){ /// menu Estudiante
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

    case 1://punto "l"
        puntoL();
        break;

    case 2://punto "m"
        puntoM();
        break;

    case 3://reporte 6
        ///No se hizo
        break;

    case 4:
        repetir = false;
        break;
        }
    }while(repetir);
};

void menuUsuarios(){ ///main menu

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
//Base de datos del proyecto
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
    insertarInicio("Hilary"   ,1001,21);
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
    relacionarProfesoresGrupo(1001,1520,51);
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

    asignarAsignaciones("Tarea",124,"TC#1",29,05,2020,1520,53,1001);
    asignarAsignaciones("Tarea",124,"TC#1",31,05,2020,1520,51,1001);
    //asignarAsignaciones("Tarea",127,"TC#1",30,07,2020,1520,52,1001);

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
    relacionarEstudiantesGrupo(2021053336,1520,53);
    //relacionarEstudiantesGrupo(2021053336,1520,53);


// amanda 2019053336
// jimmy 2021053336

    registrarActividad(2021053336,1520,53,124,"Tarea");
    registrarActividad(2021053336,1520,53,123,"Tarea");
    registrarActividad(2019053336,1520,53,123,"Tarea");
    registrarActividad(2019053336,1520,53,124,"Tarea");
    registrarActividad(2020053336,1520,51,124,"Tarea");

    //imprimirCalificacion();
    //reporte1(1001,2020,2);
    ////reporte5(1001,1520,53);
    //reporte2(1001,2020,2);
    //reporte7();
    //reporte3(1520);
    //modificarSemestre(2020,2,"Presencial");
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
//true si existe el profesor y false lo contrario
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
//Retorna el Grupo
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
//Retorna el estudiante
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
//retorna el semestre
Semestre*buscarSemestre(int year, int numS){
    Semestre*tempS = primerSemestre;

    while(tempS != NULL){
        if(tempS->anno == year && tempS->numSemestre == numS)
            return tempS;
        tempS = tempS->sig;
    }
    return NULL;
}
//retorna true si hay semestre y false lo contrario
bool buscarSemestreBool(int year, int numS){
    Semestre*tempS = primerSemestre;

    while(tempS != NULL){
        if(tempS->anno == year && tempS->numSemestre == numS)
            return true;
        tempS = tempS->sig;
    }
    return false;
}
//retorna la charla
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
