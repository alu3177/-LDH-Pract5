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

/**
 * Método encargado del manejo de un sencillo sistema de navegación de directorios
 * basado en una cadena con la ruta completa y un comando de entrada que puede 
 * ser bien el nombre o ruta de un directorio o el comando ".." para subir un
 * nivel.
 * @param i_currPath Contiene la ruta con la que se está trabajando
 * @param i_dir Nombre/Ruta de directorio a añadir o comando ".." para subir nivel
 */
void Dir(string &i_currPath, string const &i_dir){
    if (i_dir.empty())
        return;
    if (i_dir == ".."){
        if (i_currPath == ".")
            return;
        unsigned lastBarPos = i_currPath.find_last_of("/");
        i_currPath = i_currPath.substr(0, lastBarPos);
    }else{
        i_currPath += "/" + i_dir;
    }
}

void Menu(TuringMachine* &tm){
    bool loaded = false;
    bool tapeLoaded = false;
    string defFilename;
    string tapeFilename;
    string defDir = ".";
    string tapeDir = ".";
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
        if (loaded){
            cout << "   [Fichero *.tm cargado]  : " << defDir << "/" << defFilename << endl;
            if (tapeLoaded)
                cout << "   [Fichero *.tmt cargado] : " << tapeDir << "/" << tapeFilename << endl;
        }
        cout << endl << endl;
        cout << "Opción: ";
        cin >> opt;
        system("clear");

        switch (opt){
            case 0:
                return;

            case 1:
                loaded = false;
                getline(cin, defFilename);  // usado para "capturar" el enter de seleccionar la opción
                cout << "Ruta del fichero de definición" << endl;
                while (!loaded){
                    cout << defDir << "/> ";
                    getline(cin, defFilename);
                    if (defFilename.substr(0, 2) == "cd"){
                        Dir(defDir, defFilename.substr(3, defFilename.npos));
                    }else{
                        tm = new TuringMachine(defDir + "/" + defFilename);
                        if (tm->IsInitialized()){
                            loaded = true;
                            tapeLoaded = false;
                        }
                    }
                }
                break;

            case 2:
                if (loaded){
                    tapeLoaded = false;
                    getline(cin, tapeFilename);  // usado para "capturar" el enter de seleccionar la opción
                    cout << "Ruta del fichero de cinta" << endl;
                    while (!tapeLoaded){
                        cout << tapeDir << "/> ";
                        getline(cin, tapeFilename);
                        if (tapeFilename.substr(0, 2) == "cd"){
                            Dir(tapeDir, tapeFilename.substr(3, tapeFilename.npos));
                        }else{
                            tapeLoaded = tm->LoadTape(tapeDir + "/" + tapeFilename);
                        }
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

