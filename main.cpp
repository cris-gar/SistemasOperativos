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
void LlenarMatriz(int A[][4], int x, int y) {
    int maximo;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout << "ingrese los datos de la matriz [" << i <<"]"<<"["<<j<<"]: " ;
            cin >> maximo;
            A[i][j] = maximo;
        }
    }
    cout << endl;
}

void LlenarDisponible(int A[], int z) {
    int maximo;
    for (int j = 0; j < z; j++) {
        cout << "ingrese los datos del vector [" << j <<"]: ";
        cin >> maximo;
        A[j] = maximo;
    }
    cout << endl;
}

void CalcularDisponibleenTiempo(int A[][4], int B[4], int x, int y, int DisponibletiempoI[4]) {
    int dato = 0;
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            dato = dato + A[i][j];
        }
        DisponibletiempoI[i] = dato;
    }
    for (int c = 0; c < y; c++) {
        DisponibletiempoI[c] = B[c] - DisponibletiempoI[c];
    }
}

void CalcularNecesidad(int A[][4], int B[][4], int C[][4], int x, int y) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            A[i][j] = B[i][j] - C[i][j];
        }
    }
}

void MostrarMatriz(int A[][4], int x, int y) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout << "[ " << A[i][j] << " ]";
        }
        cout << endl;
    }
}

void MostrarDisponible(int C[4], int y) {


    for (int c = 0; c < y; c++) {
        cout << " [ " << C[c] << " ] ";
    }


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
    LlenarMatriz(Maximo, CantidadProcesos, CantidadRecursos);
    cout << "Ingrese Datos de la Matriz Asignados:" << endl;
    LlenarMatriz(Asignados, CantidadProcesos, CantidadRecursos);
    LlenarDisponible(Disponible, CantidadRecursos);
    CalcularDisponibleenTiempo(Asignados, Disponible, CantidadProcesos, CantidadRecursos, DisponibletiempoI);
    CalcularNecesidad(Necesidad, Maximo, Asignados, CantidadProcesos, CantidadRecursos);
    cout << "MAXIMO" << endl;
    MostrarMatriz(Maximo, CantidadProcesos, CantidadRecursos);

    cout << "ASIGNADOS" << endl;
    MostrarMatriz(Asignados, CantidadProcesos, CantidadRecursos);

    cout << "NECESIDAD" << endl;
    MostrarMatriz(Necesidad, CantidadProcesos, CantidadRecursos);

    cout << "DISPONIBLE Total" << endl;
    MostrarDisponible(Disponible, CantidadRecursos);
    
    cout  << endl << "DISPONIBLE en el tiempo i" << endl;
    MostrarDisponible(DisponibletiempoI, CantidadRecursos);

    /*for (int i = 0; i < CantidadProcesos;i++) {
        for (int j = 0; j < CantidadRecursos; j++) {
            cout << Maximo[i][j]<< "-";
        }
        cout << endl;
    }*/


    return 0;
}

