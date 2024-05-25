// Oleh Amanda Windhu Gustyas_2311102121
#include <iostream>
using namespace std;
// Definisi struktur Pohon
struct Pohon {
    char data;
    Pohon* left;
    Pohon* right;
    Pohon* parent;
};

Pohon* root; // Pointer ke simpul root
Pohon* baru; // Pointer untuk simpul baru

// Fungsi inisialisasi untuk mengatur root menjadi null
void init() {
    root = nullptr;
}

// Fungsi untuk memeriksa apakah pohon kosong
bool isEmpty() {
    return root == nullptr;
}

// Fungsi untuk membuat simpul baru sebagai root
void buatNode(char data) {
    if (isEmpty()) {
        root = new Pohon();
        root->data = data;
        root->left = nullptr;
        root->right = nullptr;
        root->parent = nullptr;
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    } else {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

// Fungsi untuk menyisipkan simpul baru sebagai anak kiri dari simpul tertentu
Pohon* insertLeft(char data, Pohon* node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return nullptr;
    } else {
        if (node->left != nullptr) {
            cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
            return nullptr;
        } else {
            baru = new Pohon();
            baru->data = data;
            baru->left = nullptr;
            baru->right = nullptr;
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
            return baru;
        }
    }
}


// Fungsi untuk menyisipkan simpul baru sebagai anak kanan dari simpul tertentu
Pohon* insertRight(char data, Pohon* node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return nullptr;
    } else {
        if (node->right != nullptr) {
            cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
            return nullptr;
        } else {
            baru = new Pohon();
            baru->data = data;
            baru->left = nullptr;
            baru->right = nullptr;
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
            return baru;
        }
    }
}

// Fungsi untuk memperbarui data pada simpul tertentu
void update(char data, Pohon* node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        } else {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}


// Fungsi untuk mendapatkan data dari simpul tertentu
void retrieve(Pohon* node) {
    if (!root) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\nData node: " << node->data << endl;
        }
    }
}

void find(Pohon* node) {
    if (!root) { // Mengecek apakah pohon telah dibuat
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {  // Mengecek apakah node yang ditunjuk tidak ada
        if (!node) {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        } else {   // Menampilkan informasi tentang node yang ditunjuk
            cout << "\nData Node: " << node->data << endl;
            cout << "Root: " << root->data << endl;

            // Menampilkan informasi tentang parent dari node yang ditunjuk
            if (!node->parent)
                cout << "Parent: (tidak punya parent)" << endl;
            else
                cout << "Parent: " << node->parent->data << endl;

            // Menampilkan informasi tentang sibling dari node yang ditunjuk
            if (node->parent != nullptr && node->parent->left != node && node->parent->right == node)
                cout << "Sibling: " << node->parent->left->data << endl;
            else if (node->parent != nullptr && node->parent->right != node && node->parent->left == node)
                cout << "Sibling: " << node->parent->right->data << endl;
            else
                cout << "Sibling: (tidak punya sibling)" << endl;

            // Menampilkan informasi tentang child kiri dari node yang ditunjuk
            if (!node->left)
                cout << "Child Kiri: (tidak punya Child kiri)" << endl;
            else
                cout << "Child Kiri: " << node->left->data << endl;
            
             // Menampilkan informasi tentang child kanan dari node yang ditunjuk
            if (!node->right)
                cout << "Child Kanan: (tidak punya Child kanan)" << endl;
            else
                cout << "Child Kanan: " << node->right->data << endl;
        }
    }
}

// Fungsi untuk melakukan traversal pre-order dari pohon
void preOrder(Pohon* node) {
    if (!root) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != nullptr) {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// Fungsi untuk melakukan traversal pre-order dari pohon
void inOrder(Pohon* node) {
    if (!root) { // Mengecek apakah pohon telah dibuat
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != nullptr) {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

// Fungsi untuk melakukan traversal post-order dari pohon
void postOrder(Pohon* node) {
    if (!root) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != nullptr) {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}

// Fungsi untuk menghapus seluruh pohon
void deleteTree(Pohon* node) {
    if (node != nullptr) {
        if (node->left != nullptr) {
            deleteTree(node->left);
            node->left = nullptr;
        }
        if (node->right != nullptr) {
            deleteTree(node->right);
            node->right = nullptr;
        }
        if (node == root) {
            delete root;
            root = nullptr;
        } else {
            delete node;
        }
    }
}

// Fungsi untuk menghapus subtree dari suatu node
void deleteSub(Pohon* node) {
    if (!root) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node->left != nullptr) {
            deleteTree(node->left);
            node->left = nullptr;
        }
        if (node->right != nullptr) {
            deleteTree(node->right);
            node->right = nullptr;
        }
        if (node == root) {
            root = nullptr;
        }
    }
}

// Fungsi untuk membersihkan seluruh pohon
void clear() {
    if (!root) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

// Fungsi untuk menghitung ukuran pohon
int size(Pohon* node) {
    if (node == nullptr)
        return 0;
    else
        return 1 + size(node->left) + size(node->right);
}

// Fungsi untuk menghitung tinggi pohon
int height(Pohon* node) {
    if (node == nullptr)
        return 0;
    else {
        int heightKiri = height(node->left);
        int heightKanan = height(node->right);
        return (heightKiri >= heightKanan) ? heightKiri + 1 : heightKanan + 1;
    }
}

// Fungsi untuk menampilkan karakteristik pohon (ukuran, tinggi, rata-rata node)
void characteristic() {
    int sz = size(root);
    int ht = height(root);
    cout << "\nSize Tree: " << sz << endl;
    cout << "Height Tree: " << ht << endl;
    cout << "Average Node of Tree: " << (ht == 0 ? 0 : sz / ht) << endl;
}

// Fungsi untuk mencari node dalam pohon berdasarkan nilai
Pohon* findNode(Pohon* node, char value) {
    if (!node) return nullptr;
    if (node->data == value) return node;
    Pohon* foundNode = findNode(node->left, value);
    if (foundNode) return foundNode;
    return findNode(node->right, value);
}

// Fungsi untuk menampilkan menu interaksi pengguna
void displayMenu() {
    cout << "----------MENU----------" << endl;
    cout << "1. Buat Tree\n";
    cout << "2. Tambah Child Kiri\n";
    cout << "3. Tambah Child Kanan\n";
    cout << "4. Ubah Data Node\n";
    cout << "5. Tampilkan Data Node\n";
    cout << "6. Cari Node\n";
    cout << "7. Traversal Preorder\n";
    cout << "8. Traversal Inorder\n";
    cout << "9. Traversal Postorder\n";
    cout << "10. Hapus Subtree\n";
    cout << "11. Hapus Tree\n";
    cout << "12. Tampilkan Karakteristik Tree\n";
    cout << "13. Keluar\n";
}

int main() {
    init(); // Inisialisasi pohon
    int amanda_2311102121;
    char data, parentData;
    Pohon* parentNode; // Pointer ke parent node

    while (true) {
        displayMenu();  // Menampilkan menu
        cout << "Pilih opsi: ";
        cin >> amanda_2311102121;

        switch (amanda_2311102121) {
            case 1: // Menambahkan root ke pohon
                cout << "Masukkan nilai root: ";
                cin >> data;
                buatNode(data);
                break;
            case 2: // Menambahkan child kiri ke suatu node
                cout << "Masukkan nilai parent: ";
                cin >> parentData;
                parentNode = findNode(root, parentData);
                cout << "Masukkan nilai node kiri baru: ";
                cin >> data;
                insertLeft(data, parentNode);
                break;
            case 3: // Menambahkan child kanan ke suatu node
                cout << "Masukkan nilai parent: ";
                cin >> parentData;
                parentNode = findNode(root, parentData);
                cout << "Masukkan nilai node kanan baru: ";
                cin >> data;
                insertRight(data, parentNode);
                break;
            case 4: // Mengubah nilai suatu node
                cout << "Masukkan nilai node yang ingin diubah: ";
                cin >> parentData;
                parentNode = findNode(root, parentData);
                cout << "Masukkan nilai baru: ";
                cin >> data;
                update(data, parentNode);
                break;
            case 5: // Menampilkan nilai suatu node
                cout << "Masukkan nilai node: ";
                cin >> data;
                parentNode = findNode(root, data);
                retrieve(parentNode);
                break;
            case 6: // Mencari node dalam pohon berdasarkan nilai
                cout << "Masukkan nilai node yang ingin dicari: ";
                cin >> data;
                parentNode = findNode(root, data);
                find(parentNode);
                break;
            case 7: // Traversal pre-order dari pohon
                cout << "\nPreorder traversal: ";
                preOrder(root);
                cout << endl;
                break;
            case 8: // Traversal in-order dari pohon
                cout << "\nInorder traversal: ";
                inOrder(root);
                cout << endl;
                break;
            case 9: // Traversal post-order dari pohon
                cout << "\nPostorder traversal: ";
                postOrder(root);
                cout << endl;
                break;
            case 10: // Menghapus subtree dari suatu node
                cout << "Masukkan nilai node subtree yang ingin dihapus: ";
                cin >> data;
                parentNode = findNode(root, data);
                deleteSub(parentNode);
                break;
            case 11: // Menghapus seluruh pohon
                clear();
                break;
            case 12:  // Menampilkan karakteristik pohon
                characteristic();
                break;
            case 13: // Keluar dari program
                return 0;
            default:
                cout << "Pilihan tidak valid, coba lagi." << endl;
                break;
        }
    }

    return 0;
}

