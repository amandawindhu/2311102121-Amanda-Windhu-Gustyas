# <h1 align="center">Laporan Praktikum Modul Single and Double Linked List</h1>
<p align="center">Amanda Windhu Gustyas - 2311102121</p>

## Dasar Teori
1) Pengertian Linked List<br/>
    Linked list adalah struktur data yang terdiri dari sekelompok elemen data dengan tipe yang
   sama, di mana setiap elemen terhubung satu sama lain melalui penggunaan pointer. Pointer ini
   merupakan alamat dari elemen data yang disimpan di memori. Dengan menggunakan pointer,
   elemen-elemen dalam linked list dapat terhubung secara logis meskipun tidak berada dalam
   urutan fisik di memori. Linked list terbentuk dari simpul-simpul yang saling terhubung, di
   mana setiap simpul direpresentasikan sebagai struktur (struct) dan tautan (link) yang berupa
   pointer menuju simpul lainnya. Dalam penggunaannya, terdapat dua jenis pointer yang umum
   digunakan, yaitu head (yang menunjukkan alamat pointer pertama) dan tail (yang menunjukkan
   simpul terakhir). Ketika operasi penambahan atau penghapusan simpul dilakukan, nilai dari
   pointer link diubah sesuai dengan perubahan tersebut. Selain itu, pada simpul terakhir,
   nilai dari pointer link biasanya diberi nilai null.<br/>
   
    ![Linked List](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/cdf9728b-a959-47d3-b9f8-bff3f82a9073)

2) Pengertian Single Linked List<br/>
   Single Linked List adalah suatu kumpulan elemen data, juga dikenal sebagai node, dimana
   urutannya ditentukan oleh sebuah pointer. Dalam Single Linked List, terdapat hanya satu
   petunjuk atau pointer yang disebut NEXT. Setiap node (elemen) dalam linked list terdiri dari
   dua bagian utama, yakni INFO yang berisi informasi tentang data yang terkait dengan node
   tersebut, dan NEXT (link field/next pointer field) yang menyimpan alamat dari node (elemen)
   berikutnya yang dituju. Berikut adalah contoh Single Linked List yang terdiri atas 4 node.<br/>

   ![Single Linked List](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/4f99a614-bf6e-4566-a11f-aa559d4b5d5c)<br/>
   Pada node ke-4 field NEXT-nya berisi NULL, artinya node ke-4 tersebut adalah node terakhir.<br/>

3) Pengertian Double Linked List<br/>
   Double Linked List adalah jenis struktur data di mana setiap node (elemen) memiliki referensi ke node (elemen) sebelumnya (PREV) dan node berikutnya (NEXT).
   Beberapa algoritma membutuhkan penggunaan tautan ganda, seperti saat melakukan sorting dan reverse traversing.<br/>
   
   ![Double Linked List](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/f50dcfb1-b9d0-428d-8abd-604688e72628)<br/>
   Tiap node memiliki pointer yang menunjuk ke node sesudahnya dan pointer yang menunjuk ke
   node sebelumnya.<br/>
   Berikut contoh apabila Double Linked List kosong:<br/>
   ![Double Linked List kosong](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/4e6de955-0319-40a4-a292-2afe87a3a794)
   
## Guided 

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
