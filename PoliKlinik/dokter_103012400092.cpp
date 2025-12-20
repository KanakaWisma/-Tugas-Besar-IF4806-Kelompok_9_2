#include "dokter.h"
#include <iostream>
using namespace std;

void createListDokter(ListDokter &L) {
    L.first = nullptr;
    L.last = nullptr;
}

addressD alokasiDokter(infotypeD data) {
    addressD P = new elmDokter;
    P->info = data;
    P->next = nullptr;
    P->firstChild = nullptr;
    return P;
}

void insertDokter(ListDokter &L, addressD D) {
    if (L.first == nullptr) {
        L.first = D;
        L.last = D;
    } else {
        L.last->next = D;
        L.last = D;
    }
}

addressD findDokter(ListDokter L, string id) {
    addressD P = L.first;
    while (P != nullptr) {
        if (P->info.idDokter == id) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void deleteDokter(ListDokter &L, addressD &D) {
    addressP child = D->firstChild;
    while (child != nullptr) {
        addressP temp = child;
        child = child->next;
        delete temp;
    }
    D->firstChild = nullptr;

    if (D == L.first) {
        L.first = L.first->next;
        if (L.first == nullptr) {
            L.last = nullptr;
        }
    } else {
        addressD prec = L.first;
        while (prec != nullptr && prec->next != D) {
            prec = prec->next;
        }

        if (prec != nullptr) {
            prec->next = D->next;
            if (D == L.last) {
                L.last = prec;
            }
        }
    }
    D->next = nullptr;
}

void printDokterDanPasien(ListDokter L) {
    addressD P = L.first;
    if (P == nullptr) {
        cout << "Belum ada data dokter.\n";
        return;
    }
    while (P != nullptr) {
        cout << "=============================================\n";
        cout << "[DOKTER] " << P->info.namaDokter
             << " (ID: " << P->info.idDokter << ")\n";
        cout << "         Spesialis: " << P->info.spesialisasi
             << " | Poli: " << P->info.namaPoli << endl;
        cout << "---------------------------------------------\n";
        printPasien(P->firstChild);
        cout << endl;
        P = P->next;
    }
}


