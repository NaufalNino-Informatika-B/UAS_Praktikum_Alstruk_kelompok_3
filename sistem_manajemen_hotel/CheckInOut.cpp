#include <iostream>
#include <queue>   
#include <string>
#include "CheckInOut.h"

void tampilkanMenuCheckInOut() {
    using namespace std;

    
    // Representasi 5 kamar hotel 
    // false = Kamar Kosong, true = Kamar Terisi.
    bool kamarHotel[5] = {false, false, false, false, false};

    
    // Antrean tamu di lobi yang menunggu giliran dilayani (FIFO).
    queue<string> antreanLobi;

    int pilihan;
    string namaTamu;

    do {
        cout << "\n=======================================" << endl;
        cout << "    SISTEM CHECK-IN & CHECK-OUT HOTEL  " << endl;
        cout << "=======================================" << endl;
        cout << "1. Tamu Datang (Masuk Antrean Lobi)" << endl;
        cout << "2. Proses Check-in Tamu Terdepan (Queue -> Array)" << endl;
        cout << "3. Proses Check-out Kamar (Array)" << endl;
        cout << "4. Lihat Status Ketersediaan Kamar (Array)" << endl;
        cout << "5. Kembali ke Menu Utama" << endl;
        cout << "=======================================" << endl;
        cout << "Jumlah antrean di lobi saat ini: " << antreanLobi.size() << " orang" << endl;
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "\nMasukkan nama tamu yang baru datang: ";
                cin.ignore();
                getline(cin, namaTamu);
                
                // OPERASI QUEUE: PUSH untuk Tamu masuk antrean lobi
                antreanLobi.push(namaTamu);
                cout << "✓ " << namaTamu << " berhasil masuk ke antrean lobi." << endl;
                break;

            case 2:
                // OPERASI QUEUE: EMPTY untuk memeriksa apakah ada antrean
                if (antreanLobi.empty()) {
                    cout << "\nTidak ada tamu yang mengantre di lobi saat ini." << endl;
                } else {
                    // OPERASI QUEUE: FRONT untuk mengambil nama tamu paling depan
                    string tamuSekarang = antreanLobi.front();
                    
                    cout << "\nMelayani tamu: " << tamuSekarang << endl;
                    cout << "--- Daftar Kamar Kosong ---" << endl;
                    
                    // Cek kamar kosong di Array
                    bool kamarTersedia = false;
                    for (int i = 0; i < 5; i++) {
                        if (!kamarHotel[i]) {
                            cout << "- Kamar " << (101 + i) << " [KOSONG]" << endl;
                            kamarTersedia = true;
                        }
                    }

                    if (!kamarTersedia) {
                        cout << " Maaf, seluruh kamar saat ini penuh!" << endl;
                    } else {
                        int nomorPilihan;
                        cout << "Pilih nomor kamar untuk check-in: ";
                        cin >> nomorPilihan;

                        int indeksKamar = nomorPilihan - 101;

                        // Validasi input nomor kamar dan cek di Array
                        if (indeksKamar >= 0 && indeksKamar < 5 && !kamarHotel[indeksKamar]) {
                            // OPERASI ARRAY untuk ubah status kamar menjadi terisi (true)
                            kamarHotel[indeksKamar] = true;
                            cout << " Check-in Sukses! " << tamuSekarang << " resmi menempati Kamar " << nomorPilihan << endl;
                            
                            // OPERASI QUEUE: POP untuk menghapus tamu dari antrean lobi
                            antreanLobi.pop();
                        } else {
                            cout << "Nomor kamar tidak valid atau sudah terisi!" << endl;
                        }
                    }
                }
                break;

            case 3: {
                int nomorKamarOut;
                cout << "\nMasukkan nomor kamar yang ingin Check-out: ";
                cin >> nomorKamarOut;

                int indeksKamarOut = nomorKamarOut - 101;

                if (indeksKamarOut >= 0 && indeksKamarOut < 5) {
                    if (kamarHotel[indeksKamarOut]) {
                        // OPERASI ARRAY untuk mengembalikan status kamar menjadi kosong (false)
                        kamarHotel[indeksKamarOut] = false;
                        cout << "Check-out Sukses! Kamar " << nomorKamarOut << " sekarang kosong kembali." << endl;
                    } else {
                        cout << "Kamar " << nomorKamarOut << " memang sudah kosong!" << endl;
                    }
                } else {
                    cout << "Nomor kamar tidak valid!" << endl;
                }
                break;
            }

            case 4:
                cout << "\n--- STATUS KETERSEDIAAN KAMAR ---" << endl;
                for (int i = 0; i < 5; i++) {
                    cout << "Kamar " << (101 + i) << " : " << (kamarHotel[i] ? "[TERISI]" : "[KOSONG]") << endl;
                }
                break;

            case 5:
                cout << "\nKembali ke menu utama..." << endl;
                break;

            default:
                cout << "\nPilihan tidak valid, silakan coba lagi." << endl;
        }
    } while (pilihan != 5);
}