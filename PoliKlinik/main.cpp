#include <iostream>
#include <string>
#include "dokter.h"

using namespace std;

ListDokter LD;

void menuAdmin() {
    string pilihan;
    int pilih;
    do {
        cout << "\n=== MENU ADMINISTRASI (KELOLA DATA) ===\n";
        cout << "1. Tambah Data Dokter\n";
        cout << "2. Hapus Data Dokter\n";
        cout << "3. Tambah Data Pasien (Registrasi ke Dokter)\n";
        cout << "4. Hapus Data Pasien dari Dokter\n";
        cout << "0. Kembali ke Menu Utama\n";
        cout << "Pilih: ";

        cin >> pilihan;

        if (pilihan == "1") pilih = 1;
        else if (pilihan == "2") pilih = 2;
        else if (pilihan == "3") pilih = 3;
        else if (pilihan == "4") pilih = 4;
        else if (pilihan == "0") pilih = 0;
        else pilih = -1;

        if (pilih == 1) {
            infotypeD data;

            cout << "ID Dokter    : "; cin >> data.idDokter;
            cout << "Nama Dokter  : "; cin >> data.namaDokter;
            cout << "Spesialisasi : "; cin >> data.spesialisasi;
            cout << "Nama Poli    : "; cin >> data.namaPoli;

            if (findDokter(LD, data.idDokter) == nullptr) {
                insertDokter(LD, alokasiDokter(data));
                cout << "Dokter " << data.namaDokter << " berhasil ditambahkan.\n";
            } else {
                cout << "Gagal: ID Dokter sudah ada!\n";
            }
        } else if (pilih == 2) {
            string id;
            cout << "Masukkan ID Dokter yg dihapus: "; cin >> id;
            addressD D = findDokter(LD, id);
            if (D != nullptr) {
                deleteDokter(LD, D);
                delete D;
                cout << "Dokter dan semua riwayat pasiennya berhasil dihapus.\n";
            } else {
                cout << "Gagal: Dokter tidak ditemukan.\n";
            }
        } else if (pilih == 3) {
            string idDok;
            infotypeP data;

            cout << "Masukkan ID Dokter tujuan: "; cin >> idDok;

            if (findDokter(LD, idDok) != nullptr) {

                cout << "ID Pasien    : "; cin >> data.idPasien;
                cout << "Nama Pasien  : "; cin >> data.namaPasien;
                cout << "Tgl Berobat  : "; cin >> data.tglBerobat;
                cout << "Keluhan      : "; cin >> data.keluhan;
                tambahPasienKeDokter(LD, idDok, data);
            } else {
                cout << "Gagal: Dokter tidak ditemukan!\n";
            }
        } else if (pilih == 4) {
            string idDok, idPas;
            cout << "ID Dokter : "; cin >> idDok;
            cout << "ID Pasien : "; cin >> idPas;
            hapusPasienDariDokter(LD, idDok, idPas);
        } else if (pilih != 0 && pilih != -1) {
             cout << "Pilihan tidak valid.\n";
        }
    } while (pilih != 0);
}

void menuStudiKasus() {
    string pilihan;
    int pilih;
    do {
        cout << "\n=== MENU STUDI KASUS (TAMPIL & KOMPUTASI) ===\n";
        cout << "1. Tampilkan Semua Dokter dan Daftar Pasiennya\n";
        cout << "2. Hitung Jumlah Pasien per Dokter\n";
        cout << "3. Cari Riwayat Pasien (Multi-Dokter)\n";
        cout << "4. Tampilkan Semua Pasien (Unik)\n"; // Tambahan
        cout << "5. Cari Dokter Terpopuler\n";         // Tambahan
        cout << "0. Kembali ke Menu Utama\n";
        cout << "Pilih: ";

        cin >> pilihan;

        if (pilihan == "1") pilih = 1;
        else if (pilihan == "2") pilih = 2;
        else if (pilihan == "3") pilih = 3;
        else if (pilihan == "4") pilih = 4; // Tambahan
        else if (pilihan == "5") pilih = 5; // Tambahan
        else if (pilihan == "0") pilih = 0;
        else pilih = -1;

        if (pilih == 1) {
            cout << "\n--- Daftar Semua Dokter dan Pasien ---\n";
            printDokterDanPasien(LD);
        } else if (pilih == 2) {
            cout << "\n--- Hasil Komputasi: Jumlah Pasien per Dokter ---\n";
            addressD P = LD.first;
            if (P == nullptr) {
                cout << "Belum ada data dokter untuk dihitung.\n";
                continue;
            }
            while (P != nullptr) {
                int total = hitungJumlahPasien(P);
                cout << "Dr. " << P->info.namaDokter << " (" << P->info.namaPoli
                     << ") menangani total " << total << " pasien.\n";
                P = P->next;
            }
        } else if (pilih == 3) {
            string idPas;
            cout << "Masukkan ID Pasien yang dicari: "; cin >> idPas;
            cariRiwayatPasien(LD, idPas);
        } else if (pilih == 4) { // Fitur baru
            printSemuaPasienUnik(LD);
        } else if (pilih == 5) { // Fitur baru
            cout << "\n--- Hasil Komputasi: Dokter Terpopuler ---\n";
            dokterTerpopuler(LD);
        } else if (pilih != 0 && pilih != -1) {
             cout << "Pilihan tidak valid.\n";
        }
    } while (pilih != 0);
}


int main() {
    createListDokter(LD);

    string menu_str;
    int menu;
    do {
        cout << "\n==============================\n";
        cout << "    APLIKASI DOKTER - PASIEN  \n";
        cout << "==============================\n";
        cout << "1. Menu Administrasi (Kelola Data)\n";
        cout << "2. Menu Studi Kasus (Tampil & Komputasi)\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";

        cin >> menu_str;

        if (menu_str == "1") menu = 1;
        else if (menu_str == "2") menu = 2;
        else if (menu_str == "0") menu = 0;
        else menu = -1;

        switch(menu) {
            case 1: menuAdmin(); break;
            case 2: menuStudiKasus(); break;
            case 0: cout << "Terima kasih telah menggunakan aplikasi ini!\n"; break;
            default:
                if (menu != -1) {
                    cout << "Pilihan tidak valid.\n";
                }
        }
    } while (menu != 0);

    return 0;
}


