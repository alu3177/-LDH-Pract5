/* 
 * File:   main.cpp
 * Author: Fernando González López - Peñalver
 *
 * Created on 9 de noviembre de 2013, 23:34
 */

#include <cstdlib>
#include "lib/menu.h"

using namespace std;

int main(int argc, char** argv) {
    TuringMachine* tm;
    
    Menu(tm);
    
    return EXIT_SUCCESS;
}

