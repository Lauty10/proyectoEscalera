#include <iostream>
#include"declararFunciones.h"
#include "rlutil.h"
#include <string>
#include<cstdlib>
#include<ctime>
using namespace std;

void crearMenu(int opcion){
int vectorD[6];
int VectorV[6];
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
int maxPuntaje=0,bandPuntaje=0;
int maxPuntajeDos=0,bandPuntajeDos=0;
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
    cout<<"4-)MODO SIMULADO"<<endl;
    rlutil::locate(ancho,altura+8);
    cout<<"0-)SALIR DEL JUEGO"<<endl;
    rlutil::locate(ancho,altura+10);
    cout<<"INGRESAR OPCION ELEGIDA: ";
    cin>>opcion;
    switch(opcion){
case 1:
     system("cls");
     jugador1=guardarNombre(nombre);
     system("cls");
    for(int j=1;j<=4;j++){
    for(int n=1;n<=3;n++){
     rlutil::locate(15,5);
    cout<<nombre<<" TIRADA NUMERO: "<<n;
    rlutil::locate(58,5);
    cout<<nombre<<" USTED SE ENCUENTRA EN LA RONDA NUMERO: "<<j;
      for(int j=40;j<110;j++){
        rlutil::locate(j,7);
         cout<<char(176);
    }
    rlutil::locate(70,20);
    cout<<"ACUMULADO TOTAL: "<<sumaTotal;
    calculoDado(vectorD);
    system("cls");
    if (condicionEscalera(vectorD)==1){
      rlutil::locate(58,14);
      cout<<"LA SUERTE ESTA DE TU LADO SACASTE ESCALERA :)"<<endl;
      rlutil::locate(10,30);
      return;
    }
    if (condicionIguales(vectorD)==1){
       rlutil::locate(58,14);
      cout<<"TODOS LOS NUMEROS FUERON IGUALES A 6. PERDISTE TODOS TUS PUNTOS :("<<endl;
       puntosLanzamiento1=0;
       sumaTotal=0;
    }
    else if (distintoDeSeis(vectorD)==6){
       multiplicarPuntos=distintoDeSeis(vectorD)*10;
       puntosLanzamiento1=multiplicarPuntos;
        rlutil::locate(58,14);
       cout<<"TODOS LOS NUMEROS DEL DADO FUERON IGUALES :)"<<endl;
        rlutil::locate(58,14);
       cout<<"SUS PUNTOS EN ESTE LANZAMIENTO SON: "<<puntosLanzamiento1<<endl;
        }
    else {
    puntosLanzamiento1=sumaDeDados(vectorD);
     rlutil::locate(58,14);
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
    }
    rlutil::locate(58,14);
    cout<<"EL MAXIMO NUMERO DE ESTA RONDA ES: "<<maxNum;
    rlutil::locate(10,30);
    system("pause");
    system("cls");
    sumaTotal+=maxNum;
    maxNum=0;
    }
     if(sumaTotal>=100){
    system("cls");
    rlutil::locate(58,14);
    cout<<jugador1<<" GANO LA PARTIDA CON ESTOS PUNTOS: "<<sumaTotal<<endl;
    rlutil::locate(10,30);
    system("pause");
    system("cls");
    }else{
     system("cls");
     rlutil::locate(58,14);
      cout<<jugador1<<" PERDIO LA PARTIDA CON ESTOS PUNTOS: "<<sumaTotal<<endl;
      rlutil::locate(10,30);
      system("pause");
      system("cls");
    }
    if(bandPuntaje=0){
        maxPuntaje=sumaTotal;
        bandPuntaje=1;
    }else if(sumaTotal>maxPuntaje){
    maxPuntaje=sumaTotal;
    }
    sumaTotal=0;
    break;
case 2:
     system("cls");
     jugador1=guardarNombre(nombre);
     jugador2=guardarNombreDos(nombreDos);
     rlutil::locate(10,30);
     system("pause");
     system("cls");
    for(int j=1;j<=4;j++){
    int tirada=true,tiradaUno=1,tiradoDos=1;
    for(int z=1;z<=6;z++){
    if(tirada==true){
     system("cls");
    rlutil::locate(15,5);
    cout<<nombre<<" TIRADA NUMERO: "<<tiradaUno;
     rlutil::locate(60,20);
     cout<<"EL TURNO DE TIRAR ES DE: "<<jugador1;
     rlutil::locate(56,5);
    cout<<nombre<<" USTED SE ENCUENTRA EN LA RONDA NUMERO: "<<j;
      for(int j=40;j<110;j++){
        rlutil::locate(j,7);
         cout<<char(176);
    }
    rlutil::locate(65,25);
    cout<<"ACUMULADO TOTAL: "<<sumaTotal1;
     calculoDado(vectorD);
     system("cls");
    if (condicionEscalera(vectorD)==1){
      rlutil::locate(58,14);
     cout<<"LA SUERTE ESTA DE TU LADO SACASTE ESCALERA :)"<<endl;
     rlutil::locate(10,30);
      return;
    }
    if (condicionIguales(vectorD)==1){
     rlutil::locate(58,14);
     cout<<"TODOS LOS NUMEROS FUERON IGUALES A 6. PERDISTE TODOS TUS PUNTOS :("<<endl;
     rlutil::locate(58,14);
     cout<<"PROXIMO JUGADOR EN TIRAR = "<<jugador2<<endl;
     puntosLanzamiento1=0;
     rlutil::locate(60,16);
     sumaTotal1=0;
    }
    else if (distintoDeSeis(vectorD)==6){
     multiplicarPuntos=distintoDeSeis(vectorD)*10;
     puntosLanzamiento1=multiplicarPuntos;
     rlutil::locate(58,14);
     cout<<"TODOS LOS NUMEROS DEL DADO FUERON IGUALES :)"<<endl;
     rlutil::locate(58,14);
     cout<<"SUS PUNTOS EN ESTE LANZAMIENTO SON: "<<puntosLanzamiento1<<endl;
    rlutil::locate(58,14);
     cout<<"PROXIMO JUGADOR EN TIRAR = "<<jugador2<<endl;
    }
    else {
     puntosLanzamiento1=sumaDeDados(vectorD);
     rlutil::locate(58,14);
     cout<<"LA SUMA DE SUS DADOS EN ESTE LANZAMIENTO ES = "<<puntosLanzamiento1<<endl;
    rlutil::locate(58,14);;
     cout<<"PROXIMO JUGADOR EN TIRAR = "<<jugador2<<endl;
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
    tiradaUno++;
}else{
    system("cls");
     rlutil::locate(15,5);
    cout<<nombre<<" TIRADA NUMERO: "<<tiradoDos;
    rlutil::locate(60,20);
    cout<<"EL TURNO DE TIRAR ES DE: "<<jugador2;
    rlutil::locate(58,5);
    cout<<nombre<<" USTED SE ENCUENTRA EN LA RONDA NUMERO: "<<j;
      for(int j=40;j<110;j++){
        rlutil::locate(j,7);
         cout<<char(176);
    }
    rlutil::locate(65,25);
    cout<<"ACUMULADO TOTAL: "<<sumaTotal2;
    calculoDado(vectorD);
    system("cls");
   if (condicionEscalera(vectorD)==1){
    rlutil::locate(58,14);
    cout<<"LA SUERTE ESTA DE TU LADO SACASTE ESCALERA :)"<<endl;
    rlutil::locate(10,30);
      return;
      }
   if (condicionIguales(vectorD)==1){
    rlutil::locate(58,14);
    cout<<"TODOS LOS NUMEROS FUERON IGUALES A 6. PERDISTE TODOS TUS PUNTOS :("<<endl;
     rlutil::locate(58,16);
    cout<<"PROXIMO JUGADOR EN TIRAR = "<<jugador1<<endl;
    puntosLanzamiento2=0;
    rlutil::locate(60,16);
    sumaTotal2=0;
    }
   else if (distintoDeSeis(vectorD)==6){
    multiplicarPuntos=distintoDeSeis(vectorD)*10;
    puntosLanzamiento2=multiplicarPuntos;
      rlutil::locate(58,14);
    cout<<"TODOS LOS NUMEROS DEL DADO FUERON IGUALES :)"<<endl;
      rlutil::locate(58,14);
    cout<<"SUS PUNTOS EN ESTE LANZAMIENTO SON: "<<puntosLanzamiento2<<endl;
      rlutil::locate(58,18);
    cout<<"PROXIMO JUGADOR EN TIRAR = "<<jugador1<<endl;
    }
   else {
    puntosLanzamiento2=sumaDeDados(vectorD);
      rlutil::locate(58,14);
    cout<<"LA SUMA DE SUS DADOS EN ESTE LANZAMIENTO ES = "<<puntosLanzamiento2<<endl;
     rlutil::locate(58,16);
    cout<<"PROXIMO JUGADOR EN TIRAR = "<<jugador1<<endl;
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
     tiradoDos++;
   if(puntosLanzamiento1>puntosLanzamiento2){
    rlutil::locate(58,15);
    cout<<"EL PUNTAJE DE " <<jugador1<< " ES MAYOR EN ESTE LANZAMIENTO"<<endl;
    }
   else {
      rlutil::locate(58,15);
    cout<<"EL PUNTAJE DE " <<jugador2<< " ES MAYOR EN ESTE LANZAMIENTO"<<endl;
    }
    rlutil::locate(10,30);
    system("pause");
    system("cls");
    }
    }
   if(true){
    rlutil::locate(58,15);
    cout<<"EL PUNTAJE MAS ALTO DE "<<jugador1<< " ES EN ESTA RONDA"<<endl;
    rlutil::locate(58,17);
    cout<<"SON: "<<maxNum;
    rlutil::locate(10,30);
    system("pause");
    system("cls");
    rlutil::locate(58,15);
    cout<<"EL PUNTAJE MAS ALTO DE "<<jugador2<< " ES EN ESTA RONDA"<<endl;
    rlutil::locate(58,17);
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
   if(sumaTotal1>sumaTotal2){
    rlutil::locate(58,15);
   cout<< "EL GANADOR DE ESTA PARTIDA ES "<<jugador1<< " SUS PUNTOS SON: "<<sumaTotal1<<endl;
    rlutil::locate(58,17);
   cout<< jugador2<< " PERDISTE ESTA PARTIDA CON "<<sumaTotal2<<" PUNTOS. "<<endl;
    }
   else {
    rlutil::locate(58,15);
    cout<<"EL GANADOR DE ESTA PARTIDA ES "<<jugador2<< " SUS PUNTOS SON: "<<sumaTotal2<<endl;
     rlutil::locate(58,17);
    cout<< jugador1<< "PERDISTE ESTA PARTIDA CON "<<sumaTotal1<<" PUNTOS. "<<endl;
   }
    if(bandPuntajeDos=0){
         bandPuntajeDos=1;
        if(sumaTotal1>sumaTotal2){
         maxPuntajeDos=sumaTotal1;
        }else{
         maxPuntajeDos=sumaTotal2;
        }
    }else if(sumaTotal1>maxPuntajeDos && sumaTotal1>sumaTotal2){
        maxPuntajeDos=sumaTotal1;
    }else if(sumaTotal2>maxPuntajeDos && sumaTotal2>sumaTotal1){
        maxPuntajeDos=sumaTotal2;
    }
    sumaTotal1=0;
    sumaTotal2=0;
    rlutil::locate(10,30);
    system("pause");
    system("cls");
    break;
case 3:
    system("cls");
    if(true){
    rlutil::locate(50,10);
    cout<<"EL PUNTAJE MAS ALTO OBTENIDO PARA MODO UN JUGADOR ES: "<<maxPuntaje<<endl;
    }
    for(int j=1;j<149;j++){
        rlutil::locate(j,15);
         cout<<char(205);;
    }
    if(true){
    rlutil::locate(50,20);
    cout<<"EL PUNTAJE MAS ALTO OBTENIDO PARA MODO DOS JUGADORES ES: "<<maxPuntajeDos<<endl;
    }
    rlutil::locate(10,30);
    system("pause");
    system("cls");
    break;
    //MODO SIMULADO
case 4:
    system("cls");
     jugador1=guardarNombre(nombre);
     system("cls");
    for(int j=1;j<=4;j++){
    for(int n=1;n<=3;n++){
     rlutil::locate(15,5);
    cout<<nombre<<" TIRADA NUMERO: "<<n;
    rlutil::locate(58,5);
    cout<<nombre<<" USTED SE ENCUENTRA EN LA RONDA NUMERO: "<<j;
      for(int j=40;j<110;j++){
        rlutil::locate(j,7);
         cout<<char(176);
    }
    cargarDado(vectorD);
    system("cls");
    if (condicionEscalera(vectorD)==1){
      rlutil::locate(58,14);
      cout<<"LA SUERTE ESTA DE TU LADO SACASTE ESCALERA :)"<<endl;
      rlutil::locate(10,30);
      return;
    }
    if (condicionIguales(vectorD)==1){
      rlutil::locate(50,14);
      cout<<"TODOS LOS NUMEROS FUERON IGUALES A 6. PERDISTE TODOS TUS PUNTOS :("<<endl;
       puntosLanzamiento1=0;
      rlutil::locate(60,16);
      sumaTotal=0;
    }
    else if (distintoDeSeis(vectorD)==6){
       multiplicarPuntos=distintoDeSeis(vectorD)*10;
       puntosLanzamiento1=multiplicarPuntos;
        rlutil::locate(58,14);
       cout<<"TODOS LOS NUMEROS DEL DADO FUERON IGUALES :)"<<endl;
       rlutil::locate(58,16);
       cout<<"SUS PUNTOS EN ESTE LANZAMIENTO SON: "<<puntosLanzamiento1<<endl;
        }
    else {
    puntosLanzamiento1=sumaDeDados(vectorD);
    rlutil::locate(58,14);
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
    }
     rlutil::locate(60,15);
    cout<<"EL MAXIMO NUMERO DE ESTA RONDA ES: "<<maxNum;
    rlutil::locate(10,30);
    system("pause");
    system("cls");
    sumaTotal+=maxNum;
    maxNum=0;
    }
     if(sumaTotal>=100){
    system("cls");
    rlutil::locate(58,15);
    cout<<jugador1<<"GANO LA PARTIDA CON ESTOS PUNTOS: "<<sumaTotal<<endl;
    rlutil::locate(10,30);
    system("pause");
    system("cls");
    }else{
     system("cls");
     rlutil::locate(58,15);
      cout<<jugador1<<"PERDIO LA PARTIDA CON ESTOS PUNTOS: "<<sumaTotal<<endl;
      rlutil::locate(10,30);
      system("pause");
      system("cls");
    }
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
  rlutil::locate(60,10);
  cout<<"INGRESE NOMBRE DEL JUGADOR: "<<endl;
  for(int j=20;j<120;j++){
        rlutil::locate(j,12);
        cout<<char(178);
    }
  rlutil::locate(88,10);
  cin>>nombre;
  return nombre;
}
std::string guardarNombreDos(std::string nombreDos){
  int ancho=rlutil::tcols()/2;
  rlutil::locate(60,15);
  cout<<"INGRESE NOMBRE DEL JUGADOR: "<<endl;
  for(int j=20;j<120;j++){
        rlutil::locate(j,17);
        cout<<char(176);
    }
  rlutil::locate(88,15);
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

void cargarDado (int VectorV [6]){
  int valor=0;
  for (int i=0; i<6;i++){
  rlutil::locate(64,14);
  cout<<"INGRESE EL VALOR DEL DADO: "<<i+1<<endl;
   rlutil::locate(64,16);
  cout<<"EL VALOR DEL DADO ES: ";
  rlutil::locate(85,16);
  cin>>valor;
  VectorV[i]=valor;
  rlutil::locate(64,18);
  cout<<"EL NUMERO DEL DADO "<< i+1 <<" ES "<<VectorV[i]<<endl;
  rlutil::locate(10,30);
}
}

