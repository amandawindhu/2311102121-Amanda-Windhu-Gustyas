# <h1 align="center">Laporan Praktikum Modul Linked List Circular dan Non Circular</h1>
<p align="center">Amanda Windhu Gustyas - 2311102121</p>

## Dasar Teori

1. Linked List Non Circular<br/>
   Setiap elemen dalam linked list memiliki dua bagian utama: bagian data yang menyimpan informasi yang ingin disimpan dalam linked list, dan bagian pointer yang menyimpan alamat elemen berikutnya dan sebelumnya
   dalam linked list. Ketika membuat elemen baru, kedua pointer (next dan prev) diinisialisasi dengan nilai NULL, menandakan bahwa elemen baru tidak terhubung dengan elemen lainnya. Selanjutnya, pointer prev
   diarahkan ke elemen sebelumnya dalam linked list, sementara pointer next diarahkan ke elemen berikutnya dalam linked list.<br/>
        Deklasari simpul :<br/>
        ```
        Struct node
        int angka;
        node *next;
        };
       ```
  - Operasi pada linked list non circular<br/>
    a) Tambah Depan<br/>
    Ketika data baru ditambahkan, head (simpul awal) linked list akan diarahkan ke data baru tersebut. Data baru ini kemudian akan menunjuk ke data yang sebelumnya berada di posisi head. Otomatis, data lama akan
    berpindah ke posisi setelah data baru.<br/>
       ```
        void tambahdepan(int x)
        {
        struct titik *baru;
        baru=new titik;
        baru->angka=x;
        baru->berikut=awal;
        awal=baru;
        }
       ```
    b) Tambah Belakang<br/>
    Pada dasarnya, konsepnya mirip dengan antrian, di mana elemen yang pertama masuk adalah yang pertama keluar. Dalam konteks linked list, elemen lama akan tetap berada di awal untuk elemen-elemen baru, sehingga
    elemen pertama yang dimasukkan akan tetap menjadi yang pertama, dan elemen-elemen baru akan terus ditambahkan setelah elemen sebelumnya.<br/>
       ```
        void tambahbelakang(int x)
        {
        struct simpul *baru;
        baru=new simpul;
        baru->angka=x;
        if(awal==NULL){awal=baru;
        }
        else{akhir->berikut=baru;}
        akhir=baru;
        akhir->berikut=NULL;
        }
        sisip_list(awal,ganti,cari);
        }
       ```
    c) Tambah Tengah<br/>
    Penambahan elemen di tengah linked list berguna ketika kita sudah memasukkan beberapa data tetapi kemudian menyadari bahwa ada data yang terlewat untuk dimasukkan dan seharusnya ditempatkan di antara data
    yang sudah dimasukkan sebelumnya.<br/>
       ```
        void sisip_list(struct simpul *first,int x,int posisi
        {
        struct simpul *bantu,*baru;
        baru = new simpul;
        baru->angka=x;
        bantu=first;
        do
        {
        if (posisi!=bantu->angka) 
        {bantu=bantu->berikut;}
        }
        while (bantu!=NULL && posisi!=bantu->angka);
        baru->berikut=bantu->berikut;
        bantu->berikut=baru;
        }
        void sisip_isi_list()
        {
        int cari;
        int ganti;
        cout<<"\nBilangan : "; 
        cin>>ganti;
        cout<<"\nDisipkan setelah : ";
        cin>>cari;
       ```
    d) Hapus Tengah<br/>
    Hapus tengah membutuhkan 2 fungsi yang pertama untuk mengiput data yang akan dihapus dan fungsi yang akan menghapus list. Fungsi ``` carihapus()``` akan menjadi fungsi untuk membawa parameter
    atau nilai yang akan dihapus sementara fungsi ```hapustengah(int info)``` akan menghapus data  yang  sesuai  dengan  isi  dari info yang dibawa oleh fungsi ```carihapus()```.<br/>
       ```
       void hapustengah(int info)
      {
      titik *bantu,*hapus;
      bantu=awal;
      while ((info!=bantu->berikut->angka) && (bantu->berikut!=NULL))
      {
      bantu=bantu->berikut;
      }
      hapus=bantu->berikut;
      bantu->berikut=hapus->berikut;
      delete hapus;
      }
      void carihapus()
      {
      int cari;
      clrscr();
      tampillist();
      cout<<"\nData yang akan dihapus, Bilangan :";
      cin>>cari;
      hapustengah(cari);
      cout<<"\nData menjadi :";
      tampillist();
      }
      ```
    e) Hapus Depan<br/>
    Hapus depan sebenarnya sangat simple karena bisa langsung menghapus ```*awal```, namun disela itu sebelum menghapus ```*awal``` harus mengganti ```*awal``` dengan pointer berikutnya sehingga ketika
    ditampilkan, data masih terlihat.<br/>
       ```
       Void hapusdepan()
       {
       Simpul *hapus;
       Hapus=awal;
       Awal=hapus->berikut;
       Delete hapus;
      }
      ```
   f) Hapus Semua<br/>
    
    
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
