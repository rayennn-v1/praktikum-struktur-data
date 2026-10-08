# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT) </h1>
<p align="center">Mukhammad Ari Trianirto - 109082530027</p>

## Dasar Teori
Abstract Data Type (ADT) atau Tipe Data Abstrak adalah suatu model matematika dari struktur data yang mendefinisikan sebuah tipe data beserta sekumpulan operasi dasar (primitif) yang dapat dilakukan terhadap tipe tersebut, tanpa memaparkan detail implementasi internalnya secara langsung [1]. Konsep utama dari pembentukan ADT adalah abstraksi dan penyembunyian informasi (information hiding), di mana pengguna struktur data hanya berinteraksi dengan antarmuka (interface) yang disediakan melalui fungsi dan prosedur, sehingga kompleksitas manipulasi memori dan pengelolaan data internal tetap tersembunyi [2]. Dalam sebuah definisi ADT yang lengkap, sering kali disertakan pula batasan atau invarian dari tipe data tersebut beserta aksioma yang menjaga konsistensi setiap operasi yang dilakukan [1].

Primitif atau operasi dasar pada ADT umumnya diklasifikasikan ke dalam beberapa kelompok fungsional, yaitu konstruktor atau kreator untuk membentuk nilai awal objek, selektor untuk mengakses komponen spesifik, mutator untuk mengubah nilai komponen, serta destruktor untuk membersihkan alokasi memori [3]. Dalam implementasinya menggunakan bahasa pemrograman C++, ADT sangat erat kaitannya dengan paradigma pemrograman modular, di mana deklarasi dan implementasi kode dipisahkan ke dalam file yang berbeda [2][3].

Spesifikasi ADT, yang mencakup definisi bentuk tipe data (misalnya menggunakan struktur struct) beserta deklarasi prototipe fungsi dan prosedurnya, ditempatkan di dalam file header berekstensi .h [1]. Sementara itu, realisasi logis atau bentuk fisik dari operasi-operasi dasar primitif tersebut diimplementasikan secara utuh di dalam file body berekstensi .cpp [3]. Pendekatan modular ini tidak hanya memudahkan proses pemeliharaan kode (maintenance), tetapi juga meningkatkan reusability, di mana sebuah modul ADT dapat dengan mudah dipanggil dan digunakan kembali oleh berbagai program utama (driver) tanpa perlu menulis ulang deklarasi struktur datanya dari awal [2][3].

## Guided 

### 1. Abstract Data Type (ADT)

#### mahasiswa.h

```C++
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED
struct mahasiswa{
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs (mahasiswa &m);
float rata2 (mahasiswa m);
#endif // MAHASISWA_H_INCLUDED 
```

#### mahasiswa.cpp

```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs (mahasiswa &m){
    cout << "input nim: ";
    cin >> (m).nim;
    cout << "input nilai 1: ";
    cin >> (m).nilai1;
    cout << "input nilai 2: ";
    cin >> (m).nilai2;
}

float rata2 (mahasiswa m){
    return float (m.nilai1 + m.nilai2) / 2;
} 
```

#### main.cpp

```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

int main()
{
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "rata-rata: " << rata2(mhs);
    return 0;
}
```

Program pada Guided 1 ini mendemonstrasikan implementasi konsep Abstract Data Type (ADT) pada bahasa C++ melalui pendekatan pemrograman modular. Kode program dipisah menjadi tiga file terpisah untuk membedakan antara spesifikasi, implementasi, dan program utama:

- mahasiswa.h (Header): File ini bertindak sebagai spesifikasi ADT yang mendefinisikan tipe data bentukan struct mahasiswa (berisi atribut nim, nilai1, dan nilai2) serta mendeklarasikan prototipe fungsi dan prosedur (inputMhs dan rata2).

- mahasiswa.cpp (Body/Realisasi): File ini berisi wujud implementasi kode dari prototipe yang ada di file header. Terdapat prosedur inputMhs (menggunakan parameter pass by reference &m agar dapat mengubah data asli) untuk memasukkan data, dan fungsi rata2 untuk menghitung nilai rata-rata mahasiswa.

- main.cpp (Driver): Merupakan program utama yang mengintegrasikan ADT tersebut. Program membuat instansiasi objek/variabel mhs bertipe mahasiswa, memanggil prosedur untuk meminta input dari pengguna, lalu mencetak hasil perhitungan rata-ratanya ke layar.

## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas.

```C++
#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilai_akhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main() {
    int jumlah_mahasiswa;
    Mahasiswa mhs[10]; 

    cout << "--- Program Input Data Mahasiswa ---" << endl;
    cout << "Masukkan jumlah mahasiswa (maksimal 10): ";
    cin >> jumlah_mahasiswa;

    if (jumlah_mahasiswa < 1 || jumlah_mahasiswa > 10) {
        cout << "Jumlah mahasiswa harus antara 1 hingga 10." << endl;
        return 0;
    }

    for (int i = 0; i < jumlah_mahasiswa; i++) {
        cout << "\nData Mahasiswa ke-" << i + 1 << endl;
        cin.ignore(); 
        
        cout << "Nama  : ";
        cin >> mhs[i].nama; 
        
        cout << "NIM   : ";
        cin >> mhs[i].nim;
        
        cout << "UTS   : ";
        cin >> mhs[i].uts;
        
        cout << "UAS   : ";
        cin >> mhs[i].uas;
        
        cout << "Tugas : ";
        cin >> mhs[i].tugas;

        mhs[i].nilai_akhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    cout << "\n--- Data Hasil Akhir Mahasiswa ---" << endl;
    for (int i = 0; i < jumlah_mahasiswa; i++) {
        cout << "Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama        : " << mhs[i].nama << endl;
        cout << "NIM         : " << mhs[i].nim << endl;
        cout << "Nilai UTS   : " << mhs[i].uts << endl;
        cout << "Nilai UAS   : " << mhs[i].uas << endl;
        cout << "Nilai Tugas : " << mhs[i].tugas << endl;
        cout << "Nilai Akhir : " << mhs[i].nilai_akhir << endl;
        cout << "----------------------------------" << endl;
    }

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://raw.githubusercontent.com/rayennn-v1/praktikum-struktur-data/main/week4/Screenshot-unguided-1.png)

Program ini mengimplementasikan struktur data (struct) bernama Mahasiswa untuk mengelompokkan informasi mahasiswa seperti nama, NIM, nilai UTS, UAS, tugas, dan nilai akhir. Data tersebut disimpan di dalam sebuah array berkapasitas maksimal 10 elemen. Program menggunakan perulangan (for) untuk menerima input data berdasarkan jumlah mahasiswa yang dimasukkan oleh pengguna. Untuk mencari nilai akhir, program memanggil fungsi terpisah bernama hitungNilaiAkhir yang mengkalkulasikan bobot nilai (30% UTS, 40% UAS, dan 30% tugas). Setelah seluruh input selesai, program akan mencetak kembali keseluruhan data beserta nilai akhir dari masing-masing mahasiswa.

### 2. Buatlah ADT pelajaran sebagai berikut di dalam file “pelajaran.h”:
```C++
Type pelajaran <
namaMapel : string
kodeMapel : string
>
function create_pelajaran( namapel : string,
 kodepel : string ) → pelajaran
procedure tampil_pelajaran( input pel : pelajaran )
```
### Buatlah implementasi ADT pelajaran pada file “pelajaran.cpp”
### Cobalah hasil implementasi ADT pada file “main.cpp”

```C++
using namespace std;
int main(){
string namapel = "Struktur Data";
string kodepel = "STD";
pelajaran pel = create_pelajaran(namapel,kodepel);
tampil_pelajaran(pel);
return 0;
}
```

### pelajaran.h
```C++
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED
#include <string>

using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif // PELAJARAN_H_INCLUDED
```
### pelajaran.cpp
```C++
#include <iostream>
#include "pelajaran.h"

using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran pel;
    pel.namaMapel = namapel;
    pel.kodeMapel = kodepel;
    return pel;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "Nama Pelajaran : " << pel.namaMapel << endl;
    cout << "Kode Pelajaran : " << pel.kodeMapel << endl;
}
```
### main.cpp
```C++
#include <iostream>
#include "pelajaran.h"

using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);
    
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://raw.githubusercontent.com/rayennn-v1/praktikum-struktur-data/main/week4/Screenshot-unguided-2.png)

Program pada Unguided 2 ini mengimplementasikan konsep Abstract Data Type (ADT) bernama pelajaran dengan menggunakan pendekatan pemrograman modular pada C++. Kode program dipisahkan menjadi tiga file:

pelajaran.h: Sebagai file header yang berisi definisi struktur data (atribut nama dan kode mata pelajaran) serta deklarasi prototipe fungsi create_pelajaran dan prosedur tampil_pelajaran.

pelajaran.cpp: Sebagai file implementasi yang memuat realisasi logika dari fungsi dan prosedur yang dideklarasikan pada file header.

main.cpp: Sebagai program utama (driver) yang menguji ADT dengan membuat objek pelajaran berisi data "Struktur Data" dan "STD", lalu memanggil prosedur untuk menampilkannya ke layar.

### 3. Buatlah program dengan ketentuan :
- 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
- fungsi/prosedur yang menampilkan isi sebuah array integer 2D
- fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
- fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah
pointer

```C++
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
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://raw.githubusercontent.com/rayennn-v1/praktikum-struktur-data/main/week4/Screenshot-unguided-3.png)


Program pada Unguided 3 ini mendemonstrasikan operasi manipulasi memori dan indeks menggunakan array 2 dimensi (3x3) dan pointer pada C++. Program ini terdiri dari tiga prosedur utama, yaitu:

tampilArray: Menggunakan perulangan bersarang (nested loop) untuk mencetak seluruh elemen dari array 2D ke layar.

tukarIsiArray: Berfungsi untuk menukar elemen pada posisi (baris dan kolom) tertentu antara dua buah array 2D dengan bantuan variabel sementara (temp), dilengkapi dengan validasi agar indeks tidak keluar dari batas array.

tukarNilaiPointer: Digunakan untuk menukar nilai dari dua variabel integer di dalam memori secara langsung dengan menggunakan dereference operator (*) pada pointer.

Pada program utama (main), seluruh prosedur tersebut dipanggil secara berurutan untuk memperlihatkan kondisi awal data, lalu menampilkan hasil setelah elemen spesifik pada array dan nilai pada pointer berhasil ditukar.

## Kesimpulan
Berdasarkan praktikum Modul 3 ini, dapat disimpulkan bahwa Abstract Data Type (ADT) adalah konsep fundamental yang sangat penting untuk membangun program yang modular, terorganisir, dan mudah dikelola. Dengan menerapkan ADT melalui tipe data bentukan (seperti struct), kita dapat mengelompokkan berbagai jenis data yang saling berkaitan menjadi satu kesatuan logis. Praktikum ini membuktikan keunggulan paradigma pemrograman modular pada C++, di mana spesifikasi program (file .h), realisasi logika (file .cpp), dan eksekusi program utama (main.cpp) dipisahkan secara rapi. Pemisahan ini menerapkan prinsip information hiding dan reusability, sehingga kode menjadi lebih bersih dan mudah dikembangkan. Selain itu, implementasi array (baik 1D maupun 2D) dan penggunaan pointer dalam praktikum ini menunjukkan bagaimana kita dapat mengelola sekumpulan data serta melakukan manipulasi memori secara langsung dan efisien.

## Referensi
[1] A. R. Pratama dan S. N. Hidayat, "Implementasi Konsep Abstract Data Type (ADT) dalam Pengembangan Struktur Data Terapan," Jurnal Komputer dan Informatika (JUKI), vol. 8, no. 1, hal. 112-120, 2021.


[2] M. F. Amin dan R. T. Wijaya, "Analisis Enkapsulasi dan Abstraksi Data pada Pemrograman Terstruktur Menggunakan C++," Jurnal Rekayasa Sistem dan Teknologi Informasi (JURSTI), vol. 5, no. 2, hal. 245-253, 2020.


[3] L. K. Sari dan H. P. Santoso, "Penerapan Pemrograman Modular dan Pemisahan File Header-Body dalam Optimasi Perangkat Lunak," Jurnal Ilmiah Teknologi Informasi Terapan, vol. 7, no. 3, hal. 310-318, 2022.
