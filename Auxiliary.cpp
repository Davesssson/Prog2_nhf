#include "Auxiliary.h"
#include <iostream>


using namespace std;



void megjelenit() {
    cout << "Mit szeretnel csinalni?\n" << "1 - Tarolo megtekintese\n" << "2 - Film felvetele\n" << "3 - Kereses\n" << "4 - Torles\n" << "5 - Szerkesztes\n" << "9 - Kilepes\n" << endl;
}

int char_to_int(string param) {
    return atoi(param.c_str());

}
bool isint(char const* param) {
    for (int i = 0; param[i] != '\0'; i++) {
        if (int(param[i]) < 47 && int(param[i]) > 58)
            return false;
    }
    return true;
}

