# <h1 align="center">Laporan Praktikum Modul 4 - SINGLY LINKED LIST (BAGIAN PERTAMA) </h1>
<p align="center">Mukhammad Ari Trianirto - 109082530027</p>

## Dasar Teori
Linked list (atau list) merupakan salah satu bentuk struktur data atau representasi penyimpanan berupa serangkaian elemen data yang saling berhubungan [1]. Struktur data ini bersifat sangat fleksibel karena ukurannya dapat tumbuh dan mengerut sesuai dengan kebutuhan alokasi memori secara dinamis [1]. Data yang disimpan di dalam linked list dapat berupa data tunggal (misalnya sebuah variabel tipe string) maupun data majemuk atau record (misalnya gabungan tipe data string dan integer untuk data mahasiswa) [2]. Dalam implementasinya, linked list sangat disarankan untuk menggunakan operasi pointer dibandingkan array [2]. Hal ini dikarenakan pointer bersifat dinamis dan sangat cocok untuk mengelola elemen data yang posisinya saling bergandengan, sementara array lebih statis dan kaku karena jumlah maksimum elemennya harus diketahui sejak awal program berjalan [2].   

Singly Linked List adalah salah satu model Abstract Data Type (ADT) pada linked list yang dirancang agar hanya memiliki satu arah pointer penunjuk saja [3]. Komponen utama pada sebuah elemen Singly Linked List dibagi menjadi dua bagian, yaitu bagian 'Data' yang menyimpan informasi utama dan bagian 'Suksesor' yang bertindak sebagai penghubung ke elemen berikutnya [3]. Terdapat beberapa sifat utama dari struktur Singly Linked List, yaitu hanya memerlukan satu buah pointer, node di posisi paling akhir akan menunjuk ke kondisi NULL (kecuali pada model circular), proses pembacaan data hanya bisa dilakukan secara maju (forward), pencarian dilakukan secara sekuensial, dan kemudahan yang tinggi saat melakukan penyisipan maupun penghapusan elemen di area tengah list [4].   

Terdapat istilah-istilah penting yang lazim digunakan dalam Singly Linked List, antara lain first atau head (pointer yang menunjuk ke alamat elemen paling pertama), next (pointer suksesor ke elemen di depannya), NULL/Nil (kondisi kosong di mana pointer tidak menunjuk ke mana pun), dan node/simpul/elemen (tempat data tersimpan di dalam memori) [4]. Secara operasional, primitif atau fungsi dasar ADT pada Singly Linked List mencakup pembuatan list awal (Create List), alokasi memori (menggunakan perintah new pada bahasa C++), dealokasi memori (menggunakan perintah delete), penyisipan elemen (Insert First, Insert Last, Insert After), penghapusan elemen (Delete First, Delete Last, Delete After), penelusuran (View), pencarian (Searching), serta pembaruan isi elemen (Update) [3]. 
## Guided 

### 1. Singly Linked List

#### list.h

```C++
//hear guard digunakan untuk mencegah file header yg sama
//di-include lebih dari sekali dalam satu program

#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //mendefinisikan alias address

struct node { //node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedList { //ini linked listnya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedList list);
void createList(linkedList &list);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList list);
void insertFirst(linkedList &list, address nodeBaru);
void insertAfter(linkedList &list, address nodeBaru, address prev);
void insertLast(linkedList &list, address nodeBaru);

void delFirst(linkedList &list);
void delLast(linkedList &list);
void delAfter(linkedList &list, address nodeHapus, address nodePrev);
int nbList(linkedList list);
void deleteList(linkedList &list);

#endif
```

### list.cpp

```C++

#include "list.h"
#include <iostream>
using namespace std;

// I.S = Initial State / kondisi awal
// F.S = Final State / kondisi akhir

// Fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List) {
    if (List.first == Nil) {
        return true;
    } else {
        return false;
    }
}

// Pembuatan linked list kosong
void createList(linkedList &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

// Pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) {
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isi data sesuai parameter dan next = Nil */
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

// Penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

// Prosedur untuk insert / menambahkan node baru ke dalam list
void insertFirst(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

// Prosedur-prosedur untuk delete / menghapus node
void delFirst(linkedList &List) {
    /* I.S. list tidak kosong
       F.S. node pertama di list terhapus */
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &List) {
    /* I.S. list tidak kosong
       F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        if (nodeHapus->next == Nil) {
            List.first = Nil;
            dealokasi(nodeHapus);
        } else {
            while (nodeHapus->next != Nil) {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    } else {
        cout << "List kosong" << endl;
    }
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev) {
    /* I.S. list tidak kosong, alamat salah satu elemen list
       F.S. nodeBantu adalah alamat dari Prev->next,
       menghapus Prev->next dari list */
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// Prosedur untuk menampilkan isi list
void printList(linkedList List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama : " << nodeBantu->isidata.nama
                << ", NIM : " << nodeBantu->isidata.nim
                << ", Usia : " << nodeBantu->isidata.umur
                << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

// Function untuk menampilkan jumlah node di dalam list
int nbList(linkedList List) {
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node di dalam list */
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

// Prosedur untuk menghapus list (menghapus semua node di dalam list)
void deleteList(linkedList &List) {
    /* I.S. list sudah ada
       F.S. menghapus semua node di dalam list */
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while (nodeBantu != Nil) {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List sudah terhapus!" << endl;
}
```

### main.cpp

```C++

#include "list.h"
#include <iostream>
using namespace std;

int main() {
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;

    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);

    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```

Program ini mengimplementasikan struktur data Singly Linked List berbasis C++ secara modular (list.h, list.cpp, main.cpp) untuk mengelola data mahasiswa (nama, nim, umur). Program ini mendemonstrasikan operasi dasar linked list, meliputi manajemen memori dinamis, penyisipan elemen (di awal, akhir, dan tengah), penghapusan elemen, serta penelusuran (menampilkan data dan menghitung jumlah elemen). Pada fungsi utama (main.cpp), program menguji operasi-operasi tersebut secara berurutan: mulai dari menyisipkan 5 data mahasiswa, menampilkannya, menghapus sebagian data, hingga mengosongkan list secara keseluruhan..

## Unguided 

### 1.  Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h” Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file “Singlylist.cpp” Kemudian buat program utama didalam file “main.cpp”.

### SinglyList.h
```C++
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
```
### SinglyList.cpp
```C++
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
```
### main.cpp
```C++
#include <iostream>
#include "Singlylist.h"

using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    
    // Inisialisasi List
    CreateList(L);
    
    // Alokasi dan Insert Data
    P1 = alokasi(2);
    insertFirst(L, P1);
    
    P2 = alokasi(0);
    insertFirst(L, P2);
    
    P3 = alokasi(8);
    insertFirst(L, P3);
    
    P4 = alokasi(12);
    insertFirst(L, P4);
    
    P5 = alokasi(9);
    insertFirst(L, P5);
    
    // Menampilkan isi list
    printInfo(L);
    
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://raw.githubusercontent.com/rayennn-v1/praktikum-struktur-data/main/week5/unguided-1/Screenshot-unguided-1.png)

Program Unguided 1 ini mengimplementasikan struktur data Singly Linked List (integer) secara modular (Singlylist.h, Singlylist.cpp, main.cpp). Program ini berfokus pada operasi dasar linked list, khususnya penyisipan elemen di awal list (insertFirst). Pada program utama, lima angka disisipkan secara berurutan (2, 0, 8, 12, 9). Karena menggunakan insertFirst, setiap data baru selalu menempati posisi terdepan, sehingga saat list ditampilkan, urutannya menjadi terbalik dari urutan input, yaitu: 9 12 8 0 2.

### 2. Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList(). 

### SinglyList.h
```C++
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

// Deklarasi prosedur dan fungsi ADT (Dari Unguided 1)
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

// Tambahan deklarasi untuk Soal Latihan 2
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address &P, address Prec);
int nbList(List L);
void deleteList(List &L);

#endif
```
### SinglyList.cpp
```C++
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
```
### main.cpp
```C++
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
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://raw.githubusercontent.com/rayennn-v1/praktikum-struktur-data/main/week5/unguided-2/Screenshot-unguided-2.png)

Program pada bagian Unguided 2 ini mengembangkan implementasi Singly Linked List sebelumnya dengan menambahkan fungsi penghapusan dan perhitungan jumlah elemen. Pada pengujiannya, list awal yang berisi 9 12 8 0 2 dimanipulasi secara berurutan dengan menghapus elemen pertama (angka 9) menggunakan prosedur deleteFirst, elemen terakhir (angka 2) menggunakan deleteLast, dan elemen di tengah (angka 8) menggunakan deleteAfter. Program kemudian menampilkan sisa elemen di dalam list (menjadi 12 0) beserta total jumlah nodenya melalui fungsi nbList, dan diakhiri dengan mengosongkan seluruh alokasi memori menggunakan prosedur deleteList hingga list benar-benar terhapus (kosong).

## Kesimpulan
Berdasarkan praktikum Modul 4 mengenai Singly Linked List yang telah dilaksanakan, dapat ditarik beberapa kesimpulan sebagai berikut:

Konsep Dasar Singly Linked List: Singly Linked List merupakan struktur data dinamis yang menggunakan pointer untuk menghubungkan satu elemen (node) dengan elemen berikutnya dalam satu arah. Struktur ini menawarkan fleksibilitas memori yang lebih tinggi dibandingkan array, karena ukuran list dapat bertambah atau berkurang secara dinamis sesuai kebutuhan saat program berjalan (dinamis).

Pendekatan Modularitas (Modular Programming): Implementasi Singly Linked List dalam praktikum ini berhasil diterapkan menggunakan bahasa C++ dengan pendekatan modular. Pemisahan kode ke dalam tiga bagian, yaitu file header (.h) untuk deklarasi, file sumber (.cpp) untuk implementasi logika/fungsi, dan file utama (main.cpp) untuk pengujian, membuat program menjadi lebih rapi, terstruktur, dan mudah untuk dikelola.

Penguasaan Operasi Primitif: Melalui latihan Guided dan Unguided, berbagai operasi dasar (primitif) pada Singly Linked List telah berhasil dipahami dan diimplementasikan. Operasi tersebut mencakup alokasi dan dealokasi memori, penyisipan elemen (insertFirst, insertLast, insertAfter), penghapusan elemen (deleteFirst, deleteLast, deleteAfter, deleteList), serta penelusuran elemen untuk menampilkan isi data dan menghitung jumlah node (nbList).

Penerapan Fleksibel: Struktur Singly Linked List terbukti fleksibel karena dapat digunakan untuk mengelola berbagai jenis struktur data, mulai dari penyimpanan tipe data tunggal sederhana seperti bilangan integer (pada latihan Unguided), hingga penyimpanan record data majemuk yang kompleks seperti data mahasiswa (pada latihan Guided).

## Referensi
[1] A. S. Rosa dan M. Shalahuddin, "Penerapan Struktur Data Linked List dalam Manajemen Memori Dinamis," Jurnal Informatika dan Komputer, vol. 9, no. 2, hal. 45-52, 2021.

[2] B. Suprapto dan H. Kurniawan, "Analisis Kinerja Algoritma Singly Linked List pada Alokasi Memori," Jurnal Rekayasa Sistem dan Teknologi Informasi (JURSTI), vol. 6, no. 1, hal. 112-118, 2022.

[3] C. R. Widodo, "Implementasi Abstract Data Type (ADT) Singly Linked List Menggunakan Pendekatan C++," Jurnal Teknik Informatika Terapan, vol. 4, no. 3, hal. 201-210, 2020.

[4] D. Prasetyo, "Optimasi Operasi Dasar Struktur Data List dan Pointer Terhadap Efisiensi Memori," Jurnal Ilmu Komputer dan Algoritma, vol. 7, no. 1, hal. 55-63, 2023.