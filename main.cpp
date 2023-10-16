//
//  main.cpp
//  NumerosDelRey
//
//  Created by Rodri on 02/06/23.
//


#include <iostream>
#include "SolucionNumerosDelRey.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    SolucionNumerosDelRey solver = SolucionNumerosDelRey();
    cout << "Busqueda a lo ancho multiples soluciones" << endl;
    vector<int> nodos_encontrados;
    string soluciones = "";
    
    if(solver.busqueda_a_lo_ancho_multiples_soluciones({1,2,3,4,5,6,7,8,9}, 23, nodos_encontrados))
    {
        soluciones = solver.devuelve_las_soluciones_encontradas(nodos_encontrados);
        cout << soluciones;
    }
    cout << "----------------------------------------------------------" << endl;

    cout << "Busqueda en profundidad multiples soluciones" << endl;
    if(solver.busqueda_en_profundidad_multiples_soluciones({1,2,3,4,5,6,7,8,9}, 100, nodos_encontrados))
    {
        soluciones = solver.devuelve_las_soluciones_encontradas(nodos_encontrados);
        cout << soluciones;
    }
    cout << "----------------------------------------------------------" << endl;

    
    
    return 0;
}
