#pragma once

/*!
 * \file
 * \brief Definicja klasy Scene
 * 
 * Plik zawiera definicję klasy Scene
 */

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <memory>
#include <list>

#include "obstacles.hh"
#include "example.h"
#include "lacze_do_gnuplota.hh"
#include "prism.hh"
#include "drone.hh"
#include "surface.hh"

#define NR 2

/*!
 * Scene zawiera łącze do gnuplota, tablicę dronów i płaszczyznę.
 */
class Scene {

PzG::LaczeDoGNUPlota Lacze;
//Drone *tab[NR];
std::list<std::shared_ptr<Drone>> DLst;
std::list<std::shared_ptr<Drone>>::iterator it = DLst.begin();
Surface *ground;
std::list<std::shared_ptr<Obstacles>> Lst;
std::list<std::shared_ptr<Obstacles>>::iterator iter = Lst.begin();
//Obstacles *mounttab[20];

public:
/*! 
* Konstruktor bezparametryczny klasy Cuboid 
*/
Scene();
/*! 
* Destruktor bezparametryczny klasy Cuboid
*/
~Scene();
/*! 
* Metoda rysująca elementy sceny
*/
void draw();
/*! 
* Metoda odpowiedzialna za cały interfejs
*/
void interface();

void deletename ( PzG::LaczeDoGNUPlota  &Lacze);
};