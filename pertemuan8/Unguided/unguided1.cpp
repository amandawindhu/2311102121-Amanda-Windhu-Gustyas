// Oleh Amanda Windhu Gustyas_2311102121
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

string kalimat;
char cari;

// Fungsi untuk melakukan binary search pada string
void binarySearch(){
    int awal, akhir, tengah;
    bool b_flag = false; // Flag untuk menandakan apakah data ditemukan
    awal = 0;
    akhir = kalimat.length() - 1;
    while (!b_flag && awal <= akhir)
    {
        tengah = (awal + akhir)/2;
        if (kalimat[tengah] == cari)
        {
            b_flag = true;  // Data ditemukan
        } else if (kalimat[tengah] <  cari)
        {
            awal = tengah +1; // Cari di bagian kanan
        } else {
            akhir = tengah -1; // Cari di bagian kiri
        }
    }
    if (b_flag){
        cout << "\nData ditemukan pada index ke- " << tengah <<endl;
    } else {
        cout << "\nDATA TIDAK DITEMUKAN" << endl;
    }
}

int main() {
    cout << "---Cari Huruf---"<<endl;
    cout << "Masukkan kalimat : ";
    getline(cin, kalimat);
    cout << "Masukkan huruf yang ingin dicari : ";
    cin >> cari;

    // Mengurutkan kalimat
    sort(kalimat.begin(), kalimat.end());

    cout << "\nKalimat diurutkan : " << kalimat << endl;

    cout << "\nBinary Search untuk mencari huruf '" << cari << "' dalam kalimat '" << kalimat << "' : ";
    binarySearch(); // Memanggil fungsi untuk melakukan pencarian biner
    _getche(); // Menunggu pengguna menekan tombol sebelum keluar
    return 0;
}