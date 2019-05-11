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
    string cabecera;
    Pelotas PV;
    int screenx, screeny;
    
    fin.open("./data/datos.txt");
    
    if(fin.is_open()){
    
        fin >> cabecera;
    
        if(cabecera == "MP−PELOTAS−T−1.0"){
        
            Pelota P;
            double x, y, dx, dy, radio;
            int tam, color_id;
            PColor color;
        
            fin >> screenx;
            fin >> screeny;
            fin >> tam;
        
            for(int i = 0; i < tam; i++){
            
                fin >> x >> y >> dx >> dy >> radio >> color_id;
            
                switch(color_id){
                
                    case 0 : color = PColor::NEGRO; break;
                    case 1 : color = PColor::ROJO; break;
                    case 2 : color = PColor::VERDE; break;
                    case 3 : color = PColor::AZUL; break;
                    case 4 : color = PColor::AMARILLO; break;
                    case 5 : color = PColor::MAGENTA; break;
                    case 6 : color = PColor::CYAN; break;
                    case 7 : color = PColor::BLANCO; break;
                }
            
                P.SetPosicion(x,y);
                P.SetVelocidad(dx,dy);
                P.SetColor(color);
            
                PV.MeterPelota(P);
            }
    
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
   
            vcierra();
   
        }
        
        else
            cout << "Cabecera del archivo de configuración incorrecta. Abortando ejecución";
    }
    
    else
        cout << "Error en la apertura del archivo de conifguración";
    
    return 0;
}


