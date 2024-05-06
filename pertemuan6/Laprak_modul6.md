# <h1 align="center">Laporan Praktikum Modul Stack</h1>
<p align="center">Amanda Windhu Gustyas - 2311102121</p>

## Dasar Teori
- Pengertian Stack<br/>
Stack atau tumpukan adalah suatu stuktur data yang penting dalam pemrograman dengan metode pemrosesan yang bersifat LIFO (Last  In  First  Out) di mana objek/benda yang terakhir masuk ke dalam stack akan menjadi benda pertama yang dikeluarkan dari stack. Dengan model demikian, maka hanya bagian paling atas saja dari stack (TOP) yang bisa di akses. Salah satu kelebihan stack adalah bahwa struktur data tersebut dapat diimplementasikan baik pada array maupun pada linked list.<br/>
![Stack](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/89a2bece-6d90-4f0b-ad0b-20efb16c2389)<br/>
Operasi struktur data pada stack:<br/>
1)Push: Digunakan untuk menambah item pada stack pada tumpukan paling atas.<br/>
2)Pop: Digunakan untuk mengambil item pada stack pada tumpukan paling atas<br/>
3)Clear: Digunakan untuk mengosongkan stack.<br/>
4)IsEmpty: Digunakan untuk mengecek apakah stack sudah kosong.<br/>
5)IsFull: Digunakan untuk mengecek apakah stack sudah penuh.<br/>
6)Peek: Digunakan untuk melihat elemen paling atas pada stack tanpa menghapusnya.<br/>
7)Size: Digunakan untuk mendapatkan jumlah elemen pada stack.<br/>
8)Top: Digunakan untuk mendapatkan elemen paling atas pada stack.<br/>
9)Copy: Digunakan untuk menyalin isi dari stack ke stack lain.<br/>
10)Reverse: Digunakan untuk membalikkan isi stack.<br/>
11)Display: Digunakan untuk menampilkan isi stack<br/>
12)Insert: Digunakan untuk menambahkan elemen dalam posisi spesifik pada stack.<br/>
13)Delete: Digunakan untuk mengahpus elemen pada posisi spesifik.<br/>
14)Search: Digunakan untuk mencari elemen yang spesifik pada stack.<br/>
15)Traverse: Digunakan untuk menelusuri isi pada stack.<br/>
- Deklarasi Struktur Data Stack<br/>
```C++
const int maxsize = 100; // Mendefinisikan maks ukuran data dalam stack
struct stack {
    int top;            // Indeks TOP
    char items[maxsize];// Array
};
```

### 1. [Guided]

```C++
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
```
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Unguided 

### 1. [Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.]
### Contoh:
### Kalimat : ini
### Kalimat tersebut adalah polindrom

### Kalimat : telkom
### Kalimat tersebut adalah bukan polindrom
![Soal_1](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/3cbbffe1-0b14-400a-80cd-4b946b79399b)<br/>

```C++
// Oleh Amanda Windhu Gustyas - 2311102121
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Fungsi untuk memeriksa apakah sebuah kalimat adalah palindrom
bool isPalindrome(const string& kal) {
    string strippedSentence;

    // Menghapus spasi dan tanda baca dari kalimat, dan mengonversi huruf menjadi lowercase
    for (char r047 : kal) {
        if (isalpha(r047)) {
            strippedSentence += tolower(r047); // Menambahkan karakter yang valid ke dalam kalimat tanpa tanda baca dan spasi
        }
    }

    string reversedSentence = strippedSentence;
    reverse(reversedSentence.begin(), reversedSentence.end()); 
    // Membalikkan kalimat untuk memeriksa apakah sama dengan kalimat asli
    
    return strippedSentence == reversedSentence; // Mengembalikan nilai true jika kalimat adalah palindrom, dan false jika tidak
}

int main() {
    string kal;
    cout << "Masukkan kalimat: ";
    getline(cin, kal);

    bool isPalindrom = isPalindrome(kal); // Memanggil fungsi isPalindrome untuk memeriksa apakah kalimat adalah palindrom atau tidak

    cout << "Kalimat: " << kal << endl;

    // Menampilkan hasil apakah kalimat adalah palindrom atau tidak
    if (isPalindrom) {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl;
    }

    return 0; // Mengembalikan nilai 0, menandakan bahwa program berjalan dengan sukses
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

### 2. [Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?]
### Contoh
### Kalimat : Telkom Purwokerto
### Hasil : otrekowruP mokleT
![Soal_2](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/2a18abde-600b-494d-90b8-884eb0a9522a)<br/>
```C++
// Oleh Amanda Windhu Gustyas - 2311102121
#include <iostream>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

// Fungsi untuk membalik urutan kata dalam sebuah kalimat
string reverseSentence(const string& kal) {
    stack<string> stack; // Membuat stack untuk menyimpan kata-kata yang sudah dibalik
    stringstream r047(kal); // Membuat stringstream untuk memproses input kalimat
    string kat; // Variabel untuk menyimpan setiap kata dalam kalimat

    // Memasukkan setiap kata (yang sudah dibalik) ke dalam stack
    while (r047 >> kat) {
        reverse(kat.begin(), kat.end()); // Membalikkan urutan karakter dalam kata
        stack.push(kat); // Memasukkan kata yang sudah dibalik ke dalam stack
    }

    string reversedSentence; // Variabel untuk menyimpan kalimat yang sudah dibalik urutannya
    // Mengambil kata-kata dari stack dan menyusunnya kembali menjadi kalimat yang sudah dibalik
    while (!stack.empty()) {
        reversedSentence += stack.top(); // Mengambil kata paling atas dari stack
        stack.pop(); // Menghapus kata paling atas dari stack
        // Tambahkan spasi sebelum kata (kecuali untuk kata pertama)
        if (!stack.empty()) {
            reversedSentence += " "; // Menambahkan spasi jika belum mencapai kata pertama
        }
    }
    return reversedSentence; // Mengembalikan kalimat yang sudah dibalik urutannya
}

int main() {
    string kal; // Variabel untuk menyimpan input kalimat dari pengguna
    cout << "Masukkan kalimat: "; // Menampilkan pesan permintaan input kepada pengguna
    getline(cin, kal); // Membaca seluruh baris input dari pengguna

    // Memanggil fungsi reverseSentence dengan input kalimat dan menyimpan hasilnya
    string hasil = reverseSentence(kal);

    // Menampilkan kalimat asli dan hasil pembalikan kalimat kepada pengguna
    cout << "Kalimat: " << kal << endl;
    cout << "Hasil: " << hasil << endl;

    return 0; // Mengembalikan nilai 0, menandakan bahwa program berjalan dengan sukses
}
```

## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
