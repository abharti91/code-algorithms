/*
Given a string detect the smallest window length that contains all the distinct characters of the given string even if it contains repeating elements​.
For eg. A = “aabcbcdbca”, then the result would be 4 as of the smallest window will be “dbca” .

Another example, in “aabcbcdb”, the smallest string that contains all the characters is “abcbcd”.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains a string S.

Output:
For each test case in a new line print the length of the smallest such string.

Constraints:
1<=T<100
1<=|S|<=1000

Example:
Input:
2
aabcbcdbca
aaab

Output:
4
2
*/
#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

int f(string s){

    if(s.length() == 1)
        return 1;

    int min = INT_MAX;

    map<char, int> m;
    //count number of distict chars in s
    for(int i = 0; i < s.length(); i++){
        if(m[s[i]] == 0){
            m[s[i]]++;
        }
    }

    int distict_count = m.size();
    m.clear();

    int start = 0;
    for(int i = 0; i< s.length(); i++){
        m[s[i]]++;

        //if we found all distict chars in this substring we check if this is smallest found so far
        if(m.size() == distict_count){
            //in found substring check if we can get smaller substring (with all chars) by removing each char from front
            while(start < s.length() && m.size() == distict_count){
                m[s[start]]--;

                //if char count is 0 then remove corresponding <key,val> from map,so count can be reduced by 1
                if(m[s[start]] == 0)
                    m.erase(s[start]);

                start++;
            }
            if(start < s.length()){
                start--;
                m[s[start]]++;
            }
            min = min > (i-start+1) ? (i-start+1) : min;
        }
    }
    return min;
}

int main(){
    int T;
    cin >> T;

    string s;
    while(T--){
        cin >> s;
        cout << f(s) << endl;
    }
    return 0;
}
