/*
Submissions: 11439   Accuracy: 33.4%   Difficulty: Medium

Given an array A[] of n numbers and another number x, determine whether or not there exist three elements in A[] whose sum is exactly x.

Expected time complexity is O(n^2).

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is n and x, n is the size of array.
The second line of each test case contains n integers representing array elements C[i].

Output:

Print 1 if there exist three elements in A whose sum is exactly x, else 0.

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 200
1 ≤ A[i] ≤ 1000

Example:

Input:
2
6 13
1 4 45 6 10 8
5 10
1 2 4 3 6

Output:
1
1
*/
#include<bits/stdc++.h>
using namespace std;

int f(int a[], int n, int k){
    int l,r;

    sort(a, a+n);
    for(int i=0; i<n-2; i++){
        l = i+1;
        r = n-1;
        while(l < r){
            if(a[l] + a[r] + a[i] == k)
                return 1;
            else if(a[l] + a[r] + a[i] < k)
                l++;
            else
                r--;
        }
    }
    return 0;
}

int main(){
    int T, N, K;
    cin >> T;
    while(T--){
        cin >> N >> K;
        int a[N];
        for(int i=0; i<N; i++){
            cin >> a[i];
        }
        cout << f(a, N, K) << endl;
    }
    return 0;
}
