#include <iostream>
#include <vector>
#define int long long
using namespace std;

/*
    COUNTING INVERSIONS IN Array
        We use DivideNConqer
        Almost identical to merge sort routine.
        In merge routine we count actual number of inversions.
        Running-Time : 0(nlogn) i.e., sub-quadratic

*/

// Counts inversions for A. given LEFT and RIGHT subarrays about some appropiate MID.
int merge (vector<int>& a, vector<int>& left, vector<int>& right) {
  int i = 0, j = 0, k = 0, inv = 0, ls = left.size(), rs = right.size(), as = a.size();

  // While LEFT and RIGHT both are traversed completely
  while (i < ls || j < rs){
      // LEFT is traversed completely
      if (i == ls) {
        j++;
        k++;
      }
      // RUGHT is traversed completely
      else if ( j == rs) {
        i++;
        k++;
      }
      // No inversions exerted.
      else if (left[i] <= right[j]) {
        i++;
        k++;
      }
      // Found inversions
      else {
        j++;
        k++;
        // Keep incrementing inv by no. of inversion.
        inv += (left.size()-i);
      }
  }
  // Return number of inversions found
  return inv;
}

int countInv (vector<int> a) {
  // Base-cases
  if (a.size() == 1) return 0;
  if (a.empty()) return 0;

  // choose mid to be half the size.
  int mid = a.size() / 2;

  int inv = 0;
  // Divide into LEFT and RIGHT subarrays about MID.
  vector<int> left = {a.begin(), a.begin()+mid};
  vector<int> right = {a.begin()+mid, a.end()};

  // Recursively count inversions in left and right.
  // AND combine the number of inversions for while orignal array;
  inv += countInv(left) + countInv(right) + merge(a, left, right);
  // Number of inversions returned.
  return inv;
}

int32_t main () {
    int n;
    cout<<"Enter number of elements in your array: ";
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    int inversions = countInv(arr);
    cout<<"Number of inversions in given array is: "<<inversions<<'\n';
    return 0;
}


/*
test cases:
    Input: N = 5, arr[] = {2, 4, 1, 3, 5}
    Output: 3

    Input: arr[] = {3, 1, 2}
    Output: 2

    arr[] = { 1, 20, 6, 4, 5 };
    op: 5

    Input: arr[] = {8, 4, 2, 1}
    Output: 6
*/
