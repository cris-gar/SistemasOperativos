/*
 * File:   main.cpp
 * Author: cristian
 *
 * Created on 15 de abril de 2013, 02:48 PM
 */

#include <iostream>

using namespace std;

/*
 *
 */


void LlenarMatriz(int Matriz[][4], int CantidadProcesos, int CantidadRecursos) { //procedimiento que se encarga de llenar la matriz que recibe con datos ingresados por el usuario
    int maximo;
    for (int i = 0; i < CantidadProcesos; i++) {
        for (int j = 0; j < CantidadRecursos; j++) {
            cout << "ingrese los datos de la matriz [" << i << "]" << "[" << j << "]: ";
            cin >> maximo;
            Matriz[i][j] = maximo;
        }
    }
    cout << endl;
}

void LlenarDisponible(int Vector[], int CantidadRecursos) {//procedimiento que se encarga de llenar el Vector que recibe con datos ingresados por el usuario
    int maximo;
    for (int j = 0; j < CantidadRecursos; j++) {
        cout << "ingrese los datos del vector [" << j << "]: ";
        cin >> maximo;
        Vector[j] = maximo;
    }
    cout << endl;
}

void CalcularDisponibleenTiempo(int MatrizA[][4], int MatrizB[4], int CantidadProcesos, int CantidadRecursos, int DisponibletiempoI[4]) {//Calcula los recursos disponibles en el tiempo para el algoritmo
    int dato[5] = {0, 0, 0, 0};
    int i, j;
    for (i = 0; i < CantidadProcesos; i++)
        for (j = 0; j < CantidadRecursos; j++)
            dato[j] += MatrizA[i][j];

    for (i = 0; i < CantidadRecursos; i++) DisponibletiempoI[i] = MatrizB[i] - dato[i];

}

void CalcularNecesidad(int MatrizA[][4], int MatrizB[][4], int MatrizC[][4], int CantidadProcesos, int CantidadRecursos) {//Calcula la necesidad de cada fila para la matriz Necesidad
    for (int i = 0; i < CantidadProcesos; i++) {
        for (int j = 0; j < CantidadRecursos; j++) {
            MatrizA[i][j] = MatrizB[i][j] - MatrizC[i][j];
        }
    }
}

void MostrarMatriz(int MatrizA[][4], int CantidadProcesos, int CantidadRecursos) {//procedimiento que muestra por pantalla el contenido de la matriz recibida como parametro
    for (int i = 0; i < CantidadProcesos; i++) {
        for (int j = 0; j < CantidadRecursos; j++) {
            cout << "[ " << MatrizA[i][j] << " ]";
        }
        cout << endl;
    }
}

void MostrarDisponible(int VectorC[4], int CantidadRecursos) {// procedimiento que muestra por pantalla el contenido del vector recibido como paramatro
    for (int c = 0; c < CantidadRecursos; c++) {
        cout << " [ " << VectorC[c] << " ] ";
    }

}
int safeSequence[10];
int Procesos[10];

void CalculoBanquero(int Asignados[][4], int Maximo[][4], int Necesidad[][4], int DisponibletiempoI[4], int CantidadProcesos, int CantidadRecursos) {
    //procedimiento que calcula el algoritmo del banquero
    int i, j, process, count;
    count = 0;
    for (i = 0; i <= CantidadProcesos; i++) {
        Procesos[i] = 0;
        void CalculoBanquero(int Asignados[][4], int Maximo[][4], int Necesidad[][4], int DisponibletiempoI[4], int CantidadProcesos, int CantidadRecursos);
        //llamada recursiva al algoritmo del banquero
    }


    do//acciones que se tienen que realizar antes de verificar
    {

        cout << "Matriz Maximo";
        cout << endl;
        MostrarMatriz(Maximo, CantidadProcesos, CantidadRecursos); //muetra la matriz Maximo correspondiente por pantalla
        cout << endl;
        cout << "Matriz Asignados";
        cout << endl;
        MostrarMatriz(Asignados, CantidadProcesos, CantidadRecursos); // muetra la matriz Asignada correspondiente por pantalla
        cout << endl;


        process = -1;
        //ciclo for para ver si el la fila correspondiente de la necesida se ajusta al disponible en el tiempo
        for (i = 0; i < CantidadProcesos; i++) {
            if (Procesos[i] == 0) {
                process = i;
                for (j = 0; j < CantidadProcesos; j++) {
                    if (DisponibletiempoI[j] < Necesidad[i][j]) {
                        process = -1;
                        break;
                    }
                }
            }
            if (process != -1)
                break;
        }

        if (process != -1)//si la fila de la nesecidad si se ajusta entra
        {
            cout << endl << "Proceso ejecutado!" << process + 1;
            cout << endl;
            safeSequence[count] = process + 1;
            count++;
            for (j = 0; j < CantidadRecursos; j++)//ciclo for para afectar a la fila asignada en le maximo y tambien la necesidad en el tiempo
            {
                DisponibletiempoI[j] += Asignados[process][j];
                Asignados[process][j] = 0;
                Maximo[process][j] = 0;
                Procesos[process] = 1;
            }
        }
    } while (count != (CantidadProcesos) && process != -1);

    if (count == CantidadProcesos)//si el contador es igual a la cantidad de procesos entra	
    {
        //muestra por pantalla la secuencia segura conrrespondiente 
        cout << "\nSistema termino de ejecutarse!!\n";
        cout << "Secuencia : < ";
        for (i = 0; i < CantidadProcesos; i++)
            cout << safeSequence[i];
        cout << ">\n";
    } else
        cout << "\nSistema no pudo terminar el ejecutarse completamente!!";


}

int main(int argc, char** argv) {
    int CantidadProcesos, CantidadRecursos;
    cout << "Ingrese la cantidad de Procesos: ";
    cin >> CantidadProcesos;
    cout << "Ingrese la cantidad de Recursos: ";
    cin >> CantidadRecursos;
    cout << endl;
    int Asignados[10][4], Maximo[10][4], Necesidad[10][4];
    int Disponible[4], DisponibletiempoI[4];

    cout << "Ingrese Datos de la Matriz Maximo:" << endl;
    LlenarMatriz(Maximo, CantidadProcesos, CantidadRecursos); //llamada al procedimiento llenar matriz enviando la matriz de Maximo
    cout << "Ingrese Datos de la Matriz Asignados:" << endl;
    LlenarMatriz(Asignados, CantidadProcesos, CantidadRecursos); //llamada al procedimiento llenar matriz enviando la matriz de Asignados 
    LlenarDisponible(Disponible, CantidadRecursos); //llamada al procedimiento llenar Disponible enviando el vector Disponible total
    CalcularDisponibleenTiempo(Asignados, Disponible, CantidadProcesos, CantidadRecursos, DisponibletiempoI); //llamada al procedimiento CalcularDisponibleenTiempo donde es enviando el vector Disponible, Asignados, la cantidad de procesos y recursos y el DisponibletiempoI 
    CalcularNecesidad(Necesidad, Maximo, Asignados, CantidadProcesos, CantidadRecursos); //llamada al procedimiento CalalcularNecesidad enviando Necesidad, Asignados, Maximo y la cantidad de procesos y recursos.
    cout << "MAXIMO" << endl;
    MostrarMatriz(Maximo, CantidadProcesos, CantidadRecursos); //llamada al procedimiento mostrar matriz con el parametro Maximo

    cout << "ASIGNADOS" << endl;
    MostrarMatriz(Asignados, CantidadProcesos, CantidadRecursos); //llamada al procedimienro mostrar matriz con el parametro Asignados

    cout << "NECESIDAD" << endl;
    MostrarMatriz(Necesidad, CantidadProcesos, CantidadRecursos); //llamada al procedimiento mostrar matriz con el parametro Necesidad

    cout << "DISPONIBLE Total" << endl;
    MostrarDisponible(Disponible, CantidadRecursos); // llamada al procedimiento mostrar Disponible con el parametro Disponible

    cout << endl << "DISPONIBLE en el tiempo i" << endl;
    MostrarDisponible(DisponibletiempoI, CantidadRecursos); //llama al procedimiento mostrar Disponible con el parametro DisponibletiempoI

    cout << endl << "CALCULANDO......" << endl;
    CalculoBanquero(Asignados, Maximo, Necesidad, DisponibletiempoI, CantidadProcesos, CantidadRecursos); //llamada al procedimiento funcion CalculoBanquero con todos los parametros.

    return 0;
}

