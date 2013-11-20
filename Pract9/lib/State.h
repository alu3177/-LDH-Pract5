/*
 * Computabilidad y Algoritmia 2013 - 2014
 * Práctica 9 - Simulación de una Máquina de Turing
 * Fecha de entrega: 21 - 11 - 2013
 * 
 * Autor: Fernando González López - Peñalver
 * Email: alu0100256543@ull.edu.es
 * 
 */

#ifndef STATE_H
#define	STATE_H

#include <iostream>
#include "../definitions.h"
#include <string>
#include <vector>

using namespace std;

/**
 * Estructura que representa las transiciones de una Máquina de Turing (MT).
 */
struct Transition{
    idt_t        stateID;     /**< ID de la transición */
    char         inputSymbol; /**< Símbolo de entrada */
    char         writeSymbol; /**< Símbolo escrito */
    TapeMovement move;        /**< Dirección de movimiento */
    idt_t        nextStateID; /**< Estado al que transita */
    
    bool operator==(const Transition& tr) const{
        return (stateID == tr.stateID && inputSymbol == tr.inputSymbol);
    }
};

/**
 * Clase que representa un estado de una Máquina de Turing (MT).
 * @param i_id ID del estado en la MT
 * @param i_final Sirve para señalizar los estados finales
 */
class State {
public:
    State(idt_t const &i_id, bool const &i_final = false);
    virtual ~State();
    
    idt_t GetID() const { return _id; }
    bool isFinal() const { return _final; }
    
    /**
     * Añade una transición al estado.
     * @param i_tr Puntero a la transición a agregar
     * @return Devuelve 'true' si se efectua correctamente; 'false' en caso contrario
     */
    bool AddTransition(Transition* const &i_tr);
    /**
     * Obtiene la transición que se usará con el símbolo de entrada especificado
     * @param i_inputSymbol Símbolo de entrada
     * @return Devuelve un puntero a la transición buscada; si no existe devuelve NULL
     */
    Transition* GetTransition(char const &i_inputSymbol);
    uint16_t TransitionCount() const { return _transitions->size(); }
    
    friend ostream& operator<<(ostream &out, State const &i_st);
    friend bool operator== (State const &i_st1, State const &i_st2);
private:
    
    idt_t _id;
    bool _final; /**< Indica si se trata de un estado final */
    vector<Transition* >* _transitions;
};



#endif	/* STATE_H */

