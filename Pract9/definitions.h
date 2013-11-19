/* 
 * File:   definitions.h
 * Author: aladaris
 *
 * Created on 10 de noviembre de 2013, 18:29
 */

#ifndef DEFINITIONS_H
#define	DEFINITIONS_H

#include <stdint.h>

using namespace std;

// Tipos y constantes
typedef uint16_t idt_t;
enum TapeMovement { L, R, S };
const char BLANK_SYMBOL = '$';

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


// Modo VERBOSE: Si se activa se muestra mas informacion
#define VERBOSE     true

#endif	/* DEFINITIONS_H */

