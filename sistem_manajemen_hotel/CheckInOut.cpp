#include <iostream>
#include <string>
#include "CheckInOut.h"
#include "Reservasi.h"

using namespace std;

void setCheckIn(NodeReservasi* head, int idCari) {
    NodeReservasi* temp = head;
    while (temp != nullptr) {
        if (temp->idReservasi == idCari) {
            if (temp->isCheckedIn) {
                cout << "Reservasi sudah Check-in sebelumnya.\n";
            } else {
                temp->isCheckedIn = true;
                cout << "BERHASIL CHECK-IN. Tamu telah masuk ke dalam kamar.\n";
            }
            return;
        }
        temp = temp->next;
    }
    cout << "ID Reservasi tidak ditemukan! Check-in ditolak.\n";
}

NodeReservasi* prosesCheckOut(NodeReservasi* head, int idCari) {
    NodeReservasi* cur = head;
    NodeReservasi* prev = nullptr;
    while (cur != nullptr) {
        if (cur->idReservasi == idCari) {
            if (!cur->isCheckedIn) {
                cout << "Tamu belum Check-in, tidak bisa Check-out.\n";
                return head;
            }
            
            if (prev) prev->next = cur->next;
            else head = cur->next;
            
            cout << "BERHASIL CHECK-OUT. Kamar tipe " << cur->jenisKamar << " telah kosong kembali.\n";
            delete cur;
            return head;
        }
        prev = cur;
        cur = cur->next;
    }
    cout << "ID Reservasi tidak ditemukan di daftar tamu aktif hotel!\n";
    return head;
}

void tampilkanMenuCheckInOut(NodeReservasi*& head) {
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
        
        if (!(cin >> pilihan)) {
            cout << "Peringatan: Masukkan nomor menu dalam bentuk angka!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (pilihan) {
            case 1: {
                if (head == nullptr) {
                    cout << "\nBelum ada tamu di daftar reservasi!" << endl;
                    cout << "Kembali ke menu utama untuk reservasi kamar terlebih dahulu." << endl;
                    break;
                }

                int idCari;
                cout << "\nMasukkan ID Reservasi tamu: ";
                
                if (!(cin >> idCari)) {
                    cout << "Peringatan: ID Reservasi harus berupa angka!" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    break;
                }
                
                setCheckIn(head, idCari);
                break;
            }

            case 2: {
                if (head == nullptr) {
                    cout << "\nBelum ada tamu aktif di dalam hotel!" << endl;
                    break;
                }

                int idCari;
                cout << "\nMasukkan ID Reservasi tamu: ";
                
                if (!(cin >> idCari)) {
                    cout << "Peringatan: ID Reservasi harus berupa angka!" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    break;
                }

                NodeReservasi* temp = head;
                bool ditemukan = false;
                while (temp != nullptr) {
                    if (temp->idReservasi == idCari) {
                        ditemukan = true;
                        break;
                    }
                    temp = temp->next;
                }

                if (!ditemukan) {
                    cout << "ID Reservasi tidak ditemukan di daftar tamu aktif hotel!\n";
                    break;
                }

                char konfirmasi;
                cout << "Apakah Anda yakin ingin Check-out sekarang? (Y/N): ";
                cin >> konfirmasi;

                if (konfirmasi == 'y' || konfirmasi == 'Y') {
                    head = prosesCheckOut(head, idCari);
                } else if (konfirmasi == 'n' || konfirmasi == 'N') {
                    cout << "Check-out dibatalkan. Status tamu tetap aktif di dalam kamar." << endl;
                } else {
                    cout << "Peringatan: Input tidak valid! Masukkan hanya huruf Y atau N." << endl;
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