/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.
A valid IP address must be in the form of A.B.C.D, where A,B,C and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.
Example:
Given “25525511135”,
return [“255.255.11.135”, “255.255.111.35”]. (Make sure the returned strings are sorted in order)
*/

#incluide<bits/stdc++.h>
using namespace std;

//validate string formed
//a,b,c,d = lengths of each part of IP address
//from base function we generate a/b/c/d combinations and valiadte if its valid here
string getStr(string s, int a, int b, int c, int d){
        string sa = "", sb = "", sc = "", sd = "";
        int i = 0, isValid = 1, aa, bb, cc, dd, res = 0;

        //if first char in each octet is '0' and length of that part > 1 then ignore it
        //Case 00.1.54.6 123.000.45.2 1.1.00.3 1.54.67.000
        if(s[0] == '0' && a > 1)
            isValid = 0;
        if(s[a] == '0' && b > 1)
            isValid = 0;
        if(s[a+b] == '0' && c > 1)
            isValid = 0;
        if(s[a+b+c] == '0' && d > 1)
            isValid = 0;

        //prepare number to check if less than 255 else invalid
        while(a--){sa += s[i]; res = res*10 + s[i]-'0';i++;}
        aa = res;

        res = 0;
        while(b--){sb += s[i];res = res*10 + s[i]-'0';i++;}
        bb = res;

        res = 0;
        while(c--){sc += s[i];res = res*10 + s[i]-'0';i++;}
        cc = res;

        res = 0;
        while(d--){sd += s[i];res = res*10 + s[i]-'0';i++;}
        dd = res;

        //if number > 255 then it is invclid
        if(aa > 255 || bb > 255 || cc > 255 || dd > 255)
            isValid = 0;

        //if valid return the combination formed
        if(isValid)
            return sa+'.'+sb+'.'+sc+'.'+sd;

        return "";
}

vector<string> Solution::restoreIpAddresses(string s) {
    int n = s.length();
    if(n < 3)
        return {};

    vector<string> res;
    int a, b, c, d;

    //prepare base first string
    if(n==12){a=3;b=3;c=3;d=3; }
    if(n==11){a=3;b=3;c=3;d=2; }
    if(n==10){a=3;b=3;c=3;d=1; }
    if(n==9){a=3;b=3;c=2;d=1; }
    if(n==8){a=3;b=3;c=1;d=1; }
    if(n==7){a=3;b=2;c=1;d=1; }
    if(n==6){a=3;b=1;c=1;d=1; }
    if(n==5){a=2;b=1;c=1;d=1; }
    if(n==4){a=1;b=1;c=1;d=1; }

    string p = getStr(s, a, b, c, d);
    if(p.length() != 0){
        res.push_back(p);
        //cout << p << endl;
    }

    //actual logic to generate all possible combinations of strings
    //3333 -> 3332 -> 3331 -> 3323 -> 3322 so on
    //a,b,c,d tell us lengths of individual parts of ip and add to result vector
    while(1){
        d--;
        if(d == 0){
            d = 3;
            c--;
            if(c == 0){
                c = 3;
                b--;
                if(b == 0){
                    b = 3;
                    a--;

                    //once a=1 break;
                    if(a == 0){
                        return res;
                    }

                }
            }
        }
        //we need to check sum of a,b,c,d = s.length()
        if(a+b+c+d != n)
            continue;

        //break input string based on . based on values a,b,c,d and push to result
        p = getStr(s, a, b, c, d);
        if(p.length() != 0){
            //cout << p << endl;
            res.push_back(p);
        }
    }

    reverse(res.begin(), res.end());
    return res;
}
