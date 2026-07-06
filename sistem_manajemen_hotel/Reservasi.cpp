#include <iostream>
#include <string>
#include "Reservasi.h"

void tampilkanStatusKamar(NodeReservasi* head) {
    using namespace std;
    const int TOTAL_KAMAR = 5;
    int jumlahDitempati = 0;

    NodeReservasi* temp = head;
    while (temp != nullptr) {
        if (temp->isCheckedIn) {
            jumlahDitempati++;
        }
        temp = temp->next;
    }

    int jumlahKosong = TOTAL_KAMAR - jumlahDitempati;

    cout << "\n--- STATUS KAMAR ---" << endl;
    cout << "Total kamar: " << TOTAL_KAMAR << endl;
    cout << "Kosong: " << jumlahKosong << endl;
    cout << "Sudah ditempati: " << jumlahDitempati << endl;
    cout << "--------------------" << endl;
}

void tampilkanMenuReservasi(NodeReservasi*& head, int& counterID) {
    using namespace std;
    int pilihan;

    do {
        tampilkanStatusKamar(head);
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
                nodeBaru->isCheckedIn = false;
                nodeBaru->next = nullptr;

                cout << "\n--- INPUT DATA RESERVASI ---" << endl;
                cout << "Masukkan nama: ";
                cin.ignore();
                getline(cin, nodeBaru->namaTamu);

                int tanggal, bulan, tahun;
                cout << "Masukkan tanggal (hanya masukan angka): ";
                cin >> tanggal;
                while (tanggal < 1 || tanggal > 31) {
                    cout << "Tanggal tidak valid. Masukkan tanggal antara 1-31: ";
                    cin >> tanggal;
                }
                cout << "Masukkan bulan (masukan antara angka 1 hingga 12): ";
                cin >> bulan;
                while (bulan < 1 || bulan > 12) {
                    cout << "Bulan tidak valid. Masukkan bulan antara 1-12: ";
                    cin >> bulan;
                }
                cout << "Masukkan tahun (contoh: 2023): ";
                cin >> tahun;
                while (tahun < 1000 || tahun > 3000) {
                    cout << "Tahun tidak valid, masukan tahun antara 1000 hingga 3000: ";
                    cin >> tahun;
                }

                nodeBaru->tanggal = to_string(tanggal) + "-" + to_string(bulan) + "-" + to_string(tahun);

                int pilihanKamar;
                cout << "Pilih jenis kamar (1 = Reguler, 2 = VIP): ";
                cin >> pilihanKamar;

                while (pilihanKamar != 1 && pilihanKamar != 2) {
                    cout << "Pilihan tidak valid. Masukkan 1 untuk Reguler atau 2 untuk VIP: ";
                    cin >> pilihanKamar;
                }

                if (pilihanKamar == 1) {
                    nodeBaru->jenisKamar = "Reguler";
                } else {
                    nodeBaru->jenisKamar = "VIP";
                }
                
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