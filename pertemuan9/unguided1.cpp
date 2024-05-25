// Oleh Amanda Windhu Gustyas_2311102121
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Fungsi untuk menampilkan adjacency matrix
void displayMatrix(vector<vector<int>> & matrix, vector<string>& nodes) {
    int amanda_2311102121 = matrix.size(); // Mendapatkan jumlah simpul dari ukuran matrix

    // Menampilkan label simpul di atas adjacency matrix
    cout << " ";
    for (int i = 0; i < amanda_2311102121; i++) 
        {
            cout << nodes[i] << " ";
        }
    cout << endl;

    // Menampilkan adjacency matrix
    for (int i = 0; i < amanda_2311102121; i++) 
        {
            cout << nodes[i] << " ";
    for (int j = 0; j < amanda_2311102121; j++) {
        cout << matrix[i][j] << " ";
         }
    cout << endl;
        }
    }

    int main() {
    int numNodes;
    cout << "Silakan masukkan jumlah simpul: "; // Meminta pengguna untuk memasukkan jumlah simpul
    cin >> numNodes;

    // Mendeklarasikan vektor untuk menyimpan nama-nama simpul
    vector<string> nodes(numNodes);
     // Meminta pengguna untuk memasukkan nama simpul
    cout << "Silakan masukkan nama simpul: " << endl;
     for (int i = 0; i < numNodes; i++) 
     {
         cout << "Simpul " << i + 1 << ": ";
         cin >> nodes[i];
     }

     // Mendeklarasikan adjacency matrix sebagai matriks berukuran numNodes x numNodes
    vector<vector<int>>adjacencyMatrix(numNodes,vector<int>(numNodes));
     // Meminta pengguna untuk memasukkan bobot antar simpul
    cout << "\nSilakan masukkan bobot antar simpul: " << endl;
    for (int i = 0; i < numNodes; i++) 
    {
        for (int j = 0; j < numNodes; j++) {
        cout << nodes[i] << " -> " << nodes[j] << " = ";
        cin >> adjacencyMatrix[i][j];
        }
    }
    cout << endl;
 displayMatrix(adjacencyMatrix, nodes); // Memanggil fungsi untuk menampilkan adjacency matrix
 return 0;
}