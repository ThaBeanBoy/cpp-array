#include <iostream>

#include "arr.h"

using namespace std;

int main() {
    system("cls");

    intArr concated_arr({ 1, 2, 3, 4, 5 });

    concated_arr.concat(6, false);

    concated_arr.loop([](int val, int index) {
        cout << val << endl;
        });

    return 0;
}