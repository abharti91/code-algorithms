/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

    342 + 465 = 807
Make sure there are no trailing zeros in the output list
So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.
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
 ListNode* reverse(ListNode* A) {

    ListNode** head_ref = &A;

    ListNode* prev   = NULL;
    ListNode* current = *head_ref;
    ListNode* next = NULL;

    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;

    return *head_ref;
}
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {

    if(A == NULL)
        return B;
    if(B == NULL)
        return A;

    //traverse till min(len(A), len(B)) since list are already in reversed order
    int sum = 0, carry = 0;
    ListNode* node = NULL;
    ListNode* head = NULL;

    while(A != NULL && B != NULL){
        sum = (A->val + B->val + carry) % 10;
        carry = (A->val + B->val + carry) / 10;

        //add in list in from end to front
        node = new ListNode(sum);
        node->next = head;
        head = node;

        A = A->next;
        B = B->next;
    }

    //if A is bigger
    while(A != NULL){
        sum = (A->val + carry) % 10;
        carry = (A->val + carry) / 10;
        node = new ListNode(sum);
        node->next = head;
        head = node;
        A = A->next;
    }

    //if B is bigger
    while(B != NULL){
        sum = (B->val + carry) % 10;
        carry = (B->val + carry) / 10;
        node = new ListNode(sum);
        node->next = head;
        head = node;
        B = B->next;
    }

    //if some carry still left
    if(carry){
        node = new ListNode(carry);
        node->next = head;
        head = node;
    }

    head = reverse(head);
    return head;
}
