#include <iostream>
using namespace std;

int main() {
    int data[2][3][3] = {
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        },
        {
            {10, 11, 12},
            {13, 14, 15},
            {16, 17, 18}
        }
    };

    for (int i = 0; i < 2; i++) {
        cout << "Layer " << i + 1 << ":" << endl;
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                cout << data[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}