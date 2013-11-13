/* 
 * File:   TuringMachine.h
 * Author: Fernando González López - Peñalver
 *
 * Created on 9 de noviembre de 2013, 23:46
 */

#ifndef TURINGMACHINE_H
#define	TURINGMACHINE_H

#include <vector>
#include "State.h"
#include "TuringTape.h"
#include "../definitions.h"

using namespace std;

class TuringMachine {
public:
    TuringMachine(idt_t const &i_id);
    //TuringMachine(const TuringMachine& orig);
    virtual ~TuringMachine();
    
    bool ParseFile(string const &i_path);
    void LoadTape(TuringTape* i_tape) {  delete(_tape); _tape = i_tape; }
    bool Run();
    
    friend ostream& operator<<(ostream &out, TuringMachine const &i_tm);
private:
    State* GetState(idt_t const &i_id) const;
    vector<State* >* GetStates() const { return _states; }
    vector<idt_t>* GetStatesIDs() const;
    bool AddState(State* i_st);
    
    idt_t _id;
    //idt_t _currState;
    int _tapePos;
    vector<State* >* _states;
    TuringTape* _tape;
};

#endif	/* TURINGMACHINE_H */

