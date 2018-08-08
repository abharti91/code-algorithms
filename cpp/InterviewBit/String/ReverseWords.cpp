/*
Given an input string, reverse the string word by word.

Example:

Given s = "the sky is blue",

return "blue is sky the".

A sequence of non-space characters constitutes a word.
Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.
If there are multiple spaces between words, reduce them to a single space in the reversed string.
*/
#include<bits/stdc++.h>
using namespace std;
bool BothAreSpaces(char lhs, char rhs) { return (lhs == rhs) && (lhs == ' '); }


void reverseWords(string &s) {
    int n = s.length();
    bool flag1 = false, flag2 = false;

    if(n == 0 || n == 1)
        return;


    //remove all leading spaces
    int i = 0;
    while(isspace(s[i])){
        i++;
        flag1 = true;
    }

    //remove trailing spaces
    int j = n-1;
    while(isspace(s[j])){
        j--;
        flag2 = true;
    }

    //erase spaces from begining of length i
    //arg1 = first char to be erased, arg2 = num of chars to remove
    if(flag1)
        s.erase(0, i);

    //cout << "string after removing leading spaces" << s << ":"<<  s.length()<< endl;

    //erase spaces from end of lenght n-j
    if(flag2)
        s.erase(j+1-i, n-j-i);

    //cout << "string after removing trailing spaces" << s << ":"<<  s.length()<< endl;


    //tricky part
    //remove duplicates spaces in between
    string::iterator new_end = unique(s.begin(), s.end(), BothAreSpaces);
    s.erase(new_end, s.end());
    //cout << "string after removing spaces in between" << s << ":"<<  s.length()<< endl;

    //reverse complete string
    reverse(s.begin(), s.end());


    //reverse word by word
    i = 0;
    int start = 0;
    while(i < s.length()){
        if(isspace(s[i])){
            reverse(s.begin() + start, s.begin() + i);

            if(i+1 < s.length())
                start = i+1;
        }
        i++;
    }
    //last word must be reversed as well, since there is no space at end
    reverse(s.begin() + start, s.begin() + i);

}
