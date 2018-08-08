/*
Remove Duplicates from Sorted List II
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.


*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #include<bits/stdc++.h>
 using namespace std;
 
ListNode* Solution::deleteDuplicates(ListNode* A) {

    if(A == NULL || A->next == NULL)
        return A;

    ListNode* n = A;
    ListNode* prev = NULL;
    bool b = false;

    while(n != NULL){

        b = false;

        while(n->next != NULL && n->val == n->next->val){
            n->next = n->next->next;
            b = true;
        }

        if(b){
            //if first element is duplicated
            //head will be first non repeating(n->next) element
            if(prev == NULL)
                A = n->next;
            else
                prev->next = n->next;
        }
        else{
            //keep track of previous element
            prev = n;
        }
        n = n->next;
    }

    return A;
}
