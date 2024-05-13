# <h1 align="center">Laporan Praktikum Modul Queue</h1>
<p align="center">Amanda Windhu Gustyas - 2311102121</p>

## Dasar Teori

- Queue (Antrian)
Adalah suatu jenis struktur data yang dapat diproses dengan sifat FIFO (First In First Out), dimana elemen yang pertama kali masuk ke antrian akan keluar pertama kalinya. Ada dua jenis operasi yang bias dilakukan diantrian, yaitu enqueue (memasukkan elemen baru ke dalam elemen) dan dequeue (mengeluarkan satu elemen dari suatu antrian). Antrian dapat dibuat dengan menggunakan Liniear Array dan Circular Array.

- Ilustrasi Proses Queue<br/>
![Ilustrasi Proses Queue](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/16e72a7c-0f97-43d3-99ee-c8e618588490)<br/>
   
- Fungsi-Fungsi Pada Queue<br/>
  1. Fungsi Initialize :<br/>
     void initialize ( queue *q )<br/>
     {<br/>
         q -> jumlah = 0;<br/>
         q -> depan = 0;<br/>
         q -> belakang = 0;<br/>
     }<br/>
  2. Fungsi Is_Empty, yang antara lain digunakan untuk:<br/>
     a. Untuk memeriksa apakah antrian sudah penuh atau belum.>br/>
     b. Dengan cara memeriksa nilai Tail, jika Tail = -1 maka empty.<br/>
     c. Tidak perlu memeriksa Head, karena Head adalah tanda untuk kepala antrian (elemen
     pertama dalam antrian) yang tidak akan berubah.<br/>
  4. Fungsi Is_Full, berfungsi untuk:<br/>
     a. Untuk mengecek apakah antrian sudah penuh atau belum.<br/>
     b. Dengan cara mengecek nilai Tail, jika Tail >= MAX-1 (karena MAX-1 adalah batas elemen
     array pada C) berarti sudah penuh.<br/>
  6. Fungsi Enqueue, berfungsi untuk:<br/>
     a. Untuk menambahkan elemen ke dalam antrian, penambahan elemen selalu ditambahkan di
     elemen paling belakang.<br/>
     b. Penambahan elemen selalu menggerakan variabel Tail dengan cara increment counter
     Tail.<br/>
  8. Fungsi Dequeue, berfungsi untuk:<br/>
     a. Digunakan untuk menghapus elemen terdepan/pertama dari antrian.<br/>
     b. Dengan cara mengurangi counter Tail dan menggeser semua elemen antrian kedepan<br/>
     c. Penggeseran dilakukan dengan menggunakan looping.<br/>
  9. Fungsi Tampil berfungsi untuk menampilkan nilai-nilai elemen dalam antrian dam
     menggunakan looping dari head sampai tail.<br/>
  
- Perbedaan implementasi queue dengan linked list dan queue dengan array<br/>
  1. Implementasi queue dengan linked list memiliki kompleksitas pada pengimplementasian,
     sedangkan pada array implementasi sederhana.<br/>
  2. Pada linked list pengalokasian memori dinamis, sedangkan pada array ukuran memori harus
     ditentukan ketika sebuah objek queue dideklarasikan.<br/>
  3. Queue dengan linked list menggunakan 2 buah pointer, qFront dan qRear untuk menandai
     posisi depan dan belakang dari queue, sedangkan queue dengan array pemborosan tempat
     (memori) ketika menggunakan jumlah data yang lebih sedikit dari alokasi memory.<br/>

## Guided 

### 1. [Guided]

```C++
#include <iostream>
using namespace std;
const int maksimalQueue = 5; // Maksimal antrian
int front = 0; // Penanda antrian
int back = 0; // Penanda
string queueTeller[5]; // Fungsi pengecekan
bool isFull() { // Pengecekan antrian penuh atau tidak
if (back == maksimalQueue) {
return true; // =1
} else {
return false;
}
}
bool isEmpty() { // Antriannya kosong atau tidak
if (back == 0) {
return true;
} else {
return false;
}
}
void enqueueAntrian(string data) { // Fungsi menambahkan antrian
if (isFull()) {
cout << "Antrian penuh" << endl;
} else {
if (isEmpty()) { // Kondisi ketika queue kosong
queueTeller[0] = data;
front++;
back++;
} else { // Antrianya ada isi
queueTeller[back] = data;
back++;
}
}
}
void dequeueAntrian() { // Fungsi mengurangi antrian
if (isEmpty()) {
cout << "Antrian kosong" << endl;
} else {
for (int i = 0; i < back; i++) {
queueTeller[i] = queueTeller[i + 1];
}
back--;
}
}
int countQueue() { // Fungsi menghitung banyak antrian
return back;
}
void clearQueue() { // Fungsi menghapus semua antrian
if (isEmpty()) {
cout << "Antrian kosong" << endl;
} else {
for (int i = 0; i < back; i++) {
queueTeller[i] = "";
}
back = 0;
front = 0;
}
}
void viewQueue() { // Fungsi melihat antrian
cout << "Data antrian teller:" << endl;
for (int i = 0; i < maksimalQueue; i++) {
if (queueTeller[i] != "") {
cout << i + 1 << ". " << queueTeller[i] <<
endl;
} else {
cout << i + 1 << ". (kosong)" << endl;
}
}
}
int main() {
enqueueAntrian("Andi");
enqueueAntrian("Maya");
viewQueue();
cout << "Jumlah antrian = " << countQueue() << endl;
dequeueAntrian();
viewQueue();
cout << "Jumlah antrian = " << countQueue() << endl;
clearQueue();
viewQueue();
cout << "Jumlah antrian = " << countQueue() << endl;
return 0;
}
```
Kode C++ di atas mengimplementasikan struktur data antrian sederhana, di mana elemen ditambahkan dan dihapus dengan cara first-in-first-out (FIFO). Program ini menggunakan array string untuk menyimpan elemen dalam antrian, dengan kapasitas maksimum lima elemen yang ditentukan oleh konstanta . Program ini mencakup fungsi untuk memeriksa apakah antrian penuh atau kosong, menambahkan elemen ke akhir antrian, menghapus elemen dari depan antrian, menghitung jumlah elemen dalam antrian, membersihkan antrian, dan menampilkan elemen dalam antrian. `maksimalQueue` `enqueueAntrian` `dequeueAntrian` `count Queue` `clearQueue` `viewQueue`<br/>
Program dimulai dengan menginisialisasi antrian dengan dua elemen, "Andi" dan "Maya", menggunakan fungsi tersebut. Fungsi tersebut kemudian dipanggil untuk menampilkan status antrian saat ini, menunjukkan dua elemen yang ditambahkan. Fungsi tersebut digunakan untuk menghitung jumlah elemen dalam antrian yang saat ini berjumlah dua. `enqueueAntrian` `viewQueue` `count Queue`<br/>
Selanjutnya fungsi tersebut dipanggil untuk menghapus elemen depan dari antrian, yaitu "Andi". Fungsi ini dipanggil lagi untuk menampilkan status antrian yang diperbarui, hanya menampilkan satu elemen, "Maya". Fungsi tersebut digunakan kembali untuk menghitung jumlah elemen dalam antrian, yang sekarang menjadi satu. `dequeueAntrian` `viewQueue` `count Queue`<br/>
Terakhir, fungsi dipanggil untuk menghapus semua elemen dari antrian, dan fungsi dipanggil sekali lagi untuk menampilkan antrian kosong. Fungsi tersebut digunakan kembali untuk mengonfirmasi bahwa antrian kini kosong. `clearQueue` `viewQueue` `countQueue`<br/>

## Unguided 

### 1. [Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list]

```C++
// Oleh Amanda Windhu Gustyas_2311102121
#include <iostream> 
using namespace std;

// Define a struct for a node in the queue
struct Node {
    string data;
    Node* next;
};

// Define a class for a queue
class Queue {
private:
    // Initialize front and rear pointers to null
    Node* front;
    Node* rear;
    // Initialize the size of the queue to 0
    int size;

public:
    // Initialize the queue with front and rear pointers to null and size to 0
    Queue() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Add an element to the end of the queue
    void enqueueAntrian(string data) {
        // Create a new node with the given data
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        
        // If the queue is empty, set both front and rear to the new node
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            // Otherwise, set the next node of the current rear to the new node and update the rear
            rear->next = newNode;
            rear = newNode;
        }
        // Increment the size of the queue
        size++;
    }

    // Remove the element from the front of the queue
    void dequeueAntrian() {
        // If the queue is empty, print an error message
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        // Store the front node in a temporary variable
        Node* temp = front;
        // Update the front to the next node in the queue
        front = front->next;
        // Delete the temporary node
        delete temp;
        // Decrement the size of the queue
        size--;
    }

    // Return the number of elements in the queue
    int countQueue() {
        return size;
    }

    // Clear the queue by removing all elements
    void clearQueue() {
        // Continue removing elements until the queue is empty
        while (!isEmpty()) {
            dequeueAntrian();
        }
    }

    // Display the elements in the queue
    void viewQueue() {
        // If the queue is empty, print an error message
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        // Print the elements in the queue
        cout << "Data antrian teller:" << endl;
        Node* current = front;
        int i = 1;
        while (current != nullptr) {
            cout << i << ". " << current->data << endl;
            current = current->next;
            i++;
        }
    }
};

int main() {
    // Create a new queue
    Queue queue;
    // Add elements to the queue
    queue.enqueueAntrian("Andi");
    queue.enqueueAntrian("Maya");
    // Display the queue
    queue.viewQueue();
    // Print the number of elements in the queue
    cout << "Jumlah antrian = " << queue.countQueue() << endl;
    // Remove an element from the queue
    queue.dequeueAntrian();
    // Display the queue
    queue.viewQueue();
    // Print the number of elements in the queue
    cout << "Jumlah antrian = " << queue.countQueue() << endl;
    // Clear the queue
    queue.clearQueue(); 
    // Display the queue
    queue.viewQueue();
    // Print the number of elements in the queue
    cout << "Jumlah antrian = " << queue.countQueue() << endl;
    return 0;
}
```
#### Output:
![SS_Unguided1](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/2b96e69c-6aa2-46eb-a062-8b6c5aea8c6c)

Kode C++ di atas mengimplementasikan struktur data antrian sederhana menggunakan linked list. Antrian dirancang untuk mengatur urutan elemen, dimana elemen ditambahkan ke akhir antrian (enqueue) dan dikeluarkan dari depan antrian (dequeue). Program ini mencakup fungsi untuk memeriksa apakah antrian kosong, menambah elemen, menghapus elemen, menampilkan elemen, dan menghapus antrian.<br/>
Program dimulai dengan mendefinisikan sebuah struct untuk setiap elemen dalam linked list, yang mencakup string dan penunjuk ke node berikutnya. Kelas Queue kemudian didefinisikan, yang mencakup anggota pribadi untuk melacak node depan dan belakang dalam antrian, dan untuk melacak jumlah elemen dalam antrian.
Kelas Queue menyertakan beberapa metode publik untuk mengelola antrian. Metode isEmpty memeriksa apakah antrian kosong dengan memeriksa apakah penunjuk depan bernilai nol. Metode enqueue menambahkan elemen baru ke akhir antrian dengan membuat node baru dengan data yang diberikan dan memperbarui penunjuk belakang agar menunjuk ke node baru. Metode dequeue menghapus elemen dari depan antrian dengan memperbarui penunjuk depan agar menunjuk ke node berikutnya dan menghapus node yang dihapus. Metode count mengembalikan jumlah elemen dalam antrian dengan mengembalikan variabel ukuran. Metode clear menghapus semua elemen dari antrian dengan memanggil dequeue berulang kali hingga antrian kosong. Metode view menampilkan elemen-elemen dalam antrian dengan melintasi linked list dari node depan ke node belakang.<br/>
Dalam fungsi main, objek Antrian baru dibuat dan beberapa operasi dilakukan. Program menambahkan dua elemen ke antrian menggunakan enqueue, menampilkan antrian menggunakan view, mencetak jumlah elemen dalam antrian menggunakan count, menghapus satu elemen dari antrian menggunakan dequeue, menampilkan kembali antrian, mencetak jumlah elemen dalam antrian, hapus antrian menggunakan clear, dan menampilkan antrian sekali lagi.<br/>

### 2. [Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa]

``` C++
// Oleh Amanda Windhu Gustyas_2311102121
#include <iostream>
using namespace std;

// Define a struct for a node in the queue
struct Node {
    // Store the name and NIM of a student
    string namaMahasiswa;
    string nimMahasiswi;
    // Pointer to the next node in the queue
    Node* next;
};

// Define a class for a queue
class Queue {
private:
    // Initialize front and rear pointers to null
    Node* front;
    Node* rear;
    // Initialize the size of the queue to 0
    int size;

public:
    // Initialize the queue with front and rear pointers to null and size to 0
    Queue() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Add a student to the end of the queue
    void enqueueAntrian(string namaMahasiswa, string nimMahasiswi) {
        // Create a new node with the given student details
        Node* newNode = new Node();
        newNode->namaMahasiswa = namaMahasiswa;
        newNode->nimMahasiswi = nimMahasiswi;
        newNode->next = nullptr;
        
        // If the queue is empty, set both front and rear to the new node
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            // Otherwise, set the next node of the current rear to the new node and update the rear
            rear->next = newNode;
            rear = newNode;
        }
        // Increment the size of the queue
        size++;
    }

    // Remove the student from the front of the queue
    void dequeueAntrian() {
        // If the queue is empty, print an error message
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        // Store the front node in a temporary variable
        Node* temp = front;
        // Update the front to the next node in the queue
        front = front->next;
        // Delete the temporary node
        delete temp;
        // Decrement the size of the queue
        size--;
    }

    // Return the number of students in the queue
    int countQueue() {
        return size;
    }

    // Clear the queue by removing all students
    void clearQueue() {
        // Continue removing students until the queue is empty
        while (!isEmpty()) {
            dequeueAntrian();
        }
    }

    // Display the students in the queue
    void viewQueue() {
        // If the queue is empty, print an error message
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        // Print the students in the queue
        cout << "Data antrian teller:" << endl;
        Node* current = front;
        int i = 1;
        while (current != nullptr) {
            cout << i << ". Nama Mahasiswa: " << current->namaMahasiswa << ", NIM Mahasiswi: " << current->nimMahasiswi << endl;
            current = current->next;
            i++;
        }
    }
};

int main() {
    // Create a new queue
    Queue queue;
    // Add students to the queue
    queue.enqueueAntrian("Andi", "2311102121");
    queue.enqueueAntrian("Maya", "2311102127");
    // Display the queue
    queue.viewQueue();
    // Print the number of students in the queue
    cout << "Jumlah antrian = " << queue.countQueue() << endl;
    // Remove a student from the queue
    queue.dequeueAntrian();
    // Display the queue
    queue.viewQueue();
    // Print the number of students in the queue
    cout << "Jumlah antrian = " << queue.countQueue() << endl;
    // Clear the queue
    queue.clearQueue();
    // Display the queue
    queue.viewQueue();
    // Print the number of students in the queue
    cout << "Jumlah antrian = " << queue.countQueue() << endl;
    return 0;
}
```

#### Output:
![SS_Unguided2](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/dc63945b-d1e4-4a8c-bb13-980a034a583c)

Program di atas merupakan implementasi sederhana dari struktur data antrian di C++. Hal ini memungkinkan pengguna untuk menambahkan siswa ke akhir antrian, menghapus siswa dari depan antrian, dan menampilkan antrian saat ini. Antrian diwakili oleh linked list dimana setiap node berisi nama dan NIM siswa. Program ini mencakup metode untuk memeriksa apakah antrian kosong, menambah siswa, mengeluarkan siswa, menghitung jumlah siswa, mengosongkan antrian, dan menampilkan antrian. Ini menunjukkan operasi dasar pada antrian, seperti menambah dan menghapus elemen, dan menampilkan keadaan antrian saat ini.<br/>

## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] Sihombing, Johnson. (2020). Penerapan Stack dan Queue pada Array dan Linked List. Program Studi Manajemen Informatika, Politeknik Piksi Ganesha. Bandung.<br/>
[2] Gunawan, R., Yuana, H., & Kirom, S. (2023). Implementasi Metode Queue pada Sistem Antrian Online Berbasis Web: Studi Kasus UPTD Puskesmas Sananwetan. ATI
    (Jurnal Mahasiswa Teknik Informatika), 7(3), 1538.<br/>
