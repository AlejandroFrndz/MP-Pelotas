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
#include <cstring>
#include <ctime>
#include "Pelota.h"
#include "utilidades.h"
#include "definiciones.h"
#include "miniwin.h"
#include "Simulador.h"

using namespace miniwin;
using namespace std;
 
/*int main() {
   
    ifstream fin;
    ofstream salida;
    string cabecera;
    int util_final;
    Pelotas PV;
    int screenx, screeny;
    
    
    
    
    
    
    
        //fin >> cabecera;
    
        if(cabecera == "MP−PELOTAS−T−1.0"){
            
            fin >> screenx;
            fin >> screeny;
            
            fin >> PV;
        
            fin.close();
        
            vredimensiona(screenx, screeny);
    
            while (tecla() != ESCAPE) {
                borra();
                mover(PV);
                colisionar(PV);
                pintar(PV);
                refresca();
                espera(25);
            }
            
            salida.open("./data/vector_final.txt");
            if(salida.is_open())
                salida << PV;
            
            salida.close();
   
            vcierra();
        }
        
        else
            cout << "Cabecera del archivo de configuración incorrecta. Abortando ejecución";
    }
    
    else
        cout << "Error en la apertura del archivo de conifguración";
    
   
    return 0;
}*/
/*
int main(){
    srand(time(0));
    Simulador partida("data/pelotas.txt");
    
    while(tecla()!= ESCAPE){
        partida.step(3);
        pintar(partida,25);
    }
    
    bool ok = partida.salvar("data/salida.txt");
    
    if(!ok)
        cout << "error de escritura";
    
    
    Pelotas local = partida.getActual();
    cout <<"estado final: \n";
    cout << local << "\n";
    
    Pelota p1 = partida.getOriginal()[0];
    Pelota p2 = partida.getActual()[0];
    
    
    
    cout << p1 << "\n" << p2 << "\n";
    
   
    
    if(p1==p2)
        cout << "Iguales\n";
    else
        cout << "Diferentes\n";
    return 0;
    
}
*/



// usa la clase Simulador y sobrecarga de operadores

int main() {

   Simulador partida("data/pelotas.txt");

   while (tecla() != ESCAPE) {
      partida.step(100);
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

