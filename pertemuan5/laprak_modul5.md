# <h1 align="center">Laporan Praktikum Modul Hash Table</h1>
<p align="center">Amanda Windhu Gustyas - 2311102121</p>

## Dasar Teori

-> Pengertian Hash Table<br/>
    Hash table adalah model struktur data yang digunakan untuk menyimpan informasi dan mempermudah proses retrieve. Hash table terdiri atas dua komponen, yaitu key
    dan value. Key digunakan untuk mengakses data yang disimpan. Key bersifat unik dan biasanya berupa string yang penentuan nilai string tergantung dengan
    kasusnya. Hash table biasanya direpresentasikan sebagai associative array. Associative array mirip dengan array, tetapi untuk mengakses nomor index-nya array
    tidak dapat dilakukan secara langsung menggunakan integer, tetapi dengan menggunakan string dengan bantuan hash function yang gunanya untuk mengubah key yang
    berupa string tadi menjadi nilai integer yang menyatakan index array tempat data disimpan. Implementasi associative array sebagai multi linked list, disebut
    juga chain. Pada pembuatan hash table dengan chain, setiap key akan di-generate menggunakan hash function untuk mendapatkan nilai hash value-nya yang digunakan
    untuk mendapatkan posisi index data yang ingin diakses. Setiap key akan merujuk hanya ke sebuah entry. Entry berupa linked list yang menyimpan data yang
    memiliki hasil generati hash value yang sama. Dengan hash table, proses pencarian tidak perlu menelusuri seluruh nilai, cukup menelusuri slot yang memiliki key
    sesuai dengan value yang ingin dicari. Tujuan dari hash table adalah untuk mempercepat pencarian kembali dari banyak data yang disimpan.<br/>
    Hash table menyediakan beberapa operasi dasar untuk memanipulasi data yang disimpan di dalamnya. Operasi ini umumnya didesain untuk berwaktu operasi rata-rata
    (average-case time complexity) yang cepat, idealnya O(1) atau waktu konstan. Namun, perlu diingat bahwa waktu operasi sebenarnya dapat bervariasi tergantung
    pada faktor-faktor seperti fungsi hash yang digunakan dan bagaimana menangani  collisions (tabrakan).<br/>
    Berikut adalah operasi utama dalam hash table:<br/>
    1. Insert (Penyisipan)<br/>
    Operasi insert menambahkan data baru (key-value pair) ke dalam hash table.<br/>
    - Fungsi hash digunakan untuk menghitung index (alamat) dalam tabel berdasarkan key.<br/>
    - Hash table diperiksa pada index tersebut.<br/>
    - Jika index kosong, data baru disimpan di sana.<br/>
    - Jika terjadi collision (key lain sudah menempati index tersebut), teknik tertentu digunakan untuk menangani situasi ini, seperti chaining atau open
    addressing.<br/>
    2. Search (Pencarian)<br/>
    Operasi search digunakan untuk menemukan data yang terkait dengan key tertentu.<br/>
    - Fungsi hash digunakan untuk menghitung index berdasarkan key yang ingin dicari.<br/>
    - Hash table diperiksa pada index tersebut.<br/>
    - Jika key ditemukan pada index tersebut, data (value) dikembalikan.<br/>
    - Jika key tidak ditemukan, teknik penanganan collision perlu diikuti untuk mencari di tempat lain (pada chaining) atau memeriksa index alternatif (pada open
    addressing). Dalam kasus terburuk, seluruh hash table perlu diperiksa.<br/>
    3.Delete (Penghapusan)<br/>
    Operasi delete digunakan untuk menghapus data yang terkait dengan key tertentu.<br/>
    - Mirip dengan search, fungsi hash digunakan untuk menghitung index berdasarkan key yang ingin dihapus.<br/>
    - Hash table diperiksa pada index tersebut.<br/>
    - Jika key ditemukan, data (value) dihapus.<br/>
    - Penanganan collision perlu dilakukan untuk memastikan integritas data lainnya dalam tabel jika teknik chaining digunakan.<br/>
    - Penghapusan mungkin memerlukan penataan ulang elemen dalam tabel (rehashing) untuk menjaga efisiensi pencarian pada masa mendatang.<br/>
    4. Rehashing (Penataan Ulang)<br/>
    Rehashing adalah operasi opsional yang dapat dilakukan untuk meningkatkan performa keseluruhan hash table.<br/>
    - Ketika terjadi terlalu banyak collisions, waktu pencarian rata-rata bisa melambat.<br/>
    -Rehashing mengalokasikan tabel yang lebih besar dan mendistribusikan ulang semua data (key-value pair) ke dalam tabel baru dengan fungsi hash yang sama atau
    berbeda. ideally, rehashing bertujuan untuk mengurangi jumlah collisions dan mengembalikan waktu pencarian ke performa optimal.<br/>

## Guided 

### Guided 1

```C++
#include <iostream>
using namespace std;
    const int MAX_SIZE = 10;
        // Fungsi hash sederhana
        int hash_func(int key) {
        return key % MAX_SIZE;
        }
        // Struktur data untuk setiap node
        struct Node {
        int key;
        int value;
        Node* next;
        Node(int key, int value) : key(key), value(value),
        next(nullptr) {}
        };
        // Class hash table
        class HashTable {
        private:
        Node** table;
        public:
        HashTable() {
        table = new Node*[MAX_SIZE]();
        }
        ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
        Node* current = table[i];
        while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
        }
        }
        delete[] table;
        }
        // Insertion
        void insert(int key, int value) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
        if (current->key == key) {
        current->value = value;
        return;
        }
        current = current->next;
        }
        Node* node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
        }
        // Searching
        int get(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
        if (current->key == key) {
        return current->value;
        }
        current = current->next;
        }
        return -1;
        }
        // Deletion
        void remove(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr) {
        if (current->key == key) {
        if (prev == nullptr) {
        table[index] = current->next;
        } else {
        prev->next = current->next;
        }
        delete current;
        return;
        }
        prev = current;
        current = current->next;
        }
        }
        // Traversal
        void traverse() {
        for (int i = 0; i < MAX_SIZE; i++) {
        Node* current = table[i];
        while (current != nullptr) {
        cout << current->key << ": " << current->value
        << endl;
        current = current->next;
        }
        }
        }
        };
        int main() {
        HashTable ht;
        // Insertion
        ht.insert(1, 10);
        ht.insert(2, 20);
        ht.insert(3, 30);
        // Searching
        cout << "Get key 1: " << ht.get(1) << endl;
        cout << "Get key 4: " << ht.get(4) << endl;
        // Deletion
        ht.remove(4);
        // Traversal
        ht.traverse();
        return 0;
        }
```
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

### Guided 2
``` C++
#include <iostream>
#include <string>
#include <vector>
using namespace std;
    const int TABLE_SIZE = 11;
    string name;
    string phone_number;
    class HashNode {
    public:
    string name;
    string phone_number;
    HashNode(string name, string phone_number)
        {
            this->name = name;
            this->phone_number = phone_number;
        }
    };
    class HashMap {
    private:
    vector<HashNode*> table[TABLE_SIZE];
    public:
    int hashFunc(string key) {
    int hash_val = 0;
    for (char c : key) {
    hash_val += c;
    }
    return hash_val % TABLE_SIZE;
    }
    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
        if (node->name == name) {
        node->phone_number = phone_number;
        return;
        }
        }
        table[hash_val].push_back(new HashNode(name,
        phone_number));
        }
            void remove(string name) {
            int hash_val = hashFunc(name);
            for (auto it = table[hash_val].begin(); it !=
            table[hash_val].end(); it++) {
            if ((*it)->name == name) {
            table[hash_val].erase(it);
            return;
        }
        }
        }
            string searchByName(string name) {
            int hash_val = hashFunc(name);
            for (auto node : table[hash_val]) {
            if (node->name == name) {
            return node->phone_number;
            }
        }
    return "";
    }
    void print() {
    for (int i = 0; i < TABLE_SIZE; i++) {
    cout << i << ": ";
    for (auto pair : table[i]) {
    if(pair != nullptr){
    cout << "[" << pair->name << ", " <<
    pair->phone_number << "]";
    }
    }
    cout << endl;
    }
    }
    };
    int main() {
    HashMap 
    employee_map;
    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");
    cout << "Nomer Hp Mistah : " <<employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : " <<employee_map.searchByName("Pastah") << endl;
    employee_map.remove("Mistah");
    cout << "Nomer Hp Mistah setelah dihapus : " <<employee_map.searchByName("Mistah") << endl << endl;
    cout << "Hash Table : " << endl;
    employee_map.print();
    return 0;
    }
```

## Unguided 

### 1. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan :<br/>
a. Setiap mahasiswa memiliki NIM dan nilai.<br/>
b. Program memiliki tampilan pilihan menu berisi poin C.<br/>
c. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).<br/>

```C++
// Oleh Amanda Windhu Gustyas_2311102121
#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

// Define the structure for a student (Mahasiswa) including nim (student ID) and nilai (score).
struct Mahasiswa {
    long long nim;
    int nilai;
};

// Define a hash function to map student IDs to indices in the hash table.
int hash_func(long long key) {
    const int prime = 101;
    return key % prime;
}

// Define a structure for a node in the hash table.
struct Node {
    Mahasiswa data;
    Node* next;
    Node(Mahasiswa data) : data(data), next(nullptr) {}
};

// Define the hash table class.
class HashTable {
private:
    Node** table;

public:
    // Constructor: Initialize the hash table array.
    HashTable() {
        table = new Node*[MAX_SIZE]();
    }

    // Destructor: Deallocate memory for the hash table.
    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Method to add a student to the hash table.
    void tambah(Mahasiswa data) {
        int index = hash_func(data.nim);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->data.nim == data.nim) {
                current->data.nilai = data.nilai;
                return;
            }
            current = current->next;
        }
        Node* node = new Node(data);
        node->next = table[index];
        table[index] = node;
    }

    // Method to search for a student by their ID (nim) and return their data.
    Mahasiswa* cariNIM(long long nim) {
        int index = hash_func(nim);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->data.nim == nim) {
                return &(current->data);
            }
            current = current->next;
        }
        return nullptr;
    }

    // Method to remove a student from the hash table by their ID (nim).
    void hapus(long long nim) {
        int index = hash_func(nim);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->data.nim == nim) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Method to search for students within a specified score range and print their data.
    void cariRentangNilai(int NilaiMin, int NilaiMax) {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                if (current->data.nilai >= NilaiMin && current->data.nilai <= NilaiMax) {
                    cout << "NIM: " << current->data.nim << "\tNilai: " << current->data.nilai << endl;
                }
                current = current->next;
            }
        }
    }

   // Method to display all student data in the hash table.
void tampilkanData() {
    int nomor = 1;
    for (int i = 0; i < MAX_SIZE; i++) {
        Node* current = table[i];
        while (current != nullptr) {
            cout << nomor << ". NIM: " << current->data.nim << "\tNilai: " << current->data.nilai << endl;
            current = current->next;
            nomor++;
        }
    }
}

};

// Main function where the hash table is used.
int main() {
    HashTable ht;
    int pilih;
    while (true) {
        // Display menu options for interacting with the hash table.
        cout << "----------M E N U----------" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Cari Data berdasarkan NIM" << endl;
        cout << "4. Cari Data berdasarkan Rentang Nilai" << endl;
        cout << "5. Tampilkan Data" << endl;
        cout << "6. Keluar" << endl;
        cout << "--------------------------" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilih;

        // Switch statement to handle user input.
        switch (pilih) {
            case 1: {
                // Add data for a new student.
                long long nim;
                int nilai;
                cout << "Masukkan NIM: ";
                cin >> nim;
                cout << "Masukkan Nilai: ";
                cin >> nilai;
                Mahasiswa mhs = { nim, nilai };
                ht.tambah(mhs);
                cout << "Data mahasiswa berhasil ditambahkan." << endl;
                break;
            }
            case 2: {
                // Remove data for a student by their ID.
                long long nim;
                cout << "Masukkan NIM mahasiswa yang akan dihapus: ";
                cin >> nim;
                ht.hapus(nim);
                cout << "Data mahasiswa dengan NIM " << nim << " berhasil dihapus." << endl;
                break;
            }
            case 3: {
                // Search for a student by their ID and display their data.
                long long nim;
                cout << "Masukkan NIM mahasiswa yang akan dicari: ";
                cin >> nim;
                Mahasiswa* foundMhs = ht.cariNIM(nim);
                if (foundMhs != nullptr) {
                    cout << "Data mahasiswa dengan NIM " << nim << ":" << endl;
                    cout << "NIM: " << foundMhs->nim << "\tNilai: " << foundMhs->nilai << endl;
                } else {
                    cout << "Data mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
                }
                break;
            }
            case 4: {
                // Search for students within a specified score range and display their data.
                int NilaiMin, NilaiMax;
                cout << "Masukkan nilai minimum: ";
                cin >> NilaiMin;
                cout << "Masukkan nilai maksimum: ";
                cin >> NilaiMax;
                cout << "Data mahasiswa dengan nilai antara " << NilaiMin << " - " << NilaiMax << ":" << endl;
                ht.cariRentangNilai(NilaiMin, NilaiMax);
                break;
            }
            case 5: {
                // Display all student data in the hash table.
                cout << "Data Nilai mahasiswa:" << endl;
                ht.tampilkanData();
                break;
            }
            case 6: {
                // Exit the program.
                return 0;
            }
            default: {
                // Handle invalid input.
                cout << "Pilihan tidak tersedia." << endl;
                break;
            }
        }
        cout << endl;
    }
    return 0;
}

```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] Kautsar, I., Saleh, K. R. W., & Wulandari, G. S. (2019). Analisis Performansi Metode Graph Decomposition. e-Proceeding of Engineering, 2(1), 1730.<br/>
[2] Ramdhani, R., Fadlil, A., & Sunardi. (2022). Penerapan Algoritma Winnowing dan Word-Level Trigrams Untuk Mengidentifikasi Kesamaan Kata. JURIKOM (Jurnal Riset Komputer), 9(2), 427–435.<br/>
