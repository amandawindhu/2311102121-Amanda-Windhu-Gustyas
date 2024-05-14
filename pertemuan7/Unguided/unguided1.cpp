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