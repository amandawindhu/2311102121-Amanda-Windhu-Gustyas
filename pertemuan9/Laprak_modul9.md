# <h1 align="center">Laporan Praktikum Modul Graph dan Tree</h1>
<p align="center">Amanda Windhu Gustyas -  2311102121</p>

## Dasar Teori

### 1. Graph<br/>
![graf1](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/c4db0f7b-3f06-4d51-bafe-87651feb3704)<br/>
Graf didefinisikan sebagai pasangan himpunan (V,E), yang dalam hal ini V adalah himpunan tidak kosong dari simpul-simpul (verticers atau node) = {v1, v2, v3,...} dan E himpunan sisi (edges atau arcs) yang menghubungkan sepasang simpul {e1, e2, e3, ...} atau dapat di tulis dengan notasi G = {V,E}. Graf dapat dikelompokkan menjadi beberapa kategori (jenis) bergantung pada sudut pandang pengelompokannya. Pengelompokan
graf dapat dipandang berdasarkan ada tidaknya sisi ganda atau sisi kalang, berdasarkan jumlah simpul, atau berdasarkan orientasi arah pada sisi.<br/>
- Berdasarkan ada tidaknya gelang atau sisi ganda pada suatu graf, secara umum graf dapat digolongkan menjadi dua jenis:<br/>
  1. Graf sederhana, graf yang tidak mengandung gelang maupun sisi-ganda (Munir, 2012).<br/>
  ![Graf sederhana](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/f6459a38-b9c8-4977-993a-0b9671bb9740)<br/>
  2. Graf tak-sederhana, graf mengandung sisi ganda atau gelang (Munir, 2012).<br/>
- Berdasarkan orientasi arah pada sisi, maka secara umum graf dibedakan atas 2 jenis:<br/>
  1. Graf tak berarah (undirected graph)<br/>
     Graf yang sisinya tidak mempunyai orientasi arah disebut graf tak berarah. Pada graf tak-berarah, urutan pasangan simpul yang dihubungkan oleh sisi tidak diperhatikan.<br/>
     ![Graf Tak Berarah](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/ad35cf67-f81c-4faf-9dff-d7b05bc0890f)<br/>
     Graf di atas merupakan salah satu contoh graf tak berarah dimana sisi-sisi yang menghubungkan antar simpul dalam graf tersebut tidak memiliki orientasi arah. Sesuai apa yang telah disebutkan di atas, urutan
     pasangan simpul tidak diperhatikan, dalam contoh ini, (Anchorage,Corvallis) = (Corvallis,Achorage), menyatakan pasangan simpul yang sama.<br/>
  2. Graf Berarah (directed graph)<br/>
     Graf yang setiap sisinya memiliki orientasi arah disebut sebagai graf berarah. Sisi berarah dalam graf ini dapat dinamakan sebagai busur (arc). Lain halnya dengan graf tak-berarah, urutan pasangan simpul
     disini sangat diperhatikan karena dapat menyatakan hal yang berbeda. Pada graf berarah, (vj,vk) dan (vk,vj) menyatakan dua buah busur yang berbeda.<br/>
     ![Graf berarah](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/b2272dc7-c1b8-4b2c-94d1-fa139d2a18ff)<br/>
     ![Graf berarah-tak berarah](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/7f2867ff-2a6b-48b8-80de-47efee708747)<br/>
     
  - Adjacency Matrix<br/>
    Adjacency Matrix merupakan representasi matriks nxn yang menyatakan hubungan antar simpul dalam suatu graf. Kolom dan baris dari matriks ini merepresentasikan simpul-simpul, dan nilai entri dalam matriks ini
    menyatakan hubungan antar simpul, apakah terdapat sisi yang menghubungkan kedua simpul tersebut. Pada sebuah matriks nxn, entri non-diagonal aij merepresentasikan sisi dari simpul i dan simpul j. Sedangkan
    entri diagonal aii menyatakan sisi loop pada simpul i.<br/>
    ![amanda](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/5af76448-175e-40b1-94a1-692da6dd472d)<br/>
    ![Windhu](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/a068c4d4-90de-4bd5-be77-a143eb872dc2)<br/>
    Kelebihan dari adjacency matrix ini adalah elemen matriksnya dapat diakses langsung melalui indeks, dengan begitu hubungan ketetanggan antara kedua simpul dapat ditentukan dengan langsung. Sedangkan
    kekurangan pada representasi ini adalah bila graf memiliki jumlah sisi atau busur yang relatif sedikit, karena matriksnya bersifat jarang yaitu hanya mengandung elemen bukan nol yang sedikit. Kasus
    seperti ini merugikan, karena kebutuhan ruang memori untuk matriks menjadi boros dan tidak efisien karena komputer menyimpan elemen 0 yang tidak perlu.<br/>
  - Adjacency List<br/>
    Dalam teori graf, adjacency list merupakan bentuk representasi dari seluruh sisi atau busur dalam suatu graf sebagai suatu senarai. Simpul-simpul yang dihubungkan sisi atau busur tersebut dinyatakan
    sebagai simpul yang saling terkait. Dalam implementasinya, hash table digunakan untuk menghubungkan sebuah simpul dengan senarai berisi simpul-simpul yang saling terkait tersebut.<br/>
    ![Gustyas](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/8a6663ac-67f4-4f45-9810-2724c5b4f335)<br/>
    ![list](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/9d3646fb-f120-4b39-a993-e0a44c38a9c6)<br/>
    Salah satu kekurangan dari teknik representasi ini adalah tidak adanya tempat untuk menyimpan nilai yang melekat pada sisi. Contoh nilai ini antara lain berupa jarak simpul, atau beban simpul.<br/>

### 2. Tree<br/>
![Tree](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/6c74be42-f0b8-4c7c-a047-96db5c06ba50)<br/>
Struktur pohon (tree) adalah struktur data yang penting dalam bidang informasi, memungkinkan pengorganisasian informasi berdasarkan struktur logis dan memberikan cara khusus untuk mengakses elemen. Pohon terdiri dari sekumpulan simpul (node) yang saling terhubung, membentuk suatu kesatuan yang menyerupai pohon atau struktur hierarkis. Dalam teori graf, pohon adalah graf asiklik di mana setiap simpul terhubung memiliki simpul anak (children) dan satu simpul ayah (parent), kecuali simpul akar (root) yang tidak memiliki simpul ayah. Dalam pohon, hanya terdapat satu jalur yang menghubungkan satu simpul ke simpul lainnya, sehingga menciptakan struktur yang terorganisir dan efisien untuk mengakses dan mengelola data.<br/>
- Sebuah komponen pengelolaan data berstruktur pohon, hendaknya mampu melakukan operasioperasi dasar yang dilakukan untuk data berstruktur pohon, seperti menambah, meng-update, dan menghapus node serta memperlihatkan (view) pohon itu sendiri.<br/>
  1. Add Node<br/>
     Add Node adalah operasi untuk menambahkan node baru ke dalam struktur pohon yang telah didefinisikan. Dalam struktur organisasi perusahaan, operasi ini dapat
     dianalogikan dengan suatu penambahan departemen atau divisi baru.<br/>
  2. Update Node<br/>
     Update Node adalah operasi untuk meng-update informasi suatu node, baik itu informasi mengenai isi node, maupun informasi parent atau children dari node
     tersebut. Terdapat dua versi dari operasi ini, yaitu yang pertama adalah operasi update yang mengupdate parent, sedangkan yang kedua adalah operasi yang meng
     update children. Versi pertama memiliki pengecualian untuk node yang dianggap sebagai root, sedangkan versi kedua memiliki pengecualian untuk node yang
     dianggap sebagai leaf. Dalam struktur organisasi perusahaan, operasi ini dapat dianalogikan dengan suatu perubahan nama departemen atau suatu divisi yang
     mengganti departemen yang membawahinya.<br/>
  3. Delete Node<br/>
     Delete Node adalah operasi untuk menghapus suatu node dari struktur pohon. Dalam suatu struktur organisasi, operasi ini dapat dianalogikan dengan
     penutupan suatu departemen. Terdapat dua versi dari operasi ini, yaitu yang pertama adalah operasi delete yang menyertakan semua node yang berada di bawahnya,
     sedangkan yang kedua adalah operasi delete yang tidak menyertakan node yang dibawahnya, sehingga children dari node yang dihapus akan menjadi orphan. Pada
     versi pertama mungkin kita perlu menambahkan sub-operasi getAllDescendant untuk mendapatkan semua keturunan yang berasal dari node yang akan dihapus.<br/>
  4. View Tree<br/>
     View Tree adalah operasi untuk memperlihatkan (enumerating) sebagian atau keseluruhan node yang menyusun suatu struktur pohon. Seperti operasi Delete Node
     versi pertama, operasi ini juga dapat dilakukan dengan sub-operasi getAllDescendant untuk node yang dianggap root, karena root dan semua keturunannya
     merupakan kumpulan node yang menyusun struktur pohon.<br/>

## Guided 

### 1. [Program Graph]

```C++
#include <iostream>   
#include <iomanip>     

using namespace std;  

// Array nama kota yang direpresentasikan sebagai string
string simpul[7] = {
    "Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"
};

// Array 2D yang mewakili matriks ketetanggaan untuk graf
// Setiap elemen merepresentasikan bobot dari busur (edge) antara simpul (kota)
int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},    // Dari Ciamis ke Bandung (7), Bekasi (8)
    {0, 0, 5, 0, 0, 15, 0},   // Dari Bandung ke Bekasi (5), Purwokerto (15)
    {0, 6, 0, 0, 5, 0, 0},    // Dari Bekasi ke Bandung (6), Cianjur (5)
    {0, 5, 0, 0, 2, 4, 0},    // Dari Tasikmalaya ke Bandung (5), Cianjur (2), Purwokerto (4)
    {23, 0, 0, 10, 0, 0, 8},  // Dari Cianjur ke Ciamis (23), Tasikmalaya (10), Yogyakarta (8)
    {0, 0, 0, 7, 0, 0, 3},    // Dari Purwokerto ke Tasikmalaya (7), Yogyakarta (3)
    {0, 0, 0, 9, 4, 0}        // Dari Yogyakarta ke Tasikmalaya (9), Cianjur (4)
};

// Fungsi untuk menampilkan graf dalam format yang mudah dibaca
void tampilGraph() {
    // Iterasi setiap simpul (kota)
    for(int baris = 0; baris < 7; baris++) {
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        // Iterasi setiap kemungkinan koneksi dari simpul saat ini
        for (int kolom = 0; kolom < 7; kolom++) {
            if (busur[baris][kolom] != 0) {  // Cek jika ada busur (bobot non-nol)
                // Cetak simpul yang terhubung dan bobot busurnya
                cout << " " << simpul[kolom] << " (" << busur[baris][kolom] << ")";
            }
        }
        cout << endl; 
    }
}

// Fungsi utama untuk menjalankan program
int main() {
    tampilGraph();  // Panggil fungsi untuk menampilkan graf
    return 0;      
}
```
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

### 2. [Program Tree]

```C++
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
```
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Unguided 

### 1. [Soal]

```C++
#include <iostream>   
#include <iomanip>     

using namespace std;  

// Array nama kota yang direpresentasikan sebagai string
string simpul[7] = {
    "Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"
};

// Array 2D yang mewakili matriks ketetanggaan untuk graf
// Setiap elemen merepresentasikan bobot dari busur (edge) antara simpul (kota)
int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},    // Dari Ciamis ke Bandung (7), Bekasi (8)
    {0, 0, 5, 0, 0, 15, 0},   // Dari Bandung ke Bekasi (5), Purwokerto (15)
    {0, 6, 0, 0, 5, 0, 0},    // Dari Bekasi ke Bandung (6), Cianjur (5)
    {0, 5, 0, 0, 2, 4, 0},    // Dari Tasikmalaya ke Bandung (5), Cianjur (2), Purwokerto (4)
    {23, 0, 0, 10, 0, 0, 8},  // Dari Cianjur ke Ciamis (23), Tasikmalaya (10), Yogyakarta (8)
    {0, 0, 0, 7, 0, 0, 3},    // Dari Purwokerto ke Tasikmalaya (7), Yogyakarta (3)
    {0, 0, 0, 9, 4, 0}        // Dari Yogyakarta ke Tasikmalaya (9), Cianjur (4)
};

// Fungsi untuk menampilkan graf dalam format yang mudah dibaca
void tampilGraph() {
    // Iterasi setiap simpul (kota)
    for(int baris = 0; baris < 7; baris++) {
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        // Iterasi setiap kemungkinan koneksi dari simpul saat ini
        for (int kolom = 0; kolom < 7; kolom++) {
            if (busur[baris][kolom] != 0) {  // Cek jika ada busur (bobot non-nol)
                // Cetak simpul yang terhubung dan bobot busurnya
                cout << " " << simpul[kolom] << " (" << busur[baris][kolom] << ")";
            }
        }
        cout << endl; 
    }
}

// Fungsi utama untuk menjalankan program
int main() {
    tampilGraph();  // Panggil fungsi untuk menampilkan graf
    return 0;      
}

```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] Nugroho, D., & Budayasa, I. K. (2024). Graf berarah sebagai representasi turnamen “Round-Robin” dan sifat-sifatnya. MATHunesa: Jurnal Ilmiah Matematika, 12(01). e-ISSN: 2716-506X, p-ISSN: 2301-9115.<br/>
[2] Nggufron, N., Rochmad, & Mashuri. (2019). Pencarian rute terbaik pemadam kebakaran Kota Semarang menggunakan algoritma Dijkstra dengan logika fuzzy sebagai penentu bobot pada graf. UNNES Journal of Mathematics (UJM), 8(1).<br/>
[3] Yusuf, R., Dewi, F. P., Firmansyah, & Mujib, A. (2022). Generalisasi bilangan kromatik pada beberapa kelas graf korona. Jurnal Derivat, 9(2), Desember. ISSN: 2549-2616<br/>
[4] Agustina, S., Permana, A. Y., Fazri, H. N., Daffa, M. R. H., Robie, M., & Firmansyah, R. (2022). Implementasi Struktur Data Tree pada Web Blog sebagai Media Pembelajaran. Jurnal JITEK, 2(2), 206-212. P-ISSN: 2809-9249, E-ISSN: 2809-9230.<br/>
