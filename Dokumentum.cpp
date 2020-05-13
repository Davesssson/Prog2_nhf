#include "Dokumentum.h"

string Dokumentum::get_leiras() {
    return leiras;
}
void Dokumentum::set_leiras(string ujleiras) {
    leiras = ujleiras;
}
void Dokumentum::kiir() {
    Film::kiir();
    cout << "Leiras: " << "\t" << "[" << leiras << "]" << endl;
    cout << endl;
}
void Dokumentum::fajlbakiir(ofstream& os) {
    Film::fajlbakiir(os);
    os << leiras;
}
