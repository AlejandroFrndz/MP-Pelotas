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

#include "Simulador.h"
#include <iostream>
#include "Pelota.h"
#include "Pelotas.h"
#include "utilidades.h"
#include <fstream>
#include <cstring>
#include "miniwin.h"

using namespace std;
using namespace miniwin;

Simulador::Simulador(const string direccion){
    
    ifstream fin;
    string cabecera;
    
    fin.open(direccion);
    
    if(fin.is_open()){
    
        fin >> cabecera;
    
        if(cabecera == "MP−PELOTAS−T−1.0"){
            
            fin >> ancho;
            fin >> alto;
            
            fin >> original;
        
            fin.close();
        
            vredimensiona(ancho, alto);
           
      }
   }
    
    actual = original;
}

Simulador::~Simulador() {
    vcierra();
    ancho = 0;
    alto = 0;
}

bool Simulador::salvar(const string &entrada){
    
    bool salvado = false;
    ofstream salida;
    
    salida.open(entrada);
    
    if(salida.is_open()){
        salida << "MP−PELOTAS−T−1.0" << "\n";
        salida << alto << "\n";
        salida << ancho << "\n";
        //salida << actual.getUtil() << endl;
        salida << actual;

        salida.close();
        
        salvado = true;
    }
    
    return salvado;   
}

Pelotas Simulador::getOriginal(){
    return original;
}

Pelotas Simulador::getActual(){
    return actual;
}

void Simulador::step(const int n){
    
    for(int i = 0; i < n; i++){
        //borra();
        mover(actual);
        colisionar(actual);
    }
}

