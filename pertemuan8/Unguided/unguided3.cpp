// Oleh Amanda Windhu Gustyas_2311102121
#include <iostream>
using namespace std;

int main() 
{
    const int n = 10;
    int *data = new int[n] {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int cari = 4;
    int count = 0;

    // Loop melalui elemen-elemen array
    for (int i = 0; i < n; i++) 
    {   
        // Periksa jika elemen array saat ini sama dengan angka yang dicari
         if (data[i] == cari) 
         {

        // Tambahkan hitungan jika ditemukan angka yang dicari
         count++;
         }
     }
    cout << "MENGHITUNG BANYAK ANGKA 4" << endl;
    cout << "Data: 9, 4, 1, 4, 7, 10, 5, 4, 12, 4" << endl;
    cout << "\nJumlah angka " << cari << " dalam data: " << count << endl;
    delete[] data;
    return 0;
}