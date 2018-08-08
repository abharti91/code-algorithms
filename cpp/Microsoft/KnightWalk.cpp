/*
Given a chess board of order NxM and source points (s1,s2) and destination points (d1,d2), Your task to find min number of moves required by the Knight to go to the destination cell.

Other way is to use array to get only correct moves by knight as
d[x] = {-2, -1,  1,  2, -2, -1, 1 ,2}
d[y] = {-1, -2, -2, -1,  1,  2, 2, 1};
*/
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int minMovesStoD(int n, int m, int Sx, int Sy, int Dx, int Dy){
    //Edge case 1
    if(Sx==Dx && Sy==Dy)
        return 0;

    queue< pair<int,int> > q;
    int ans = -1;
    int A[n][m];
    std::memset(A, -1, sizeof(A));

    //starting index(Sx,Sy) should be at 0 distance from (Sx.Sy)
    A[Sx][Sy] = 0;

    q.push(make_pair(Sx, Sy));
    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        //cout << "Popped element: (" << p.first << "," << p.second << ")" << endl;

        for(int x = std::max(0,p.first-2); x <= std::min(p.first+2, n-1); x++){
            for(int y = std::max(0,p.second-2); y <= std::min(p.second+2, m-1); y++){
                //cout << " (" << x << "," << y << ") " << endl;

                //knight cannot move in same line, it moves 2&1/2 moves at one time
                //skip all diagonal elemnts in 5x5 matrix centred at (p.first,p.second)
                //also if cordinates already visited skip it
                if(x == p.first || y == p.second ||
                    (x == p.first-1 && y == p.second-1 && p.first-1 >=0 && p.second-1 >=0) ||
                    (x == p.first-2 && y == p.second-2 && p.first-2 >=0 && p.second-2 >=0) ||
                    (x == p.first+1 && y == p.second-1 && p.first+1 < n && p.second-1 >=0) ||
                    (x == p.first+2 && y == p.second-2 && p.first+2 < n && p.second-2 >=0) ||
                    (x == p.first-1 && y == p.second+1 && p.first-1 >=0 && p.second+1 < m) ||
                    (x == p.first-2 && y == p.second+2 && p.first-2 >=0 && p.second+2 < m) ||
                    (x == p.first+1 && y == p.second+1 && p.first+1 < n && p.second+1 < m) ||
                    (x == p.first+2 && y == p.second+2 && p.first+2 < n && p.second+2 < m) ||
                                    A[x][y] != -1)
                    continue;

                //cout << "Adding into queue: (" << x << "," << y << ") " << endl;
                q.push(make_pair(x, y));
                A[x][y] = A[p.first][p.second] + 1;
                //cout << " A[" << x << "][" << y << "] = " << A[x][y] << endl;

                //found destination after above step since we may get this dest pair in one of above non valid moves
                if(x == Dx && y == Dy)
                    return A[x][y];
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    int T, n, m;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> n >> m;
        int sx, sy, dx, dy;
        cin >> sx >> sy >> dx >> dy;

        cout << minMovesStoD(n, m, sx-1, sy-1, dx-1, dy-1) << endl;
    }
  return 0;
}
