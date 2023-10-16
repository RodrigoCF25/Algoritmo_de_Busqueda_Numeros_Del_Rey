//
//  Arbol.cpp
//  NumerosDelRey
//
//  Created by Rodri on 02/06/23.
//


#include "Arbol.hpp"

using  namespace::std;


Arbol::Arbol()
{

}

Arbol::~Arbol()
{

}

void Arbol::crea_arbol(tipo_nodo_del_arbol nodo)
{
    nodo.nombre_del_nodo = "";
    nodo.nivel_de_profundidad = 0;
    nodo.padre = -1;
    arbol.push_back(nodo);
}

void Arbol::agrega_hijo_a_un_nodo_del_arbol(int padre, tipo_nodo_del_arbol hijo)
{

    hijo.nivel_de_profundidad = arbol[padre].nivel_de_profundidad + 1;
    hijo.padre = padre;
    arbol.push_back(hijo);
    arbol[padre].hijos.push_back((unsigned int)arbol.size() - 1);
}

void Arbol::push_back(tipo_nodo_del_arbol nodo)
{
    arbol.push_back(nodo);
}




void Arbol::limpia_arbol()
{
    arbol.clear();
}

/*
bool Arbol::esta_un_nodo_en_ancestros(unsigned int nodo_actual, string nombre_del_nodo) const
{
    int temporal = arbol[nodo_actual].padre;
    while (temporal != -1) {
        if (arbol[temporal].nombre_del_nodo == nombre_del_nodo)
            return true;
        temporal = arbol[temporal].padre;
    }
    return false;
}
 */


bool Arbol::esta_un_nodo_en_ancestros(unsigned int nodo_actual, string nombre_del_nodo) const
{
    for(unsigned int i = 0; i < arbol.size();i++)
        if(arbol[i].nombre_del_nodo == nombre_del_nodo && arbol[nodo_actual].nivel_de_profundidad == arbol[i].nivel_de_profundidad)
            return true;
    return false;
}


unsigned int Arbol::size() const
{
    return (unsigned int)arbol.size();
}


tipo_nodo_del_arbol Arbol::operator [] (unsigned int indice) const
{
    return arbol[indice];
}


void Arbol::erase(unsigned int indice)
{
    arbol.erase(arbol.begin() + indice);
}


