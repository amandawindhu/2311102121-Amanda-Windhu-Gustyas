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
