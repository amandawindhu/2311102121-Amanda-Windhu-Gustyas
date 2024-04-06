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
