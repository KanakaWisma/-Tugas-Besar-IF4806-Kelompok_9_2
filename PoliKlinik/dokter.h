#ifndef DOKTER_H
#define DOKTER_H

#include "pasien.h"
#include <string>
using namespace std;

struct infotypeD {
    string idDokter;
    string namaDokter;
    string spesialisasi;
    string namaPoli;
};

typedef struct elmDokter *addressD;
struct elmDokter {
    infotypeD info;
    addressD next;
    addressP firstChild;
};

struct ListDokter {
    addressD first;
    addressD last;
};

void createListDokter(ListDokter &L);
addressD alokasiDokter(infotypeD data);
void insertDokter(ListDokter &L, addressD D);
addressD findDokter(ListDokter L, string id);
void deleteDokter(ListDokter &L, addressD &D);
void printDokterDanPasien(ListDokter L);

void tambahPasienKeDokter(ListDokter &L, string idDokter, infotypeP dataPasien);
void hapusPasienDariDokter(ListDokter &L, string idDokter, string idPasien);
int hitungJumlahPasien(addressD D);
void cariRiwayatPasien(ListDokter L, string idPasien);
void dokterTerpopuler(ListDokter L);
void printSemuaPasienUnik(ListDokter L);

#endif


