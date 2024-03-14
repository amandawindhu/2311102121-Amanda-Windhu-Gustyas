// Oleh Amanda Windhu Gustyas - 2311102121
#include <iostream>
using namespace std;

int main(){
    int arr[10]; // Mendeklarasikan array dengan 10 elemen
    int genap[5], ganjil[5]; // Mendeklarasikan array untuk menyimpan angka genap dan ganjil
    int genapIndex = 0; // Indeks untuk array angka genap
    int ganjilIndex = 0; // Indeks untuk array angka ganjil
    
    // Meminta pengguna untuk memasukkan data array
    cout << "Data Array: ";
    for (int a = 0; a < 10; a++){
        cin >> arr[a];
    }

    // Memisahkan angka genap dan ganjil dari array
    for (int a = 0; a < 10; a++){
        if(arr[a] % 2 == 0){
            genap[genapIndex] = arr[a]; // Menyimpan angka genap ke dalam array angka genap
            genapIndex++;
        } else {
            ganjil[ganjilIndex] = arr[a]; // Menyimpan angka ganjil ke dalam array angka ganjil
            ganjilIndex++;
        }
    }

    // Mencetak angka genap
    cout << "Angka Genap: ";
    for (int a = 0; a < genapIndex; a++){
        cout << genap[a] << " , ";
    }
   cout << endl;

    // Mencetak angka ganjil
    cout << "Angka Ganjil: ";
    for (int a = 0; a < ganjilIndex; a++){
        cout << ganjil[a] << " , ";
    }
    cout << endl;
    return 0;
}
    