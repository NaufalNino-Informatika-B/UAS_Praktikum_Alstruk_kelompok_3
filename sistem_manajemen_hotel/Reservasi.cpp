#include <iostream>
#include <string>
#include "Reservasi.h"

void tampilkanMenuReservasi() {
    using namespace std;

    NodeReservasi* head = nullptr;
    
    int pilihan;
    int counterID = 1001; // ID otomatis unik, dimulai dari 1001

    do {
        cout << "\n=======================================" << endl;
        cout << "       SISTEM RESERVASI KAMAR HOTEL    " << endl;
        cout << "=======================================" << endl;
        cout << "1. Buat Reservasi Baru (Insert Last)" << endl;
        cout << "2. Batalkan/Hapus Reservasi (Delete By ID)" << endl;
        cout << "3. Tampilkan Semua Daftar Reservasi" << endl;
        cout << "4. Kembali ke Menu Utama" << endl;
        cout << "=======================================" << endl;
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {

                NodeReservasi* nodeBaru = new NodeReservasi();
                nodeBaru->idReservasi = counterID++;
                nodeBaru->next = nullptr;

                cout << "\n--- BUAT RESERVASI BARU ---" << endl;
                cout << "ID Reservasi Anda: " << nodeBaru->idReservasi << endl;
                cout << "Masukkan Nama Tamu: ";
                cin.ignore();
                getline(cin, nodeBaru->namaTamu);
                cout << "Masukkan Nomor Kamar: ";
                cin >> nodeBaru->nomorKamar;
                cout << "Masukkan Tipe Kamar (Reguler/VIP/Suite): ";
                cin >> nodeBaru->tipeKamar;

                if (head == nullptr) {
                    head = nodeBaru;
                } else {
                    NodeReservasi* temp = head;
                    while (temp->next != nullptr) {
                        temp = temp->next;
                    }
                    temp->next = nodeBaru;
                }
                cout << "\nReservasi berhasil dibuat atas nama " << nodeBaru->namaTamu << "!" << endl;
                break;
            }

            case 2: {
                if (head == nullptr) {
                    cout << "\nBelum ada data reservasi aktif saat ini." << endl;
                    break;
                }

                int idCari;
                cout << "\nMasukkan ID Reservasi yang ingin dibatalkan: ";
                cin >> idCari;

                NodeReservasi* temp = head;
                NodeReservasi* prev = nullptr;

                // Kasus A: Jika data yang mau dihapus berada di paling depan (Head)
                if (temp != nullptr && temp->idReservasi == idCari) {
                    head = temp->next; 
                    delete temp;       
                    cout << "\nReservasi ID " << idCari << " berhasil dibatalkan." << endl;
                    break;
                }

                // Kasus B: Mencari data di urutan tengah atau ujung belakang list
                while (temp != nullptr && temp->idReservasi != idCari) {
                    prev = temp;
                    temp = temp->next;
                }

                // Jika setelah dicari sampai habis tetap tidak ketemu
                if (temp == nullptr) {
                    cout << "\nID Reservasi " << idCari << " tidak ditemukan!" << endl;
                } else {
                    prev->next = temp->next;
                    delete temp; 
                    cout << "\nReservasi ID " << idCari << " berhasil dibatalkan." << endl;
                }
                break;
            }

            case 3: {
                if (head == nullptr) {
                    cout << "\nTidak ada data reservasi aktif." << endl;
                } else {
                    cout << "\n--- DAFTAR RESERVASI AKTIF ---" << endl;
                    NodeReservasi* temp = head;
                    while (temp != nullptr) {
                        cout << "ID: " << temp->idReservasi 
                             << " | Nama: " << temp->namaTamu 
                             << " | Kamar: " << temp->nomorKamar 
                             << " [" << temp->tipeKamar << "]" << endl;
                        temp = temp->next; 
                    }
                    cout << "-------------------------------" << endl;
                }
                break;
            }

            case 4:
                cout << "\nKembali ke menu utama..." << endl;
                break;

            default:
                cout << "\nPilihan tidak valid, silakan coba lagi." << endl;
        }
    } while (pilihan != 4);

    // Menghapus semua node tersisa saat keluar dari menu 
    while (head != nullptr) {
        NodeReservasi* temp = head;
        head = head->next;
        delete temp;
    }
}