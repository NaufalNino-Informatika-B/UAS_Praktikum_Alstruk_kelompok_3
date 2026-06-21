#include <iostream>
#include <queue>
#include <string>
#include "Layanan.h"

void tampilkanMenuLayanan() {
    // Memasukkan 'using namespace std' di dalam fungsi agar tidak bentrok
    // dengan namespace global dari library atau header lain.
    using namespace std; 

    // STRUKTUR DATA: ARRAY OF STRUCT
    // Mengelompokkan data menu makanan ke dalam array statis berisi 5 item.
    ItemLayanan menuMakanan[5] = {
        {"Nasi Goreng Hotel", 45000},
        {"Club Sandwich", 40000},
        {"Sup Buntut Premium", 65000},
        {"Chicken Caesar Salad", 35000},
        {"French Fries", 25000}
    };

    // Mengelompokkan data menu minuman ke dalam array statis berisi 5 item.
    ItemLayanan menuMinuman[5] = {
        {"Fresh Juice (Jeruk/Alpukat)", 20000},
        {"Iced Cafe Latte", 25000},
        {"Hot Lemon Tea", 15000},
        {"Milkshake Chocolate", 22000},
        {"Air Mineral Premium", 10000}
    };

    // STRUKTUR DATA UTAMA: PRIORITY QUEUE
    // Menggunakan std::pair<int, string> untuk menyimpan dua informasi sekaligus:
    // 1. int (first)   : Sebagai key tingkat prioritas (VIP = 2, Reguler = 1).
    // 2. string (second): Sebagai value deskripsi pesanan/layanan kamar.
    priority_queue<pair<int, string>> antreanLayanan;

    int nomorKamar;
    int tipeKamar; 
    int pilihan;
    int totalBiaya = 0; 

    // [INPUT PROSES AWAL]
    cout << "\n=======================================" << endl;
    cout << "      WELCOME TO ROOM SERVICE SYSTEM   " << endl;
    cout << "=======================================" << endl;
    cout << "Masukkan Nomor Kamar Anda: ";
    cin >> nomorKamar;
    cout << "Pilih Tipe Kamar (1. Reguler / 2. VIP): ";
    cin >> tipeKamar;

    // LOGIKA PENENTUAN PRIORITAS
    // Jika input tipeKamar adalah 2, maka diberi label [VIP] dan bobot prioritasnya tinggi (2).
    // Jika selain itu, dianggap kamar [Reguler] dengan bobot prioritas rendah (1).
    string labelKamar = (tipeKamar == 2) ? "[VIP]" : "[Reguler]";
    int nilaiPrioritas = (tipeKamar == 2) ? 2 : 1; 

    // KONTROL ALUR: DO-WHILE LOOP
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

        // Percabangan untuk mengeksekusi fungsi berdasarkan angka menu yang dipilih
        switch (pilihan) {
            case 1: {
                int katPilihan;
                cout << "\n--- PILIH KATEGORI LAYANAN ---" << endl;
                cout << "1. Makanan" << endl;
                cout << "2. Minuman" << endl;
                cout << "Pilih kategori (1-2): ";
                cin >> katPilihan;

                // SUB KATEGORI 1: MAKANAN
                if (katPilihan == 1) {
                    int pilMakanan, jumlah;
                    cout << "\n--- DAFTAR MENU MAKANAN ---" << endl;
                    // Perulangan FOR untuk membaca dan menampilkan isi Array Struct menuMakanan
                    for (int i = 0; i < 5; i++) {
                        cout << i + 1 << ". " << menuMakanan[i].nama << " - Rp" << menuMakanan[i].harga << endl;
                    }
                    cout << "Pilih item makanan (1-5): ";
                    cin >> pilMakanan;

                    // Validasi batas input array agar tidak terjadi 'out of bounds'
                    if (pilMakanan >= 1 && pilMakanan <= 5) {
                        cout << "Jumlah yang dipesan: ";
                        cin >> jumlah;
                        
                        // Menghitung harga item dikali jumlah, lalu ditumpuk ke totalBiaya
                        totalBiaya += menuMakanan[pilMakanan - 1].harga * jumlah;

                        // OPERASI QUEUE: PUSH
                        // Menyusun string deskripsi pesanan, lalu memasukkannya ke dalam Priority Queue
                        // bersama dengan bobot nilaiPrioritas kamar.
                        string info = "Kamar " + to_string(nomorKamar) + " " + labelKamar + " - Pesan " + to_string(jumlah) + " " + menuMakanan[pilMakanan - 1].nama;
                        antreanLayanan.push({nilaiPrioritas, info});
                        cout << "✓ Pesanan dimasukkan ke antrean prioritas dapur." << endl;
                    } else {
                        cout << "⚠ Pilihan item tidak valid!" << endl;
                    }
                } 
                // SUB KATEGORI 2: MINUMAN
                else if (katPilihan == 2) {
                    int pilMinuman, jumlah;
                    cout << "\n--- DAFTAR MENU MINUMAN ---" << endl;
                    // Perulangan FOR untuk membaca dan menampilkan isi Array Struct menuMinuman
                    for (int i = 0; i < 5; i++) {
                        cout << i + 1 << ". " << menuMinuman[i].nama << " - Rp" << menuMinuman[i].harga << endl;
                    }
                    cout << "Pilih item minuman (1-5): ";
                    cin >> pilMinuman;

                    if (pilMinuman >= 1 && pilMinuman <= 5) {
                        cout << "Jumlah yang dipesan: ";
                        cin >> jumlah;
                        totalBiaya += menuMinuman[pilMinuman - 1].harga * jumlah;

                        // OPERASI QUEUE: PUSH
                        string info = "Kamar " + to_string(nomorKamar) + " " + labelKamar + " - Pesan " + to_string(jumlah) + " " + menuMinuman[pilMinuman - 1].nama;
                        antreanLayanan.push({nilaiPrioritas, info});
                        cout << "✓ Pesanan dimasukkan ke antrean prioritas dapur." << endl;
                    } else {
                        cout << "⚠ Pilihan item tidak valid!" << endl;
                    }
                }
                break;
            }
            case 2: {
                // OPERASI QUEUE: PUSH untuk layanan non-makanan
                string info = "Kamar " + to_string(nomorKamar) + " " + labelKamar + " - Pembersihan Kamar";
                antreanLayanan.push({nilaiPrioritas, info});
                cout << "\n✓ Permintaan Pembersihan Kamar dimasukkan ke antrean prioritas." << endl;
                break;
            }
            case 3: {
                // OPERASI QUEUE: PUSH untuk layanan fasilitas tambahan
                string info = "Kamar " + to_string(nomorKamar) + " " + labelKamar + " - Fasilitas Tambahan";
                antreanLayanan.push({nilaiPrioritas, info});
                cout << "\n✓ Permintaan fasilitas tambahan dimasukkan ke antrean prioritas." << endl;
                break;
            }
            case 4:
                cout << "\n--- PROSES ANTREAN LAYANAN (BERDASARKAN PRIORITAS) ---" << endl;
                
                // OPERASI QUEUE: EMPTY
                // Mengecek apakah antrean kosong atau tidak sebelum melakukan pemrosesan data.
                if (antreanLayanan.empty()) {
                    cout << "Tidak ada antrean layanan aktif saat ini." << endl;
                } else {
                    // .size() digunakan untuk menghitung jumlah total elemen yang ada di dalam queue
                    cout << "Jumlah pesanan di antrean: " << antreanLayanan.size() << endl;
                    
                    // Melakukan perulangan terus-menerus selama antrean TIDAK kosong (!antreanLayanan.empty())
                    while (!antreanLayanan.empty()) {
                        // OPERASI QUEUE: TOP
                        // Mengambil/melihat data yang berada di kasta prioritas tertinggi saat ini.
                        auto topItem = antreanLayanan.top();
                        
                        // Menampilkan output proses. topItem.first menduga angka prioritas, topItem.second menduga teks pesanannya.
                        cout << "[DIPROSES] (Level Prioritas: " << topItem.first << ") " << topItem.second << endl;
                        
                        // OPERASI QUEUE: POP
                        // Mengeluarkan/menghapus data terdepan yang baru saja diproses agar antrean terus maju.
                        antreanLayanan.pop();
                    }
                    cout << "✓ Semua antrean prioritas telah diselesaikan!" << endl;
                }
                break;
            case 5: {

                // Menghitung pajak pembangunan & biaya layanan kamar khas hotel sebesar 10%
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
                cout << "⚠ Pilihan tidak valid, silakan coba lagi." << endl;
        }
    } while (pilihan != 5);
}