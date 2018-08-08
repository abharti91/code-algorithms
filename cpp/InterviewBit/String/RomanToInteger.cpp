/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

Read more details about roman numerals at Roman Numeric System

Example :

Input : "XIV"
Return : 14
Input : "XX"
Output : 20
*/

#include<bits/stdc++.h>
using namespace std;

int romanToInt(string A) {

    map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;

    int n = A.length(), ans = 0;

    //base case
    if(n == 0)
        return 0;

    if(n == 1)
        return m[A[0]];

    int j = 0;
    while(j < n){
        if(A[j] == 'I'){
            if(j+1 < n && A[j+1] == 'V'){
                ans += 4;
                j++;
            }
            else if(j+1 < n && A[j+1] == 'X'){
                ans += 9;
                j++;
            }
            else
                ans += m[A[j]];
        }

        else{
            if(j-1 >= 0 && m[A[j-1]] < m[A[j]])
                ans += m[A[j]] - 2 * m[A[j-1]];
            else
                ans += m[A[j]];
        }

        j++;
    }

    return ans;
}
