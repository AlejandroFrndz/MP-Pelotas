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
#include <ctime>

using namespace std;

Pelota::Pelota() {
    
    srand(time(0));
    
    x = (rand() % 800);
    y = (rand() % 600);
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

float Pelota::GetX() const{
    return x;
}

float Pelota::GetY() const{
    return y;
}

float Pelota::GetVelX() const{
    return dx;
}

float Pelota::GetVelY() const{
    return dy;
}

float Pelota::GetRadio() const{
    return radio;
}

PColor Pelota::GetColor() const{
    return color;
}

void Pelota::SetPosicion(float X, float Y){
    x = X;
    y = Y;
}

void Pelota::SetVelocidad(float DX, float DY){
    
    if(DX < MAX_VEL && DY < MAX_VEL)
    {
        dx = DX;
        dy = DY;
    }
}

void Pelota::SetColor(PColor COLOR){
    
    color = COLOR;
}

void Pelota::SetRadio(float r){
    radio = r;
}

float Pelota::distancia(const Pelota &n2){
    return sqrt(pow(x-n2.GetX(),2)+pow(y-n2.GetY(),2));
}

bool Pelota::colisionado(const Pelota &n2){
    return this->distancia(n2) < GetRadio() + n2.GetRadio() + UMBRAL;
}

void Pelota::mover(){
    this->SetPosicion(x+dx,y+dy);
}

bool Pelota::operator==(const Pelota &P2) const{
    return (ToString(color) == ToString(P2.color) && radio == P2.radio);
}
  
