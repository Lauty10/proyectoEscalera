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
int maxNum=0,band=0,puntosLanzamiento1=0,multiplicarPuntos=0,dato=1,sumaTotal=0;
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
     system("cls");
    for(int j=1;j<=3;j++){
    for(int n=1;n<=3;n++){
    rlutil::locate(58,5);
    cout<<nombre<<" USTED SE ENCUENTRA EN LA RONDA NUMERO: "<<j;
      for(int j=40;j<110;j++){
        rlutil::locate(j,7);
         cout<<char(176);
    }
    calculoDado(vectorD);
    system("cls");
    if (condicionEscalera(vectorD)==1){
      rlutil::locate(60,14);
      cout<<"LA SUERTE ESTA DE TU LADO SACASTE ESCALERA :)"<<endl;
      rlutil::locate(10,30);
      return;
    }
    if (condicionIguales(vectorD)==1){
      rlutil::locate(60,14);
      cout<<"TODOS LOS NUMEROS FUERON IGUALES A 6. PERDISTE TODOS TUS PUNTOS :("<<endl;
       puntosLanzamiento1=0;
      rlutil::locate(60,16);
      cout<<"SUS PUNTOS SON : "<<puntosLanzamiento1<<endl;
    }
    else if (distintoDeSeis(vectorD)==6){
       multiplicarPuntos=distintoDeSeis(vectorD)*10;
       puntosLanzamiento1=multiplicarPuntos;
        rlutil::locate(60,14);
       cout<<"TODOS LOS NUMEROS DEL DADO FUERON IGUALES :)"<<endl;
       rlutil::locate(60,16);
       cout<<"SUS PUNTOS EN ESTE LANZAMIENTO SON: "<<puntosLanzamiento1<<endl;
        }
    else {
    puntosLanzamiento1=sumaDeDados(vectorD);
    rlutil::locate(60,14);
    cout<<"LA SUMA DE SUS DADOS EN ESTE LANZAMIENTO ES = "<<puntosLanzamiento1<<endl;
    }
    rlutil::locate(10,30);
    system("pause");
    system("cls");
    if(band==0){
        maxNum=puntosLanzamiento1;
        band=1;
    }else if(puntosLanzamiento1>maxNum){
     maxNum=puntosLanzamiento1;
    }
    } //BUCLE FOR INTERNO
     rlutil::locate(60,15);
    cout<<"EL MAXIMO NUMERO DE ESTA RONDA ES: "<<maxNum;
    rlutil::locate(10,30);
    system("pause");
    system("cls");
    sumaTotal+=maxNum;
    maxNum=0;
    } //BUCLE FOR EXTERNO
     if(sumaTotal>=100){
    system("cls");
    rlutil::locate(60,15);
    cout<<"USTED GANO LA PARTIDA CON ESTOS PUNTOS: "<<sumaTotal;
    sumaTotal=0;
    system("pause");
    system("cls");
    }else{
     system("cls");
     rlutil::locate(60,15);
      cout<<"USTED PERDIO LA PARTIDA CON ESTOS PUNTOS: "<<sumaTotal<<endl;
      sumaTotal=0;
      rlutil::locate(10,30);
      system("pause");
      system("cls");
    }
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

//FUNCIONES UTILIZADAS -- FUNCIONES EJECUTADAS

std::string guardarNombre(std::string nombre){
  int ancho=rlutil::tcols()/2;
  rlutil::locate(10,5);
  cout<<"INGRESE NOMBRE DEL JUGADOR: "<<endl;
  for(int j=1;j<120;j++){
        rlutil::locate(j,8);
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
  rlutil::locate(62,13);
  cout<<"EL NUMERO DEL DADO "<< i+1 <<" ES "<<vectorD[i]<<endl;
  for(int j=40;j<110;j++){
        rlutil::locate(j,15);
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

int sumaDeDados(int vectorD[6]){
int sumaDePuntos=0;
for (int a=0;a<6;a++){
    sumaDePuntos+=vectorD[a];
}
return sumaDePuntos;
}






