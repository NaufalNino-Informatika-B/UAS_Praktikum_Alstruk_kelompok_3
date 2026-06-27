#ifndef RESERVASI_H
#define RESERVASI_H

#include <string>

struct NodeReservasi {
    int idReservasi;
    std::string namaTamu;
    std::string tanggal;
    std::string jenisKamar;
    NodeReservasi* next;
};

void tampilkanMenuReservasi(NodeReservasi*& head, int& counterID);

#endif