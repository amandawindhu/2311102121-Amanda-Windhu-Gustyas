#include <iostream> // untuk operasi input output
#include <map> // untuk menyimpan data dalam struktur pasangan key-value
#include <string> // memungkinkan program menggunakan tipe data string

using namespace std; // agar elemen cout dan cin dapat langsung ditulis tanpa menggunakan std

struct Pemesanan_amanda { // deklarasi struct dengan nama Pemesanan
    string penumpang_121;
    string nomor_121;
    string stasiun_asal_121;
    string stasiun_tujuan_121;
    string tgl_keberangkatan_121;
};

int main() {
    map<string, Pemesanan_amanda> pemesanan_tiket_kereta; // deklarasi variabel 'pemesanan_tiket_kereta' bertipe map dengan key bertipe string dan value bertipe 'Pemesanan'
   // menambahkan data pemesanan tiket ke dalam 'pemesanan_tiket_kereta'
    pemesanan_tiket_kereta["310805"] = {"Amanda Windhu", "A11", "Semarang", "Purwokerto", "2022-02-27"}; 
    pemesanan_tiket_kereta["291205"] = {"Diego Valdano", "C8", "Malang", "Kroya", "2023-03-06"};

   // untuk mencetak semua data pemesanan tiket
    cout << "\nSemua Data Pemesanan Tiket:" << endl;
    // const auto& memastikan agar data tidak diubah dalam loop
    for (const auto& [nomor_pemesanan, detail] : pemesanan_tiket_kereta) { // loop for menggunakan range-based for loop
    // didalam loop 'for', program mencetak informasi mengenai setiap pemesanan tiket
        cout << "Nomor Pemesanan: " << nomor_pemesanan << endl;
        cout << "Nama Penumpang: " << detail.penumpang_121 << endl;
        cout << "Nomor Kursi: " << detail.nomor_121 << endl;
        cout << "Stasiun Asal: " << detail.stasiun_asal_121 << endl;
        cout << "Stasiun Tujuan: " << detail.stasiun_tujuan_121 << endl;
        cout << "Tanggal Keberangkatan: " << detail.tgl_keberangkatan_121 << endl;
        cout << endl;
    }

    return 0; // mengembalikan nilai 0
}
