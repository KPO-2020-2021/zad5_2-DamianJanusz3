#pragma once

/*!
 * \file
 * \brief Definicja klasy Ridge
 * 
 * Plik zawiera definicję klasy Ridge 
 */



#include "solid.hh"

/*!
 * Ridge dziedziczy po klasie Solid
 * zawiera dodatkowe pola: środek podstawy i typ.
 */
class Ridge: public Solid{

protected:

std::string type="Góra z granią";

   
public:

/*! 
* Konstruktor parametryczny klasy Ridge
*/
Ridge(Vector3D mid=Vector3D(), double x=100, double y=100, double z=100, std::string name="../datasets/ridge.dat");  

/*! 
* Metoda dostępowa, zwraca typ obiektu
*/
std::string gettype() {return type;}

};