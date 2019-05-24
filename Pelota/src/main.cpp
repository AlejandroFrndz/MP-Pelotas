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
    pelotas PV;
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

int main(){
    simulador partida("data/datos.txt");
    
    while(tecla()!= ESCAPE){
        partida.step(5);
        pintar(partida,25);
    }
    
     partida.salvar("data/vector_final.txt");
    
    pelotas local = partida.getActual();
    cout <<"estado final: \n";
    cout << local;
    
    /*pelota p1 = partida.getOriginal()[0];
    pelota p2 = partida.getActual()[0];
    
    cout << p1<< "\n"<<p2<<"\n";
    if(p1==p2)
        cout << "Iguales\n";
    else
        cout << "Diferentes\n";*/
    return 0;
    
}




