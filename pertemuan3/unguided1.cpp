// oleh Amanda Windhu Gustyas
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
int hitungList() {
    int jumlah = 0;
    Node* hitung = head;
    while (hitung != nullptr) {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

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

// ubah data node
void ubahData(string namaCari, string namaBaru, int usiaBaru) {
    Node* bantu = head;
    while (bantu != nullptr) {
        if (bantu->nama == namaCari) {
            bantu->nama = namaBaru;
            bantu->usia = usiaBaru;
            return;
        }
        bantu = bantu->next;
    }
    cout << "Data tidak ditemukan!" << endl;
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

    // Masukkan data mahasiswa
    cout << "Masukkan data mahasiswa sesuai urutan berikut:" << endl;
    cout << "[Nama] [Usia]" << endl;
    string nama;
    int usia;
    while (true) {
        cout << "Masukkan nama : ";
        cin >> nama;
        if (nama == "stop") break; // apabila menginputkan stop, maka perulangan berhenti
        cout << "Masukkan usia : ";
        cin >> usia;
        insertBelakang(nama, usia);
    }

    // a. Hapus data
    cout << "Masukkan nama mahasiswa yang ingin dihapus: ";
    cin >> nama;
    hapusTengah(nama);

    // b. Tambahkan data
    cout << "Masukkan nama mahasiswa yang ingin ditambahkan: ";
    cin >> nama;
    cout << "Masukkan usia : ";
    cin >> usia;
    insertTengah(nama, usia, 2);

    // c. Tambahkan data di awal
    cout << "Masukkan nama mahasiswa yang ingin ditambahkan di awal: ";
    cin >> nama;
    cout << "Masukkan usia : ";
    cin >> usia;
    insertDepan(nama, usia);

    // d. Ubah data
    string namaCari, namaBaru;
    int usiaBaru;
    cout << "Masukkan nama mahasiswa yang ingin diubah datanya: ";
    cin >> namaCari;
    cout << "Masukkan nama baru: ";
    cin >> namaBaru;
    cout << "Masukkan usia baru: ";
    cin >> usiaBaru;
    ubahData(namaCari, namaBaru, usiaBaru);

    // e. Tampilkan seluruh data
    cout << "Data Mahasiswa:" << endl;
    tampil();

    return 0;
}

