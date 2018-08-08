/*
Given an integer, convert it to a roman numeral, and return a string corresponding to its roman numeral version
Input is guaranteed to be within the range from 1 to 3999.\
Example :
Input : 5
Return : "V"

Input : 14
Return : "XIV"
 Note : This question has a lot of scope of clarification from the interviewer. Please take a moment to
  think of all the needed clarifications and see the expected response using “See Expected Output” For the purpose of this question, https://projecteuler.net/about=roman_numerals has very detailed explanations.
*/
#include<bits/stdc++.h>
using namespace std;

string intToRoman(int A) {

    if(A == 0)
        return "";

    map<int, char> m;
    m[1] = 'I'; m[5] = 'V'; m[10] = 'X'; m[50] = 'L'; m[100] = 'C'; m[500] = 'D'; m[1000] = 'M';
    string V[] = {"X", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};// if last digit is 0 add X

    int N = A, digits = 0;
    while(N != 0){
        N = N/10;
        digits++;
    }

    string result;

    int front;
    //keep tracking first digit from front
    while(A != 0){

        //get front digit
        front = A / (int)pow(10, digits-1);

        if(digits == 4){
            //add val times M
            while(front != 0){
                result += 'M';
                front--;
            }
        }


        else if(digits == 3){

            if(front == 4){
                //400 => CD => 500-100
                result += "CD";
            }
            else if(front == 9){
                //900 => CM => 1000-100
                result += "CM";
            }

            //if val>=5, add val-5 times C and 1 D  ex. 800 => DCCC
            else if(front >= 5 ){
                result += 'D';
                front = front-5;
                while(front != 0){
                    result += 'C';
                    front--;
                }
            }
            else if(front < 4){
                //cases => 100, 200, 300
                while(front != 0){
                    result += 'C';
                    front--;
                }
            }
        }


        else if(digits == 2){
            if(front == 4){
                //40 => XL => 50-10
                result += "XL";
            }

            else if(front == 9){
                //90 => XC => 100-10
                result += "XC";
            }

            //if val>=5, add val-5 times X and 1 L  ex. 80 => LXXX
            else if(front >= 5){
                result += 'L';
                front = front-5;
                while(front != 0){
                    result += 'X';
                    front--;
                }
            }
            else if(front < 4){
                //cases => 10, 20, 30
                while(front != 0){
                    result += 'X';
                    front--;
                }
            }
        }


        else{
            //last digits can vary from 0 to 9
            result += V[A];
        }


        A = A % (int)pow(10, digits-1);
        digits--;
    }


    return result;

}
