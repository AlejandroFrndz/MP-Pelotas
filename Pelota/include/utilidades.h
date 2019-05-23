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
#include <string>

using namespace std;

void pintar(const Pelota& P);

void pintar(const Pelotas& Pelotas);

void mover(Pelota &P);

void mover(Pelotas &Pelotas);

void intercambio(float& P1, float& P2);

void intercambio(PColor& P1, PColor& P2);

void colisionar(Pelota &P1, Pelota &P2);

void colisionar(Pelotas& PV);

void Add(const Pelota &n1, Pelotas &PV);


std::string ToString(PColor C);

PColor ToPColor(std::string C);

std::istream& operator>>(std::istream& is, Pelotas & PV);

ostream& operator<<(ostream & salida, const Pelotas &PV);

#endif /* UTILIDADES_H */

