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

### Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user.
### 1. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan NIM mahasiswa.

```C++
// Oleh Amanda Windhu Gustyas - 2311102121
    #include <iostream>
    using namespace std;
    struct Node
    {
        string name;
        string nim;
        Node *next;
    };
    Node *head;
    Node *tail;
    //untuk menginisialkan
    void init()
    {
        head = NULL;
        tail = NULL;
    }
        bool isEmpty()
    {
        if (head == NULL)
            {
                return true;
            }
        else
            {
                return false;
            }
    }
    // Tambah data di index pertama
    void insertDepan(string name, string nim)
        {
            Node *newNode = new Node;
            newNode->name = name;
            newNode->nim = nim;
            newNode->next = NULL;
            if (isEmpty() == true)
                {
                    head = tail = newNode;
                    tail->next = NULL;
                }
            else
                {
                    newNode->next = head;
                    head = newNode;
                }
        cout << "Data " << name << " berhasil ditambahkan" << endl;
    }
    // Tambah data di bagian index terbesar atau terakhir
    void insertBelakang(string name, string nim)
        {
            Node *newNode = new Node;
            newNode->name = name;
            newNode->nim = nim;
            newNode->next = NULL;
            if (isEmpty() == true)
                {
                    head = tail = newNode;
                }
            else
                {
                    tail->next = newNode;
                    tail = newNode;
                }
        cout << "Data " << name << " berhasil ditambahkan" << endl;
    }
    // Prosedur untuk menghitung list yang ada
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
            // Tambah data dibagian atntar index atau data list
            void insertTengah(string name, string nim, int posisi)
        {
            Node *newNode = new Node;
            newNode->name = name;
            newNode->nim = nim;
            newNode->next = nullptr;
            if (posisi == 1)
                {
                    newNode->next = head;
                    head = newNode;
        cout << "Data " << name << " berhasil ditambahkan pada posisi " << posisi << endl;
    return;
        }
            Node *prevNode = head;
            for (int i = 1; i < posisi - 1 && prevNode != nullptr; 
            i++)
        {
            prevNode = prevNode->next;
        }
            if (prevNode == nullptr)
                {
                    cout << "Posisi tidak ditemukan" << endl;
                    return;
                }
        newNode->next = prevNode->next;
        prevNode->next = newNode;
        cout << "Data " << name << " berhasil ditambahkan pada posisi " << posisi << endl;
        }
            // Prosedur untuk menghapus data di posisi tertentu
            void remove()
        {
            bool loop = true;
            while (loop)
        {
    int posisi;
    cout << "----- Hapus Data -----\n";
    cout << "1. Hapus Depan\n"<< "2. Hapus Tengah\n"<< "3. Hapus Belakang\n"<< "4. Keluar\nMasukan Pilihan: ";
    cin >> posisi;
    // Untuk menghapus data index ke 0 atau data list pertama
        if (posisi == 1)
            {
                Node *hapus;
                if (isEmpty() == false)
            {
                if (head->next != NULL)
                    {
                        hapus = head;
                        head = head->next;
                        delete hapus;
                        cout << "Data berhasil dihapus!" << endl;
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
    // untuk menghapus data antar index sesuai posisi
    else if (posisi == 2)
        {
            int pos;
            cout << "Masukan posisi yang ingin dihapus: "; 
            cin >> pos;
            Node *bantu, *hapus, *sebelum;
            if (pos < 1 || pos > hitungList())
                {
                    cout << "Posisi di luar jangkauan" << endl;
                }
            else if (pos == 1)
                {
                    cout << "Posisi bukan posisi tengah" << endl;
                }
            else
                {
                    int nomor = 1;
                    bantu = head;
                    while (nomor <= pos)
                {
            if (nomor == pos - 1)
                {
                    sebelum = bantu;
                }
            if (nomor == pos)
                {
                    hapus = bantu;
                }
        bantu = bantu->next;
        nomor++;
    }
        sebelum->next = bantu;
        delete hapus;
        cout << "Data berhasil dihapus!" << endl;
    }
        }
        // untuk menghapus data diindex terbesar atau terakhir
        else if (posisi == 3)
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
        cout << "Data berhasil dihapus!" << endl;
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
        // pilihan untuk keluar dari fungsi remove
        else if (posisi == 4)
            {
                cout << "Keluar" << endl;
                loop = false;
            }
        else
            {
                cout << "Input tidak valid!" << endl;
            }
        }
    }
    // untuk mengubah data index 0 atau pertama
    void ubahDepan(string name, string nim)
    {
        if (isEmpty() == 0)
            {
                head->name = name;
                head->nim = nim;
            }
        else
            {
                cout << "List masih kosong!" << endl;
            }
    }
    // untuk mengubah data diantara index sesuai posisi
    void ubahTengah(string name, string nim, int posisi)
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
                    cout << "Posisi bukan posisi tengah" << endl;
                }
            else
                {
                    bantu = head;
                    int nomor = 1;
                    while (nomor < posisi)
                        {
                            bantu = bantu->next;
                            nomor++;
                        }
        bantu->name = name;
        bantu->nim = nim;
    }
        }
            else
                {
                    cout << "List masih kosong!" << endl;
                }
    }
    // untuk mengubah data di index terbesar atay terakhir
    void ubahBelakang(string name, string nim)
        {
            if (isEmpty() == 0)
                {
                    tail->name = name;
                    tail->nim = nim;
                }
            else
                {
                    cout << "List masih kosong!" << endl;
                }
        }
    // untuk menampilkan data list dalam program
    void display()
        {
            if (head == NULL)
                {
                    cout << "List kosong!" << endl;
                    return;
                }
    Node *current = head;
    int o = 1;
    while (current != NULL)
        {
            cout << o++ << ". " << "Nama: " << current->name << endl;
            cout << " NIM: " << current->nim << endl;
            current = current->next;
        }
        }
    int main()
    {
    // Deklarasi Variabel
    int choice;
    int choice_data;
    string name, nim;
    int posisi;
    loop_menu:
    // Menampilkan menu
    cout << "\nPROGRAM SINGLE LINKED LIST NON-CIRCULAR: "<< endl;
    cout << "1. Tambah Depan" << endl;
    cout << "2. Hapus data" << endl;
    cout << "3. Ubah data" << endl;
    cout << "4. Tampilkan data" << endl;
    cout << "5. Keluar" << endl;
    cout << "Masukkan pilihan dari menu (1-5): ";
    cin >> choice;
        switch (choice)
            {
                case 1: // Pilihan untuk menambah data
            {
                cout << "----- Tambahkan Data -----\n";
                cout << "Masukan Posisi Data : \n";
                cout << "1. Tambah Depan\n";
                cout << "2. Tambah Belakang\n";
                cout << "3. Tambah Tengah\n";
                cout << "4. Keluar\n";
                loop_choice_data:
                cout << "Masukan pilihan Anda (1-4): ";
                cin >> choice_data;
                if (choice_data == 1) // Pilihan untuk menambah data di depan
                    {
                        cout << "--Tambah Depan--\n";
                        cout << "Masukkan Nama: ";
                        cin >> name;
                        cout << "Masukkan NIM: ";
                        cin >> nim;
                        insertDepan(name, nim);
                    }
                else if (choice_data == 2) // Pilihan untuk menambah data di belakang
                    {
                        cout << "--Tambah Belakang--\n";
                        cout << "Masukkan Nama: ";
                        cin >> name;
                        cout << "Masukkan NIM: ";
                        cin >> nim;
                        insertBelakang(name, nim);
                    }
                else if (choice_data == 3) // Pilihan untuk menambah data di tengah
                    {
                        cout << "--Tambah Tengah--\n";
                        cout << "Masukkan Nama: ";
                        cin >> name;
                        cout << "Masukkan NIM: ";
                        cin >> nim;
                        cout << "Masukan Posisi: ";
                        cin >> posisi;
                        insertTengah(name, nim, posisi);
                    }
                else if (choice_data == 4) // Pilihan untuk keluar dari submenu
                    {
                        cout << "Keluar dari Menu Tambah Data\n";
                        goto loop_menu;
                    }
                else
                    {
                        cout << "Pilihan Anda Tidak Valid\n";
                    }
                goto loop_choice_data;
                break;
            }
                case 2: // Pilihan untuk menghapus data
            {
                remove();
                break;
            }
                case 3: // Pilihan untuk mengubah data
            {
                string newNim, newName;
                int pilihan, posisi;
                cout << "----- Ubah Data -----\n";
                cout << "1. Ubah Depan\n"
                << "2. Ubah Tengah\n"
                << "3. Ubah Belakang\n";
                cout << "Masukan pilihan anda: ";
                cin >> pilihan;
                    if (pilihan == 1) // Untuk mengubah data di depan
                        {
                            cout << "Masukan nama yang baru: ";
                            cin >> newName;
                            cout << "Masukan NIM yang baru: ";
                            cin >> newNim;
                            ubahDepan(newName, newNim);
                        }
                    else if (pilihan == 2) // Untuk mengubah data di tengah
                        {
                            cout << "Masukan nama yang baru: ";
                            cin >> newName;
                            cout << "Masukan NIM yang baru: ";
                            cin >> newNim;
                            cout << "Masukan data posisi yang ingin diubah: ";
                            cin >> posisi;
                            ubahTengah(newName, newNim, posisi);
                        }
                    else if (pilihan == 3) // Untuk mengubah data di belakang
                        {
                            cout << "Masukan nama yang baru: ";
                            cin >> newName;
                            cout << "Masukan NIM yang baru: ";
                            cin >> newNim;
                            ubahBelakang(newName, newNim);
                        }
                break;
            }
                case 4: // Menampilkan data
            {
                cout << "----- Tampilkan Data -----\n";
                display();
                break;
            }
                 case 5: // Keluar dari program
            {
                cout << "Terima kasih telah mencoba program ini!" << endl;
                return 0;
                break;
            }
                default:
            {
                cout << "Pilihan tidak valid" << endl;
            }
        }
    goto loop_menu;
    return 0;
    }
```
#### Output:
- Tampilan Menu<br/>
![Tampilan menu](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/9ea4112c-606d-4cc6-92bb-9b1f9a892b55)
- Tampilan Operasi Tambah<br/>
![Tampilan Operasi Tambah](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/400c297d-22ed-497e-99dc-8df989823c72)
- Operasi Tambah Depan<br/>
![Tambah Depan](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/c24efdd0-3bb7-404b-b8ac-23576421706d)
- Operasi Tambah Belakang<br/>
![Tambah Belakang](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/8de04678-43fb-44be-96c8-2202a7f36306)
- Operasi Tambah Tengah<br/>
![Tambah Tengah](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/a9e87b88-4430-4ea5-97cd-65f1f60fad7b)
- Tampilan Hapus Data<br/>
![Tampilan Hapus Data](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/6ea5b548-c1a3-48a3-a4dd-a814334eaa60)
- Hapus Depan<br/>
![Hapus Depan](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/3de5b65a-88ae-4c2e-add6-eb625f8f6256)
- Hapus Tengah<br/>
![Hapus Tengah](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/22846cbc-3135-457a-a527-0c0f5cc50ff2)
- Hapus Belakang<br/>
![Hapus Belakang](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/0f4bf51e-7ae1-4a3b-b6ad-e467082a67bf)
- Tampilan Ubah Data<br/>
![Tampilan Ubah Data](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/be519337-a502-4798-85bf-63b19969a2ea)
- Ubah Data Depan<br/>
![Ubah Depan](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/60d21c67-67b1-4424-9634-992459ea4fe8)
- Ubah Data Tengah<br/>
![Ubah Tengah](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/91138042-083b-4fff-a884-c045b95a2436)
- Ubah Data Belakang<br/>
![Ubah Belakang](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/1e2d20c1-073f-4dab-a776-5d736efe7552)

### 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah)
![SS_2](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/7689f1f1-345e-417f-8d19-ef5b0af5cdfd)

### 3. Lakukan perintah berikut:
a) Tambahkan data berikut diantara Farrel dan Denis: Wati 2330004<br/>
![Unguided_a](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/da3392a7-9847-4daa-a7b5-2ef37d30ea40)<br/>
b) Hapus data Denis<br/>
![Unguided_b](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/3ca597ea-2c15-4fa8-bce1-3eaf7b8d885a)<br/>
c) Tambahkan data berikut di awal:Owi 2330000<br/>
![Unguided_c](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/e37ffbcf-31ae-4248-ae77-404bb1d5755d)<br/>
d) Tambahkan data berikut di akhir: David 23300100<br/>
![Unguided_d](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/14a8b8b5-b3ec-4bba-8cbe-0a559ce6a945)<br/>
e) Ubah data Udin menjadi data berikut: Idin 23300045<br/>
![Unguided_e](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/15bdbffa-b143-4a90-a710-a2bd74cf7952)<br/>
f) Ubah data terakhir menjadi berikut: Lucy 23300101<br/>
![Unguided_f](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/7a679c6f-e75e-4c34-8df5-159d67c4a734)<br/>
g) Hapus data awal<br/>
![Unguided_g](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/ec1240d8-73cc-453a-86bc-3fb7f0e05411)<br/>
h) Ubah data awal menjadi berikut: Bagas 2330002<br/>
![Unguided_h](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/bf24ae19-8a73-461f-9512-8136a26802f2)<br/>
i) Hapus data akhir<br/>
![Unguided_i](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/98b1b98a-aae2-4536-baf8-257e65f7a54c)<br/>
j) Tampilkan seluruh data<br/>
![Unguided_j](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/fe704db0-f3a6-48f3-8f3c-635399e2eeb4)<br/>

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] Kurniman Putra, A. (2019). List linier (linked list) dan variasinya. Dalam Struktur Data (hal. 19). Fakultas Komputer. UMitra.<br/>
[2] Aksu, M., & Karci, A. (2019). Skip Ring/Circular Skip List: Circular Linked List Based New Data Structure. Computer Engineering and Intelligent Systems, 6(5), 35.<br/>

