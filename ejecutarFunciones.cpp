#include <iostream>
#include"declararFunciones.h"
using namespace std;

void crearMenu(int opcion){
int dato=1;
while(dato!=0){
    cout<<"1-)Iniciar juego para un jugador"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"2-)Iniciar juego para dos jugadores"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"3-)Mostrar puntuacion mas alta"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"4-)Ingrese 0 para salir del juego"<<endl;
    cout<<"------------------------------"<<endl;
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
case 4:
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
