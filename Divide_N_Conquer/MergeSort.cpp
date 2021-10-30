#include <iostream>
#include <vector>
#define int long long
using namespace std;
void prnt (vector<int>& a) {
    for (int i: a) cout<<i<<" ";
    cout<<'\n';
    return;
}


void merge (vector<int>& a, vector<int>& left, vector<int>& right) {
    int i = 0, j = 0, k = 0, ls = left.size(), rs = right.size();
    while (i < ls || j < rs) {
        if (i == ls) a[k++] = right[j++]; 
        else if (j == rs) a[k++] = left[i++];
        else if (left[i] <= right[j]) a[k++] = left[i++];
        else a[k++] = right[j++];    
    }
}


void MergeSort (vector<int>& a) {
    if (!a.empty()) {
        if (a.size() == 1) return;
        int m = a.size() / 2;
        vector<int> left = {a.begin(), a.begin()+m};
        vector<int> right = {a.begin()+m, a.end()};
        MergeSort(left);
        MergeSort(right);
        merge (a, left, right);
    }
}

int32_t main () {
    int n;
    cout<<"Enter number of elements you want to sort: "; cin>>n;
    vector<int> a(n);
    cout<<"Enter "<<n<<" numbers in un-sorted order: \n";
    for (int i = 0; i < n; i++) cin>>a[i];
    MergeSort(a);
    prnt(a);
    return 0;
}