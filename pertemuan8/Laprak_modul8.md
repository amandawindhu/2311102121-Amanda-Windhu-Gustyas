# <h1 align="center">Laporan Praktikum Modul Algoritma Searching</h1>
<p align="center">Amanda Windhu Gustyas - 2311102121</p>

## Dasar Teori

Ada beberapa algoritma yang bisa digunakan untuk melakukan pencarian, salah satunya adalah Sequential Search, yaitu algoritma yang dasar dan simpel dari pencarian, dimana menggunakan metode pencarian data dari paling awal hingga paling akhir dari sebuah list sampai data ditemukan. Selain itu ada algoritma Binary Search, yaitu sebuah list yang sudah terurut kemudian dibagi menjadi dua bagian. Awalnya adalah membandingkan inputan dengan nilai tengah, selanjutnya dibandingkan ke kanan atau ke kiri sesuai dengan urutan listnya.<br/>
- Sequential Search<br/>
  Sequential search adalah cara untuk pencarian data dalam array 1 dimensi. Data yang akan dicari nanti akan ditelusuri dalam semua elemenelemen array dari awal
  sampai akhir, dan data yang dicari tersebut tidak perlu diurutkan terlebih dahulu. Terdapat 2 kemungkinan yang akan terjadi dalam waktu pencarian data
  Sequential Search, diantaranya yaitu:<br/>
  1. Best Case<br/>
     Best case atau kemungkinan terbaik akan terjadi apabila data yang dicari terletak pada index array yang paling depan, sehingga waktu yang dibutuhkan untuk
     mencari data sedikit.<br/>
  2. Worse Case<br/>
     Worse case atau kemungkinan terburuk akan terjadi apabila data yang dicari terletak pada index array yang paling akhir, sehingga waktu yang
     dibutuhkan untuk mencari data akan sangat lama.<br/>
  Untuk meningkatkan efisiensi pencarian data pada Sequential Search dapat dilakukan dengan cara menghentikan looping dengan menggunakan BREAK apabila data yang
  dicari sudah ketemu.<br/>
![Proses_pencarian_sequentialsearch](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/3f32f078-fa3e-45ef-b7ec-05b2ad3759d0)<br/>
- Langkah-langkah pencarian dengan sequential search:<br/>
  1. Melakukan perbandingan beruntun pada kumpulan data dengan menggunakan keyword atau kata kunci yang akan dicari.<br/>
  2. Pencarian ini melakukan looping atau pengulangan dari data pertama hingga jumlah data ke-n.<br/>
  3. Setiap perulangan dilakukan pencocokan data dengan kata kunci yang dicari.<br/>
  4. Apabila terdapat kecocokan data dengan kata kunci yang di cari maka data berhasil ditemukan dan pencarian di hentikan, sebaliknya apabila tidak ada
     kecocokan data hingga data terakhir maka pencarian dihentikan dan data tidak ditemukan.<br/>
  
- Binary Search<br/>
  Binary Search adalah cara untuk pencarian data pada array yang sudah terurut. karena salah satu syarat dalam Binary Search adalah data sudah dalam keadaan
  terurut, dengan kata lain apabila data belum dalam keadaan terurut, pencarian Binary tidak dapat dilakukan. Binary Search ini dilakukan untuk:<br/>
  1. Memperkecil jumlah operasi perbandingan yang harus dilakukan antara data yang dicari dengan data yang ada didalam tabel, khususnya untuk jumlah data yang
     sangat besar ukurannya.<br/>
  2. Beban komputasi lebih kecil karena pencarian dilakukan dari depan, belakang dan tengah.<br/>
  3. Prinsip dasarnya adalah melakukan proses pembagian ruang pencarian secara berulang-ulang sampai data ditemukan atau sampai pencarian tidak dapat dibagi lagi
     (berarti terdapat kemungkinan data tidak ditemukan).<br/>
     
![Langkah_Kerja_BinarySearch](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/8a823f08-5276-4aef-9f9c-32676a7a6214)<br/>
- Berikut langkah-langkah pencarian binary search:<br/>
  1. Mengurutkan data terlebih dahulu bisa secara ascending (dari depan ke belakang) atau descending (dari belakang ke depan).<br/>
  2. Membagi dua array atau keseluruhan data. Apabila data yang dicari lebih kecil dari data yang terletak di tengah, maka pencarian data akan berlanjut kesebelah
     kiri. Apabila data yang dicari lebih besar dari data terletak ditengah, maka pencarian data akan berlanjut kesebelah kanan kemudian proses pencarian
     tersebut akan terus berulang sampai data yang dimaksud atau dicari dapat ditemukan<br/>
     
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
Program tersebut merupakan implementasi sederhana dari algoritma Sequential Search, yang digunakan untuk mencari angka tertentu dalam suatu array. Dalam kasus ini, program mencari sebuah array dengan 10 elemen yang berisi nilai 9, 4, 1, 7, 5, 12, 4, 13, 4, dan 10. Kemudian, program melakukan iterasi melalui setiap elemen array secara berurutan untuk mencari angka yang dicari. Jika angka ditemukan, program akan menandai hasilnya dan mencetak pesan yang menyatakan bahwa angka tersebut ditemukan beserta indeksnya. Jika angka tidak ditemukan, program akan mencetak pesan yang menyatakan bahwa angka tidak ditemukan dalam data. Dengan demikian, program ini memberikan pengguna informasi tentang apakah angka yang dicari ada dalam array dan di indeks mana angka tersebut ditemukan.

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
#include <conio.h>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

string kalimat;
char cari;

// Fungsi untuk melakukan binary search pada string
void binarySearch(){
    int awal, akhir, tengah;
    bool b_flag = false; // Flag untuk menandakan apakah data ditemukan
    awal = 0;
    akhir = kalimat.length() - 1;
    while (!b_flag && awal <= akhir)
    {
        tengah = (awal + akhir)/2;
        if (kalimat[tengah] == cari)
        {
            b_flag = true;  // Data ditemukan
        } else if (kalimat[tengah] <  cari)
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
    cout << "---Cari Huruf---"<<endl;
    cout << "Masukkan kalimat : ";
    getline(cin, kalimat);
    cout << "Masukkan huruf yang ingin dicari : ";
    cin >> cari;

    // Mengurutkan kalimat
    sort(kalimat.begin(), kalimat.end());

    cout << "\nKalimat diurutkan : " << kalimat << endl;

    cout << "\nBinary Search untuk mencari huruf '" << cari << "' dalam kalimat '" << kalimat << "' : ";
    binarySearch(); // Memanggil fungsi untuk melakukan pencarian biner
    _getche(); // Menunggu pengguna menekan tombol sebelum keluar
    return 0;
}
```
#### Output:
![SS_Unguided1](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/c049b81d-1560-41fb-88a0-f32a1fa2f6be)<br/>
![SS_Unguided1_!](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/7312ba95-85bc-4551-b502-1a8664a37cfb)<br/>

Program tersebut merupakan implementasi algoritma Binary Search untuk mencari huruf dalam sebuah kalimat. Program meminta pengguna untuk memasukan sebuah kalimat dan huruf yang ingin dicari. Kemudian, program akan mencari huruf tersebut dalam kalimat menggunakan algoritma Binary Search dan menampilkan hasilnya.<br/>
Pertama-tama program mengurutkan kalimat yang diberikan pengguna secara alfabetis menggunakan fungsi dari `sort` `algorithm`, lalu memanggil fungsi untuk melakukan pencarian huruf dalam kalimat yang telah diurutkan `binarySearch`. Fungsi menggunakan algoritma Binary Search untuk mencari huruf yang ingin dicari. Algoritma ini bekerja dengan cara membagi kalimat menjadi dua bagian, kemudian mencari huruf di bagian yang dipilih. Proses ini diulangi hingga huruf ditemukan atau kalimat tidak ditemukan `binarySearch`. Jika huruf ditemukan, program akan menampilkan indeks huruf yang ditemukan. Jika tidak ditemukan, program akan menampilkan "DATA TIDAK DITEMUKAN".

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
![SS_Unguided_2](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/700c7b63-0965-490a-920e-0d355791889b)

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
![SS_Unguided_3](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/65681815-2256-4e2c-bbe3-f6dbd3ac909b)

Program tersebut merupakan implementasi dari algoritma Sequential Search untuk menghitung banyak angka dalam sebuah array. Dalam kasus ini, program mencari angka 4 dalam array yang berisi nilai 9, 4, 1, 4, 7, 10, 5, 4, 12, dan 4. Program pertama-tama mendefinisikan variabel konstan `n` dengan nilai 10 dan mendefinisikan array `data` yang berisi nilai-nilai. Kemudian, program mendefinisikan variabel `cari` dengan nilai 4 dan variabel `count` untuk menampung jumlah angka 4. Program lalu melakukan perulangan setiap elemen dalam array `data` dan memeriksa jika elemen saat ini sama dengan nilai `cari`. Jika elemen array saat ini sama dengan nilai `cari`, program akan meningkatkan nilai `count` untuk menampung jumlah angka 4. Setelah perulangan selesai, program mencetak hasil perhitungan jumlah angka 4 dalam array `data`. Program akhirnya menghapus memori yang dialokasikan untuk array `data` menggunakan fungsi `delete[]`.

## Kesimpulan
Secara keseluruhan, Sequential Search cocok digunakan untuk dataset kecil atau ketika data tidak terurut. Keuntungannya adalah kesederhanaannya dan tidak membutuhkan data yang terurut, tetapi kelemahannya adalah efisiensinya yang rendah untuk dataset besar. Di sisi lain, Binary Search sangat efisien untuk dataset besar, tetapi memerlukan data yang sudah terurut. Keuntungannya adalah jumlah operasi perbandingan yang lebih sedikit dan beban komputasi yang lebih rendah. Namun, jika data belum terurut, algoritma ini tidak dapat digunakan langsung, dan waktu tambahan diperlukan untuk mengurutkan data terlebih dahulu.<br/>
Memilih algoritma pencarian yang tepat bergantung pada karakteristik dataset dan kebutuhan spesifik dari aplikasi yang sedang dikembangkan. Sequential Search menawarkan kesederhanaan dan fleksibilitas, sedangkan Binary Search menawarkan kecepatan dan efisiensi pada dataset besar yang terurut.<br/>

## Referensi
[1] Markuci, D., & Prianto, C. (2022). Analisis Perbandingan Penggunaan Algoritma Sequential Search dan Binary Search pada Aplikasi Surat Perjalanan Dinas. Jurnal Informatika dan Komputer, 6(1), 110.<br/>
[2] Religia, Y. (2019). Analisis Algoritma Sequential Search dan Binary Search pada Big Data. Pelita Teknologi: Jurnal Ilmiah Informatika, Arsitektur dan Lingkungan, 14(1), 74-79.<br/>
[3] Wahyuni, W. S., Andryana, S., & Rahman, B. (2022). Penggunaan Algoritma Sequential Searching pada Aplikasi Perpustakaan Berbasis Web. JIPI (Jurnal Ilmiah Penelitian dan Pembelajaran Informatika), 7(2), 294-302. E-ISSN: 2540-8984.<br/>
