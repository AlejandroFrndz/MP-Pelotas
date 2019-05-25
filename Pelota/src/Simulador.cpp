/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   simulador.cpp
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

simulador::simulador(const string direccion){
    
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

simulador::~simulador() {
    vcierra();
    ancho = 0;
    alto = 0;
}

bool simulador::salvar(const string &entrada){
    
    bool salvado = false;
    ofstream salida;
    
    salida.open(entrada);
    
    if(salida.is_open()){
        salida << actual;

        salida.close();
        
        salvado = true;
    }
    
    return salvado;   
}

pelotas simulador::getOriginal(){
    return original;
}

pelotas simulador::getActual(){
    return actual;
}

void simulador::step(const int n){
    
    for(int i = 0; i < n; i++){
        //borra();
        mover(actual);
        colisionar(actual);
    }
}

