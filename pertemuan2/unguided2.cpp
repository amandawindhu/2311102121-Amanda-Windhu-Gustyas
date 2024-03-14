// Oleh Amanda Windhu Gustyas - 2311102121
#include <iostream>
using namespace std;

int main() {
    // Array 3 dimensi
    int arr[2][3][3];

    // Memasukkan nilai ke dalam array
    for (int i = 0; i < 2; i++) {
        for (int a = 0; a < 3; a++) {
            for (int f = 0; f < 3; f++) {
                cout << "Masukkan nilai untuk array[" << i << "][" << a << "][" << f << "] =  ";
                cin >> arr[i][a][f];
            } cout << endl;
        }
    }

    // Menampilkan isi array
    cout << "Isi Array:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int a = 0; a < 3; a++) {
            for (int f = 0; f < 3; f++) {
                cout << arr[i][a][f] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
