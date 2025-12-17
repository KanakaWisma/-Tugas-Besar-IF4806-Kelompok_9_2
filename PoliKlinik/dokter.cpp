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
    P->prev = nullptr;
    P->firstChild = nullptr;
    return P;
}

void insertDokter(ListDokter &L, addressD D) {
    if (L.first == nullptr) {
        L.first = D;
        L.last = D;
    } else {
        L.last->next = D;
        D->prev = L.last;
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
    if (D == L.first) {
        L.first = L.first->next;
        if (L.first != nullptr) {
            L.first->prev = nullptr;
        } else {
            L.last = nullptr;
        }
    } else if (D == L.last) {
        L.last = L.last->prev;
        if (L.last != nullptr) {
            L.last->next = nullptr;
        }
    } else {
        D->prev->next = D->next;
        D->next->prev = D->prev;
    }

    addressP child = D->firstChild;
    while (child != nullptr) {
        addressP temp = child;
        child = child->next;
        delete temp;
    }

    D->next = nullptr;
    D->prev = nullptr;
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

void tambahPasienKeDokter(ListDokter &L, string idDokter, infotypeP dataPasien) {
    addressD D = findDokter(L, idDokter);
    if (D != nullptr) {
        addressP P = alokasiPasien(dataPasien);
        insertLastPasien(D->firstChild, P);
        cout << "Pasien " << dataPasien.namaPasien << " berhasil didaftarkan ke Dr. " << D->info.namaDokter << endl;
    } else {
        cout << "Error: ID Dokter tidak ditemukan.\n";
    }
}

void hapusPasienDariDokter(ListDokter &L, string idDokter, string idPasien) {
    addressD D = findDokter(L, idDokter);
    if (D != nullptr) {
        addressP P = D->firstChild;
        while (P != nullptr) {
            if (P->info.idPasien == idPasien) {
                deletePasien(D->firstChild, P);
                delete P;
                cout << "Pasien berhasil dihapus.\n";
                return;
            }
            P = P->next;
        }
        cout << "Error: Pasien tidak ditemukan pada dokter tersebut.\n";
    } else {
        cout << "Error: Dokter tidak ditemukan.\n";
    }
}

int hitungJumlahPasien(addressD D) {
    int count = 0;
    if (D != nullptr) {
        addressP P = D->firstChild;
        while (P != nullptr) {
            count++;
            P = P->next;
        }
    }
    return count;
}

void cariRiwayatPasien(ListDokter L, string idPasien) {
    cout << "\n--- Riwayat Berobat Pasien ID: " << idPasien << " ---\n";
    addressD D = L.first;
    bool foundAny = false;

    while (D != nullptr) {
        addressP P = D->firstChild;
        while (P != nullptr) {
            if (P->info.idPasien == idPasien) {
                cout << "- Berobat ke Dr. " << D->info.namaDokter
                     << " (" << D->info.namaPoli << ") pada tgl "
                     << P->info.tglBerobat << ". Keluhan: " << P->info.keluhan << endl;
                foundAny = true;
            }
            P = P->next;
        }
        D = D->next;
    }

    if (!foundAny) {
        cout << "Pasien ini belum pernah berobat ke dokter manapun.\n";
    }
}
