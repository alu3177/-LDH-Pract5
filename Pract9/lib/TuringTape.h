/* 
 * File:   TuringTape.h
 * Author: aladaris
 *
 * Created on 10 de noviembre de 2013, 19:53
 */

#ifndef TURINGTAPE_H
#define	TURINGTAPE_H

#include <map>
#include <stdexcept>
#include <string>
#include "../definitions.h"

using namespace std;

class TuringTape {
public:
    TuringTape(string const &i_path);
    virtual ~TuringTape();
     
    bool IsInitialized() const { return _initialized; }
    char Read(int const &i_pos) const;
    void Write(int const &i_pos, char const &i_symbol);
    int LowerPos() const { return _lowerPos; }
    int UpperPos() const { return _upperPos; }
    
    friend ostream& operator<<(ostream &out, TuringTape const &i_tt);
private:
    bool ParseFile(string const &i_path);
    
    bool _initialized;
    map<int, char> _tape;
    int _lowerPos;
    int _upperPos;
    

};

#endif	/* TURINGTAPE_H */

