#include <iostream>
using namespace std;

int main() {
    int A[3][3], B[3][3];

    // Input Matriks A
    cout << "Masukkan 9 angka untuk Matriks A:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cin >> A[i][j];
    }

    // Input Matriks B
    cout << "Masukkan 9 angka untuk Matriks B:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cin >> B[i][j];
    }

    // Hitung dan cetak Penjumlahan
    cout << "\n Hasil Penjumlahan (A + B) \n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cout << A[i][j] + B[i][j] << " ";
        cout << endl;
    }

    // Hitung dan cetak Pengurangan
    cout << "\n Hasil Pengurangan (A - B) \n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cout << A[i][j] - B[i][j] << " ";
        cout << endl;
    }

    // Hitung dan cetak Perkalian
    cout << "\n Hasil Perkalian (A * B) \n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int hasilKali = 0;
            for (int k = 0; k < 3; k++) {
                hasilKali += A[i][k] * B[k][j];
            }
            cout << hasilKali << " ";
        }
        cout << endl;
    }

    return 0;
}