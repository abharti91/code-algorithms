/*
Next Permutation
Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers.
If such arrangement is not possible, it must be rearranged as the lowest possible order ie, sorted in an ascending order.
The replacement must be in-place, do not allocate extra memory.
Examples:
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
20, 50, 113 → 20, 113, 50
Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
*/
#include<bits/stdcc+.h>
using namespace std;-

void Solution::nextPermutation(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size(), r = n-1, i, x, min = INT_MAX, min_id;
    if(n == 0 || n == 1)
        return;

    while(r > 0 && A[r] < A[r-1]){
        r--;
    }
    //no greater permutation possible
    if(r == 0){
        sort(A.begin(), A.end());
        return;
    }

    //x should be placed in A[r..n] and get min from A[r..n] > x
    x = A[r-1];
    for(i=r; i<n; i++){
        if(x < A[i]){
            if(min > A[i]){
                min_id = i;
                min = A[i];
            }
        }
    }

    //cout << "min from A[" << r  << ".." << n-1 << "] at index:" << min_id << " is " << min << endl;
    A[r-1] = min;
    A[min_id] = x;
    sort(A.begin()+r , A.end());

}
