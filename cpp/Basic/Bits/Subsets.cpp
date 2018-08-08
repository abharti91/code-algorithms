/*
Given Set of S = {1,2,3} generate all sub sets(= power set)
{empty, {1}, {1,2}, {1,2,3}, {1,3}, {2}, {2,3}, {3}}

We can modify to print only k sized subsets
*/

#include<bits/stdc++.h>
using namespace std;

template <typename T>
void generate_power_set_helper(std::vector<T> &S, int idx, std::vector<T> &res){

    if(res.empty() == false){
        copy(res.begin(), res.end()-1, ostream_iterator<T>(cout, ","));
        cout << res.back();
    }
    cout << endl;

    for(int i=idx; i<S.size(); i++){
        res.push_back(S[i]);
        generate_power_set_helper(S, i+1, res);
        res.pop_back();
    }
}

template <typename T>
void generate_power_set(std::vector<T> &S){
    std::vector<T> res;
    generate_power_set_helper(S, 0, res);
}

int main(){
    int n, x;
    std::vector<int> S;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x;
        S.push_back(x);
    }
    generate_power_set(S);
    return 0;
}
