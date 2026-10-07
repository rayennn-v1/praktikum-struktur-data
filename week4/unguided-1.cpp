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