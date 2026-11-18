
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

// Max Heapify: Maintains the largest element at the root
void maxHeapify(int a[], int n, int i)
{
    int largest = i, l = 2*i+1, r = 2*i+2; // Find parent and child indices

    if (l < n && a[l] > a[largest]) largest = l; // Check left child
    if (r < n && a[r] > a[largest]) largest = r; // Check right child

    if (largest != i) {
        swap(a[i], a[largest]); // Swap with largest child
        maxHeapify(a, n, largest); // Restore heap property
    }
}

// Max Heap Sort: Builds max heap and sorts elements
void maxHeapSort(int a[], int n)
{
    // Build max heap from the array
    for (int i = n/2-1; i >= 0; i--)
        maxHeapify(a, n, i);

    // Move largest element to the end repeatedly
    for (int i = n-1; i > 0; i--) {
        swap(a[0], a[i]); // Move root to correct position
        maxHeapify(a, i, 0); // Restore max heap
    }
}

// Min Heapify: Maintains the smallest element at the root
void minHeapify(int a[], int n, int i)
{
    int smallest = i, l = 2*i+1, r = 2*i+2; // Find parent and child indices

    if (l < n && a[l] < a[smallest]) smallest = l; // Check left child
    if (r < n && a[r] < a[smallest]) smallest = r; // Check right child

    if (smallest != i) {
        swap(a[i], a[smallest]); // Swap with smallest child
        minHeapify(a, n, smallest); // Restore heap property
    }
}

// Min Heap Sort: Builds min heap and sorts elements
void minHeapSort(int a[], int n)
{
    // Build min heap from the array
    for (int i = n/2-1; i >= 0; i--)
        minHeapify(a, n, i);

    // Move smallest element to the end repeatedly
    for (int i = n-1; i > 0; i--) {
        swap(a[0], a[i]); // Move root to correct position
        minHeapify(a, i, 0); // Restore min heap
    }
}

// Display: Prints all array elements
void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n; // Get array size

    int *a = new int[n]; // Array for max heap sort
    int *b = new int[n]; // Array for min heap sort

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i]; // Copy elements into second array
    }

    // MAX HEAP SORT: Measure execution time
    auto s = high_resolution_clock::now();
    maxHeapSort(a, n);
    auto e = high_resolution_clock::now();

    long long maxTime =
        duration_cast<nanoseconds>(e - s).count(); // Calculate time in ns

    // MIN HEAP SORT: Measure execution time
    s = high_resolution_clock::now();
    minHeapSort(b, n);
    e = high_resolution_clock::now();

    long long minTime =
        duration_cast<nanoseconds>(e - s).count(); // Calculate time in ns

    // Display Max Heap Sort result and execution time
    cout << "\n========== MAX HEAP SORT ==========\n";
    cout << "Sorted Array: ";
    display(a, n);
    cout << "Nanoseconds : " << maxTime << " ns\n";
    cout << "Microseconds : " << maxTime/1000 << " us\n";

    // Display Min Heap Sort result and execution time
    cout << "\n========== MIN HEAP SORT ==========\n";
    cout << "Sorted Array: ";
    display(b, n);
    cout << "Nanoseconds : " << minTime << " ns\n";
    cout << "Microseconds : " << minTime/1000 << " us\n";

    delete[] a; // Free dynamically allocated memory
    delete[] b;

    return 0; // End program
}
