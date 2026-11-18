
#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

// Linear Search: Checks each element one by one
int linearSearch(int arr[], int n, int key)
{
    int i = 0;

    while (i < n)
    {
        if (arr[i] == key)
        {
            return i; // Return index if element is found
        }
        i++; // Move to next element
    }

    return -1; // Return -1 if element is not found
}


// Binary Search: Finds element by repeatedly dividing the search range
int binarySearch(int arr[], int n, int key)
{
    int first = 0;
    int last = n - 1;

    while (first <= last)
    {
        int middle = (first + last) / 2; // Find middle index

        if (arr[middle] == key)
        {
            return middle; // Element found
        }
        else if (key > arr[middle])
        {
            first = middle + 1; // Search right half
        }
        else
        {
            last = middle - 1; // Search left half
        }
    }

    return -1; // Element not found
}


int main()
{
    const int SIZE = 100000; // Total number of elements
    int arr[SIZE];

    // Store sorted values from 1 to 100000
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = i + 1;
    }

    int key;
    cout << "Enter element to search: ";
    cin >> key; // Get search element from user

    int position;

    // Linear Search and execution time calculation
    auto begin = high_resolution_clock::now();

    position = linearSearch(arr, SIZE, key);

    auto finish = high_resolution_clock::now();

    cout << "\nLinear Search" << endl;

    // Display search result
    if (position != -1)
        cout << "Element found at index " << position << endl;
    else
        cout << "Element not found" << endl;

    // Display Linear Search execution time
    cout << "Time Taken : "
         << duration_cast<microseconds>(finish - begin).count()
         << " microseconds" << endl;


    // Binary Search and execution time calculation
    begin = high_resolution_clock::now();

    position = binarySearch(arr, SIZE, key);

    finish = high_resolution_clock::now();

    cout << "\nBinary Search" << endl;

    // Display search result
    if (position != -1)
        cout << "Element found at index " << position << endl;
    else
        cout << "Element not found" << endl;

    // Display Binary Search execution time
    cout << "Time Taken : "
         << duration_cast<microseconds>(finish - begin).count()
         << " microseconds" << endl;

    return 0; // End program
}
