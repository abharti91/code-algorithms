/*

Given a linked list, remove the nth node from the end of list and return its head.

For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

 Note:
If n is greater than the size of the list, remove the first node of the list.
Try doing it using constant additional space.
*/


#include<bits/stdcc+.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* A, int n) {

    //if list is empty
    if(A == NULL)
        return A;

    //p and q will take care of distance
    ListNode* p = A;
    ListNode* q = A;

    //move by B times
    while(n != 0){
        //n is greater than size of list
        //remove first node from the list
        if(q->next == NULL)
            return A->next;

        q = q->next;
        n--;
    }

    //since we have to remove nth node, we will stop just before nth node from mend
    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }

    //remove node at poistion p+1
    p->next = p->next->next;
    return A;
}
