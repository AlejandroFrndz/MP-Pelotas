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

#include "pelota.h"
#include "definiciones.h"
#include "utilidades.h"
#include <cstdlib>
#include <cmath>

using namespace std;

//Constructor aleatorio por defecto
Pelota::Pelota(){
    x = (rand() % MAX_ANCHO);
    y = (rand() % MAX_ALTO);
    dx = (rand() % (MAX_VEL-1))+1;
    dy = (rand() % (MAX_VEL-1))+1;
    radio = MAX_RADIO;
    color = PColor::VERDE;
}
//Constructor con parámetros de posición
Pelota::Pelota(float X, float Y){
    x = X;
    y = Y;
    dx = dy = 1.0;
    color = PColor::ROJO;
    radio = 40;
}
//Consultor
float Pelota::getX() const{
    return x;
}
//Consultor
float Pelota::getY() const{
    return y;
}
//Consultor
float Pelota::getVelX() const{
    return dx;
}
//Consultor
float Pelota::getVelY() const{
    return dy;
}
//Consultor
float Pelota::getRadio() const{
    return radio;
}
//Consultor
PColor Pelota::getColor() const{
    return color;
}
//Modificador de posición. Se asegura de que las coordenadas están dentro de la pantalla de miniwin
void Pelota::setPosicion(float X, float Y){
    if(X >= 0 && X <= MAX_ANCHO)
        x = X;
    
    if(Y >= 0 && Y <= MAX_ALTO)
        y = Y;
}
//Modificador de velocidad. Se asegura de que la velocidad no supera el máximo establecido en definiciones.h
void Pelota::setVelocidad(float DX, float DY){
    
    if(DX <= MAX_VEL && DX >= -MAX_VEL)
        dx = DX;
    
    if(DY <= MAX_VEL && DY >= -MAX_VEL)
        dy = DY;
}
//Modificador de color. Se asegura de que el color es Rojo o Verde exclusivamente
void Pelota::setColor(PColor COLOR){
    if(COLOR == PColor::VERDE || COLOR == PColor::ROJO)
        color = COLOR;
}
//Modificador del radio. Se asegura de que este es positivo y menor que el radio máximo definido en definiciones.h
void Pelota::setRadio(float r){
    if(r > 0 || r <= MAX_RADIO)
        radio = r;
}
//Modificador de toda la pelota. Tiene en cuenta todas las restricciones anteriores
void Pelota::setPelota(float X, float Y, float DX, float DY, float R, PColor COLOR){
    
    if(X >= 0 && X <= MAX_ANCHO)
        x = X;
    
    if(Y >= 0 && Y <= MAX_ALTO)
        y = Y;
    
    if(DX >= -MAX_VEL && DX <= MAX_VEL)
        dx = DX;
    
    if(DY >= -MAX_VEL && DY <= MAX_VEL)
        dy = DY;
    
    if(R > 0 && R <= MAX_RADIO)
        radio = R;
    
    if(COLOR == PColor::VERDE || COLOR == PColor::ROJO)
        color = COLOR;
}
//Método que calcula y devuelve la distancia entre dos pelotas
float Pelota::distancia(const Pelota &n2){
    return sqrt(pow(x-n2.getX(),2)+pow(y-n2.getY(),2));
}
//Método que determina si 2 pelotas han colisionado cuando estas estan a una distancia 
//menor que la suma de sus radios más un umbraldefinido en definiciones.h
bool Pelota::colisionado(const Pelota &n2){
    return this->distancia(n2) < this->getRadio() + n2.getRadio() + UMBRAL;
}
//Método que cambia la posición de una pelota en función de su velocidad
void Pelota::mover(){
    this->setPosicion(x+dx,y+dy);
}
//Operador que compara si 2 pelotas son iguales en función de si lo son su color y su radio
bool Pelota::operator==(const Pelota &P2) const{
    return (ToString(color) == ToString(P2.color) && radio == P2.radio);
}