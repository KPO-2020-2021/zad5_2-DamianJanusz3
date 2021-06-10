#pragma once

/*!
 * \file
 * \brief Definicja klasy Ridge
 * 
 * Plik zawiera definicję klasy Ridge 
 */


//#include "solid.hh"
#include "obstacles.hh"
#include "solid.hh"

/*!
 * Ridge dziedziczy po klasie Solid
 */
class Ridge: public Solid{

protected:
Vector3D bmid;

   
public:

/*! 
* Konstruktor parametryczny klasy Cuboid
*/
Ridge(Vector3D mid=Vector3D(), double x=100, double y=100, double z=100, std::string name="../datasets/ridge.dat");           
/*! 
* Destruktor bezparametryczny klasy Cuboid
*/
//~Cuboid() {free (dimen);};

void setbmid (Vector3D bmid);

Vector3D getbmid() const;

};