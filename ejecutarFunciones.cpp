#include <iostream>
#include"declararFunciones.h"
#include "rlutil.h"
#include <string>
using namespace std;

void crearMenu(int opcion){
std::string nombre;
int ancho=rlutil::tcols()/2;
int alturaTotal=rlutil::trows();
int altura=rlutil::trows()/2;
int dato=1;
while(dato!=0){
     rlutil::locate(48,5);
    cout<<"BIENVENIDO A ESCALERA ESPERAMOS QUE DISFRUTES EL JUEGO";
    for(int j=1;j<alturaTotal;j++){
        rlutil::locate(10,j);
        cout<<char(186);
    }
     for(int j=1;j<alturaTotal;j++){
        rlutil::locate(12,j);
        cout<<char(186);
    }
        for(int j=1;j<alturaTotal;j++){
        rlutil::locate(14,j);
        cout<<char(186);
    }

    for(int j=41;j<110;j++){
        rlutil::locate(j,7);
         cout<<char(176);
    }
    for(int j=41;j<110;j++){
        rlutil::locate(j,12);
       cout<<"-";
       rlutil::locate(j,27);
       cout<<"-";
    }
       for(int j=13;j<27;j++){
        rlutil::locate(40,j);
        cout<<char(221);
        rlutil::locate(110,j);
        cout<<char(221);
    }

    rlutil::locate(ancho,altura);
    cout<<"1-)Iniciar juego para un jugador"<<endl;
    rlutil::locate(ancho,altura+2);
    cout<<"2-)Iniciar juego para dos jugadores"<<endl;
    rlutil::locate(ancho,altura+4);
    cout<<"3-)Mostrar puntuacion mas alta"<<endl;
    rlutil::locate(ancho,altura+6);
    cout<<"0-)Salir del juego"<<endl;
    rlutil::locate(ancho,altura+8);
    cout<<"Ingrese la opcion elegida: ";
    cin>>opcion;
    switch(opcion){
case 1:
    system("cls");
    guardarNombre(nombre);
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

std::string guardarNombre(std::string nombre){
  cout<<"ingrese el nombre del jugador "<<endl;
  cin>>nombre;
  cout<<"Bienvenid@ "<<nombre<<endl;
   return nombre;
}

