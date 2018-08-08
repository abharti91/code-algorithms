/*
Sort a linked list using insertion sort.
We have explained Insertion Sort at Slide 7 of Arrays
Insertion Sort Wiki has some details on Insertion Sort as well.
Example :
Input : 1 -> 3 -> 2
Return 1 -> 2 -> 3
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    if(A->next == NULL)
        return A;

    ListNode* prev = A;
    ListNode* curr = A->next;

    //for loop running from i->1 to n
    while(curr != NULL){

        bool b = false;
        //for loop from j->head to i-1
        ListNode* t = A;
        ListNode* t_prev = NULL;
        ListNode* t_next = NULL;
        ListNode* curr_next = NULL;

        while(t != curr){

            if(t->val > curr->val){
                //if head is smaller than curr, modify head to curr
                if(t == A)
                    A = curr;

                t->next = t->next;
                curr_next = curr->next;
                //shift curr to right position
                curr->next = t;

                //set front pointer to curr
                if(t_prev != NULL)
                    t_prev->next = curr;

                //all elements till prev  ->>>> sorted order
                //all elements after prev ->>>> unsorted order
                prev->next = curr_next;
                b = true;
                break;
            }

            t_prev = t;
            t = t->next;
        }

        //if curr was smaller than any previous sorted list, then curr is changed
        //get curr = prev->next since prev was never modified
        if(b){
            curr = prev->next;
        }
        else{
            prev = curr;
            curr = curr->next;
        }
    }

    return A;
}
