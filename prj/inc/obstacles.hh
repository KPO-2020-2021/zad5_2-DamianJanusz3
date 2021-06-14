# pragma once

/*!
 * \file
 * \brief Definicja klasy Obstacles
 * 
 * Plik zawiera definicję klasy Obstacles
 */

#include "matrix3x3.hh"
#include "vector3D.hh"
//#include "solid.hh"
#include "ridge.hh"
#include "flat.hh"
#include "peak.hh"
#include "../inc/lacze_do_gnuplota.hh"


/*!
 * Obstacles zawiera: numer obiektu, łącze do gnuplota, 3 liczniki dla poszczególnych
 * przeszkód, 3 zmienne reprezentujące różne typy przeszkód
 */
class Obstacles { 

    int nr;
    PzG::LaczeDoGNUPlota  &Lacze;
    int nextr=0, nextf=0, nextp=0;
    Flat fla2;
    Ridge rid2;
    Peak pea2;
    

public:
/*! 
* Konstruktor bezparametryczny klasy Obstacles
*/
Obstacles ();
/*! 
* Konstruktor parametryczny klasy Obstacles
*/
Obstacles(int nr,int next, PzG::LaczeDoGNUPlota  &Lacze,Vector3D dimensions, Vector3D position);

/*! 
* Metoda dostępowa, zwraca środek 
*/
  Vector3D getmid();
/*! 
* Metoda dostępowa, zwraca typ
*/
  std::string gettype();
/*! 
* Metoda dostępowa, zwraca nazwę
*/
  std::string getname();
};