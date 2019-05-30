/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Simulador.cpp
 * Author: alejandro
 * 
 * Created on 14 de mayo de 2019, 11:57
 */

#include "simulador.h"
#include <iostream>
#include "pelota.h"
#include "pelotas.h"
#include "utilidades.h"
#include <fstream>
#include <cstring>
#include "miniwin.h"
#include "definiciones.h"

using namespace std;
using namespace miniwin;
//Constructor con parámetro una ruta de fichero que inicializa el simulador y abre la ventana de miniwin
//Se asegura de que el tamaño de la ventana no supera los máximos establecidos en definiciones.h
//En caso contrario, se crea una ventana de tamaño máximo
Simulador::Simulador(const string direccion){
    
    ifstream fin;
    string cabecera;
    
    fin.open(direccion);
    
    if(fin.is_open()){
    
        fin >> cabecera;
    
        if(cabecera == "MP−PELOTAS−T−1.0"){
            
            fin >> ancho;
            if(ancho < 0 || ancho > MAX_ANCHO)
                ancho = MAX_ANCHO;
            fin >> alto;
            if(alto < 0 || alto > MAX_ALTO)
                alto = MAX_ALTO;
            
            fin >> original;
        
            fin.close();
        
            vredimensiona(ancho, alto);
           
      }
   }
    
    actual = original;
}
//Destructor que cierra la ventana de miniwin
Simulador::~Simulador() {
    vcierra();
    ancho = 0;
    alto = 0;
}
//Método que salva el estado actual del vector de pelotas en un archivo
bool Simulador::salvar(const string &entrada){
    
    bool salvado = false;
    ofstream salida;
    
    salida.open(entrada);
    
    if(salida.is_open()){
        salida << "MP−PELOTAS−T−1.0" << "\n";
        salida << ancho << "\n";
        salida << alto << "\n";
        salida << actual;

        salida.close();
        
        salvado = true;
    }
    
    return salvado;   
}
//Consultor
Pelotas Simulador::getOriginal() const{
    return original;
}
//Consultor
Pelotas Simulador::getActual() const{
    return actual;
}
//Métodod step
void Simulador::step(const int n){
    
    for(int i = 0; i < n; i++){
        mover(actual);
        colisionar(actual);
    }
}

