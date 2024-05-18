// Oleh Amanda Windhu Gustyas_2311102121
#include <iostream>
#include <algorithm>

using namespace std;

string kalimat;
char cari;

// Fungsi untuk melakukan pencarian biner pada string yang telah diurutkan
bool binary_search(const string& kalimat, char cari) {
 int awal = 0, akhir = kalimat.length() - 1;
 while (awal <= akhir) {
 int tengah = (awal + akhir) / 2; // Menghitung indeks tengah
 if (kalimat[tengah] == cari) {
 return true; // Huruf ditemukan
 } else if (kalimat[tengah] < cari) {
 awal = tengah + 1; // Cari di bagian kanan
 } else {
 akhir = tengah - 1; // Cari di bagian kiri
 }
 }
 return false; // Huruf tidak ditemukan
}
int main() {
    cout << "--- MENCARI HURUF ---\n";
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);
    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> cari;
    cari = tolower(cari); // Mengubah huruf yang dicari menjadi huruf kecil

    // Mengurutkan kalimat agar bisa dilakukan pencarian biner
    sort(kalimat.begin(), kalimat.end());

    // Melakukan pencarian biner
    bool ditemukan = binary_search(kalimat, cari);

    // Menampilkan hasil pencarian
    if (ditemukan) {
    cout << "Huruf " << cari << " ditemukan." << endl;
    } else {
    cout << "Huruf " << cari << " tidak ditemukan." << endl;
        }
    return 0;
}