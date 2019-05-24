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
#include "Simulador.h"

using namespace std;

void pintar(const pelota& P);

void pintar(const pelotas& pelotas);

void pintar(const simulador& partida, const int n);

void mover(pelota &P);

void mover(pelotas &pelotas);

void intercambio(float& P1, float& P2);

void intercambio(PColor& P1, PColor& P2);

void colisionar(pelota &P1, pelota &P2);

void colisionar(pelotas& PV);

void Add(const pelota &n1, pelotas &PV);


std::string ToString(PColor C);

PColor ToPColor(std::string C);

ostream& operator<<(ostream& out, const pelotas& PV);

ostream& operator<<(ostream& out, const pelota& P);

istream& operator>>(istream& in, pelotas &PV);

istream& operator>>(istream& in, pelotas &PV);

#endif /* UTILIDADES_H */

