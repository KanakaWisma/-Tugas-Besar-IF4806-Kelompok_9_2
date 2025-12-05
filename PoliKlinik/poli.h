#ifndef POLI_H
#define POLI_H

#include <string>
#include "dokter.h"
using namespace std;

struct infotypeP {
    string namaPoli;
    string kodePoli;
};

typedef struct elmListP *addressP;
struct elmListP {
    infotypeP info;
    addressP next;
    addressD firstChild;
};

struct ListPoli {
    addressP first;
};

void createListPoli(ListPoli &L);
addressP alokasiP(infotypeP x);
void insertLastP(ListPoli &L, addressP P);
addressP findPoli(ListPoli L, string kode);
void deletePoli(ListPoli &L, addressP &P);
void printAllPoli(ListPoli L);

void connectPoliDokter(addressP P, addressD D);
void disconnectPoliDokter(addressP P, addressD D);
void printDokterInPoli(addressP P);

#endif
