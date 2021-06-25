#pragma once

/*!
 * \file
 * \brief Definicja klasy Solid
 * 
 * Plik zawiera definicję klasy Solid
 */


#include "matrix3x3.hh"
#include "vector3D.hh"
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <fstream>
#include <vector>



/*!
 * Solid zawiera kontener na wierzchołki, wektor środka bryły, wektor pomocniczego środka, nazwę, typ,
 * nr bryły, promień obrsysu oraz wymiary.
 */
class Solid {

protected:

int nr=0;
Vector3D mid;
std:: string name;
std::vector<Vector3D> vert;
Vector3D dimen; 
std::string type="obiekt niezidentyfikowany";

public:




/*! 
* Metoda dostępowa, zwraca typ
*/
virtual std::string gettype() {return type;}
/*! 
* Operator indeksowania
*/
Vector3D &operator[](int index);
/*! 
* Operator indeksowania const
*/
Vector3D operator[](int index)const;
/*! 
* Metoda odpowiedzialna za usatwienie środka bryły
*/
void setmid (Vector3D mid);
/*! 
* Metoda odpowiedzialna za ustawienie nazwy
*/
void setname (std::string name);
/*! 
* Metoda dostępowa, zwraca środek
*/
virtual Vector3D getmid() {return mid;}
/*! 
* Metoda dostępowa, zwraca nazwę
*/
virtual std:: string getname () {return name;}
/*! 
* Metoda odpowiedzialna za przesunięcie bryły
*/
void move (Vector3D mov);
/*! 
* Metoda odpowiedzialna za translację bryły
*/
void translate (Matrix3x3 rot);
/*! 
* Metoda odpowiedzialna za zapis
*/
void save();



};
