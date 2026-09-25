#include <iostream>
using namespace std;

// int main() {
//     cout << "Hello, World!" << endl;
//     return 0;
// }

// int main() {
//     int inp;
//     cin >> inp;
//     cout << "nilai = " << inp;
//     return 0;
// }

// int main() {
//     int w, x, y; float z;
//     x = 7; y = 3; w = 1;
//     z = (float) (x + y) / (y + w);
//     cout << "nilai z = " << z << endl;
//     return 0;
// }

//latihan
int main() {
    int a, b;
    cout << "Masukkan nilai a: ";
    cin >> a;
    cout << "Masukkan nilai b: ";
    cin >> b;

    int jumlah = a + b;
    int kurang = a - b;
    int kali = a * b;
    int bagi = a / b;
    cout << "Jumlah = " << jumlah << endl;
    cout << "Kurang = " << kurang << endl;
    cout << "Kali = " << kali << endl;
    cout << "Bagi = " << bagi << endl;
    return 0;
}