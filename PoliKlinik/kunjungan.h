#ifndef KUNJUNGAN_H
#define KUNJUNGAN_H

#include <string>

using namespace std;

struct infotypeK {
    string namaPasien;
    string tglKunjungan;
    string idKunjungan;
};

typedef struct elmListK *addressK;
struct elmListK {
    infotypeK info;
    addressK next;
    addressK prev;
};

struct ListKunjungan {
    addressK first;
    addressK last;
};

void createListKunjungan(ListKunjungan &L);
addressK alokasiK(infotypeK x);
void insertLastK(ListKunjungan &L, addressK K);
addressK findKunjungan(ListKunjungan L, string id);
void deleteLastK(ListKunjungan &L, addressK &K);
void printAllKunjungan(ListKunjungan L);

#endif
