/* 
 * File:   State.h
 * Author: Fernando González López - Peñalver
 *
 * Created on 9 de noviembre de 2013, 23:51
 */

#ifndef STATE_H
#define	STATE_H

#include <iostream>
#include "../definitions.h"
#include <string>
#include <vector>

using namespace std;

struct Transition{
    idt_t        stateID;
    char         inputSymbol;
    char         writeSymbol;
    TapeMovement move;
    idt_t        nextStateID;
    
    bool operator==(const Transition& tr) const{
        return (stateID == tr.stateID && inputSymbol == tr.inputSymbol);
    }
};


class State {
public:
    State(idt_t const &i_id, bool const &i_final = false);
    virtual ~State();
    
    idt_t GetID() const { return _id; }
    bool isFinal() const { return _final; }
    
    bool AddTransition(Transition* const &i_tr);
    Transition* GetTransition(char const &i_inputSymbol);
    uint16_t TransitionCount() const { return _transitions->size(); }
    
    friend ostream& operator<<(ostream &out, State const &i_st);
    friend bool operator== (State const &i_st1, State const &i_st2);
private:
    vector<Transition* >* GetTransitions() const { return _transitions; }
    
    idt_t _id;
    bool _final;
    vector<Transition* >* _transitions;
};



#endif	/* STATE_H */

