#ifndef RESERVASI_H
#define RESERVASI_H

#include <string>

struct NodeReservasi {
    int idReservasi;
    std::string namaTamu;
    std::string tanggal;
    std::string jenisKamar;
    bool isCheckedIn;
    NodeReservasi* next;
};

void tampilkanStatusKamar(NodeReservasi* head);
void tampilkanMenuReservasi(NodeReservasi*& head, int& counterID);

#endif