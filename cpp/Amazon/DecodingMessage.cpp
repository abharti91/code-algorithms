/*
Better Approach - > Using DP
A top secret message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
You are an FBI agent. You have to determine the total number of ways that message can be decoded.
Note: An empty digit sequence is considered to have one decoding. It may be assumed that the input contains valid digits from 0 to 9 and
If there are leading 0’s, extra trailing 0’s and two or more consecutive 0’s then it is an invalid string.

Example :
Given encoded message "123",  it could be decoded as "ABC" (1 2 3) or "LC" (12 3) or "AW"(1 23).
So total ways are 3.

Input:
First line contains the test cases T.  1<=T<=1000
Each test case have two lines
First is length of string N.  1<=N<=40
Second line is string S of digits from '0' to '9' of N length.

Example:
Input:
2
3
123
4
2563
Output:
3
2
*/
#include<bits/stdc++.h>
using namespace std;

int fUtil(string s){
    int n  = s.length();

    //valid string do not have leading 0's
    if(n > 0 && s[0] == '0')
        return 0;

    if(n==0 || n==1)
        return 1;

    int a = 0, b = 0;
    a = fUtil(s.substr(1, n));

    if(10*(s[0]-'0') + (s[1]-'0') <= 26)
        b = fUtil(s.substr(2, n));

    //cout << "s,a,b:"<< s << "," << a << "," << b<< endl;
    return a+b;
}

int f(string s){
    int n = s.length();

    //valid string(if ends with 0) should end with 10 or 20
    if(n > 1 && s[n-2] > '2' && s[n-1] == '0' )
        return 0;

    //there should be no copnsecutive 0's
    for(int i=0; i<n-1; i++){
        if(s[i] == '0' && s[i+1] == '0')
            return 0;
    }

    return fUtil(s);
}

int main(){
    int T, N;
    string s;

    cin >> T;
    while(T--){
        cin >> N;
        cin >> s;
        cout << f(s) << endl;
    }
    return 0;
}
