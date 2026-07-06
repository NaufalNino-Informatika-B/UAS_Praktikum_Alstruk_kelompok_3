#include <iostream>
#include <string>
#include "Riwayat_Pesanan.h"

using namespace std;

NodeRiwayat* headRiwayat = nullptr;

void tambahKeRiwayat(NodeRiwayat*& headRiwayat, int id, string nama, string kamar) {
    NodeRiwayat* nodeBaru = new NodeRiwayat();
    nodeBaru->idReservasi = id;
    nodeBaru->namaTamu = nama;
    nodeBaru->jenisKamar = kamar;
    nodeBaru->next = nullptr;

    if (headRiwayat == nullptr) {
        headRiwayat = nodeBaru;
    } else {
        NodeRiwayat* temp = headRiwayat;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = nodeBaru;
    }
}

void tampilkanRiwayat(NodeRiwayat* headRiwayat) {
    cout << "\n=======================================" << endl;
    cout << "          DAFTAR RIWAYAT TAMU          " << endl;
    cout << "=======================================" << endl;

    if (headRiwayat == nullptr) {
        cout << "Belum ada riwayat kunjungan tamu saat ini." << endl;
        cout << "=======================================" << endl;
        return;
    }

    NodeRiwayat* temp = headRiwayat;
    while (temp != nullptr) {
        cout << "ID: " << temp->idReservasi 
             << " | Nama: " << temp->namaTamu 
             << " | Tipe Kamar: " << temp->jenisKamar << endl;
        temp = temp->next;
    }
    cout << "=======================================" << endl;
}