# <h1 align="center">Laporan Praktikum Modul Queue</h1>
<p align="center">Amanda Windhu Gustyas - 2311102121</p>

## Dasar Teori

Berikan penjelasan teori terkait materi modul ini dengan bahasa anda sendiri serta susunan yang terstruktur per topiknya.

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
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

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

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

### 2. [ Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa]
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

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
