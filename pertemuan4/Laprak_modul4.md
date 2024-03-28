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
    Penghapusan seluruh elemen merupakan metode penghapusan paling sederhana, di mana kita hanya perlu menentukan kapan pointer penghapusan menunjuk ke NULL, dan pada titik tersebut penghapusan dihentikan.<br/>
       ```
       void hapus()
       {
      simpul *hapus;
      hapus=awal;
      while(hapus!=NULL)
      {
      awal=hapus->berikut;
      delete hapus;
      hapus=awal;
      }
      }
      ```
2. Linked List Circular<br/>
   Linked list circular adalah tipe dari daftar tautan di mana node terakhir dari daftar menunjuk kembali ke node pertama. Pada single atau double linked list, node terakhir mengandung penunjuk NULL karena tidak
   ada node berikutnya, sedangkan pada linked list circular, penunjuk "next" dari node terakhir berisi alamat dari node pertama. Oleh karena itu, disebut sebagai linked list circular. Sebuah linked list circular
   memiliki node "start", tetapi tidak memiliki node "end". Dalam linked list circular semua node terhubung dalam lingkaran yang kontinu.<br/>
      Deklarasi simpul :<br/>
      ```
      struct node{
      int angka;
      node *next;
      };
      ```
   - Operasi pada linked list circular<br/>
     a) Tambah Depan<br/>
        ```
        void insertDepan(string data)
        {
        buatNode(data);
        if (isEmpty() == 1)
        {
        head = baru;
        tail = head;
        baru->next = head;
        }
        else
        {
        while (tail->next != head)
        {
        tail = tail->next;
        }
        baru->next = head;
        head = baru;
        tail->next = head;
        }
        }
        ```
     b) Pengecekan Kondisi<br/>
        ```
        baru->next = head;
        head = baru;
        tail->next = head;
        }
        }
        int isEmpty()
        {
        if (head == NULL)
        return 1;
        else
        return 0;
        }
        ```
     c) Hapus Belakang<br/>
        ```
        void hapusBelakang()
        {
        if (isEmpty() == 0)
        {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
        head = NULL;
        tail = NULL;
        delete hapus;
        }
        else
        {
        while (hapus->next != head)
        {
        hapus = hapus->next;
        }
        while (tail->next != hapus)
        {
        tail = tail->next;
        }
        tail->next = head;
        hapus->next = NULL;
        delete hapus;
        }
        }
        ```
     d) Tampil Data<br/>
        ```
        void tampil()
        {
        if (isEmpty() == 0)
        {
        tail = head;
        do
        {
        cout << tail->data << ends;
        tail = tail->next;
        }
        while (tail != head);
        cout << endl;
        }
        }
        ```
        
## Guided 

### 1. Linked List Non Circular

```C++
// Oleh Amanda Windhu Gustyas_2311102121
#include <iostream>
using namespace std;
/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node
{
    int data;
    Node *next;
};
Node *head;
Node *tail;
// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}
// Tambah Depan
void insertDepan(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}
// Tambah Belakang
void insertBelakang(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}
// Hitung Jumlah List
int hitungList()
{
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
// Tambah Tengah
void insertTengah(int data, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
// Hapus Depan
void hapusDepan()
{
    Node *hapus;
    if (isEmpty() == false)
    {
        if (head->next != NULL)
        {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Belakang
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false)
    {
        if (head != tail)
        {
            hapus = tail;
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }

    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Tengah
void hapusTengah(int posisi)
{
    Node *bantu, *hapus, *sebelum;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                sebelum = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        sebelum->next = bantu;
        delete hapus;
    }
}
// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == 0)
    {
        head->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Tengah
void ubahTengah(int data, int posisi)
{
    Node *bantu;
    if (isEmpty() == 0)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
        }
        else
        {
            cout << "Posisi bukan posisi tengah" << endl;
            bantu = head;
            int nomor = 1;
            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = data;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Belakang
void ubahBelakang(int data)
{
    if (isEmpty() == 0)
    {
        tail->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus List
void clearList()
{
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
// Tampilkan List
void tampil()
{
    Node *bantu;
    bantu = head;
    if (isEmpty() == false)
    {
        while (bantu != NULL)
        {
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
int main()
{
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7, 2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    return   0;
}
```
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

### 2. Linked List Circular

```C++
// Oleh Amanda Windhu Gustyas_2311102121
#include <iostream>
using namespace std;

// Deklarasi Struct Node
struct Node
{
    string data;
    Node* next;
};

Node* head, * tail, * baru, * bantu, * hapus;

void init()
{
    head = NULL;
    tail = head;
}

// Pengecekan
int isEmpty()
{
    if (head == NULL)
        return 1; // true
    else
        return 0; // false
}

// Buat Node Baru
void buatNode(string data)
{
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// Hitung List
int hitungList()
{
    bantu = head;
    int jumlah = 0;
    while (bantu != NULL)
    {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}

// Tambah Depan
void insertDepan(string data)
{
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah Belakang
void insertBelakang(string data)
{
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        tail->next = baru;
        baru->next = head;
    }
}

// Tambah Tengah
void insertTengah(string data, int posisi)
{
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        baru->data = data;
        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Depan
void hapusDepan()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
            delete hapus;
        }
        else
        {
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
            delete hapus;
        }
        else
        {
            while (hapus->next != head)
            {
                hapus = hapus->next;
            }
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi)
{
    if (isEmpty() == 0)
    {
        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void clearList()
{
    if (head != NULL)
    {
        hapus = head->next;
        while (hapus != head)
        {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
    }
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil()
{
    if (isEmpty() == 0)
    {
        tail = head;
        do
        {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head);
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

int main()
{
    init();
    insertDepan("Ayam ");
    tampil();
    insertDepan("Bebek ");
    tampil();
    insertBelakang("Cicak ");
    tampil();
    insertBelakang("Domba ");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi ", 2);
    tampil();
    hapusTengah(2);
    tampil();
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
[1] Kurniman Putra, A. (2019). List linier (linked list) dan variasinya. Dalam Struktur Data (hal. 19). Fakultas Komputer. UMitra.<br/>
[2] Aksu, M., & Karci, A. (2019). Skip Ring/Circular Skip List: Circular Linked List Based New Data Structure. Computer Engineering and Intelligent Systems, 6(5), 35.<br/>

