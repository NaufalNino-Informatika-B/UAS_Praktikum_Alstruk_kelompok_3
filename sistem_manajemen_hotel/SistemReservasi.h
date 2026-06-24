#ifndef RESERVASI_H
#define RESERVASI_H

#include <string>

// Merepresentasikan satu data reservasi kamar milik tamu
struct NodeReservasi {
    int idReservasi;
    std::string namaTamu;
    int nomorKamar;
    std::string tipeKamar;
    NodeReservasi* next; // Pointer untuk menyambung ke data reservasi berikutnya
};

// Deklarasi fungsi utama menu reservasi
void tampilkanMenuReservasi();

#endif