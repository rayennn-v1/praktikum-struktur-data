#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

// Pada Alternatif 3, antrean penuh jika indeks setelah tail adalah head
// Operasi modulo (%) digunakan agar indeks berputar (4 + 1) % 5 = 0
bool isFullQueue(Queue Q) {
    return ((Q.tail + 1) % MAKSIMAL == Q.head); 
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            // Tail bergerak maju dengan konsep melingkar
            Q.tail = (Q.tail + 1) % MAKSIMAL;
        }
        Q.info[Q.tail] = x;
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
            // Head bergerak maju dengan konsep melingkar
            Q.head = (Q.head + 1) % MAKSIMAL;
        }
    }
    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " \t| ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        // Loop khusus untuk mencetak elemen yang melingkar
        int i = Q.head;
        while (true) {
            cout << Q.info[i] << " ";
            if (i == Q.tail) {
                break;
            }
            i = (i + 1) % MAKSIMAL;
        }
        cout << endl;
    }
}