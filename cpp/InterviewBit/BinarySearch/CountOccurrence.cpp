#include<bits/stdc++.h>
using namespace std;

int f(vector<int> A, int N, int x){
    int low = 0, high = N-1, result = -1;

    while(low <= high){
        int mid = (low+high)/2;

        if(A[mid] == x){
            result = mid;
            //there may be some x before mid, find first occurrence of x
            high = mid-1;
        }
        else if(A[mid] > x)
            high = mid-1;
        else
            low = mid+1;
    }
    return result;
}

int Solution::findCount(const vector<int> &A, int B) {

    int n = A.size(), ans = 0;
    int first_occurrence = f(A, n, B);
    if(first_occurrence == -1)
        return 0;
    int i = first_occurrence;
    //cout << i << endl;
    for(; i<n && A[i]==B; i++);

    return i-first_occurrence;
}
