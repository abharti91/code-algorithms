/*
Suppose a sorted array A is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Find the minimum element.
The array will not contain duplicates.
NOTE 1: Also think about the case when there are duplicates. Does your current solution work? How does the time complexity change?*
PROBLEM APPROACH:
Note: If you know the number of times the array is rotated, then this problem becomes trivial. If the number of rotation is x, then minimum element is A[x].
Lets look at how we can calculate the number of times the array is rotated.
*/
#include<bits/stdc++.h>
using namespace std;

int f(vector<int> A, int N){
    int low = 0, high = N-1;

    while(low <= high){
        if(A[low] <= A[high])
            return low;

        int mid = (low+high)/2;
        int prev = (mid+N-1)%N;
        int next = (mid+1)%N;

        //A[mid] is smallest element in array
        if(A[mid] <= A[prev] && A[mid] <= A[next])
            return mid;
        else if(A[mid] <= A[high])
            high = mid-1;
        else if(A[mid] >= A[high])
            low = mid+1;
    }
    return -1;

}

int Solution::findMin(const vector<int> &A) {
    int n = A.size();
    if(n == 0)
        return -1;

    if(n == 1)
        return A[0];
    //cout << f(A, n) << endl;
    return A[f(A, n)];
}
