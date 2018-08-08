#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

//sort in descendng order by order of X
//if first elements are same then sort second array in increasing order
bool sortByX(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

//sort in descendng order by order of Y
bool sortByY(pair<int,int> a, pair<int,int> b){
    return a.second > b.second;
}


int f(int N, int X, int Y, std::vector< pair<int,int> > v){
    //loop untill one of them gets all orders either X or Y
    int i = 0, ans = 0;
    while(i < N  && X > 0 && Y > 0){
        //select from x & y which gives maximum tip for that index
        //if there is duplicate of maximum element(lets say in array x) then pick index from x with minimum value from y
        //since with sorting, if there are duplicate elements in one array , corresponding elements in other array  (are in increasing sorted)
        if(v[i].first > v[i].second){
            ans += v[i].first;
            i++;
            X--;
        }
        else{
            ans += v[i].second;
            i++;
            Y--;
        }
    }
    //if any elements left from array x just copy them
    if(X > 0){
        while(X > 0 && i < N){
            ans += v[i].first;
            i++;
            X--;
        }
    }

    //if any elements left from array y just copy them
    if(Y > 0){
        while(Y > 0 && i < N){
            ans += v[i].second;
            i++;
            Y--;
        }
    }
    return ans;
}

int main() {
    int T, X, Y, N;
    cin >> T ;
    for(int t=0; t<T; t++){
        cin >> N >> X >> Y;

        int x[N], y[N], max = -1;
        for(int n=0; n<N; n++)
            cin >> x[n];

        for(int n=0; n<N; n++)
            cin >> y[n];

        std::vector< pair<int,int> > v;
        for(int i=0; i<N; i++)
            v.push_back(make_pair(x[i], y[i]));

        int ans1 = 0, ans2 = 0;
        sort(v.begin(), v.end(), sortByX);
        ans1 = f(N, X, Y, v);

        sort(v.begin(), v.end(), sortByY);
        ans2 = f(N, X, Y, v);
        cout << max(ans1, ans2) << endl;
    }
	return 0;
}
