/* 
 * File:   main.cpp
 * Author: Fernando González López - Peñalver
 *
 * Created on 9 de noviembre de 2013, 23:34
 */

#include <cstdlib>
#include <iostream>
#include <map>  // Tests con MAP
#include <stdexcept>

#include "lib/TuringMachine.h"
//#include "lib/TuringTape.h"

using namespace std;

int main(int argc, char** argv) {
    TuringTape* t = new TuringTape();
    t->ParseFile("tapes/ejem1.tmt");
    TuringMachine tm(0);
    string path = "machines/ejem1.tm";
    tm.ParseFile(path);
    tm.LoadTape(t);
    tm.Run();
    
    /*
    map<int, char> tape;
    //tape.insert(pair<int, char>(0,'0'));
    tape[0] = '$';
    cout << tape[0] << endl;
    tape[0] = 'E';
    cout << tape.at(0) << endl;
    try{
        cout << tape.at(1) << endl;
    }catch (const out_of_range& orr){
        cout << "No existe tape[1]" << endl;
    }
    */
/*
    TuringMachine tm(0);
    string path = "machines/ejem1.tm";
    tm.ParseFile(path);
    cout << tm;
 */
 /*   
    State* s = new State(0);
    Transition* tr = new Transition;
    tr->stateID = 0;
    tr->inputSymbol = '0';
    tr->writeSymbol = 'X';
    tr->move = R;
    tr->nextStateID = 1;
    cout << s->AddTransition(tr) << endl;
    cout << s->AddTransition(tr) << endl;
 */   
    
    return EXIT_SUCCESS;
}

