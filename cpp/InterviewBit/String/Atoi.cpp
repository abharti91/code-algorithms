/*
Implement atoi to convert a string to an integer.

Example :
Input : "9 2704"
Output : 9
Note: There might be multiple corner cases here. Clarify all your doubts using “See Expected Output”.

 Questions: Q1. Does string contain whitespace characters before the number?
A. Yes
Q2. Can the string have garbage characters after the number?
A. Yes. Ignore it.
Q3. If no numeric character is found before encountering garbage characters, what should I do?
A. Return 0.
Q4. What if the integer overflows?
A. Return INT_MAX if the number is positive, INT_MIN otherwise.
*/


#include<bits/stdc++.h>
using namespace std;

bool isNumericChar(char c){return (c >= '0' && c <= '9') ? true : false;}


int atoi(const string A) {
    int n = A.length();
    if(n == 0)
        return 0;

    //trim while spaces before number
    int i=0;
    while(isspace(A[i])){
        i++;
    }
    //arg1 = starting index, arg2 = number of chars
    //A.erase(0, i);

    int res = 0;
    int sign = 1;

    //get sign of number
    if(A[i] == '-'){
        sign = -1;
        i++;
    }

    if(A[i] == '+'){
        i++;
    }

    //traverse string
    for(; i < n; i++){
        //if space is found return number found till this point
        if(isspace(A[i]))
            break;

        //return 0 if garbage chars are there
        if(!isNumericChar(A[i]))
            break;

        //check overflow
        if(res > ( INT_MAX - (A[i]-'0') ) / 10 ){
            if(sign == 1)
                return sign*INT_MAX;
            else
                return sign*INT_MIN;
        }

        res = res*10 + A[i]-'0';
    }

    return sign*res;
}
