//
//  SolucionNumerosDelRey.hpp
//  NumerosDelRey
//
//  Created by Rodri on 02/06/23.
//


#ifndef SolucionNumerosDelRey_hpp
#define SolucionNumerosDelRey_hpp

#include <stdio.h>
#include "Arbol.hpp"
#include "Agenda.hpp"
#include "Arbol_Binario.hpp"


using namespace std;


class SolucionNumerosDelRey //Clase que se encarga de ejecutar los algoritmos de b�squedas en cualquier grafo
{
public:
    SolucionNumerosDelRey();
    ~SolucionNumerosDelRey();
    
    bool busqueda_a_lo_ancho_multiples_soluciones(const vector <int> numeros, const int resultado_esperado_del_problema, vector<int>& nodos_encontrados);
    bool busqueda_en_profundidad_multiples_soluciones(const vector <int> numeros, const int resultado_esperado_del_problema, vector<int>& nodos_encontrados);
    string devuelve_la_solucion_encontrada(int nodo_encontrado) const;
    string devuelve_las_soluciones_encontradas(vector <int> nodo_encontrado) const;
    
    
private:
    vector <int> numeros_del_problema;
    vector <char> operadores = {'+','-','*','/'};
    Arbol arbol_de_busqueda;
    Agenda agenda;
    Arbol arbol_de_busqueda_combinaciones_de_operaciones_de_izquierda_a_derecha; //Arbol que crea combinaciones resguardando cada nivel ciertos elementos de la izquierda y modifica los que sobran (los de la derecha). El numero de caracteres inmutables lo determina el nivel del nodo al que se le sacan sus vecinos
    Agenda agenda_combinaciones_de_operaciones_de_izquierda_a_derecha;
    Arbol arbol_de_busqueda_combinaciones_de_operaciones_de_derecha_a_izquierda;//Arbol que crea combinaciones resguardando cada nivel ciertos elementos de la derecha y modifica los que sobran (los de la izquierda). El numero de caracteres inmutables lo determina el nivel del nodo al que se le sacan sus vecinos
    Agenda agenda_combinaciones_de_operaciones_de_derecha_a_izquierda;
    bool revisa_si_es_la_solucion(string nombre_del_nodo, const int resultado_del_problema) const;
    void devuelve_vecinos( tipo_nodo_del_arbol nodo_actual, vector <tipo_nodo_del_arbol> &vecinos) const;


};



#endif /* SolucionNumerosDelRey_hpp */
