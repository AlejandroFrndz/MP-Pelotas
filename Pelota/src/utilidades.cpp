/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Pelota.h"
#include "utilidades.h"
#include "definiciones.h"
#include "miniwin.h"
#include "Pelotas.h"
#include <cstring>
#include <fstream>

using namespace std;
using namespace miniwin;

void pintar(const Pelota& P) {
   color((int) P.getColor());
   circulo_lleno(P.getX(), P.getY(), P.getRadio());
}

void pintar(const Pelotas& Pelotas){
    
    for(int i = 0; i< Pelotas.util; i++){
        pintar(Pelotas.v[i]);
    }
}

void pintar(const Simulador& partida, const int n){
    
    borra();
    pintar(partida.actual);
    refresca();
    espera(n);
            
}

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

void mover(Pelotas &Pelotas){
    const float factor = 0.97;
    
    for(int i = 0; i < Pelotas.util; i++){
      mover(Pelotas.v[i]);
    }
}

void intercambio(float& P1, float& P2){
    float aux;
    aux = P1;
    P1 = P2;
    P2 = aux;
}

void intercambio(PColor& P1, PColor& P2){
    PColor aux;
    aux = P1;
    P1 = P2;
    P2 = aux;
}

void colisionar(Pelota &P1, Pelota &P2){
        intercambio(P1.dx, P2.dx);
        intercambio(P1.dy, P2.dy);  
        //intercambio(P1.color, P2.color);
         
}

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

string ToString(PColor C){
    
    string sol;
    
    if(C == PColor::VERDE)
        sol = "VERDE";
    else
        sol = "ROJO";
    
    return sol;
}

PColor ToPColor(string C){
    
    PColor sol;
    
    if(C == "VERDE")
        sol = PColor::VERDE;
    else
        sol = PColor::ROJO;
    
    return sol;
}



istream& operator>>(istream& in, Pelota &P){
    
    string color_id;
    double x, y, dx, dy, radio;
    PColor color;
    
    in >> x >> y >> dx >> dy >> radio >> color_id;
    
    color = ToPColor(color_id);
    
    P.setPosicion(x,y);
    P.setVelocidad(dx,dy);
    P.setRadio(radio);
    P.setColor(color);
    
    return in;
    
}

istream& operator>>(istream& in, Pelotas &PV){
   
    Pelota P;
    int tam;
    
    in >> tam;
    for (int i = 0; i < tam; i++){
        in >> P;
        PV += P;
    }
    
    return in;
}

ostream& operator<<(ostream& out, const Pelota& P){
    
    out << P.getX() << " " << P.getY() << " " << P.getVelX() << " " << P.getVelY() << " " << P.getRadio() << " " << ToString(P.getColor()) << endl;
    
    return out;
}

ostream& operator<<(ostream& out, const Pelotas& PV){
    
    out << PV.getUtil() << "\n";
    
    for(int i = 0; i < PV.getUtil(); i++)
        out << PV[i];
    
    return out;
} 

