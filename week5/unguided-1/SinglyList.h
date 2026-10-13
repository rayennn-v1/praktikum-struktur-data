#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#include <iostream>

#define Nil NULL
using namespace std;

// Deklarasi tipe data
typedef int infotype;
typedef struct ElmList *address;

// Struktur node (elemen) linked list
struct ElmList {
    infotype info;
    address next;
};

// Struktur dari linked list itu sendiri
struct List {
    address First;
};

// Deklarasi prosedur dan fungsi ADT
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif