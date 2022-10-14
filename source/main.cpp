#include <iostream>

#include "arr.h"

using namespace std;

int main() {
    system("cls");

    intArr arr({ 1, 2, 3, 4, 5 });
    intArr concated_arr = arr;
    arr[0] = 1000;

    cout << "Changes" << endl;

    // arr.concat(6);

    arr.loop([](int val, int index) {
        cout << val << endl;
        });

    return 0;
}