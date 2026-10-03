#include <iostream>
using namespace std;

void tukarPointer(int *x, int *y, int *z) {
    int temp = *x; 
    *x = *y;       
    *y = *z;       
    *z = temp;    
}

void tukarReference(int &x, int &y, int &z) {
    int temp = x;  
    x = y;         
    y = z;         
    z = temp;      
}

int main() {
    int a = 10, b = 20, c = 30;

    cout << "Nilai Awal" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << "\n\n";

    tukarPointer(&a, &b, &c);
    cout << "Setelah ditukar dengan Pointer" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
    cout << "(Logika: a mengambil b, b mengambil c, c mengambil a awal)\n\n";

    tukarReference(a, b, c);
    cout << "Setelah ditukar lagi dengan Reference" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
    cout << "(Logika berlanjut dari hasil sebelumnya)\n";

    return 0;
}