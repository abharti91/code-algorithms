/*
A Hamiltonian path, is a path in an undirected or directed graph that visits each vertex exactly once.
Given an undirected graph  the task is to check if a Hamiltonian path is present in it or not.
Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line consists of two space
separated integers N and M denoting the number of vertices and number of edges.Then in the next line are M space separated pairs u,v denoting an edge from u to v.
Output:
For each test case in a new line print 1 if a Hamiltonean path exists else print 0.

Constraints:
1<=T<=100
1<=N<=10
1<=M<=15
Example:
Input:
2
4 4
1 2 2 3 3 4 2 4
4 3
1 2 2 3 2 4
Output:
1
0
*/
#include<bits/stdc++.h>
using namespace std;

class Graph{
        int V;
        //pointer to list of ints, ie adjacent[0] is array , adjacent[1] is array and so on
        list<int> *adjacent;
    public:
        Graph(int V);
        void addEdge(int u, int v);
        int DFSUtil(bool visited[], int count, int s);
        int isHamiltonianPathExists(int start);
        void printGraph();
};

Graph::Graph(int V){
    this->V = V;
    adjacent = new list<int>[V+1];
}

void Graph::addEdge(int u, int v){
    adjacent[u].push_back(v);
    adjacent[v].push_back(u);
}

/*int Graph::DFSUtil(bool visited[], int *count, int s){

    list<int>::iterator it;
    for(it = adjacent[s].begin(); it != adjacent[s].end(); it++){
        if(!visited[*it]){
            visited[*it] = true;
            cout << "(" << *it << ","  << *count << ")";
            if(*count == V-1){
                //cout << "found Hamiltonion path" << endl;
                return 1;
            }
            else{
                (*count)++;
                if(DFSUtil(visited, count, *it))
                    return 1;
                //  count--;
            }
            visited[*it] = false;
        }
    }
    return 0;
}*/

int Graph::DFSUtil(bool visited[], int count, int s){
    if(count == V)
        return 1;

    list<int>::iterator it;
    for(it = adjacent[s].begin(); it != adjacent[s].end(); it++){
        if(!visited[*it]){
            visited[*it] = true;

            //cout << "(" << *it << ","  << count << ")";

            if(DFSUtil(visited, count+1, *it))
                return 1;

            visited[*it] = false;
        }
    }
    return 0;
}

int Graph::isHamiltonianPathExists(int start){
    if(V == 1)
        return 1;

    bool visited[V+1];
    memset(visited, false, sizeof(visited));

    //cout << "Path starting from  vertex :" << start << " --->";
    int count = 1;
    visited[start] = true;
    return DFSUtil(visited, count, start);
}

void Graph::printGraph(){
    for(int i=1; i<=V; i++){
        cout << " Edge from " << i << " ---> ";
        list<int>::iterator it;
        for(it = adjacent[i].begin() ; it != adjacent[i].end(); it++){
            cout << *it << " ";
        }
        cout << endl;
    }
}


int main(int argc, char const *argv[]) {
    int T;
    cin >> T;

    for(int t=0; t<T; t++){
        int V, E;
        cin >> V >> E;

        Graph g(V);

        for(int i=0; i<E; i++){
            int u , v;
            cin >> u >> v;
            g.addEdge(u, v);
        }

        //g.printGraph();
        int ans = 0;
        for(int i=1; i<=V; i++){
            if(g.isHamiltonianPathExists(i)){
                ans = 1;
                //cout << "for vertex " << i << ":" << ans << endl;
                break;
            }
            else{
                // /cout << "for vertex " << i << ":" << ans << endl;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
