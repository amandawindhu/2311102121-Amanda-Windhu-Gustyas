// Oleh Amanda Windhu Gustyas - 2311102121
#include <iostream>
using namespace std;

// Array untuk menyimpan data stack buku
string arrayBuku[5];
// Maksimal jumlah elemen yang dapat disimpan dalam stack
int maksimal = 5;
// Variabel untuk menunjukkan posisi teratas dalam stack
int top = 0;

// Fungsi untuk memeriksa apakah stack penuh
bool isFull() {
    return (top == maksimal);
}

// Fungsi untuk memeriksa apakah stack kosong
bool isEmpty() {
    return (top == 0);
}

// Fungsi untuk menambahkan data baru ke dalam stack
void pushArrayBuku(string data) {
    if (isFull()) { // Jika stack penuh
        cout << "Data telah penuh" << endl;
    } else { // Jika stack belum penuh
        arrayBuku[top] = data; // Menambahkan data ke dalam stack
        top++; // Menaikkan indeks top
    }
}

// Fungsi untuk menghapus data teratas dari stack
void popArrayBuku() {
    if (isEmpty()) { // Jika stack kosong
        cout << "Tidak ada data yang dihapus" << endl;
    } else { // Jika stack tidak kosong
        arrayBuku[top - 1] = ' '; // Menghapus data teratas dengan mengganti dengan karakter kosong
        top--; // Mengurangi indeks top
    }
}

// Fungsi untuk melihat data pada posisi tertentu dalam stack
void peekArrayBuku(int posisi) {
    if (isEmpty()) { // Jika stack kosong
        cout << "Tidak ada data yang dapat dilihat" << endl;
    } else { // Jika stack tidak kosong
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--; // Mencari indeks data yang ingin dilihat
        }
        cout << "posisi ke " << posisi << " adalah " << arrayBuku[index] << endl; // Menampilkan data pada posisi yang diinginkan
    }
}

// Fungsi untuk menghitung jumlah data dalam stack
int countStack() {
    return top;
}

// Fungsi untuk mengubah data pada posisi tertentu dalam stack
void chargeArrayBuku(int posisi, string data) {
    if (posisi > top) { // Jika posisi melebihi jumlah data dalam stack
        cout << "Posisi melebihi data yang ada" << endl;
    } else { // Jika posisi valid
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--; // Mencari indeks data yang ingin diubah
        }
        arrayBuku[index] = data; // Mengubah data pada posisi yang diinginkan
    }
}

// Fungsi untuk menghapus semua data dalam stack
void destroyArrayBuku() {
    for (int i = top - 1; i >= 0; i--) {
        arrayBuku[i] = ""; // Menghapus semua data dengan mengganti dengan string kosong
    }
    top = 0; // Mengatur ulang top menjadi 0 karena stack kosong
}

// Fungsi untuk mencetak semua data dalam stack
void cetakArrayBuku() {
    if (isEmpty()) { // Jika stack kosong
        cout << "Tidak ada data yang di cetak" << endl;
    } else { // Jika stack tidak kosong
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl; // Mencetak data dari top ke bottom
        }
    }
}

int main() {
    // Menambahkan beberapa buku ke dalam stack
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    // Menampilkan isi stack buku
    cout << "Isi stack buku:" << endl;
    cetakArrayBuku();
    cout << endl;

    // Melakukan pengecekan apakah stack penuh atau kosong
    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;

    // Melihat data pada posisi tertentu dalam stack
    cout << "Data pada posisi 2:" << endl;
    peekArrayBuku(2);

    // Menghapus data teratas dari stack
    popArrayBuku();
    cout << "Data teratas dihapus." << endl;

    // Menghitung jumlah data dalam stack
    cout << "Banyaknya data = " << countStack() << endl;

    // Mengubah data pada posisi tertentu dalam stack
    chargeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();

    cout << endl;

    // Menghapus semua data dalam stack
    destroyArrayBuku();
    cout << "Jumlah data setelah dihapus : " << top << endl;

    cetakArrayBuku();

    return 0;
}
