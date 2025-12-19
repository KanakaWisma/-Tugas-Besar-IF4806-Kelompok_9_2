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
