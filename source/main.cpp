#include <iostream>

#include "arr.h"

using namespace std;

int main() {
    system("cls");
    intArr arr(5);

    // arr[0] = 30;
    cout << arr[0] << endl;
    cout << arr.length();

    return 0;
}