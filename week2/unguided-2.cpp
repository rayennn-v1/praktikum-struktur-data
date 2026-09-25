#include <iostream>
using namespace std;

int main() {
    int angka;

    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    if (angka == 0)
        cout << "Nol";
    else if (angka == 100)
        cout << "Seratus";
    else if (angka < 10) {
        string satuan[] = {"", "Satu", "Dua", "Tiga", "Empat","Lima", "Enam", "Tujuh", "Delapan", "Sembilan"};
        cout << satuan[angka];
    }
    else if (angka < 20) {
        string belasan[] = {"", "", "Dua Belas", "Tiga Belas", "Empat Belas",
                            "Lima Belas", "Enam Belas", "Tujuh Belas",
                            "Delapan Belas", "Sembilan Belas"};
        if (angka == 10)
            cout << "Sepuluh";
        else if (angka == 11)
            cout << "Sebelas";
        else
            cout << belasan[angka];
    }
    else if (angka < 100) {
        string satuan[] = {"", "Satu", "Dua", "Tiga", "Empat","Lima", "Enam", "Tujuh", "Delapan", "Sembilan"};

        string puluhan[] = {"", "", "Dua Puluh", "Tiga Puluh", "Empat Puluh",
                            "Lima Puluh", "Enam Puluh", "Tujuh Puluh",
                            "Delapan Puluh", "Sembilan Puluh"};

        cout << puluhan[angka / 10];

        if (angka % 10 != 0)
            cout << " " << satuan[angka % 10];
    }

    return 0;
}