/*
 * Computabilidad y Algoritmia 2013 - 2014
 * Práctica 9 - Simulación de una Máquina de Turing
 * Fecha de entrega: 21 - 11 - 2013
 * 
 * Autor: Fernando González López - Peñalver
 * Email: alu0100256543@ull.edu.es
 * 
 */

#ifndef TURINGTAPE_H
#define	TURINGTAPE_H

#include <map>
#include <stdexcept>
#include <string>
#include "../definitions.h"

using namespace std;

/**
 * Clase que representa una cinta "infinita" de un Máquina de Turing (MT).
 * Permite el acceso R/W a índices negativos.
 * @param i_path Ruta al fichero con el contenido de la cinta
 */
class TuringTape {
public:
    TuringTape(string const &i_path);
    virtual ~TuringTape();
    
    /**
     * Devuelve el símbolo almacenado en la posición solicitada
     * @param i_pos Posición/Casilla de la cinta
     * @return Devuelve el símbolo encontrado (si no hay nada; está sin inicializar; devuelve BLANK_SYMBOL)
     */
    char Read(int const &i_pos) const;
    /**
     * Escribe un símbolo en la posición especificada de la cinta
     * @param i_pos Posición/Casilla de la cinta
     * @param i_symbol Símbolo a escribir
     */
    void Write(int const &i_pos, char const &i_symbol);
    bool IsInitialized() const { return _initialized; }
    int LowerPos() const { return _lowerPos; }
    int UpperPos() const { return _upperPos; }
    
    friend ostream& operator<<(ostream &out, TuringTape const &i_tt);
private:
    /**
     * Carga y analiza un fichero *.tmt con el contenido de la cinta.
     * @param i_path Ruta de acceso al fichero *.tmt
     * @return Devuelve 'true' si se efectua correctamente; 'false' en caso contrario
     */
    bool ParseFile(string const &i_path);
    
    bool _initialized;
    map<int, char> _tape;
    int _lowerPos;
    int _upperPos;
    

};

#endif	/* TURINGTAPE_H */

