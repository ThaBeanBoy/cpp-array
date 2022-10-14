#include <iostream>

#include "arr.h"

using namespace std;

int main() {
    system("cls");

    intArr concated_arr({ 1, 2, 3, 4, 5 });

    // Looping on concated array, disabled hard concat
    cout << "Disabled hard concat" << endl;
    concated_arr.concat(6, false).loop([](int val, int index) {
        cout << val << endl;
        });

    cout << endl << "Original array" << endl;
    // Looping on the original
    concated_arr.loop([](int val, int index) {
        cout << val << endl;
        });

    return 0;
}