/*

Example

     1                    1
   /    \                 /   \
 2      3             3     2

Output: 1

    1                      1
   /  \                    /  \
 2    3                2    3

Output: 0

Note: you may assume that root of both the given tree as 1.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow.
The first line of each test case contains two space separated values n and e denoting the no of nodes and edges respectively.
Then in the next line two lines are 2*e space separated values u,v denoting an edge from u to v for the both trees .

Output:
For each test case in a new line print 1 if both the trees are mirrors of each other else print 0.

Constraints:
1<=T<=20
1<=n<=15
1<=e<=20

Example:
Input:
2
3 2
1 2 1 3
1 3 1 2
3 2
1 2 1 3
1 2 1 3
Output:
1
0
*/

#include<bits/stdc++.h>
using namespace std;

//tree1 -> tree1[x] -> stack of all childrens of node x
//tree2 -> tree2[y] -> queue of all childrens of node y
int isMirror(vector< stack<int> >& tree1, vector< queue<int> > tree2, int n){

    for(int i = 1; i < n+1; i++){
        stack<int>& s = tree1[i];
        queue<int>& q = tree2[i];

        if(s.size() != q.size())
            return 0;

        while(!s.empty() && !q.empty()){
            if(s.top() != q.front())
                return 0;
            else{
                s.pop();
                q.pop();
            }
        }
    }
    return 1;
}

int main(int argc, char const *argv[]) {
    int T;
    cin >> T;
    while(T--){
        int n, e, u, v;
        cin >> n >> e;

        vector< stack<int> > tree1(n+1);
        for(int i = 0; i < e; i++){
            cin >> u >> v;
            tree1[u].push(v);
        }

        vector< queue<int> > tree2(n+1);
        for(int i = 0; i < e; i++){
            cin >> u >> v;
            tree2[u].push(v);
        }
        cout << isMirror(tree1, tree2, n) << endl;
    }
    return 0;
}
