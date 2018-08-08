/*

Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20
  4 -> 11 -> 15
The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20
*/

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
ListNode* mergeTwoLists(ListNode* A, ListNode* B) {

    if(A == NULL)
        return B;

    if(B == NULL)
        return A;

    //head points to lower value
    ListNode* head = A->val < B->val ? A : B;
    if(A->val < B->val)
        A= A->next;
    else
        B= B->next;

    ListNode* t = head;

    while(A != NULL && B != NULL){

        if(A->val < B->val){
            t->next = A;
            t = t->next;
            A = A->next;
        }
        else{
            t->next = B;
            t = t->next;
            B = B->next;
        }
    }

    //if A is not completed
    while(A != NULL){
        t->next  = A;
        t = t->next;
        A= A->next;
    }

    while(B != NULL){
        t->next  = B;
        t = t->next;
        B= B->next;
    }
    return head;
}
