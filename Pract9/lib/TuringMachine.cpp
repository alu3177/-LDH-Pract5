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

TuringMachine::TuringMachine(idt_t const &i_id) {
    _id = i_id;
    //_currState = 0;
    _tapePos = 0;
    _states = new vector<State* >();
    _tape = NULL;
}

TuringMachine::~TuringMachine() {
}

bool TuringMachine::ParseFile(string const &i_path){
    fstream* fs = new fstream(i_path.c_str());
    
    if (!fs->is_open()){
        cout << "[ERROR FICHERO] No se ha podido abrir el fichero \"" << i_path << "\"" << endl;
        return false;
    }
    
    int nStates;
    int firstFinal;
    int nTuples;
    
    *fs >> nStates;
    *fs >> firstFinal;
    *fs >> nTuples;
    
    vector<idt_t>* readedStates = new vector<idt_t>();
    for (uint16_t i = 0; i < nTuples; i++){
        Transition* tr = new Transition;
        char move;
        *fs >> tr->stateID >> tr->inputSymbol >> tr->writeSymbol >> move >> tr->nextStateID;
        if (!isInVector<idt_t>(readedStates, i))
            readedStates->push_back(i);            
        if (!isInVector<idt_t>(readedStates, tr->nextStateID))
            readedStates->push_back(tr->nextStateID);
        switch(move){
            case 'R':
            case 'r': tr->move = R; break;
            case 'L':
            case 'l': tr->move = L; break;
            case 'S':
            case 's': tr->move = S; break;
        }

        State* stActual = GetState(tr->stateID);
        if (stActual == NULL){ // No existe el estado
            bool final = tr->stateID < firstFinal ? false : true;
            stActual = new State(tr->stateID, final);
            AddState(stActual);
            
        }
        stActual->AddTransition(tr);
    }
    
    vector<idt_t>* stsIDs = GetStatesIDs();
    for (uint16_t i = 0; i < readedStates->size(); i++){
        idt_t rStateID = readedStates->at(i);
        if ( !isInVector<idt_t>(stsIDs, rStateID) ){
            // "rStateID" no está en el vector de estados. Lo creamos y añadimos
            bool final = rStateID < firstFinal ? false : true;
            State* newState = new State(rStateID, final);
            AddState(newState);
        }
    }
}

bool TuringMachine::Run(){
    //cout << "RUN" << endl;  // DEBUG
    State* stActual = GetState(0);
    cout << "[" << 0 << "] ";
    for (int i = _tape->LowerPos() - 1; i < _tape->UpperPos() + 1; i++){
            if (i == 0)
                cout << C_BRED;
            cout << _tape->Read(i);
            if (i == 0)
                cout << C_DEFAULT;
        }
        cout << endl;
    
    while(stActual->TransitionCount() > 0){
        //cout << "ID: " << stActual->GetID() << endl;  // DEBUG
        //cout << "tCount = " << stActual->TransitionCount() << endl;  // DEBUG
        char symbLeido = _tape->Read(_tapePos);
        //cout << "SymbLeido = " << symbLeido << endl;  // DEBUG
        Transition* trActual = stActual->GetTransition(symbLeido);
        if (trActual == NULL){
            cout << "[RESULTADO] Cadena rechazada." << endl;  // DEBUG ?
            return false;
        }
        _tape->Write(_tapePos, trActual->writeSymbol);
        switch(trActual->move){
            case L  : _tapePos--; break;
            case R  : _tapePos++; break;
            default : break;
        }
        stActual = GetState(trActual->nextStateID);
        if (stActual == NULL){
            cout << "[RESULTADO] Cadena rechazada." << endl;  // DEBUG ?
            return false;
        }
            
        
        // Mostramos las cinta, resaltando en color la posición del cabezal
        cout << "[" << stActual->GetID() << "] ";
        for (int i = _tape->LowerPos() - 1; i < _tape->UpperPos() + 1; i++){
            if (i == _tapePos)
                cout << C_BRED;
            cout << _tape->Read(i);
            if (i == _tapePos)
                cout << C_DEFAULT;
        }
        cout << endl;
    }
    
    if (stActual->isFinal()){
        cout << "[RESULTADO] Cadena aceptada." << endl;
        return true;
    }
    return false;
}

State* TuringMachine::GetState(idt_t const &i_id) const{   
    for (uint16_t i = 0; i < _states->size(); i++)
        if (_states->at(i)->GetID() == i_id)
            return _states->at(i);
    return NULL;
}

bool TuringMachine::AddState(State* i_st){
    if (!isInVector<State>(GetStates(), i_st)){
        _states->push_back(i_st);
        return true;
    }
    return false;
}

vector<idt_t>* TuringMachine::GetStatesIDs() const{
    vector<idt_t>* result = new vector<idt_t>();
    for (uint16_t i = 0; i < _states->size(); i++)
        result->push_back(_states->at(i)->GetID());
    return result;
}

ostream& operator<<(ostream &out, TuringMachine const &i_tm){
    out << "ID:            " << i_tm._id << endl;
    out << "Posición del cabezal: " << i_tm._tapePos << endl;
//    out << "Estado actual: " << i_tm._currState << endl;
    if (VERBOSE){
        uint16_t cPos = 0;
        for (uint16_t i = 0; i < i_tm._states->size(); i++){
            cPos = i % NCOLORS;
            switch (cPos){
                case 0: cout << C_RED; break;
                case 1: cout << C_BLUE; break;
                case 2: cout << C_GREEN; break;
                case 3: cout << C_CYAN; break;
                case 4: cout << C_MAGENTA; break;
                case 5: cout << C_BRED; break;
                case 6: cout << C_BGREEN; break;
                default: cout << C_DEFAULT; break;
            }
            cout << * i_tm._states->at(i);
        }
    }else{
        out << "Numero de estados: " << i_tm._states->size() << endl;
    }
}

