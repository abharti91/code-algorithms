/*
Given an array of integers A and a sum B, find all unique combinations in A where the sum is equal to B.
each number in A may only be used once in the combination

Note:
   All numbers will be positive integers.
   Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
   The combinations themselves must be sorted in ascending order.
   If there is no combination possible the print "Empty" (without qoutes).
Example,
Given A = 10,1,2,7,6,1,5 and B(sum) 8,

//1,1,2,5,6,7,10

A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
*/
#include<bits/stdc++.h>
using namespace std;

void findSum(vector< vector<int> >& res, vector<int>& v, vector<int>& r, int sum, int i){
    if(sum < 0)
        return;

    if(sum == 0){
        res.push_back(r);
        return;
    }

    //backtracking logic
    while(i < v.size() && sum-v[i] >= 0){
        r.push_back(v[i]);
        //if we just pass i here then we will get all unique combinations with elements of array repeated
        findSum(res, v, r, sum-v[i], i+1);
        i++;
        r.pop_back();
    }
}

std::vector< vector<int> > combinationSum(std::vector<int>& v, int sum){
    sort(v.begin(), v.end());
    std::vector<int> r;
    std::vector< std::vector<int> > res;
    findSum(res, v, r, sum, 0);
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
        cin >> sum;

        std::vector< vector<int> > res = combinationSum(v, sum);

        if(res.size() == 0)
            cout << "Empty";
        else{

            //logic to remove duplicate entries from vector of vectors
            std::sort(res.begin(), res.end());
            res.erase(unique(res.begin(), res.end()), res.end());

            std::vector< vector<int> >::iterator row;
            std::vector<int>::iterator col;
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
