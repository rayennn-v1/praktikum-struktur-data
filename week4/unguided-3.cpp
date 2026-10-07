#include <iostream>

using namespace std;

void tampilArray(int arr[3][3], string namaArray) {
    cout << "Isi " << namaArray << ":" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void tukarIsiArray(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    if (baris >= 0 && baris < 3 && kolom >= 0 && kolom < 3) {
        int temp = arr1[baris][kolom];
        arr1[baris][kolom] = arr2[baris][kolom];
        arr2[baris][kolom] = temp;
        cout << "Berhasil menukar elemen pada posisi [" << baris << "][" << kolom << "]" << endl;
    } else {
        cout << "Posisi di luar batas array!" << endl;
    }
}

void tukarNilaiPointer(int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    int array1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int array2[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int var1 = 100;
    int var2 = 200;
    int* ptrA = &var1;
    int* ptrB = &var2;

    cout << "--- KONDISI AWAL ---" << endl;
    tampilArray(array1, "Array 1");
    tampilArray(array2, "Array 2");
    
    cout << "Nilai var1 (ditunjuk ptrA) : " << *ptrA << endl;
    cout << "Nilai var2 (ditunjuk ptrB) : " << *ptrB << endl;
    cout << "------------------------------------------------\n" << endl;

    cout << "--- PROSES PENUKARAN ARRAY ---" << endl;
    tukarIsiArray(array1, array2, 1, 1); 
    cout << endl;
    
    tampilArray(array1, "Array 1 (Setelah ditukar)");
    tampilArray(array2, "Array 2 (Setelah ditukar)");

    cout << "--- PROSES PENUKARAN POINTER ---" << endl;
    tukarNilaiPointer(ptrA, ptrB);
    
    cout << "Nilai var1 (ditunjuk ptrA) setelah ditukar : " << *ptrA << endl;
    cout << "Nilai var2 (ditunjuk ptrB) setelah ditukar : " << *ptrB << endl;

    return 0;
}