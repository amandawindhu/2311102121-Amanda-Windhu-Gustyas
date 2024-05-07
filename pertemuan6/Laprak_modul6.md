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
- Beberapa fungsi penting dari struktur data stack:<br/>
1. Manajemen Memori: Stack digunakan untuk menyimpan alamat memori dari suatu fungsi saat program dijalankan, membantu dalam alokasi dan dealokasi memori dengan efisien.<br/>
2. Pengecekan Tata Bahasa: Stack digunakan untuk menyimpan konteks dari suatu ekspresi matematika atau kondisi logika, memastikan urutan operasi dan sintaksis yang benar.<br/>
3. Algoritma Backtracking: Stack digunakan untuk menyimpan state dari suatu proses yang dapat dikembalikan ke state sebelumnya jika proses tersebut gagal, memungkinkan eksplorasi ulang dari pilihan sebelumnya.<br/>
4. Algoritma Pengurutan: Stack digunakan dalam beberapa algoritma pengurutan seperti quicksort dan mergesort, membantu dalam penyimpanan sementara data dan pengaturan urutan.<br/>
5. Pemecahan Masalah Rekursif: Stack digunakan dalam pemecahan masalah rekursif karena setiap panggilan rekursif akan ditambahkan ke stack dan setiap pengembalian dari rekursif akan dihapus dari stack, memastikan tidak terjadi kelebihan memori.<br/>
6. Evaluasi Ekspresi: Stack digunakan dalam evaluasi ekspresi aritmatika dan logika, membantu dalam pemrosesan operasi dan operand.<br/>
- Beberapa kelebihan dari stack:<br/>
1. Efisiensi Waktu: Operasi seperti push, pop, dan peek memerlukan waktu yang konstan, yaitu O(1), sehingga memungkinkan untuk eksekusi cepat.<br/>
2. Penanganan Data Sementara: Stack dapat digunakan untuk menyimpan data sementara selama proses eksekusi, seperti dalam manajemen memori, pengecekan tata bahasa, dan algoritma backtracking.<br/>
3. Implementasi yang Mudah: Stack dapat diimplementasikan dengan menggunakan berbagai struktur data dasar seperti array, linked list, dan pointer, sehingga mudah diintegrasikan dalam berbagai aplikasi.<br/>
4. Penyimpanan Data yang Aman: Stack dapat digunakan untuk menyimpan data sensitif dengan menerapkan teknik keamanan seperti enkripsi, sehingga menjaga keamanan informasi.<br/>
5. Penanganan Masalah Rekursif: Stack dapat digunakan efektif dalam penyelesaian masalah rekursif karena kemampuannya dalam menyimpan dan menghapus panggilan rekursif secara berurutan.<br/>
6. Kapasitas Terbatas: Stack memiliki kapasitas terbatas yang telah ditentukan sebelumnya, sehingga mencegah kemungkinan terjadinya overflow dan memberikan kepastian terhadap penggunaan memori.<br/>
- Beberapa kekurangan dari stack:<br/>
1. Kapasitas Terbatas: Stack memiliki kapasitas yang telah ditentukan sebelumnya dan tidak dapat menambah elemen jika sudah penuh, sehingga dapat menyebabkan overflow jika tidak dikelola dengan baik.<br/>
2. Akses Terbatas: Hanya elemen yang berada di atas elemen teratas yang dapat diakses. Elemen yang berada di bawah elemen teratas tidak dapat diakses tanpa menghapus elemen di atasnya, membatasi fleksibilitas dalam akses data.<br/>
3. Akses Data yang Lambat: Jika ingin mengakses data yang berada di bawah elemen teratas, harus menghapus semua elemen di atasnya terlebih dahulu, menyebabkan keterlambatan dalam akses data.
4. Kekurangan dalam Penyimpanan Data: Stack hanya cocok untuk menyimpan data sementara dan tidak dapat digunakan untuk menyimpan data permanen, mengakibatkan keterbatasan dalam penggunaan.<br/>
5. Overflow dan Underflow: Stack dapat mengalami overflow jika terus menerus menambah elemen tanpa cukup kapasitas, dan mengalami underflow jika terus menerus menghapus elemen tanpa tersisa, mengurangi kehandalan struktur data.<br/>
6. Keterbatasan dalam Pencarian Data: Stack tidak dapat digunakan untuk mencari elemen tertentu, karena hanya elemen teratas yang dapat diakses, membatasi kemampuan pencarian data.<br/>

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
Program di atas adalah implementasi dari C++ struktur data stack menggunakan array untuk menyimpan data buku. Stack adalah struktur data yang memungkinkan penambahan dan penghapusan elemen dari atas ke bawah. Program ini menawarkan fungsi untuk memeriksa apakah stack penuh atau kosong, menambahkan data baru, menghapus data teratas, melihat data pada posisi tertentu, menghitung jumlah data, mengubah data pada posisi tertentu, dan menghapus semua data dalam stack.<br/>
Program ini dimulai dengan menambahkan beberapa judul buku ke dalam stack menggunakan fungsi `pushArrayBuku`. Kemudian, program menampilkan isi stack buku menggunakan fungsi `cetakArrayBuku`. Selanjutnya, program melakukan pengecekan apakah stack penuh atau kosong menggunakan fungsi `isFull` dan `isEmpty`.
Program juga menampilkan data pada posisi tertentu dalam stack menggunakan fungsi `peekArrayBuku`, menghapus data teratas dari stack menggunakan fungsi `popArrayBuku`, menghitung jumlah data dalam stack menggunakan fungsi `countStack`, mengubah data pada posisi tertentu dalam stack menggunakan fungsi `chargeArrayBuku`, dan menghapus semua data dalam stack menggunakan fungsi `destroyArrayBuku`.<br/>
Dalam akhir program, isi stack buku dihapus dan jumlah data setelah dihapus ditampilkan. Program ini memberikan contoh bagaimana struktur data stack dapat digunakan dalam aplikasi yang memerlukan pengelolaan data secara terstruktur.<br/>

## Unguided 

### 1. [Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.]
### Contoh:
### Kalimat : ini
### Kalimat tersebut adalah polindrom

### Kalimat : telkom
### Kalimat tersebut adalah bukan polindrom
![Soal_1](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/3cbbffe1-0b14-400a-80cd-4b946b79399b)<br/>

Algoritma:<br/>
1. Mulai<br/>
2. Masukkan kata yang ingin diperiksa<br/>
3. Hitung jumlah huruf dalam kata<br/>
4. Masukkan setiap huruf ke dalam stack (push)<br/>
5. Bandingkan huruf pertama dalam stack dengan huruf terakhir<br/>
6. Perbandingan dilakukan berulang sebanyak jumlah huruf<br/>
7. Jika setiap huruf yang dibandingkan sama, kata tersebut adalah polindrom<br/>
8. Selesai
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
![SS_UNGUIDED_1](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/e4683150-f321-45be-8fd8-f36fe9460490)<br/>
![SS_UNGUIDED_2](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/5601c700-863c-4063-b82c-0c096f204bde)<br/>

Program di atas adalah implementasi dari C++ struktur data stack yang memeriksa apakah sebuah kalimat adalah palindrom atau tidak. Palindrom adalah sebuah kalimat yang memiliki sifat bahwa jika dibalik, maka hasilnya tetap sama dengan kalimat asli. Program ini meminta pengguna untuk memasukkan sebuah kalimat melalui input, lalu memanggil fungsi `isPalindrome` dengan kalimat yang diberikan sebagai parameter.<br/>
Fungsi `isPalindrome` menghapus spasi dan tanda baca dari kalimat, serta mengonversi huruf menjadi lowercase untuk memudahkan pengecekan. Kemudian, fungsi `isPalindrome` membalikkan kalimat yang telah disiapkan dan membandingkan dengan kalimat asli. Jika kalimat asli sama dengan kalimat yang dibalik, maka fungsi `isPalindrome` mengembalikan nilai `true`, yang menandakan bahwa kalimat adalah palindrom. Jika tidak, maka nilai `false` dikembalikan.<br/>
Program ini kemudian menampilkan hasil pengecekan dengan menampilkan kalimat yang diberikan dan apakah kalimat tersebut adalah palindrom atau tidak. Dengan demikian, program ini dapat membantu dalam memeriksa apakah sebuah kalimat adalah palindrom atau tidak.<br/>

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
### Output:
![SS_UNGUIDED2_1](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/a85cbb03-a897-44f4-a01a-644f1df533b4)<br/>
![SS_UNGUIDED2_2](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/41f0db6b-1798-4417-8399-10d0f8c56f0c)<br/>
![SS_UNGUIDED2_3](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/8164ebbd-3622-4f43-afb2-c3b50f001865)<br/>

Program di atas adalah implementasi dari C++ struktur data stack yang membalikkan urutan kata dalam sebuah kalimat. Program ini meminta pengguna untuk memasukkan sebuah kalimat melalui input, lalu memanggil fungsi `reverseSentence` dengan kalimat yang diberikan sebagai parameter.<br/>
Fungsi `reverseSentence` menggunakan stack untuk menyimpan kata-kata yang sudah dibalik. Program ini memproses input kalimat dengan menggunakan stringstream untuk memisahkan kata-kata dan mengonversi huruf menjadi lowercase. Kemudian, program ini membalikkan urutan karakter dalam setiap kata dan memasukkan kata-kata yang sudah dibalik ke dalam stack.<br/>
Setelah semua kata dibalik, program ini mengambil kata-kata dari stack dan menyusunnya kembali menjadi kalimat yang sudah dibalik urutannya. Program ini menambahkan spasi antara kata-kata untuk mempertahankan struktur asli kalimat. Akhirnya, program ini mengembalikan kalimat yang sudah dibalik urutannya.
Dalam program utama, hasil dari fungsi `reverseSentence` ditampilkan kepada pengguna bersama dengan kalimat asli. Dengan demikian, program ini dapat membantu dalam membalikkan urutan kata dalam sebuah kalimat.<br/>

## Kesimpulan
Stack atau tumpukan adalah struktur data yang penting dalam pemrograman dengan metode pemrosesan yang bersifat LIFO (Last In First Out), di mana objek/benda yang terakhir masuk ke dalam stack akan menjadi benda pertama yang dikeluarkan dari stack. Dengan model demikian, maka hanya bagian paling atas saja dari stack (TOP) yang bisa diakses. Salah satu kelebihan stack adalah bahwa struktur data tersebut dapat diimplementasikan baik pada array maupun pada linked list.<br/>
Beberapa fungsi penting dari struktur data stack meliputi manajemen memori, pengecekan tata bahasa, algoritma backtracking, algoritma pengurutan, pemecahan masalah rekursif, evaluasi ekspresi, dan lain-lain. Kelebihan stack meliputi efisiensi waktu, penanganan data sementara, implementasi yang mudah, penyimpanan data yang aman, penanganan masalah rekursif, dan kapasitas terbatas. Namun, stack juga memiliki beberapa kekurangan, seperti kapasitas terbatas, akses terbatas, akses data yang lambat, kekurangan dalam penyimpanan data, overflow dan underflow, dan keterbatasan dalam pencarian data.<br/>

## Referensi
[1] Sihombing, Johnson. (2020). Penerapan Stack dan Queue pada Array dan Linked List. Program Studi Manajemen Informatika, Politeknik Piksi Ganesha. Bandung.<br/>
[2] Selamet, Rachmat. (2019). Implementasi Struktur Data List, Queue, dan Stack. Media Informatika, Volume 15, Nomor 3.<br/>
[3] Aliyanto, Arif. (2019). Sistem Pembelajaran Algoritma Stack dan Queue dengan Pendekatan Problem Based Learning untuk Mendukung Pembelajaran Struktur Data.<br/>
