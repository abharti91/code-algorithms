#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int LCS(char* S1, char* S2, int n, int m){
    int A[n+1][m+1], result = 0;
    std::memset(A, 0, sizeof(A));

    for(int i=0; i<n+1; i++){
        for(int j=0; j<m+1; j++){
            if(i ==0 || j ==0){
                A[i][j] = 0;
            }
            else if(S1[i-1] == S2[j-1]){
                A[i][j] = A[i-1][j-1] + 1;
                result = max(result, A[i][j]);
            }
        }
    }
    return result;
}

int main(){
    int T; cin >> T;
    for(int t=0; t<T; t++){
        int n1, n2;
        cin >> n1 >> n2;
        char s1[n1], s2[n2];
        cin >> s1 >> s2;

        cout << LCS(s1, s2, n1, n2) << endl;
    }
    return 0;
}
