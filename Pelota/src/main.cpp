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

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

#include "definiciones.h"
#include "pelota.h"
#include "pelotas.h"
#include "miniwin.h"
#include "simulador.h"
#include "utilidades.h"

using namespace miniwin;

// usa la clase Simulador y sobrecarga de operadores

int main() {
    
    srand(time(0));
    
   Simulador partida("data/pelotas.txt");

   while (tecla() != ESCAPE) {
      partida.step(1);
      pintar(partida,25);
   }   
   bool ok = partida.salvar("data/salida.txt");
   if (!ok)
       std::cerr << "error de escritura";
   
   // probando la sobrecarga de << de Pelotas
   Pelotas local = partida.getActual();
   std::cout << "estado final: \n";
   std::cout << local;
   Pelota p1 = partida.getOriginal()[0];
   Pelota p2 = partida.getActual()[0];
      std::cout << p1 << "\n" <<  p2 << "son ";
   if (p1==p2)
       std::cout << "iguales \n";
   else
       std::cout << "diferentes \n";
   return 0;
}