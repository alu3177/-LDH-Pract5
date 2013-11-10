/* 
 * File:   TuringMachine.cpp
 * Author: Fernando González López - Peñalver
 * 
 * Created on 9 de noviembre de 2013, 23:46
 */

#include <fstream>
#include <iostream>
#include "tools.cpp"

#include "TuringMachine.h"

TuringMachine::TuringMachine() {
}

TuringMachine::~TuringMachine() {
}

bool TuringMachine::ParseFile(string &i_path){
    fstream* fs = new fstream(i_path.c_str());
    
    if (!fs->is_open()){
        cout << "[ERROR FICHERO] No se ha podido abrir el fichero seleccionado" << endl;
        return false;
    }
    
    int nStates;
    int firstFinal;
    int nTuples;
    
    *fs >> nStates;
    *fs >> firstFinal;
    *fs >> nTuples;
    
    for (uint16_t i = 0; i < nTuples; i++){
        Transition* tr = new Transition;
        char move;
        *fs >> tr->stateID >> tr->inputSymbol >> tr->writeSymbol >> move >> tr->nextStateID;
        switch(move){
            case 'R':
            case 'r': tr->move = R; break;
            case 'L':
            case 'l': tr->move = L; break;
            case 'S':
            case 's': tr->move = S; break;
        }
    }
}

