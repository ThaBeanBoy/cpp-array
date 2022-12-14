# [ cpp-arr ]

## Table Of Content

- [[cpp-arr]](#-cpp-arr-)
  - [Table Of Content](#table-of-content)
  - [Description](#description)
  - [Downloading](#downloading)
  - [Using IntArr in your file](#using-intarr-in-your-file)
  - [Initialisation](#initialisation)
  - [Array Methods](#array-methods)
    - [length()](#length)
    - [loop()](#loop)
    - [loopReverse()](#loopreverse)
    - [at()](#at)
    - [concat()](#concat)

## Description

This is to help abstract alot of the boring pointers involved in making dynamic arrays in c++. It also provides a few utility functions that make working with arrays easier.

## Downloading

## Using IntArr in your file

## Initialisation

Ofcourse like every object, it first needs to be instantiated. there are a couple of ways of achieving this.

- The default constructor will have only 1 value set to the value of 0:

  ```cpp
  intArr arr;
  // Essentially is the same as
  // intArr arr({0});

  //RESULTING ARRAY: [0]
  ```

- You can initialise the array with a list, here's an example:

  ```cpp
  intArr arr({ 1, 2, 3, 4, 5 });

  //RESULTING ARRAY: [1, 2, 3, 4, 5]
  ```

- You can initialise the array by equating it to another array, <span style='color:#f7746d; font-weight: bold'>This is used to make deep copies of another array object & reassigning an array.</span>

  ```cpp
  intArr arr = arr2;
  ```

- You can initialise the array by placing the number of elements you want in the array, 0s are placed as the default value

  ```cpp
  intArr arr(5);

  //RESULTING ARRAY: [0, 0, 0, 0, 0]
  ```

## Array Methods

### length()

This method returns the number of elements in the array.

```cpp
intArr arr({ 1, 2, 3, 4, 5 });

cout << "array length : " << arr.length();

//EXPECTED OUTPUT:
//array length : 5
```

### loop()

This is an alternative way of looping through the array. <span style='color:#95ed98;'>From index 0 to last index</span> <br/>
<span style='color:#f7746d; font-weight: bold'>It would be adviseable if you knew the basics of lambda functions</span> <br/>
[Explanation of Lambda Functions](https://learn.microsoft.com/en-us/cpp/cpp/lambda-expressions-in-cpp?view=msvc-170)

```cpp
intArr arr({ 1, 2, 3, 4, 5 });

arr.loop([](int val, int index /* Optional Argument */) {
    cout << "Value : " << val << endl
        << "Index : " << index << endl << endl;
    });

//EXPECTED OUTPUT:
//----------------

// Value : 1
// Index : 0

// Value : 2
// Index : 1

// Value : 3
// Index : 2

// Value : 4
// Index : 3

// Value : 5
// Index : 4
```

### loopReverse()

This is an alternative way of looping through the array. <span style='color:#95ed98;'>From last index to index 0</span> <br/>
<span style='color:#f7746d; font-weight: bold'>It would be adviseable if you knew the basics of lambda functions</span> <br/>
[Explanation of Lambda Functions](https://learn.microsoft.com/en-us/cpp/cpp/lambda-expressions-in-cpp?view=msvc-170)

```cpp
intArr arr({ 1, 2, 3, 4, 5 });

arr.loopReverse([](int val, int index /* Optional Argument */) {
    cout << "Value : " << val << endl
        << "Index : " << index << endl << endl;
    });

//EXPECTED OUTPUT:
//----------------

// Value : 5
// Index : 4

// Value : 4
// Index : 3

// Value : 3
// Index : 2

// Value : 2
// Index : 1

// Value : 1
// Index : 0
```

### at()

This allows you to acces any element in the array with it's index, and you also have the ability to change the value

```cpp
intArr arr({ 1, 2, 3, 4, 5 });

arr.at(0) = -1000;
arr[4] = 1000;

arr.loop([](int val, int index) {
    cout << "Value : " << val << endl
        << "Index : " << index << endl << endl;
    });

//EXPECTED OUTPUT:
//----------------

// Value : -1000
// Index : 0

// Value : 2
// Index : 1

// Value : 3
// Index : 2

// Value : 4
// Index : 3

// Value : 1000
// Index : 4
```

### concat()

This method allows you to concat new data into the array.

```cpp
intArr concated_arr({ 1, 2, 3, 4, 5 });

concated_arr.concat(6);

concated_arr.loop([](int val, int index) {
    cout << val << endl;
    });

//EXPECTED OUTPUT:
//----------------


// 1
// 2
// 3
// 4
// 5
// 6
```

if you don't want the array to change, then you can disable hard concat

```cpp
intArr concated_arr({ 1, 2, 3, 4, 5 });

// Looping on concated array, disabled hard concat
cout << "Disabled hard concat" << endl;
concated_arr.concat(6, false).loop([](int val, int index) {
    cout << val << endl;
    });

cout << endl << "Original array" << endl;
// Looping on the original
concated_arr.loop([](int val, int index) {
    cout << val << endl;
    });

//EXPECTED OUTPUT:
//----------------

// Disabled hard concat
// 1
// 2
// 3
// 4
// 5
// 6

// Original array
// 1
// 2
// 3
// 4
// 5
```

In the example above, I just wanted to loop over an array with a concated element wothout actually changing the actual array itself.
