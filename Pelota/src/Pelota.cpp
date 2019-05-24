/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pelota.cpp
 * Author: alejandro
 * 
 * Created on 30 de abril de 2019, 13:12
 */

#include "Pelota.h"
#include "definiciones.h"
#include "utilidades.h"
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

pelota::pelota() {
    
    srand(time(0));
    
    x = (rand() % 800);
    y = (rand() % 600);
    dx = (rand() % MAX_VEL);
    dy = (rand() % MAX_VEL);
    radio = 30;
    color = PColor::VERDE;
}

pelota::pelota(float X, float Y) {
    x = X;
    y = Y;
    dx = dy = 1.0;
    color = PColor::ROJO;
    radio = 40;
}

float pelota::getX() const{
    return x;
}

float pelota::getY() const{
    return y;
}

float pelota::getVelX() const{
    return dx;
}

float pelota::getVelY() const{
    return dy;
}

float pelota::getRadio() const{
    return radio;
}

PColor pelota::getColor() const{
    return color;
}

void pelota::setPosicion(float X, float Y){
    x = X;
    y = Y;
}

void pelota::setVelocidad(float DX, float DY){
    
    if(DX < MAX_VEL && DY < MAX_VEL)
    {
        dx = DX;
        dy = DY;
    }
}

void pelota::setColor(PColor COLOR){
    
    color = COLOR;
}

void pelota::setRadio(float r){
    radio = r;
}

float pelota::distancia(const pelota &n2){
    return sqrt(pow(x-n2.getX(),2)+pow(y-n2.getY(),2));
}

bool pelota::colisionado(const pelota &n2){
    return this->distancia(n2) < getRadio() + n2.getRadio() + UMBRAL;
}

void pelota::mover(){
    this->setPosicion(x+dx,y+dy);
}

bool pelota::operator==(const pelota &P2) const{
    return (ToString(color) == ToString(P2.color) && radio == P2.radio);
}
  
