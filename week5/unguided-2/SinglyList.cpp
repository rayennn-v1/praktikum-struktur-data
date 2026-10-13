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

// --- IMPLEMENTASI FUNGSI BARU SOAL 2 ---

// Menghapus node pertama (deleteFirst)
void deleteFirst(List &L, address &P) {
    if (L.First != Nil) {
        P = L.First;
        L.First = P->next;
        P->next = Nil;
        dealokasi(P);
    }
}

// Menghapus node terakhir (deleteLast)
void deleteLast(List &L, address &P) {
    if (L.First != Nil) {
        if (L.First->next == Nil) {
            deleteFirst(L, P);
        } else {
            address Prec = L.First;
            while (Prec->next->next != Nil) {
                Prec = Prec->next;
            }
            P = Prec->next;
            Prec->next = Nil;
            dealokasi(P);
        }
    }
}

// Menghapus node setelah node Prec (deleteAfter)
void deleteAfter(List &L, address &P, address Prec) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = Nil;
        dealokasi(P);
    }
}

// Menghitung jumlah node (nbList)
int nbList(List L) {
    int count = 0;
    address P = L.First;
    while (P != Nil) {
        count++;
        P = P->next;
    }
    return count;
}

// Menghapus seluruh isi list (deleteList)
void deleteList(List &L) {
    address P;
    while (L.First != Nil) {
        deleteFirst(L, P);
    }
    cout << "\n- List Berhasil Terhapus -" << endl;
}