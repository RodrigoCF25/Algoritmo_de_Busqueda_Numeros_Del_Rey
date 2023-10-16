//
//  Agenda.cpp
//  NumerosDelRey
//
//  Created by Rodri on 02/06/23.
//

#include "Agenda.hpp"



using namespace std;

Agenda::Agenda()
{
    tamano_maximo_agenda = 0;
}

Agenda::~Agenda()
{
}

void Agenda::push_back(unsigned int numero_del_nodo_en_el_arbol)
{
    agenda.push_back(numero_del_nodo_en_el_arbol);
}

void Agenda::push_front(unsigned int numero_del_nodo_en_el_arbol)
{
    agenda.insert(agenda.begin(),numero_del_nodo_en_el_arbol);
}

unsigned int Agenda::front()
{
    return agenda.front();
}

unsigned int Agenda::back()
{
    return agenda.back();
}


void Agenda::pop_front()
{
    agenda.erase(agenda.begin());
}

void Agenda::pop_back()
{
    agenda.erase(agenda.end()-1);
}

unsigned int Agenda::operator [] (unsigned int indice) const
{
    return agenda[indice];
}


void Agenda:: revisa_tamano_maximo_de_la_agenda()
{
    if(tamano_maximo_agenda < agenda.size())
        tamano_maximo_agenda = (unsigned int)agenda.size();
}

unsigned int Agenda::obten_tamano_maximo_de_la_agenda()
{
    return tamano_maximo_agenda;
}


bool Agenda::esta_vacia() const
{
    return agenda.empty();
}



void Agenda::limpia_agenda()
{
    tamano_maximo_agenda = 0;
    agenda.clear();
}


unsigned int Agenda::size() const
{
    return (unsigned int)agenda.size();
}

void Agenda::erase(unsigned int indice)
{
    agenda.erase(agenda.begin() + indice);
}

