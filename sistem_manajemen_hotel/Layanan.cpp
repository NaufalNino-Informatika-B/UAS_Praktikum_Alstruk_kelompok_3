#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include "Layanan.h"
#include "Reservasi.h"

using namespace std;

void tampilkanMenuLayanan(NodeReservasi* head) {
    NodeReservasi* tempCek = head;
    bool adaTamuAktif = false;

    while (tempCek != nullptr) {
        if (tempCek->isCheckedIn) {
            adaTamuAktif = true;
            break;
        }
        tempCek = tempCek->next;
    }

    if (!adaTamuAktif) {
        cout << "\nMaaf, belum ada tamu aktif yang sudah check-in!" << endl;
        cout << "Silakan lakukan check-in di menu Check In/Out terlebih dahulu." << endl;
        return;
    }

    string IDReservasi;
    cout << "\n=======================================" << endl;
    cout << "  WELCOME TO ROOM SERVICE SYSTEM  " << endl;
    cout << "=======================================" << endl;
    cout << "Masukkan ID Reservasi Tamu: ";
    cin.ignore();
    getline(cin, IDReservasi);

    bool ditemukan = false;
    string labelKamar = "";

    NodeReservasi* temp = head;
    while (temp != nullptr) {
        if (temp->isCheckedIn && temp->idReservasi == stoi(IDReservasi)) {
            ditemukan = true;
            labelKamar = temp->jenisKamar;
            break;
        }
        temp = temp->next;
    }

    if (!ditemukan) {
        cout << "ID Reservasi tidak terdaftar di daftar tamu aktif yang sedang check-in. Akses ditolak!" << endl;
        return;
    }

    int tingkatPrioritas = (labelKamar == "VIP") ? 2 : 1;

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
        {"Air Mineral Premium", 10000},
        {"", 0}, 
        {"", 0}  
    };

    priority_queue<pair<int, string>> antreanLayanan;

    int pilihan;
    int totalBiaya = 0;

    do {
        cout << "\n=======================================" << endl;
        cout << "         SISTEM LAYANAN KAMAR          " << endl;
        cout << "         TAMU: " << IDReservasi << " (" << labelKamar << ")" << endl;
        cout << "=======================================" << endl;
        cout << "1. Pesan Makanan & Minuman" << endl;
        cout << "2. Minta Pembersihan Kamar" << endl;
        cout << "3. Minta Fasilitas Tambahan (Handuk/Bantal)" << endl;
        cout << "4. Cek Antrean & Proses Layanan" << endl;
        cout << "5. Cek Total Tagihan & Selesai" << endl;
        cout << "6. Kembali ke Menu Utama" << endl;
        cout << "=======================================" << endl;
        cout << "Pilih menu (1-6): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                int pilihJenis;
                cout << "\nPilih jenis layanan: " << endl;
                cout << "1. Makanan" << endl;
                cout << "2. Minuman" << endl;
                cout << "3. Makanan dan Minuman" << endl;
                cout << "4. Batal Pemesanan" << endl;
                cout << "Pilihan Anda: ";
                cin >> pilihJenis;

                bool pilihMakanan = false;
                bool pilihMinuman = false;
                string namaMakanan = "";
                string namaMinuman = "";
                int hargaMakanan = 0;
                int hargaMinuman = 0;

                if (pilihJenis == 1 || pilihJenis == 3) {
                    cout << "\n--- MENU MAKANAN ---" << endl;
                    for (int i = 0; i < 5; i++) {
                        cout << i + 1 << ". " << menuMakanan[i].nama << " (Rp" << menuMakanan[i].harga << ")" << endl;
                    }
                    cout << "Pilih Nomor Makanan (1-5): ";
                    int pilMakan;
                    cin >> pilMakan;

                    if (pilMakan >= 1 && pilMakan <= 5) {
                        pilihMakanan = true;
                        namaMakanan = menuMakanan[pilMakan - 1].nama;
                        hargaMakanan = menuMakanan[pilMakan - 1].harga;
                    } else {
                        cout << "Pilihan makanan tidak valid!" << endl;
                    }
                }

                if (pilihJenis == 2 || pilihJenis == 3) {
                    cout << "\n--- MENU MINUMAN ---" << endl;
                    for (int i = 0; i < 3; i++) {
                        cout << i + 1 << ". " << menuMinuman[i].nama << " (Rp" << menuMinuman[i].harga << ")" << endl;
                    }
                    cout << "Pilih Nomor Minuman (1-3): ";
                    int pilMinum;
                    cin >> pilMinum;

                    if (pilMinum >= 1 && pilMinum <= 3) {
                        pilihMinuman = true;
                        namaMinuman = menuMinuman[pilMinum - 1].nama;
                        hargaMinuman = menuMinuman[pilMinum - 1].harga;
                    } else {
                        cout << "Pilihan minuman tidak valid!" << endl;
                    }
                }

                if (pilihJenis == 4) {
                    cout << "Pemesanan dibatalkan." << endl;
                    break;
                }

                if ((pilihJenis == 1 && pilihMakanan) || (pilihJenis == 2 && pilihMinuman) || (pilihJenis == 3 && pilihMakanan && pilihMinuman)) {
                    totalBiaya += hargaMakanan + hargaMinuman;

                    string deskripsiPesanan = "Pesanan ";
                    if (pilihMakanan) {
                        deskripsiPesanan += namaMakanan;
                    }
                    if (pilihMakanan && pilihMinuman) {
                        deskripsiPesanan += " & ";
                    }
                    if (pilihMinuman) {
                        deskripsiPesanan += namaMinuman;
                    }
                    deskripsiPesanan += " (" + labelKamar + ")";

                    antreanLayanan.push(make_pair(tingkatPrioritas, deskripsiPesanan));
                    cout << "\nPesanan berhasil dimasukkan ke antrean." << endl;
                } else {
                    cout << "Pilihan tidak valid!" << endl;
                }
                break;
            }
            case 2: {
                string deskripsiLayanan = "Pembersihan Kamar (" + labelKamar + ")";
                antreanLayanan.push(make_pair(tingkatPrioritas, deskripsiLayanan));
                totalBiaya += 25000;
                cout << "\n Permintaan pembersihan kamar dimasukkan ke antrean." << endl;
                break;
            }
            case 3: {
                string deskripsiLayanan = "Fasilitas Tambahan (" + labelKamar + ")";
                antreanLayanan.push(make_pair(tingkatPrioritas, deskripsiLayanan));
                totalBiaya += 15000;
                cout << "\n Permintaan fasilitas tambahan dimasukkan ke antrean." << endl;
                break;
            }
            case 4:
                cout << "\n--- PROSES ANTREAN LAYANAN (PRIORITY QUEUE) ---" << endl;
                if (antreanLayanan.empty()) {
                    cout << "Tidak ada antrean permintaan saat ini." << endl;
                } else {
                    while (!antreanLayanan.empty()) {
                        pair<int, string> depan = antreanLayanan.top();
                        cout << "[Prioritas: " << depan.first << "] " << depan.second << " -> [PERMINTAAN DI PROSES]" << endl;
                        antreanLayanan.pop();
                    }
                    cout << "\n Semua antrean layanan selesai diproses berdasarkan prioritas!" << endl;
                }
                break;
            case 5: {
                int pajakService = totalBiaya * 0.10;
                int totalAkhir = totalBiaya + pajakService;

                cout << "\n=======================================" << endl;
                cout << "       RINGKASAN LAYANAN KAMAR         " << endl;
                cout << "       TAMU: " << IDReservasi << " (" << labelKamar << ")" << endl;
                cout << "=======================================" << endl;
                cout << "Subtotal Pesanan      : Rp" << totalBiaya << endl;
                cout << "Pajak & Service (10%) : Rp" << pajakService << endl;
                cout << "---------------------------------------" << endl;
                cout << "Total Tagihan Kamar   : Rp" << totalAkhir << endl;
                cout << "=======================================" << endl;
                cout << "Terima kasih. Kembali ke sistem utama hotel..." << endl;
                break;
            }
            default:
                cout << "\nPilihan tidak valid!" << endl;
        }
    } while (pilihan != 5 && pilihan != 6);
}