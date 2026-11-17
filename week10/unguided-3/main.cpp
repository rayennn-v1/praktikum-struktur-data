#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Queue Q;
    createQueue(Q);
    
    cout << "---------------------------" << endl;
    cout << " H - T \t| Queue Info" << endl;
    cout << "---------------------------" << endl;
    
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    enqueue(Q, 4); printInfo(Q); // Tail ada di indeks 3
    
    dequeue(Q); printInfo(Q); // Head maju ke 1
    dequeue(Q); printInfo(Q); // Head maju ke 2
    
    // Antrean saat ini menyisakan 2 elemen, tetapi indeks 0 dan 1 sudah kosong.
    // Memasukkan 2 elemen baru untuk memaksa Tail berputar ke indeks 0
    enqueue(Q, 1); printInfo(Q); // Tail maju ke 4
    enqueue(Q, 9); printInfo(Q); // Tail berputar (4+1)%5 ke 0!
    
    return 0;
}