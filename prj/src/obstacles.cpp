#include "obstacles.hh"

/*! 
* Konstruktor parametryczny klasy Drone. 
* \param[in]  - id -numer drona,   
* \param[in]  - Lacze -łącze do gnoplota,  
* \param[in]  - position -wektor określający położenie drona, 
* Ustawia zakresy rysowania, tworzy płaszczyznę,
* losuje pozycje dla dronów i je roztawia  
*/
Obstacles::Obstacles(int nr, int next,PzG::LaczeDoGNUPlota  &Lacze,Vector3D dimensions, Vector3D position):Lacze(Lacze){
double x=dimensions[0]; double y=dimensions[1]; double z=dimensions[2];
std::string name=" ";
this->nr=nr;
if (nr==1) {
  Ridge rid(position,x,y,z,name);
rid.setname("../datasets/rmountain"+std::to_string(nr)+std::to_string(next)+".dat");
Lacze.DodajNazwePliku(rid.getname().c_str(), PzG::RR_Ciagly, 2);
rid.move(position);
rid.save();
//this->nextr++;
}
else if(nr==2) {
  //flatmount.setname("../datasets/fmountain"+std::to_string(nr)+".dat");
//Lacze.DodajNazwePliku(flatmount.getname().c_str(), PzG::RR_Ciagly, 2);
//flatmount.move(position);
Flat fla(position,x,y,z,name);
fla.setname("../datasets/fmountain"+std::to_string(nr)+std::to_string(next)+".dat");
Lacze.DodajNazwePliku(fla.getname().c_str(), PzG::RR_Ciagly, 2);
fla.move(position);
fla.save();
//this->nextf++;
}
else if(nr==3) {
  //std::cout<<nextp<<std::endl;
Peak pea(position,x,y,z,name);
pea.setname("../datasets/pmountain"+std::to_string(nr)+std::to_string(next)+".dat");
Lacze.DodajNazwePliku(pea.getname().c_str(), PzG::RR_Ciagly, 2);
pea.move(position);
pea.save();
//makepeak(nr,Lacze,position,x,y,z,name);
//nextp1();
//nextp=nextp+1;
//std::cout<<nextp<<std::endl;
}
else{std::cout<<"_______________"<<std::endl;}

//nextp++;
//std::cout<<nextp<<std::endl;
}


/*void Obstacles::makepeak(int nr,PzG::LaczeDoGNUPlota  &Lacze, Vector3D position,double x,double y,double z,std::string name) {
  Peak pea(position,x,y,z,name);
pea.setname("../datasets/pmountain"+std::to_string(nr)+std::to_string(0)+".dat");
Lacze.DodajNazwePliku(pea.getname().c_str(), PzG::RR_Ciagly, 2);
pea.move(position);
pea.save();

nextp1();
}



void Obstacles::nextp1(){
  this->nextp+=1;
}*/
/*! 
* Metoda odpowiedzialna za zapis wierzchołków    
* \param[in]  - brak, 
* Zapisuje współrzędne wierzchołków do pliku 
*/
//void Obstacles::save()
//{
//  if (this->nr==1) 
    //rid.save();
//    ;

//  else if(this->nr==2)
  //flatmount.save();
 // ;
     /* std::fstream file;

    file.open(name, std::ios::out);
 for (int i = 0; i < (int)vert.size(); i++)
 {
   if(i%counter==0) {
   file<<std::endl;
   }
   file<<vert[i]<<std::endl;
 }
   
    file.close();*/
//}
