#pragma once

/*!
 * \file
 * \brief Definicja klasy Ridge
 * 
 * Plik zawiera definicję klasy Ridge 
 */



#include "solid.hh"
#include "obstacles.hh"

/*!
 * Ridge dziedziczy po klasie Solid i Obstacles
 * zawiera tylko zmienne z klas rodziców
 */
class Ridge: public Solid, public Obstacles{


   
public:

/*! 
* Konstruktor parametryczny klasy Ridge 
*/
Ridge(PzG::LaczeDoGNUPlota  &Lacze ,int nr,Vector3D mid=Vector3D(),Vector3D dimenn=Vector3D());  

/*! 
* Metoda dostępowa, zwraca typ obiektu
*/
virtual std::string gettype() override {return type;}
/*! 
* Metoda dostępowa, zwraca środek obiektu
*/
virtual Vector3D getmid()  override {return mid;}
/*! 
* Metoda dostępowa, zwraca nazwę obiektu
*/
virtual std::string getname() override {return name;}


};
