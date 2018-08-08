
#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


pair<ListNode*, bool> f(ListNode* n, int l, int mid){
    pair<ListNode*, bool> t;

    //if we reached mid of ll
    if(mid == 0){
        if(l%2 == 0){
            t.first = n;
            t.second = 1;
        }
        else{
            t.first = n->next;
            t.second = 1;
        }
        return t;
    }
    //cout << "val:" << n->val << ", mid:" << mid << endl;

    t = f(n->next, l, mid-1);

    //cout << "val:" << (t.first)->val << ", bool:" << t.second << endl;

    //if matches till these pairs then unfold next pairs
    if( (t.first)->val == n->val && t.second == 1){
        t.first = (t.first)->next;
        t.second = 1;
    }
    else{
        //mismatch set boolean as false
        t.first = (t.first)->next;
        t.second = 0;
    }

    return t;
}

int Solution::lPalin(ListNode* A) {

    //if ll is empty of length 1
    if(A == NULL || A->next == NULL)
        return 1;

    int l = 0;
    ListNode* N = A;
    while(N != NULL){
        l++;
        N = N->next;
    }

    pair<ListNode*, bool> p = f(A, l, l/2);

    if(p.second)
        return 1;
    return 0;
}
