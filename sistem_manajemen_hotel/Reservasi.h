#ifndef RESERVASI_H
#define RESERVASI_H

#include <string>

// Struktur data Linked List untuk reservasi
struct NodeReservasi {
    int idReservasi;
    std::string namaTamu;
    std::string tanggal;
    std::string jenisKamar;
    NodeReservasi* next;
};

// Deklarasi fungsi utama
void tampilkanMenuReservasi();

#endif