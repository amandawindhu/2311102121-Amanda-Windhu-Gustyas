#include <iostream> // untuk operasi input output
#include <array> // untuk menyediakan array statis dengan ukuran tetap
using namespace std; // agar elemen cout dan cin dapat langsung ditulis tanpa menggunakan std

int main() {
// Deklarasi dan inisialisasi array
    int nilai_amanda_121[5];
    nilai_amanda_121[0] = 23;
    nilai_amanda_121[1] = 50;
    nilai_amanda_121[2] = 34;
    nilai_amanda_121[3] = 78;
    nilai_amanda_121[4] = 90;
    
    // Mencetak isi array dengan 
    cout << "Isi array pertama : " << nilai_amanda_121[0] << endl;
    cout << "Isi array kedua : " << nilai_amanda_121[1] << endl;
    cout << "Isi array ketiga : " << nilai_amanda_121[2] << endl;
    cout << "Isi array keempat : " << nilai_amanda_121[3] << endl;
    cout << "Isi array kelima : " << nilai_amanda_121[4] << endl;

    return 0;
}