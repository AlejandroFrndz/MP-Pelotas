/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Simulador.cpp
 * Author: alejandro
 * 
 * Created on 14 de mayo de 2019, 11:57
 */

#include "simulador.h"
#include <iostream>
#include "pelota.h"
#include "pelotas.h"
#include "utilidades.h"
#include <fstream>
#include <cstring>
#include "miniwin.h"
#include "definiciones.h"

using namespace std;
using namespace miniwin;
//Constructor con parámetro una ruta de fichero que inicializa el simulador y abre la ventana de miniwin
//Se asegura de que el tamaño de la ventana no supera los máximos establecidos en definiciones.h
//En caso contrario, se crea una ventana de tamaño máximo
Simulador::Simulador(const string direccion){
    
    ifstream fin;
    string cabecera;
    
    fin.open(direccion);
    
    if(fin.is_open()){
        fin >> cabecera;
    
        if(cabecera == "MP-PELOTAS−T−1.0"){
            fin >> *this;
        
            fin.close();
        
            vredimensiona(ancho, alto);
      }
   }
}
//Destructor que cierra la ventana de miniwin
Simulador::~Simulador() {
    vcierra();
    ancho = 0;
    alto = 0;
}
//Método que salva el estado actual del vector de pelotas en un archivo
bool Simulador::salvar(const string &entrada){
    
    bool salvado = false;
    ofstream salida;
    
    salida.open(entrada);
    
    if(salida.is_open()){
        salida << *this;

        salida.close();
        
        salvado = true;
    }
    
    return salvado;   
}
//Consultor
Pelotas Simulador::getOriginal() const{
    return original;
}
//Consultor
Pelotas Simulador::getActual() const{
    return actual;
}
//Consultor
int Simulador::getAncho() const{
    return ancho;
}
//Consultor
int Simulador::getAlto() const{
    return alto;
}
//Método step
void Simulador::step(const int n){
    
    for(int i = 0; i < n; i++){
        mover(actual);
        colisionar(actual);
    }
}
//Modificador del tamaño de la ventana de miniwin. Se asegura que se recibe un tamaño válido
//que no supera el máximo establecido en definiciones.h
void Simulador::SetScreen(int anch, int alt){
    if(anch > 0 && anch <= MAX_ANCHO)
        ancho = anch;
    else
        ancho = MAX_ANCHO;
                
    if(alt > 0 && alt <= MAX_ALTO)
        alto = alt;
    else
        alto = MAX_ALTO;
}
//Modificador del vector de pelotas original usado en la lectura de Simulador
void Simulador::SetOriginal(const Pelotas& PV){
    original = PV;
}
//Modificador del vector de pelotas actual usado en la lectura de Simulador
void Simulador::SetActual(const Pelotas& PV){
    actual = PV;
}
