#include <iostream>
#include"declararFunciones.h"
#include "rlutil.h"
#include <string>
#include<cstdlib>
#include<ctime>
using namespace std;

void crearMenu(int opcion){
int vectorD[6];
std::string nombre;
int ancho=rlutil::tcols()/2;
int alturaTotal=rlutil::trows();
int altura=rlutil::trows()/2;
int dato=1;
while(dato!=0){
     rlutil::locate(48,5);
    cout<<"BIENVENIDO A ESCALERA ESPERAMOS QUE DISFRUTES EL JUEGO";
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
    cout<<"1-)INICIAR JUEGO PARA UN JUGADOR"<<endl;
    rlutil::locate(ancho,altura+2);
    cout<<"2-)INICIAR JUEGO PARA DOS JUGADORES"<<endl;
    rlutil::locate(ancho,altura+4);
    cout<<"3-)MOSTRAR PUNTUACION MAS ALTA"<<endl;
    rlutil::locate(ancho,altura+6);
    cout<<"0-)SALIR DEL JUEGO"<<endl;
    rlutil::locate(ancho,altura+8);
    cout<<"INGRESAR OPCION ELEGIDA: ";
    cin>>opcion;
    switch(opcion){
case 1:
    system("cls");
    guardarNombre(nombre);
    calculoDado(vectorD);
    system("cls");
    if(condicionEscalera(vectorD)==1){
        rlutil::locate(50,10);
        cout<<"LA SUERTE ESTA DE TU LADO SACASTE ESCALERA :)"<<endl;
    }else{
        rlutil::locate(50,10);
      cout<<"LA SUERTE NO ESTA DE TU LADO NO SACASTE ESCALERA :("<<endl;
    }
    if(distintoDeSeis(vectorD)==6){
        rlutil::locate(50,12);
      cout<<"TODOS LOS NUMEROS DEL DADO FUERON IGUALES :)"<<endl;
      }
    else{
        rlutil::locate(50,12);
        cout<<"LOS NUMEROS DE LOS DADOS NO SON IGUALES :( "<<endl;
    }
    if(condicionIguales(vectorD)==1){
         rlutil::locate(50,14);
        cout<<"TODOS LOS NUMEROS SON IGUALES A 6 PERDES TU PUNTO :( "<<endl;
    }else{
        rlutil::locate(50,14);
        cout<<"TODOS LOS NUMEROS NO SON IGUALES A 6 PODES SEGUIR PROBANDO :) "<<endl;
    }
    rlutil::locate(10,30);
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
  int ancho=rlutil::tcols()/2;
  rlutil::locate(10,5);
  cout<<"INGRESE NOMBRE DEL JUGADOR: "<<endl;
  for(int j=1;j<120;j++){
        rlutil::locate(j,7);
        cout<<char(186);
    }
  rlutil::locate(40,5);
  cin>>nombre;
  return nombre;
}

void calculoDado(int vectorD[6]){
  int puntos=0;

  srand(time(NULL));
  for (int i=0; i<6;i++){
  vectorD[i]=(rand()%6)+1;
  rlutil::locate(10,10);
  cout<<"EL NUMERO DEL DADO "<< i+1 <<" ES "<<vectorD[i]<<endl;
  for(int j=0;j<6;j++)
  for(int j=1;j<120;j++){
        rlutil::locate(j,12);
        cout<<char(186);
    }
   rlutil::locate(10,30);
   system("pause");
 }

}

int condicionEscalera(int vectorD[6]){
int trueEscalera=1;
for(int j=1;j<=6;j++){
    int positivismo=0;
    for(int z=0;z<6;z++){
      if(j==vectorD[z])
        positivismo++;
        if(positivismo>1){
        trueEscalera=0;
        }
    }
}
  return trueEscalera;
}

//MUESTRA SI EL VALOR DE TODOS LOS DADOS ES IGUAL A 6
int condicionIguales (int vectorD[6]){
int contadorSeis;
int dados=0;
  for(int r=0;r<6;r++){
   if(vectorD[r]==6){
    contadorSeis++;
    }
  }
   if(contadorSeis==6){
   dados=1;
   }
   return dados;
   }

//MUESTRA SI EL VALOR DE LOS DADOS ES IGUALES PERO SI EL VALOR ES DISTINTO DE SEIS
   int distintoDeSeis(int vectorD[6]){
   int contadorDistintos;
   int distinto=0;
   int bandera=0;
   int numRetorno=0;
   for( int m=0; m<6;m++){
    if(bandera==0 && vectorD[m]!=6){
       distinto=vectorD[m];
       contadorDistintos++;
       bandera+1;
       }else if(vectorD[m]==distinto&&vectorD[m]!=6){
       contadorDistintos++;
       }
 }
 if(contadorDistintos==6){
    numRetorno=distinto;
 }
  return numRetorno;
   }












