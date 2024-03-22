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

### 1. Single Linked List

```C++
// Oleh Amanda Windhu Gustyas-2311102121
#include <iostream>
using namespace std;

///PROGRAM SINGLE LINKED LIST NON-CIRCULAR
//Deklarasi Struct Node
struct Node{
    int data;
    Node *next;
    };
    Node *head;
    Node *tail;

//Inisialisasi Node
void init(){
    head = NULL;
    tail = NULL;
    }

// Pengecekan
bool isEmpty(){
    if (head == NULL)
    return true;
    else
    return false;
    }

//Tambah Depan
void insertDepan(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
        baru->next = head;
        head = baru;
    
    }
}

//Tambah Belakang
void insertBelakang(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
    tail->next = baru;
    tail = baru;
    }
}

//Hitung Jumlah List
int hitungList(){
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while( hitung != NULL ){
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

//Tambah Tengah
void insertTengah(int data, int posisi){
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" <<
endl;
    }
    else{
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;

        // tranversing
        bantu = head;
        int nomor = 1;
    while( nomor < posisi - 1 ){
        bantu = bantu->next;
        nomor++;
    }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

//Hapus Depan
void hapusDepan() {
    Node *hapus;
    if (isEmpty() == false){
        if (head->next != NULL){
            hapus = head;
            head = head->next;
        delete hapus;
    }
else{
    head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}

//Hapus Belakang
void hapusBelakang() {
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false){
        if (head != tail){
            hapus = tail;
            bantu = head;
            while (bantu->next != tail){
        bantu = bantu->next;
    }
    tail = bantu;
    tail->next = NULL;
        delete hapus;
    }
    else{
        head = tail = NULL;
            }
        }       
    else{
        cout << "List kosong!" << endl;
    }
}

//Hapus Tengah
void hapusTengah(int posisi){
    Node *hapus, *bantu, *bantu2;
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        int nomor = 1;
        bantu = head;
    while( nomor <= posisi ){
    if( nomor == posisi-1 ){
        bantu2 = bantu;
    }
    if( nomor == posisi ){
        hapus = bantu;
    }
        bantu = bantu->next;
        nomor++;
    }
        bantu2->next = bantu;
    delete hapus;
    }
}

//Ubah Depan
void ubahDepan(int data){
    if (isEmpty() == false){
        head->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}

//Ubah Tengah
void ubahTengah(int data, int posisi){
    Node *bantu;
    if (isEmpty() == false){
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi di luar jangkauan" << endl;
}
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
}
    else{
    bantu = head;
        int nomor = 1;
    while (nomor < posisi){
    bantu = bantu->next;nomor++;
    }
    bantu->data = data;
    }
}
    else{
        cout << "List masih kosong!" << endl;
    }
}

//Ubah Belakang
void ubahBelakang(int data){
    if (isEmpty() == false){
        tail->data = data;
    }
        else{
            cout << "List masih kosong!" << endl;
    }
}

//Hapus List
void clearList(){
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL){
    hapus = bantu;bantu = bantu->next;
    delete hapus;
    }
    head = tail = NULL;
        cout << "List berhasil terhapus!" << endl;
    }
//Tampilkan List
    void tampil(){
    Node *bantu;
    bantu = head;
    if (isEmpty() == false){
    while (bantu != NULL){
        cout << bantu->data << ends;
    bantu = bantu->next;
    }
    cout << endl;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
    int main(){
    init();
    insertDepan(3);tampil();
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
    insertTengah(7,2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
        return 0;
 }
```
Program tersebut adalah implementasi dari sebuah single linked list non-circular dalam bahasa pemrograman C++. Program ini mencakup beberapa fungsi dasar untuk manipulasi linked list, seperti penambahan elemen di depan, di belakang, di tengah, penghapusan elemen di depan, di belakang, di tengah, serta pengubahan nilai elemen di depan, di belakang, dan di tengah. Dalam program ini, terdapat beberapa fungsi yang digunakan untuk operasi dasar pada linked list, seperti penambahan elemen, penghapusan elemen, pengubahan nilai elemen, serta penampilan isi linked list. Fungsi init() digunakan untuk menginisialisasi linked list dengan mengatur head dan tail menjadi NULL. Fungsi isEmpty() digunakan untuk memeriksa apakah linked list kosong atau tidak. Selanjutnya, terdapat fungsi-fungsi untuk penambahan elemen di depan, di belakang, dan di tengah, yaitu insertDepan(int nilai), insertBelakang(int nilai), dan insertTengah(int data, int posisi). Fungsi-fungsi tersebut bertugas untuk menambahkan elemen baru sesuai dengan posisi yang diinginkan dalam linked list.<br/>
Selain itu, program juga menyediakan fungsi-fungsi untuk penghapusan elemen di depan, di belakang, dan di tengah, yaitu hapusDepan(), hapusBelakang(), dan hapusTengah(int posisi). Fungsi-fungsi tersebut digunakan untuk menghapus elemen tertentu sesuai dengan posisi yang ditentukan dalam linked list. Selanjutnya, program juga menyediakan fungsi-fungsi untuk pengubahan nilai elemen di depan, di belakang, dan di tengah, yaitu ubahDepan(int data), ubahBelakang(int data), dan ubahTengah(int data, int posisi). Fungsi-fungsi tersebut digunakan untuk mengubah nilai dari elemen tertentu sesuai dengan posisi yang ditentukan dalam linked list. Terakhir, terdapat fungsi clearList() yang bertugas untuk menghapus semua elemen dari linked list, serta fungsi tampil() yang digunakan untuk menampilkan semua elemen dalam linked list. Pada fungsi main(), program melakukan serangkaian operasi untuk memperlihatkan fungsionalitas dari setiap operasi tersebut, seperti memasukkan, menghapus, mengubah, dan menampilkan elemen-elemen dalam linked list.<br/>

### 2. Double Linked List

```C++
// Oleh Amanda Windhu Gustyas-2311102121
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
};
class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    void
        push(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr)
        {
            head->prev = newNode;
        }
        else
        {
            tail = newNode;
        }
        head = newNode;
    }
    void
        pop()
    {
        if (head == nullptr)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        delete temp;
    }
    bool
        update(int oldData, int newData)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data == oldData)
            {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void
        deleteAll()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void
        display()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
int main()
{
    DoublyLinkedList list;
    while (true)
    {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int data;
            cout << "Enter data to add: ";
            cin >> data;
            list.push(data);
            break;
        }
            case 2:
            {
                list.pop();
                break;
            }
            case 3:
            {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData,
                                           newData);
                if (!updated)
                {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4:
            {
                list.deleteAll();
                break;
            }
            case 5:
            {
                list.display();
                break;
            }
            case 6:
            {
                return 0;
            }
            default:
            {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```
Program di atas merupakan implementasi dari sebuah Double Linked List dalam bahasa pemrograman C++. Double Linked List memiliki dua pointer, yaitu pointer prev dan next. Kelas 'Node' digunakan untuk merepresentasikan elemen dalam Double Linked List dengan atribut data untuk menyimpan nilai elemen, serta pointer 'prev' dan 'next' untuk menunjukkan elemen sebelumnya dan selanjutnya dalam list. Kelas DoublyLinkedList memiliki atribut head dan tail yang menunjukkan elemen pertama dan terakhir dalam list, kelas tersebut menyediakan beberapa fungsi seperti fungsi 'push(data)' untuk menambahkan sebuah node baru dengan nilai data di depan linked list. Fungsi 'pop()' untuk menghapus node pertama (kepala) dari linked list. Fungsi update(oldData, newData) untuk mencari node dengan nilai oldData dan memperbaruinya dengan nilai newData, apabila data lama ditemukan, fungsi tersebut mengembalikan nilai true, dan false jika data tidak ditemukan. Selanjutnya, fungsi deleteAll() untuk menghapus semua node dari linked list. Yang terakhir fungsi display() untuk menampilkan seluruh data dalam linked list.<br/>
Di dalam fungsi main, program menampilkan menu pilihan yang memungkinkan pengguna untuk melakukan operasi. Berdasarkan pilihan menu yang dimasukkan pengguna, program akan menjalankan fungsi terkait untuk memanipulasi data. Pengguna dapat memilih opsi 1 untuk menambahkan data, opsi 2 menghapus data, opsi 3 memperbarui data, opsi 4 menghapus semua data, opsi 5 menampilkan data dan opsi 6 keluar dari program.<br/>

## Unguided 

### 1. Soal Single Linked List<br/>
Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut:<br/>
a. Masukkan data sesuai urutan berikut. (Gunakan insert depan, belakang atau tengah). Data pertama yang dimasukkan adalah nama dan usia anda.<br/>
[Nama_anda]  [Usia_anda]<br/>
John             19<br/>
Jane             20<br/>
Michael          18<br/>
Yusuke           19<br/>
Akechi           20<br/>
Hoshino          18<br/>
Karin            18<br/>
b. Hapus data Akechi<br/>
c. Tambahkan data berikut diantara John dan Jane : Futaba 18<br/>
d. Tambahkan data berikut diawal : Igor 20<br/>
e. Ubah data Michael menjadi : Reyn 18<br/>
f. Tampilkan seluruh data<br/>

```C++
// oleh Amanda Windhu Gustyas-2311102121
#include <iostream>
#include <string>
using namespace std;

// deklarasi struct node
struct Node {
  string nama;
  int usia;
  Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

// inisialisasi node
void init() {
  head = nullptr;
  tail = nullptr;
}

// pengecekan apakah list kosong
bool isEmpty() {
  return head == nullptr;
}

// hitung jumlah node
int hitungList();

// tambah node di depan
void insertDepan(string nama, int usia) {
  Node* baru = new Node;
  baru->nama = nama;
  baru->usia = usia;
  baru->next = nullptr;

  if (isEmpty()) {
    head = tail = baru;
  } else {
    baru->next = head;
    head = baru;
  }
}

// tambah node di belakang
void insertBelakang(string nama, int usia) {
  Node* baru = new Node;
  baru->nama = nama;
  baru->usia = usia;
  baru->next = nullptr;

  if (isEmpty()) {
    head = tail = baru;
  } else {
    tail->next = baru;
    tail = baru;
  }
}

// tambah node di tengah
void insertTengah(string nama, int usia, int posisi) {
  if (posisi < 1) {
    cout << "Posisi diluar jangkauan" << endl;
    return;
  }

  if (posisi == 1) {
    cout << "Posisi bukan posisi tengah" << endl;
    return;
  }

  if (posisi > 1 && posisi <= hitungList()) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->usia = usia;

    Node* bantu = head;
    int nomor = 1;

    while (nomor < posisi - 1) {
      bantu = bantu->next;
      nomor++;
    }

    baru->next = bantu->next;
    bantu->next = baru;
  } else {
    cout << "Posisi diluar jangkauan" << endl;
  }
}

// hapus node di depan
void hapusDepan() {
  if (!isEmpty()) {
    Node* hapus = head;
    head = head->next;
    delete hapus;
  } else {
    cout << "List kosong!" << endl;
  }
}

// hapus node di belakang
void hapusBelakang() {
  if (!isEmpty()) {
    if (head == tail) {
      delete head;
      head = tail = nullptr;
    } else {
      Node* bantu = head;
      while (bantu->next != tail) {
        bantu = bantu->next;
      }
      delete tail;
      tail = bantu;
      tail->next = nullptr;
    }
  } else {
    cout << "List kosong!" << endl;
  }
}

// hapus node di tengah
void hapusTengah(string nama) {
  if (!isEmpty()) {
    Node* hapus;
    Node* bantu = head;

    if (head->nama == nama) {
      hapus = head;
      head = head->next;
      delete hapus;
      return;
    }

    while (bantu->next != nullptr && bantu->next->nama != nama) {
      bantu = bantu->next;
    }

    if (bantu->next == nullptr) {
      cout << "Data tidak ditemukan!" << endl;
    } else {
      hapus = bantu->next;
      bantu->next = bantu->next->next;
      delete hapus;
    }
  } else {
    cout << "List kosong!" << endl;
  }
}

// hitung jumlah node
int hitungList() {
  int jumlah = 0;
  Node* hitung = head;
  while (hitung != nullptr) {
    jumlah++;
    hitung = hitung->next;
  }
  return jumlah;
}

// ubah data node di depan
void ubahDepan(string nama, int usia) {
  if (!isEmpty()) {
    head->nama = nama;
    head->usia = usia;
   }else {
    cout << "List masih kosong!" << endl;
  }
}

// ubah data node di belakang
void ubahBelakang(string nama, int usia) {
  if (!isEmpty()) {
    tail->nama = nama;
    tail->usia = usia;
  } else {
    cout << "List masih kosong!" << endl;
  }
}

// ubah data node di tengah
void ubahTengah(string nama, int usia, int posisi) {
  if (!isEmpty()) {
    if (posisi < 1 || posisi > hitungList()) {
      cout << "Posisi di luar jangkauan" << endl;
    } else if (posisi == 1) {
      cout << "Posisi bukan posisi tengah" << endl;
    } else {
      Node* bantu = head;
      int nomor = 1;
      while (nomor < posisi) {
        bantu = bantu->next;
        nomor++;
      }
      bantu->nama = nama;
      bantu->usia = usia;
    }
  } else {
    cout << "List masih kosong!" << endl;
  }
}

// hapus semua node
void clearList() {
  while (!isEmpty()) {
    hapusDepan();
  }
  cout << "List berhasil terhapus!" << endl;
}

// tampilkan seluruh node
void tampil() {
  Node* bantu = head;
  if (!isEmpty()) {
    while (bantu != nullptr) {
      cout << bantu->nama << " " << bantu->usia << endl;
      bantu = bantu->next;
    }
  } else {
    cout << "List masih kosong!" << endl;
  }
}

int main() {
  init();
  // Masukkan data awal
  insertBelakang("John", 19);
  insertBelakang("Jane", 20);
  insertBelakang("Michael", 18);
  insertBelakang("Yusuke", 19);
  insertBelakang("Akechi", 20);
  insertBelakang("Hoshino", 18);
  insertBelakang("Karin", 18);
         ubahTengah("Reyn", 18, 3);
         hapusTengah("Akechi");
         insertDepan("Igor", 20);
         insertTengah("Futaba", 18, 3);

  tampil();

  return 0;
}
```
#### Output:
![Unguided1_Amanda](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/073d4086-33e7-4845-a611-721688647bf1)

Program ini merupakan implementasi dari single linked list dalam bahasa pemrograman C++. Program menyediakan fungsi-fungsi untuk manipulasi data dalam linked list, termasuk menambahkan node di depan, di belakang, atau di tengah, menghapus node, mengubah nilai node, serta menampilkan seluruh data dalam linked list. Variabel global ‘head’ dan ‘tail’ digunakan untuk menyimpan pointer ke node pertama (head) dan terakhir (tail) dalam linked list. Terdapat fungsi ‘isEmpty()’ untuk memeriksa apakah linked list kosong dan fungsi ‘hitungList()’ untuk menghitung jumlah node dalam linked list. Fungsi ‘main()’ dari program ini memasukkan beberapa data awal ke dalam linked list, melakukan operasi seperti mengubah dan menghapus data pada posisi tertentu, kemudian menampilkan seluruh data yang ada dalam linked list setelah operasi-operasi tersebut dilakukan. Program ini memberikan contoh sederhana dari bagaimana single linked list dapat diimplementasikan dalam sebuah program C++ untuk mengelola data dengan dinamis.

### 2. Soal Double Linked List<br/>
Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.<br/>
    Nama                Produk Harga<br/>
Originote                  60.000<br/>
Somethinc                  150.000<br/>
Skintific                  100.000<br/>
Wardah                     50.000<br/>
Hanasui                    30.000<br/>
Case:
1. Tambahkan produk Azarine dengan harga 65000 diantara Somethinc dan Skintific.<br/>
2. Hapus produk wardah.<br/>
3. Update produk Hanasui menjadi Cleora dengan harga 55.000<br/>
4. Tampilkan menu seperti dibawah ini<br/>
    Toko Skincare Purwokerto<br/>
        1. Tambah Data<br/>
        2. Hapus Data<br/>
        3. Update Data<br/>
        4. Tambah Data Urutan Tertentu<br/>
        5. Hapus Data Urutan Tertentu<br/>
        6. Hapus Seluruh Data<br/>
        7. Tampilkan Data<br/>
        8. Exit<br/>
    Pada menu 7, tampilan akhirnya akan menjadi seperti dibawah ini :<br/>
    Nama Produk Harga<br/>
    Originote 60.000<br/>
    Somethinc 150.000<br/>
    Azarine 65.000<br/>
    Skintific 100.000<br/>
    Cleora 55.000<br/>

```C++
// Oleh Amanda Windhu Gustyas-2311102121
#include <iostream>
#include <string>
using namespace std;

// Struktur Node untuk merepresentasikan data produk dan hubungan antar-node
struct Node {
  string namaProduk; // Nama produk
  int harga; // Harga produk
  Node* prev; // Pointer ke node sebelumnya dalam linked list
  Node* next; // Pointer ke node berikutnya dalam linked list
};

Node* head = NULL; // Pointer ke node pertama dalam linked list
Node* tail = NULL; // Pointer ke node terakhir dalam linked list

// Fungsi untuk menambahkan data produk ke dalam linked list
void tambahData() {
  string nama;
  int harga;
  cout << "Masukkan nama produk: ";
  cin >> nama;
  cout << "Masukkan harga: ";
  cin >> harga;

  // Buat node baru dan inisialisasi datanya
  Node* newNode = new Node;
  newNode->namaProduk = nama;
  newNode->harga = harga;
  newNode->prev = NULL;
  newNode->next = NULL;

  // Tambahkan node baru ke dalam linked list
  if (head == NULL) {
    // Jika linked list kosong, node baru menjadi kepala dan ekor
    head = tail = newNode;
  } else {
    // Jika tidak kosong, tambahkan node baru setelah ekor dan update ekor
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }
  cout << "Data berhasil ditambahkan!" << endl;
}

// Fungsi untuk menghapus data produk dari linked list berdasarkan nama
void hapusData() {
  if (head == NULL) {
    cout << "Linked list kosong!" << endl;
  } else {
    string nama;
    cout << "Masukkan nama produk yang ingin dihapus: ";
    cin >> nama;

    // Mulai pencarian dari kepala linked list
    Node* currentNode = head;
    while (currentNode != NULL && currentNode->namaProduk != nama) {
      currentNode = currentNode->next;
    }

    // Jika data tidak ditemukan
    if (currentNode == NULL) {
      cout << "Data tidak ditemukan!" << endl;
    } else {
      // Jika data ditemukan, hapus data sesuai kasus
      if (currentNode == head && currentNode == tail) {
        delete currentNode;
        head = tail = NULL;
      } else if (currentNode == head) {
        head = head->next;
        head->prev = NULL;
        delete currentNode;
      } else if (currentNode == tail) {
        tail = tail->prev;
        tail->next = NULL;
        delete currentNode;
      } else {
        currentNode->prev->next = currentNode->next;
        currentNode->next->prev = currentNode->prev;
        delete currentNode;
      }
      cout << "Data berhasil dihapus!" << endl;
    }
  }
}

// Fungsi untuk mengupdate data produk berdasarkan nama
void updateData() {
  if (head == NULL) {
    cout << "Linked list kosong!" << endl;
  } else {
    string namaLama, namaBaru;
    int hargaBaru;
    cout << "Masukkan nama produk yang ingin diubah: ";
    cin >> namaLama;

    // Mulai pencarian dari kepala linked list
    Node* currentNode = head;
    while (currentNode != NULL && currentNode->namaProduk != namaLama) {
      currentNode = currentNode->next;
    }

    // Jika data tidak ditemukan
    if (currentNode == NULL) {
      cout << "Data tidak ditemukan!" << endl;
    } else {
      // Jika data ditemukan, minta input untuk update nama dan harga baru
      cout << "Masukkan nama baru: ";
      cin >> namaBaru;
      cout << "Masukkan harga baru: ";
      cin >> hargaBaru;

      // Update data produk
      currentNode->namaProduk = namaBaru;
      currentNode->harga = hargaBaru;
      cout << "Data berhasil diperbarui!" << endl;
    }
  }
}

// Fungsi untuk menambahkan data produk pada posisi tertentu dalam linked list
void tambahDataUrutan() {
  if (head == NULL) {
    cout << "Linked list kosong!" << endl;
  } else {
    string nama;
    int harga;
    string posisi;
    cout << "Masukkan nama produk: ";
    cin >> nama;
    cout << "Masukkan harga: ";
    cin >> harga;
    cout << "Masukkan nama produk sebelum posisi yang diinginkan: ";
    cin >> posisi;

    // Buat node baru dan inisialisasi datanya
    Node* newNode = new Node;
    newNode->namaProduk = nama;
    newNode->harga = harga;

    // Mulai pencarian dari kepala linked list
    Node* currentNode = head;
    while (currentNode != NULL && currentNode->namaProduk != posisi) {
      currentNode = currentNode->next;
    }

    // Jika posisi tidak ditemukan
    if (currentNode == NULL) {
      cout << "Posisi tidak ditemukan!" << endl;
    } else {
      // Tambahkan node baru setelah node yang ditemukan
      newNode->prev = currentNode;
      newNode->next = currentNode->next;
      if (currentNode->next != NULL)
        currentNode->next->prev = newNode;
      currentNode->next = newNode;
      cout << "Data berhasil ditambahkan di urutan tertentu!" << endl;
    }
  }
}

// Fungsi untuk menghapus data produk pada posisi tertentu dalam linked list
void hapusDataUrutan() {
  if (head == NULL) {
    cout << "Linked list kosong!" << endl;
  } else {
    int posisi;
    cout << "Masukkan posisi data yang ingin dihapus: ";
    cin >> posisi;

    // Mulai pencarian dari kepala linked list
    Node* currentNode = head;
    for (int i = 1; i < posisi && currentNode != NULL; ++i) {
      currentNode = currentNode->next;
    }

    // Jika posisi tidak valid
    if (currentNode == NULL) {
      cout << "Posisi tidak valid!" << endl;
    } else {
      // Hapus node sesuai dengan kasus
      if (currentNode == head && currentNode == tail) {
        delete currentNode;
        head = tail = NULL;
      } else if (currentNode == head) {
        head = head->next;
        head->prev = NULL;
        delete currentNode;
      } else if (currentNode == tail) {
        tail = tail->prev;
        tail->next = NULL;
        delete currentNode;
      } else {
        currentNode->prev->next = currentNode->next;
        currentNode->next->prev = currentNode->prev;
        delete currentNode;
      }
      cout << "Data berhasil dihapus!" << endl;
    }
  }
}

// Fungsi untuk menampilkan seluruh data produk dalam linked list
void tampilkanData() {
  if (head == NULL) {
    cout << "Linked list kosong!" << endl;
  } else {
    Node* currentNode = head;
    int counter = 1;
    cout << "No.\tNama Produk\tHarga" << endl;
    while (currentNode != NULL) {
      cout << counter << "\t" << currentNode->namaProduk << "\t\t" << currentNode->harga << endl;
      currentNode = currentNode->next;
      counter++;
    }
  }
}

int main() {
  int pilihan;
  do {
    // Menampilkan menu pilihan
    cout << "\nToko Skincare Purwokerto" << endl;
    cout << "     1. Tambah Data" << endl;
    cout << "     2. Hapus Data" << endl;
    cout << "     3. Update Data" << endl;
    cout << "     4. Tambah Data Urutan Tertentu" << endl;
    cout << "     5. Hapus Data Urutan Tertentu" << endl;
    cout << "     6. Hapus Seluruh Data" << endl;
    cout << "     7. Tampilkan Data" << endl;
    cout << "     8. Exit" << endl;
    cout << "Pilihan Anda: ";
    cin >> pilihan;

    // Memproses pilihan pengguna menggunakan switch case
    switch (pilihan) {
      case 1:
        tambahData();
        break;
      case 2:
        hapusData();
        break;
      case 3:
        updateData();
        break;
      case 4:
        tambahDataUrutan();
        break;
      case 5:
        hapusDataUrutan();
        break;
      case 6:
        cout << "Terima kasih!" << endl;
        break;
      case 7:
        tampilkanData();
        break;
      case 8:
        cout << "Terima kasih!" << endl;
        break;
      default:
        cout << "Pilihan tidak valid!" << endl;
        break;
    }
  } while (pilihan != 6 && pilihan != 8);

  return 0;
}
```
#### Output:
![Unguided2_Amanda](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/5d6dfffb-b614-461e-a6d9-3cf4c57f1375)

Program di atas merupakan program C++ untuk manajemen data produk dalam sebuah toko skincare di Purwokerto. Program tersebut menggunakan implementasi dari Double Linked List untuk menyimpan dan mengelola data produk. Deklarasi Struktur Node mendeklarasikan sebuah struktur ‘Node’ yang memiliki tiga atribut yaitu ‘namaProduk’ untuk menyimpan nama produk, ‘harga’ untuk menyimpan harga produk, dan dua pointer ‘prev’ dan ‘next’ untuk menunjukkan hubungan antara node-node dalam linked list. Deklarasi Variabel Global mendeklarasikan dua variabel global ‘head’ dan ‘tail’ yang bertipe pointer ke ‘Node’, yang digunakan untuk menandai node pertama (head) dan terakhir (tail) dalam linked list.<br/>
Kemudian, fungsi tambahData(), fungsi ini meminta pengguna memasukkan nama dan harga produk, kemudian membuat sebuah node baru dengan data yang dimasukkan dan menambahkannya ke akhir linked list. Jika linked list masih kosong, node baru tersebut akan menjadi head dan tail dari linked list. Fungsi hapusData(), fungsi ini meminta pengguna memasukkan nama produk yang ingin dihapus, kemudian mencari node dengan nama produk tersebut dalam linked list. Jika ditemukan, node tersebut akan dihapus dari linked list sesuai dengan kasus (head, tail, atau tengah). Fungsi updateData(), fungsi ini meminta pengguna memasukkan nama produk yang ingin diubah, kemudian mencari node dengan nama produk tersebut dalam linked list. Jika ditemukan, pengguna diminta memasukkan nama dan harga baru untuk produk tersebut, dan data produk akan diperbarui. Fungsi tambahDataUrutan(), fungsi ini meminta pengguna memasukkan nama, harga, dan nama produk sebelum posisi yang diinginkan untuk menambahkan data produk pada posisi tertentu dalam linked list. Fungsi ini akan menambahkan node baru setelah node yang ditemukan berdasarkan nama produk yang dimasukkan. Fungsi hapusDataUrutan(), fungsi ini meminta pengguna memasukkan posisi data yang ingin dihapus, kemudian mencari node pada posisi tersebut dalam linked list. Jika ditemukan, node tersebut akan dihapus dari linked list sesuai dengan kasus (head, tail, atau tengah). Fungsi `tampilkanData()``, fungsi ini menampilkan seluruh data produk dalam linked list beserta nomor urutannya. Data produk ditampilkan dalam format yang terstruktur dengan nomor urut, nama produk, dan harga. Terakhir fungsi main(), fungsi utama program yang berisi logika utama. Program akan menampilkan menu pilihan kepada pengguna dan memproses pilihan pengguna menggunakan perulangan do-while dan struktur switch-case. Program akan terus berjalan sampai pengguna memilih untuk keluar (pilihan 6 atau 8). Melalui program ini, pengguna dapat dengan mudah menambah, menghapus, mengupdate, atau menampilkan data produk dalam toko skincare dengan menggunakan operasi-operasi yang disediakan dalam menu pilihan. Program ini memberikan sebuah contoh penggunaan double linked list dalam konteks nyata untuk mengelola data dengan efisien.<br/>

## Kesimpulan
[1] Terdapat tiga jenis Linked List yang umum digunakan dalam struktur data, yaitu Single Linked List, Circular Linked List, dan Double Linked List.<br/>
[2] Single Linked List merupakan struktur data Linked List yang paling sederhana, dimana setiap simpul hanya memiliki satu pointer yang menunjuk ke simpul berikutnya. Operasi penambahan dan penghapusan pada ujung depan atau belakang daftar bisa dilakukan dengan efisien. Namun, traversal ke simpul tertentu membutuhkan waktu yang lebih lama.<br/>
[3] Circular Linked List mirip dengan Single Linked List, namun pointer next pada simpul terakhir selalu menunjuk kembali ke simpul pertama, membentuk lingkaran. Hal ini memungkinkan traversal melalui seluruh elemen dalam daftar dengan lebih mudah dan operasi penghapusan dan penambahan dapat dilakukan dengan efisien.<br/>
[4] Double Linked List lebih kompleks daripada Single Linked List karena setiap simpul memiliki dua pointer, satu untuk menunjuk ke simpul berikutnya (next) dan satu untuk menunjuk ke simpul sebelumnya (prev). Hal ini memungkinkan operasi penghapusan dan penambahan pada simpul mana saja dalam daftar dengan efisien. Namun, Double Linked List membutuhkan lebih banyak memori dan operasi tambahan untuk mengelola pointer prev.<br/>
[5] Ketiga jenis Linked List tersebut memiliki kelebihan dan kekurangan masing-masing. Pemilihan jenis Linked List yang sesuai tergantung pada kebutuhan dan karakteristik spesifik dari algoritma yang akan diimplementasikan.<br/>

## Referensi
[1] Abdi Dharma, & Hendra Handoko Syahputra P. (Desember, 2019). Aplikasi Pembelajaran Linked
    List Berbasi Mobile Learning. Riau Journal of Computer Science, Vol. 4(1), hlm. 3-4.<br/>
[2] Sihombing, J. (2019). Penerapan Stack dan Queue pada Array dan Linked List dalam Java.
    Jurnal Infokom, Vol. 7(2), Desember 2019.<br/>
