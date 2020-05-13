#include "Film.h"

string Film::get_cim() {
    return cim;
}
int Film::get_kiadaseve() {
    return kiadaseve;
}
int Film::get_jatekido() {
    return jatekido;
}
MovieType Film::get_MovieType() {
    return type;
}

void Film::set_cim(string ujcim) {
    cim = ujcim;
}
void Film::set_kiadaseve(int ujkiadaseve) {
    kiadaseve = ujkiadaseve;
}
void Film::set_jatekido(int ujjatekido) {
    jatekido = ujjatekido;
}
void Film::set_type(MovieType tipus) {
    type = tipus;
}

void Film::kiir() {
    cout << "Cim: " << "\t" << "\t" << "[" << cim << "]" << endl;
    cout << "Jatekido: " << "\t" << "[" << jatekido << "]" << endl;
    cout << "kiadaseve: " << "\t" << "[" << kiadaseve << "]" << endl;
    if (type == MovieType::csaladi)
        cout << "Tipus : " << "\t" << "[" << "Csaladi" << "]" << endl;
    else if (type == MovieType::dokumentum)
        cout << "Tipus : " << "\t" << "[" << "Dokumentum" << "]" << endl;
    else
        cout << "Tipus : " << "\t" << "[" << "Nincs" << "]" << endl;

}
void Film::fajlbakiir(ofstream& os) {
    os << cim << "\t" << kiadaseve << "\t" << jatekido << "\t";
}

