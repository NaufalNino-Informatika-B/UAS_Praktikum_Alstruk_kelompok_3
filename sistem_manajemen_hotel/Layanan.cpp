#include <iostream>
#include <string>
#include "Layanan.h"
#include "Reservasi.h"

using namespace std;

void tampilkanMenuLayanan(NodeReservasi* head) {
    int pilihan;

    do {
        cout << "\n=======================================" << endl;
        cout << "          MENU LAYANAN KAMAR           " << endl;
        cout << "=======================================" << endl;
        cout << "1. Pesan Layanan Kamar" << endl;
        cout << "2. Kembali ke Menu Utama" << endl;
        cout << "=======================================" << endl;
        cout << "Pilih menu (1-2): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                if (head == nullptr) {
                    cout << "\nMaaf, belum ada tamu aktif di reservasi. Layanan tidak tersedia!" << endl;
                    break;
                }

                string namaCari;
                cout << "\nMasukkan nama tamu pemesan: ";
                cin.ignore();
                getline(cin, namaCari);

                bool ditemukan = false;
                NodeReservasi* temp = head;
                while (temp != nullptr) {
                    if (temp->namaTamu == namaCari) {
                        ditemukan = true;
                        break;
                    }
                    temp = temp->next;
                }

                if (!ditemukan) {
                    cout << "Nama tidak terdaftar di reservasi hotel! Pemesanan ditolak." << endl;
                    break;
                }

                ItemLayanan daftarMenu[2] = {
                    {"Room Service Makanan", 50000},
                    {"Pembersihan Kamar", 25000}
                };

                cout << "\n--- PILIHAN LAYANAN UNTUK " << namaCari << " ---" << endl;
                for (int i = 0; i < 2; i++) {
                    cout << i + 1 << ". " << daftarMenu[i].nama << " (Rp" << daftarMenu[i].harga << ")" << endl;
                }
                cout << "Pilih layanan (1-2): ";
                int jenisLayanan;
                cin >> jenisLayanan;

                if (jenisLayanan >= 1 && jenisLayanan <= 2) {
                    cout << "\n✓ Sukses memesan " << daftarMenu[jenisLayanan - 1].nama << "!" << endl;
                    cout << "Biaya sebesar Rp" << daftarMenu[jenisLayanan - 1].harga << " dimasukkan ke tagihan." << endl;
                } else {
                    cout << "Pilihan layanan tidak valid." << endl;
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