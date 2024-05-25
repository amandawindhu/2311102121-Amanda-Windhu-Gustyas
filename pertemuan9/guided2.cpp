#include <iostream>
using namespace std;


// Struktur untuk merepresentasikan node dalam pohon
struct Pohon {
    char data;
    Pohon* left, * right, * parent;
};
// Pointer ke root dari pohon
Pohon* root, * baru;

// Inisialisasi pohon
void init() {
    root = NULL;
}

// Memeriksa apakah pohon kosong
int isEmpty() {
    return root == NULL;
}


// Membuat node baru dan menentukan apakah akan menjadi root atau tidak
void buatNode(char data) {
    if (isEmpty()) {
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\n Node " << data << " berhasil dibuat menjadi root." << endl;
    } else {
        cout << "\n Pohon sudah dibuat" << endl;
    }
}

// Menyisipkan node sebagai anak kiri dari node tertentu
Pohon* insertLeft(char data, Pohon* node) {
    if (isEmpty()) {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->left != NULL) {
            cout << "\n Node " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        } else {
            baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
            return baru;
        }
    }
}

// Menyisipkan node sebagai anak kanan dari node tertentu
Pohon* insertRight(char data, Pohon* node) {
    if (isEmpty()) {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->right != NULL) {
            cout << "\n Node " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        } else {
            baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
            return baru;
        }
    }
}

// Memperbarui data dari node yang dituju
void update(char data, Pohon* node) {
    if (isEmpty()) {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\n Node yang ingin diganti tidak ada!!" << endl;
        } else {
            char temp = node->data;
            node->data = data;
            cout << "\n Node " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

// Mengambil data dari node yang dituju
void retrieve(Pohon* node) {
    if (!root) {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\n Data node : " << node->data << endl;
        }
    }
}

// Mencetak informasi tentang node yang dituju
void find(Pohon* node) {
    if (!root) {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\n Data Node : " << node->data << endl;
            cout << " Root : " << root->data << endl;
            if (!node->parent)
                cout << " Parent : (tidak punya parent)" << endl;
            else
                cout << " Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << " Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << " Sibling : " << node->parent->right->data << endl;
            else
                cout << " Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << " Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << " Child Kiri : " << node->left->data << endl;
            if (!node->right)
                cout << " Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << " Child Kanan : " << node->right->data << endl;
        }
    }
}


// Fungsi untuk melakukan penelusuran pre-order pada pohon
void preOrder(Pohon* node) {
    if (!root) {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// Fungsi untuk melakukan penelusuran in-order pada pohon
void inOrder(Pohon* node) {
    if (!root) {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

// Fungsi untuk melakukan penelusuran post-order pada pohon
void postOrder(Pohon* node) {
    if (!root) {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}


// Fungsi untuk menghapus seluruh pohon
void deleteTree(Pohon* node) {
    if (node != NULL) {
        if (node->left != NULL) {
            deleteTree(node->left);
            node->left = NULL;
        }
        if (node->right != NULL) {
            deleteTree(node->right);
            node->right = NULL;
        }
        if (node == root) {
            delete root;
            root = NULL;
        } else {
            delete node;
        }
    }
}

// Fungsi untuk menghapus semua anak dari suatu node
void deleteSub(Pohon* node) {
    if (!root) {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    } else {
        if (node->left != NULL) {
            deleteTree(node->left);
            node->left = NULL;
        }
        if (node->right != NULL) {
            deleteTree(node->right);
            node->right = NULL;
        }
        if (node == root) {
            root = NULL;
        }
    }
}

// Fungsi untuk membersihkan seluruh pohon
void clear() {
    if (!root) {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    } else {
        deleteTree(root);
        cout << "\n Pohon berhasil dihapus." << endl;
    }
}

// Fungsi untuk menghitung jumlah node dalam pohon
int size(Pohon* node) {
    if (node == NULL)
        return 0;
    else
        return 1 + size(node->left) + size(node->right);
}

// Fungsi untuk menghitung tinggi dari pohon
int height(Pohon* node) {
    if (node == NULL)
        return 0;
    else {
        int heightKiri = height(node->left);
        int heightKanan = height(node->right);
        return (heightKiri >= heightKanan) ? heightKiri + 1 : heightKanan + 1;
    }
}

// Fungsi untuk mencetak karakteristik dari pohon
void characteristic() {
    int sz = size(root);
    int ht = height(root);
    cout << "\n Size Tree : " << sz << endl;
    cout << " Height Tree : " << ht << endl;
    cout << " Average Node of Tree : " << (ht == 0 ? 0 : sz / ht) << endl;
}

int main() {
    init();  // Inisialisasi pohon

    // Membuat beberapa simpul dan menyisipkan mereka ke dalam pohon
    buatNode('A');
    Pohon* nodeB, * nodeC, * nodeD, * nodeE, * nodeF, * nodeG, * nodeH, * nodeI, * nodeJ;
    nodeB = insertLeft('B', root);
    nodeC = insertRight('C', root);
    nodeD = insertLeft('D', nodeB);
    nodeE = insertRight('E', nodeB);
    nodeF = insertLeft('F', nodeC);
    nodeG = insertLeft('G', nodeE);
    nodeH = insertRight('H', nodeE);
    nodeI = insertLeft('I', nodeG);
    nodeJ = insertRight('J', nodeG);

    // Memperbarui dan menampilkan data simpul C
    update('Z', nodeC);
    update('C', nodeC);
    retrieve(nodeC);

    // Menampilkan informasi tentang simpul C dan karakteristik pohon
    find(nodeC);
    characteristic();

    // Menampilkan penelusuran pohon dalam pre-order, in-order, dan post-order
    cout << "\n PreOrder :" << endl;
    preOrder(root);
    cout << "\n" << endl;
    cout << " InOrder :" << endl;
    inOrder(root);
    cout << "\n" << endl;
    cout << " PostOrder :" << endl;
    postOrder(root);
    cout << "\n" << endl;
}
