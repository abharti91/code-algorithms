#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> &A, int start, int end){
    cout << "Array after sorted subarray from [" << start <<"," <<end << "] ---> ";
    for(int i=0; i<A.size(); i++)
        cout << A[i] << ",";
    cout << endl;
}

int merge(vector<int> &A, int start, int mid, int end){
    int left_start = start;
    int right_start = mid;
    vector<int> A_sorted;

    int inversion = 0;

    while(left_start < mid && right_start < end){
        if(A[left_start] <= A[right_start])
            A_sorted.push_back(A[left_start++]);
        else{
            inversion += mid - left_start;
            A_sorted.push_back(A[right_start++]);
        }
    }

    //copy remaining leftover elements from both sub arrays to end of A_sorted
    copy(A.begin() + left_start, A.begin() + mid, back_inserter(A_sorted));
    copy(A.begin() + right_start, A.begin() + end, back_inserter(A_sorted));

    //copy back to A
    copy(A_sorted.begin(), A_sorted.end(), A.begin() + start);

    //printVector(A, start, end);
    return inversion;
}

//end = n, so range of array is from start to end-1
int count_inversion_helper(vector<int> &A, int start, int end){
    if(start >= end-1)
        return 0;

    int mid = start + ((end-start) >> 1);
    return count_inversion_helper(A, start, mid) + count_inversion_helper(A, mid, end) + merge(A, start, mid, end);
}

int count_inversion(vector<int> &A){
    return count_inversion_helper(A, 0, A.size());
}

int main(){
    int n, x;
    int a[] = {5,4,1,2,5};
    n = sizeof(a)/sizeof(a[0]);
    vector<int> A(a, a+n);
    cout << count_inversion(A) << endl;
}
