#include <iostream>
#include <string>
#include "Reservasi.h"

void tampilkanMenuReservasi(NodeReservasi*& head, int& counterID) {
    using namespace std;
    int pilihan;

    do {
        cout << "\n=======================================" << endl;
        cout << "       SISTEM RESERVASI KAMAR HOTEL    " << endl;
        cout << "=======================================" << endl;
        cout << "1. Lakukan Reservasi" << endl;
        cout << "2. Tampilkan Semua Daftar Reservasi" << endl;
        cout << "3. Kembali ke Menu Utama" << endl;
        cout << "=======================================" << endl;
        cout << "Pilih menu (1-3): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                int jumlahReservasi = 0;
                NodeReservasi* hitung = head;
                while (hitung != nullptr) {
                    jumlahReservasi++;
                    hitung = hitung->next;
                }

                if (jumlahReservasi >= 5) {
                    cout << "\nMaaf, tidak ada kamar tersedia! Reservasi gagal." << endl;
                    break;
                }

                NodeReservasi* nodeBaru = new NodeReservasi();
                nodeBaru->idReservasi = counterID++;
                nodeBaru->next = nullptr;

                cout << "\n--- INPUT DATA RESERVASI ---" << endl;
                cout << "Masukkan nama: ";
                cin.ignore();
                getline(cin, nodeBaru->namaTamu);
                cout << "Masukkan tanggal (DD-MM-YYYY): ";
                getline(cin, nodeBaru->tanggal);
                cout << "Masukkan jenis kamar: ";
                getline(cin, nodeBaru->jenisKamar);
                
                if (head == nullptr) {
                    head = nodeBaru;
                } else {
                    NodeReservasi* temp = head;
                    while (temp->next != nullptr) {
                        temp = temp->next;
                    }
                    temp->next = nodeBaru;
                }
                cout << "BERHASIL RESERVASI dengan ID: " << nodeBaru->idReservasi << endl;
                break;
            }

            case 2: {
                if (head == nullptr) {
                    cout << "\nTidak ada data reservasi aktif." << endl;
                } else {
                    cout << "\n--- DAFTAR RESERVASI AKTIF ---" << endl;
                    NodeReservasi* temp = head;
                    while (temp != nullptr) {
                        cout << "ID: " << temp->idReservasi 
                             << " | Nama: " << temp->namaTamu 
                             << " | Tgl: " << temp->tanggal 
                             << " | Jenis: " << temp->jenisKamar << endl;
                        temp = temp->next;
                    }
                    cout << "-------------------------------" << endl;
                }
                break;
            }

            case 3:
                cout << "\nKembali ke menu utama..." << endl;
                break;

            default:
                cout << "\nPilihan tidak valid, silakan coba lagi." << endl;
        }
    } while (pilihan != 3);
}