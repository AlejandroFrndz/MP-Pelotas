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
#include <fstream>
#include "Pelota.h"
#include "Pelotas.h"
#include "utilidades.h"
#include "definiciones.h"
#include "miniwin.h"

using namespace miniwin;
using namespace std;

/*
 * 

int main() {

   
   
   Pelota P; 
   Pelotas Ps;
   ifstream fentrada;
   string cabecera;
   float dx , dy, x , y;
   int capacidad, ancho, alto;
   
   
   fentrada.open("data/datos.txt");
   fentrada >> cabecera;
   
   if (cabecera == "MP-PELOTAS-T-1.0"){
       fentrada >> ancho;
       fentrada >> alto;
       vredimensiona(ancho, alto);
       
       fentrada >> capacidad;
       Ps.SetCapacidad(capacidad);
       
       for (int i = 0; i < capacidad; i++){
           fentrada >> x;
           fentrada >> y;
           fentrada >> dx;
           fentrada >> dy;
           
           P.SetPosicion(x,y);
           P.SetVelocidad(dx , dy);
           
           Ps.MeterPelota(P);
       }
       
       fentrada.close();
   }

   while (tecla() != ESCAPE) {
      borra();
      for (int i = 0; i < Ps.GetUtil(); i++){
          mover(Ps);
          pintar(Ps);
      }
      
      refresca();
      espera(25);
   }
   
   vcierra();
   
    return 0;
}
*/


#include <cstdlib>
#include "Pelota.h"
#include "utilidades.h"
#include "definiciones.h"
#include "miniwin.h"

using namespace miniwin;
 
int main() {
    
   vredimensiona(800, 600);
   
   Pelota P(0,0), P1(800,600), P2(300,300), P3(500,100);
   Pelotas PV;
   
   P.SetColor(PColor::BLANCO);
   P2.SetColor(PColor::MAGENTA);
   P3.SetColor(PColor::CYAN);
   P.SetVelocidad(-20,-20);
   P1.SetVelocidad(10,10);
   P2.SetVelocidad(10, -20);
   P3.SetVelocidad(-20,15);
   
   PV.MeterPelota(P);
   PV.MeterPelota(P1);
   PV.MeterPelota(P2);
   PV.MeterPelota(P3);

   while (tecla() != ESCAPE) {
      borra();
      mover(PV);
      //mover(P);
      //mover(P1);
      //colisionar(P,P1);
     
      for(int i = 0; i < PV.GetUtil(); i++){
          PV.Colisionar(i);
      }
     
      pintar(PV);
      //pintar(P1);
      //pintar(P);
      refresca();
      espera(25);
   }
   
   vcierra();
   
    return 0;
}

