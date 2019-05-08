/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alejandro
 *
 * Created on 2 de mayo de 2019, 18:00
 */

#include <cstdlib>
#include "Pelota.h"
#include "utilidades.h"
#include "definiciones.h"
#include "miniwin.h"

using namespace miniwin;
using namespace std;
 
int main() {
    
   vredimensiona(MIN_X, MIN_Y);
   
   Pelota P(0,0), P1(800,600), P2(300,300), P3(500,100), P4;
   Pelotas PV;
   
   P.SetColor(PColor::BLANCO);
   P2.SetColor(PColor::MAGENTA);
   P3.SetColor(PColor::CYAN);
   P.SetVelocidad(-20,-20);
   P1.SetVelocidad(10,10);
   P2.SetVelocidad(10, -20);
   P3.SetVelocidad(-20,15);
   P4.SetColor(PColor::AMARILLO);
   
   PV.MeterPelota(P);
   PV.MeterPelota(P1);
   PV.MeterPelota(P2);
   PV.MeterPelota(P3);
   PV.MeterPelota(P4);

   while (tecla() != ESCAPE) {
      borra();
      mover(PV);
      colisionar(PV);
      pintar(PV);
      refresca();
      espera(25);
   }
   
   vcierra();
   
    return 0;
}

