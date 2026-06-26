#include <iostream>
#include <string>
#include "CheckInOut.h"
#include "Reservasi.h"

void tampilkanMenuCheckInOut(NodeReservasi* head) {
    using namespace std;
    int pilihan;

    do {
        cout << "\n=======================================" << endl;
        cout << "          MENU CHECK-IN / OUT          " << endl;
        cout << "=======================================" << endl;
        cout << "1. Jalankan Alur Check-in/out" << endl;
        cout << "2. Kembali ke Menu Utama" << endl;
        cout << "=======================================" << endl;
        cout << "Pilih menu (1-2): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                cout << "\n[PROSES] Menjalankan Fitur Check-in/out..." << endl;

                if (head == nullptr) {
                    cout << "Maff, belum ada tamu terdaftar di data Reservasi!" << endl;
                    cout << "Silakan lakukan registrasi di menu Reservasi terlebih dahulu." << endl;
                    break;
                }

                string namaCari;
                cout << "Masukkan nama tamu untuk verifikasi check-in: ";
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
                    cout << "Nama tidak ada di daftar reservasi. Silakan reservasi dulu!" << endl;
                    break;
                }

                cout << "Tamu '" << namaCari << "' ditemukan di daftar reservasi." << endl;
                cout << "Proses CHECK-IN berhasil dilakukan." << endl;

                cout << "\nMelanjutkan ke alur CHECK-OUT..." << endl;
                cout << "Apakah tamu '" << namaCari << "' ingin check-out sekarang? (1 = Ya / 0 = Tidak): ";
                int statusAktif;
                cin >> statusAktif;

                if (statusAktif == 1) {
                    cout << "Berhasil Check-out! Kamar telah kosong kembali." << endl;
                } else {
                    cout << "Tamu tetap aktif berada di dalam kamar." << endl;
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