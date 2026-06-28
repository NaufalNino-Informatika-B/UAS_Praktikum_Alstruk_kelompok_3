#ifndef LAYANAN_H
#define LAYANAN_H

#include <string>
#include "Reservasi.h"

struct ItemLayanan {
    std::string nama;
    int harga;
};

void tampilkanMenuLayanan(NodeReservasi* head);

#endif