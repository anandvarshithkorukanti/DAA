#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

// Linear Search Function
int linearSearch(int arr[], int n, int key)
{
    int i = 0;

    while (i < n)
    {
        if (arr[i] == key)
        {
            return i;
        }
        i++;
    }

    return -1;
}


// Binary Search Function
int binarySearch(int arr[], int n, int key)
{
    int first = 0;
    int last = n - 1;

    while (first <= last)
    {
        int middle = (first + last) / 2;

        if (arr[middle] == key)
        {
            return middle;
        }
        else if (key > arr[middle])
        {
            first = middle + 1;
        }
        else
        {
            last = middle - 1;
        }
    }

    return -1;
}


int main()
{
    const int SIZE = 100000;
    int arr[SIZE];

    // Store values from 1 to 100000
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = i + 1;
    }

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int position;                           


// Linear Search
    auto begin = high_resolution_clock::now();

    position = linearSearch(arr, SIZE, key);

    auto finish = high_resolution_clock::now();

    cout << "\nLinear Search" << endl;

    if (position != -1)
        cout << "Element found at index " << position << endl;
    else
        cout << "Element not found" << endl;

    cout << "Time Taken : "
         << duration_cast<microseconds>(finish - begin).count()
         << " microseconds" << endl;


// Binary Search
    begin = high_resolution_clock::now();

    position = binarySearch(arr, SIZE, key);

    finish = high_resolution_clock::now();

    cout << "\nBinary Search" << endl;

    if (position != -1)
        cout << "Element found at index " << position << endl;
    else
        cout << "Element not found" << endl;

    cout << "Time Taken : "
         << duration_cast<microseconds>(finish - begin).count()
         << " microseconds" << endl;

    return  0;
}



