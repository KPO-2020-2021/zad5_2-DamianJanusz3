/*!
 * \file
 * \brief plik źródłowy
 * 
 * Plik zawiera wszystkie metody klasy Drone 
 */
#include "drone.hh"

/*! 
* Konstruktor parametryczny klasy Drone. 
* \param[in]  - id -numer drona,   
* \param[in]  - Lacze -łącze do gnoplota,  
* \param[in]  - position -wektor określający położenie drona,             
* Ustawia nazwy plików, dodaje je do gnuplota, ustawia promień obrysu i typ 
*/
Drone::Drone(int id,PzG::LaczeDoGNUPlota  &Lacze,Vector3D position):Obstacles(Lacze){ 

angle=0;
this->id=id;

org.setname("../datasets/body"+std::to_string(id)+".dat");

 for (int i = 0; i < 4; ++i)
    orgw[i].setname("../datasets/rotor" + std::to_string(id) + std::to_string(i) + ".dat");

Lacze.DodajNazwePliku(org.getname().c_str(), PzG::RR_Ciagly, 2); 
for (int j = 0; j < 4; ++j)
Lacze.DodajNazwePliku(orgw[j].getname().c_str(),PzG::RR_Ciagly,2);
cpy=org;

cpy.move(position);

for (int k=0; k<4; ++k) {
    cpyw[k]=orgw[k];
}
for (int l = 0; l < 4; l++) {
        cpyw[l].move(org[l*2] + position);
}
    this->path = this->path + position;
    this->mid =position;
this->type="Dron";
this->save();
}

/*! 
* Metoda odpowiedzialna za ruch pionowy drona. 
* \param[in]  - path -długość drogi,                
* Porusza dronem w górę i w dół  
*/
void Drone::verticalmove(double path) {

    Vector3D patho;
    patho[2]=path;

    this->path = this->path + patho;
    cpy.translate(rot);
    cpy.move(this->path);
}

/*! 
* Metoda odpowiedzialna za ruch poziomy drona. 
* \param[in]  - path -długość drogi,                
* Porusza dronem na zadaną odległość  
*/
void Drone::move(double path) {
    Vector3D patho;
    patho[0]=path*cos(angle*M_PI/180);
    patho[1]=path*sin(angle*M_PI/180);

    this->path=this->path+patho;
    cpy.translate(rot);
    cpy.move(this->path);
}

/*! 
* Metoda odpowiedzialna za rotację drona. 
* \param[in]  - angle -kąt obrotu,
* Obraca dronem o zadany kąt  
*/
void Drone::rotate(double angle) {
    this->angle+=angle;
    Matrix3x3 m;
    Matrix3x3 n; n.make3DZ(this->angle);
    rot=m*n;
    cpy.translate(rot);
    cpy.move(this->path);

}

/*! 
* Metoda odpowiedzialna za obrót rotorów. 
* \param[in]  - brak,                
* Obraca rotorami wokół ich środka i przesuwa 
* te rotory na swoje miejsca
*/
void Drone::rotatew() {

    static int angle1=0;
    static int angle2=0;
    angle1+=3;
    angle2-=3;
    if(angle1==360)
    angle1=0;

    if(angle2==-360)
    angle2=0;

    Matrix3x3 m;
    Matrix3x3 n; n.make3DZ(angle1);
    m=m*n;
    Matrix3x3 y;
    Matrix3x3 t; t.make3DZ(angle2);
    y=y*t;

    for (int i = 0; i < 4; i+=2){
        cpyw[i].translate(y);
    }

    for (int j = 0; j < 4; j+=2)
    {
        cpyw[j].move(cpy[j * 2]);
    }

    for (int k = 1; k < 4; k+=2){
        cpyw[k].translate(m);
    }

    for (int l = 1; l < 4; l+=2)
    {
        cpyw[l].move(cpy[l * 2]);
    }
}

/*! 
* Metoda odpowiedzialna za zapis. 
* \param[in]  - brak,                
* Wywołuje kolejne funkcje save dla kadłuba i rotorów
*/
void Drone::save() {
    cpy.save();
    for (int i = 0; i < 4; i++)
        cpyw[i].save();
        
}


/*! 
* Metoda odpowiedzialna za wyznaczenie trasy. 
* \param[in]  - path -droga do przebycia,                
* Zapisuje w kontenerze drogę, którą przebędzie dron
* i zapisuje ją do pliku
*/
void Drone::calculatepath(double path, double angle1) {



    Vector3D next = cpy.getmid();
    next[2] = 0;
    pathr.push_back(next);
    next[2] = 100;
    pathr.push_back(next);
    next[0] += path * cos(angle1 * M_PI / 180);
    next[1] += path * sin(angle1 * M_PI / 180);
    pathr.push_back(next);
    next[2] = 0;
    pathr.push_back(next);

    std::fstream file;

    file.open("../datasets/path.dat", std::ios::out);
    for (int i = 0; i < (int)pathr.size(); i++)
    {

        file << pathr[i] << std::endl;
    }
    file.close();

    }

