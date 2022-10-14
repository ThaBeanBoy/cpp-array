#include <iostream>

#include "arr.h"

using namespace std;

int main() {
    system("cls");

    intArr concated_arr({ 1, 2, 3, 4, 5 });

    cout << endl << "PRE CONCAT" << endl;
    // PRE CONCAT
    concated_arr.loop([](int val, int index) {
        cout << val << endl;
        });

    // PERMANENT CONCAT
    concated_arr = concated_arr.concat(6);


    cout << endl << "PERMANENT CONCAT" << endl;
    // POST CONCAT
    concated_arr.loop([](int val, int index) {
        cout << val << endl;
        });

    return 0;
}