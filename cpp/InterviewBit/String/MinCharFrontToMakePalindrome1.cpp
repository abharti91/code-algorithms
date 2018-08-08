/*
Minimum Characters required to make a String Palindromic
Problem Setter: glowing_glare
Problem Tester: RAMBO_tejasv
You are given a string. The only operation allowed is to insert characters in the beginning of the string. How many minimum characters are needed to be inserted to make the string a palindrome string

Example:
Input: ABC
Output: 2
Input: AACECAAAA
Output: 2
*/

#include<bits/stdc++.h>

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

int Solution::solve(string s) {
    int len = s.length();

    string s_rev = s;
    reverse(s_rev.begin(), s_rev.end());

    string s2 = s_rev + "$" + s;

    return len - f(s2);
}
