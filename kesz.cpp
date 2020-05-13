#include "memtrace.h"
#include <iostream>
#include "Auxiliary.h"
#include "Csaladi.h"
#include "Dokumentum.h"
#include "Film.h"
#include "Filmtar.h"
#define MEMTRACE
//#define __cplusplus

int main()
{

    Filmtar tarolo;
    string ezt;
    string torles;

    tarolo.megnyit();

    while (true) {
        megjelenit();
        int valasz;
        cin >> valasz;

        switch (valasz) {
        case 1:
            tarolo.listaz();
            break;
        case 2:
            tarolo.ujfilm_felvetel();
            break;
        case 3:
            tarolo.kereses();
            break;
        case 4:
            tarolo.listaz();
            cout << "[Melyik filmet szeretne torolni?]\n";
            cin.ignore(1, '\n');
            getline(cin, torles);
            tarolo.torles(torles);
            break;
        case 5:
            tarolo.listaz();
            cout << "[Melyik filmet szeretned szerkeszteni?]\n" << endl;
            cin.ignore(1, '\n');
            getline(cin, ezt);
            tarolo.szerkesztes(ezt);
            break;
        case 9:
            tarolo.felszabadit();
            return 0;
        }
    }
}
