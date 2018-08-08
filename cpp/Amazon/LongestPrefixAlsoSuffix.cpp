/*
######## USES KMP algorithm that makes lps[i]

Given a string of character, find the length of longest proper prefix which is also a proper suffix.
Example:
S = abab
lps is 2 because, ab.. is prefix and ..ab is also a suffix.

Input:
First line is T number of test cases. 1<=T<=100.
Each test case has one line denoting the string of length less than 100000.

Expected time compexity is O(N).

Output:
Print length of longest proper prefix which is also a proper suffix.

Example:
Input:
2
abab
aaaa

Output:
2
3
*/
#include<bits/stdc++.h>
using namespace std;

int f(string s){
    int n = s.length();
    int lps[n];
    memset(lps, 0, sizeof(lps));

    int len = 0, i = 1;
    while(i < n){
        //if chars match we just keep checking next chars i.e.len+1 and i+1
        if(s[len] == s[i]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            //if mismatch happens, then check current char at i with previous char(which is pointed by len)
            if(len != 0)
                len = lps[len-1];
            else{
                //if len==0, means cannot have any prefix that can also be proper suffix
                lps[i] = 0;
                i++;
            }
        }
    }
    //if we want non overlapping prefix/suffix use
    //return lps[n-1] > n/2 ? n/2 : lps[n-1];
    return lps[n-1];
}
int main() {
    int T; cin >> T;
    string s;

    for(int t=0; t<T; t++){
        cin >> s;
        cout << f(s) << endl;
    }
    return 0;
}
