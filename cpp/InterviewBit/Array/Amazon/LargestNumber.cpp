/*
Given a list of non negative integers, arrange them such that they form the largest number.
For example:
Given [3, 30, 34, 5, 9], the largest formed number is 9534330.
*/

#include<bits/stdc++.h>
#include<string>
using namespace std;

int compare(string x, string y){
    string xy = x.append(y);
    string yx = y.append(x);
    return xy.compare(yx) > 0 ? 1 : 0;
}

string largestNumber(const vector<int> &A) {

    int n = A.size(), i;
    string ans = "";
    vector<string> v;

    if(n == 0)
        return "";

    if(n == 1)
        return std::to_string(A[0]);

    //if all are 0's
    for(i=0; i<n; i++){
        if(A[i] != 0)
            break;
    }
    if(i == n)
        return "0";


    for(i=0; i<n; i++)
        v.push_back(std::to_string(A[i]));

    sort(v.begin(), v.end(), compare);

    for(i=0; i<v.size(); i++){
        cout << v[i] << "   ";
        ans += v[i];
    }
    return ans;
}

int main(){
    vector<int> v;
    int n, x;
    cin >> n;

    while(n--){
        cin >> x;
        v.push_back(x);
    }

    cout << largestNumber(v);
    return 0;
}
