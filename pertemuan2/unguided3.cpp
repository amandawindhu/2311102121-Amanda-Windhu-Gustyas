// Oleh Amanda Windhu Gustyas - 2311102121
#include <iostream>
using namespace std;

int main() {
    int arr[100]; // Mendeklarasikan array dengan ukuran maksimal
    int f;

    // Meminta pengguna untuk memasukkan jumlah elemen array
    cout << "Masukkan jumlah elemen array: ";
    cin >> f;

    // Meminta pengguna untuk memasukkan nilai-nilai array
    cout << "Masukkan " << f << " nilai untuk array:" << endl;
    for (int a = 0; a < f; ++a) {
        cout << "Nilai ke-" << a+1 << ": ";
        cin >> arr[a];
    }

    int pilih;
    int max = arr[0]; // Inisialisasi max dengan nilai pertama dalam array
    int min = arr[0]; // Inisialisasi min dengan nilai pertama dalam array
    double average = 0; // Inisialisasi average dengan nilai awal 0
    do {
        // Menampilkan menu
        cout << "\nMenu:" << endl;
        cout << "1. Cari nilai maksimum" << endl;
        cout << "2. Cari nilai minimum" << endl;
        cout << "3. Cari nilai rata-rata" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                // Mencari nilai maksimum
                for (int a = 1; a < f; ++a) {
                    if (arr[a] > max) {
                        max = arr[a];
                    }
                }
                cout << "Nilai maksimum: " << max << endl;
                break;

            case 2:
                // Mencari nilai minimum
                for (int a = 1; a < f; ++a) {
                    if (arr[a] < min) {
                        min = arr[a];
                    }
                }
                cout << "Nilai minimum: " << min << endl;
                break;

            case 3:
                // Mencari nilai rata-rata
                double sum = 0;
                for (int a = 0; a < f; ++a) {
                    sum += arr[a];
                }
                average = sum / f;
                cout << "Nilai rata-rata: " << average << endl;
                break;
        }
    } while (true); 

    return 0;
}
