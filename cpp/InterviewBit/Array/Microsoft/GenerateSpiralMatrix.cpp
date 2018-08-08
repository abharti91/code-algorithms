#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > generateMatrix(int n) {

    vector< vector<int> > res;
    if(n == 1){
        vector<int> v;
        v.push_back(n);
        res.push_back(v);
        return res;
    }

    int L = 0, R = n-1;
    int T = 0, B = n-1;

    int M[n][n];
    memset(M, 0, sizeof(M));

    int dir = 0, num = 1, i, j;
    while(L <= R && T <= B){

        if(dir == 0){
            for(i=L; i<=R; i++){
                M[T][i] = num;
                num++;
            }
            T++;
            dir = 1;
        }

        else if(dir == 1){
            for(i=T; i<=B;i++){
                M[i][R] = num;
                num++;
            }
            R--;
            dir = 2;
        }

        else if(dir == 2){
            for(i=R; i>=L; i--){
                M[B][i] = num;
                num++;
            }
            B--;
            dir = 3;
        }

        else if(dir == 3){
            for(i=B; i>=T; i--){
                M[i][L] = num;
                num++;
            }
            L++;
            dir = 0;
        }
    }


    for(i=0; i<n; i++){
        vector<int> v;
        for(j=0; j<n; j++){
            cout << M[i][j] << ",";
            v.push_back(M[i][j]);
        }
        cout << endl;
        res.push_back(v);
    }
    return res;
}


int main(int argc, char const *argv[]) {
    vector< vector<int> > v = generateMatrix(50);
    return 0;
}
