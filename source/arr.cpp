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
intArr::intArr(const intArr& arr_RHS) {
    // Saving length
    _length = arr_RHS._length;

    // reallocating _arr
    _arr = new int[_length];

    // copying values
    for (int i = 0; i < _length; i++)
        _arr[i] = arr_RHS._arr[i];

    bool sameLocation = _arr == arr_RHS._arr;
}

intArr& intArr::operator=(const intArr& arr_rhs) {
    if (this == &arr_rhs)
        return *this;

    // Delete anything that might've been in the array
    delete _arr;
    _arr = nullptr;

    // Set the same length as the rhs
    _length = arr_rhs._length;

    // Alloc mem
    _arr = new int[_length];

    // Copy values
    for (int i = 0; i < _length; i++)
        _arr[i] = arr_rhs._arr[i];

    return *this;
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

void intArr::loop(std::function<void(int)> loop) {
    for (int i = 0; i < _length; i++)
        loop(_arr[i]);
}

void intArr::loop(std::function<void(int, int)> loop) {
    int indx = 0;
    for (int i = 0; i < _length; i++) {
        loop(_arr[i], indx);
        indx++;
    }
}

void intArr::loopReverse(std::function<void(int)> loop) {
    for (int i = (_length - 1); i >= 0; i--)
        loop(_arr[i]);
}

void intArr::loopReverse(std::function<void(int, int)> loop) {
    for (int i = (_length - 1); i >= 0; i--)
        loop(_arr[i], i);
}

int& intArr::at(int int_indx) {
    if (0 <= int_indx && int_indx < _length)
        return _arr[int_indx];

    // ! ERR THROW POINT
    // Throw an out of range error
    throw 0;
}

// Add new element to the array
intArr intArr::concat(int int_newVal, bool hardConcat) {
    if (hardConcat) {
        // Concat the actual array
        _length += 1;
        int* temp = new int[_length];

        // Copying original values
        this->loop([temp](int val, int indx) {
            temp[indx] = val;
            });

        // Saving the given value
        temp[_length - 1] = int_newVal;


        // Delete original
        delete[] _arr;
        _arr = nullptr;

        _arr = temp;

        return *this;
    }

    // return a copy of concated array
    intArr temp = *this;
    temp.allocateForNewData({ int_newVal });

    return temp;
}
// Add new elements to the array
intArr intArr::concat(std::initializer_list<int> arrOfNums) {
    allocateForNewData(arrOfNums);
    return *this;
}
// Add elements from another array
intArr& intArr::concat(intArr arrClass) {
    for (int i = 0; i < arrClass.length(); i++)
        allocateForNewData({ arrClass[i] });

    return *this;
}

// # OPERATOR FUNCTIONS

// int operator>>(int int_LHS, intArr me) {


//     return int_LHS;
// }

// Add a new element to the array
intArr intArr::operator<<(int int_newVal) { return concat(int_newVal); }
// intArr& intArr::operator<<(std::initializer_list<int> arrOfNums) { return concat(arrOfNums, true); };
intArr& intArr::operator<<(intArr arrClass) { return concat(arrClass); }; // Concat another array
// Add a new element to the array

// intArr intArr::operator>>(int int_newVal) {}
// void intArr::operator>>(std::initializer_list<int> arrOfNums) {}
// // Concat another array
// void intArr::operator>>(intArr arrClass) {}

// Delete the last element in the array
intArr intArr::operator--() {}


int& intArr::operator[](int int_indx) {
    return at(int_indx);
}

void intArr::allocateForNewData(std::initializer_list<int> dataSet) {
    int* temp = new int[dataSet.size() + _length];

    // Copying original values
    this->loop([temp](int val, int indx) {
        temp[indx] = val;
        });

    // Copying new values
    int indx = _length;
    for (int newVal : dataSet) {
        temp[indx] = newVal;
        indx++;
    }

    // Delete original
    delete[] _arr;
    _arr = nullptr;

    _length += dataSet.size();
    _arr = temp;
}