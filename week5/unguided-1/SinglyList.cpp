#include <iostream>
#include "Singlylist.h"
using namespace std;

// Prosedur untuk membuat list kosong
void CreateList(List &L) {
    L.First = Nil;
}

// Fungsi untuk mengalokasikan memori untuk node baru
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

// Prosedur untuk menghapus dan membebaskan alokasi memori
void dealokasi(address &P) {
    delete P;
    P = Nil;
}

// Prosedur untuk menampilkan isi linked list
void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

// Prosedur untuk menyisipkan node di awal list
void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}