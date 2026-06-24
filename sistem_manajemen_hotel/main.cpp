#include <iostream>
#include <string>
#include "SistemReservasi.h"

using namespace std;

void printMenu() {
    cout << "==== Sistem Reservasi Hotel ====" << endl;
    cout << "1. Lihat kamar" << endl;
    cout << "2. Lihat reservasi" << endl;
    cout << "3. Buat reservasi (pilih tipe)" << endl;
    cout << "4. Batalkan reservasi (kode booking)" << endl;
    cout << "5. Ubah reservasi (kode booking)" << endl;
    cout << "6. Simpan dan keluar" << endl;
    cout << "Pilih opsi: ";
}

int main() {
    SistemReservasi sys;
    const string dataFile = "data.txt";
    if (!sys.loadFromFile(dataFile)) {
        sys.addSampleData();
    }

    while (true) {
        printMenu();
        int opt; if (!(cin >> opt)) break;
        cin.ignore();
        if (opt == 1) {
            auto rooms = sys.getRooms();
            cout << "Kamar tersedia:\n";
            for (const auto &r : rooms) {
                cout << "- No: " << r.number << " | " << r.type << " | Harga: " << r.price << "\n";
            }
        } else if (opt == 2) {
            auto res = sys.getReservations();
            cout << "Reservasi:\n";
            for (const auto &r : res) {
                cout << "- ID:" << r.id << " | Kode:" << r.bookingCode << " | Tamu:" << r.guest.name << " | Kamar:" << r.roomNumber << " (" << r.roomType << ") | " << r.checkIn << " -> " << r.checkOut << " | " << r.status << "\n";
            }
        } else if (opt == 3) {
            Guest guest;
            cout << "Nama tamu: "; getline(cin, guest.name);
            cout << "NIK/Paspor: "; getline(cin, guest.idNumber);
            cout << "No. HP: "; getline(cin, guest.phone);
            cout << "Email: "; getline(cin, guest.email);
            cout << "Tipe kamar (Single/Double/Suite): "; string tipe; getline(cin, tipe);
            cout << "Check-in (YYYY-MM-DD): "; string checkIn; getline(cin, checkIn);
            cout << "Check-out (YYYY-MM-DD): "; string checkOut; getline(cin, checkOut);
            string code = sys.makeReservationByType(guest, tipe, checkIn, checkOut);
            if (!code.empty()) cout << "Reservasi berhasil. Kode booking: " << code << "\n";
            else cout << "Gagal membuat reservasi (tipe tidak tersedia/format tanggal salah).\n";
        } else if (opt == 4) {
            string code; cout << "Kode booking: "; getline(cin, code);
            double penalty = 0;
            if (sys.cancelReservationByCode(code, penalty)) cout << "Reservasi dibatalkan. Denda: " << penalty << "\n";
            else cout << "Kode tidak ditemukan atau sudah dibatalkan.\n";
        } else if (opt == 5) {
            string code; cout << "Kode booking: "; getline(cin, code);
            cout << "New check-in (YYYY-MM-DD): "; string nci; getline(cin, nci);
            cout << "New check-out (YYYY-MM-DD): "; string nco; getline(cin, nco);
            double penalty = 0;
            if (sys.modifyReservationByCode(code, nci, nco, penalty)) cout << "Reservasi diubah. Biaya perubahan: " << penalty << "\n";
            else cout << "Gagal mengubah reservasi (cek ketersediaan atau kode).\n";
        } else if (opt == 6) {
            if (sys.saveToFile(dataFile)) cout << "Data disimpan ke " << dataFile << "\n";
            else cout << "Gagal menyimpan data.\n";
            break;
        } else {
            cout << "Opsi tidak dikenal.\n";
        }
        cout << "\n";
    }

    return 0;
}
