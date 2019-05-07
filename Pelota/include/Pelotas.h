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

#ifndef PELOTAS_H
#define PELOTAS_H

#include "Pelota.h"

class Pelotas{
private :
    Pelota *v; //vector de pelotas
    int capacidad;
    int util;
public:
    Pelotas();
    Pelotas(int cap, int ut);
    Pelotas(const Pelotas& PS);
    ~Pelotas();
    void SetCapacidad(int cap);
    int GetCapacidad() const;
    int GetUtil() const;
    void BorrarPelota(int i);
    void MeterPelota(const Pelota &n1);
    Pelota GetComponente(int i) const;
    friend void mover(Pelotas &P);
    friend void pintar(const Pelotas& Pelotas);
    friend void colisionar(Pelotas& PV);
    void Colisionar(int id);
};

#endif /* PELOTAS_H */

