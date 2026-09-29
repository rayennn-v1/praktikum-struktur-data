#include <iostream>
using namespace std;

//1. Call by value: variable asli TIDAK berubah
void tukarvalue(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

//2. Call by reference: variable asli IKUT berubah (pakai*)
void tukarPointer(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

//3. Call by reference: variable asli IKUT berubah (pakai &)
void tukarReference(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a =4, b = 6;

    // Tes Call by Value
    cout << "Setelah Call by Value   -> a = " << a << ", b = " << b << " (Tetap)" << endl;

    // Tes Call by Pointer(kirim alamatnya pakai &)
    tukarPointer(&a, &b);
    cout << "Setelah Call by Pointer -> a = " << a << ", b = " << b << " (Berubah!)" << endl;

    // Tes Call by Reference(mengembalikan posisi semula)
    tukarReference(a, b);
    cout << "Setelah Call by Reference -> a = " << a << ", b = " << b << " (Berubah lagi!)" << endl;

    return 0;
}