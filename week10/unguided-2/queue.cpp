#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

// Pada Alternatif 2, antrean dikatakan benar-benar penuh 
// HANYA JIKA tail sudah mencapai indeks akhir DAN head berada di indeks awal (0)
bool isFullQueue(Queue Q) {
    return (Q.tail == 4 && Q.head == 0); 
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
            Q.info[Q.tail] = x;
        } else {
            // Cek kondisi antrean penuh "semu" (tail di akhir, tapi head > 0)
            if (Q.tail == 4 && Q.head > 0) {
                // Geser seluruh elemen ke depan untuk menciptakan ruang kosong
                int geser = Q.head;
                for (int i = Q.head; i <= Q.tail; i++) {
                    Q.info[i - geser] = Q.info[i];
                }
                Q.tail = Q.tail - geser;
                Q.head = 0; // Kembalikan head ke 0 setelah digeser
            }
            Q.tail++;
            Q.info[Q.tail] = x;
        }
    }
}

infotype dequeue(Queue &Q) {
    infotype x = -1; 
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
    } else {
        x = Q.info[Q.head];
        if (Q.head == Q.tail) {
            // Jika hanya tersisa 1 elemen, kembalikan ke kondisi kosong
            createQueue(Q);
        } else {
            // Pada Alternatif 2, elemen TIDAK digeser saat dequeue,
            // melainkan indeks head yang bergerak maju.
            Q.head++;
        }
    }
    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " \t| ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}