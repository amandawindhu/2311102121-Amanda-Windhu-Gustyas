#include <iostream>
using namespace std;

struct Node {
    string namaMahasiswa;
    string nimMahasiswi;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
    int size;
public:
    Queue() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueueAntrian(string namaMahasiswa, string nimMahasiswi) {
        Node* newNode = new Node();
        newNode->namaMahasiswa = namaMahasiswa;
        newNode->nimMahasiswi = nimMahasiswi;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    void dequeueAntrian() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        size--;
    }

    int countQueue() {
        return size;
    }

    void clearQueue() {
        while (!isEmpty()) {
            dequeueAntrian();
        }
    }

    void viewQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
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
    Queue queue;
    queue.enqueueAntrian("Andi", "2311102121");
    queue.enqueueAntrian("Maya", "2311102127");
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;
    queue.dequeueAntrian();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;
    queue.clearQueue();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;
    return 0;
}
