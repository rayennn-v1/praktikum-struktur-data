# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>

<p align="center">Mukhammad Ari Trianirto - 109082530027</p>

## Dasar Teori

Bahasa pemrograman C++ pada awalnya diciptakan oleh Bjarne Stroustrup pada awal tahun 1980-an yang dikembangkan berdasarkan C ANSI. Bahasa ini merupakan versi yang dipercanggih dari bahasa C dengan menambahkan fasilitas pemrograman berorientasi objek seperti class (kelas). Dalam penulisannya, program C++ tersusun dari beberapa komponen utama, seperti bagian include untuk mendeklarasikan library (contohnya <iostream>), pendefinisian konstanta dan struktur, serta fungsi utama int main() yang menjadi tempat eksekusi blok program. Untuk mengembangkan dan menjalankan program C++, dibutuhkan perangkat lunak yang dikenal sebagai IDE (Integrated Development Environment), salah satunya adalah Code Blocks. Code Blocks adalah kakas (tool) IDE free, open-source, dan cross-platform yang dapat membantu dalam menulis syntax, melakukan proses kompilasi (build), hingga menjalankan program (run).   
Dalam mempelajari dasar pemrograman C++, pemahaman mengenai variabel, tipe data, operasi input/output (I/O), dan percabangan (kondisional) menjadi fundamental yang penting. Tipe data dasar yang umum digunakan meliputi integer untuk bilangan bulat, float atau double untuk bilangan desimal, serta char untuk karakter. Untuk memfasilitasi interaksi pengguna dengan program, C++ menyediakan perintah cout untuk mencetak output atau keluaran ke layar, dan cin untuk menerima nilai inputan (input) dari keyboard. Pengendalian alur logika program juga dapat dilakukan menggunakan pernyataan kondisional seperti if, if-else, dan switch-case yang berfungsi untuk membuat keputusan berdasarkan pengujian suatu kondisi tertentu.
## Unguided

### 1. Buatlah program yang menerima input-an dua buah bilangan bertipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```C++
#include <iostream>
using namespace std;

int main(){
    float x, y;

    cin >> x >> y;

    cout << "hasil penjumlahan = " << x + y << endl;
    cout << "hasil pengurangan = " << x - y << endl;
    cout << "hasil perkalian = " << x * y << endl;
    cout << "hasil pembagian = " << x / y << endl;

    return 0;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_2](https://raw.githubusercontent.com/rayennn-v1/praktikum-struktur-data/main/week2/Screenshot-unguided-1.png)

Program ini memproses dua nilai masukan bertipe data float untuk dieksekusi menggunakan empat operasi dasar aritmatika, yakni penjumlahan, pengurangan, perkalian, dan pembagian. Seluruh hasil perhitungan tersebut selanjutnya dicetak ke layar melalui perintah cout.

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat positif mulai dari 0 s.d. 100.

Contoh:

```text
79 : tujuh puluh sembilan
```

```C++
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
        string satuan[] = {"", "Satu", "Dua", "Tiga", "Empat",
                           "Lima", "Enam", "Tujuh", "Delapan", "Sembilan"};
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
        string satuan[] = {"", "Satu", "Dua", "Tiga", "Empat",
                           "Lima", "Enam", "Tujuh", "Delapan", "Sembilan"};

        string puluhan[] = {"", "", "Dua Puluh", "Tiga Puluh", "Empat Puluh",
                            "Lima Puluh", "Enam Puluh", "Tujuh Puluh",
                            "Delapan Puluh", "Sembilan Puluh"};

        cout << puluhan[angka / 10];

        if (angka % 10 != 0)
            cout << " " << satuan[angka % 10];
    }

    return 0;
}

```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 1_2](https://raw.githubusercontent.com/rayennn-v1/praktikum-struktur-data/main/week2/Screenshot-unguided-2.png)

Program ini dirancang untuk membaca masukan bilangan cacah dalam rentang 0 hingga 100, lalu mengonversi angka tersebut menjadi format ejaan kata dalam bahasa Indonesia.

### 3. Buatlah program yang dapat memberikan input dan output seperti berikut.

Contoh input:

```text
3
```

Contoh output:

```text
3 2 1 * 1 2 3
  2 1 * 1 2
    1 * 1
      *
```

```C++
#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Input: ";
    cin >> n;

    cout << "Output:" << endl;

    for (int i = n; i >= 1; i--)
    {
        for (int j = n; j > i; j--)
            cout << "  ";

        for (int j = i; j >= 1; j--)
            cout << j << " ";

        cout << "*";

        for (int j = 1; j <= i; j++)
            cout << " " << j;

        cout << endl;
    }

    for (int i = 0; i < n; i++)
        cout << "  ";
    cout << "*";

    return 0;
}
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 1_2](https://raw.githubusercontent.com/rayennn-v1/praktikum-struktur-data/main/week2/Screenshot-unguided-3.png)

Program ini memproses masukan berupa satu buah bilangan untuk mencetak luaran berpola simetris. Pada masing-masing baris, deret angka akan dicetak menurun hingga batas angka 1, disisipkan karakter bintang (*) di bagian tengah, dan dilanjutkan dengan deret angka yang kembali menaik.

## Kesimpulan

Berdasarkan praktikum Modul 1, dapat disimpulkan bahwa Code::Blocks merupakan lingkungan pengembangan terpadu (IDE) yang sangat mendukung untuk proses penulisan, kompilasi (build), dan eksekusi program C++. Melalui praktikum ini, praktikan telah berhasil memahami dan mengimplementasikan konsep fundamental pemrograman C++, meliputi struktur dasar program, manipulasi tipe data dan variabel, operasi input-output menggunakan cin dan cout, serta penerapan operator aritmatika. Lebih lanjut, praktikum ini juga mengasah kemampuan logika algoritmik melalui penerapan pernyataan kondisional bersarang (if-else) untuk menyeleksi kondisi yang kompleks, serta pemanfaatan struktur perulangan (nested for-loop) untuk memanipulasi bentuk keluaran berupa pola bersusun. Secara keseluruhan, pengerjaan tugas unguided membuktikan bahwa teori-teori dasar tersebut dapat dikombinasikan dan diterapkan secara praktis untuk menyelesaikan berbagai permasalahan program sederhana dengan output yang presisi.

## Referensi

[1] Modul Praktikum Struktur Data 1. (n.d.). "Modul 1: Code Blocks IDE & Pengenalan Bahasa C++ (Bagian Pertama)."