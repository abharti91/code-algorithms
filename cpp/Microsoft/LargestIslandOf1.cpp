/*
Getting largest island of 1's in 2D matrix using non-recursive/BFS
*/
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

int findLargestGroupOf1(int M[][55], int n, int m){

	queue< pair<int,int> > q;
	int count = 0, maxi = -10000;

	bool visited[n][m];
	memset(visited, 0, n*m);

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){

			if(M[i][j] == 1 && !visited[i][j]){
				q.push(make_pair(i,j));
				cout << "(" << i << "," << j << ")";
				visited[i][j] = 1;
				count = 1;

				while(!q.empty()){
					pair<int,int> p = q.front();
					q.pop();

					//search all 8 neighbours in array and validates index as well
					for(int x=max(0,p.first-1); x<=min(p.first+1,n); x++){
						for(int y=max(0,p.second-1); y<=min(p.second+1,m); y++){

							if(x==p.first && y==p.second)
								continue;

							if(M[x][y]==1 && !visited[x][y]){
								q.push(make_pair(x,y));
								count++;
								visited[x][y] = 1;
							}
						}
					}
				}
			}
			maxi = max(count, maxi);
		}
	}
	return maxi;
}

int main(){

	int T, n, m;
	cin >> T;
	while(T--){
		cin >> n >> m;
		int M[55][55];
		memset(M , 0 ,sizeof(M));
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++)
				cin >> M[i][j];
		}
		cout << findLargestGroupOf1(M, n, m) << endl;
	}
	return 0;
}
