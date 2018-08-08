/*
Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row and column to 0.

Do it in place.

Example

Given array A as

1 0 1
1 1 1
1 1 1
On returning, the array A should be :

0 0 0
1 0 1
1 0 1
*/


void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int i, j, m = A.size(), n = A[0].size();
    bool a = false, b = false;

    //base case
    if(m == 0 || n == 0)
        return;


    //check first row
    for(j=0; j<n; j++){
        if(A[0][j] == 0)
            a = true;
    }

    //check first column
    for(i=0; i<m; i++){
        if(A[i][0] == 0)
            b = true;
    }

    for(i=1; i<m; i++){
        for(j=1; j<n; j++){
            if(A[i][j] == 0){
                A[i][0] = 0;
                A[0][j] = 0;
            }
        }
    }

    //for all rows
    for(i=1; i<m; i++){
        //mark all col of this row to 0
        if(A[i][0] == 0){
            for(j=1; j<n; j++)
                A[i][j] = 0;
        }
    }


    //for all cols
    for(j=0; j<n; j++){
        if(A[0][j] == 0){
            for(i=1; i<m; i++)
                A[i][j] = 0;
        }
    }


    //mark row 0 as 0's
    if(a){
        for(j=0; j<n; j++)
            A[0][j] = 0;
    }

    if(b){
        for(i=0; i<m; i++)
            A[i][0] = 0;
    }

    return;
}
