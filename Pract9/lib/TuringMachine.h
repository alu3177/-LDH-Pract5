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
    TuringMachine(string const &i_path);
    //TuringMachine(const TuringMachine& orig);
    virtual ~TuringMachine();
    
    bool IsInitialized() const { return _initialized; }
    bool LoadTape(string const &i_path);
    //void SetTape(TuringTape* i_tape) { _tape = i_tape; }
    bool Run();
    
    friend ostream& operator<<(ostream &out, TuringMachine const &i_tm);
private:
    bool ParseFile(string const &i_path);
    State* GetState(idt_t const &i_id) const;
    vector<State* >* GetStates() const { return _states; }
    vector<idt_t>* GetStatesIDs() const;
    bool AddState(State* i_st);

    bool _initialized;
    int _tapePos;
    vector<State* >* _states;
    TuringTape* _tape;
};

#endif	/* TURINGMACHINE_H */

