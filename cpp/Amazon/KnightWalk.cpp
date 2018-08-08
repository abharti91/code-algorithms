/*
Given a chess board of order NxN and source points (s1,s2) and destination points (d1,d2), Your task to find min number of moves required by the Knight to go to the destination cell.

Other way is to use array to get only correct moves by knight as
d[x] = {-2, -1,  1,  2, -2, -1, 1 ,2}
d[y] = {-1, -2, -2, -1,  1,  2, 2, 1};
*/
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

//they are valid adjacent moves of knight when added by their current indices
int a[] = {-2,-1,1,2,-2,-1,1,2};
int b[] = {-1,-2,-2,-1,1,2,2,1};

int minMovesStoD(int N, int sx, int sy, int dx, int dy){
    if(sx==dx && dx==dy)
        return 0;

    int A[N][N];
    memset(A, -1, sizeof(A));
    A[sx][sy] = 0;

    //store valid index pairs from matrix A
    queue< pair<int,int> > q;
    q.push(make_pair(sx,sy));
    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();


        for(int i=0; i<8; i++){

            if(p.first+a[i] < 0 || p.first+a[i] >= N || p.second+b[i] < 0 || p.second+b[i] >= N)
                continue;

            //move by knight not traversed
            if(A[p.first + a[i]][p.second + b[i]] == -1){
                A[p.first+a[i]][p.second+b[i]] = A[p.first][p.second] + 1;
                q.push(make_pair(p.first+a[i], p.second+b[i]));
            }

            //found destination
            if(p.first+a[i] == dx && p.second+b[i] == dy)
                return A[p.first+a[i]][p.second+b[i]];
        }
    }
    return -1;
}

int main(int argc, char const *argv[]) {
    int T, n, m;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> n;
        int sx, sy, dx, dy;
        cin >> sx >> sy;
        cin >> dx >> dy;
        cout << minMovesStoD(n, sx-1, sy-1, dx-1, dy-1) << endl;
    }
  return 0;
}
