#include <iostream>
using namespace std;
int maks3(int a, int b, int c);
int main() {
    int x,y,z;
    cout << "masukkan nilai bilangan ke-1 = ";
    cin >> x;
    cout << "masukkan nilai bilangan ke-2 = ";
    cin >> y;
    cout << "masukkan nilai bilangan ke-3 = ";
    cin >> z;
    cout << "nilai maksimumnya adalah = " << maks3(x,y,z);
    return 0;
}
int maks3(int a, int b, int c) {
    int temp_max = a;
    if (b > temp_max)
    temp_max = b;
    if (c > temp_max)
    temp_max = c;
    return (temp_max);
}


