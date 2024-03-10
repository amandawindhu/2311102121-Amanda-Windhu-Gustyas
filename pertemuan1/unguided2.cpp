#include <iostream> // untuk operasi input output
using namespace std; // agar elemen cout dan cin dapat langsung ditulis tanpa menggunakan std

class Kalkulasi_amanda_121 { //deklarasi class
private:
    int a, b, c; //deklarasi tiga variabel tipe data integer

public:
    Kalkulasi_amanda_121(int d, int e, int f) : a(d), b(e), c(f) {} //konstruktor class dengan tiga parameter ('d', 'e', 'f') dan menginisialisasi variabel ('a', 'b', 'c') menggunakan daftar inisialisasi ( a(d), b(e), c(f))

    int kali_121() { //mengembalikan nilai integer
        return a * b * c; //menghitung perkalian dari ketiga variabel dan mengembalikan hasilnya dengan pernyataan return
    }
};

int main() {
    Kalkulasi_amanda_121 obj(31, 2, 23); //pembuatan objek 
    cout << obj.kali_121() << endl; //pemanggilan objek
    return 0; //mengembalikan nilai 0
}
