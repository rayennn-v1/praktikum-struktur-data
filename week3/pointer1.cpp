#include <iostream>
using namespace std;

int main() {
    char a;
    int j;
    char arr[6];

    arr[3] = 'b';
    a = 'u';
    j = 10;

    cout << a << endl; //u
    cout << &a << endl; //alamat memory atau address

    cout << j << endl; //10
    cout << &j << endl; //alamat memory atau address

    cout << arr[3] << endl; //value
    cout << &(arr[4]) << endl; //alamat memory atau address

    return 0;
}