//fact(N)   1<=N<=1000
#include<bits/stdc++.h>
#include<string>
#include<algorithm>
using namespace std;

//logic to reverse a char array
string rev(string s){
    if(s.length() == 0 || s.length() == 1)
        return s;

    int i=0, j=s.length()-1;
    while(i<j){
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
        i++;
        j--;
    }
    return s;
}


//string multiplied to x
string stoi_multi(string s, int x){
    string srev = "";

    int len = s.length();
    if(len == 1){
        int t = (s[0]-'0') * x;    //"6" * 4
        srev += t/10 + '0';         //""+2
        srev += t%10 + '0';         //""+4
        return srev;
    }

    int sum = 0, carry = 0;
    for(int i=len-1; i>=0; i--){
        sum = ( (s[i]-'0') * x ) + carry;
        srev += sum%10 +'0';
        carry = sum/10;
    }

    //while carry is prsent get each char from carry one by one
    while(carry != 0){
        srev += carry%10 + '0';
        carry = carry/10;
        //if(carry)
            //srev += carry%10+ '0';
    }

    return rev(srev);
}

std::map<int, string> buildFactTable(){
    std::map<int, string> map;
    map[1] = "1";
    map[2] = "2";
    for(int i=3; i<=1000; i++){
        map[i] = stoi_multi( map[i-1] , i);
        //cout << map[i] << " ";
    }
    return map;
}

int main(){
    std::map<int, string> result = buildFactTable();

    int T, n; cin>>T;
    for(int t=0; t<T; t++){
        cin >> n;
        cout << result[n] << endl;
    }
    return 0;
}
