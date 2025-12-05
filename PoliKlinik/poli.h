#ifndef DOKTER_H
#define DOKTER_H

#include <string>
#include "kunjungan.h"

using namespace std;

struct infotypeD {
    string namaDokter;
    string idDokter;
    string spesialisasi;
};

typedef struct elmListD *addressD;
struct elmListD {
    infotypeD info;
    addressD next;
    addressD prev;
    addressK firstChild;
};

struct ListDokter {
    addressD first;
    addressD last;
};

void createListDokter(ListDokter &L);
addressD alokasiD(infotypeD x);
void insertAfterD(ListDokter &L, addressD prec, addressD D);
addressD findDokter(ListDokter L, string id);
void deleteAfterD(ListDokter &L, addressD prec, addressD &D);
void printAllDokter(ListDokter L);

void connectDokterKunjungan(addressD D, addressK K);
void disconnectDokterKunjungan(addressD D, addressK K);
void printKunjunganDokter(addressD D);

#endif
