# <h1 align="center">Laporan Praktikum Modul Array</h1>
<p align="center">Amanda Windhu Gustyas - 2311102121</p>

## Dasar Teori

Array adalah struktur data yang menyimpan sekumpulan data dengan tipe sama, tersusun berurutan dalam memori komputer. Kecocokan array terletak pada organisasinya terhadap data homogen dengan jumlah elemen yang diketahui sejak awal.<br/>
Array dibagi menjadi:<br/>
    1) Array Satu Dimensi<br/>
    Array satu dimensi adalah struktur data yang terdiri dari elemen-elemen dengan tipe data
    sama, tersusun dalam satu baris, dan boleh memiliki nilai yang berbeda-beda. Istilah lain
    untuk array satu dimensi adalah vektor, yang menggambarkan data yang tersusun dalam
    urutan. Deklarasi array satu dimensi menggunakan format Type_Data Nama_Variabel [index],
    di mana Type_Data adalah jenis data elemen, Nama_Variabel adalah nama array, dan index
    adalah penunjuk untuk mengakses elemen array. Contohnya, int A[5] mendeklarasikan array
    dengan tipe data int dan memiliki 5 elemen.<br/>
    2) Array Dua Dimensi<br/>
    Array dua dimensi, sering digambarkan sebagai matriks, merupakan pengembangan dari array
    satu dimensi. Jika array satu dimensi hanya terdiri dari satu baris dengan beberapa kolom
    elemen, maka array dua dimensi memiliki beberapa baris dan beberapa kolom elemen dengan
    tipe data yang sama. Deklarasi array dua dimensi mirip dengan array satu dimensi, namun
    terdapat dua jumlah elemen array di dalam kurung siku dan keduanya boleh tidak sama.
    Contohnya, int A[3][2] mendeklarasikan array A dengan tipe data int yang memiliki 3 baris
    dan 2 kolom.<br/>
    3) Array Multidimensi<br/>
    Aray multidimensi merupakan struktur data yang memungkinkan penyimpanan data dalam bentuk
    struktur yang lebih kompleks, dengan lebih dari dua dimensi. Array ini merupakan perluasan
    dari array satu dan dua dimensi.<br/>
    4) Array Empat Dimensi<br/>
    Array 4 dimensi merupakan struktur data yang memungkinkan penyimpanan data dalam bentuk
    tabel dengan 4 dimensi. Ini merupakan perluasan dari array satu, dua, dan tiga dimensi.        <br/>
    5) Array Lima Dimensi<br/>
    Array 5 dimensi adalah struktur data yang memungkinkan penyimpanan data dalam bentuk tabel
    dengan 5 dimensi. Ini merupakan perluasan dari array satu, dua, tiga, dan empat dimensi.<br/>
    
## Guided 

### 1. [Array Tiga Dimensi]

```C++
#include <iostream>
using namespace std;
// PROGRAM INPUT ARRAY 3 DIMENSI
int main()
{
// Deklarasi array
int arr[2][3][3];
// Input elemen
for (int x = 0; x < 2; x++)
{
for (int y = 0; y < 3; y++)
{
for (int z = 0; z < 3; z++)
{
cout << "Input Array[" << x << "][" << y << "][" <<
z << "] = ";
cin >> arr[x][y][z];
}
}
cout << endl;
}
// Output Array
for (int x = 0; x < 2; x++)
{
for (int y = 0; y < 3; y++)
{
for (int z = 0; z < 3; z++)
{
cout << "Data Array[" << x << "][" << y << "][" << z
<< "] = " << arr[x][y][z] << endl;
}
}
}
cout << endl;
// Tampilan array
for (int x = 0; x < 2; x++)
{
for (int y = 0; y < 3; y++)
{
for (int z = 0; z < 3; z++)
{
cout << arr[x][y][z] << ends;
}
cout << endl;
}
cout << endl;
}
}
```
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

### 2. [Mencari Nilai Maksimal pada Array]

```C++
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
```


## Unguided 

### 1. [Buatlah program untuk menampilkan output seperti berikut dengan data yang diinputkan oleh user!]
![SS 1](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/d647166a-5e19-4801-b639-ffeb943027b1)

```C++
// Oleh Amanda Windhu Gustyas - 2311102121
#include <iostream>
using namespace std;

int main(){
    int arr[10]; // Mendeklarasikan array dengan 10 elemen
    int genap[5], ganjil[5]; // Mendeklarasikan array untuk menyimpan angka genap dan ganjil
    int genapIndex = 0; // Indeks untuk array angka genap
    int ganjilIndex = 0; // Indeks untuk array angka ganjil
    
    // Meminta pengguna untuk memasukkan data array
    cout << "Data Array: ";
    for (int a = 0; a < 10; a++){
        cin >> arr[a];
    }

    // Memisahkan angka genap dan ganjil dari array
    for (int a = 0; a < 10; a++){
        if(arr[a] % 2 == 0){
            genap[genapIndex] = arr[a]; // Menyimpan angka genap ke dalam array angka genap
            genapIndex++;
        } else {
            ganjil[ganjilIndex] = arr[a]; // Menyimpan angka ganjil ke dalam array angka ganjil
            ganjilIndex++;
        }
    }

    // Mencetak angka genap
    cout << "Angka Genap: ";
    for (int a = 0; a < genapIndex; a++){
        cout << genap[a] << " , ";
    }
   cout << endl;

    // Mencetak angka ganjil
    cout << "Angka Ganjil: ";
    for (int a = 0; a < ganjilIndex; a++){
        cout << ganjil[a] << " , ";
    }
    cout << endl;
    return 0;
}
    
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

### 2. [Buatlah program input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!]

```C++
// Oleh Amanda Windhu Gustyas - 2311102121
#include <iostream>
using namespace std;

int main() {
    // Array 3 dimensi
    int arr[2][3][3];

    // Memasukkan nilai ke dalam array
    for (int i = 0; i < 2; i++) {
        for (int a = 0; a < 3; a++) {
            for (int f = 0; f < 3; f++) {
                cout << "Masukkan nilai untuk array[" << i << "][" << a << "][" << f << "] =  ";
                cin >> arr[i][a][f];
            } cout << endl;
        }
    }

    // Menampilkan isi array
    cout << "Isi Array:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int a = 0; a < 3; a++) {
            for (int f = 0; f < 3; f++) {
                cout << arr[i][a][f] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
```
### Output:

### 3. [Buatlah program menu untuk mencari nilai maksimum, minimum dan nilai rata - rata dari suatu array dengan input yang dimasukan oleh user!]

```C++
// Oleh Amanda Windhu Gustyas - 2311102121
#include <iostream>
using namespace std;

int main() {
    int arr[100]; // Mendeklarasikan array dengan ukuran maksimal
    int f;

    // Meminta pengguna untuk memasukkan jumlah elemen array
    cout << "Masukkan jumlah elemen array: ";
    cin >> f;

    // Meminta pengguna untuk memasukkan nilai-nilai array
    cout << "Masukkan " << f << " nilai untuk array:" << endl;
    for (int a = 0; a < f; ++a) {
        cout << "Nilai ke-" << a+1 << ": ";
        cin >> arr[a];
    }

    int pilih;
    int max = arr[0]; // Inisialisasi max dengan nilai pertama dalam array
    int min = arr[0]; // Inisialisasi min dengan nilai pertama dalam array
    double average = 0; // Inisialisasi average dengan nilai awal 0
    do {
        // Menampilkan menu
        cout << "\nMenu:" << endl;
        cout << "1. Cari nilai maksimum" << endl;
        cout << "2. Cari nilai minimum" << endl;
        cout << "3. Cari nilai rata-rata" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                // Mencari nilai maksimum
                for (int a = 1; a < f; ++a) {
                    if (arr[a] > max) {
                        max = arr[a];
                    }
                }
                cout << "Nilai maksimum: " << max << endl;
                break;

            case 2:
                // Mencari nilai minimum
                for (int a = 1; a < f; ++a) {
                    if (arr[a] < min) {
                        min = arr[a];
                    }
                }
                cout << "Nilai minimum: " << min << endl;
                break;

            case 3:
                // Mencari nilai rata-rata
                double sum = 0;
                for (int a = 0; a < f; ++a) {
                    sum += arr[a];
                }
                average = sum / f;
                cout << "Nilai rata-rata: " << average << endl;
                break;
        }
    } while (true); 

    return 0;
}
```
### Output:

## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
