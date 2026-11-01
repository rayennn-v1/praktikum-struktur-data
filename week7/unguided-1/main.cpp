#include <iostream>
#include "Buku.h"

using namespace std;

// Fungsi untuk mengecek duplikasi kodeBuku sebelum insert
bool cekDuplikat(List L, string kode) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.kodeBuku == kode) {
            return true;
        }
        P = P->next;
    }
    return false;
}

void inputBuku(List &L) {
    infotype data;
    cout << "masukkan kode buku: ";
    cin >> data.kodeBuku;
    cout << "masukkan judul buku: ";
    cin >> data.judul;
    cout << "masukkan tahun terbit: ";
    cin >> data.thnTerbit;

    if (!cekDuplikat(L, data.kodeBuku)) {
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

    inputBuku(L);
    inputBuku(L);
    inputBuku(L);
    inputBuku(L);

    cout << "DATA LIST 1\n" << endl;
    printInfo(L);

    return 0;
}