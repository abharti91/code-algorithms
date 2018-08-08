/*
Count number of binary strings without consecutive 1’s

Problem Description:
Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1’s. Output your answer mod 10^9 + 7.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
Each test case contain an integer N representing length of the binary string.

Output:
Print the count number of binary strings without consecutive 1’s of length N.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 100

Example:
Input:
2
3
2

Output:
5
3

Explaination:
For first test case 5 strings are (000, 001, 010, 100, 101)
For second test case 3 strings are (00,01,10)*/
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int COUNT;

/* recursion
void f(string s, int x){
    if(x >= s.length())
        return;

    for(int i=x; i<s.length(); i++){
        if(i >= 1 && s[i-1] == '1')
            s[i-1] = '0';

        s[i] = '1';
        cout << s << ",";
        COUNT++;
        f(s, i+2);
    }
    return;
}*/

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int F[101];
void f(){
    memset(F, 0, sizeof(F));
    F[1] = 2;
    F[2] = 3;
    for(int i=3; i<=100; i++)
        F[i] =  (F[i-1]%1000000007 + F[i-2]%1000000007) % 1000000007;

    //for(int i=1; i<=100; i++)
        //cout << F[i] % (1000000007) << ",";
    //cout << endl;
    return;
}

int main(){
    f();

    int T, n, count;
    cin >> T;

    for(int t=0; t<T; t++){
        cin >> n;
        cout << F[n] % (1000000007) << endl;
    }
}
