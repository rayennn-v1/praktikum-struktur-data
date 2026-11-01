#include <iostream>
#include "Buku.h"

using namespace std;

void inputBuku(List &L) {
    infotype data;
    cout << "masukkan kode buku: ";
    cin >> data.kodeBuku;
    cout << "masukkan judul buku: ";
    cin >> data.judul;
    cout << "masukkan tahun terbit: ";
    cin >> data.thnTerbit;

    if (findElm(L, data) == Nil) {
        address P = alokasi(data);
        insertLast(L, P);
    } else {
        cout << "kode buku sudah terdaftar" << endl;
    }
    cout << endl;
}

int main() {
    List L;
    CreateList(L);

    // 1. Insert Data Buku
    inputBuku(L);
    inputBuku(L);
    inputBuku(L);
    inputBuku(L);

    cout << "DATA LIST 1\n" << endl;
    printInfo(L);

    // 2. Pencarian Elemen (Searching)
    infotype x;
    cout << "\nMasukkan Kode Buku yang dicari : ";
    cin >> x.kodeBuku;

    address P = findElm(L, x);
    if (P != Nil) {
        cout << "\nKode Buku    : " << P->info.kodeBuku << endl;
        cout << "Judul        : " << P->info.judul << endl;
        cout << "Tahun Terbit : " << P->info.thnTerbit << endl;
    } else {
        cout << "\nData buku dengan kode " << x.kodeBuku << " tidak ditemukan." << endl;
    }

    return 0;
}