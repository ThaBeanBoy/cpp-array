#include "arr.h"

// Constructor Utility function
void intArr::copyFromInitialiserList(std::initializer_list<int> list) {
    if (_length != list.size()) {
        std::cerr << "DEV ERR : Unable to copy from given initialiser list";
        exit(-1);
    }

    int int_indx = 0;
    for (int elem : list) {
        _arr[int_indx] = elem;
        int_indx++;
    }
}

// # CONSTRUCTORS
// Initializing array with values
intArr::intArr(std::initializer_list<int> arrOfNums) {
    // Saving required properties
    _length = arrOfNums.size();
    _arr = new int[_length];

    // Saving the number in the array
    copyFromInitialiserList(arrOfNums);
}

// set value to the given arrClass
void intArr::operator=(intArr arr_RHS) {
    // Saving length
    _length = arr_RHS._length;

    // deallocating the _arr
    delete _arr;
    _arr = nullptr;

    // reallocating _arr
    _arr = new int[_length];

    // copying values
    for (int i = 0; i < _length; i++)
        _arr[i] = arr_RHS[i];
}

// ! There seems to be a problem, I may need to debug
// set value to the given initializer list
// intArr& intArr::operator=(std::initializer_list<int> arrOfNums) {
//     // Saving length
//     _length = arrOfNums.size();

//     // deallocating the _arr
//     delete _arr;
//     _arr = nullptr;

//     // reallocating _arr
//     _arr = new int[_length];

//     // copying values
//     copyFromInitialiserList(arrOfNums);

//     std::cout << "Im supposed to copy from an initializer list bruv";
// }

// Initializing the array with it's size
intArr::intArr(int int_size) {
    // Saving required properties
    _length = int_size;
    _arr = new int[_length];

    for (int i = 0; i < _length; i++)
        _arr[i] = 0;
}

// # DESTRUCTOR
intArr::~intArr() {
    delete _arr;
    _arr = nullptr;
}

// # ARRAY METHODS
// Loop through elements in array
int intArr::length() const { return _length; }

void intArr::loop(void(*loop)(int, int)) const {
    int indx = 0;
    for (int i = 0; i < _length; i++) {
        loop(_arr[i], indx);
        indx++;
    }
}

// Return value of the given index
int intArr::valueAt(int int_indx) const {
    if (int_indx >= _length) {
        exit(-1);
    }
    return _arr[int_indx];
}

void intArr::changeValue(int int_index, int int_newVal) {
    _arr[int_index] = int_newVal;
}

// Add new element to the array
intArr& intArr::addElement(int int_newVal) {
    allocateForNewData({ int_newVal });
    return *this;
}
// Add new elements to the array
intArr& intArr::addElement(std::initializer_list<int> arrOfNums) {
    allocateForNewData(arrOfNums);
    return *this;
}
// Add elements from another array
intArr& intArr::addElement(intArr arrClass) {
    for (int i = 0; i < arrClass.length(); i++)
        allocateForNewData({ arrClass[i] });

    return *this;
}

// # OPERATOR FUNCTIONS
// intArr intArr::operator+(const intArr& RHS) {
//     if (_length != RHS._length)
//         throw "can't add two arrays that have different lengths";


// }

int operator>>(int int_LHS, intArr me) {


    return int_LHS;
}

// Add a new element to the array
intArr& intArr::operator<<(int int_newVal) { return addElement(int_newVal); }
intArr& intArr::operator<<(std::initializer_list<int> arrOfNums) { return addElement(arrOfNums); };
intArr& intArr::operator<<(intArr arrClass) { return addElement(arrClass); }; // Concat another array
// Add a new element to the array

// intArr intArr::operator>>(int int_newVal) {}
// void intArr::operator>>(std::initializer_list<int> arrOfNums) {}
// // Concat another array
// void intArr::operator>>(intArr arrClass) {}

// Delete the last element in the array
intArr intArr::operator--() {}


int& intArr::operator[](int i) {
    if (0 <= i && i < _length)
        return _arr[i];

    // ! ERR THROW POINT
    // Throw an out of range error
    throw 0;
}

void intArr::allocateForNewData(std::initializer_list<int> dataSet) {
    // Initialising the copy array
    int* copy = new int[_length];
    const int copyLength = _length;

    // Copying from the array into the copy array
    for (int i = 0; i < _length; i++) {
        copy[i] = _arr[i];
    }

    // Resizing the arr and increasing length
    delete _arr;
    _length += dataSet.size();
    _arr = nullptr;
    _arr = new int[_length];

    // copying from the copy array into the arr
    for (int i = 0; i < copyLength; i++)
        _arr[i] = copy[i];

    // Adding value to the array
    int int_indx = copyLength;
    for (int data : dataSet) {
        _arr[int_indx] = data;
        int_indx++;
    }

    // deleting the copy array
    delete copy;
    copy = nullptr;
}