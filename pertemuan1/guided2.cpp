#include <stdio.h> // menyediakan fungsi standar seperti printf
#include <string.h> // menyediakanfungsi untuk manipulasi string seperti strcpy

// deklarasi struct bernama 'Mahasiswa'
struct Mahasiswa_121_amanda
{
    char name_amanda[50];
    char address_amanda[100];
    int age_amanda;
};
int main()
{

// deklarasi variabel-variabel bertipe struct 'Mahasiswa'
struct Mahasiswa_121_amanda mhs1, mhs2;
// mengisi nilai ke struct
strcpy(mhs1.name_amanda, "Dian");
strcpy(mhs1.address_amanda, "Mataram");
mhs1.age_amanda = 22;
strcpy(mhs2.name_amanda, "Bambang");
strcpy(mhs2.address_amanda, "Surabaya");
mhs2.age_amanda = 23;

// mencetak isi struct
printf("## Mahasiswa 1 ##\n");
printf("Nama: %s\n", mhs1.name_amanda);
printf("Alamat: %s\n", mhs1.address_amanda);
printf("Umur: %d\n", mhs1.age_amanda);
printf ("\n");
printf("## Mahasiswa 2 ##\n");
printf("Nama: %s\n", mhs2.name_amanda);
printf("Alamat: %s\n", mhs2.address_amanda);
printf("Umur: %d\n", mhs2.age_amanda);
return 0; // mengembalikan nilai 0
}