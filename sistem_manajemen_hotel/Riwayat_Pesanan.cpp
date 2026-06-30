#include <iostream>
#include <string>
#include "Riwayat_Pesanan.h"

void tambahLogRiwayat(NodeRiwayat*& top, std::string nama, std::string jenisAksi, std::string infoWaktu) {
    NodeRiwayat* nodeBaru = new NodeRiwayat();
    nodeBaru->namaTamu = nama;
    nodeBaru->aksi = jenisAksi;
    nodeBaru->waktu = infoWaktu;
    nodeBaru->next = top;
    top = nodeBaru;
}

void tampilkanMenuRiwayat(NodeRiwayat* top) {
    using namespace std;
    int pilihan;

    do {
        cout << "\n=======================================" << endl;
        cout << "       LOG RIWAYAT PEMESANAN HOTEL     " << endl;
        cout << "=======================================" << endl;
        cout << "1. Tampilkan Semua Riwayat (Sesuai Flowchart)" << endl;
        cout << "2. Kembali ke Menu Utama" << endl;
        cout << "=======================================" << endl;
        cout << "Pilih menu (1-2): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                if (top == nullptr) {
                    cout << "\nBelum ada data riwayat pemesanan saat ini." << endl;
                } else {
                    cout << "\n--- DAFTAR RIWAYAT TAMU (TERBARU -> TERLAMA) ---" << endl;
                    NodeRiwayat* temp = top;
                    int no = 1;
                    while (temp != nullptr) {
                        cout << no++ << ". [" << temp->waktu << "] " 
                             << temp->namaTamu << " Berhasil Melakukan " << temp->aksi << endl;
                        temp = temp->next;
                    }
                    cout << "------------------------------------------------" << endl;
                }
                break;
            }

            case 2:
                cout << "\nKembali ke menu utama..." << endl;
                break;

            default:
                cout << "\nPilihan tidak valid, silakan coba lagi." << endl;
        }
    } while (pilihan != 2);
}