/*
http://www.ics.uci.edu/~eppstein/161/960125.html

worst case = O(n2)   T(n) = T(n-1) + O(n)
average case = O(n)  T(n) = T(n/2) + O(n)

quickselect(L,k)
    {
    pick x in L
    partition L into L1<x, L2=x, L3>x
    if (k <= length(L1))
        return quickselect(L1,k)
    else if (k > length(L1)+length(L2))
        return quickselect(L3,k-length(L1)-length(L2))    //k is changed when we consider indexing 0 for L3
    else return x
    }
*/
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

void swap(int *x, int *y){
    int temp = *y;
    *y = *x;
    *x = temp;
}

void print(int a[], int low, int high, int n){
    cout << "printing array 1:";
    for(int i=low; i<=high; i++){
        cout << a[i] << " ";
    }
    cout << "   printing array 2:";
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

//partition around pivot=last_element
int  partition(int *a, int l, int r, int k, int n){
    int x = a[r], j = l;
    for(int i=l; i<r; i++){
        if(a[i] <= x){
            swap(&a[i], &a[j]);
            j++;
        }
    }
    swap(&a[r], &a[j]);
    //print(a, l, r, n);
    return j;
}

int quickSelect(int *a, int l, int r, int k, int n){

    if(l <= r){
        int pos = partition(a, l, r, k, n);
        //cout << "(" << pos << "," << k-1<< ")" << endl;

        //kth smallest element means at index k-1 from start
        //if pivot position matches with k-1 return this element
        if(k-1 == pos)
            return a[pos];
        //if kth(k-1 indexed) smallest element is less than equal to pivot_index-1,
        //then it should be present in left subarray
        //recursive call to left array do not chnages value of k
        if(k-1 < pos)
            return quickSelect(a, l, pos-1, k, n);
        //if kth(k-1 indexed) smallest element is greater than to pivot_index-1,
        //then it should be present in right subarray
        return quickSelect(a, pos+1, r, k, n);
    }
    return INT_MAX;
}

int findKthSmallest(int *a, int n, int k){
    return quickSelect(a, 0, n-1, k, n);
}

int main(){
    int T, n, k;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> n;
        int a[n];
        for(int i=0; i<n; i++){
            cin >> a[i];
        }

        cin >> k;
        cout << findKthSmallest(a, n, k);
    }
    return 0;
}
