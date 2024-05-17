# <h1 align="center">Laporan Praktikum Modul Algoritma Searching</h1>
<p align="center">Amanda Windhu Gustyas - 2311102121</p>

## Dasar Teori

Berikan penjelasan teori terkait materi modul ini dengan bahasa anda sendiri serta susunan yang terstruktur per topiknya.

## Guided 

### 1. [Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data.]

```C++
#include <iostream>

using namespace std;

int main () {
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}; 
    int cari = 10;
    bool ketemu = false; // Variabel boolean untuk melacak apakah nilai ditemukan
    int i;

    // Loop melalui array untuk mencari nilai
    for (i = 0; i < n; i++) { 
        if (data[i] == cari) {
            ketemu = true;
            break;
        }
    }

    cout << "Program Sequential Search" << endl;
    cout << "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;

    // Memeriksa apakah nilai ditemukan dan mencetak pesan yang sesuai
    if (ketemu) { 
        cout << "\nAngka " << cari << " ditemukan pada indeks ke- " << i << endl;
    } else {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }

    return 0;
}
```
Program di atas adalah implementasi sederhana dari algoritma Sequential Search, yang digunakan untuk mencari angka tertentu dalam suatu array. Dalam kasus ini, program mencari sebuah array dengan 10 elemen yang berisi nilai 9, 4, 1, 7, 5, 12, 4, 13, 4, dan 10. Kemudian, program melakukan iterasi melalui setiap elemen array secara berurutan untuk mencari angka yang dicari. Jika angka ditemukan, program akan menandai hasilnya dan mencetak pesan yang menyatakan bahwa angka tersebut ditemukan beserta indeksnya. Jika angka tidak ditemukan, program akan mencetak pesan yang menyatakan bahwa angka tidak ditemukan dalam data. Dengan demikian, program ini memberikan pengguna informasi tentang apakah angka yang dicari ada dalam array dan di indeks mana angka tersebut ditemukan.

### 2. [Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search.]

```C++
#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int dataArray[7] = {1,8,2,5,4,9,7};
int cari;


// Fungsi untuk melakukan selection sort pada array
void selection_sort(){
    int temp, min, i, j;
    for (i = 0; i < 7; i++)
    {
        min = i;
        for (j = i + 1; j < 7; j++)
        {
            if (dataArray[j] < dataArray[min])
            {
                min = j;
            }
        }

        // Tukar elemen terkecil yang ditemukan dengan elemen pada posisi i
        temp = dataArray[i];
        dataArray[i] = dataArray[min];
        dataArray[min] = temp;
    }
}

// Fungsi untuk melakukan pencarian biner pada array
void binarySearch(){
    int awal, akhir, tengah;
    bool b_flag = false; // Flag untuk menandakan apakah data ditemukan
    awal = 0;
    akhir = 6;
    while (!b_flag && awal <= akhir)
    {
        tengah = (awal + akhir)/2;
        if (dataArray[tengah] == cari)
        {
            b_flag = true;  // Data ditemukan
        } else if (dataArray[tengah] <  cari)
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
    cout << "BINARY SEARCH"<<endl;
    cout << "\nData : ";

     // Menampilkan data array sebelum diurutkan
    for (int x =0; x < 7; x++)
    {
        cout <<setw(3)<<dataArray[x];
    }
    cout << endl;

    cout << "Masukkan data yang ingin dicari : ";
    cin >> cari;

    cout << "\nData diurutkan : ";
    selection_sort(); // Memanggil fungsi untuk mengurutkan array

    // Menampilkan data array setelah diurutkan
    for (int x = 0; x < 7; x++)
    {
        cout <<setw(3)<<dataArray[x];
    }
    cout <<endl;
    binarySearch(); // Memanggil fungsi untuk melakukan pencarian biner
    _getche(); // Menunggu pengguna menekan tombol sebelum keluar
    return 0;
}
```
Program tersebut merupakan implementasi dari algoritma Binary Search yang digunakan untuk mencari angka tertentu dalam sebuah array. Pada awalnya, program ini mendefinisikan sebuah array dengan 7 elemen dan sebuah variabel untuk menyimpan angka yang akan dicari. Kemudian, 
program melakukan proses pengurutan array menggunakan algoritma Selection Sort agar data terurut secara ascending. Setelah proses pengurutan selesai, program meminta pengguna untuk 
memasukkan angka yang ingin dicari. Kemudian, program menjalankan algoritma Binary Search untuk mencari angka tersebut dalam array yang telah diurutkan. Jika angka ditemukan, program akan mencetak pesan yang menyatakan angka tersebut ditemukan pada indeks tertentu. Jika angka 
tidak ditemukan, program akan mencetak pesan yang menyatakan bahwa angka tidak ditemukan dalam data. Dengan demikian, program ini memberikan kemampuan untuk mencari angka dalam array menggunakan algoritma Binary Search setelah melakukan pengurutan menggunakan Selection Sort.

## Unguided 

### 1. [Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!]

```C++
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
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Program tersebut merupakan implementasi algoritma Binary Search untuk mencari keberadaan sebuah huruf dalam sebuah kalimat. Pada awalnya, program meminta pengguna untuk memasukkan sebuah kalimat dan huruf yang ingin dicari. Selanjutnya, program akan melakukan pengurutan 
karakter-karakter dalam kalimat secara ascending. Setelah itu, program menjalankan algoritma Binary Search untuk mencari huruf yang dicari dalam kalimat yang telah diurutkan. Jika huruf tersebut ditemukan, program mencetak pesan yang menyatakan bahwa huruf tersebut ditemukan. Jika huruf tidak ditemukan, program mencetak pesan yang menyatakan bahwa huruf tidak ditemukan dalam kalimat. Dengan demikian, program ini memberikan kemampuan untuk mencari keberadaan sebuah huruf dalam kalimat menggunakan algoritma Binary Search setelah melakukan pengurutan karakter dalam kalimat.

### 2. [Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!]

```C++
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
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Program tersebut merupakan implementasi dari fungsi yang digunakan untuk menghitung jumlah huruf vokal dalam sebuah kalimat. Program ini menggunakan algoritma untuk menghitung jumlah huruf vokal dalam kalimat yang diberikan pengguna. Program pertama-tama mendefinisikan variabel `kalimat` untuk menampung kalimat yang diberikan pengguna. Kemudian, program mendefinisikan fungsi `huruf_vokal()` yang digunakan untuk menghitung jumlah huruf vokal dalam kelimat. 
Dalam fungsi `huruf_vokal()`, program pertama-tama mendefinisikan variabel `count` untuk menampung jumlah huruf vokal dan string `vokal` yang berisi huruf vokal. Setelah itu, program mengubah semua karakter dalam kalimat menjadi huruf kecil menggunakan fungsi `transform()` dari library `algorithm` untuk memastikan pencarian huruf vokal tidak sensitif terhadap huruf besar atau kecil. Program lalu melakukan perulangan melalui setiap karakter dalam kalimat yang telah diubah menjadi huruf kecil dan menghitung jumlah huruf vokal yang ditemukan.
Dalam fungsi `main()`, program pertama-tama menampilkan pesan "Program Menghitung Huruf Vokal" dan meminta pengguna untuk memasukkan kalimat. Program kemudian menghitung jumlah huruf vokal dalam kalimat menggunakan fungsi `huruf_vokal()` dan mencetak hasil perhitungan jumlah huruf vokal. Program akhirnya menampilkan jumlah huruf vokal yang ditemukan dalam kalimat.

### 3. [Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!]

```C++
// Oleh Amanda Windhu Gustyas_2311102121
#include <iostream>
using namespace std;

int main() 
{
    const int n = 10;
    int *data = new int[n] {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int cari = 4;
    int count = 0;

    // Loop melalui elemen-elemen array
    for (int i = 0; i < n; i++) 
    {   
        // Periksa jika elemen array saat ini sama dengan angka yang dicari
         if (data[i] == cari) 
         {

        // Tambahkan hitungan jika ditemukan angka yang dicari
         count++;
         }
     }
    cout << "MENGHITUNG BANYAK ANGKA 4" << endl;
    cout << "Data: 9, 4, 1, 4, 7, 10, 5, 4, 12, 4" << endl;
    cout << "\nJumlah angka " << cari << " dalam data: " << count << endl;
    delete[] data;
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
