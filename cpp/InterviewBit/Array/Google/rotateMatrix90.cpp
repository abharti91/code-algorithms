/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

You need to do this in place.

Note that if you end up using an additional array, you will only receive partial score.

Example:

If the array is

[
    [1, 2],
    [3, 4]
]
Then the rotated array becomes:

[
    [3, 1],
    [4, 2]
]
*/
void Solution::rotate(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details


    int t, i, j, n = A.size();

    if(n == 0 || n == 1)
        return;

    for(i=0; i<n; i++){
        for(j=i; j<n; j++){
            t = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = t;
        }
    }



    /*for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cout <<  A[i][j] << " ";
        }
        cout << endl;
    }*/


    //swap front and end cols iteratively
   int l = 0, r = n-1;
   while(l < r){

       //for all rows of col l and r
       for(i=0; i<n; i++){
           t = A[i][l];
           A[i][l] = A[i][r];
           A[i][r] = t;
       }

       l++;
       r--;
   }

}
