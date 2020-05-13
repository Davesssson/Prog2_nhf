#include "Csaladi.h"

int Csaladi::get_korhatar() {
    return korhatar;
}
void Csaladi::set_korhatar(int ujkorhatar) {
    korhatar = ujkorhatar;
}
void Csaladi::kiir() {
    Film::kiir();
    cout << "Korhatar: " << "\t" << "[" << korhatar << "]" << endl;
    cout << endl;
}
void Csaladi::fajlbakiir(ofstream& os) {
    Film::fajlbakiir(os);
    os << korhatar;

}