/*
Zigzag String
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P.......A........H.......N
..A..P....L....S....I...I....G
....Y.........I........R
And then read line by line: PAHNAPLSIIGYIR
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"
**Example 2 : **
ABCD, 2 can be written as

A....C
...B....D
and hence the answer would be ACBD.
*/
#include<bits/stdc++.h>
using namespace std;

string Solution::convert(string s, int n) {

    int m = s.size();
    if(isspace(s[m-1])){
        s = s.substr(0, m-1);
    }
    m = s.size();

    //if string is empty or of length 1
    if(m == 0 || m == 1)
        return s;

    //if there is only one row
    if(n == 0 || n == 1)
        return s;


    //if n is graeter than equal to string length
    if(n >= m)
        return s;


    char C[n][m];
    memset(C, '.', n*m);



    //row and col indexes
    int r = 0, c = 0;
    bool inc = true;

    for(int i=0; i<m; i++){

        //if reached bottom then move in up direction
        if(r == n){
            r = r-2;
            inc = false;
        }
        else if(r < 0){
            r = r+2;
            inc =true;
        }

        C[r][c] = s[i];
        if(inc)
            r++;
        else
            r--;

        c++;
    }


    string result = "";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(C[i][j] != '.')
                result += C[i][j];
            //cout << C[i][j] << " ";
        }
        //cout << endl;
    }
    return result;
}
