# pragma once

/*!
 * \file
 * \brief Definicja klasy Obstacles
 * 
 * Plik zawiera definicję klasy Obstacles
 */


#include "../inc/lacze_do_gnuplota.hh"




/*!
 * Obstacles zawiera:  łącze do gnuplota, 
 */
class Obstacles { 
public:

    
    PzG::LaczeDoGNUPlota  &Lacze;
    


/*! 
* Konstruktor parametryczny klasy Obstacles
*/
Obstacles(PzG::LaczeDoGNUPlota  &Lacze):Lacze(Lacze) { };

 




};
