/*

Given an integer array, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p
If such an integer is found return 1 else return -1.
*/
//Map based logic
//was giving memory exceeded error

    /*map<int,int> m;
    map<int,int>::iterator it;
    map<int,int>::reverse_iterator rit;

    //store count of int in map only for non negative elements
    for(int i=0; i<n; i++){
        if(A[i] >= 0)
            m[A[i]]++;
    }


    rit = m.rbegin();
    //for last element, there is no bigger element than it
    //initialize with -1 since there can be element 0
    int prev = rit->second;
    m[rit->first] = -1;

    rit++;
    for(; rit!=m.rend(); rit++){
        temp = rit->second;
        m[rit->first] = prev;
        prev += temp;
    }


    //if 0 is largest element m[0] = -1 based on above logic
    //but this is correct
    for(it=m.begin(); it!=m.end(); ++it){
        if( (it->first == it->second) || (it->first == 0 && it->second == -1) )
            return 1;
    }
    */


#include<bits/stdc++.h>
using namespace std;

//sortiing
int solve(vector<int> &A) {

    int n = A.size(), temp, i = 0, j;

    //base case
    if(n == 0)
        return -1;

    //tricky base case
    if(n == 1){
        if(A[0] == 0)
            return 1;
        else
            return -1;
    }

    sort(A.begin(), A.end());
    while(A[i] < 0){
        i++;
    }

    while(i < n){
        while(A[i] == A[i+1] && i+1<n){
            i++;
        }
        //j = last index if A[j] in case there is repition of A[j]
        if(A[i] == n-1-i)
            return 1;
        i++;
    }

    return -1;
}


int main(){
    int a[] = {-3, -2, -1, 0, 0, 0};
    vector<int> v(a, a + sizeof(a)/sizeof(a[0]));
    cout << solve(v);
    return 0;
}
