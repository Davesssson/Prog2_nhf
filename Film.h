#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

enum class MovieType { nincs = 0, csaladi = 1, dokumentum = 2 };

class Film {
    string cim;
    int kiadaseve;
    int jatekido;
    MovieType type;

public:
    Film(string cim = "nincs", int kiadaseve = 0, int jatekido = 0, MovieType type = MovieType::nincs) :
        cim(cim), kiadaseve(kiadaseve), jatekido(jatekido), type(type) {}

    string get_cim();
    int get_kiadaseve();
    int get_jatekido();
    MovieType get_MovieType();

    void set_cim(string ujcim);
    void set_kiadaseve(int ujkiadaseve);
    void set_jatekido(int ujjatekido);
    void set_type(MovieType tipus);

    virtual void kiir();
    virtual void fajlbakiir(ofstream& os);


    virtual ~Film() {}


};