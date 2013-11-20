/*
 * Computabilidad y Algoritmia 2013 - 2014
 * Práctica 9 - Simulación de una Máquina de Turing
 * Fecha de entrega: 21 - 11 - 2013
 * 
 * Autor: Fernando González López - Peñalver
 * Email: alu0100256543@ull.edu.es
 * 
 */

#ifndef DEFINITIONS_H
#define	DEFINITIONS_H

#include <stdint.h>

using namespace std;

// Tipos y constantes
typedef uint16_t idt_t; /**< Tipo de dato para IDentificadores */
enum TapeMovement { L, R, S }; /**< Movimientos posibles del cabezal de la MT */
const char BLANK_SYMBOL = '$'; /**< Símbolo de casilla vacia en una cinta de una MT */

// Colores para std::cout
#define NCOLORS 8
#define C_DEFAULT "\033[0;m"
#define C_RED     "\033[0;31m"
#define C_BLUE    "\033[0;34m"
#define C_GREEN   "\033[0;32m"
#define C_CYAN    "\033[0;36m"
#define C_MAGENTA "\033[0;35m"
#define C_BRED    "\033[1;31m"   // BOLD
#define C_BGREEN  "\033[1;32m"   // BOLD

#define VERBOSE     true  /**< Modo VERBOSE: Si se activa se muestra mas informacion */

#endif	/* DEFINITIONS_H */

