#include <iostream>
#include <queue>
#include <string>
#include "Layanan.h"

void tampilkanMenuLayanan() {
    
    using namespace std; 

    ItemLayanan menuMakanan[5] = {
        {"Nasi Goreng Hotel", 45000},
        {"Club Sandwich", 40000},
        {"Sup Buntut Premium", 65000},
        {"Chicken Caesar Salad", 35000},
        {"French Fries", 25000}
    };

    ItemLayanan menuMinuman[5] = {
        {"Fresh Juice (Jeruk/Alpukat)", 20000},
        {"Iced Cafe Latte", 25000},
        {"Hot Lemon Tea", 15000},
        {"Milkshake Chocolate", 22000},
        {"Air Mineral Premium", 10000}
    };

    priority_queue<pair<int, string>> antreanLayanan;

    int nomorKamar;
    int tipeKamar; 
    int pilihan;
    int totalBiaya = 0; 

    cout << "\n=======================================" << endl;
    cout << "      WELCOME TO ROOM SERVICE SYSTEM   " << endl;
    cout << "=======================================" << endl;
    cout << "Masukkan Nomor Kamar Anda: ";
    cin >> nomorKamar;
    cout << "Pilih Tipe Kamar (1. Reguler / 2. VIP): ";
    cin >> tipeKamar;

    string labelKamar = (tipeKamar == 2) ? "[VIP]" : "[Reguler]";
    int nilaiPrioritas = (tipeKamar == 2) ? 2 : 1; 

    do {
        cout << "\n=======================================" << endl;
        cout << "        SISTEM LAYANAN KAMAR           " << endl;
        cout << "        KAMAR NO: " << nomorKamar << " " << labelKamar << endl;
        cout << "=======================================" << endl;
        cout << "1. Pesan Makanan & Minuman" << endl;
        cout << "2. Minta Pembersihan Kamar" << endl;
        cout << "3. Minta Fasilitas Tambahan (Handuk/Bantal)" << endl;
        cout << "4. Cek Antrean & Proses Layanan (Priority Queue)" << endl;
        cout << "5. Cek Total Tagihan & Selesai" << endl;
        cout << "=======================================" << endl;
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                int katPilihan;
                cout << "\n--- PILIH KATEGORI LAYANAN ---" << endl;
                cout << "1. Makanan" << endl;
                cout << "2. Minuman" << endl;
                cout << "Pilih kategori (1-2): ";
                cin >> katPilihan;

                if (katPilihan == 1) {
                    int pilMakanan, jumlah;
                    cout << "\n--- DAFTAR MENU MAKANAN ---" << endl;
                    for (int i = 0; i < 5; i++) {
                        cout << i + 1 << ". " << menuMakanan[i].nama << " - Rp" << menuMakanan[i].harga << endl;
                    }
                    cout << "Pilih item makanan (1-5): ";
                    cin >> pilMakanan;

                    if (pilMakanan >= 1 && pilMakanan <= 5) {
                        cout << "Jumlah yang dipesan: ";
                        cin >> jumlah;
                        
                        totalBiaya += menuMakanan[pilMakanan - 1].harga * jumlah;

                        string info = "Kamar " + to_string(nomorKamar) + " " + labelKamar + " - Pesan " + to_string(jumlah) + " " + menuMakanan[pilMakanan - 1].nama;
                        antreanLayanan.push({nilaiPrioritas, info});
                        cout << "\nPesanan dimasukkan ke antrean prioritas dapur." << endl;
                    } else {
                        cout << "\nPilihan item tidak valid!" << endl;
                    }
                } 
                else if (katPilihan == 2) {
                    int pilMinuman, jumlah;
                    cout << "\n--- DAFTAR MENU MINUMAN ---" << endl;
                    for (int i = 0; i < 5; i++) {
                        cout << i + 1 << ". " << menuMinuman[i].nama << " - Rp" << menuMinuman[i].harga << endl;
                    }
                    cout << "Pilih item minuman (1-5): ";
                    cin >> pilMinuman;

                    if (pilMinuman >= 1 && pilMinuman <= 5) {
                        cout << "Jumlah yang dipesan: ";
                        cin >> jumlah;
                        totalBiaya += menuMinuman[pilMinuman - 1].harga * jumlah;

                        string info = "Kamar " + to_string(nomorKamar) + " " + labelKamar + " - Pesan " + to_string(jumlah) + " " + menuMinuman[pilMinuman - 1].nama;
                        antreanLayanan.push({nilaiPrioritas, info});
                        cout << "\nPesanan dimasukkan ke antrean prioritas dapur." << endl;
                    } else {
                        cout << "\nPilihan item tidak valid!" << endl;
                    }
                }
                break;
            }
            case 2: {
                string info = "Kamar " + to_string(nomorKamar) + " " + labelKamar + " - Pembersihan Kamar";
                antreanLayanan.push({nilaiPrioritas, info});
                cout << "\n✓ Permintaan Pembersihan Kamar dimasukkan ke antrean prioritas." << endl;
                break;
            }
            case 3: {
                string info = "Kamar " + to_string(nomorKamar) + " " + labelKamar + " - Fasilitas Tambahan";
                antreanLayanan.push({nilaiPrioritas, info});
                cout << "\n✓ Permintaan fasilitas tambahan dimasukkan ke antrean prioritas." << endl;
                break;
            }
            case 4:
                cout << "\n--- PROSES ANTREAN LAYANAN (BERDASARKAN PRIORITAS) ---" << endl;
                if (antreanLayanan.empty()) {
                    cout << "Tidak ada antrean layanan aktif saat ini." << endl;
                } else {
                    cout << "Jumlah pesanan di antrean: " << antreanLayanan.size() << endl;
                    
                    while (!antreanLayanan.empty()) {

                        auto topItem = antreanLayanan.top();
                        
                        cout << "[DIPROSES] (Level Prioritas: " << topItem.first << ") " << topItem.second << endl;
                        
                        antreanLayanan.pop();
                    }
                    cout << "\nSemua antrean prioritas telah diselesaikan!" << endl;
                }
                break;
            case 5: {

                int pajakService = totalBiaya * 0.10;
                int totalAkhir = totalBiaya + pajakService;

                cout << "\n=======================================" << endl;
                cout << "        RINGKASAN LAYANAN KAMAR        " << endl;
                cout << "        KAMAR NO: " << nomorKamar << " " << labelKamar << endl;
                cout << "=======================================" << endl;
                cout << "Subtotal Pesanan : Rp" << totalBiaya << endl;
                cout << "Pajak & Service (10%) : Rp" << pajakService << endl;
                cout << "---------------------------------------" << endl;
                cout << "Total Tagihan Kamar   : Rp" << totalAkhir << endl;
                cout << "=======================================" << endl;
                cout << "Terima kasih. Kembali ke sistem utama hotel..." << endl;
                break;
            }
            default:
                cout << "Pilihan tidak valid, silakan coba lagi." << endl;
        }
    } while (pilihan != 5);
}