/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pelota.h
 * Author: alejandro
 *
 * Created on 30 de abril de 2019, 13:12
 */

#ifndef PELOTA_H
#define PELOTA_H

#include "definiciones.h"
enum class PColor {
    NEGRO, ROJO, VERDE, AZUL,
    AMARILLO, MAGENTA, CYAN, BLANCO
};

class pelota {
    private:
    float x;
    float y;
    float dx;
    float dy;
    float radio;
    PColor color;
    
public:
    pelota();
    pelota(float X, float Y);
    float getX() const;
    float getY() const;
    float getVelX() const;
    float getVelY() const;
    float getRadio() const;
    PColor getColor() const;
    void setPosicion(float X, float Y);
    void setVelocidad(float DX, float DY);
    void setColor(PColor COLOR);
    void setRadio(float r);
    float distancia(const pelota &n2);
    bool colisionado(const pelota &n2);
    void mover();
    friend void colisionar(pelota &P1, pelota &P2);
    bool operator==(const pelota &P2) const;
};

#endif /* PELOTA_H */

