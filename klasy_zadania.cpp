#include <iostream>
#include <fstream>
#include <vector>

class Zadania{

public:
    std::string logowanie(std::string login);
    void przejrzyj_zadania();
    void dodaj_zad(std::string dodaj_zadanie);
    void wyk_zadania(std::string wykonane_zadanie);
};

std::string Zadania::logowanie(std::string login){
    std::ifstream(plik);
    plik.open("login.txt");
    std::string nowy_string;
    while(std::getline(plik,nowy_string)){
        if(nowy_string==login){
            return "ok";
        }else{
            return "blad";
        }
    }
    plik.close();
}

void Zadania::przejrzyj_zadania(){
    std::ifstream(plik);
    plik.open("zadania.txt");
    std::string czytanie_wierszy;
    std::string nowy;
    for(int i=0;plik>>czytanie_wierszy;){
        nowy+=czytanie_wierszy+" ";
    }
    std::cout<<nowy<<std::endl;
    plik.close();
}

void Zadania::dodaj_zad(std::string dodaj_zadanie){
    std::ofstream plik;
    plik.open("zadania.txt",std::ofstream::app);
    plik<<std::endl<<dodaj_zadanie;
    plik.close();
}

void Zadania::wyk_zadania(std::string wykonane_zadanie){
    std::ifstream(plik);
    plik.open("zadania.txt");
    std::string nowy_string;
    std::string wykonane_zad;
    std::fstream(plik_z);
    plik_z.open("zadania.txt");
    while(std::getline(plik,nowy_string)){
           if(nowy_string==wykonane_zadanie){
                nowy_string+=" WYKONANE";
            }
            wykonane_zad+=nowy_string+="\n";
        }
        plik_z<<wykonane_zad;
    plik.close();
}



int main(){
    Zadania zadania;
    std::cout<<"Podaj login: "<<std::endl;
    std::string login;
    std::cin>>login;
    std::cout<<zadania.logowanie(login)<<std::endl;

    zadania.przejrzyj_zadania();

    std::cout<<"Jakie zadanie chcesz dodac: "<<std::endl;
    std::string dodaj_zadanie;
    std::cin>>dodaj_zadanie;
    zadania.dodaj_zad(dodaj_zadanie);

    std::cout<<"Podaj wykonane zadanie: "<<std::endl;
    std::string wykonane_zadanie;
    std::cin>>wykonane_zadanie;
    zadania.wyk_zadania(wykonane_zadanie);


}
