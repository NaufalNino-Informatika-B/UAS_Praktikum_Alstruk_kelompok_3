#ifndef RIWAYAT_PEMESANAN_H
#define RIWAYAT_PEMESANAN_H

#include <string>

struct NodeRiwayat {
    std::string namaTamu;
    std::string aksi;
    std::string waktu;
    NodeRiwayat* next;
};

void tambahLogRiwayat(NodeRiwayat*& top, std::string nama, std::string jenisAksi, std::string infoWaktu);
void tampilkanMenuRiwayat(NodeRiwayat* top);

#endif