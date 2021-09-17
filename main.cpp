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

    Estudiante(string nom, int unCarnet, string carr){

    nombre = nom;
    carnet = unCarnet;
    carrera= carr;
    sig  = NULL;
    enlaceReporte=NULL;
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

//Metodos de buscar
bool buscarEstudiante(int num);
bool buscarProfesor(int ced);
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


        while((temp != NULL) && (anno >= temp->anno)){
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

}


//Punto "j"
void asignarAsignaciones(string tipo, int id, string nom, int p, int d, int m, int year, string codCurso, int idGrupo, int cedula){

    Profesor* tempProf = buscarProfesor2(cedula);
    if(tempProf == NULL){
        cout<<"No se encuentra el profesor");
        return NULL;
    }
else{// si existe el profesor

    Grupo *temp = tempProf->suGrupo;
    while(temp!= NULL){//verificar si tiene el grupo asignado
        if(temp->enlaceCurso->codigo == idGrupo)
                if(temp->enlace->enlaceCurso->codigo == codCurso){
                    //si lo tiene asignado
                    Asignaciones *nn = new Asignaciones(id,nom,p,d,m,year);
                    //ocupo saber en cual de las cuatros  sublista es
                   //FALTA la programacion de insertar ordenado por fecha de entrega.
                    if(tipo == "Proyecto" ){

                        nn->sig = temp->enlace->subListaProyectos;
                        temp->enlace->subListaProyectos = nn;// aquí se hizo insercion al inicio y no ORDENADO

                    }
                    else if(tipo == "Tarea" ){

                        nn->sig = temp->enlace->subListaTareas;
                        temp->enlace->subListaTareas = nn;
                    }
                    else if(tipo == "Giras" ){

                        nn->sig = temp->enlace->subListaGiras;
                        temp->enlace->subListaGiras = nn;
                    }
                    else if(tipo == "Examen" ){

                        nn->sig = temp->enlace->subListaExamen;
                        temp->enlace->subListaExamen = nn;
                    }
                    else{
                        cout<<"El tipo de asignacion no existe";
                        return;

                    }
                    cout<<"Se inserto la asignacion correctamente";
                    break;//se sale cuando lo inserta
                }

        temp = temp->sig;
    }
    if(temp == NULL){

        cout<<"No tiene el curso asignado";
        return;
    }
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
        int choiceReporte;//cambiar por un do while
        while(choiceReporte!=1){
            cout<<"----------- Menu de reportes -----------\n\n";
            cout<<" 1 - Reporte 1 \n";
            cout<<" 2 - Reporte 2 \n";
            cout<<" 3 - Reporte 3 \n";
            cout<<" 4 - Reporte 4 \n";
            cout<<" 5 - Reporte 5 \n\n";
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

void baseDeDatos(){



    //Semestres insertados
    primerSemestre      = insertarSemestreOrdenado(2020,2);
    primerSemestre      = insertarSemestreOrdenado(2020,1);
    primerSemestre      = insertarSemestreOrdenado(2019,2);
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
    relacionarSemestresCursos(2020,1,1520);
    relacionarSemestresCursos(2020,1,1535);
    relacionarSemestresCursos(2020,1,1545);

    imprimirInformeMatricula(2020,1);














}
int main()
{
    baseDeDatos();
    //relacionarEstudiantesGrupo(2020053336,1520,53);
    //imprimirInformeMatricula(2020053336);

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

//Metodos de buscar
bool buscarEstudiante(int num)
{

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
