
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Bubble Sort: Repeatedly swaps adjacent elements if they are in wrong order
void bubbleSort(vector<int> &arr)
{
    int n = arr.size();

    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]); // Swap adjacent elements
}

// Selection Sort: Finds the smallest element and places it in correct position
void selectionSort(vector<int> &arr)
{
    int n=arr.size();

    for(int i=0;i<n-1;i++)
    {
        int min=i; // Assume current element is smallest

        for(int j=i+1;j<n;j++)
            if(arr[j]<arr[min])
                min=j; // Update minimum element index

        swap(arr[i],arr[min]); // Place smallest element at current position
    }
}

// Insertion Sort: Inserts each element into its correct position
void insertionSort(vector<int> &arr)
{
    int n=arr.size();

    for(int i=1;i<n;i++)
    {
        int key=arr[i]; // Element to be inserted
        int j=i-1;

        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j]; // Shift larger elements to right
            j--;
        }

        arr[j+1]=key; // Insert key at correct position
    }
}

// Merge: Combines two sorted parts into one sorted array
void merge(vector<int> &arr,int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;

    vector<int> L(n1),R(n2); // Temporary arrays

    for(int i=0;i<n1;i++)
        L[i]=arr[l+i]; // Copy left half

    for(int j=0;j<n2;j++)
        R[j]=arr[m+1+j]; // Copy right half

    int i=0,j=0,k=l;

    // Compare elements and merge in sorted order
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
            arr[k++]=L[i++];
        else
            arr[k++]=R[j++];
    }

    // Copy remaining elements from left array
    while(i<n1)
        arr[k++]=L[i++];

    // Copy remaining elements from right array
    while(j<n2)
        arr[k++]=R[j++];
}

// Merge Sort: Divides array into halves and sorts them recursively
void mergeSort(vector<int> &arr,int l,int r)
{
    if(l<r)
    {
        int m=(l+r)/2; // Find middle position

        mergeSort(arr,l,m); // Sort left half
        mergeSort(arr,m+1,r); // Sort right half

        merge(arr,l,m,r); // Merge both sorted halves
    }
}

// Partition: Places pivot in correct position
int partition(vector<int> &arr,int low,int high)
{
    int pivot=arr[high]; // Select last element as pivot
    int i=low-1;

    for(int j=low;j<high;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]); // Move smaller element to left
        }
    }

    swap(arr[i+1],arr[high]); // Place pivot in correct position

    return i+1; // Return pivot index
}

// Quick Sort: Sorts elements using partitioning
void quickSort(vector<int> &arr,int low,int high)
{
    if(low<high)
    {
        int pi=partition(arr,low,high); // Find pivot position

        quickSort(arr,low,pi-1); // Sort left part
        quickSort(arr,pi+1,high); // Sort right part
    }
}

int main()
{
    const int n=100; // Number of elements

    vector<int> arr(n),temp;

    srand(time(0)); // Generate different random numbers each run

    // Fill array with random numbers
    for(int i=0;i<n;i++)
        arr[i]=rand()%1000;

    cout<<"Number of Elements = "<<n<<"\n\n";

    // Measure Bubble Sort execution time
    auto start=high_resolution_clock::now();
    temp=arr; // Copy original array
    bubbleSort(temp);
    auto stop=high_resolution_clock::now();
    cout<<"Bubble Sort Time    : "<<duration_cast<microseconds>(stop-start).count()<<" microseconds\n";

    // Measure Selection Sort execution time
    start=high_resolution_clock::now();
    temp=arr;
    selectionSort(temp);
    stop=high_resolution_clock::now();
    cout<<"Selection Sort Time : "<<duration_cast<microseconds>(stop-start).count()<<" microseconds\n";

    // Measure Insertion Sort execution time
    start=high_resolution_clock::now();
    temp=arr;
    insertionSort(temp);
    stop=high_resolution_clock::now();
    cout<<"Insertion Sort Time : "<<duration_cast<microseconds>(stop-start).count()<<" microseconds\n";

    // Measure Merge Sort execution time
    start=high_resolution_clock::now();
    temp=arr;
    mergeSort(temp,0,n-1);
    stop=high_resolution_clock::now();
    cout<<"Merge Sort Time     : "<<duration_cast<microseconds>(stop-start).count()<<" microseconds\n";

    // Measure Quick Sort execution time
    start=high_resolution_clock::now();
    temp=arr;
    quickSort(temp,0,n-1);
    stop=high_resolution_clock::now();
    cout<<"Quick Sort Time     : "<<duration_cast<microseconds>(stop-start).count()<<" microseconds\n";

    return 0; // End program
}
