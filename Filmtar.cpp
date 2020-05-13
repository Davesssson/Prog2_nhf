#include "Filmtar.h"
#include "Csaladi.h"
#include "Dokumentum.h"
#include "Auxiliary.h"
#include <string.h>
#include <stdio.h>

using namespace std;



Film* Filmtar::get_last() {
    return Tarolo[db];
}


int Filmtar::get_db() {
    return db;
}
void Filmtar::set_db(int ujdb) {
    db = ujdb;
}

void  Filmtar::ujfilm_felvetel() {
    string cim, leiras;
    int jatekido, kiadaseve;
    MovieType tipus;
    int korhatar;
    Film* ujfilm;
    int valasztas;

    cout << "[Az uj filmnek a cime]\t";
    cin.ignore(1, '\n');
    getline(cin, cim);

    cout << "[Az uj film megjelenesenek eve]\t";
    cin.ignore(0, '\n');
    cin >> kiadaseve;

    cout << "[Az uj film hossza percben]\t";   
    cin.ignore(1, '\n');
    cin >> jatekido;

    cout << "[Az uj film tipusa]\n" << "\t[1 - Dokumentumfilm]\n" << "\t[2 - Csaladifilm]\n";
    cin.ignore(1, '\n');
    cin >> valasztas;


    if (valasztas == 1) {
        tipus = MovieType::dokumentum;
        cout << "[Az uj film leirasa]\t";
        cin.ignore(1, '\n');
        getline(cin, leiras,'\n');
        ujfilm = new Dokumentum(cim, kiadaseve, jatekido, tipus, leiras);
        hozzafuz(*ujfilm);
    }
    else if (valasztas == 2) {
        tipus = MovieType::csaladi;
        cout << "[Az uj film korhatara]\t";
        cin.ignore(1, '\n');
        cin >> korhatar;
        ujfilm = new Csaladi(cim, kiadaseve, jatekido, tipus, korhatar);
        hozzafuz(*ujfilm);
    }
    savetofile();

}

void Filmtar::hozzafuz(Film& ujfilm) {

    Film** ujTarolo = new Film * [db + 1];
    for (size_t i = 0; i < db; i++){
        ujTarolo[i] = Tarolo[i];
    }
    ujTarolo[db] = &ujfilm;
    delete[] Tarolo;
    Tarolo = ujTarolo;
    db += 1;

}
void Filmtar::torles(string ezt) {
    bool megvan = false;
    size_t i = 0;
    for (; i < db; i++) {
        if (Tarolo[i]->get_cim() == ezt) {
            delete Tarolo[i];
            megvan = true;
        }
        if (megvan) {
            for (size_t j = i; i < db; i++) {
                Tarolo[j] = Tarolo[j + 1];
                db--;
                savetofile();
                cout << "\n[Film sikeresen torolve!]\n";
                return;
            }
        }
    }
    cout << "\n[Nem talaltam meg a filmet] (biztos hogy letezik?)\n";




}

void Filmtar::szerkesztes(string ezt) {

    int valasztas;
/*!!*/int ujjatekido, ujkiadaseve;

    string ujcim;
    bool megtalaltam = false;
    for (size_t i = 0; i < db; i++) {
        if (Tarolo[i]->get_cim() == ezt) {
            megtalaltam = true;
            do {
                cout << "\n[Mit szeretnel valtoztatni?]\n" << endl;
                cout << "[1 - Cimet]" << "\n" << "[2 - Jatekidot]" << "\n" << "[3 - Kiadas evet]" << "\n"
                    << "[9 - befejeztem ennek a filmnek a szerkeszteset]\n" << endl;



                cin >> valasztas;
                switch (valasztas) {
                case 1:
                    cout << "[Adjon meg egy uj cimet]" << endl;

                    cin.ignore(1, '\n');

                    getline(cin, ujcim);
                    Tarolo[i]->set_cim(ujcim);
                    savetofile();
                    break;
                case 2:
                    cout << "[Adjon meg uj jatekidot]" << endl;
//!!!!!!!!
                    cin.get();
                    //ujjatekido = robosztus_szamotbeolvas(ujjatekido);
                    cin.ignore(0, '\n');
                    cin >> ujjatekido;

                    Tarolo[i]->set_jatekido(ujjatekido);
                    savetofile();
                    break;
                case 3:
                    cout << "[Adja meg az uj kiadasevet]" << endl;
                    cin.get();

  //!!             //ujkiadaseve = robosztus_szamotbeolvas(ujkiadaseve);
                    cin.ignore(0, '\n');
                    cin >> ujkiadaseve;


                    Tarolo[i]->set_kiadaseve(ujkiadaseve);
                    savetofile();
                    break;

                default:
                    cout << "normalis gombot nyomjal meg mert szetbaszom a fejed" << endl;
                    break;
                }
            } while (valasztas != 9);
        }

    }if (!megtalaltam)
        cout << "nem talaltam meg";


}

void Filmtar::savetofile() {
    ofstream output;
    output.open("filmek.txt");

    if (!output.is_open()) {
        throw "nem tudtam megnyitni";
    }
    else {
        for (size_t i = 0; i < db; i++) {
            if (Tarolo[i]->get_MovieType() == MovieType::csaladi) {
                output << "Csaladi" << "\t";
                Tarolo[i]->fajlbakiir(output);
                output << "\n";
            }
            if (Tarolo[i]->get_MovieType() == MovieType::dokumentum) {
                output << "Dokumentum" << "\t";
                Tarolo[i]->fajlbakiir(output);
                output << "\n";
            }
        }
        output.close();
    }
}

void Filmtar::kereses() {
    cout << "Mi alapjan akarsz keresni?" << endl;
    cout << "1 - cim\n" << "2 - jatekido\n" << "3 - kiadaseve\n" << "4 - tipus\n" << endl;
    cin.get();
    int valasztas;
    int jatekidokereses;
    int kiadasevekeres;
    int ujravalasztas;

    cin.ignore(0, '\n');
    cin >> valasztas;
    if (valasztas == 1) {

        cout << "[Add meg a cimet!]" << endl;
        string cimkeres;
        cin.ignore(1, '\n');
        getline(cin, cimkeres);

        bool megtalalva = false;
        for (size_t i = 0; i < db; i++) {

            if (Tarolo[i]->get_cim()==cimkeres ) {
                Tarolo[i]->kiir();
                megtalalva = true;
                break;

            }
        }
        if (!megtalalva) {
            cout << "\n[Nincs ilyen film]\n\n";
        }

    }
    if (valasztas == 2) {
        cout << "[Hany perces filmet keres?]" << endl;

        cin.ignore(1, '\n');
        cin >> jatekidokereses;

        bool megtalalva = false;
        for (size_t i = 0; i < db; i++) {
            if (Tarolo[i]->get_jatekido() == jatekidokereses) {
                Tarolo[i]->kiir();
                megtalalva = true;
                break;
            }
        }
        if (!megtalalva)
            cout << "\n[Nincs ilyen film]\n\n";
    }
    if (valasztas == 3) {
        cout << "[Mikori filmet keres?]" << endl;

        cin.ignore(1, '\n');
        cin >> kiadasevekeres;

        bool megtalalva = false;
        for (size_t i = 0; i < db; i++) {
            if (Tarolo[i]->get_kiadaseve() == kiadasevekeres) {
                Tarolo[i]->kiir();
                megtalalva = true;
                break;
            }

        }
        if (!megtalalva) {
            cout << "\n[Nincs ilyen film]\n\n";
        }
    }



    if (valasztas == 4) {
        cout << "Milyen filmet keres" << endl;
        cout << "[1 - Dokumentumfilm]\n" << "[2 - Csaaldifilm]" << endl;




      
        cin.ignore(1, '\n');
        cin >> ujravalasztas;


        if (ujravalasztas == 1) {
            bool megtalaltam = false;
            for (size_t i = 0; i < db; i++) {
                if (Tarolo[i]->get_MovieType() == MovieType::dokumentum) {
                    Tarolo[i]->kiir();
                    megtalaltam = true;

                }
                if (!megtalaltam) {
                    cout << "\n[Nincs ilyen film]\n";
                }
            }
        }
        if (ujravalasztas == 2) {
            bool megtalaltam = false;
            for (size_t i = 0; i < db; i++) {
                if (Tarolo[i]->get_MovieType() == MovieType::csaladi) {
                    Tarolo[i]->kiir();
                    megtalaltam = true;

                }
                if (!megtalaltam) {
                    cout << "\n[Nincs ilyen film]\n";
                }

            }
        }

    }
    else if (valasztas > 2 || valasztas < 0) {
        cout << "\nErvenytelen keresesi mod\n";
    }
}

void Filmtar::listaz() {
    if (db == 0) {
        cout << "\n[Nincs film a taroloban]\n";
    }
    for (size_t i = 0; i < (size_t)this->get_db(); i++) {
        Tarolo[i]->kiir();
    }
}

void Filmtar::megnyit() {
    string filename = "filmek.txt";
    ifstream input;
    Film* uj;
    input.open(filename);

    if (!input.is_open()) {
        throw "[Nem tudtam megnyitni a fajlt]";
        return;
    }
    string cim, leiras, tipus;
    int jatekido, kiadaseve;

    while (input) {
        getline(input, tipus, '\t');

        if (tipus== "Csaladi")  {
            getline(input, cim, '\t');
            int korhatar;
            input >> jatekido >> kiadaseve >> korhatar;
                        
            uj = new Csaladi(cim, kiadaseve, jatekido, MovieType::csaladi, korhatar);
            hozzafuz(*uj);
            input.ignore(1, '\n');
            
        }
        else if (tipus== "Dokumentum")  {
            getline(input, cim, '\t');
            input >> jatekido >> kiadaseve;
            input.get();

            string leiras;
            getline(input, leiras);   
            
            uj = new Dokumentum(cim, kiadaseve, jatekido, MovieType::dokumentum, leiras);
            hozzafuz(*uj);                    
        }
         input.get();
    }
    input.close();
}

void Filmtar::felszabadit() {
    for (size_t i = 0; i < db; i++) {
        delete Tarolo[i];
    }
    db = 0;
}

//void Filmtar::tesztek() {
//
//    Film f = Film("Filmcime", 1980, 120, MovieType::nincs);
//    if (f.get_cim() == "Filmcime")
//        cout << "sikeres teszt" << endl;
//    else
//        cout << "sikertelen teszt" << endl;
//
//    Csaladi cs = Csaladi("Ennek a filmnek a cime", 2020, 150, MovieType::csaladi, 30);
//    if (cs.get_korhatar() == 30)
//        cout << "siekres teszt (csaladi)";
//    else
//        cout << "sikertelen teszt (csaladi)" << endl;
//
//    this->hozzafuz(new Dokumentum("harmadik film mcime", 2000, 90, MovieType::dokumentum, "leiras"));
//    if (this->get_db() != 0)
//        cout << "sikeres teszt (hozzafuz)" << endl;
//    else
//        cout << "sikertelen teszt (hozzafuz)" << endl;
//
//
//}

