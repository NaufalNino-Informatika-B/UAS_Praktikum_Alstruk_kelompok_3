#include <iostream>
#include <queue>
#include "Layanan.h"

using namespace std;

void tampilkanMenuLayanan() {

    //Inisialisasi daftar menu makanan dan minuman
    ItemLayanan MenuMakanan[5] = {
        {"Nasi Goreng", 35000},
        {"Club Sandwich", 40000},
        {"Sop Buntut", 65000},
        {"Chicken Caesar Salad", 25000},
        {"French Fries", 20000},
    };

    ItemLayanan menuMinuman[5] = {
        {"Fresh Juice (Jeruk/Alpukat)", 20000},
        {"Iced Cafe Latte", 25000},
        {"Hot Lemon Tea", 15000},
        {"Milkshake Chocolate", 22000},
        {"Air Mineral Premium", 10000}
    };

    // Penerapan Struktur data QUEUE untuk menampung daftar permintaan layanan kamar
    queue<string> antreanLayanan;

    int nomorKamar; 
    int pilihan;
    int TotalBiaya = 0;

    cout << "\n=======================================" << endl;
    cout << "      WELCOME TO ROOM SERVICE SYSTEM   " << endl;
    cout << "=======================================" << endl;
    cout << "Masukkan Nomor Kamar Anda: ";
    cin >> nomorKamar;

    do { 
    cout << "=======================================" << endl;
    cout << "        SISTEM LAYANAN KAMAR          " << endl;
    cout << "        KAMAR NO: " << nomorKamar << endl;
    cout << "=======================================" << endl;
    cout << "1. Pesan Makanan & Minuman" << endl;
    cout << "2. Minta Pembersihan Kamar" << endl;
    cout << "3. Minta Fasilitas Tambahan" << endl;
    cout << "4. Cek Antrean & Proses Layanan" << endl;
    cout << "5. Cek Total Tagihan & Selesai" << endl;
    cout << "=======================================" << endl;
    cout << "Pilih Menu (1-5): ";
    cin >> pilihan;

    switch (pilihan) {
        case 1: {
            int katPilihan;
            cout << "\n--- PILIH KATEGORI LAYANAN ---" << endl;
            cout << "1. Makanan" << endl;
            cout << "2. Minuman" << endl;
            cout << "Pilih Kategori (1-2): ";
            cin >> katPilihan;

            if (katPilihan == 1) {
                int pilMakanan, jumlah;
                cout << "\n--- DAFTAR MENU MAKANAN ---" << endl;
                for (int i = 0 ; i <5 ; i++) {
                    cout << i+1 << ". " << MenuMakanan[i].nama << " - Rp " << MenuMakanan[i].harga << endl;
                }
                cout << "Pilih Menu Makanan (1-5): ";
                cin >> pilMakanan;

                if (pilMakanan >= 1 && pilMakanan <= 5) {
                    cout << "Masukkan Jumlah Pesanan: ";
                    cin >> jumlah;
                    int subTotal = MenuMakanan[pilMakanan - 1].harga * jumlah;
                    TotalBiaya += subTotal;

                    // PUSH : Untuk memasukan pesanan makanan ke antrean queue
                    antreanLayanan.push("Pesan " + to_string(jumlah) + " " + MenuMakanan[pilMakanan -1].nama);
                    cout << "Pesanan dimasukan ke antrean layanan kamar. " << endl;
                } else {
                    cout << "pilihan tidak valid!" << endl;
                }
            }
            else if (katPilihan == 2) {
                int pilMinuman, jumlah;
                cout << "\n--- DAFTAR MENU MINUMAN ---" << endl;
                for (int i = 0 ; i <5 ; i++) {
                    cout << i+1 << ". " << menuMinuman[i].nama << " - Rp " << menuMinuman[i].harga << endl;
                }
                cout << "Pilih Menu Minuman (1-5): ";
                cin >> pilMinuman;

                if (pilMinuman >= 1&& pilMinuman <= 5) {
                    cout << "Masukkan Jumlah Pesanan: ";
                    cin >> jumlah;
                    int subTotal = menuMinuman[pilMinuman - 1].harga * jumlah;
                    TotalBiaya += subTotal;

                    // PUSH : Untuk memasukan pesanan minuman ke antrean queue
                    antreanLayanan.push("Pesan " + to_string(jumlah) + " " + menuMinuman[pilMinuman -1].nama);
                    cout << "Pesanan dimasukan ke antrean layanan kamar. " << endl; 
                } else {
                    cout << "pilihan tidak valid!" << endl;
                }
            }
            else {
                cout << "Pilihan kategori tidak valid!" << endl;
            }
            break;
        }
        case 2:
            // PUSH : Untuk memasukan permintaan pembersihan kamar ke antrean queue
            antreanLayanan.push("Pembersihan Kamar");
            cout << "\n Permintaan pembersihan kamar dimasukan ke antrean." << endl;
            break;
        case 3:
            // PUSH : Untuk memasukan permintaan fasilitas tambahan ke antrean queue
            antreanLayanan.push("Permintaan Fasilitas Tambahan (Handuk, bantal, dll)");
            cout << "\n Permintaan fasilitas tambahan dimasukan ke antrean." << endl;
            break;
        case 4:
            // LOGIKA QUEUE: Memproses antrean satu per satu dari yang pertama masuk (FIFO)
                cout << "\n--- PROSES ANTREAN LAYANAN KAMAR ---" << endl;
                if (antreanLayanan.empty()) {
                    cout << "Tidak ada antrean layanan aktif untuk kamar ini." << endl;
                } else {
                    cout << "Jumlah antrean saat ini: " << antreanLayanan.size() << endl;
                    while (!antreanLayanan.empty()) {
                        // FRONT: Melihat antrean terdepan
                        cout << "[DIPROSES] " << antreanLayanan.front() << " sedang diantarkan..." << endl;
                        // POP: Menghapus antrean yang sudah selesai diproses
                        antreanLayanan.pop();
                    }
                    cout << "Semua antrean layanan untuk kamartelah selesai diproses." << endl;
                }
                break;
            case 5: {
                int pajakService = TotalBiaya * 0.10;
                int totalAkhir = TotalBiaya + pajakService;

                cout << "\n=======================================" << endl;
                cout << "        RINGKASAN LAYANAN KAMAR        " << endl;
                cout << "        KAMAR NO: " << nomorKamar << endl;
                cout << "=======================================" << endl;
                cout << "Subtotal Pesanan : Rp" << TotalBiaya << endl;
                cout << "Pajak & Service (10%) : Rp" << pajakService << endl;
                cout << "---------------------------------------" << endl;
                cout << "Total Tagihan Kamar   : Rp" << totalAkhir << endl;
                cout << "=======================================" << endl;
                cout << "Terma kasih. Kembali ke sistem utama hotel..." << endl;
                break;
            }
            default:
                cout << "⚠ Pilihan tidak valid, silakan coba lagi." << endl;
        }
    } while (pilihan != 5);
}