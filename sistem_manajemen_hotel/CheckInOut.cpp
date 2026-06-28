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
        cout << "1. Check-In" << endl;
        cout << "2. Check-Out" << endl;
        cout << "3. Kembali ke Menu Utama" << endl;
        cout << "=======================================" << endl;
        cout << "Pilih menu (1-3): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                if (head == nullptr) {
                    cout << "\nBelum ada tamu di daftar reservasi!" << endl;
                    cout << "Kembali ke menu utama untuk reservasi kamar terlebih dahulu." << endl;
                    break;
                }

                int idCari;
                cout << "\nMasukkan ID Reservasi tamu: ";
                cin >> idCari;

                bool ditemukan = false;
                string namaTamu = "";
                string jenisKamarTamu = "";
                
                NodeReservasi* temp = head;
                while (temp != nullptr) {
                    if (temp->idReservasi == idCari) {
                        ditemukan = true;
                        namaTamu = temp->namaTamu;
                        jenisKamarTamu = temp->jenisKamar;
                        break;
                    }
                    temp = temp->next;
                }

                if (!ditemukan) {
                    cout << "ID Reservasi tidak ditemukan! Check-in ditolak." << endl;
                    break; 
                }

                cout << "Tamu ditemukan atas nama: " << namaTamu << " (" << jenisKamarTamu << ")" << endl;
                cout << "BERHASIL CHECK-IN. Tamu telah masuk ke dalam kamar." << endl;
                break;
            }

            case 2: {
                if (head == nullptr) {
                    cout << "\nBelum ada tamu aktif di dalam hotel!" << endl;
                    break;
                }

                int idCari;
                cout << "\nMasukkan ID Reservasi tamu: ";
                cin >> idCari;

                bool ditemukan = false;
                string namaTamu = "";
                string jenisKamarTamu = "";
                
                NodeReservasi* temp = head;
                while (temp != nullptr) {
                    if (temp->idReservasi == idCari) {
                        ditemukan = true;
                        namaTamu = temp->namaTamu;
                        jenisKamarTamu = temp->jenisKamar;
                        break;
                    }
                    temp = temp->next;
                }

                if (!ditemukan) {
                    cout << "ID Reservasi tidak ditemukan di daftar tamu aktif hotel!" << endl;
                    break; 
                }

                cout << "Tamu ditemukan atas nama: " << namaTamu << " (" << jenisKamarTamu << ")" << endl;
                cout << "Apakah Anda yakin ingin Check-out sekarang? (1 = Ya / 0 = Tidak): ";
                int konfirmasi;
                cin >> konfirmasi;

                if (konfirmasi == 1) {
                    cout << "BERHASIL CHECK-OUT. Kamar tipe " << jenisKamarTamu << " telah kosong kembali." << endl;
                } else {
                    cout << "Check-out dibatalkan. Status tamu tetap aktif di dalam kamar." << endl;
                }
                break;
            }

            case 3:
                cout << "\nKembali ke menu utama..." << endl;
                break;

            default:
                cout << "\nPilihan tidak valid!" << endl;
        }
    } while (pilihan != 3);
}