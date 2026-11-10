#include "stack.h"

void createStack(Stack &S) {
    S.top = 0;
}

void push(Stack &S, infotype x) {
    if (S.top < 20) {
        S.top = S.top + 1;
        S.info[S.top - 1] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    infotype x = -1;
    if (S.top > 0) {
        x = S.info[S.top - 1];
        S.top = S.top - 1;
    } else {
        cout << "Stack kosong!" << endl;
    }
    return x;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top - 1; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    while (S.top > 0) {
        push(temp, pop(S));
    }
    S = temp;
}

// Implementasi prosedur pushAscending
void pushAscending(Stack &S, infotype x) {
    Stack temp;
    createStack(temp);

    while (S.top > 0 && S.info[S.top - 1] > x) {
        push(temp, pop(S));
    }

    push(S, x);

    while (temp.top > 0) {
        push(S, pop(temp));
    }
}