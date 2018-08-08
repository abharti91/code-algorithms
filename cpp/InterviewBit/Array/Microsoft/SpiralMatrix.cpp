#include<bits/stdc++.h>
using namespace std;

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {

    vector<int> v;
    int T = 0, B = A.size()-1, L = 0, R = A[0].size()-1;

    if(A.size() == 1){
        for(int i=0; i<A[0].size(); i++){
            v.push_back(A[0][i]);
        }
        return v;
    }

    if(A[0].size() == 1){
        for(int i=0; i<A.size(); i++){
            v.push_back(A[i][0]);
        }
        return v;
    }

    int dir = 0;
    while(T <= B && L <= R){
        if(dir == 0){
            for(int j = L; j <= R; j++)
                v.push_back(A[T][j]);
            T++;
            dir = 1;
        }

        else if(dir == 1){
            for(int i = T; i <= B; i++)
                v.push_back(A[i][R]);
            R--;
            dir = 2;
        }

        else if(dir == 2){
            for(int j = R; j >= L; j--)
                v.push_back(A[B][j]);
            B--;
            dir = 3;
        }

        else if(dir == 3){
            for(int i = B; i >= T; i--)
                v.push_back(A[i][L]);
            L++;
            dir = 0;
        }
    }
    return v;
}
