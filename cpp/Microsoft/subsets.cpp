/*

Given an array of integers that might contain duplicates, return all possible subsets.

Note Output:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.
    The subsets must be sorted lexicographically.

Example :
If S = [1,2,2], the solution is:

[
[],
[1],
[1,2],
[1,2,2],
[2],
[2, 2]
]
*/
#include<bits/stdc++.h>
using namespace std;

void subsetUtil(vector< vector<int> >& res, vector<int>& v, vector<int>& r, int i){
    //backtracking logic
    while(i < v.size()){
        r.push_back(v[i]);
        res.push_back(r);

        subsetUtil(res, v, r, i+1);
        i++;
        r.pop_back();
    }
}

std::vector< vector<int> > subsets(std::vector<int>& v){
    sort(v.begin(), v.end());
    std::vector<int> r;
    std::vector< std::vector<int> > res;
    subsetUtil(res, v, r, 0);
    return res;
}


int main(){
    int T, n, sum; cin >> T;
    for(int t=0; t<T; t++){
        cin >> n;
        std::vector<int> v; int x;

        for(int i=0; i<n; i++){
            cin >> x;
            v.push_back(x);
        }

        std::vector< vector<int> > res = subsets(v);

        if(res.size() == 0)
            cout << "Empty";
        else{

            //logic to remove duplicate entries from vector of vectors
            std::sort(res.begin(), res.end());
            res.erase(unique(res.begin(), res.end()), res.end());

            std::vector< vector<int> >::iterator row;
            std::vector<int>::iterator col;
            cout << "()";
            for(row = res.begin(); row != res.end(); row++){
                cout << "(";
                for(col = row->begin(); col != row->end(); col++){
                    cout << *col << " ";
                }
                cout << ")";
            }
        }
        cout << endl;
    }

    return 0;
}
