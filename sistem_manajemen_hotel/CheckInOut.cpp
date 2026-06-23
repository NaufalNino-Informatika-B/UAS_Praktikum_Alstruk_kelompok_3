#include <iostream>
#include <queue>   // Library untuk antrean lobi (Queue)
#include <string>
#include "CheckInOut.h"

void tampilkanMenuCheckInOut() {
    using namespace std;

    // Menyiapkan 5 kamar hotel secara statis.
    // false = KOSONG, true = TERISI.
    bool kamarHotel[5] = {false, false, false, false, false};

    // Menyiapkan wadah antrean tamu di lobi hotel.
    queue<string> antreanLobi;

    int pilihan;

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
            case 5:
                cout << "\nKembali ke menu utama..." << endl;
                break;
            default:
                cout << "\n[Tahap 1] Menu ini belum diimplementasikan." << endl;
        }
    } while (pilihan != 5);
}