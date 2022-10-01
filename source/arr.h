#ifndef arr_h
#define arr_h

#include <initializer_list>
#include <functional>
#include <iostream>

class intArr {
public:
    // # CONSTRUCTORS
    // Initializing array with values
    intArr(std::initializer_list<int> arrOfNums = { 0 });

    // set value to the given arrClass
    void operator=(intArr arr_RHS);

    // ! There seems to be a problem, I may need to debug
    // When user wants to instantiate, it should look like this intArr arr = {1, 2, 3, 4, 5}; 
    // intArr& operator=(std::initializer_list<int> arrOfNums);

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
    int valueAt(int int_indx) const;

    void changeValue(int int_index, int int_newVal);

    // Add new element to the array
    intArr& addElement(int int_newVal);

    // Add new elements to the array
    intArr& addElement(std::initializer_list<int> arrOfNums);

    // Add elements from another array
    intArr& addElement(intArr arrClass);

    intArr& addAtBegining(int int_newVal);

    intArr& addAtBegining(std::initializer_list<int> arrOfNums);

    intArr& addAtBegining(intArr arrClass);

    // # OPERATOR FUNCTIONS
    // intArr operator+(const intArr& RHS);

    // Return value at array
    int operator[](int int_indx) const;
    // ADDING ELEMENTS TO THE END OF THE ARRAY
    // Add a new element to the array
    intArr& operator<<(int int_newVal);
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

    int& operator[](int i);

private:
    int* _arr;
    int _length;

    void allocateForNewData(std::initializer_list<int> dataSet);
    void copyFromInitialiserList(std::initializer_list<int> list);
};

#endif