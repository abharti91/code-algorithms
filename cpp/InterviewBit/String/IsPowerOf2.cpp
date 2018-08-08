/*
Power of 2
Find if Given number is power of 2 or not.
More specifically, find if given number can be expressed as 2^k where k >= 1.

Input:
number length can be more than 64, which mean number can be greater than 2 ^ 64 (out of long long range)
Output:
return 1 if the number is a power of 2 else return 0

Example:
Input : 128
Output : 1
*/

#include<bits/stdc++.h>
using namespace std;
int Solution::power(string A) {

    //divide by 2
    int n = A.length();
    string s = "";
    int carry  = 0;

    //k>=1 base cases
    if(A.compare("0") == 0 || A.compare("1") == 0)
        return 0;

    while(A.length() > 0){
        //cout << A << endl;
        if(carry && A.compare("1") != 0)
            return 0;

        if(!carry && A.compare("1") == 0)
            return 1;

        carry = 0;
        s.clear();

        //if this leaves carry = 1 it means number is not divisible by 2
        for(int i=0; i<A.length(); i++){
            int num;
            if(carry){
                num = 10 + (A[i]-'0');
            }
            else{
                num = A[i]-'0';
            }

            //if A[i] = 1 and there is no carry , thenget A[i+1]
            if(carry==0 && A[i] == '1' && i+1 < n){
                num = (A[i]-'0')*10 + (A[i+1]-'0');

                //if 1 is not in 0th index or last index then we need to pad extra '0' in s
                if(i != 0 )
                   s += '0';

                i++;
            }


            //if odd then store half of it in s and forward carry = 1
            if(num % 2 != 0){
                s += (num/2) + '0';
                carry = 1;
            }

            else{
                s += (num/2) + '0' ;
                carry = 0;
            }
        }

        A.clear();
        A = s;

    }
    return 1;
}
