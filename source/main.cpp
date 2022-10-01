#include <iostream>

#include "arr.h"

using namespace std;

int main() {
    system("cls");
    intArr arr({ 1, 2, 3, 4, 5 });

    arr.loopReverse([](int val, int index) {
        cout << "Value : " << val << endl
            << "Index : " << index << endl << endl;
        });

    // arr.loopReverse([](int val, int indx) {
    //     cout << "Value : " << val << "\nIndex : " << indx << "\n\n";
    //     });

    return 0;
}