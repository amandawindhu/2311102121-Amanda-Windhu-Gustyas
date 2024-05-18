// Oleh Amanda Windhu Gustyas_2311102121
#include <iostream>
#include <algorithm>

using namespace std;
string kalimat;

    
// Fungsi untuk menghitung jumlah huruf vokal dalam sebuah kalimat
int huruf_vokal(const string& kalimat) {
    int count = 0;
    string vokal = "aiueo"; // String berisi huruf vokal
    string lowercase_kalimat = kalimat; // Salinan dari kalimat yang akan diubah menjadi huruf kecil
   
    // Mengubah semua karakter dalam kalimat menjadi huruf kecil
    transform(lowercase_kalimat.begin(), lowercase_kalimat.end(), 
              lowercase_kalimat.begin(), ::tolower);
    
      // Menghitung jumlah huruf vokal
    for (char c : lowercase_kalimat) {
    if (vokal.find(c) != string::npos) { // Jika karakter adalah huruf vokal
    count++; // Tambahkan ke hitungan
    }
 }
 return count; // Mengembalikan jumlah huruf vokal
    }
    int main() {
        cout << "Program Menghitung Huruf Vokal" << endl;
        cout << "Masukkan kalimat: ";
        getline(cin, kalimat);

        // Menghitung jumlah huruf vokal dalam kalimat
        int jumlah_vokal = huruf_vokal(kalimat);

        // Menampilkan hasil perhitungan jumlah huruf vokal
        cout << "Jumlah huruf vokal di dalam kalimat: " << jumlah_vokal << endl;
        return 0;
    }