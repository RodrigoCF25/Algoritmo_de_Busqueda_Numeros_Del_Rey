//
//  SolucionNumerosDelRey.cpp
//  NumerosDelRey
//
//  Created by Rodri on 02/06/23.
//


#include "SolucionNumerosDelRey.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stddef.h>
#include <ctime>
#include <algorithm>
#include <cmath>



using namespace::std;

#pragma warning(disable : 6011)

SolucionNumerosDelRey::SolucionNumerosDelRey()
{
}
//---------------------------------------------------------------------------------------------------------------

SolucionNumerosDelRey::~SolucionNumerosDelRey()
{

}


void SolucionNumerosDelRey::devuelve_vecinos(tipo_nodo_del_arbol nodo_actual, vector <tipo_nodo_del_arbol> &vecinos) const
{
    vecinos.clear();
    tipo_nodo_del_arbol vecino;
    
    string operadores_al_reves = "";
    
    if(nodo_actual.padre != -1) //vecinos de un hijos
    {
        for (unsigned int i = 0; i < operadores.size();i++)
        {
            vecino.nombre_del_nodo = nodo_actual.nombre_del_nodo;
            for (unsigned int j = nodo_actual.nivel_de_profundidad; j < numeros_del_problema.size()-1;j++) //la profundidad del nodo al que sacamos vecinos, es el numero de indices que no son modificados de izquierda a derecha, los que restan se modifican, para ir obteniendo diferentes coombinaciones a la larga (estilo algo factorial)
                vecino.nombre_del_nodo[j] = operadores[i];
            
            vecinos.push_back(vecino);
            
        }
        
        
    }
    else //vecinos del nodo raiz
    {
        //Queremos obtener los vecinos principales : todo suma, todo resta, todo multiplicacion, todo division
        for(unsigned int i = 0; i < operadores.size();i++)
        {
            vecino.nombre_del_nodo = "";
            for (unsigned int j = 0; j < numeros_del_problema.size()-1;j++)
                vecino.nombre_del_nodo += operadores[i];
            
            vecinos.push_back(vecino);
        }
    }
    
}




bool SolucionNumerosDelRey::revisa_si_es_la_solucion(string nombre_del_nodo, const int resultado_del_problema) const
{

    if (nombre_del_nodo != "")
    {
        vector <int> cola;
        vector <int> numeros = numeros_del_problema;
        string operaciones_a_realizar = nombre_del_nodo;
        char operacion_a_realizar = ' ';
        
        int res_temporal = 0;
        while(operaciones_a_realizar.length() != 0)
        {
            while(cola.size()!= 2)
            {
                cola.push_back(numeros[0]);
                numeros.erase(numeros.begin());

            }

            
            operacion_a_realizar = operaciones_a_realizar[0];
            switch(operacion_a_realizar)
            {
                case '+':
                {
                    res_temporal = cola[0] + cola[1];
                    //cout << cola[0] << " + " << cola[1] << endl;
                    cola.clear();
                    cola.push_back(res_temporal);
                    break;
                }
                case '-':
                {
                    res_temporal = cola[0] - cola[1];
                    //cout << cola[0] << " - " << cola[1] << endl;
                    cola.clear();
                    cola.push_back(res_temporal);
                    break;
                }
                case '*':
                {
                    res_temporal = cola[0] * cola[1];
                    //cout << cola[0] << " * " << cola[1] << endl;
                    cola.clear();
                    cola.push_back(res_temporal);
                    break;
                }
                case '/':
                {
                    res_temporal = cola[0] / cola[1];
                    //cout << cola[0] << "/" << cola[1] << endl;
                    cola.clear();
                    cola.push_back(res_temporal);
                    break;
                }
                    
                default:
                {
                    break;
                }
            }
            operaciones_a_realizar.erase(operaciones_a_realizar.begin());
            //cout << cola[0] << endl;
        }
        
        int resultado_del_nodo = cola[0];

        return resultado_del_nodo == resultado_del_problema ;
    }
    else
        return false;
    
}

//-------------------------------------------------------------------------------------------------------------------

bool SolucionNumerosDelRey::busqueda_a_lo_ancho_multiples_soluciones(const vector <int> numeros, const int resultado_esperado_del_problema, vector<int>& nodos_encontrados)
{

    nodos_encontrados.clear();
    numeros_del_problema = numeros;
    
    arbol_de_busqueda.limpia_arbol();
    agenda.limpia_agenda();
    
    Arbol_Binario arbol_binario = Arbol_Binario();
    

    int nodo_actual = 0;
    vector <tipo_nodo_del_arbol> vecinos;
    
    tipo_nodo_del_arbol nodo_raiz;
    
    arbol_de_busqueda.crea_arbol(nodo_raiz);

    agenda.push_back(0);

    unsigned int t1, t2;
    t1 = (unsigned int)clock();
    
    while (!agenda.esta_vacia())
    {
        nodo_actual = agenda.front();
        
        if (revisa_si_es_la_solucion(arbol_de_busqueda[nodo_actual].nombre_del_nodo, resultado_esperado_del_problema))
            nodos_encontrados.push_back(nodo_actual);

        
        agenda.pop_front();

        
        if(arbol_de_busqueda[nodo_actual].nivel_de_profundidad < numeros_del_problema.size() - 1)
        {

            vecinos.clear();
            devuelve_vecinos(arbol_de_busqueda[nodo_actual], vecinos);
            
            
            for (size_t i = 0; i < vecinos.size(); i++)
            {
                arbol_de_busqueda.agrega_hijo_a_un_nodo_del_arbol(nodo_actual, vecinos[i]);
                agenda.push_back(arbol_de_busqueda.size()-1);
            }
            
            
            agenda.revisa_tamano_maximo_de_la_agenda();
        }
        
    }
    
    if (nodos_encontrados.size() != 0)
    {
        
        Arbol_Binario soluciones_sin_repetir = Arbol_Binario();
        for(unsigned int i = 0; i < nodos_encontrados.size();i++)
            if(!soluciones_sin_repetir.push(arbol_de_busqueda[nodos_encontrados[i]].nombre_del_nodo))
            {
                nodos_encontrados.erase(nodos_encontrados.begin()+i);
                i--;
            }
    
        t2 = (unsigned int)clock();
        cout << "Tiempo de busqueda: " << (double(t2 - t1) / CLOCKS_PER_SEC) << " segundos" << endl;
        cout << "Soluciones encontradas: " << nodos_encontrados.size() << endl;
        cout << "Tamano del arbol: " << arbol_de_busqueda.size() << " nodos" << endl;
        cout << "Tamano maximo de la agenda: " << agenda.obten_tamano_maximo_de_la_agenda() << " nodos" << endl;
    }
    return nodos_encontrados.size() != 0;


}

//------------------------------------------------------------------------------------------------------


bool SolucionNumerosDelRey::busqueda_en_profundidad_multiples_soluciones(const vector <int> numeros, const int resultado_esperado_del_problema, vector<int>& nodos_encontrados)
{
    nodos_encontrados.clear();
    numeros_del_problema = numeros;
    
    arbol_de_busqueda.limpia_arbol();
    agenda.limpia_agenda();
    
    Arbol_Binario arbol_binario = Arbol_Binario();
    

    int nodo_actual = 0;
    vector <tipo_nodo_del_arbol> vecinos;
    
    tipo_nodo_del_arbol nodo_raiz;
    
    arbol_de_busqueda.crea_arbol(nodo_raiz);

    agenda.push_back(0);

    unsigned int t1, t2;
    t1 = (unsigned int)clock();
    
    while (!agenda.esta_vacia())
    {
        nodo_actual = agenda.back();
        
        if (revisa_si_es_la_solucion(arbol_de_busqueda[nodo_actual].nombre_del_nodo, resultado_esperado_del_problema))
            nodos_encontrados.push_back(nodo_actual);

        
        agenda.pop_back();

        
        if(arbol_de_busqueda[nodo_actual].nivel_de_profundidad < numeros_del_problema.size() - 1)
        {

            vecinos.clear();
            devuelve_vecinos(arbol_de_busqueda[nodo_actual], vecinos);
            
            
            for (size_t i = 0; i < vecinos.size(); i++)
            {
                arbol_de_busqueda.agrega_hijo_a_un_nodo_del_arbol(nodo_actual, vecinos[i]);
                agenda.push_back(arbol_de_busqueda.size()-1);
            }
            
            
            agenda.revisa_tamano_maximo_de_la_agenda();
        }
        
    }
    
    if (nodos_encontrados.size() != 0)
    {
        
        Arbol_Binario soluciones_sin_repetir = Arbol_Binario();
        for(unsigned int i = 0; i < nodos_encontrados.size();i++)
            if(!soluciones_sin_repetir.push(arbol_de_busqueda[nodos_encontrados[i]].nombre_del_nodo))
            {
                nodos_encontrados.erase(nodos_encontrados.begin()+i);
                i--;
            }
    
        t2 = (unsigned int)clock();
        cout << "Tiempo de busqueda: " << (double(t2 - t1) / CLOCKS_PER_SEC) << " segundos" << endl;
        cout << "Soluciones encontradas: " << nodos_encontrados.size() << endl;
        cout << "Tamano del arbol: " << arbol_de_busqueda.size() << " nodos" << endl;
        cout << "Tamano maximo de la agenda: " << agenda.obten_tamano_maximo_de_la_agenda() << " nodos" << endl;
    }
    return nodos_encontrados.size() != 0;
}

//------------------------------------------------------------------------------------------------------

string SolucionNumerosDelRey::devuelve_las_soluciones_encontradas(vector <int> nodos_encontrados) const
{

    string soluciones = "";
    string solucion = "";
    string orden_de_operaciones = "";
    int contador_de_numeros_del_rey_anadidos_a_la_solucion = 0;
    

    
    if(nodos_encontrados.size() != 0)
    {
        for(unsigned int i = 0; i < nodos_encontrados.size(); i++)
        {
            solucion = "";
            orden_de_operaciones = arbol_de_busqueda[nodos_encontrados[i]].nombre_del_nodo;
            while (contador_de_numeros_del_rey_anadidos_a_la_solucion != numeros_del_problema.size())
            {
                solucion = solucion + to_string(numeros_del_problema[contador_de_numeros_del_rey_anadidos_a_la_solucion]);
                
                if (contador_de_numeros_del_rey_anadidos_a_la_solucion < orden_de_operaciones.length())
                    solucion += orden_de_operaciones[contador_de_numeros_del_rey_anadidos_a_la_solucion];
                
                contador_de_numeros_del_rey_anadidos_a_la_solucion++;
            }
            
            soluciones = soluciones + solucion +  "\n";
            contador_de_numeros_del_rey_anadidos_a_la_solucion = 0;
        }
        
    }

    return soluciones;

}


