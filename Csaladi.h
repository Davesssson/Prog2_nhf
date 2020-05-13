#pragma once

#include "Film.h"

class Csaladi :public Film {
    int korhatar;
public:
    Csaladi(string cim = "nincs", int kiadaseve = 0, int jatekido = 0, MovieType type = MovieType::nincs, int korhatar = 0) :
        Film(cim, kiadaseve, jatekido, type), korhatar(korhatar) {}
    int get_korhatar();
    void set_korhatar(int ujkorhatar);
    void kiir();
    void fajlbakiir(ofstream& os);


};
