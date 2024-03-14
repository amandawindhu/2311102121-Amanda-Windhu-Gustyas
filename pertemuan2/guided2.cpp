#include <iostream>
using namespace std;

int main() {
    int maks; // Variabel untuk menyimpan nilai maksimum
    int a, i = 1, lokasi; // Variabel untuk panjang array, iterasi, dan lokasi nilai maksimum

    cout << "Masukkan panjang array: ";
    cin >> a; // Meminta pengguna untuk memasukkan panjang array
    
    int array[a]; // Mendeklarasikan array dengan panjang yang dimasukkan pengguna
    cout << "Masukkan " << a << " angka\n";
    // Meminta pengguna untuk memasukkan angka-angka ke dalam array
    for (i = 0; i < a; i++) {
        cout << "Array ke-" << (i + 1) << ": ";
        cin >> array[i];
    }
    maks = array[0]; // Menginisialisasi nilai maksimum dengan elemen pertama dari array
    // Mencari nilai maksimum dari array dan menentukan lokasinya
    for (i = 0; i < a; i++) {
        if (array[i] > maks) {
            maks = array[i];
            lokasi = i;
        }
    }
    // Menampilkan nilai maksimum beserta lokasinya di dalam array
    cout << "Nilai maksimum adalah " << maks << " berada di Array ke-" << (lokasi + 1) << endl;
    return 0;
}
