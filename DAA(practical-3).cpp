#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

void maxHeapify(int a[], int n, int i)
{
    int largest = i, l = 2*i+1, r = 2*i+2;

    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;

    if (largest != i) {
        swap(a[i], a[largest]);
        maxHeapify(a, n, largest);
    }
}

void maxHeapSort(int a[], int n)
{
    for (int i = n/2-1; i >= 0; i--)
        maxHeapify(a, n, i);

    for (int i = n-1; i > 0; i--) {
        swap(a[0], a[i]);
        maxHeapify(a, i, 0);
    }
}

void minHeapify(int a[], int n, int i)
{
    int smallest = i, l = 2*i+1, r = 2*i+2;

    if (l < n && a[l] < a[smallest]) smallest = l;
    if (r < n && a[r] < a[smallest]) smallest = r;

    if (smallest != i) {
        swap(a[i], a[smallest]);
        minHeapify(a, n, smallest);
    }
}

void minHeapSort(int a[], int n)
{
    for (int i = n/2-1; i >= 0; i--)
        minHeapify(a, n, i);

    for (int i = n-1; i > 0; i--) {
        swap(a[0], a[i]);
        minHeapify(a, i, 0);
    }
}

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
    cin >> n;

    int *a = new int[n];
    int *b = new int[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    // MAX HEAP SORT
    auto s = high_resolution_clock::now();
    maxHeapSort(a, n);
    auto e = high_resolution_clock::now();

    long long maxTime =
        duration_cast<nanoseconds>(e - s).count();

    // MIN HEAP SORT
    s = high_resolution_clock::now();
    minHeapSort(b, n);
    e = high_resolution_clock::now();

    long long minTime =
        duration_cast<nanoseconds>(e - s).count();

    cout << "\n========== MAX HEAP SORT ==========\n";
    cout << "Sorted Array: ";
    display(a, n);
    cout << "Nanoseconds : " << maxTime << " ns\n";
    cout << "Microseconds : " << maxTime/1000 << " us\n";

    cout << "\n========== MIN HEAP SORT ==========\n";
    cout << "Sorted Array: ";
    display(b, n);
    cout << "Nanoseconds : " << minTime << " ns\n";
    cout << "Microseconds : " << minTime/1000 << " us\n";

    delete[] a;
    delete[] b;

    return 0;
}