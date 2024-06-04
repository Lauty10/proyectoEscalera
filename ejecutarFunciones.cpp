#include <iostream>
#include"declararFunciones.h"
#include "rlutil.h"
using namespace std;

void crearMenu(int opcion){
int dato=1;
while(dato!=0){
    rlutil::locate(60,10);
    cout<<"1-)Iniciar juego para un jugador"<<endl;
     rlutil::locate(50,11);
    cout<<"-------------------------------------------------------------"<<endl;
    rlutil::locate(60,12);
    cout<<"2-)Iniciar juego para dos jugadores"<<endl;
    rlutil::locate(50,13);
    cout<<"-------------------------------------------------------------"<<endl;
    rlutil::locate(60,14);
    cout<<"3-)Mostrar puntuacion mas alta"<<endl;
     rlutil::locate(50,15);
    cout<<"-------------------------------------------------------------"<<endl;
    rlutil::locate(60,16);
    cout<<"0-)Salir del juego"<<endl;
    rlutil::locate(50,17);
    cout<<"-------------------------------------------------------------"<<endl;
    rlutil::locate(65,18);
    cout<<"Ingrese la opcion elegida: ";
    cin>>opcion;
    switch(opcion){
case 1:
    system("cls");
    cout<<"ACA OPCION 1"<<endl;
    system("pause");
    system("cls");
    break;
case 2:
    system("cls");
    cout<<"ACA OPCION 2"<<endl;
    system("pause");
    system("cls");
    break;
case 3:
    system("cls");
    cout<<"ACA OPCION 3"<<endl;
    system("pause");
    system("cls");
    break;
case 0:
    system("cls");
    dato=0;
    return;
    break;
default:
    system("cls");
    cout<<"Eliga una opcion correcta"<<endl;
    system("pause");
    system("cls");
}
}
}
