#pragma once


/*!
 * \file
 * \brief Definicja klasy Flat
 * 
 * Plik zawiera definicję klasy Flat 
 */


#include "solid.hh"


/*!
 * Flat dziedziczy po klasie Solid
 * zawiera dodatkowe pola: środek podstawy i typ.
 */
class Flat: public Solid {

protected:

std::string type="Płaskowyż";
   
public:

/*! 
* Konstruktor parametryczny klasy Flat
*/
Flat(Vector3D mid=Vector3D(), double x=100, double y=100, double z=20, std::string name="../datasets/flat.dat");  

/*! 
* Metoda dostępowa, zwraca typ obiektu
*/
std::string gettype() {return type;}

};