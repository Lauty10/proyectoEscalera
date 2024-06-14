#ifndef DECLARARFUNCIONES_H_INCLUDED
#define DECLARARFUNCIONES_H_INCLUDED
#include <string>
void crearMenu(int opcion);
std::string guardarNombre(std::string nombre);
std::string guardarNombreDos(std::string nombre);
void calculoDado(int vectorD[6]);
int condicionEscalera(int vectorD[6]);
int condicionIguales (int vectorD[6]);
int distintoDeSeis (int vectorD [6]);
int sumaDeDados(int vectorD[6]);
void cargarDado (int VectorV [6]);
int distintoDeSeis(int VectorV[6]);
void juegoUno(std::string jugador1,std::string nombre,int sumaTotal, int vectorD[6],int opcion,int puntosLanzamiento1,int multiplicarPuntos,int band,int maxNum,int bandPuntaje,int&maxPuntaje);
void juegoDos(std::string nombre,std::string nombreDos,std::string jugador1,std::string jugador2,int sumaTotal1,int vectorD[6],int opcion,int puntoLanzamiento1,int multiplicarPuntos,int band,int maxNum,int sumaTotal2,int puntosLanzamiento2,int band1,int maxNum2,int bandPuntajeDos,int&maxPuntajeDos);
void mostrarPuntajes(int&maxPuntaje,int&maxPuntajeDos);
void modoSimulado(std::string jugador1,std::string nombre,int vectorD[6],int opcion,int puntosLanzamiento1,int sumaTotal,int multiplicarPuntos,int band,int maxNum);
void resultado(int escalera,int igualesSeis,int distintosSeis,int sumaDados,int opcion,int&puntosLanzamiento1,int&sumaTotal,int multiplicarPuntos);
#endif // DECLARARFUNCIONES_H_INCLUDED
