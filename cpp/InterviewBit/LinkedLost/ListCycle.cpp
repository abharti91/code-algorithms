/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    ListNode* head = A;

    //length 1
    if(A->next == NULL)
        return NULL;

    ListNode* slow = A->next;
    ListNode* fast = slow->next;

    while(slow != fast){

        if(slow == NULL || fast == NULL || fast->next == NULL)
            return NULL;

        //cout << slow->val << "," << fast->val << endl;

        slow = slow->next;
        fast = fast->next->next;
    }

    assert(slow==fast);


    //there exists cycle
    while(head != slow){
        head = head->next;
        slow = slow->next;
    }
    return head;
}
