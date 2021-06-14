#pragma once


/*!
 * \file
 * \brief Definicja klasy Peak
 * 
 * Plik zawiera definicję klasy Peak 
 */


#include "solid.hh"


/*!
 * Peak dziedziczy po klasie Solid
 * zawiera dodatkowe pola: środek podstawy i typ.
 */
class Peak: public Solid {

protected:

std::string type="Góra ze szczytem";

   
public:

/*! 
* Konstruktor parametryczny klasy Peak 
*/
Peak(Vector3D mid=Vector3D(), double x=100, double y=100, double z=20, std::string name="../datasets/peak.dat");           


/*! 
* Metoda dostępowa, zwraca typ obiektu
*/
std::string gettype() {return type;}

};