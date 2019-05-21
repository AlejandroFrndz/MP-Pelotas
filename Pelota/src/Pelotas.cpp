/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pelotas.cpp
 * Author: alejandro
 * 
 * Created on 2 de mayo de 2019, 18:40
 */

#include "Pelotas.h"

Pelotas::Pelotas(){
    capacidad = 0;
    util = 0;
    v = 0;
}

Pelotas::Pelotas(int cap, int ut){
    capacidad = cap;
    util = ut;
    v = new Pelota [capacidad];
}

Pelotas::Pelotas(const Pelotas& PS){
    
    capacidad = PS.capacidad;
    util = PS.util;
    
    v = new Pelota [capacidad];
    
    for(int i = 0; i < util; i++)
    {
        v[i] = PS.v[i];
    }
}

Pelotas::~Pelotas(){
    v = 0;
    capacidad = 0;
    util = 0;
    delete [] v;
}

int Pelotas::GetCapacidad() const{
    return capacidad;
    
}
int Pelotas::GetUtil() const{
    return util;
}

void Pelotas::BorrarPelota(int i){
    for (int j = i; j < capacidad-1; j++){
        v[j] = v[j+1];
    }
    
    capacidad = capacidad -1;
}

Pelota& Pelotas::GetComponente(int i) const{
    return v[i];
}

void Pelotas::operator+=(const Pelota &n1){
    Pelota *v1;
    
    if (util >= capacidad){
        Realojar();   
    }
    
    v[util] = n1;
    util++;
}

void Pelotas::Matar(int i){
    
    for(int j = i; j < util-1; j++){
        v[j] = v[j+1];
    }
    
    util--;
}


void Pelotas::Nacer(){
    Pelota P;
    
    *this+=P ;
    
}

void Pelotas::Realojar(){
    Pelota *v1;
    
    
    capacidad = (capacidad+1)*2;
    v1 = new Pelota [capacidad];
        
    for (int i = 0; i < util; i++){
         v1[i] = v[i];
    }
        
    delete [] v;
    v = v1;    
    
}

Pelotas& Pelotas::operator=(const Pelotas& PS){
    
    if(this != &PS){
        capacidad = PS.capacidad;
        util = PS.util;
        
        delete [] v;
        v = new Pelota [capacidad];

        for(int i = 0; i < util; i++)
            v[i] = PS.v[i];
    }
    
    return *this;
}

Pelota& Pelotas::operator[](int i){
    return v[i];
}

const Pelota& Pelotas::operator[](int i) const{
    return v[i];
}