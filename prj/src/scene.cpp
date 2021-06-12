/*!
 * \file
 * \brief plik źródłowy
 * 
 * Plik zawiera wszystkie metody klasy Scene
 */
#include "scene.hh"

 /*! 
* Konstruktor bezparametryczny klasy Scene. 
* \param[in]  - brak,                
* Ustawia zakresy rysowania, tworzy płaszczyznę,
* losuje pozycje dla dronów i je roztawia  
*/
Scene::Scene(){

Lacze.ZmienTrybRys(PzG::TR_3D);

Lacze.UstawZakresX(-400, 400);
Lacze.UstawZakresY(-400, 400);
Lacze.UstawZakresZ(-100, 400);

double tab1[3]={800,800,0};
Vector3D dimground(tab1);
ground=new Surface(dimground,30);
Lacze.DodajNazwePliku(ground->getname().c_str(),PzG::RR_Ciagly, 2);
ground->save();
/////////////////
//double place[3]{(double)(rand()%510-200),50/*(double)(rand()%510-200)*/,50};
//double place2[3]{(double)(rand()%510-200),-50/*(double)(rand()%510-200)*/,50};
//Vector3D a(place2); 
double x=100, y=100, z=100, k=50, l=50, i=-50, j=-50, zz=40, g=-30, h=20, m=50, n=-50;//, nr=1;
double place2[3]{k,l,z/4}; double wym2[3]{x,y,z}; 
double place3[3]{i,j,zz/4}; double wym3[3]{x,y,zz};
double place4[3]{g,h,zz/4}; double wym4[3]{x,y,zz};
double place5[3]{m,n,z/4}; double wym5[3]{x,y,z}; 
Vector3D a(place2);Vector3D d(wym2);
Vector3D a2(place3); Vector3D d2(wym3);
Vector3D a3(place4); Vector3D d3(wym4);
Vector3D a4(place5); Vector3D d4(wym5);
//std::string name="../datasets/ridge.dat";
//mounttab[0]=new Obstacles(1,Lacze,Vector3D(place));
//mounttab[1]=new Obstacles(2,Lacze,Vector3D(place2));
//for (int i=0; i<2; ++i)
//mounttab[i]->save();
Lst.push_back(std::make_shared<Obstacles>(1,0,Lacze,d,a));
Lst.push_back(std::make_shared<Obstacles>(2,0,Lacze,d2,a2));
Lst.push_back(std::make_shared<Obstacles>(3,0,Lacze,d3,a3));
Lst.push_back(std::make_shared<Obstacles>(3,1,Lacze,d4,a4));
///////////////////
for (int i=0; i<NR; ++i){
double position[3]{(double)(rand()%510-200),(double)(rand()%510-200),30};
tab[i]=new Drone (i,Lacze,Vector3D(position));
tab[i]->save();
}
Lacze.Rysuj(); 
}

 /*! 
* Metoda draw     
* \param[in]  - brak,                                                 
* Rysuje w gnuplocie     
*/
void Scene::draw(){

Lacze.Rysuj();

}

 /*! 
* Metoda interface     
* \param[in]  - brak,                                                 
* odpowiedzialna za kontakt z użytkownikiem,
* posiada całe menu użytkownika    
*/
void Scene::interface(){

Vector3D vec;

std::cout<<"Program dragonfly - faza 1"<<std::endl<<std::endl;
std::cout<<"a - wybierz aktywnego drona"<<std::endl;
std::cout<<"p - zadaj parametry przelotu"<<std::endl;
std::cout<<"d - dodaj element powierzchni"<<std::endl;
std::cout<<"u - usuń element powierzchni"<<std::endl;
std::cout<<"m - wyswietl menu"<<std::endl<<std::endl;
std::cout<<"k - koniec dzialania programu"<<std::endl<<std::endl;

    char action;
    int r=0,num=0, nextr=1,nextf=1,nextp=2;
    double x, y;
    Vector3D dimens;  
    Vector3D a;
    
    do {
    
    std::cout<<"Twoj wybor (m - menu):";
    std::cin>>action;
    switch (action){

        case 'a':
        std::cout<<"Wybor aktywnego drona"<<std::endl<<std::endl;
        std::cout<<"0 - pierwszy dron"<<std::endl;
        std::cout<<"1 - drugi dron"<<std::endl<<std::endl;

        std::cout<<"Wprowadz numer drona:";
        std::cin>>r;
            if(r<NR) {
                ;
            }
            else{
                std::cerr<<"brak drona o podanym numerze."<<std::endl;
                r=0;
            }
        break;

        case 'p':
        tab[r]->manipulate();
        break;

        case 'd':
        std::cout<<"Wybierz rodzaj powierzchniowego elementu"<<std::endl<<std::endl;
        std::cout<<"1 - Gora z grania"<<std::endl;
        std::cout<<"2 - Plaskowyz"<<std::endl;
        std::cout<<"3 - Gora z ostrym sztytem"<<std::endl;
        std::cout<<"Wprowadz numer typu elementu> ";
        std::cin>>num;
        std::cout<<std::endl<<std::endl<<"Podaj scale wzdluz kolejnych osi OX, OY, OZ."<<std::endl;
        std::cout<<"Wprowadz skale: OX OY OZ> ";
        std::cin>>dimens;
        std::cout<<std::endl<<std::endl<<"Podaj wspolrzedne srodka podstawy x,y."<<std::endl;
        std::cout<<"Wprowadz wspolrzedne: x y>  ";
        std::cin>>x; std::cin>>y;
        a[0]=x; a[1]=y; a[2]=dimens[2]/4;
        

        
        if(num==1){Lst.push_back(std::make_shared<Obstacles>(1,nextr,Lacze,dimens,a)); ++nextr;}
        else if(num==2){Lst.push_back(std::make_shared<Obstacles>(2,nextf,Lacze,dimens,a)); ++nextf;}
        else if(num==3){Lst.push_back(std::make_shared<Obstacles>(3,nextp,Lacze,dimens,a)); ++nextp;}
        else {std::cerr<<"Nie ma bryły o takim numerze"<<std::endl;}

        break;


        case 'm':
        std::cout<<"a - wybierz aktywnego drona"<<std::endl;
        std::cout<<"p - zadaj parametry przelotu"<<std::endl;
        std::cout<<"d - dodaj element powierzchni"<<std::endl;
        std::cout<<"u - usuń element powierzchni"<<std::endl;
        std::cout<<"m - wyswietl menu"<<std::endl<<std::endl;
        std::cout<<"k - koniec dzialania programu"<<std::endl<<std::endl;
        break;

        case 'k':
        std::cout<<"koniec działania programu"<<std::endl;
        break;

        default:
        break;
    }
    draw();
    std::cout<<std::endl;
  vec.vecamount(std::cout);
  std::cout<<std::endl;
    } while (action!='k');
}
 /*! 
* Destruktor bezparametryczny klasy Scene.      
* \param[in]  - brak,                                                 
* niszczy nieużywną już, dynamicznie alokowaną pamięć     
*/
Scene::~Scene()
 {
free (ground);
for(int i=0; i<NR; i++)
free (tab[i]);
//for(int j=0; j<2; j++)
//free (mounttab[j]);
 }