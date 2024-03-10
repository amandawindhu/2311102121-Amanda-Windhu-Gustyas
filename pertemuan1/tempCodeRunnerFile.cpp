#include <iostream> // untuk operasi input output
#include <iomanip> // untuk pemformatan output fixed dan setprecision
using namespace std; // agar elemen cout dan cin dapat langsung ditulis tanpa menggunakan std

int main()
{
    char op_amanda; // deklarasi variabel 'op' bertipe data char
    float num1_121, num2_121; // deklarasi variabel 'num1', 'num2' bertipe data float
    // menampilkan pesan untuk menginputkan operator
    cout << "Enter operator (+, -, *, /): "; 
    cin >> op_amanda;
    // menampilkan pesan untuk menginputkan dua operand
    cout << "Enter two operands: ";
    cin >> num1_121 >> num2_121;
    // statement switch-case
    switch (op_amanda)
    {
    // jika pengguna menginputkan +
    case '+':
        cout << "Result: " << num1_121 + num2_121;
        break;
    // jika pengguna menginputkan -
    case '-':
        cout << "Result: " << num1_121 - num2_121;
        break;
    // jika pengguna menginputkan *
    case '*':
        cout << "Result: " << num1_121 * num2_121;
        break;
    // jika pengguna menginputkan /
    case '/':
        if (num2_121 != 0)
        {
            cout << "Result: " << fixed << setprecision(2) << num1_121 / num2_121;
        }
        else
        {
            cout << "Error! Division by zero is not allowed.";
        }
        break;
    // jika pengguna menginputkan operator selaain +, -, *, /, maka pesan kesalahan akan ditampilkan
    default:
        cout << "Error! Operator is not correct";
    } 
    return 0; // mengembalikan nilai 0
}