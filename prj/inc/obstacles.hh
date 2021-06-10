# pragma once

/*!
 * \file
 * \brief Definicja klasy Drone
 * 
 * Plik zawiera definicję klasy Drone
 */

#include "matrix3x3.hh"
#include "vector3D.hh"
//#include "solid.hh"
#include "ridge.hh"
//#include "flat.hh"
#include "../inc/lacze_do_gnuplota.hh"


/*!
 * Drone zawiera: kąt, id, odległość do przebycia, macierz rotacji
 * oryginalne rotory, ich kopie, oryginalny kadłub, jego kopię,
 *łącze do gnu plota i rysowaną scieżkę.
 */
class Obstacles {

    int nr;
    PzG::LaczeDoGNUPlota  &Lacze;
    //Ridge ridgemount;
    //Flat flatmount;

public:
Obstacles ();
    Obstacles(int nr, PzG::LaczeDoGNUPlota  &Lacze,Vector3D dimensions, Vector3D position);

   // void save();
};