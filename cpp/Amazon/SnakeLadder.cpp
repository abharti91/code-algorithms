#include<bits/stdc++.h>
using namespace std;

struct Node{
    int v; //vertex number
    int dist; //distance from start 1
};

Node *getNode(int v, int d){
    Node *n = (Node*)malloc(sizeof(Node*));
    n->v = v;
    n->dist = d;
    return n;
}

int f(int M[], int n){
    bool *visited = new bool[n];
    memset(visited, false, sizeof(visited));

    queue<Node*> q;
    Node *node = getNode(0, 0);

    q.push(node);
    visited[0] = true;

    while(!q.empty()){
        node = q.front();
        int v = node->v;
        if(v == n-1)
            break;

        int d = node->dist;
        //cout << "popping : " << v << endl;
        q.pop();

        for(int i=v+1; i<=v+6 && i<n; i++){
            if(!visited[i]){
                Node *n = getNode(0, 0);
                n->dist = d+1;
                visited[i] = true;
                //if there is snake or laddere from this vertex i
                if(M[i] != -1)
                    n->v = M[i];
                else
                    n->v = i;
                q.push(n);
            }
        }
    }
    return node->dist;
}

int main(int argc, char const *argv[]) {

    int T, N, i, j, M[30]; //M[i] = j array represents move of i to j
    cin >> T;

    while(T--){
        memset(M, -1, sizeof(M));
        cin >> N;
        for(int x=0; x<N; x++){
            cin >> i >> j;
            M[i-1] = j-1;
        }
        cout << f(M, 30) << endl;
    }
    return 0;
}
