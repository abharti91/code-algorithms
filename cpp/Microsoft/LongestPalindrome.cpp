/*
Given a string S, find the longest palindromic substring in S.
Substring of string S:
S[ i . . . . j ] where 0 ≤ i ≤ j < len(S)

Palindrome string:
A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.
Incase of conflict, return the substring which occurs first ( with the least starting index ).
*/

/*
O(n2) time + O(1) space https://www.geeksforgeeks.org/longest-palindromic-substring-set-2/
generate all odd and even length palindromes by making each index as centre and traversing in both directions
*/
#include<bits/stdc++.h>
#include<string>
using namespace std;

string longestPalindromeSubstring(string s){
    int len = s.length();

    if(len == 0 || len == 1)
        return s;

    int start = 0, maxLength = 1;

    //for each index we iterate in forward and backward directions getting starting index & max lenght of palindromes
    for(int i=1; i<len; i++){

        //find all odd length palindromes
        int low = i-1;
        int high = i+1;
        while(low >= 0 && high < len && s[low] == s[high]){
            if(maxLength < high-low+1){
                start = low;
                maxLength = high-low+1;
            }
            --low;
            ++high;
        }

        //find all even length palindromes
        low = i-1;
        high = i;
        while(low >= 0 && high < len && s[low] == s[high]){
            if(maxLength < high-low+1){
                start = low;
                maxLength = high-low+1;
            }
            --low;
            ++high;
        }
    }
    return s.substr(start, maxLength);
}

int main(){
    int T; cin >> T;
    string s;

    for(int t=0; t<T; t++){
        cin >> s;
        cout << longestPalindromeSubstring(s) << endl;
    }
    return 0;
}
