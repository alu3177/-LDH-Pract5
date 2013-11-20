/*
 * Computabilidad y Algoritmia 2013 - 2014
 * Práctica 9 - Simulación de una Máquina de Turing
 * Fecha de entrega: 21 - 11 - 2013
 * 
 * Autor: Fernando González López - Peñalver
 * Email: alu0100256543@ull.edu.es
 * 
 */

#ifndef TURINGMACHINE_H
#define	TURINGMACHINE_H

#include <vector>
#include "../definitions.h"
#include "State.h"
#include "TuringTape.h"

using namespace std;

/**
 * Clase que respresenta una Máquina de Turing (MT) básica.
 * @param i_path Ruta al fichero de definición de la MT
 */
class TuringMachine {
public:
    TuringMachine(string const &i_path);
    virtual ~TuringMachine();
    
    bool IsInitialized() const { return _initialized; }
    /**
     * Carga una cinta desde la ruta especificada en la MT.
     * @param i_path Ruta de acceso al fichero *.tmt con el contenido de la cinta
     * @return Devuelve 'true' si se efectua correctamente; 'false' en caso contrario
     */
    bool LoadTape(string const &i_path);
    /**
     * Ejecuta la MT con la cinta cargada.
     * @return Devuelve 'true' si se ha detenido en un estado de aceptación; 'false' en caso contrario
     */
    bool Run();
    
    friend ostream& operator<<(ostream &out, TuringMachine const &i_tm);
private:
    /**
     * Carga y analiza un fichero *.tm de definición de la MT.
     * @param i_path Ruta de acceso al fichero *.tm con la definición de la MT
     * @return Devuelve 'true' si se efectua correctamente; 'false' en caso contrario
     */
    bool ParseFile(string const &i_path);
    /**
     * Obtiene un puntero al estado con ID especificada.
     * @param i_id Es la ID del estado que se desea obtener
     * @return Devuelve un puntero al estado buscado; si no existe devuelve NULL
     */
    State* GetState(idt_t const &i_id) const;
    /**
     * Añade un nuevo estado a la MT.
     * @param i_st Puntero al estado a añadir
     * @return Devuelve 'true' si se efectua correctamente; 'false' en caso contrario
     */
    bool AddState(State* i_st);

    bool _initialized; /**< Indica si se ha cargado correctamente la definición */
    int _tapePos; /**< Posición del cabezal en la cinta */
    vector<State* >* _states;
    TuringTape* _tape;
};

#endif	/* TURINGMACHINE_H */

