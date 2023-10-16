//
//  Arbol.hpp
//  NumerosDelRey
//
//  Created by Rodri on 02/06/23.
//



#ifndef Arbol_hpp
#define Arbol_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;



struct tipo_nodo_del_arbol //Guarda la informacion interna del nodo, quien es su padre y quienes sus hijos
{
    string nombre_del_nodo = ""; //Guarda el orden de las operaciones. Ej: "++*/"
    unsigned int nivel_de_profundidad = 0;
    int padre = -1;
    vector<int> hijos;
};


class Arbol //Clase que se encarga de manejar el arbol de b�squeda
{
public:
    Arbol();
    ~Arbol();
    void crea_arbol(tipo_nodo_del_arbol contenido);
    void agrega_hijo_a_un_nodo_del_arbol(int padre, tipo_nodo_del_arbol hijo);
    void push_back(tipo_nodo_del_arbol nodo);
    void limpia_arbol();
    bool esta_un_nodo_en_ancestros(unsigned int nodo_actual, string nombre_del_nodo) const;
    unsigned int size() const;
    tipo_nodo_del_arbol operator [] (unsigned int indice) const;
    void erase(unsigned int indice);
    


private:
    vector <tipo_nodo_del_arbol> arbol;
};


#endif /* Arbol_hpp */
