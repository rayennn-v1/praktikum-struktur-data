#include <iostream>
#include "Singlylist.h"

using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    address P_hapus = Nil; // Variabel penampung node yang akan dihapus
    
    // Inisialisasi List
    CreateList(L);
    
    // Alokasi dan Insert Data (Persis seperti Unguided 1)
    P1 = alokasi(2); insertFirst(L, P1);
    P2 = alokasi(0); insertFirst(L, P2);
    P3 = alokasi(8); insertFirst(L, P3);
    P4 = alokasi(12); insertFirst(L, P4);
    P5 = alokasi(9); insertFirst(L, P5);
    
    // List saat ini: 9 12 8 0 2
    
    // 1. Hapus node 9 (Node pertama)
    deleteFirst(L, P_hapus);
    
    // 2. Hapus node 2 (Node terakhir)
    deleteLast(L, P_hapus);
    
    // 3. Hapus node 8 (Setelah node 12). 
    // Saat ini list berisi: 12 8 0. Node 12 berada di posisi pertama (L.First).
    address Prec = L.First;
    deleteAfter(L, P_hapus, Prec);
    
    // Tampilkan isi list saat ini (Output yang diharapkan: 12 0)
    printInfo(L);
    
    // Tampilkan jumlah node
    cout << "Jumlah node: " << nbList(L) << endl;
    
    // Hapus seluruh list
    deleteList(L);
    
    // Tampilkan jumlah node kembali
    cout << "Jumlah node: " << nbList(L) << endl;
    
    return 0;
}