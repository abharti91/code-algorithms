/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.
For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,
return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list. Note 2:
Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question.
*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* reverse(ListNode* A, int diff) {
    ListNode* prev   = NULL;
    ListNode* current = A;
    ListNode* next = NULL;
    ListNode* reverse_end = A;

    while (diff > 0 && current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
        diff--;
    }

    //point last elemet of reverse list to  current
    reverse_end->next = current;
    return prev;
}

ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if(B == C)
        return A;

    ListNode* head = A;
    ListNode* p = NULL;
    int x = B;

    while(x != 1){
        p = A;
        A = A->next;
        x--;
    }

    //mth node = A
    //B-C list of length  B-C to be reversed

    //means m=0
    if(p == NULL)
        return reverse(A, C-B+1);
    else
        p->next = reverse(A, C-B+1);

    return head;
}
