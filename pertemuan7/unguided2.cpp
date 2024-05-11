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