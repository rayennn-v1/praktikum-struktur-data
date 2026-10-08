# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>
<p align="center">Mukhammad Ari Trianirto - 109082530027</p>

## Dasar Teori
Array merupakan struktur data linear yang digunakan untuk menyimpan sekumpulan elemen dengan tipe data sejenis pada lokasi memori yang saling berurutan, di mana setiap elemennya dapat diakses secara langsung melalui indeks referensi yang selalu dimulai dari nol [1]. Dalam implementasinya, array dapat dibentuk sebagai struktur satu dimensi maupun multidimensi untuk mengelola data kompleks seperti matriks atau tabel [2]. Karena struktur array sangat bergantung pada manajemen memori, bahasa C++ memfasilitasi penggunaan pointer, yaitu variabel khusus yang menyimpan alamat memori fisik dari variabel atau struktur data lain di dalam RAM [2]. Pointer memberikan keleluasaan dalam alokasi memori dinamis dan memiliki keterkaitan erat dengan array; secara fundamental, nama dari sebuah array bertindak sebagai pointer konstan yang menunjuk pada alamat dari elemen pertama array tersebut [3].

Selain efisiensi memori, C++ mendukung pengembangan perangkat lunak terstruktur melalui pemrograman modular menggunakan fungsi dan prosedur [1]. Fungsi adalah sub-program independen yang bertugas mengeksekusi instruksi komputasi spesifik dan mengembalikan sebuah nilai (return value) kepada program pemanggilnya, sementara prosedur merupakan fungsi bertipe void yang hanya menjalankan serangkaian aksi tanpa mengembalikan nilai [3]. Komunikasi data antara program utama dan sub-program tersebut dikelola melalui pengiriman parameter [2]. Terdapat tiga mekanisme utama dalam pengiriman parameter: call by value yang menduplikasi nilai aktual sehingga variabel asli tidak terpengaruh, call by pointer yang mengirimkan alamat memori melalui variabel pointer, serta call by reference yang memberikan alias atau referensi langsung ke memori variabel asli [1][3]. Penggunaan referensi dan pointer sangat diandalkan dalam optimasi memori karena fungsi dapat memodifikasi nilai variabel asli secara langsung tanpa perlu menyalin keseluruhan data [2].

## Guided 

### 1. Array Satu Dimensi

```C++
#include <iostream>
using namespace std;

int main() {
    int nilai[5];

    nilai[0] = 80;
    nilai[1] = 85;
    nilai[2] = 90;
    nilai[3] = 75;
    nilai[4] = 95;

    for (int i = 0; i < 5; i++) {
        cout << "index ke-" << i << " = " << nilai[i] << endl;
    }
    
    return 0;
}
```

Kode pada Guided 1 merupakan contoh implementasi array satu dimensi dalam bahasa C++. Program ini mendeklarasikan sebuah array bertipe integer bernama nilai yang memiliki kapasitas 5 elemen. Setiap elemen array tersebut kemudian diisi data secara manual berdasarkan indeksnya, mulai dari indeks 0 hingga 4 (contoh: nilai[0] = 80). Setelah data dimasukkan, program menggunakan perulangan for untuk menelusuri setiap indeks dan mencetak nilainya secara berurutan ke layar.

### 2. Array Dua Dimensi

```C++
#include <iostream>
using namespace std;

int main() {
    int nilai[3][3] = {
        {80, 85, 90},
        {75, 80, 85},
        {90, 95, 100}
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << nilai[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```

Kode pada Guided 2 merupakan contoh implementasi array dua dimensi (matriks) dalam bahasa C++. Program ini mendeklarasikan dan langsung menginisialisasi array bertipe integer bernama nilai dengan ukuran 3x3 (terdiri dari 3 baris dan 3 kolom). Untuk menelusuri dan mencetak data tersebut, program menggunakan perulangan bersarang (nested loop). Perulangan luar (i) bertugas menelusuri setiap baris, sementara perulangan dalam (j) bertugas menelusuri setiap kolom pada baris tersebut. Hasilnya, elemen-elemen array dicetak ke layar dengan format matriks 3x3.

### 3. Array Tiga Dimensi

```C++
#include <iostream>
using namespace std;

int main() {
    int data[2][3][3] = {
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        },
        {
            {10, 11, 12},
            {13, 14, 15},
            {16, 17, 18}
        }
    };

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                cout << data[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
```

Kode pada Guided 3 merupakan contoh implementasi array tiga dimensi dalam bahasa C++. Program ini mendeklarasikan dan menginisialisasi array bertipe integer bernama data dengan ukuran 2x3x3, yang berarti terdapat 2 blok/layer, di mana masing-masing blok berisi matriks berukuran 3 baris dan 3 kolom. Untuk mengakses dan mencetak seluruh datanya, program membutuhkan tiga tingkat perulangan bersarang (nested loop). Perulangan paling luar (i) digunakan untuk menelusuri blok, perulangan tengah (j) untuk menelusuri baris, dan perulangan paling dalam (k) untuk menelusuri kolom. Hasil akhirnya, elemen-elemen tersebut dicetak ke layar menjadi dua kelompok matriks 3x3.

### 4. Array Empat Dimensi

```C++
#include <iostream>
using namespace std;

int main() {
    int data[2][2][2][2] = {
        {
            {
                {1, 2},
                {3, 4}
            },
            {
                {5, 6},
                {7, 8}
            }
        },
        {
            {
                {9, 10},
                {11, 12}
            },
            {
                {13, 14},
                {15, 16}
            }
        }
    };

    cout << data[0][0][0][0] << endl; // 1
    cout << data[1][1][1][1] << endl; // 16

    return 0;
}
```

Kode pada Guided 4 merupakan contoh implementasi array empat dimensi dalam bahasa C++. Program ini mendeklarasikan dan secara langsung menginisialisasi array bertipe integer bernama data dengan ukuran 2x2x2x2. Berbeda dengan contoh-contoh sebelumnya yang menggunakan perulangan (looping) untuk menampilkan seluruh data, program ini menunjukkan cara mengakses dan mencetak elemen array secara spesifik menggunakan indeksnya. Kode tersebut mencetak elemen pertama yang berada di indeks [0][0][0][0] dengan nilai 1, serta elemen terakhir di indeks [1][1][1][1] dengan nilai 16.

### 5. Pointer

```C++
#include <iostream>
using namespace std;

int main() {
    char a;
    int j;
    char arr[6];

    arr[3] = 'b';
    a = 'u';
    j = 10;

    cout << a << endl; //u
    cout << &a << endl; //alamat memory atau address

    cout << j << endl; //10
    cout << &j << endl; //alamat memory atau address

    cout << arr[3] << endl; //value
    cout << &(arr[4]) << endl; //alamat memory atau address

    return 0;
}
```

Kode pada Guided 5 merupakan contoh cara mengetahui alamat memori fisik dari suatu variabel dalam bahasa C++ dengan menggunakan operator address-of (&). Program mendeklarasikan beberapa variabel, yaitu variabel tipe karakter (char a), bilangan bulat (int j), dan sebuah array (char arr[6]). Selain mencetak nilai atau isi dari variabel tersebut (seperti u, 10, dan b), program juga mencetak alamat lokasi memori di mana variabel dan elemen array tersebut disimpan di dalam RAM dengan menambahkan simbol & di depan nama variabel (contohnya &a dan &j).

### 6. Pointer dan Alamat

```C++
#include <iostream>
using namespace std;

int main() {
    int x, y;
    int *px;

    x = 87;
    px = &x; 
    y = *px; 

    cout << "Alamat x= " << &x << endl;
    cout << "Isi px= " << px << endl;
    cout << "Isi x= " << x << endl;
    cout << "Niali yang ditunjuk px= " << *px << endl;
    cout << "Nilai y= " << y << endl;

    return 0;
}
```

Program mendeklarasikan variabel x dengan nilai 87 dan sebuah variabel pointer px. Pointer px kemudian diisi dengan alamat memori dari variabel x menggunakan sintaks px = &x. Selanjutnya, variabel y diisi dengan nilai yang berada di alamat memori yang ditunjuk oleh pointer px menggunakan sintaks y = *px. Hasil cetak program ini akan membuktikan bahwa &x dan px menampilkan alamat memori fisik yang sama persis, sementara variabel x, *px, dan y semuanya akan menampilkan nilai yang sama, yaitu 87.

### 7. Pointer dan Array

```C++
#include <iostream>
#define MAX 5
using namespace std;

int main() {
    int i, j;
    float nilai_total, rata_rata;
    float nilai[MAX];

    static int nilai_tahun[MAX][MAX] = {
        {0, 2, 2, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 3, 3, 3, 0},
        {4, 4, 0, 0, 4},
        {5, 0, 0, 0, 5}
    };

    // inisilisasi array satu dimensi
    for (i = 0; i < MAX; i++) {
        cout << "Masukkan nilai ke-" << i + 1 << endl;
        cin >> nilai[i];
    }

    cout << "\ndata nilai siswa :\n";

    // menampilkan array satu dimensi
    for (i = 0; i < MAX; i++)
        cout << "nilai k-" << i + 1 << " = " << nilai[i] << endl;

    cout << "\nnilai tahunan :\n";

    // menampilkan array dua dimensi
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++)
            cout << nilai_tahun[i][j];

        cout << "\n";
    }

    return 0;
}
```

Kode pada Guided 7 menunjukkan cara mengelola input dan output array menggunakan bantuan konstanta makro (#define MAX 5) untuk mendefinisikan ukurannya. Program ini pertama-tama menggunakan perulangan untuk meminta pengguna memasukkan 5 buah data ke dalam array satu dimensi nilai, lalu menampilkan kembali data yang telah diinputkan. Selanjutnya, program menggunakan perulangan bersarang untuk menelusuri dan mencetak elemen-elemen dari array dua dimensi nilai_tahun yang sudah diinisialisasi secara statis di dalam kode.

### 8. Pointer dan Array

```C++
#include <iostream>
using namespace std;

int main() {
    char nama[] = "strukdat";

    cout << nama << endl;
    cout << nama[3] << endl;

    return 0;
}
```

Kode pada Guided 8 menunjukkan cara mendeklarasikan dan menginisialisasi array karakter (C-string) secara langsung dengan teks "strukdat". Program ini mendemonstrasikan dua operasi keluaran: pertama, mencetak seluruh isi array (string) secara utuh dengan memanggil nama variabelnya (nama), dan kedua, mengakses serta mencetak satu karakter spesifik dari string tersebut menggunakan indeks, yaitu elemen pada indeks ke-3 (nama[3]) yang menghasilkan karakter huruf 'u'.

### 9. Function

```C++
#include <iostream>
using namespace std;
int maks3(int a, int b, int c);
int main() {
    int x,y,z;
    cout << "masukkan nilai bilangan ke-1 = ";
    cin >> x;
    cout << "masukkan nilai bilangan ke-2 = ";
    cin >> y;
    cout << "masukkan nilai bilangan ke-3 = ";
    cin >> z;
    cout << "nilai maksimumnya adalah = " << maks3(x,y,z);
    return 0;
}
int maks3(int a, int b, int c) {
    int temp_max = a;
    if (b > temp_max)
    temp_max = b;
    if (c > temp_max)
    temp_max = c;
    return (temp_max);
}



```

Kode pada Guided 9 merupakan contoh implementasi pembuatan dan pemanggilan fungsi dalam bahasa C++. Program ini mendefinisikan sebuah fungsi bernama maks3 yang bertugas mencari nilai terbesar dari tiga buah bilangan bulat yang diterimanya melalui parameter a, b, dan c. Pada blok program utama (main), pengguna diminta untuk menginputkan tiga buah angka, yang kemudian dikirimkan sebagai argumen saat memanggil fungsi maks3(x, y, z). Fungsi tersebut membandingkan ketiga angka menggunakan struktur kendali if dan mengembalikan (return) nilai tertinggi ke fungsi utama untuk langsung dicetak ke layar.

### 10. Prosedur

```C++
#include <iostream>
using namespace std;

void tulis(int x);
int main() {
    int jum;
    cout << "jumlah baris kata = ";
    cin >> jum;
    tulis(jum);
    return 0;

}
void tulis(int x) {
    for (int i=0; i < x; i++)
        cout << "baris ke-" << i+1 << endl;
}
```

Kode pada Guided 10 merupakan contoh implementasi prosedur dalam bahasa C++, yaitu sebuah fungsi yang tidak mengembalikan nilai apapun (ditandai dengan kata kunci void). Program ini mendefinisikan sebuah prosedur bernama tulis yang menerima satu parameter bilangan bulat x. Pada program utama (main), pengguna diminta untuk memasukkan angka yang disimpan dalam variabel jum. Angka tersebut kemudian dilempar sebagai argumen saat memanggil prosedur tulis(jum). Prosedur tulis kemudian merespons dengan menjalankan perulangan for untuk mencetak teks "baris ke-[angka]" secara berulang ke layar sebanyak jumlah yang diinputkan tadi.

### 11. Parameter Fungsi

```C++
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
```

Kode pada Guided 11 mendemonstrasikan tiga metode pengiriman parameter (argumen) dari program utama ke dalam sebuah fungsi pada bahasa C++.

1. Call by Value (tukarvalue): Fungsi hanya menerima salinan nilai dari variabel. Perubahan yang terjadi di dalam fungsi tidak akan memengaruhi variabel asli di program utama.

2. Call by Pointer (tukarPointer): Fungsi menerima alamat memori menggunakan pointer (*). Karena mengakses memori secara langsung, perubahan di dalam fungsi akan mengubah variabel aslinya.

3. Call by Reference (tukarReference): Fungsi menggunakan alias atau referensi alamat memori (&). Sama seperti pointer, metode ini juga akan memodifikasi nilai variabel aslinya secara langsung.

Program utama (main) membuktikan hal ini dengan mencoba menukar nilai variabel a dan b menggunakan ketiga fungsi tersebut secara bergantian dan mencetak hasilnya untuk melihat metode mana yang benar-benar berhasil mengubah nilai aslinya.

## Unguided 

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3 

```C++
#include <iostream>
using namespace std;

int main() {
    int A[3][3], B[3][3];

    cout << "Masukkan 9 angka untuk Matriks A:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cin >> A[i][j];
    }

    cout << "Masukkan 9 angka untuk Matriks B:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cin >> B[i][j];
    }

    cout << "\n Hasil Penjumlahan (A + B) \n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cout << A[i][j] + B[i][j] << " ";
        cout << endl;
    }

    cout << "\n Hasil Pengurangan (A - B) \n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cout << A[i][j] - B[i][j] << " ";
        cout << endl;
    }

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
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://raw.githubusercontent.com/rayennn-v1/praktikum-struktur-data/main/week3/Screenshot-unguided-1.png)

Program pada Unguided 1 merupakan implementasi penggunaan array dua dimensi untuk melakukan operasi matematika dasar pada matriks berukuran 3x3, yang meliputi operasi penjumlahan, pengurangan, dan perkalian.

Berikut adalah rincian alur kerja program tersebut:

Deklarasi dan Input: Program mendeklarasikan dua buah array dua dimensi bertipe integer, yaitu A[3][3] dan B[3][3]. Dengan menggunakan perulangan bersarang (nested loop), program meminta pengguna untuk memasukkan 9 angka sebagai elemen untuk Matriks A dan 9 angka untuk Matriks B.

Operasi Penjumlahan & Pengurangan: Untuk melakukan penjumlahan dan pengurangan, program menggunakan nested loop untuk mengakses setiap baris dan kolom. Program akan mengoperasikan elemen-elemen yang memiliki posisi indeks yang sama persis antara matriks A dan matriks B (yaitu A[i][j] + B[i][j] untuk penjumlahan dan A[i][j] - B[i][j] untuk pengurangan), lalu langsung mencetak hasilnya.

Operasi Perkalian: Berbeda dengan operasi sebelumnya, perkalian matriks menggunakan tiga tingkat perulangan bersarang (variabel i, j, dan k). Program menggunakan variabel lokal hasilKali yang diinisialisasi dengan nilai 0. Nilai dari matriks hasil perkalian didapatkan dengan mengalikan elemen baris dari Matriks A dengan elemen kolom dari Matriks B secara berurutan, lalu menjumlahkannya (hasilKali += A[i][k] * B[k][j]).

Output: Setiap hasil operasi perhitungan akan langsung dicetak ke layar dengan format menyerupai bentuk matriks asli dengan bantuan spasi antar elemen dan newline (endl) untuk memisahkan setiap baris.


### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel 

```C++
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
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://raw.githubusercontent.com/rayennn-v1/praktikum-struktur-data/main/week3/Screenshot-unguided-2.png)

Program pada Unguided 2 mendemonstrasikan cara menukar (rotasi) nilai dari tiga buah variabel sekaligus menggunakan dua metode pengiriman parameter yang memodifikasi nilai asli di memori, yaitu Call by Pointer dan Call by Reference.

Berikut adalah rincian alur kerja program tersebut:

1. Fungsi tukarPointer (Call by Pointer): Fungsi ini menerima tiga parameter berupa pointer (*x, *y, *z), yang berarti fungsi ini menerima alamat memori dari variabel aslinya. Proses penukaran dilakukan menggunakan variabel bantuan temp. Nilai yang ditunjuk oleh x (dereference) diamankan ke temp, kemudian x mengambil nilai dari y, y mengambil nilai dari z, dan z mengambil nilai dari temp. Karena memodifikasi data di alamat memori secara langsung, variabel asli di fungsi utama (main) akan ikut berubah secara permanen.

2. Fungsi tukarReference (Call by Reference): Fungsi ini menggunakan referensi (&x, &y, &z) yang bertindak sebagai alias dari variabel asli yang dikirimkan. Logika penukarannya berputar sama persis dengan fungsi pointer, namun sintaksnya jauh lebih sederhana karena tidak perlu menuliskan operator dereference (*) di setiap baris. Mengubah nilai di dalam fungsi ini juga akan langsung mengubah nilai variabel aslinya.

3. Program Utama (main): Program mendeklarasikan tiga variabel awal yaitu a = 10, b = 20, dan c = 30.

- Saat memanggil tukarPointer(&a, &b, &c), program wajib menyematkan operator & untuk mengirimkan alamat memori dari a, b, dan c. Hasilnya nilai bergeser (a mengambil b, b mengambil c, c mengambil a) menjadi a = 20, b = 30, dan c = 10.

- Saat memanggil tukarReference(a, b, c), variabel cukup ditulis namanya saja seperti mengirim nilai biasa. Fungsi ini akan melanjutkan rotasi nilai dari status terakhir (hasil fungsi pointer sebelumnya), sehingga nilai bergeser sekali lagi. Output akhir membuktikan bahwa kedua fungsi berhasil mengubah variabel asli.

### 3. Diketahui sebuah array 1 dimensi sebagai berikut :  arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55} Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur hitungRataRata() untuk menghitung nilai rata – rata! Buat program menggunakan menu switch-case seperti berikut ini : 
--- Menu Program Array --- 
1. Tampilkan isi array 
2. cari nilai maksimum 
3. cari nilai minimum 
4. Hitung nilai rata - rata 

```C++
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
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://raw.githubusercontent.com/rayennn-v1/praktikum-struktur-data/main/week3/Screenshot-unguided-3.1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://raw.githubusercontent.com/rayennn-v1/praktikum-struktur-data/main/week3/Screenshot-unguided-3.2.png)

Program pada Unguided 3 merupakan implementasi program interaktif berbasis menu menggunakan struktur switch-case untuk menganalisis data pada sebuah array satu dimensi. Program ini menerapkan konsep pemrograman modular dengan memisahkan logika perhitungan ke dalam fungsi (mengembalikan nilai) dan prosedur (tidak mengembalikan nilai).

Berikut adalah rincian alur kerja program tersebut:

1. Inisialisasi Data: Pada fungsi utama (main), program mendeklarasikan array satu dimensi arrA beserta isinya secara statis. Program juga secara dinamis menghitung jumlah elemen array menggunakan rumus sizeof(arrA) / sizeof(arrA[0]) yang disimpan dalam variabel ukuran. Hal ini memastikan kode tetap valid meskipun elemen array ditambah atau dikurangi.

2. Fungsi Pencarian (cariMaksimum & cariMinimum): Keduanya merupakan fungsi bertipe int yang menerima pengiriman parameter berupa array beserta ukurannya.

- cariMaksimum: Menginisialisasi variabel maks dengan elemen pertama array, lalu melakukan perulangan untuk mengecek satu per satu. Jika ada nilai yang lebih besar dari maks, maka nilai maks akan diperbarui. Hasil akhirnya akan di-return.

- cariMinimum: Logikanya sama dengan pencarian maksimum, namun ia membandingkan elemen untuk mencari nilai yang lebih kecil dan menyimpannya di variabel min.

3. Prosedur hitungRataRata: Merupakan sub-program bertipe void yang bertugas menghitung rata-rata elemen array. Prosedur ini menjumlahkan semua isi array ke dalam variabel total, membaginya dengan jumlah ukuran elemen, dan langsung mencetak hasilnya ke layar tanpa melakukan return nilai ke program utama.

4. Menu Interaktif (Perulangan & Percabangan): Program menggunakan struktur perulangan do-while agar menu utama terus ditampilkan hingga pengguna memilih opsi untuk keluar.

- Input pilihan pengguna diproses menggunakan switch-case.

- Case 1 mencetak isi array.

- Case 2 dan 3 memanggil fungsi pencarian (maks/min) dan mencetak nilai yang dikembalikan.

- Case 4 memanggil prosedur rata-rata.

- Case 0 akan menghentikan perulangan do-while dan menyelesaikan program dengan pesan perpisahan. Jika input tidak sesuai (selain 0-4), default akan memberikan peringatan kepada pengguna.

## Kesimpulan
Praktikum Modul 2 ini memberikan pemahaman dan keterampilan komprehensif dalam mengimplementasikan konsep lanjutan C++, khususnya terkait manajemen data dan struktur program. Mahasiswa telah berhasil mempraktikkan penggunaan struktur data array, mulai dari satu dimensi hingga multidimensi, untuk menyimpan dan memanipulasi sekumpulan data secara efisien, seperti pada operasi matriks. Selain itu, pemahaman tentang manajemen memori juga diperdalam melalui penggunaan pointer untuk mengakses alamat data secara langsung. Konsep pemrograman modular juga berhasil diterapkan melalui pembuatan fungsi dan prosedur, lengkap dengan penerapan berbagai metode pengiriman parameter—yaitu call by value, call by pointer, dan call by reference—yang terbukti sangat berguna dalam memodifikasi nilai variabel secara dinamis dan menjaga kode tetap terstruktur, rapi, serta mudah dikembangkan.

## Referensi
[1] A. S. R. Sinaga dan T. H. Nasution, "Analisis Perbandingan Kinerja Struktur Data Array dan Linked List dalam Pemrograman C++," Jurnal Teknik Informatika dan Sistem Informasi, vol. 6, no. 2, hal. 231-240, 2020.
<br>[2] R. Setiawan dan M. I. Herdiansyah, "Implementasi Manajemen Memori Dinamis Menggunakan Pointer pada Bahasa Pemrograman C++," Jurnal Ilmiah Komputasi, vol. 19, no. 3, hal. 305-312, 2020.
<br>[3] D. Kurniawan dan A. Fitriani, "Penerapan Konsep Pemrograman Modular dengan Fungsi dan Prosedur dalam Optimasi Kode Perangkat Lunak," Jurnal Nasional Komputasi dan Teknologi Informasi (JNKTI), vol. 5, no. 1, hal. 45-52, 2022.
