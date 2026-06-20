#include <iostream>
#include "Layanan.h"

using namespace std;

void tampilkanMenuLayanan() {

    //Inisialisasi daftar menu makanan dan minuman
    ItemLayanan MenuMakanan[5] = {
        {"Nasi Goreng", 35000},
        {"Club Sandwich", 40000},
        {"Sop Buntut", 65000},
        {"French Fries", 25000},
        {"Fresh Juice", 20000},
    };

    int pilihan;
    int TotalBiaya = 0;

    do { 
    cout << "=======================================" << endl;
    cout << "        SISTEM LAYANAN KAMAR          " << endl;
    cout << "=======================================" << endl;
    cout << "1. Pesan Makanan / Minuman" << endl;
    cout << "2. Minta Pembersihan Kamar" << endl;
    cout << "3. Minta Handuk / Fasilitas Tambahan" << endl;
    cout << "4. Cek Total Tagihan & Selesai" << endl;
    cout << "=======================================" << endl;
    cout << "Pilih Menu (1-4): ";
    cin >> pilihan;

    switch (pilihan) {
        case 1: {
            int pilMakanan, jumlah;
            cout << "\n--- Daftar Menu Makanan & Minuman ---" << endl;

            //Perulangan untuk menampilkan menu makanan dan minuman
            for (int i = 0; i < 5; i++) {
                cout << i + 1 << ". " << MenuMakanan[i].nama << " - Rp " << MenuMakanan[i].harga << endl;
            }
            cout << "Pilih Menu (1-5): ";
            cin >> pilMakanan;

            if (pilMakanan >= 1 && pilMakanan <= 5) {
                cout << "Masukkan Jumlah Pesanan: ";
                cin >> jumlah;

                //Menghitung subtotal pesanan dan menambahkannya ke totalBiaya
                int subtotal = MenuMakanan[pilMakanan - 1].harga * jumlah;
                TotalBiaya += subtotal;
                cout << "Berhasil Memesan " << jumlah << " " << MenuMakanan[pilMakanan - 1].nama << endl;
            } else {
                cout << "Pilihan Tidak Valid!" << endl;
            }
            break;
        }
        case 2: {
            cout << "\n Permintaan pembersihan kamar telah dicatat. Petugas akan segera datang." << endl;
        } break;
        case 3: {
            cout << "\n Permintaan fasilitas tambahan telah di teruskan ke bagian housekeeping." << endl;
        } break;
        case 4: {
            cout << "\n=======================================" << endl;
            cout << "        RINGKASAN LAYANAN KAMAR        " << endl;
            cout << "=======================================" << endl;
            cout << "Total Tagihan Layanan Kamar: Rp " << TotalBiaya << endl;
            cout << "Terima kasih telah menggunakan layanan kami!. Kembali ke sistem utama hotel..." << endl;
        } break;
        default: {
            cout << "Pilihan Tidak Valid! Silakan coba lagi." << endl;
        }
    }
    } while (pilihan != 4);
    
}