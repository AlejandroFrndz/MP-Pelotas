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
   color((int) P.GetColor());
   circulo_lleno(P.GetX(), P.GetY(), P.GetRadio());
}

void pintar(const Pelotas& Pelotas){
    
    for(int i = 0; i< Pelotas.util; i++){
        pintar(Pelotas.v[i]);
    }
}

void mover(Pelota &P) {
   const float factor = 0.97;
   
   P.mover();
  
   if (P.GetX() > vancho() - P.GetRadio()) {
      P.SetVelocidad(-P.GetVelX()*factor, P.GetVelY());
      P.SetPosicion(vancho()-P.GetRadio(), P.GetY());
   } 
   else if (P.GetX() < P.GetRadio()) {
      P.SetVelocidad(-P.GetVelX()*factor, P.GetVelY());
      P.SetPosicion(P.GetRadio(), P.GetY());
   } 
   else if (P.GetY() > valto() - P.GetRadio()) {
      P.SetVelocidad(P.GetVelX(), -P.GetVelY()*factor);
      P.SetPosicion(P.GetX(), valto() - P.GetRadio());
   } 
   else if (P.GetY() < P.GetRadio()) {
      P.SetVelocidad(P.GetVelX(), -P.GetVelY()*factor);
      P.SetPosicion(P.GetX(), P.GetRadio());
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
                
                    if(P1.GetColor() == PColor::VERDE){
                        if(PV.util < 30)
                            PV.Nacer();
                        colisionar(PV.v[i], PV.v[j]);
                        chocado = true;
                    }

                    if(P1.GetColor() == PColor::ROJO){
                      colisionar(PV.v[i], PV.v[j]);
                       chocado = true;
                     }
                }

                else{
                    
                    if(P1.GetColor() == PColor::ROJO)
                            PV.Matar(j);


                    if (P2.GetColor() == PColor::ROJO )
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

istream& operator>>(istream& in, Pelota &P){
    
    string color_id;
    double x, y, dx, dy, radio;
    PColor color;
    
    in >> x >> y >> dx >> dy >> radio >> color_id;
    
    color = ToPColor(color_id);
    
    P.SetPosicion(x,y);
    P.SetVelocidad(dx,dy);
    P.SetRadio(radio);
    P.SetColor(color);
    
    return in;
    
}

ostream& operator<<(ostream& out, const Pelotas& PV){
    
    out << PV.GetUtil();
    
    for(int i = 0; i < PV.GetUtil(); i++)
        out << PV[i];
    
    return out;
} 

ostream& operator<<(ostream& out, const Pelota& P){
    
    out << P.GetX() << " " << P.GetY() << " " << P.GetVelX() << " " << P.GetVelY() << " " << P.GetRadio() << " " << ToString(P.GetColor()) << endl;
}