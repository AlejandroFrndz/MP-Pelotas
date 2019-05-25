/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pelotas.h
 * Author: alejandro
 *
 * Created on 2 de mayo de 2019, 18:40
 */

//Alumno1: Fernández Alcaide Alejandro
//Alumno2: Aparcio Martos Francisco José

#ifndef PELOTAS_H
#define PELOTAS_H

#include "Pelota.h"

class pelotas{
private :
    pelota *v; //vector de pelotas
    int capacidad;
    int util;
public:
    //Constructores
    pelotas();
    pelotas(int cap, int ut);
    pelotas(const pelotas& PS);
    //Destructor
    ~pelotas();
    //Consultores
    int getCapacidad() const;
    int getUtil() const;
    //Métodos
    void Matar(int i);
    void Nacer();
    void Realojar();
    //Operadores
    void operator+=(const pelota &n1);
    pelotas& operator=(const pelotas& PS);
    pelota& operator[](int i);
    const pelota& operator[](int i) const;
    //Funciones externas
    friend void mover(pelotas &P);
    friend void pintar(const pelotas& pelotas);
    friend void colisionar(pelotas& PV);
};

#endif /* PELOTAS_H */

