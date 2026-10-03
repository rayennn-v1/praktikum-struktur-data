#include <iostream>
using namespace std;

int cariMaksimum(int arr[], int ukuran) {
    int maks = arr[0];
    for (int i = 1; i < ukuran; i++) {
        if (arr[i] > maks) {
            maks = arr[i];
        }
    }
    return maks;
}

int cariMinimum(int arr[], int ukuran) {
    int min = arr[0];
    for (int i = 1; i < ukuran; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

void hitungRataRata(int arr[], int ukuran) {
    float total = 0;
    for (int i = 0; i < ukuran; i++) {
        total += arr[i];
    }
    float rataRata = total / ukuran;
    cout << "Nilai rata - rata array adalah : " << rataRata << endl;
}

int main() {
    int arrA[] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int ukuran = sizeof(arrA) / sizeof(arrA[0]);
    int pilihan;

    do {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata - rata" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu (0-4): ";
        cin >> pilihan;
        
        cout << endl;

        switch (pilihan) {
            case 1:
                cout << "Isi array arrA: { ";
                for (int i = 0; i < ukuran; i++) {
                    cout << arrA[i];
                    if (i < ukuran - 1) cout << ", ";
                }
                cout << " }" << endl;
                break;
                
            case 2:
                cout << "Nilai maksimum dalam array adalah : " << cariMaksimum(arrA, ukuran) << endl;
                break;
                
            case 3:
                cout << "Nilai minimum dalam array adalah : " << cariMinimum(arrA, ukuran) << endl;
                break;
                
            case 4:
                hitungRataRata(arrA, ukuran);
                break;
                
            case 0:
                cout << "Program selesai. Terima kasih" << endl;
                break;
                
            default:
                cout << "Pilihan tidak valid! Silakan masukkan angka 0 - 4" << endl;
                break;
        }
    } while (pilihan != 0);

    return 0;
}