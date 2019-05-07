/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pelota.h
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

class Pelota {
public:
    Pelota();
    Pelota(float X, float Y);
    float GetX() const;
    float GetY() const;
    float GetVelX() const;
    float GetVelY() const;
    float GetRadio() const;
    PColor GetColor() const;
    void SetPosicion(float X, float Y);
    void SetVelocidad(float DX, float DY);
    void SetColor(PColor COLOR);
    float distancia(const Pelota &n2);
    bool colisionado(const Pelota &n2);
    void mover();
    friend void colisionar(Pelota &P1, Pelota &P2);
private:
    float x;
    float y;
    float dx;
    float dy;
    constexpr static const float radio = RADIO;
    PColor color;
};

#endif /* PELOTA_H */

