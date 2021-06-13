#pragma once


/*!
 * \file
 * \brief Definicja klasy Flat
 * 
 * Plik zawiera definicję klasy Flat 
 */


#include "solid.hh"
//#include "obstacles.hh"

/*!
 * Flat dziedziczy po klasie Solid
 */
class Flat: public Solid {

protected:
Vector3D bmid;
std::string type="Płaskowyż";
   
public:

/*! 
* Konstruktor parametryczny klasy Cuboid
*/
Flat(Vector3D mid=Vector3D(), double x=100, double y=100, double z=20, std::string name="../datasets/flat.dat");           
/*! 
* Destruktor bezparametryczny klasy Cuboid
*/
//~Cuboid() {free (dimen);};

void setbmid (Vector3D bmid);

Vector3D getbmid() const;

std::string gettype() {return type;}

};