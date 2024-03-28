// Oleh Amanda Windhu Gustyas - 2311102121
    #include <iostream>
    using namespace std;
    struct Node
    {
        string name;
        string nim;
        Node *next;
    };
    Node *head;
    Node *tail;
    //untuk menginisialkan
    void init()
    {
        head = NULL;
        tail = NULL;
    }
        bool isEmpty()
    {
        if (head == NULL)
            {
                return true;
            }
        else
            {
                return false;
            }
    }
    // Tambah data di index pertama
    void insertDepan(string name, string nim)
        {
            Node *newNode = new Node;
            newNode->name = name;
            newNode->nim = nim;
            newNode->next = NULL;
            if (isEmpty() == true)
                {
                    head = tail = newNode;
                    tail->next = NULL;
                }
            else
                {
                    newNode->next = head;
                    head = newNode;
                }
        cout << "Data " << name << " berhasil ditambahkan" << endl;
    }
    // Tambah data di bagian index terbesar atau terakhir
    void insertBelakang(string name, string nim)
        {
            Node *newNode = new Node;
            newNode->name = name;
            newNode->nim = nim;
            newNode->next = NULL;
            if (isEmpty() == true)
                {
                    head = tail = newNode;
                }
            else
                {
                    tail->next = newNode;
                    tail = newNode;
                }
        cout << "Data " << name << " berhasil ditambahkan" << endl;
    }
    // Prosedur untuk menghitung list yang ada
    int hitungList()
        {
            Node *hitung;
            hitung = head;
            int jumlah = 0;
            while (hitung != NULL)
        {
            jumlah++;
            hitung = hitung->next;
        }
    return jumlah;
        }
            // Tambah data dibagian atntar index atau data list
            void insertTengah(string name, string nim, int posisi)
        {
            Node *newNode = new Node;
            newNode->name = name;
            newNode->nim = nim;
            newNode->next = nullptr;
            if (posisi == 1)
                {
                    newNode->next = head;
                    head = newNode;
        cout << "Data " << name << " berhasil ditambahkan pada posisi " << posisi << endl;
    return;
        }
            Node *prevNode = head;
            for (int i = 1; i < posisi - 1 && prevNode != nullptr; 
            i++)
        {
            prevNode = prevNode->next;
        }
            if (prevNode == nullptr)
                {
                    cout << "Posisi tidak ditemukan" << endl;
                    return;
                }
        newNode->next = prevNode->next;
        prevNode->next = newNode;
        cout << "Data " << name << " berhasil ditambahkan pada posisi " << posisi << endl;
        }
            // Prosedur untuk menghapus data di posisi tertentu
            void remove()
        {
            bool loop = true;
            while (loop)
        {
    int posisi;
    cout << "----- Hapus Data -----\n";
    cout << "1. Posisi Depan\n"<< "2. Posisi Tengah\n"<< "3. Posisi Belakang\n"<< "4. Keluar\nMasukan Pilihan: ";
    cin >> posisi;
    // Untuk menghapus data index ke 0 atau data list pertama
        if (posisi == 1)
            {
                Node *hapus;
                if (isEmpty() == false)
            {
                if (head->next != NULL)
                    {
                        hapus = head;
                        head = head->next;
                        delete hapus;
                        cout << "Data berhasil dihapus!" << endl;
            }
                else
                    {
                        head = tail = NULL;
                }
            }
                else
                    {
                        cout << "List kosong!" << endl;
                    }
            }
    // untuk menghapus data antar index sesuai posisi
    else if (posisi == 2)
        {
            int pos;
            cout << "Masukan posisi yang ingin dihapus: "; 
            cin >> pos;
            Node *bantu, *hapus, *sebelum;
            if (pos < 1 || pos > hitungList())
                {
                    cout << "Posisi di luar jangkauan" << endl;
                }
            else if (pos == 1)
                {
                    cout << "Posisi bukan posisi tengah" << endl;
                }
            else
                {
                    int nomor = 1;
                    bantu = head;
                    while (nomor <= pos)
                {
            if (nomor == pos - 1)
                {
                    sebelum = bantu;
                }
            if (nomor == pos)
                {
                    hapus = bantu;
                }
        bantu = bantu->next;
        nomor++;
    }
        sebelum->next = bantu;
        delete hapus;
        cout << "Data berhasil dihapus!" << endl;
    }
        }
        // untuk menghapus data diindex terbesar atau terakhir
        else if (posisi == 3)
            {
            Node *hapus;
            Node *bantu;
        if (isEmpty() == false)
            {
                if (head != tail)
                    {
                        hapus = tail;
                        bantu = head;
                        while (bantu->next != tail)
                            {
                                bantu = bantu->next;
                            }
        tail = bantu;
        tail->next = NULL;
        delete hapus;
        cout << "Data berhasil dihapus!" << endl;
    }
        else
            {
                head = tail = NULL;
            }
    }
        else
            {
                cout << "List kosong!" << endl;
            }
    }
        // pilihan untuk keluar dari fungsi remove
        else if (posisi == 4)
            {
                cout << "Keluar" << endl;
                loop = false;
            }
        else
            {
                cout << "Input tidak valid!" << endl;
            }
        }
    }
    // untuk mengubah data index 0 atau pertama
    void ubahDepan(string name, string nim)
    {
        if (isEmpty() == 0)
            {
                head->name = name;
                head->nim = nim;
            }
        else
            {
                cout << "List masih kosong!" << endl;
            }
    }
    // untuk mengubah data diantara index sesuai posisi
    void ubahTengah(string name, string nim, int posisi)
        {
            Node *bantu;
            if (isEmpty() == 0)
                {
                    if (posisi < 1 || posisi > hitungList())
                        {
                            cout << "Posisi di luar jangkauan" << endl;
                        }
            else if (posisi == 1)
                {
                    cout << "Posisi bukan posisi tengah" << endl;
                }
            else
                {
                    bantu = head;
                    int nomor = 1;
                    while (nomor < posisi)
                        {
                            bantu = bantu->next;
                            nomor++;
                        }
        bantu->name = name;
        bantu->nim = nim;
    }
        }
            else
                {
                    cout << "List masih kosong!" << endl;
                }
    }
    // untuk mengubah data di index terbesar atay terakhir
    void ubahBelakang(string name, string nim)
        {
            if (isEmpty() == 0)
                {
                    tail->name = name;
                    tail->nim = nim;
                }
            else
                {
                    cout << "List masih kosong!" << endl;
                }
        }
    // untuk menampilkan data list dalam program
    void display()
        {
            if (head == NULL)
                {
                    cout << "List kosong!" << endl;
                    return;
                }
    Node *current = head;
    int o = 1;
    while (current != NULL)
        {
            cout << o++ << ". " << "Nama: " << current->name << endl;
            cout << " NIM: " << current->nim << endl;
            current = current->next;
        }
        }
    int main()
    {
    // Deklarasi Variabel
    int choice;
    int choice_data;
    string name, nim;
    int posisi;
    loop_menu:
    // Menampilkan menu
    cout << "\nPROGRAM SINGLE LINKED LIST NON-CIRCULAR: "<< endl;
    cout << "1. Tambah Depan" << endl;
    cout << "2. Hapus data" << endl;
    cout << "3. Ubah data" << endl;
    cout << "4. Tampilkan data" << endl;
    cout << "5. Keluar" << endl;
    cout << "Masukkan pilihan dari menu (1-5): ";
    cin >> choice;
        switch (choice)
            {
                case 1: // Pilihan untuk menambah data
            {
                cout << "----- Tambahkan Data -----\n";
                cout << "Masukan Posisi Data : \n";
                cout << "1. Posisi di Depan\n";
                cout << "2. Posisi di Belakang\n";
                cout << "3. Posisi di Tengah\n";
                cout << "4. Keluar\n";
                loop_choice_data:
                cout << "Masukan pilihan Anda (1-4): ";
                cin >> choice_data;
                if (choice_data == 1) // Pilihan untuk menambah data di depan
                    {
                        cout << "--Posisi di Depan--\n";
                        cout << "Masukkan Nama: ";
                        cin >> name;
                        cout << "Masukkan NIM: ";
                        cin >> nim;
                        insertDepan(name, nim);
                    }
                else if (choice_data == 2) // Pilihan untuk menambah data di belakang
                    {
                        cout << "--Posisi di Belakang--\n";
                        cout << "Masukkan Nama: ";
                        cin >> name;
                        cout << "Masukkan NIM: ";
                        cin >> nim;
                        insertBelakang(name, nim);
                    }
                else if (choice_data == 3) // Pilihan untuk menambah data di tengah
                    {
                        cout << "--Posisi di Tengah--\n";
                        cout << "Masukkan Nama: ";
                        cin >> name;
                        cout << "Masukkan NIM: ";
                        cin >> nim;
                        cout << "Masukan Posisi: ";
                        cin >> posisi;
                        insertTengah(name, nim, posisi);
                    }
                else if (choice_data == 4) // Pilihan untuk keluar dari submenu
                    {
                        cout << "Keluar dari Menu Tambah Data\n";
                        goto loop_menu;
                    }
                else
                    {
                        cout << "Pilihan Anda Tidak Valid\n";
                    }
                goto loop_choice_data;
                break;
            }
                case 2: // Pilihan untuk menghapus data
            {
                remove();
                break;
            }
                case 3: // Pilihan untuk mengubah data
            {
                string newNim, newName;
                int pilihan, posisi;
                cout << "----- Ubah Data -----\n";
                cout << "1. Ubah Depan\n"
                << "2. Ubah Tengah\n"
                << "3. Ubah Belakang\n";
                cout << "Masukan pilihan anda: ";
                cin >> pilihan;
                    if (pilihan == 1) // Untuk mengubah data di depan
                        {
                            cout << "Masukan nama yang baru: ";
                            cin >> newName;
                            cout << "Masukan NIM yang baru: ";
                            cin >> newNim;
                            ubahDepan(newName, newNim);
                        }
                    else if (pilihan == 2) // Untuk mengubah data di tengah
                        {
                            cout << "Masukab nama yang baru: ";
                            cin >> newName;
                            cout << "Masukan NIM yang baru: ";
                            cin >> newNim;
                            cout << "Masukan data posisi yang ingin diubah: ";
                            cin >> posisi;
                            ubahTengah(newName, newNim, posisi);
                        }
                    else if (pilihan == 3) // Untuk mengubah data di belakang
                        {
                            cout << "Masukan nama yang baru: ";
                            cin >> newName;
                            cout << "Masukan NIM yang baru: ";
                            cin >> newNim;
                            ubahBelakang(newName, newNim);
                        }
                break;
            }
                case 4: // Menampilkan data
            {
                cout << "----- Tampilkan Data -----\n";
                display();
                break;
            }
                 case 5: // Keluar dari program
            {
                cout << "Terima kasih telah mencoba program ini!" << endl;
                return 0;
                break;
            }
                default:
            {
                cout << "Pilihan tidak valid" << endl;
            }
        }
    goto loop_menu;
    return 0;
    }