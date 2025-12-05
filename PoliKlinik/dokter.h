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
void insertLastD(ListDokter &L, addressD D);
addressD findDokter(ListDokter L, string id);
void deleteDokter(ListDokter &L, addressD &D);
void printAllDokter(ListDokter L);

void connectDokterKunjungan(addressD D, addressK K);
void disconnectDokterKunjungan(addressD D, addressK K);
void printKunjunganDokter(addressD D);

#endif
