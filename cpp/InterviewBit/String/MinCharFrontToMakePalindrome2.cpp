#include<bits/stdc++.h>

bool isPalindrome(string s){
    int n = s.length(), i, j;

    for(i =0, j = n-1; i <= j; i++, j--){
        if(s[i] != s[j])
            return false;
    }
    return true;
}

int solve(string s) {
    int len = s.length();

    if(len == 0 || len == 1)
        return 0;

    int i = 0, cnt = 0, flag =01;

    while(i < len){
        if(isPalindrome(s)){
            flag = 1;
            break;
        }
        else{
            s.erase(s.begin() + s.length() - 1);
            cnt++;
        }
    }

    if(flag)
        return cnt;
}
