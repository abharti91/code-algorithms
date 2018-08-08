/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1,
If version1 < version2 return -1,
otherwise return 0.
You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 1.13 < 1.13.4
*/

#include<bits/stdc++.h>
using namespace std;

string extract(int &i, string str){
    if(i >= str.size()){
        return "0";
    }
    int temp = i;
    stringstream ss;
    ss.str("")
    while(str[temp] != '.' && temp < str.size()){
        ss << str[temp];
        temp++;
    }
    i = temp + 1;

    return ss.str();
}

string rem(string a){
    int i = 0;
    while(a[i] == '0' && i < a.size()){
        i++;
    }
    return a.substr(i);
}

int compareStr(string a, string b, int first){

    string A = rem(a);
    string B = rem(b);

    if(A.size() > B.size()){
        return 1;
    }
    else if(A.size() < B.size()){
        return -1;
    }
    else{
        for(int i = 0; i < A.size(); i++){
            int numa = A[i];
            int numb = B[i];
            if(numa > numb){
                return 1;
            }
            else if(numa < numb){
                return -1;
            }
        }
    }

    return 0;
}

int compareVersion(string A, string B) {
    int i = 0, j = 0, first = 1;
    while(i < A.size() || j < B.size()){
        string numa = extract(i, A);
        string numb = extract(j, B);
        if(compareStr(numa, numb, first) == 1){
            return 1;
        }
        else if(compareStr(numa, numb, first) == -1){
            return -1;
        }
        first = 0;
    }
    return 0;
}
/
