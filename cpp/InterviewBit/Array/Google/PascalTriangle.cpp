#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > generate(int n) {

    vector< vector<int> > res;
    vector<int> v, prev;

    for(int i=0; i<n; i++){
        v.clear();

        //first value will always be 1
        v.push_back(1);
        //iterate on prev vector
        for(int j=0; j<i; j++){

            //if this this last element in vector just paste 1
            if(j == i-1){
                v.push_back(1);
            }
            else{
                 v.push_back(prev[j] + prev[j+1]);
            }
        }

        //copy current vector to prev and add vector for row i
        prev = v;
        res.push_back(v);
    }

    return res;
}


int main(){
    vector<vector<int>> v = generate(10);
    return 0;
}
