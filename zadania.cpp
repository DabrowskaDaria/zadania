#include <iostream>
#include <fstream>
#include <vector>

std::string logowanie(std::string login){
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

void przejrzyj_zadania(){
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

void dodaj_zad(std::string dodaj_zadanie){
    std::ofstream plik;
    plik.open("zadania.txt",std::ofstream::app);
    plik<<std::endl<<dodaj_zadanie;
    plik.close();
}

void wyk_zadania(std::string wykonane_zadanie){
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
    std::string login;
    std::cout<<"Podaj login: ";
    std::cin>>login;

    std::string wynik;
    wynik=logowanie(login);
    std::cout<<wynik<<std::endl;

    przejrzyj_zadania();
    std::cout<<std::endl;

    std::cout<<"Podaj zadanie jakie chesz dodac: "<<std::endl;
    std::string dodaj_zadanie;
    std::cin>>dodaj_zadanie;
    dodaj_zad(dodaj_zadanie);
    std::cout<<std::endl;

    std::string wykonane_zadanie;
    std::cout<<"Podaj wykonane zadanie: ";
    std::cin>>wykonane_zadanie;
    wyk_zadania(wykonane_zadanie);
}


