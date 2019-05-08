/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   utilidades.h
 * Author: alejandro
 *
 * Created on 2 de mayo de 2019, 17:17
 */

#ifndef UTILIDADES_H
#define UTILIDADES_H

#include "Pelotas.h"
#include "Pelota.h"

void pintar(const Pelota& P);

void pintar(const Pelotas& Pelotas);

void mover(Pelota &P);

void mover(Pelotas &Pelotas);

void intercambio(float& P1, float& P2);

void intercambio(PColor& P1, PColor& P2);

void colisionar(Pelota &P1, Pelota &P2);

void colisionar(Pelotas& PV);


#endif /* UTILIDADES_H */

