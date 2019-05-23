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

using namespace miniwin;
using namespace std;
 
int main() {
   
    ifstream fin;
    ofstream salida;
    string cabecera;
    int util_final;
    Pelotas PV;
    int screenx, screeny;
    
    fin.open("./data/datos.txt");
    
    if(fin.is_open()){
    
        fin >> cabecera;
    
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
}


