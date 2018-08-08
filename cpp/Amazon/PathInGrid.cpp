/*
Submissions: 4431   Accuracy: 36.22%   Difficulty: Medium

Given a N X N matrix (M) filled with 1 , 0 , 2 , 3 . Your task is to find whether there is a path possible from source to destination,
while traversing through blank cells only. You can traverse up, down, right and left.

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Blank Wall.
Note : there is only single source and single destination
*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 25

int f(int a[MAX][MAX], int N){
    bool found = false;
    int visited[N][N], x, y, i, j;

    memset(visited, 0, sizeof(visited));

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(!found && a[i][j] == 1)
                {found=true;break;}
        }
        if(found)
            break;
    }

    queue< pair<int,int> > q;
    q.push(make_pair(i,j));

    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        x = p.first;
        y = p.second;
        visited[x][y] = 1;

        if(x-1 >= 0){
            if(a[x-1][y] == 3 && !visited[x-1][y])
                q.push(make_pair(x-1,y));
            else if(a[x-1][y] == 2)
                return 1;
        }

        //cout << "<" << (x+1<N) << "," << a[x+1][y] << "," << visited[x+1][y] << ">" << endl;
        if(x+1 < N){
            if(a[x+1][y] == 3 && !visited[x+1][y])
                q.push(make_pair(x+1,y));
            else if(a[x+1][y] == 2)
                return 1;
        }

        if(y-1 >= 0){
            if(a[x][y-1] == 3 && !visited[x][y-1])
                q.push(make_pair(x,y-1));
            else if(a[x][y-1] == 2)
                return 1;
        }

        if(y+1 < N){
            if(a[x][y+1] == 3 && !visited[x][y+1])
                q.push(make_pair(x,y+1));
            else if(a[x][y+1] == 2)
                return 1;
        }
    }
    return 0;
}

int main(int argc, char const *argv[]) {
    int T, N;
    cin >> T;
    while(T--){
        cin >> N;
        int a[MAX][MAX];
        memset(a, 0, MAX*MAX);
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                cin >> a[i][j];

        cout << f(a, N) << endl;
    }
    return 0;
}
