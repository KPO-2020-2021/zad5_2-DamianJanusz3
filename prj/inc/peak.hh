#pragma once


/*!
 * \file
 * \brief Definicja klasy Peak
 * 
 * Plik zawiera definicję klasy Peak 
 */


#include "solid.hh"
//#include "obstacles.hh"

/*!
 * Peak dziedziczy po klasie Solid
 */
class Peak: public Solid {

protected:
Vector3D bmid;
std::string type="Góra ze szczytem";

   
public:

/*! 
* Konstruktor parametryczny klasy Cuboid
*/
Peak(Vector3D mid=Vector3D(), double x=100, double y=100, double z=20, std::string name="../datasets/peak.dat");           
/*! 
* Destruktor bezparametryczny klasy Cuboid
*/
//~Cuboid() {free (dimen);};

void setbmid (Vector3D bmid);

Vector3D getbmid() const;

std::string gettype() {return type;}

};