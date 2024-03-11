# <h1 align="center">Laporan Praktikum Modul 1 Tipe Data</h1>
<p align="center">Amanda Windhu Gustyas - 2311102121</p>


## Dasar Teori

Tipe data adalah kategori yang membantu komputer memahami jenis data yang disimpan dalam variabel. Hal ini memungkinkan komputer untuk memproses data dengan cara yang tepat dan menghindari kesalahan. Berikut ada tipe data yang akan dipelajari : 

1. Tipe Data Primitif<br/>
Tipe data primitif adalah tipe data yang sederhana dan disediakan oleh bahasa pemrograman. Contoh tipe data primitif :<br/>
    a. Int merupakan tipe data numerik untuk menyimpan bilangan bulat.<br/>
    b. Float merupakan tipe data untuk menyimpan bilangan desimal.<br/>
    c. Char adalah karakter tunggal yang pendefinisiannya di awal dan di akhir menggunakan     
       tanda petik tunggal.<br/>
    d. Boolean merupakan tipe data yang terdiri dari dua nilai saja, yaitu true dan false.<br/>

2. Tipe Data Abstrak<br/>
Tipe data abstrak atau tipe data yang dikenal Abstrack data Type (ADT) adalah suatu tipe data yang merujuk pada sejumlah bentuk struktur data yang memiliki kegunaan serupa. TDA berfokus pada apa yang dapat dilakukan dengan struktur data, bukan bagaimana strukturnya diimplementasikan dalam memori komputer.

3. Tipe Data Koleksi<br/>
Tipe data koleksi (Collection Data Type) adalah adalah tipe data yang digunakan untuk menyimpan dan mengelompokan beberapa data dengan jenis yang sama atau berbeda. Berikut merupakan tipe data koleksi yang umum digunakan :<br/>
    a. Array merupakan kumpulan data yang bertipe sama yang menggunakan nama yang sama.<br/>
    b. Vector adalah struktur data yang sama dengan array untuk menyimpan data dalam bentuk
       elemen-elemen yang alokasi memorinya dilakukan otomatis dan bersebelahan.<br/>
    c. Map adalah tipe data yang menyyimpan data berdasarkan pasangan key-value.<br/>

## Guided 

### 1. [Tipe Data Primitif]

```C++
#include <iostream> // untuk operasi input output
#include <iomanip> // untuk pemformatan output fixed dan setprecision
using namespace std; // agar elemen cout dan cin dapat langsung ditulis tanpa menggunakan std

int main()
{
    char op_amanda; // deklarasi variabel 'op' bertipe data char
    float num1_121, num2_121; // deklarasi variabel 'num1', 'num2' bertipe data float
    // menampilkan pesan untuk menginputkan operator
    cout << "Enter operator (+, -, *, /): "; 
    cin >> op_amanda;
    // menampilkan pesan untuk menginputkan dua operand
    cout << "Enter two operands: ";
    cin >> num1_121 >> num2_121;
    // statement switch-case
    switch (op_amanda)
    {
    // jika pengguna menginputkan +
    case '+':
        cout << "Result: " << num1_121 + num2_121;
        break;
    // jika pengguna menginputkan -
    case '-':
        cout << "Result: " << num1_121 - num2_121;
        break;
    // jika pengguna menginputkan *
    case '*':
        cout << "Result: " << num1_121 * num2_121;
        break;
    // jika pengguna menginputkan /
    case '/':
        if (num2_121 != 0)
        {
            cout << "Result: " << fixed << setprecision(2) << num1_121 / num2_121;
        }
        else
        {
            cout << "Error! Division by zero is not allowed.";
        }
        break;
    // jika pengguna menginputkan operator selaain +, -, *, /, maka pesan kesalahan akan ditampilkan
    default:
        cout << "Error! Operator is not correct";
    } 
    return 0; // mengembalikan nilai 0
}
'''
Kode di atas adalah kode hitung, kurang, kali, dan bagi dua bilangan yang diinputkan oleh user. Kode diatas menggunakan tipe data primitif char dan float.

### 2. [Tipe Data Abstrak]

```C++
#include <stdio.h> // menyediakan fungsi standar seperti printf
#include <string.h> // menyediakanfungsi untuk manipulasi string seperti strcpy

// deklarasi struct
struct Mahasiswa_121_amanda
{
    char name_amanda[50];
    char address_amanda[100];
    int age_amanda;
};
int main()
{

// deklarasi variabel-variabel bertipe struct 
struct Mahasiswa_121_amanda mhs1, mhs2;
// mengisi nilai ke struct
strcpy(mhs1.name_amanda, "Dian");
strcpy(mhs1.address_amanda, "Mataram");
mhs1.age_amanda = 22;
strcpy(mhs2.name_amanda, "Bambang");
strcpy(mhs2.address_amanda, "Surabaya");
mhs2.age_amanda = 23;

// mencetak isi struct
printf("## Mahasiswa 1 ##\n");
printf("Nama: %s\n", mhs1.name_amanda);
printf("Alamat: %s\n", mhs1.address_amanda);
printf("Umur: %d\n", mhs1.age_amanda);
printf ("\n");
printf("## Mahasiswa 2 ##\n");
printf("Nama: %s\n", mhs2.name_amanda);
printf("Alamat: %s\n", mhs2.address_amanda);
printf("Umur: %d\n", mhs2.age_amanda);
return 0; // mengembalikan nilai 0
}
```
Kode di atas digunakan untuk menampilkan isi dari fungsi struct.

### 3. [Tipe Data Koleksi]

```C++
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
'''
Kode di atas digunakan untuk menampilkan isi dari sebuah array, dimana output yang dihasilkan berupa bilangan yang sudah dimasukkan kedalam index.

## Unguided 

### 1. [Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!]

```C++
#include <iostream> // untuk operasi input output
using namespace std; //  // agar elemen cout dan cin dapat langsung ditulis tanpa menggunakan std

int main() {
    int pilih_121_amanda; // deklarasi variabel pilih bertipe int untuk menyimpan pilihan menu pengguna
    float panjang_121, lebar_121, tinggi_121, jari2_121; // deklarasi variabel panjang, lebar, tinngi, jari2 bertipe data float untuk menyimpan nilai tersebut
    float vb_amanda, vl_amanda; // deklarasi variabel vb, vl bertipe float untuk menyimpan nilai volume balok dan volume lingkaran
    
    cout <<" <<<< M E N U >>>>\n"; // menampilkan output menu
    cout <<"\n";
    cout <<"1. Menghitung Volume balok\n"; // menampilkan output 1. menghitung volume balok
    cout <<"2. Menghitung Volume Lingkaran\n"; // menampilkan output 2. menghitung volume lingkaran
    cout <<"\n";
    cout <<"Pilih Nomor (1/2) ?"; // menampilkan output pilih nomor (1/2) ?
    cin >> pilih_121_amanda; // input pilih untuk meminta pengguna memilih nomor 1/2
    cout << "\n";

    switch(pilih_121_amanda){ // pernyataan switch-case berdasarkan nilai variabel pilih
        case 1: // meminta input panjang, lebar, dan tinngi balok
            cout <<"Panjang balok :";
            cin >> panjang_121;
            cout <<"Lebar balok : ";
            cin >> lebar_121;
            cout <<"Tinggi balok : ";
            cin >> tinggi_121;
            vb_amanda = panjang_121 * lebar_121 * tinggi_121; // menghitung volume balok
            cout << "Volume Balok = " << vb_amanda; // menampilkan hasil volume balok
            break; // menghentikan eksekusi
        case 2: // meminta input jari-jari lingkaran
            cout <<"Jari - jari lingkaran : ";
            cin >> jari2_121;
            vl_amanda = 3.14 * jari2_121 * jari2_121; // menghitung volume lingkaran
            cout <<"Volume Lingkaran = " << vl_amanda; // menampilkan hasil volume lingkaran
            break; // menghentikan eksekusi
    }

    return 0; // mengembalikan nilai 0
}
```
#### Output:
![Screenshot Output Unguided 1] ![image](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/219ad76e-8451-4273-b8e4-1d2b91842507) 
(![Screenshot Output Unguided 1](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/c704bcfc-5414-40b8-8087-130024dec778)
Kode di atas digunakan untuk mencetak teks " 1. Menghitung volume balok dan 2. menghitung volume lingkaran". User akan diminta memilih antara menu 1 atau 2 yang merupakan tipe data integer. Kemudian hasil volumenya berupa tipe data float. 
 
Kesimpulan Tipe Data Primitif<br/>
Tipe data primitif adalah tipe data yang tidak bisa diubah nilainya, contohnya integer, float, char, dan boolean.

### 2. [Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya!]

```C++
// contoh program class
#include <iostream> // untuk operasi input output
using namespace std; // agar elemen cout dan cin dapat langsung ditulis tanpa menggunakan std

class Kalkulasi_amanda_121 { //deklarasi class
private:
    int a, b, c; //deklarasi tiga variabel tipe data integer

public:
    Kalkulasi_amanda_121(int d, int e, int f) : a(d), b(e), c(f) {} //konstruktor class dengan tiga parameter ('d', 'e', 'f') dan menginisialisasi variabel ('a', 'b', 'c') menggunakan daftar inisialisasi ( a(d), b(e), c(f))

    int kali_121() { //mengembalikan nilai integer
        return a * b * c; //menghitung perkalian dari ketiga variabel dan mengembalikan hasilnya dengan pernyataan return
    }
};

int main() {
    Kalkulasi_amanda_121 obj(31, 2, 23); //pembuatan objek 
    cout << obj.kali_121() << endl; //pemanggilan objek
    return 0; //mengembalikan nilai 0
}
```

```C++
// contoh program struct
#include <iostream> // untuk operasi input output
#include <string> // memungkinkan program menggunakan tipe data string
using namespace std; // agar elemen cout dan cin dapat langsung ditulis tanpa menggunakan std

struct Buku_amanda_windhu_gustyas // deklarasi struct dengan nama buku yang memiliki 4 anggota bertipe data string, string, int, float
{
    string judul_121;
    string penulis_121;
    int tahun_terbit_121;
    float harga_121;
};
 
int main(){
     Buku_amanda_windhu_gustyas buku1; // pengisian nilai ke variabel 'buku1'
    buku1.judul_121 = "Bumi"; 
    buku1.penulis_121 = "Tere Liye"; // 
    buku1.tahun_terbit_121 = 2014;
    buku1.harga_121 = 95000.0;

    cout << "Judul: " << buku1.judul_121 << endl; // menampilkan hasil judul buku yang tersimpan dalam variabel buku1
    cout << "Penulis: " << buku1.penulis_121 << endl; // menampilkan hasil nama penulis yang tersimpan dalam variabel buku1
    cout << "Tahun terbit: " << buku1.tahun_terbit_121 << endl; // // menampilkan hasil tahun terbit yang tersimpan dalam variabel buku1
    cout << "Harga: Rp " << buku1.harga_121 << endl; // menampilkan hasil harga yang tersimpan dalam variabel buku1

    return 0; // mengembalikan nilai 0
}
```
### Output Class:
![Screenshot Output Unguided 2 Class](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/2635ff83-7013-4964-bd2b-26277e824058)
Kode di atas adalah kode kalkulasi sederhana yang menggunakan class untuk menghitung perkalian dari tiga variabel a, b, c dengan nilai 31, 2, 23, class kalkulasi_amanda_121 mendeklarasikan class bernama Kalkulasi_amanda_121, variabel a, b, dan c dideklarasikan sebagai variabel privat, dan fungsi kali_121() dideklarasikan sebagai fungsi public.
### Output Struct:
![Screenshot Output Unguided 2 Struct](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/a865d075-84e8-432f-8212-e4c31facdd8f)
Kode di atas menampilkan penggunaan struct untuk menyimpan data buku. Struct membantu dalam mengelompokkan data terkait dan mudah diakses, struct Buku_amanda_windhu_gustyas mendeklarasikan struct bernama Buku_ amanda_windhu_gutyas.

A. Fungsi Class<br/>
Class untuk membangun berbagai objek dengan kemiripan dalam data, fungsi, dan relasi sehingga mempermudah pengelolaan data.

B. Fungsi Struct<br/>
Struct berguna untuk mengelompokkan data terkait dalam pemrograman, struct umumnya tidak memiliki enkapsulasi data yang ketat seperti class, yang artinya anggota struct bisa langsung diakses dari luar, sedangkan class biasanya diakses melalui metode.

### 3. [Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map!]

```C++
#include <iostream> // untuk operasi input output
#include <map> // untuk menyimpan data dalam struktur pasangan key-value
#include <string> // memungkinkan program menggunakan tipe data string

using namespace std; // agar elemen cout dan cin dapat langsung ditulis tanpa menggunakan std

struct Pemesanan_amanda { // deklarasi struct dengan nama Pemesanan
    string penumpang_121;
    string nomor_121;
    string stasiun_asal_121;
    string stasiun_tujuan_121;
    string tgl_keberangkatan_121;
};

int main() {
    map<string, Pemesanan> pemesanan_tiket_kereta; // deklarasi variabel 'pemesanan_tiket_kereta' bertipe map dengan key bertipe string dan value bertipe 'Pemesanan'
   // menambahkan data pemesanan tiket ke dalam 'pemesanan_tiket_kereta'
    pemesanan_tiket_kereta["310805"] = {"Amanda Windhu", "A11", "Semarang", "Purwokerto", "2022-02-27"}; 
    pemesanan_tiket_kereta["291205"] = {"Diego Valdano", "C8", "Malang", "Kroya", "2023-03-06"};

   // untuk mencetak semua data pemesanan tiket
    cout << "\nSemua Data Pemesanan Tiket:" << endl;
    // const auto& memastikan agar data tidak diubah dalam loop
    for (const auto& [nomor_pemesanan, detail] : pemesanan_tiket_kereta) { // loop for menggunakan range-based for loop
    // didalam loop 'for', program mencetak informasi mengenai setiap pemesanan tiket
        cout << "Nomor Pemesanan: " << nomor_pemesanan << endl;
        cout << "Nama Penumpang: " << detail.penumpang_121 << endl;
        cout << "Nomor Kursi: " << detail.nomor_121 << endl;
        cout << "Stasiun Asal: " << detail.stasiun_asal_121 << endl;
        cout << "Stasiun Tujuan: " << detail.stasiun_tujuan_121 << endl;
        cout << "Tanggal Keberangkatan: " << detail.tgl_keberangkatan_121 << endl;
        cout << endl;
    }

    return 0; // mengembalikan nilai 0
}
```
### Output:
![Screenshot Output Unguided 3](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/9d2dc5e7-98e5-4f25-91db-1893c20ba0f6)
Kode di atas menampilkan penggunaan strutur data struct dan map untuk menyimpan data pemesanan tiket kereta. struct Pemesanan_amanda mendeklrasikan struktur bernama Pemesanan_amanda dengan 5 anggota yang bertipe data string. map<string, Pemesanan_amanda> pemesanan_tiket_kereta mendeklarasikan variabel pemesanan_tiket_kereta bertipe map dengan key bertipe string (nomor pemesanan) dan value bertipe Pemesanan_amanda. Dua contoh data pemesanan tiket ditambahkan ke pemesanan_tiket_kereta dengan key nomor pemesanan.

Perbedaan Array dengan Map :<br/>
1. Struktur<br/>
   - Array deretan elemennya berurutan<br/>
   - Map elemenya disimpan dalam struktur data yang lebihh kompleks, seperti hash-table.     
   Koleksi pasangan berupa key-value.<br/>
2. Kemampuan<br/>
   - Array tidak memiliki kemampuan bawaan untuk mencari elemen berdasarkan nilai.<br/>
   - Map menyediakan fungsi bawaan untuk mencari, menambahkan, dan menghapus elemen<br/>
   berdasarkan key dan value.
3. Akses Data<br/>
   - Array menggunakan indeks.
   - Map menggunakan key.

##  Kesimpulan 
Pembelajaran kali ini mempelajari 3 tipe data, yaitu primitif, abstrak, dan koleksi. 
Tipe data primitif contohnya int, float, char, dan boolean.
Tipe data asbtrak contohnya class dan struct.
Tipe data koleksi contohnya array, map, dan vector.
Mempelajari tipe data merupakan hal penting bagi programer, pemahaman yang baik tentang tipe data membantu dalam membangun program yang lebih handal, efisien, dan mudah dipahami.

## Referensi
[1] Dwi Putra, Muhammad Taufik, Deden Paradeka, dan Ana Rahma Yuniarti. (2022). Belajar Dasar Pemrograman dengan C++. Bandung: Widina. <br/>
[2] Triase (2020). Struktur Data. Medan: Universitas Islam Negeri Sumatera Utara.
