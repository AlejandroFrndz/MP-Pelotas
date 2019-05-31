/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "pelota.h"
#include "utilidades.h"
#include "definiciones.h"
#include "miniwin.h"
#include "pelotas.h"
#include <cstring>
#include <fstream>

using namespace std;
using namespace miniwin;
//Función para pintar 1 pelota
void pintar(const Pelota& P) {
   color((int) P.getColor());
   circulo_lleno(P.getX(), P.getY(), P.getRadio());
}
//Función para pintar un vector de pelotas
void pintar(const Pelotas& Pelotas){
    
    for(int i = 0; i< Pelotas.util; i++){
        pintar(Pelotas.v[i]);
    }
}
//Función para pintar las pelotas de una partida
void pintar(const Simulador& partida, const int n){
    
    borra();
    pintar(partida.actual);
    refresca();
    espera(n);
            
}
//Función que mueve 1 pelota y las mantiene en los límites de la ventana
void mover(Pelota &P) {
   const float factor = 0.97;
   
   P.mover();
  
   if (P.getX() > vancho() - P.getRadio()) {
      P.setVelocidad(-P.getVelX()*factor, P.getVelY());
      P.setPosicion(vancho()-P.getRadio(), P.getY());
   } 
   else if (P.getX() < P.getRadio()) {
      P.setVelocidad(-P.getVelX()*factor, P.getVelY());
      P.setPosicion(P.getRadio(), P.getY());
   } 
   else if (P.getY() > valto() - P.getRadio()) {
      P.setVelocidad(P.getVelX(), -P.getVelY()*factor);
      P.setPosicion(P.getX(), valto() - P.getRadio());
   } 
   else if (P.getY() < P.getRadio()) {
      P.setVelocidad(P.getVelX(), -P.getVelY()*factor);
      P.setPosicion(P.getX(), P.getRadio());
   }
  // P.dy += 0.1;
}
//Función para mover un vector de pelotas
void mover(Pelotas &Pelotas){
    const float factor = 0.97;
    
    for(int i = 0; i < Pelotas.util; i++){
      mover(Pelotas.v[i]);
    }
}
//Función para realizar el intercambio de 2 variables de tipo float
void intercambio(float& P1, float& P2){
    float aux;
    aux = P1;
    P1 = P2;
    P2 = aux;
}
//Función para intercambiar 2 variables de tipo PColor
void intercambio(PColor& P1, PColor& P2){
    PColor aux;
    aux = P1;
    P1 = P2;
    P2 = aux;
}
//Función que realiza el choque de 2 pelotas intercambiando sus posiciones. (Y opcionalmente su color)
void colisionar(Pelota &P1, Pelota &P2){
        intercambio(P1.dx, P2.dx);
        intercambio(P1.dy, P2.dy);  
        //intercambio(P1.color, P2.color);
         
}
//Función para realizar el choque de todas las pelotas del vector. Aquí se tienen en consideración las reglas del juego
//Si una pelota verde choca con otra verde, intercambian velocidades y nace otra pelota verde con atributos aleatorios y el radio de los padres
//Si una pelota roja choca con una verde, la verde muere y la roja continúa su camino inalterada
//Si chocan 2 pelotas rojas se intercambian las velocidades
void colisionar(Pelotas& PV){
    
    Pelota P1, P2;
    bool chocado = false;
    int i = 0, j= 0;
    
    for(i = 0; i < PV.util; i++){
        
        chocado = false;
        for(j = i+1; j < PV.util && !chocado; j++){
            
            P1=PV.v[i];
            P2=PV.v[j];
            
            if(P1.colisionado(P2)){
                
                if(P1==P2){
                
                    if(P1.getColor() == PColor::VERDE){
                        PV.Nacer(P1.getRadio());
                        colisionar(PV.v[i], PV.v[j]);
                        chocado = true;
                    }

                    if(P1.getColor() == PColor::ROJO){
                      colisionar(PV.v[i], PV.v[j]);
                       chocado = true;
                     }
                }

                else{
                    
                    if(P1.getColor() == PColor::ROJO)
                            PV.Matar(j);


                    if (P2.getColor() == PColor::ROJO )
                            PV.Matar(i);

                    chocado = true;
                }
            }
        }
    }
}
//Función para convertir un dato PColor en string
string ToString(PColor C){
    
    string sol;
    
    if(C == PColor::VERDE)
        sol = "VERDE";
    else
        sol = "ROJO";
    
    return sol;
}
//Función para convertir un dato string a PColor
PColor ToPColor(string C){
    
    PColor sol;
    
    if(C == "VERDE")
        sol = PColor::VERDE;
    else
        sol = PColor::ROJO;
    
    return sol;
}
//Operador de lectura de Pelota
istream& operator>>(istream& in, Pelota &P){
    
    string color_id;
    double x, y, dx, dy, radio;
    
    in >> x >> y >> dx >> dy >> radio >> color_id;
        
    P.setPelota(x,y,dx,dy,radio,ToPColor(color_id));
    
    return in;
    
}
//Operador de lectura de Pelotas
istream& operator>>(istream& in, Pelotas& PV){
   
    Pelota P;
    int tam;
    
    in >> tam;
    for (int i = 0; i < tam; i++){
        in >> P;
        PV += P;
    }
    
    return in;
}
//Operador de lectura de Simulador
istream& operator>>(istream& in, Simulador& Partida){
    
    Pelotas PV;
    int anch, alt;
    
    in >> anch >> alt;
    
    Partida.SetScreen(anch, alt);
    
    in >> PV;
    
    Partida.SetOriginal(PV);
    Partida.SetActual(PV);
    
    return in;
}
//Operador de escritura de Pelota
ostream& operator<<(ostream& out, const Pelota& P){
    
    out << P.getX() << " " << P.getY() << " " << P.getVelX() << " " << P.getVelY() << " " << P.getRadio() << " " << ToString(P.getColor()) << endl;
    
    return out;
}
//Operador de escritura de Pelotas
ostream& operator<<(ostream& out, const Pelotas& PV){
    
    out << PV.getUtil() << "\n";
    
    for(int i = 0; i < PV.getUtil(); i++)
        out << PV[i];
    
    return out;
} 
//Operador de escritura de Simulador
ostream& operator<<(ostream& out, const Simulador& Partida){
    
        out << "MP−PELOTAS−T−1.0" << "\n";
        out << Partida.getAncho() << "\n";
        out << Partida.getAlto() << "\n";
        out << Partida.getActual();
}