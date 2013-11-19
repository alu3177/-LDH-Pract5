/* 
 * File:   TuringTape.cpp
 * Author: aladaris
 * 
 * Created on 10 de noviembre de 2013, 19:53
 */

#include <fstream>
#include <iostream>
#include "TuringTape.h"

TuringTape::TuringTape(string const &i_path) {
    _upperPos = 0;
    _lowerPos = 0;
    _initialized = ParseFile(i_path);
}

TuringTape::~TuringTape() {
}

bool TuringTape::ParseFile(string const &i_path){
    fstream* fs = new fstream(i_path.c_str());
    
    if (!fs->is_open()){
        cout << "[ERROR FICHERO] No se ha podido abrir el fichero \"" << i_path << "\"" << endl;
        return false;
    }
    
    string raw;
    
    *fs >> raw;
    
    for (uint16_t i = 0; i < raw.size(); i++)
        Write(i, raw[i]);
    return true;
}

char TuringTape::Read(int const &i_pos) const{
    try{
        return _tape.at(i_pos);
    }catch (const out_of_range& orr){
        return BLANK_SYMBOL;
    }
}

void TuringTape::Write(int const &i_pos, char const &i_symbol){
    if (i_pos < _lowerPos)
        _lowerPos = i_pos;
    else if (i_pos > _upperPos)
        _upperPos = i_pos;
    _tape[i_pos] = i_symbol;
}

ostream& operator<<(ostream &out, TuringTape const &i_tt){
    out << BLANK_SYMBOL;
    for (uint16_t i = i_tt._lowerPos; i <= i_tt._upperPos; i++){
        out << i_tt.Read(i);
    }
    out << BLANK_SYMBOL << endl;
}
