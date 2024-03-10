#include <iostream> // untuk operasi input output
#include <string> // memungkinkan program menggunakan tipe data string
using namespace std; // agar elemen cout dan cin dapat langsung ditulis tanpa menggunakan std

struct Buku_amanda_windhu_gustyas // deklarasi struct dengan nama buku yang memiliki 4 anggota bertipe data string, string, int, float
{
    string judul_121;
    string penulis_121;
    int tahun_terbit_121;
    float harga_121;
};
 
int main(){
     Buku_amanda_windhu_gustyas buku1; // pengisian nilai ke variabel 'buku1'
    buku1.judul_121 = "Bumi"; 
    buku1.penulis_121 = "Tere Liye"; // 
    buku1.tahun_terbit_121 = 2014;
    buku1.harga_121 = 95000.0;

    cout << "Judul: " << buku1.judul_121 << endl; // menampilkan hasil judul buku yang tersimpan dalam variabel buku1
    cout << "Penulis: " << buku1.penulis_121 << endl; // menampilkan hasil nama penulis yang tersimpan dalam variabel buku1
    cout << "Tahun terbit: " << buku1.tahun_terbit_121 << endl; // // menampilkan hasil tahun terbit yang tersimpan dalam variabel buku1
    cout << "Harga: Rp " << buku1.harga_121 << endl; // menampilkan hasil harga yang tersimpan dalam variabel buku1

    return 0; // mengembalikan nilai 0
}
