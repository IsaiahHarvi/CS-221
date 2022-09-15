// Worksheet2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Literally just for testing this homework so I dont have to think.

#include <iostream>

using namespace std;

int main()
{
    double a, b, c, d; double* p1, * p2; a = 21.2; b = 52.6; c = 9.2; d = 0;
    p1 = &a; p2 = &b;
    *p1 = 2.0 * *p2;
    // What are a & b at this point?
    cout << a << " " << b << endl;
    p1 = &c; p2 = &d; p1 = p2;
    *p1 = 8.8;
    // What are c & d at this point?


    cout << c << " " << d << endl;


    int* array1 = new int[5]; 
    int* array2 = new int[5];
    // fill first array with some data 
    for (int j = 0; j < 5; j++) {
        array1[j] = j;
    }
    //… user writes some code to do some things with array1…
    // user wants to copy array1 into array2 
    array2 = array1;
    // …user goes on and does other work
    array1[0] = 7;
    cout << array1 << endl;
    for (int j = 0; j < 5; j++) {
        cout << "arr 1: " << array1[j] << endl;
        cout << "arr 2: " << array2[j] << endl;
    }
    cout << array2 << endl;
}

