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

#include "pelotas.h"
//Constructor por defecto
Pelotas::Pelotas(){
    capacidad = 0;
    util = 0;
    v = 0;
}
//Constructor con parametros de capacidad
Pelotas::Pelotas(int cap, int ut){
    capacidad = cap;
    util = ut;
    v = new Pelota [capacidad];
}
//Constructor de copia
Pelotas::Pelotas(const Pelotas& PS){
    
    capacidad = PS.capacidad;
    util = PS.util;
    
    v = new Pelota [capacidad];
    
    for(int i = 0; i < util; i++)
    {
        v[i] = PS.v[i];
    }
}
//Destructor
Pelotas::~Pelotas(){
    delete [] v;
    v = nullptr;
    capacidad = 0;
    util = 0;
}
//Consultor
int Pelotas::getCapacidad() const{
    return capacidad;
    
}
//Consultor
int Pelotas::getUtil() const{
    return util;
}
//Operador que añade una pelota al vector. Si es necesario, realoja en un nuevo vector con el doble de capacidad
void Pelotas::operator+=(const Pelota &n1){    
    if (util >= capacidad){
        this->Realojar();   
    }
    
    v[util] = n1;
    util++;
}
//Método que elimina una pelota del vector (Cuando colisiona una pelota verde con una roja
void Pelotas::Matar(int i){
    
    for(int j = i; j < util-1; j++){
        v[j] = v[j+1];
    }
    
    util--;
   
}
//Método que añade una pelota al vector (cuando colisionan 2 pelotas verdes) con atributos aleatorios y el radio de los padres
//Limitado a 50 pelotas por razones de eficiencia y espacio en pantalla
void Pelotas::Nacer(float radio){
    Pelota P;
    
    P.setRadio(radio);
    
    if(util < 50)
        *this+=P ;
    
}
//Método para aumentar la capacidad del vector
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
//Operador de asignación
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
//Operador de indexación (no const)
Pelota& Pelotas::operator[](int i){
    return v[i];
}
//Operador de asignación (const)
const Pelota Pelotas::operator[](int i) const{
    return v[i];
}
