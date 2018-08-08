/*Implement strstr
*/
#include<bits/stdc++.h>
using namespace std;

void print(int lps[], int m){
    for(int i=0; i<m; i++)
        cout << lps[i] << " ";
    cout << endl;
}


//preprocessing
void computeLPS(string s, int lps[], int m){
    int len = 0, i = 1;

    while(i < m){
        //if chars match we just keep checking next chars i.e.len+1 and i+1
        if(s[len] == s[i]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            //if mismatch happens, then check current char at i with previous char(which is pointed by len)
            //len-1 = last char which matched with i in above if loop
            //lps[len-1] = length of longest proper prefix which is suffix ending of string ending at indec len-1
            if(len != 0)
                len = lps[len-1];
            else{
                //if len==0, means cannot have any prefix that can also be proper suffix
                lps[i] = 0;
                i++;
            }
        }
    }
    //if we want non overlapping prefix/suffix use
    //return lps[n-1] > n/2 ? n/2 : lps[n-1];
    //return lps[n-1];
}

int strStr(const string A, const string B) {

    //A = text
    int n = A.length();
    //B = pattern
    int m = B.length();


    if(n == 0 || m == 0 || n < m)
        return -1;

    int lps[m];
    memset(lps, 0, sizeof(lps));

    computeLPS(B, lps, m);
    //print(lps, m);

    int i = 0, j = 0;
    while(i < n){

        if(A[i] == B[j]){
            i++;
            j++;
        }

        //pattern B matched to A
        if(j == m){
            //return i - m;
            cout << "Found pattern at starting at index : " << i-m << ", ";
            j = lps[j-1];
        }

        if(A[i] != B[j]){
            //do not match chars from lps[0..j-1]
            //reason = lps[0..j-1] matched with text[k..k+j-1], lps[j-1] chars will be skipped
            //AAAABAAAA,AAAA, lps[0..3] matches with text[0..3], lps[3]=3 means 3 chars will be skipped
            //because these 3 (prefix) chars from pattern matches with 3 (suffix) chars from text
            if(j != 0)
                j = lps[j-1];
            else
                i++;
        }

    }
    return -1;
}

int main(){
    string A, B;

    cin >> A >> B;
    strStr(A, B);
    return 0;
}
