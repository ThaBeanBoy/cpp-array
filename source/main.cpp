#include <iostream>

#include "arr.h"

using namespace std;

int main() {
    system("cls");

    intArr arr({ 1, 2, 3, 4, 5 });
    intArr concated_arr = arr;

    arr.concat(6);
    // arr.loop([](int val) {
    //     cout << val << endl;
    //     });
    cout << "concated" << endl;

    // arr.loopReverse([](int val, int indx) {
    //     cout << "Value : " << val << "\nIndex : " << indx << "\n\n";
    //     });

    return 0;
}