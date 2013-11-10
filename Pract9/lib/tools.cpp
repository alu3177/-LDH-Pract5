/* 
 * File:   tools.cpp
 * Author: Fernando González López - Peñalver
 * 
 * Created on 9 de noviembre de 2013, 23:51
 */

#ifndef TOOLS
#define	TOOLS

#include <stdint.h>
#include <vector>

using namespace std;

template <typename T>
bool isInVector(vector<T>* &i_vector, T i_elem){
    for (uint32_t i = 0; i < i_vector->size(); i++)
        if (i_vector->at(i) == i_elem)
            return true;
    
    return false;
}

template <typename T>
bool isInVector(vector<T* >* &i_vector, T* i_elem){
    for (uint32_t i = 0; i < i_vector->size(); i++)
        if (i_vector->at(i) == i_elem)
            return true;
    
    return false;
}

#endif	/* TOOLS */
