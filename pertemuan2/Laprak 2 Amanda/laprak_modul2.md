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
Program tersebut adalah contoh program C++ yang menggunakan array tiga dimensi untuk menginputkan dan menampilkan elemen-elemen array. Array tersebut memiliki ukuran 2x3x3. Program ini terdiri dari loop untuk menginputkan nilai-nilai array, loop untuk menampilkan nilai-nilai array, dan loop untuk menampilkan nilai-nilai array dalam format yang lebih terstruktur.

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
Program tersebut merupakan program C++ yang meminta pengguna untuk memasukkan panjang array, kemudian meminta pengguna untuk memasukkan angka-angka ke dalam array. Setelah array terisi, program mencari nilai maksimum di dalam array beserta lokasinya. Nilai maksimum dan lokasinya kemudian ditampilkan kepada pengguna.

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
![SS_Unguided1_Amanda](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/3284bfb9-5d5c-472f-910d-ce984ca1acfd)
Program tersebut merupakan program C++ yang meminta pengguna untuk memasukkan data ke dalam array dengan panjang 10 elemen. Setelah semua data dimasukkan, program memisahkan angka genap dan ganjil dari array tersebut, dan menyimpannya dalam array yang terpisah. Kemudian, program mencetak angka genap dan angka ganjil tersebut.

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
![SS_Unguided2_Amanda](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/782a759c-cd10-4a58-92dc-5caf5f837e11)
Program tersebut adalah program C++ yang menggunakan array tiga dimensi. Program ini meminta pengguna untuk memasukkan nilai ke dalam array tiga dimensi dengan ukuran 2x3x3. Setelah semua nilai dimasukkan, program menampilkan isi array tersebut.

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
![SS_Unguided3_Amanda](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/9c098126-818e-4648-9bb3-b550cc8efed4)
Program tersebut adalah program C++ yang memungkinkan pengguna untuk memasukkan sejumlah elemen ke dalam sebuah array. Setelah memasukkan elemen-elemen tersebut, pengguna dapat memilih dari beberapa opsi yang tersedia, yaitu mencari nilai maksimum, nilai minimum, atau nilai rata-rata dari elemen-elemen array yang telah dimasukkan. Program akan terus menampilkan menu dan memproses pilihan pengguna sampai pengguna memilih untuk keluar.

## Kesimpulan
Array merupakan struktur data yang penting dalam pemrograman untuk menyimpan data dengan tipe sama dan tersusun berurutan dalam memori komputer. Array dibagi menjadi beberapa jenis berdasarkan dimensinya, yaitu array satu dimensi, dua dimensi, multidimensi, empat dimensi, dan lima dimensi.<br/>
* Keuntungan Array:<br/>
1. Memudahkan penyimpanan data homogen dalam jumlah banyak.<br/>
2. Akses data yang efisien dengan menggunakan indeks.<br/>
3. Memudahkan manipulasi data dengan algoritma yang dirancang untuk struktur array.<br/>
* Kekurangan Array:<bt/>
1. Ukuran array harus ditentukan pada saat deklarasi.<br/>
2. Mengubah ukuran array setelah deklarasi bisa jadi rumit.<br/>
3. Kurang efisien untuk menyimpan data heterogen.<br/>

Pemilihan jenis array yang tepat tergantung pada kebutuhan penyimpanan dan manipulasi data dalam program. Array satu dimensi cocok untuk menyimpan data yang tersusun dalam urutan, seperti daftar nama. Array dua dimensi cocok untuk menyimpan data yang berbentuk tabel, seperti matriks. Array multidimensi, empat dimensi, dan lima dimensi cocok untuk menyimpan data yang lebih kompleks dengan dimensi yang lebih banyak. Memahami struktur dan penggunaan array sangat penting untuk mengoptimalkan penyimpanan dan manipulasi data dalam program.

## Referensi
[1] Pratama, M. Aldi. (2024). Penerapan Array Multidimensi untuk Simulasi Sistem Persamaan Diferensial Parsial. [Tesis, Universitas Mitra Indonesia].<br/>
[2] Jurnal Informatika Universitas Gadjah Mada. (2022). Penerapan Array 4 Dimensi untuk Penyimpanan Data Spasial dan Temporal.<br/>
