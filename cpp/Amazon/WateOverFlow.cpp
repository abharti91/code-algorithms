/*
There is a stack of water glasses in a form of pascal triangle and a person wants to pour the water at the topmost glass, but the capacity of each glass is 1 unit .
Overflow takes place in such a way that after 1 unit, 1/2 of remaining unit gets into bottom left glass and other half in bottom right glass.
Now the pours K units of water in the topmost glass and wants to know how much water is there in the jth glass of the ith row.
Assume that there are enough glasses in the triangle till no glass overflows.

Input:   First line of the input contains an integer T denoting the number of test cases and each test case consists of three lines.
First line contain an integer K, second line contains an integer i and third line contains an integer j.
Output: Corresponding to each test case output the remaining amount of water in jth cup of the ith row correct to 6 decimal places.

Constraints:
T<=20
K<=1000
i <= K
j<= K
Example:
Input:
1
3
2
1

Output:
1
*/
#include<bits/stdc++.h>
using namespace std;

int f(int i, int j, float K){
    float glass[i * (i+1) /2];

    int index = 0;
    memset(glass, 0, sizeof(glass));
    glass[index] = K;

    for(int row = 1; row <= i; ++row){
        for(int col = 1; col <= row; ++col, ++index){

            int K = glass[index];
            glass[index] = (K >= 1.0f) ? 1.0f : K;

            //remaining amount that will go down
            K =  (K >= 1.0f) ? (K - 1) : 0.0f;
            glass[index + row] += K/2;
            glass[index + row + 1] += K/2;
        }
    }
    return glass[i*(i-1)/2 + j - 1];
}

int main(){
    int T, i, j; float K;
    cin >> T;
    while(T--){
        cin >> K >> i >> j;
        cout << f(i, j, K) << endl;
    }
}
