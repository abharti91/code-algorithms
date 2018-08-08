/*
K reverse linked list
Problem Setter: mihai.gheorghe
Problem Tester: yashpal1995
Given a singly linked list and an integer K, reverses the nodes of the
list K at a time and returns modified linked list.
 NOTE : The length of the list is divisible by K
Example :
Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,
You should return 2 -> 1 -> 4 -> 3 -> 6 -> 5
Try to solve the problem using constant extra space.
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

//logic to reverse k elements
ListNode* reverse(ListNode* A, int k) {
    ListNode* prev   = NULL;
    ListNode* current = A;
    ListNode* next = NULL;

    //last element in reverse list
    ListNode* reverse_end = A;
    while (k > 0 && current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
        k--;
    }

    //point last element of reverse list to  current
    reverse_end->next = current;
    return prev;
}

ListNode* Solution::reverseList(ListNode* A, int B) {

    //base case
    if(B == 0 || B == 1)
        return A;

    //same as above
    if(A == NULL || A->next == NULL)
        return A;


    ListNode* n = A;
    int len = 0;
    while(n != NULL){
        n = n->next;
        len++;
    }

    ListNode* new_head = A;
    ListNode* end_prevlist = NULL;
    bool head_found = false;
    //reverse list of size B
    while(len >= B){
        if(!head_found){
            head_found = true;
            new_head = reverse(A, B);
        }
        else{
            end_prevlist->next = reverse(A, B);
        }

        //keep track of last element of previous list ,
        //this will point to head of new reversed list
        end_prevlist = A;
        A = A->next;
        len = len-B;
    }
    return new_head;
}
