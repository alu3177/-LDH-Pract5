/*
 * Computabilidad y Algoritmia 2013 - 2014
 * Práctica 9 - Simulación de una Máquina de Turing
 * Fecha de entrega: 21 - 11 - 2013
 * 
 * Autor: Fernando González López - Peñalver
 * Email: alu0100256543@ull.edu.es
 * 
 */

#include "State.h"
#include "tools.h"

State::State(idt_t const &i_id, bool const &i_final) : _id(i_id), _final(i_final){
    _transitions = new vector<Transition* >();
}

State::~State() {
}

bool State::AddTransition(Transition* const &i_tr){
    if (!isInVector<Transition>(_transitions, i_tr)){
        _transitions->push_back(i_tr);
        return true;
    }
    return false;
}

Transition* State::GetTransition(char const &i_inputSymbol){
    for (uint16_t i = 0; i < _transitions->size(); i++)
        if (_transitions->at(i)->inputSymbol == i_inputSymbol)
            return _transitions->at(i);
    return NULL;
}

ostream& operator<<(ostream &out, State const &i_st){
    out << "ID: " << i_st._id << endl;
    string final = i_st._final ? "Final" : "No Final";
    out << final << endl;
    out << "Transiciones:" << endl;
    for (uint16_t i = 0; i < i_st._transitions->size(); i++){
        out << "   [" << i << "] Input Symbol:  " << i_st._transitions->at(i)->inputSymbol << endl;
        out << "   [" << i << "] OutPut Symbol: " << i_st._transitions->at(i)->writeSymbol << endl;
        out << "   [" << i << "] Movement:      " << i_st._transitions->at(i)->move << endl;
        out << "   [" << i << "] NextState ID:  " << i_st._transitions->at(i)->nextStateID << endl;
        out << endl;
    }
}

bool operator== (State const &i_st1, State const &i_st2){
    if ((i_st1._id != i_st2._id) || (i_st1._final != i_st2._final))
        return false;
    if (i_st1._transitions->size() != i_st2._transitions->size())
        return false;
    for (uint16_t i = 0; i < i_st1._transitions->size(); i++){
        if (!isInVector<Transition>(i_st1._transitions, i_st1._transitions->at(i)))
            return false;
    }
    return true;
}
