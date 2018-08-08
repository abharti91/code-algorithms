/*
For given string ‘str’ of digits, find length of the longest substring of ‘str’, such that the length of the substring is 2k digits and sum of left k digits is equal to the sum of right k digits.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
Each test case contains a string string of length N.

Output:
Print length of the longest substring of length 2k such that sum of left k elements is equal to right k elements and if there is no such substring print 0.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 100

Example:

Input:
2
000000
1234123

Output:
6
4
*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

void print(int sum[][100], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
}

int longestEvenString(string s){
    int n = s.length();
    int sum[n][n];
    std::memset(sum, 0, sizeof(sum));

    for(int i=0; i<n; i++)
        sum[i][i] = s[i]-'0';

    int j;
    //computing sum of two consecutive elements, three consecutive elements , and so on
    for(int k=2; k<=n; k++){
        for(int i=0; i<=n-k; i++){
            j =i+k-1;
            sum[i][j] = s[j]-'0' + sum[i][j-1];
        }
    }

    int maxl = 0;
    //start from last column and get string of length 2, 4, ... ending at column
    //check if sum of first half = sum of second half
    for(int j=n-1; j>=1; j--){
        int count = 1;
        for(int i=j-1; i>=0; i=i-2){
            if(sum[i][j] == 2 * sum[i][j-count]){
                if(count*2 > maxl)
                    maxl = 2*count;
            }

            count++;
        }
    }
    return maxl;
}

int main(){
    int T; cin>>T;
    string s;
    for(int t=0; t<T; t++){
        cin >> s;
        cout << longestEvenString(s) << endl;
    }
    return 0;
}
