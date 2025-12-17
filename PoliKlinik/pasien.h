#ifndef PASIEN_H
#define PASIEN_H

#include <string>
#include <iostream>
using namespace std;

struct infotypeP {
    string idPasien;
    string namaPasien;
    string tglBerobat;
    string keluhan;
};

typedef struct elmPasien *addressP;
struct elmPasien {
    infotypeP info;
    addressP next;
    addressP prev;
};

addressP alokasiPasien(infotypeP data);
void insertLastPasien(addressP &first, addressP P);
void deletePasien(addressP &first, addressP &P);
void printPasien(addressP first);

#endif
