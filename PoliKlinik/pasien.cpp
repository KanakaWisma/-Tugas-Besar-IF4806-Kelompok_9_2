#include "pasien.h"

addressP alokasiPasien(infotypeP data) {
    addressP P = new elmPasien;
    P->info = data;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void insertLastPasien(addressP &first, addressP P) {
    if (first == nullptr) {
        first = P;
    } else {
        addressP last = first;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = P;
        P->prev = last;
    }
}

void deletePasien(addressP &first, addressP &P) {
    if (P == nullptr) return;

    if (P == first) {
        first = first->next;
        if (first != nullptr) {
            first->prev = nullptr;
        }
    } else {
        P->prev->next = P->next;
        if (P->next != nullptr) {
            P->next->prev = P->prev;
        }
    }
    P->next = nullptr;
    P->prev = nullptr;
}

void printPasien(addressP first) {
    addressP P = first;
    if (P == nullptr) {
        cout << "   (Belum ada pasien)\n";
        return;
    }
    int i = 1;
    while (P != nullptr) {
        cout << "   " << i << ". " << P->info.namaPasien
             << " (ID: " << P->info.idPasien << ") - "
             << P->info.tglBerobat << " [" << P->info.keluhan << "]\n";
        P = P->next;
        i++;
    }
}
