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

void CalcularDisponibleenTiempo(int A[][4], int B[4], int p, int r, int DisponibletiempoI[4]) {
    int dato[5]={0,0,0,0};
    int i,j;
    for( i=0;i<p;i++)
    for( j=0;j<r;j++) 
        dato[j]+=A[i][j];
  
 
  for(i=0;i<r;i++) DisponibletiempoI[i]=B[i]-dato[i];
 
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
int safeSequence[10];
int Procesos[10];
void CalculoBanquero( int Asignados[][4],int Maximo[][4],int Necesidad[][4],int x , int y , int DisponibletiempoI[4],int p , int r){

     int  i , j ,process, count;
     count=0;
     for(i=0;i<=p;i++){
     Procesos[i]=0;
    
     }
     
     
     do
        {
                
                cout<<"Matriz Maximo";
                cout<<endl;
                MostrarMatriz(Maximo,p,r);
                cout<<endl;
                cout<<"Matriz Asignados";
                cout<<endl;
                MostrarMatriz(Asignados,p,r);
                cout<<endl;
            

            process = -1;

            for(i = 0; i < p; i++)
            {
                if(Procesos[i] == 0)//if not completed
                {
                    process = i ;
                    for(j = 0; j < r; j++)
                    {
                        if(DisponibletiempoI[j] < Necesidad[i][j])
                        {
                            process = -1;
                            break;
                        }
                    }
                }
                if(process != -1)
                    break;
            }

            if(process != -1)
            {
                cout<<"\nProceso ejecutado!"<<process + 1;
                cout<<endl;
                safeSequence[count] = process + 1;
                count++;
                for(j = 0; j < r; j++)
                {
                    DisponibletiempoI[j] += Asignados[process][j];
                    Asignados[process][j] = 0;
                    Maximo[process][j] = 0;
                    Procesos[process] = 1;
                }
            }
        }
        while(count != p && process != -1);

        if(count == p)
        {
            cout<<"\nSistema termino de ejecutarse!!\n";
            cout<<"Secuencia : < ";
            for( i = 0; i < p; i++)
            cout<<safeSequence[i];
            cout<<">\n";
        }
        else
            cout<<"\nSistema no pudo terminar el ejecutarse completamente!!";


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
//
    cout  << endl << "DISPONIBLE en el tiempo i" << endl;
    MostrarDisponible(DisponibletiempoI, CantidadRecursos);

    cout<< endl << "CALCULANDO......"<<endl;
    CalculoBanquero(Asignados,Maximo,Necesidad,CantidadProcesos,CantidadRecursos,DisponibletiempoI,CantidadProcesos,CantidadRecursos);

    /*for (int i = 0; i < CantidadProcesos;i++) {
        for (int j = 0; j < CantidadRecursos; j++) {
            cout << Maximo[i][j]<< "-";
        }
        cout << endl;
    }*/


    return 0;
}

