#pragma once

#include "Film.h"

class Filmtar {
    size_t db;
    
    Film** Tarolo;

public:
    Filmtar( ) {
        db = 0;
        Tarolo = new Film * [db];
    }

    Filmtar(const Filmtar& ez) {
        Tarolo = new Film*[ez.db];
        for (size_t i = 0; i < ez.db; i++) 
            Tarolo[i] = ez.Tarolo[i];
        db = ez.db;
    }



    Film* get_last();
    int get_db();
    void set_db(int ujdb);
    int get_capacity();
    void set_capacity(int ertek);
    void ujfilm_felvetel();


    void hozzafuz(Film& ujfilm);
    void torles(string ezt);

    void szerkesztes(string ezt);

    void savetofile();

    void kereses();

    void listaz();

    void megnyit();

    void felszabadit();



    

    //void tesztek();
};