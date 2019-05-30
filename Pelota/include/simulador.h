/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Simulador.h
 * Author: alejandro
 *
 * Created on 14 de mayo de 2019, 11:57
 */

//Alumno1: Fernández Alcaide Alejandro
//Alumno2: Aparcio Martos Francisco José

#ifndef SIMULADOR_H
#define SIMULADOR_H
#include "pelota.h"
#include "pelotas.h"
#include <cstring>
#include <iostream>
#include "miniwin.h"

using namespace std;

class Simulador {

private:
    int ancho, alto;
    Pelotas original;
    Pelotas actual;
    
public:
    //Constructor
    Simulador(const string direccion);
    //Detructor
    ~Simulador();
    //Consultores
    Pelotas getOriginal() const;
    Pelotas getActual() const;
    //Métodos
    bool salvar(const string &entrada);
    void step(const int n);
    //Funciones externas
    friend void pintar(const Simulador& partida, const int n);

};

#endif /* SIMULADOR_H */

