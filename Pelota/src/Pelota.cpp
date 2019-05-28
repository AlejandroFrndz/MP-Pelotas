/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pelota.cpp
 * Author: alejandro
 * 
 * Created on 30 de abril de 2019, 13:12
 */

#include "Pelota.h"
#include "definiciones.h"
#include "utilidades.h"
#include <cstdlib>
#include <cmath>

using namespace std;

Pelota::Pelota() {
    x = (rand() % 3840);
    y = (rand() % 2160);
    dx = (rand() % MAX_VEL);
    dy = (rand() % MAX_VEL);
    radio = 30;
    color = PColor::VERDE;
}

Pelota::Pelota(float X, float Y) {
    x = X;
    y = Y;
    dx = dy = 1.0;
    color = PColor::ROJO;
    radio = 40;
}

Pelota::Pelota(float tamanio) {
    x = 0;
    y = 0;
    dx = (rand() % MAX_VEL);
    dy = (rand() % MAX_VEL);
    color = PColor::VERDE;
    radio = tamanio;
}

float Pelota::getX() const{
    return x;
}

float Pelota::getY() const{
    return y;
}

float Pelota::getVelX() const{
    return dx;
}

float Pelota::getVelY() const{
    return dy;
}

float Pelota::getRadio() const{
    return radio;
}

PColor Pelota::getColor() const{
    return color;
}

void Pelota::setPosicion(float X, float Y){
    x = X;
    y = Y;
}

void Pelota::setVelocidad(float DX, float DY){
    
    if(DX < MAX_VEL && DY < MAX_VEL)
    {
        dx = DX;
        dy = DY;
    }
}

void Pelota::setColor(PColor COLOR){
    
    color = COLOR;
}

void Pelota::setRadio(float r){
    radio = r;
}

float Pelota::distancia(const Pelota &n2){
    return sqrt(pow(x-n2.getX(),2)+pow(y-n2.getY(),2));
}

bool Pelota::colisionado(const Pelota &n2){
    return this->distancia(n2) < getRadio() + n2.getRadio() + UMBRAL;
}

void Pelota::mover(){
    this->setPosicion(x+dx,y+dy);
}

bool Pelota::operator==(const Pelota &P2) const{
    return (ToString(color) == ToString(P2.color) && radio == P2.radio);
}
  
