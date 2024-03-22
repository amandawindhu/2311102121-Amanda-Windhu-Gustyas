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
