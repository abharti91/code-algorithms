/*
1. Create a leaf node for each symbol and add it to the priority queue.
2. While there is more than one node in the queue:
    2.1. Remove the two nodes of highest priority (lowest probability) from the queue
    2.2. Create a new internal node with these two nodes as children and with probability equal to the sum of the two nodes' probabilities.
    2.3. Add the new node to the queue.
3.The remaining node is the root node and the tree is complete.
*/
#include<bits/stdc++.h>
#include<algorithm>
#include <sstream>
#include <string>
using namespace std;

struct MinHeapNode{
    char data;
    int freq;
    struct MinHeapNode *left, *right;

    MinHeapNode(char data, int freq){
        this->data = data;
        this->freq = freq;
        left = NULL;
        right = NULL;
    }
};

//min heap based priority_queue such that top is always smallest value
struct compare{
    bool operator()(MinHeapNode *l, MinHeapNode *r){
        return l->freq > r->freq;
    }
};

void printCode(MinHeapNode *root, string s){
    if(!root)
        return;

    if(root->data != '$')
        cout << s << " ";
        //cout << root->data << ":" << s << "" ;

    printCode(root->left, s+"0");
    printCode(root->right, s+"1");
}

void f(char data[], int freq[], int n){

    MinHeapNode *left, *right, *top;
    //first argument stores all leaves with (data,freq,NULL,NULL)
    //second argument is container object based on vector of first argument
    //compare helps in building min heap
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

    //push all leaves nodes and build minHeap
    for (size_t i = 0; i < n; i++){
        //convert char data[i] into string
        stringstream ss;
        string s;
        ss << data[i];
        ss >> s;
        minHeap.push(new MinHeapNode(data[i], freq[i]));
    }

    //step 2
    while(minHeap.size() != 1){
        left = minHeap.top(); minHeap.pop();
        right = minHeap.top(); minHeap.pop();
        top = new MinHeapNode('$' , left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }

    printCode(minHeap.top(), "");
}

int main(){
    int T; cin >> T;
    while(T--){
        string s;
        cin >> s;

        char data[s.length()+1];
        strcpy(data, s.c_str());

        int freq[s.length()];
        for(int i=0; i<s.length(); i++)
            cin >> freq[i];

        f(data, freq, s.length());
        cout << endl;
    }
}
