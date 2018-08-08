/*
Find out the maximum sub-array of non negative numbers from an array.
The sub-array should be continuous. That is, a sub-array created by choosing the second and fourth element and skipping the third element is invalid.
Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).
Example:0
A : [1, 2, 5, -7, 2, 3]
The two sub-arrays are [1, 2, 5] [2, 3].
The answer is [1, 2, 5] as its sum is larger than [2, 3]
NOTE: If there is a tie, then compare with segment's length and return segment which has maximum length
NOTE 2: If there is still a tie, then return the segment with minimum starting index
*/
#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

vector<int> Solution::maxset(vector<int> &A) {

    int n = A.size();
    int i, j;
    unsigned long long int sum = 0;

    //if all elements are negative
    for(i=0; i<n; i++){
        if(A[i] >= 0)
            break;
    }

    if(i == n){
        return {};
    }

    //l = starting index of subarray
    //r = ending index of subarray
    //s = sum of elements in  this subarray
    pair< pair<int,int>, long long int> res = make_pair( make_pair(0,0), -1);

    //i in matrix will give starting index of sub-array
    //j in matrix will give ending index of sub-array

    for(i=0; i<n; i++){

        if(A[i] < 0)
            continue;

        sum = A[i];

        for(j=i+1; j<n; j++){
            if(A[j] < 0)
                break;

            //iterate to next element and add in sum only if its non negative
            if(A[j] >= 0){
                sum += A[j];
            }
        }

        //cout << "Max non negative sub array for row "<< i << " : (" << i << "," << j-1 << "," << sum << ") " << endl;

        //found new max non-negative sum subarray
        if(sum > res.second || res.second < 0){
            res = make_pair( make_pair(i, j-1), sum);
        }

        //if sum matches get sub array of greater length
        else if(sum == res.second){
            assert(j-1 >= i && res.first.second >= res.first.first);

            if(j-1 - i + 1 > res.first.second - res.first.first + 1){
                res = make_pair( make_pair(i, j-1), sum);
            }
            //if length is also same then keep subarray with lower starting index, which will be by defualt
        }

    }
    //cout << "Max non negative sub array : (" << res.first.first << "," << res.first.second << "," << res.second << ") " << endl;

    vector<int> v;
    for(i=res.first.first; i<=res.first.second; i++){
        v.push_back(A[i]);
    }
    return v;
}
