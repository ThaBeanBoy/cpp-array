#include <iostream>
#include <initializer_list>

using namespace std;

class intArr {
public:
    // # CONSTRUCTORS
    // Initializing array with values
    intArr(initializer_list<int> arrOfNums = { 0 }) {
        // Saving required properties
        _length = arrOfNums.size();
        _arr = new int[_length];

        // Saving the number in the array
        int int_indx = 0;
        for (int elem : arrOfNums) {
            _arr[int_indx] = elem;
            int_indx++;
        }
    }
    // set value to the given arrClass
    void operator=(intArr arr_RHS) {
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

    // Initializing the array with it's size
    intArr(int int_size) {
        // Saving required properties
        _length = int_size;
        _arr = new int[_length];

        for (int i = 0; i < _length; i++)
            _arr[i] = 0;
    }

    // # DESTRUCTOR
    ~intArr() {
        delete _arr;
        _arr = nullptr;
    }

    // # ARRAY METHODS
    // Loop through elements in array
    int length() const { return _length; }

    void loop(void(*loop)(int, int)) const {
        int indx = 0;
        for (int i = 0; i < _length; i++) {
            loop(_arr[i], indx);
            indx++;
        }
    }

    // Return value of the given index
    int valueAt(int int_indx) const {
        if (int_indx >= _length) {
            exit(-1);
        }
        return _arr[int_indx];
    }

    void changeValue(int int_index, int int_newVal) {
        _arr[int_index] = int_newVal;
    }

    // Add new element to the array
    intArr& addElement(int int_newVal) {
        allocateForNewData({ int_newVal });
        return *this;
    }
    // Add new elements to the array
    intArr& addElement(initializer_list<int> arrOfNums) {
        allocateForNewData(arrOfNums);
        return *this;
    }
    // Add elements from another array
    intArr& addElement(intArr arrClass) {
        for (int i = 0; i < arrClass.length(); i++)
            allocateForNewData({ arrClass[i] });

        return *this;
    }

    // # OPERATOR FUNCTIONS
    intArr operator+(const intArr& RHS) {
        if (_length != RHS._length)
            throw "can't add two arrays that have different lengths";


    }

    // Return value at array
    int operator[](int int_indx) const { return valueAt(int_indx); }

    // Add a new element to the array
    intArr& operator<<(int int_newVal) { return addElement(int_newVal); }
    intArr& operator<<(initializer_list<int> arrOfNums) { return addElement(arrOfNums); };
    intArr& operator<<(intArr arrClass) { return addElement(arrClass); }; // Concat another array
    // Add a new element to the array

    intArr operator>>(int int_newVal);
    void operator>>(initializer_list<int> arrOfNums);
    // Concat another array
    void operator>>(intArr arrClass);

    // Delete the last element in the array
    void operator--();

    int& operator[](int i) { return _arr[i]; }

    // out puts list
    friend ostream& operator<<(ostream& stream, const intArr& me);

private:
    int* _arr;
    int _length;

    void allocateForNewData(initializer_list<int> dataSet) {
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

};

int main() {
    system("cls");
    intArr arr({ 1, 2, 3, 4, 5 });
    // intArr ar2({ -5, -4, -3, -2, -1, 0 });

    // ar2 << arr;

    arr[0] = 1000;

    // cout << endl << endl;

    // arr << 1000 << 2000 << 3000;
    // arr.addElement(4000).addElement(5000).addElement(6000);

    // cout << endl << endl;

    arr.loop([](int value, int indx) {
        cout << "index " << indx << ": " << value << endl;
        });

    return 0;
}