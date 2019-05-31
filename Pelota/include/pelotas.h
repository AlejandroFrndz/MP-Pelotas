/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pelotas.h
 * Author: alejandro
 *
 * Created on 2 de mayo de 2019, 18:40
 */

//Alumno1: Fernández Alcaide Alejandro
//Alumno2: Aparcio Martos Francisco José

#ifndef PELOTAS_H
#define PELOTAS_H

#include "pelota.h"

class Pelotas{
private :
    Pelota *v; //vector de Pelotas
    int capacidad;
    int util;
public:
    //Constructores
    Pelotas();
    Pelotas(int cap, int ut);
    Pelotas(const Pelotas& PS);
    //Destructor
    ~Pelotas();
    //Consultores
    int getCapacidad() const;
    int getUtil() const;
    //Métodos
    void Matar(int i);
    void Nacer(float radio);
    void Realojar();
    //Operadores
    void operator+=(const Pelota &n1);
    Pelotas& operator=(const Pelotas& PS);
    Pelota& operator[](int i);
    const Pelota operator[](int i) const;
    //Funciones externas
    friend void mover(Pelotas &P);
    friend void pintar(const Pelotas& Pelotas);
    friend void colisionar(Pelotas& PV);
};

#endif /* PELOTAS_H */