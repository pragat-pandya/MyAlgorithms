#include <iostream>
#include <vector>
using namespace std;


// MOST TRIVIAL SEARCHING FOR SORTED ITEMS 
// RUNS IN logarithmic time.
// Is tail recursive so easily can be implemented using a while loop without maintaing a calling stack


// Recursive implementation of Binary Search.
int RecBSearch (vector<int>& a, int start, int end, int key) {
    if (end > start) {
        int mid = (start + end) / 2;
        if (a[mid] > key) return RecBSearch (a, start, mid, key);
        else if (a[mid] < key) return RecBSearch (a, mid+1, end, key);
        else return mid;
    }
    return -1;
}


// Iterative implementaion of Binary Search :: Beats Recursive Implementation in the long run.
int ItrBSearch (vector<int>& a, int start, int end, int key) {
    while (end > start) {
        int mid = (start + end) / 2;
        if (a[mid] == key) return mid;
        else if (a[mid] > key) {
            end = mid;
        }
        else start = mid+1;
    }
    return -1;
}


int main () {
    int n, key;
    cout<<"Enter number of elements in the array: ";
    cin>>n;
    vector<int> a(n); for (int i = 0; i < n; i++) a[i]=i+1;
    cout<<"Enter the element you wish to search: ";
    cin>>key;
    cout<<"The "<<key<<" is at index: "<<ItrBSearch(a, 0, n, key)<<endl;//<<RecBSearch(a, 0, n, key)<<endl;
    return 0;
}