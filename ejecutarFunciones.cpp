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
std::string nombreDos;
std::string jugador1;
std::string jugador2;
int ancho=rlutil::tcols()/2;
int alturaTotal=rlutil::trows();
int altura=rlutil::trows()/2;
int maxNum=0,band=0,puntosLanzamiento1=0,multiplicarPuntos=0,dato=1,sumaTotal=0;
int puntosLanzamiento2=0, maxNum2=0,band1=0;
int acumuladorpuntos1=0, acumuladorpuntos2=0, sumaTotal2=0,sumaTotal1=0;
int mayorPuntaje=0;

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
     jugador1=guardarNombre(nombre);
     system("cls");
    for(int j=1;j<=4;j++){
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
      sumaTotal=0;
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
    cout<<jugador1<<" GANO LA PARTIDA CON ESTOS PUNTOS: "<<sumaTotal<<endl;
    sumaTotal=0;
    rlutil::locate(10,30);
    system("pause");
    system("cls");
    }else{
     system("cls");
     rlutil::locate(60,15);
      cout<<jugador1<<" PERDIO LA PARTIDA CON ESTOS PUNTOS: "<<sumaTotal<<endl;
      sumaTotal=0;
      rlutil::locate(10,30);
      system("pause");
      system("cls");
    }
    break;
case 2:
     system("cls");
     jugador1=guardarNombre(nombre);
     jugador2=guardarNombreDos(nombreDos);
     rlutil::locate(10,30);
     system("pause");
     system("cls");
    for(int j=1;j<=4;j++){
         int tirada=true;
    for(int z=1;z<=6;z++){
    if(tirada==true){
     system("cls");
     rlutil::locate(60,18);
     cout<<"EL TURNO DE TIRAR ES DE: "<<jugador1;
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
     sumaTotal=0;
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
    if(band==0){
     maxNum=puntosLanzamiento1;
     band=1;
    }
   else if(puntosLanzamiento1>maxNum){
    maxNum=puntosLanzamiento1;
    }
    rlutil::locate(10,30);
    system("pause");
    system("cls");
    rlutil::locate(10,30);
    tirada=false;
}
   else{
    system("cls");
    rlutil::locate(60,18);
    cout<<"EL TURNO DE TIRAR ES DE: "<<jugador2;
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
    puntosLanzamiento2=0;
    rlutil::locate(60,16);
    sumaTotal=0;
    }
   else if (distintoDeSeis(vectorD)==6){
    multiplicarPuntos=distintoDeSeis(vectorD)*10;
    puntosLanzamiento2=multiplicarPuntos;
    rlutil::locate(60,14);
    cout<<"TODOS LOS NUMEROS DEL DADO FUERON IGUALES :)"<<endl;
    rlutil::locate(60,16);
    cout<<"SUS PUNTOS EN ESTE LANZAMIENTO SON: "<<puntosLanzamiento2<<endl;
    }
   else {
    puntosLanzamiento2=sumaDeDados(vectorD);
    rlutil::locate(60,14);
    cout<<"LA SUMA DE SUS DADOS EN ESTE LANZAMIENTO ES = "<<puntosLanzamiento2<<endl;
    }
   if(band1==0){
    maxNum2=puntosLanzamiento2;
    band1=1;
    }
   else if(puntosLanzamiento2>maxNum2){
    maxNum2=puntosLanzamiento2;
    }
    rlutil::locate(10,30);
    system("pause");
    system("cls");
    rlutil::locate(10,30);
    tirada=true;

   if(puntosLanzamiento1>puntosLanzamiento2){
    rlutil::locate(60,15);
    cout<<"EL PUNTAJE DE " <<jugador1<< " ES MAYOR EN ESTE LANZAMIENTO"<<endl;
    }
   else {
    rlutil::locate(60,15);
    cout<<"EL PUNTAJE DE " <<jugador2<< " ES MAYOR EN ESTE LANZAMIENTO"<<endl;
    }
    rlutil::locate(10,30);
    system("pause");
    system("cls");
    }
    }
//FOR INTERNO
   if(true){
    rlutil::locate(60,15);
    cout<<"EL PUNTAJE MAS ALTO DE "<<jugador1<< " ES EN ESTA RONDA"<<endl;
    rlutil::locate(60,17);
    cout<<"SON: "<<maxNum;
    rlutil::locate(10,30);
    system("pause");
    system("cls");
    rlutil::locate(60,15);
    cout<<"EL PUNTAJE MAS ALTO DE "<<jugador2<< " ES EN ESTA RONDA"<<endl;
    rlutil::locate(60,17);
    cout<<"SON: "<<maxNum2;
    rlutil::locate(10,30);
    system("pause");
    system("cls");
    }
    sumaTotal2+=maxNum2;
    sumaTotal1+=maxNum;
    maxNum=0;
    maxNum2=0;
    }
 //FOR EXTERNO
   if(sumaTotal1>sumaTotal2){
    rlutil::locate(60,15);
   cout<< "EL GANADOR DE ESTA PARTIDA ES "<<jugador1<< " SUS PUNTOS SON: "<<sumaTotal1<<endl;
    rlutil::locate(60,17);
   cout<< jugador2<< " PERDISTE ESTA PARTIDA CON "<<sumaTotal2<<" PUNTOS. "<<endl;
    }
   else {
    rlutil::locate(60,15);
    cout<<"EL GANADOR DE ESTA PARTIDA ES "<<jugador2<< " SUS PUNTOS SON: "<<sumaTotal2<<endl;
     rlutil::locate(60,17);
    cout<< jugador1<< " PERDISTE ESTA PARTIDA CON "<<sumaTotal1<<" PUNTOS. "<<endl;
   }
    rlutil::locate(10,30);
    system("pause");
    system("cls");
    break;


case 3:
    system("cls");
    if(sumaTotal1>sumaTotal2){
        mayorPuntaje=sumaTotal1;
        cout<<"EL MAYOR PUNTAJE ES DE: "<<jugador1<<" Y SUS PUNTOS SON : "<<mayorPuntaje<<endl;
    } else{
    mayorPuntaje=sumaTotal2;
    cout<<"EL MAYOR PUNTAJE ES DE: "<<jugador2<<" Y SUS PUNTOS SON: "<<mayorPuntaje<<endl;
    }


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

std::string guardarNombreDos(std::string nombreDos){
  int ancho=rlutil::tcols()/2;
  rlutil::locate(10,10);
  cout<<"INGRESE NOMBRE DEL JUGADOR: "<<endl;
  for(int j=1;j<120;j++){
        rlutil::locate(j,13);
        cout<<char(186);
    }
  rlutil::locate(42,10);
  cin>>nombreDos;
  return nombreDos;
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






