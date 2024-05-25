# <h1 align="center">Laporan Praktikum Modul Graph dan Tree</h1>
<p align="center">Amanda Windhu Gustyas -  2311102121</p>

## Dasar Teori

### 1. Graph<br/>
Graf didefinisikan sebagai pasangan himpunan (V,E), yang dalam hal ini V adalah himpunan tidak kosong dari simpul-simpul (verticers atau node) = {v1, v2, v3,...} dan E himpunan sisi (edges atau arcs) yang menghubungkan sepasang simpul {e1, e2, e3, ...} atau dapat di tulis dengan notasi G = {V,E}. Graf dapat dikelompokkan menjadi beberapa kategori (jenis) bergantung pada sudut pandang pengelompokannya. Pengelompokan
graf dapat dipandang berdasarkan ada tidaknya sisi ganda atau sisi kalang, berdasarkan jumlah simpul, atau berdasarkan orientasi arah pada sisi.<br/>
- Berdasarkan ada tidaknya gelang atau sisi ganda pada suatu graf, secara umum graf dapat digolongkan menjadi dua jenis:<br/>
  1. Graf sederhana, graf yang tidak mengandung gelang maupun sisi-ganda (Munir, 2012).<br/>
  ![Graf sederhana](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/f6459a38-b9c8-4977-993a-0b9671bb9740)<br/>
  2. Graf tak-sederhana, graf mengandung sisi ganda atau gelang (Munir, 2012).<br/>
- Berdasarkan orientasi arah pada sisi, maka secara umum graf dibedakan atas 2 jenis:<br/>
  1. Graf tak berarah (undirected graph)<br/>
     Graf yang sisinya tidak mempunyai orientasi arah disebut graf tak berarah. Pada graf tak-berarah, urutan pasangan simpul yang dihubungkan oleh sisi tidak diperhatikan.<br/>
     ![Graf Tak Berarah](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/ad35cf67-f81c-4faf-9dff-d7b05bc0890f)<br/>
     Graf di atas merupakan salah satu contoh graf tak berarah dimana sisi-sisi yang menghubungkan antar simpul dalam graf tersebut tidak memiliki orientasi arah. Sesuai apa yang telah disebutkan di atas, urutan
     pasangan simpul tidak diperhatikan, dalam contoh ini, (Anchorage,Corvallis) = (Corvallis,Achorage), menyatakan pasangan simpul yang sama.<br/>
  2. Graf Berarah (directed graph)<br/>
     Graf yang setiap sisinya memiliki orientasi arah disebut sebagai graf berarah. Sisi berarah dalam graf ini dapat dinamakan sebagai busur (arc). Lain halnya dengan graf tak-berarah, urutan pasangan simpul
     disini sangat diperhatikan karena dapat menyatakan hal yang berbeda. Pada graf berarah, (vj,vk) dan (vk,vj) menyatakan dua buah busur yang berbeda.<br/>
     ![Graf berarah](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/b2272dc7-c1b8-4b2c-94d1-fa139d2a18ff)<br/>
     ![Graf berarah-tak berarah](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/7f2867ff-2a6b-48b8-80de-47efee708747)<br/>
     
  - Adjacency Matrix<br/>
    Adjacency Matrix merupakan representasi matriks nxn yang menyatakan hubungan antar simpul dalam suatu graf. Kolom dan baris dari matriks ini merepresentasikan simpul-simpul, dan nilai entri dalam matriks ini
    menyatakan hubungan antar simpul, apakah terdapat sisi yang menghubungkan kedua simpul tersebut. Pada sebuah matriks nxn, entri non-diagonal aij merepresentasikan sisi dari simpul i dan simpul j. Sedangkan
    entri diagonal aii menyatakan sisi loop pada simpul i.<br/>
    ![amanda](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/5af76448-175e-40b1-94a1-692da6dd472d)<br/>
    ![Windhu](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/a068c4d4-90de-4bd5-be77-a143eb872dc2)<br/>
    Kelebihan dari adjacency matrix ini adalah elemen matriksnya dapat diakses langsung melalui indeks, dengan begitu hubungan ketetanggan antara kedua simpul dapat ditentukan dengan langsung. Sedangkan
    kekurangan pada representasi ini adalah bila graf memiliki jumlah sisi atau busur yang relatif sedikit, karena matriksnya bersifat jarang yaitu hanya mengandung elemen bukan nol yang sedikit. Kasus
    seperti ini merugikan, karena kebutuhan ruang memori untuk matriks menjadi boros dan tidak efisien karena komputer menyimpan elemen 0 yang tidak perlu.<br/>
  - Adjacency List<br/>
    Dalam teori graf, adjacency list merupakan bentuk representasi dari seluruh sisi atau busur dalam suatu graf sebagai suatu senarai. Simpul-simpul yang dihubungkan sisi atau busur tersebut dinyatakan
    sebagai simpul yang saling terkait. Dalam implementasinya, hash table digunakan untuk menghubungkan sebuah simpul dengan senarai berisi simpul-simpul yang saling terkait tersebut.<br/>
    ![Gustyas](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/8a6663ac-67f4-4f45-9810-2724c5b4f335)<br/>
    ![list](https://github.com/amandawindhu/2311102121-Amanda-Windhu-Gustyas/assets/150095443/9d3646fb-f120-4b39-a993-e0a44c38a9c6)<br/>
    Salah satu kekurangan dari teknik representasi ini adalah tidak adanya tempat untuk menyimpan nilai yang melekat pada sisi. Contoh nilai ini antara lain berupa jarak simpul, atau beban simpul.<br/>






     


## Guided 

### 1. [Nama Topik]

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code guided praktikan" << endl;
    return 0;
}
```
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Unguided 

### 1. [Soal]

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code unguided praktikan" << endl;
    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
