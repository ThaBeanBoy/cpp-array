#ifndef arr_h
#define arr_h

#include <initializer_list>
#include <functional>
#include <iostream>
#include <cassert>

class intArr {
public:
    // # CONSTRUCTORS
    // Initializing array with values
    intArr(std::initializer_list<int> arrOfNums = { 0 });

    // set value to the given arrClass
    intArr(const intArr& arr_RHS);

    // ! There seems to be a problem, I may need to debug
    // When user wants to instantiate, it should look like this intArr arr = {1, 2, 3, 4, 5}; 
    intArr& operator=(const intArr& arr_rhs);

    // Initializing the array with it's size
    intArr(int int_size);

    // # DESTRUCTOR
    ~intArr();

    // # ARRAY METHODS
    // returns the length of the arr
    int length() const;

    // Loop through elements in array
    void loop(std::function<void(int)> loop);

    void loop(std::function<void(int, int)> loop);

    void loopReverse(std::function<void(int)> loop);

    void loopReverse(std::function<void(int, int)> loop);

    // Return value of the given index
    int& at(int int_indx);

    // Add new element to the array
    intArr concat(int int_newVal, bool hardConcat = true);

    // Add new elements to the array
    intArr concat(std::initializer_list<int> arrOfNums);

    // Add elements from another array
    intArr& concat(intArr arrClass);

    intArr& concatStart(int int_newVal);

    intArr& concatStart(std::initializer_list<int> arrOfNums);

    intArr& concatStart(intArr arrClass);

    intArr& pop();

    intArr& pop(int index);

    intArr& pop(std::initializer_list<int> indexs);

    intArr filter(std::function<bool(int value)> filterFunction);

    intArr filter(std::function<bool(int value, int index)> filterFunction);

    intArr every(std::function<bool(int value)> filterFunction);

    intArr every(std::function<bool(int value, int index)> filterFunction);

    // !It would be cool to have a map function
    // template <typename K>
    // arr<K> map(std::function<bool(T element,int index)> mapFuction);

    // # OPERATOR FUNCTIONS
    // intArr operator+(const intArr& RHS);

    // Return value at array
    int& operator[](int int_indx);
    // ADDING ELEMENTS TO THE END OF THE ARRAY
    // Add a new element to the array
    intArr operator<<(int int_newVal);
    intArr& operator<<(std::initializer_list<int> arrOfNums);
    intArr& operator<<(intArr arrClass); // Concat another array
    // Add a new element to the array

    intArr operator>>(int& int_newVal);
    void operator>>(std::initializer_list<int> arrOfNums);
    // Concat another array
    void operator>>(intArr arrClass);

    // Delete the last element in the array
    intArr operator--();
    // Delete the first element in the array
    intArr operator~();

    intArr operator&&(intArr RHS);
    intArr operator||(intArr RHS);

    intArr operator==(intArr RHS);
    intArr operator!=(intArr RHS);

private:
    int* _arr;
    int _length;

    void allocateForNewData(std::initializer_list<int> dataSet);
    void copyFromInitialiserList(std::initializer_list<int> list);
};

#endif