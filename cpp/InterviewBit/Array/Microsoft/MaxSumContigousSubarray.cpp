/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
For example:
Given the array [-2,1,-3,4,-1,2,1,-5,4],the contiguous subarray [4,-1,2,1] has the largest sum = 6.
For this problem, return the maximum sum.
*/
#include<bits/stdc++.h>
using namespace std;

int maxSubArray(const vector<int> &A) {

    int max = -1000000;

    bool allnegative = true;
    for(int i=0; i<A.size(); i++){
        if(A[i] > 0){
            allnegative = false;
            break;
        }
        else{
            max = A[i] > max ? A[i] : max;
        }
    }

    if(allnegative)
        return max;

    int max_ending_here = 0, max_so_far = 0;

    for(int i=0; i<A.size(); i++){
        max_ending_here += A[i];
        if(max_ending_here < 0)
            max_ending_here = 0;
        if(max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    return max_so_far;
}
