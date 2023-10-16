//
//  Agenda.hpp
//  NumerosDelRey
//
//  Created by Rodri on 02/06/23.
//


#ifndef Agenda_hpp
#define Agenda_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

class Agenda //Clase que se encarga de manejar la agenda de los algoritmos de b˙squeda
{
public:
    Agenda();
    ~Agenda();
    void push_back(unsigned int numero_del_nodo_en_el_arbol);
    void push_front(unsigned int numero_del_nodo_en_el_arbol);
    unsigned int front();
    unsigned int back();
    void pop_front();
    void pop_back();
    unsigned int operator [] (unsigned int indice) const;
    bool esta_vacia() const;
    void limpia_agenda();
    unsigned int size() const;
    void erase(unsigned int indice);
    void revisa_tamano_maximo_de_la_agenda();
    unsigned int obten_tamano_maximo_de_la_agenda();
    
    
private:
    vector <unsigned int> agenda;
    unsigned int tamano_maximo_agenda;
    
};


#endif /* Agenda_hpp */
