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

using namespace std;

class TuringMachine {
public:
    TuringMachine();
    //TuringMachine(const TuringMachine& orig);
    virtual ~TuringMachine();
    
    bool ParseFile(string &i_path);
private:
    idt_t _id;
    idt_t _currState;
    vector<State>* _states;
};

#endif	/* TURINGMACHINE_H */

