#include <iostream>
#include "rekursif.h"

using namespace std;

int main() {
    int x;

    cout << "Menghitung pangkat 2 secara rekursif" << endl;
    cout << "Masukkan nilai x: ";
    cin >> x;

    if (x < 0) {
        cout << "Nilai x harus lebih besar atau sama dengan 0." << endl;
    } else {
        cout << "2^" << x << " = " << pangkat_2(x) << endl;
    }

    return 0;
}