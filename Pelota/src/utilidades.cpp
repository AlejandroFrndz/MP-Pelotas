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

using namespace miniwin;

void pintar(const Pelota& P) {
   color((int) P.GetColor());
   circulo_lleno(P.GetX(), P.GetY(), RADIO);
}

void pintar(const Pelotas& Pelotas){
    
    for(int i = 0; i< Pelotas.util; i++){
        pintar(Pelotas.v[i]);
    }
}

void mover(Pelota &P) {
   const float factor = 0.97;
   
   P.mover();
  
   if (P.GetX() > vancho() - RADIO) {
      P.SetVelocidad(-P.GetVelX()*factor, P.GetVelY());
      P.SetPosicion(vancho()-RADIO, P.GetY());
   } 
   else if (P.GetX() < RADIO) {
      P.SetVelocidad(-P.GetVelX()*factor, P.GetVelY());
      P.SetPosicion(RADIO, P.GetY());
   } 
   else if (P.GetY() > valto() - RADIO) {
      P.SetVelocidad(P.GetVelX(), -P.GetVelY()*factor);
      P.SetPosicion(P.GetX(), valto() - RADIO);
   } 
   else if (P.GetY() < RADIO) {
      P.SetVelocidad(P.GetVelX(), -P.GetVelY()*factor);
      P.SetPosicion(P.GetX(), RADIO);
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
    
    if(P1.colisionado(P2)){
        intercambio(P1.dx, P2.dx);
        intercambio(P1.dy, P2.dy);
        intercambio(P1.color, P2.color);
    }
}

void colisionar(Pelotas& PV){
    
    for(int i = 0; i < PV.util; i++){
       
        for(int j = 0; j < PV.util; j++){
            
            if(i != j)
                colisionar(PV.v[i], PV.v[j]);
        }
        
    }
    
}

