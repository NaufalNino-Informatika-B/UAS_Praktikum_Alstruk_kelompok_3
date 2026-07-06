#include <iostream>
#include "Reservasi.h"
#include "CheckInOut.h"
#include "Layanan.h"
#include "Riwayat_Pesanan.h"
#include <limits>

using namespace std;

void menuUtama(NodeReservasi* head) {
    tampilkanStatusKamar(head);
    cout << "\n======== MENU UTAMA ========\n" << endl;
    cout << "1.Reservasi\n" << endl;
    cout << "2.Check In/Out\n" << endl;
    cout << "3.Riwayat Reservasi\n" << endl;
    cout << "4.Pelayanan Kamar\n" << endl;
    cout << "5.Keluar\n" << endl;
    cout << "============================\n" << endl;
}

int pilihMenu() {
    int pilihan;
    while (true) {
        cout << "Masukan angka 1-5 untuk memilih menu yang tersedia" << endl;
        cout << "Masukkan pilihan Anda: ";
        if (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Input tidak valid. Silakan masukkan angka.\n" << endl;
            continue;
        }
        if (pilihan >= 1 && pilihan <= 5) {
            return pilihan;
        }
        cout << "Pilihan tidak valid. Silakan coba lagi.\n" << endl;
    }
}

int main() {
    int pilihan;
    NodeReservasi* head = nullptr;
    int counterID = 1;
    do {
        menuUtama(head);
        pilihan = pilihMenu();
        switch (pilihan) {
            case 1:
                tampilkanMenuReservasi(head, counterID);
                break;
            case 2:
                tampilkanMenuCheckInOut(head);
                break;
            case 3:
                tampilkanRiwayat(headRiwayat);
                break;
            case 4:
                tampilkanMenuLayanan(head);
                break;
            case 5:
                cout << "menu ditutup.\n" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n" << endl;
        }
    } while (pilihan != 5);
    return 0;
}
