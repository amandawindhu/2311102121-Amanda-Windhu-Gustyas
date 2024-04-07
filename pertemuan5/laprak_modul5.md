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
-> Solusi alternatif untuk menyelesaikan tabrakan yang berkualifikasi menginduksi klasifikasi struktur data hash table. Sebagian besar implementasi mengikuti         salah satu dari dua strategi alternatif ini:<br/>
    1.Penyisipan Terbuka (Open Addressing): Ketika terjadi tabrakan yang berkualifikasi, tempat lain dicari mengikuti strategi penyelusuran, misalnya:
    penyelusuran linear, hashing ganda, dll. Fitur pentingnya adalah bahwa paling banyak satu pasangan  disimpan dalam larik (di dalam bucket).<br/>
    2.Chaining: Ketika terjadi tabrakan yang berkualifikasi, pasangan tersebut tetap disimpan di slot larik tersebut. Artinya, bucket tidak menyimpan pasangan
    secara  langsung, tetapi menggunakan struktur data lain yang mampu menyimpan beberapa pasangan, biasanya daftar berantai, tetapi juga struktur data lain
    seperti pohon biner.<br/>
    Dalam kedua kasus tersebut, tujuannya adalah untuk menangani tabrakan yang mungkin terjadi saat menggunakan fungsi hash untuk memetakan kunci ke indeks dalam
    hash table. Dengan demikian, baik penyisipan terbuka maupun chaining adalah strategi untuk mengatasi tabrakan, tetapi dengan pendekatan yang berbeda.<br/>

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
Program di atas memanfaatkan array dinamis "table" untuk menyimpan bucket dalam hash table. Setiap bucket direpresentasikan sebagai sebuah linked list, di mana setiap node mewakili satu item data. Fungsi hash sederhana digunakan untuk memetakan setiap kunci input ke nilai indeks array menggunakan operasi modulus.<br/>

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
Pada program di atas, HashNode adalah kelas yang digunakan untuk mewakili setiap simpul (node) dalam tabel hash. Setiap simpul memiliki atribut nama 
dan nomor telepon karyawan. HashMap adalah kelas yang digunakan untuk mengimplementasikan struktur tabel hash dengan menggunakan vektor yang 
menyimpan pointer ke HashNode. Fungsi hashFunc digunakan untuk menghitung nilai hash dari nama karyawan yang diberikan. Fungsi insert digunakan untuk menambahkan data baru ke dalam tabel hash. Jika nama karyawan sudah ada dalam tabel, nomor telepon akan diperbarui. Fungsi remove digunakan untuk menghapus data dari tabel 
hash berdasarkan nama karyawan. Fungsi searchByName digunakan untuk mencari nomor telepon karyawan berdasarkan nama yang diberikan Dalam program ini, pengguna dapat menyisipkan data karyawan, mencari nomor telepon karyawan berdasarkan nama, dan menghapus data karyawan. Seluruh tabel hash kemudian dicetak untuk menampilkan data yang tersimpan.<br/>

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
1. Tampilan Menu<br/>
![Tampilan menu](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/63ed56a7-6ab2-4155-b7ea-adb89a2872d4)<br/>
2. Tambah Data<br/>
![Tambah Data](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/c431b5de-8bc5-4699-adc0-fd8bca3aeded)<br/>
![Tambah Data_1](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/157e760d-25ec-403d-a418-a206bc7c8337)<br/>
![Tambah Data_2](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/f17efad2-5a88-44e3-b4ae-08a75539caf8)<br/>
![Tambah Data_3](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/5df454a5-549c-443a-bc06-4f290e9939e9)<br/>
![Tambah Data_4](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/331ccba3-c87f-40dd-9813-3a7955cb3009)<br/>
![Tambah Data_5](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/9130ff58-52a5-4d68-8713-93e563fb1fa1)<br/>
3. Hapus Data<br/>
![Hapus Data](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/8a804957-89c6-434b-adaa-1f3234b759ad)<br/>
4. Cari Data berdasarkan NIM<br/>
![Cari Data NIM](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/78b4f62e-968e-439c-8496-4163766c91f6)<br/>
5. Cari Data berdasarkan Rentang Nilai<br/>
![Cari Data Rentang Nilai](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/98dd8e8e-b5c0-4c92-9b58-38867cbf1801)<br/>
6. Tampilkan Data<br/>
![Tampilkan Data](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/d3e7b23b-65ca-4c58-8c9d-ed05581e27b1)<br/>

Program di atas adalah implementasi sederhana dari struktur data tabel hash dalam bahasa C++. Program ini memungkinkan pengguna untuk menambahkan data mahasiswa (NIM dan nilai), menghapus data mahasiswa berdasarkan NIM, mencari data mahasiswa berdasarkan NIM, mencari data mahasiswa berdasarkan rentang nilai, dan menampilkan seluruh data mahasiswa yang disimpan dalam tabel hash.<br/>
Struktur Data Mahasiswa ```Mahasiswa``` merupakan struktur data yang berisi dua anggota: NIM dan nilai. Fungsi Hash ```hash_func``` merupakan fungsi hash sederhana yang menggunakan metode modulus untuk memetakan NIM ke indeks dalam tabel hash. Struktur Data Node ```Node``` merupakan struktur data untuk node dalam tabel hash yang menyimpan data mahasiswa dan pointer ke node berikutnya (untuk menangani tabrakan menggunakan chaining). Kelas Tabel Hash ```HashTable``` merupakan kelas yang mewakili tabel hash, menyediakan metode untuk menambahkan, mencari, menghapus, dan menampilkan data mahasiswa dan menggunakan penyisipan chaining untuk menangani tabrakan.<br/>
Fungsi ```main``` untuk menampilkan menu kepada pengguna dan memungkinkan pengguna untuk memilih operasi yang ingin dilakukan pada tabel hash, menggunakan switch statement untuk menangani pilihan pengguna dan memanggil metode yang sesuai pada kelas HashTable.<br/>
Program ini memberikan pengguna kemampuan untuk mengelola data mahasiswa secara efisien menggunakan struktur data tabel hash.<br/>

## Kesimpulan
Hash table adalah struktur data yang digunakan untuk menyimpan data dan mempermudah proses pencarian. Hash table terdiri dari dua komponen: key dan value. Key digunakan untuk mengakses data yang disimpan dan bersifat unik. Hash table biasanya direpresentasikan sebagai associative array. Tujuan hash table adalah untuk mempercepat pencarian kembali dari banyak data yang disimpan. Hash table menyediakan beberapa operasi dasar untuk memanipulasi data, seperti: Insert, search, delete, dan rehashing. Solusi untuk menangani tabrakan hash table yaitu open addresing dan chaining.<br/>
Keuntungan menggunakan hash table:<br/>
- Pencarian data yang cepat<br/>
- Penyimpanan data yang efisien<br/>
- Mendukung operasi insert, delete, dan search dengan waktu konstan<br/>
Kekurangan menggunakan hash table:<br/>
- Kinerja dapat menurun saat terjadi banyak tabrakan<br/>
- Membutuhkan fungsi hash yang baik<br/>

## Referensi
[1] Kautsar, I., Saleh, K. R. W., & Wulandari, G. S. (2019). Analisis Performansi Metode Graph Decomposition. e-Proceeding of Engineering, 2(1), 1730.<br/>
[2] Ramdhani, R., Fadlil, A., & Sunardi. (2022). Penerapan Algoritma Winnowing dan Word-Level Trigrams Untuk Mengidentifikasi Kesamaan Kata. JURIKOM (Jurnal Riset Komputer), 9(2), 427–435.<br/>
