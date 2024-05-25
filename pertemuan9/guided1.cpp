#include <iostream>   
#include <iomanip>     

using namespace std;  

// Array nama kota yang direpresentasikan sebagai string
string simpul[7] = {
    "Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"
};

// Array 2D yang mewakili matriks ketetanggaan untuk graf
// Setiap elemen merepresentasikan bobot dari busur (edge) antara simpul (kota)
int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},    // Dari Ciamis ke Bandung (7), Bekasi (8)
    {0, 0, 5, 0, 0, 15, 0},   // Dari Bandung ke Bekasi (5), Purwokerto (15)
    {0, 6, 0, 0, 5, 0, 0},    // Dari Bekasi ke Bandung (6), Cianjur (5)
    {0, 5, 0, 0, 2, 4, 0},    // Dari Tasikmalaya ke Bandung (5), Cianjur (2), Purwokerto (4)
    {23, 0, 0, 10, 0, 0, 8},  // Dari Cianjur ke Ciamis (23), Tasikmalaya (10), Yogyakarta (8)
    {0, 0, 0, 7, 0, 0, 3},    // Dari Purwokerto ke Tasikmalaya (7), Yogyakarta (3)
    {0, 0, 0, 9, 4, 0}        // Dari Yogyakarta ke Tasikmalaya (9), Cianjur (4)
};

// Fungsi untuk menampilkan graf dalam format yang mudah dibaca
void tampilGraph() {
    // Iterasi setiap simpul (kota)
    for(int baris = 0; baris < 7; baris++) {
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        // Iterasi setiap kemungkinan koneksi dari simpul saat ini
        for (int kolom = 0; kolom < 7; kolom++) {
            if (busur[baris][kolom] != 0) {  // Cek jika ada busur (bobot non-nol)
                // Cetak simpul yang terhubung dan bobot busurnya
                cout << " " << simpul[kolom] << " (" << busur[baris][kolom] << ")";
            }
        }
        cout << endl; 
    }
}

// Fungsi utama untuk menjalankan program
int main() {
    tampilGraph();  // Panggil fungsi untuk menampilkan graf
    return 0;      
}
