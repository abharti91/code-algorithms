/*
Given a string with repeated characters, task is to rearrange characters in a string such that no two adjacent characters are same.
Note : It may be assumed that the string has only lowercase English alphabets.
Input:
The first line of input contains an integer T denoting the number of test cases.
Then T test cases follow. Each test case contains a single line containing a string of lowercase english alphabets.

Output:
For each test case in a new line print 1 if the generated sting doesn't contains any same adjacent characters, else if no such string is possible to be made print 0.
Constraints:
1<=T<=100
1<=length of string<=600

Example:
Input:
3
geeksforgeeks
bbbabaaacd
bbbbb

Output:
1
1
0
*/
#include<bits/stdc++.h>
using namespace std;

struct compare{
    bool operator()(pair<char,int> p1, pair<char,int> p2){
        return p1.second < p2.second;
    }
};

int f(string s){
    int len = s.length();
    int alpha[26];

    memset(alpha, 0, sizeof(alpha));

    for(int i = 0; i < len; i++)
        alpha[s[i]-'a']++;

    //max heap based on count of character
    priority_queue<pair<char,int>, vector< pair<char,int> >, compare> pq;
    for(int i = 0; i < 26; i++){
        if(alpha[i])
            pq.push(make_pair(i+'a', alpha[i]));
    }


    //output string such that no char is adjacent
    string ans = "";

    //set previous to popped element (which was inserted to s)
    pair<char,int> prev = make_pair('$', -1);

    //Input : bbbabaaacd --> Priority Queue : (a,4) (b,4) (c,1) (d,1)  --> Required String : ababababcd
    while(!pq.empty()){
        pair<char, int> p1 = pq.top();
        pq.pop();

        //compare popped element from prev, if same pop next element
        if(prev.first == p1.first){
            if(!pq.empty()){
                pair<char,int> p2 = pq.top();
                pq.pop();
                (p2.second)--;
                ans += p2.first;
                prev = p2;
                if(p2.second > 0)
                    pq.push(p2);
            }
            else
                return 0;
        }
        else{
            (p1.second)--;
            ans += p1.first;
            prev = p1;
        }

        //push into queue this char whose count was lowered by 1, only if count>0
        if(p1.second > 0)
            pq.push(p1);
    }

    //cout << ans << endl;
    return 1;
}

int main(){
    int T; cin >> T;
    string s;
    while(T--){
        cin >> s;
        cout << f(s) << endl;
    }
}
