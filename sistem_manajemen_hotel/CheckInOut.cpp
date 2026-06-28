#include <iostream>
#include <string>
#include "CheckInOut.h"
#include "Reservasi.h"

using namespace std;

void tampilkanMenuCheckInOut(NodeReservasi* head) {
    int pilihan;

    do {
        cout << "\n=======================================" << endl;
        cout << "          MENU CHECK-IN / OUT          " << endl;
        cout << "=======================================" << endl;
        cout << "1. Proses Check-in & Check-out" << endl;
        cout << "2. Kembali ke Menu Utama" << endl;
        cout << "=======================================" << endl;
        cout << "Pilih menu (1-2): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                if (head == nullptr) {
                    cout << "\nBelum ada tamu di daftar reservasi!" << endl;
                    cout << "Kembali ke menu utama untuk reservasi kamar terlebih dahulu." << endl;
                    break;
                }

                string namaCari;
                cout << "\nMasukkan nama tamu untuk verifikasi: ";
                cin.ignore();
                getline(cin, namaCari);

                bool ditemukan = false;
                string jenisKamarTamu = "";
                
                NodeReservasi* temp = head;
                while (temp != nullptr) {
                    if (temp->namaTamu == namaCari) {
                        ditemukan = true;
                        jenisKamarTamu = temp->jenisKamar;
                        break;
                    }
                    temp = temp->next;
                }

                if (!ditemukan) {
                    cout << "Nama tidak ditemukan di daftar reservasi!" << endl;
                    cout << "Silakan lakukan reservasi kamar terlebih dahulu." << endl;
                    break; 
                }

                cout << "Tamu terdaftar dengan tipe kamar: " << jenisKamarTamu << endl;
                
                cout << "\n--- LAKUKAN CHECK-IN ---" << endl;
                cout << "Tamu '" << namaCari << "' berhasil melakukan Check-in dan masuk kamar." << endl;

                prosesCheckOut:
                
                cout << "\n--- LAKUKAN CHECK-OUT ---" << endl;
                cout << "Apakah tamu '" << namaCari << "' ingin Check-out sekarang?" << endl;
                cout << "Tekan (1 = Ya, konfirmasi keluar / 0 = Tidak, tunda keluar): ";
                int konfirmasi;
                cin >> konfirmasi;

                if (konfirmasi == 1) {
                    cout << "\nBERHASIL CHECK-OUT" << endl;
                    cout << "Kamar tipe " << jenisKamarTamu << " telah kosong dan dibersihkan." << endl;
                } else {
                    cout << "\nTamu belum siap Check-out atau status masih aktif di dalam kamar!" << endl;
                    cout << "Mengembalikan tamu ke status Check-in..." << endl;
                    goto prosesCheckOut; 
                }
                break;
            }
            case 2:
                cout << "\nKembali ke menu utama..." << endl;
                break;
            default:
                cout << "\nPilihan tidak valid!" << endl;
        }
    } while (pilihan != 2);
}

