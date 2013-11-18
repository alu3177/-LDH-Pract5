/* 
 * File:   menu.h
 * Author: aladaris
 *
 * Created on 18 de noviembre de 2013, 16:20
 */

#ifndef MENU_H
#define	MENU_H

#include <iostream>
#include <stdio.h>
#include "TuringMachine.h"

using namespace std;

void Pausa(){
    int c;
    cout << endl << "Pulse enter para continuar..." << endl;
    fflush(stdout);
    getchar();  // Evitar salir del Pausa si se ha presionado 'enter' antes
    do c = getchar(); while((c != '\n') && (c != EOF));
}

void Menu(TuringMachine* &tm){
    bool loaded = false;
    bool tapeLoaded = false;
    string defFilename;
    string tapeFilename;
    int opt;
    while(1){
        system("clear");
        cout << "···························································" << endl;
        cout << "·· Computabilidad y Algoritmia | 2013-2014 | Práctica 9  ··" << endl;
        cout << "··                     Fernando González López Peñalver  ··" << endl;
        cout << "···························································" << endl;
        cout << "·· [1] Cargar Máquina de Turing desde un fichero         ··" << endl;
        if (loaded){
            cout << "·· [2] Cargar Cinta desde un fichero                     ··" << endl;
            cout << "·· [3] Mostrar información de la Máquina de Turing       ··" << endl;
            if (tapeLoaded)
                cout << "·· [4] Ejecutar Máquina de Turing                        ··" << endl;
        }
        cout << ".. [0] Salir                                             ··" << endl;
        cout << "···························································" << endl;
        cout << "Opción: ";
        cin >> opt;
        system("clear");

        switch (opt){
            case 0:
                return;

            case 1:
                loaded = false;
                while (!loaded){
                    cout << "Ruta del fichero de definición: ";
                    cin >> defFilename;
                    tm = new TuringMachine(defFilename);
                    if (tm->IsInitialized())
                        loaded = true;
                }
                break;

            case 2:
                if (loaded){
                    tapeLoaded = false;
                    while (!tapeLoaded){
                        cout << "Ruta del fichero de cinta: ";
                        cin >> tapeFilename;
                        tapeLoaded = tm->LoadTape(tapeFilename);
                    }
                }
                break;

            case 3:
                if (loaded){
                    cout << *tm;
                    Pausa();
                }
                break;
            case 4:
                if ((loaded)&&(tapeLoaded)){
                    tm->Run();
                    Pausa();
                }
                break;
        }
    }

}



#endif	/* MENU_H */

