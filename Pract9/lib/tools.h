/*
 * Computabilidad y Algoritmia 2013 - 2014
 * Práctica 9 - Simulación de una Máquina de Turing
 * Fecha de entrega: 21 - 11 - 2013
 * 
 * Autor: Fernando González López - Peñalver
 * Email: alu0100256543@ull.edu.es
 * 
 */

#ifndef TOOLS
#define	TOOLS

#include <stdint.h>
#include <vector>

using namespace std;

/**
 * Función encargada de comprobar si un elemento pertenece (está dentro) de un vector dado.
 * @param i_vector Puntero al vector a analizar
 * @param i_elem Elemento a buscar en el vector
 * @return Devuelve 'true' si existe; 'false' en caso contrario
 */
template <typename T>
bool isInVector(vector<T>* &i_vector, T i_elem){
    for (uint32_t i = 0; i < i_vector->size(); i++)
        if (i_vector->at(i) == i_elem)
            return true;
    
    return false;
}

/**
 * Función encargada de comprobar si un puntero a un elemento pertenece (está dentro) de un vector dado.
 * @param i_vector Puntero al vector a analizar
 * @param i_elem Puntero al elemento a buscar en el vector
 * @return Devuelve 'true' si existe; 'false' en caso contrario
 */
template <typename T>
bool isInVector(vector<T* >* const &i_vector, T* i_elem){
    for (uint32_t i = 0; i < i_vector->size(); i++)
        if (*i_vector->at(i) == *i_elem)
            return true;
    
    return false;
}

#endif	/* TOOLS */
