#include <iostream> // untuk operasi input output
using namespace std; //  // agar elemen cout dan cin dapat langsung ditulis tanpa menggunakan std

int main() {
    int pilih_121_amanda; // deklarasi variabel pilih bertipe int untuk menyimpan pilihan menu pengguna
    float panjang_121, lebar_121, tinggi_121, jari2_121; // deklarasi variabel panjang, lebar, tinngi, jari2 bertipe data float untuk menyimpan nilai tersebut
    float vb_amanda, vl_amanda; // deklarasi variabel vb, vl bertipe float untuk menyimpan nilai volume balok dan volume lingkaran
    
    cout <<" <<<< M E N U >>>>\n"; // menampilkan output menu
    cout <<"\n";
    cout <<"1. Menghitung Volume balok\n"; // menampilkan output 1. menghitung volume balok
    cout <<"2. Menghitung Volume Lingkaran\n"; // menampilkan output 2. menghitung volume lingkaran
    cout <<"\n";
    cout <<"Pilih Nomor (1/2) ?"; // menampilkan output pilih nomor (1/2) ?
    cin >> pilih_121_amanda; // input pilih untuk meminta pengguna memilih nomor 1/2
    cout << "\n";

    switch(pilih_121_amanda){ // pernyataan switch-case berdasarkan nilai variabel pilih
        case 1: // meminta input panjang, lebar, dan tinngi balok
            cout <<"Panjang balok :";
            cin >> panjang_121;
            cout <<"Lebar balok : ";
            cin >> lebar_121;
            cout <<"Tinggi balok : ";
            cin >> tinggi_121;
            vb_amanda = panjang_121 * lebar_121 * tinggi_121; // menghitung volume balok
            cout << "Volume Balok = " << vb_amanda; // menampilkan hasil volume balok
            break; // menghentikan eksekusi
        case 2: // meminta input jari-jari lingkaran
            cout <<"Jari - jari lingkaran : ";
            cin >> jari2_121;
            vl_amanda = 3.14 * jari2_121 * jari2_121; // menghitung volume lingkaran
            cout <<"Volume Lingkaran = " << vl_amanda; // menampilkan hasil volume lingkaran
            break; // menghentikan eksekusi
    }

    return 0; // mengembalikan nilai 0
}
