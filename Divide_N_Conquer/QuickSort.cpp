#include <iostream>
#include <vector>
#include <algorithm>
#define int long long 
using namespace std;


/*
    QUICKSORT: 
        m <-- partition(arr, start, end)
        QUICKSORT(arr, start, m-1);
        QUICKSORT(arr, m+1, end);

    PARTIOTION (arr[], start, end) {
        p = arr[end];
        i = start -1;
        for j = start to end-1
            if a[j] <= p
                i++;
                swap a[i] a[j];
        swap a[i+1] a[end];
        return i+1;
    }  

    Worst-Case: 0(n^2)
    Average-Case: 0(nlogn)

*/


void printArray (vector<int>& a) {
    for (int i : a) cout<<i<<" ";
    cout<<'\n';
}

int Partition (vector<int>& a, int start, int end) {
    int pivot = a[end];
    int i = start - 1;
    for (int j = start; j < end; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap (a[i+1], a[end]);
    return (i+1);
}

void Qsort (vector<int>& arr, int start, int end) {
    if (end > start) {
        int part = Partition (arr, start, end);
        Qsort (arr, start, part-1);
        Qsort (arr, part+1, end);
    }
}

int32_t main () {
    int n; 
    cout<<"Enter number of elements you whish to sort: ";
    cin>>n;

    vector<int> array(n); 
    cout<<"Enter "<<n<<" elements in unsorted order below: \n";
    for (vector<int>::iterator i = array.begin(); i < array.end(); i++) {
        cin>>*i;
    }
    Qsort (array, 0, n-1); 
    cout<<"In Sorted order: ";
    printArray(array);
}
