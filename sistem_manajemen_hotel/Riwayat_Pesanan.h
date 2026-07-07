#ifndef RIWAYAT_H
#define RIWAYAT_H

#include <string>

struct NodeRiwayat {
    int idReservasi;
    std::string namaTamu;
    std::string jenisKamar;
    NodeRiwayat* next;
};

extern NodeRiwayat* headRiwayat;

void tambahKeRiwayat(NodeRiwayat*& headRiwayat, int id, std::string nama, std::string kamar);
void tampilkanRiwayat(NodeRiwayat* headRiwayat);

#endif