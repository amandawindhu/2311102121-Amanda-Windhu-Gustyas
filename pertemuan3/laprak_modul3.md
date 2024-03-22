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
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

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
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

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
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

### 2. Soal Double Linked List<br/>
Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.<br/>
    Nama                Produk Harga<br/>
Originote                  60.000<br/>
Somethinc                  150.000<br/>
Skintific                  100.000<br/>
Wardah                     50.000<br/>
Hanasui                    30.000<br/>
Case:<br/>
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

## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] Abdi Dharma, & Hendra Handoko Syahputra P. (Desember, 2019). Aplikasi Pembelajaran Linked
    List Berbasi Mobile Learning. Riau Journal of Computer Science, Vol. 4(1), hlm. 3-4.<br/>
[2] Sihombing, J. (2019). Penerapan Stack dan Queue pada Array dan Linked List dalam Java. Jurnal Infokom, Vol. 7(2), Desember 2019.<br/>
