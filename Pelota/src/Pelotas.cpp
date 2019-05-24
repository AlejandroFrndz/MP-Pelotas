/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pelotas.cpp
 * Author: alejandro
 * 
 * Created on 2 de mayo de 2019, 18:40
 */

#include "Pelotas.h"

pelotas::pelotas(){
    capacidad = 0;
    util = 0;
    v = 0;
}

pelotas::pelotas(int cap, int ut){
    capacidad = cap;
    util = ut;
    v = new pelota [capacidad];
}

pelotas::pelotas(const pelotas& PS){
    
    capacidad = PS.capacidad;
    util = PS.util;
    
    v = new pelota [capacidad];
    
    for(int i = 0; i < util; i++)
    {
        v[i] = PS.v[i];
    }
}

pelotas::~pelotas(){
    v = 0;
    capacidad = 0;
    util = 0;
    delete [] v;
}

int pelotas::getCapacidad() const{
    return capacidad;
    
}
int pelotas::getUtil() const{
    return util;
}

void pelotas::Borrarpelota(int i){
    for (int j = i; j < capacidad-1; j++){
        v[j] = v[j+1];
    }
    
    capacidad = capacidad -1;
}

pelota& pelotas::getComponente(int i) const{
    return v[i];
}

void pelotas::operator+=(const pelota &n1){
    pelota *v1;
    
    if (util >= capacidad){
        Realojar();   
    }
    
    v[util] = n1;
    util++;
}

void pelotas::Matar(int i){
    
    for(int j = i; j < util-1; j++){
        v[j] = v[j+1];
    }
    
    util--;
   
}


void pelotas::Nacer(){
    pelota P;
    
    if(util < 100)
        *this+=P ;
    
}

void pelotas::Realojar(){
    pelota *v1;
    
    
    capacidad = (capacidad+1)*2;
    v1 = new pelota [capacidad];
        
    for (int i = 0; i < util; i++){
         v1[i] = v[i];
    }
        
    delete [] v;
    v = v1;    
    
}


pelotas& pelotas::operator=(const pelotas& PS){
    
    if(this != &PS){
        capacidad = PS.capacidad;
        util = PS.util;
        
        delete [] v;
        v = new pelota [capacidad];

        for(int i = 0; i < util; i++)
            v[i] = PS.v[i];
    }
    
    return *this;
}

pelota& pelotas::operator[](int i){
    return v[i];
}

const pelota& pelotas::operator[](int i) const{
    return v[i];
}

