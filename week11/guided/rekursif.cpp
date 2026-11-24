#include "rekursif.h"

// implementasi fungsi rekrusif pangkat 2.
int pangkat_2(int x) {
    // kondisi khusus (base case).
    if (x == 0) {
        return 1;
    }// Pemanggilan fungsi itu sendiri (recursive case).
    else {
        return 2 * pangkat_2(x -1);
    }
}