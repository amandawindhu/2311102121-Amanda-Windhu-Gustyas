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




### 1. [Nama Topik]

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code guided praktikan" << endl;
    return 0;
}
```
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Unguided 

### 1. [Soal]

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code unguided praktikan" << endl;
    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
