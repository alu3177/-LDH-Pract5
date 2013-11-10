/* 
 * File:   State.h
 * Author: Fernando González López - Peñalver
 *
 * Created on 9 de noviembre de 2013, 23:51
 */

#ifndef STATE_H
#define	STATE_H

#include <set>
#include <stdint.h>
#include <string>

using namespace std;

typedef uint16_t idt_t;
enum TapeMovement { L, R, S };
const char BLANK = '$';

struct Transition{
    idt_t        stateID;
    char         inputSymbol;
    char         writeSymbol;
    TapeMovement move;
    idt_t        nextStateID;
};

class State {
public:
    State(idt_t i_id, bool i_final = false);
    virtual ~State();
    
private:
    idt_t _id;
    bool _final;
    set<Transition* >* _transitions;

};

#endif	/* STATE_H */

