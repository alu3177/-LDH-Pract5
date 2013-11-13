/* 
 * File:   State.cpp
 * Author: Fernando González López - Peñalver
 * 
 * Created on 9 de noviembre de 2013, 23:51
 */

#include "State.h"
#include "tools.cpp"

State::State(idt_t const &i_id, bool const &i_final) : _id(i_id), _final(i_final){
    _transitions = new vector<Transition* >();
}

State::~State() {
}

bool State::AddTransition(Transition* const &i_tr){
    if (!isInVector<Transition>(GetTransitions(), i_tr)){
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
        if (!isInVector<Transition>(i_st1.GetTransitions(), i_st1._transitions->at(i)))
            return false;
    }
    return true;
}
