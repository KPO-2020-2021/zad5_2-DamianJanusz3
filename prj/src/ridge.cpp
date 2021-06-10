#include "ridge.hh"


Ridge::Ridge(Vector3D mid, double x, double y, double z, std::string name) { 

    double tab[]={x,y,z};
    double tab2[]={0,0,z/2};
    double tab3[]={x/2,0,0};
    dimen=Vector3D(tab);
    Vector3D mov(tab2);
    Vector3D mov2(tab3);
    this->name=name;
    this->bmid=mid-mov;
    Vector3D vertex;

    vertex[0]=mid[0]+(x/2);
   vertex[1]=mid[1]+(y/2);
   vertex[2]=mid[2]+(z/2);
   vert.push_back(vertex);

   vertex[0]=mid[0]-(x/2);
   vertex[1]=mid[1]+(y/2);
   vertex[2]=mid[2]-(z/2);
   vert.push_back(vertex);

   vertex[0]=mid[0]+(x/2);
   vertex[1]=mid[1]+(y/2);
   vertex[2]=mid[2]+(z/2);
   vert.push_back(vertex);

   vertex[0]=mid[0]+(x/2);
   vertex[1]=mid[1]+(y/2);
   vertex[2]=mid[2]-(z/2);
   vert.push_back(vertex);

   vertex[0]=mid[0]+(x/2);
   vertex[1]=mid[1]-(y/2);
   vertex[2]=mid[2]+(z/2);
   vert.push_back(vertex);

   vertex[0]=mid[0]+(x/2);
   vertex[1]=mid[1]-(y/2);
   vertex[2]=mid[2]-(z/2);
   vert.push_back(vertex);

   vertex[0]=mid[0]+(x/2);
   vertex[1]=mid[1]-(y/2);
   vertex[2]=mid[2]+(z/2);
   vert.push_back(vertex);

   vertex[0]=mid[0]-(x/2);
   vertex[1]=mid[1]-(y/2);
   vertex[2]=mid[2]-(z/2);
   vert.push_back(vertex);

    this->mid=mid+mov2;
}

/*! 
* Metoda odpowiedzialna za ustawianie środka     
* \param[in]  - mid -srodek,                                              
* Przypisuje odpowiedniej zmiennej z klasy, srodek podany w argumencie 
*/
void Ridge::setbmid (Vector3D bmid){
this->bmid=bmid;
}

/*! 
* Metoda odpowiedzialna za zwracanie środka     
* \param[in]  - brak,                                              
* Funkcja dostępowa do środka, zwraca środek bryły  
*/
Vector3D Ridge::getbmid() const{
return bmid;
}
