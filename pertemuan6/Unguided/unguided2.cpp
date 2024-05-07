// Oleh Amanda Windhu Gustyas - 2311102121
#include <iostream>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;
// Fungsi untuk membalik urutan kata dalam sebuah kalimat
string reverseSentence(const string& kal) {
    stack<string> stack; // Membuat stack untuk menyimpan kata-kata yang sudah dibalik
    stringstream r047(kal); // Membuat stringstream untuk memproses input kalimat
    string kat; // Variabel untuk menyimpan setiap kata dalam kalimat

    // Memasukkan setiap kata (yang sudah dibalik) ke dalam stack
    while (r047 >> kat) {
        reverse(kat.begin(), kat.end()); // Membalikkan urutan karakter dalam kata
        stack.push(kat); // Memasukkan kata yang sudah dibalik ke dalam stack
    }

    string reversedSentence; // Variabel untuk menyimpan kalimat yang sudah dibalik urutannya
    // Mengambil kata-kata dari stack dan menyusunnya kembali menjadi kalimat yang sudah dibalik
    while (!stack.empty()) {
        reversedSentence += stack.top(); // Mengambil kata paling atas dari stack
        stack.pop(); // Menghapus kata paling atas dari stack
        // Tambahkan spasi sebelum kata (kecuali untuk kata pertama)
        if (!stack.empty()) {
            reversedSentence += " "; // Menambahkan spasi jika belum mencapai kata pertama
        }
    }
    return reversedSentence; // Mengembalikan kalimat yang sudah dibalik urutannya
}

int main() {
    string kal; // Variabel untuk menyimpan input kalimat dari pengguna
    cout << "Masukkan kalimat: "; // Menampilkan pesan permintaan input kepada pengguna
    getline(cin, kal); // Membaca seluruh baris input dari pengguna

    // Memanggil fungsi reverseSentence dengan input kalimat dan menyimpan hasilnya
    string hasil = reverseSentence(kal);

    // Menampilkan kalimat asli dan hasil pembalikan kalimat kepada pengguna
    cout << "Kalimat: " << kal << endl;
    cout << "Hasil: " << hasil << endl;

    return 0; // Mengembalikan nilai 0, menandakan bahwa program berjalan dengan sukses
}
