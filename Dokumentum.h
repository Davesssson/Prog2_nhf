#pragma once
#include "Film.h"

class Dokumentum :public Film {
    string leiras;
public:
    Dokumentum(string cim = "nincs", int kiadaseve = 0, int jatekido = 0, MovieType type = MovieType::nincs, string leiras = "nincs") :
        Film(cim, kiadaseve, jatekido, type), leiras(leiras) {}

    string get_leiras();
    void set_leiras(string ujleiras);
    void kiir();
    void fajlbakiir(ofstream& os);


};