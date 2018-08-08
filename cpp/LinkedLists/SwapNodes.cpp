#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

void push(struct Node **head_ref, int data){
    Node *new_node = (struct Node*)malloc(sizeof(struct Node*));
    new_node -> data = data;
    new_node -> next = (*head_ref);
    (*head_ref) = new_node;
}

void print(struct Node **head_ref){
    struct Node *head = *head_ref;
    while(head != NULL){
        cout << head->data << ",";
        head = head->next;
    }
    cout << endl;
}

/*No duplicates
1) x and y may or may not be adjacent.
2) Either x or y may be a head node.
3) Either x or y may be last node.
4) x and/or y may not be present in linked list.
*/
void swap(struct Node **head_ref, int x, int y){
    if((*head_ref) == NULL)
        return;

    if(x == y)
        return;

    struct Node *h = (*head_ref);
    struct Node *prev_x = NULL, *curr_x = (*head_ref);
    while(curr_x != NULL && curr_x->data != x){
        prev_x = curr_x;
        curr_x = curr_x->next;
    }

    struct Node *prev_y = NULL, *curr_y = (*head_ref);
    while(curr_y != NULL && curr_y->data != y){
        prev_y = curr_y;
        curr_y = curr_y->next;
    }

    //if x or y is not present in the list
    if(curr_x == NULL || curr_y == NULL)
        return;

    if(prev_x != NULL)
        prev_x->next = curr_y;
    else
        *head_ref = curr_y;

    if(prev_y != NULL)
        prev_y->next = curr_x;
    else
        *head_ref = curr_y;

    struct Node *temp = curr_y->next;
    curr_y->next = curr_x->next;
    curr_x->next = temp;

    /*h = (*head_ref);
    struct Node *ttemp, *temp;
    //if x or y is at the head of list
    if(prev_x == NULL || prev_y == NULL){
        //prev_x == NULL then x is head of list and y is last element or any other element but not head
        //prev_y == NULL then y is head of list and x is last element or any other element but not head

        struct Node *n = (prev_x == NULL) ? prev_y : prev_x;
        ttemp = n->next->next;
        (*head_ref) = n->next;//new head
        (*head_ref)->next = h->next;
        n->next = h;
        h->next = ttemp;
    }
    else{
        //x and y both are not at head
        //struct Node *curr_x = prev_x->next, *curr_y = prev_y->next;
        if(curr_y == curr_x->next){
            temp = curr_y->next;
            prev_x->next = curr_y;
            curr_y->next = curr_x;
            curr_x->next = temp;
        }
        else{
            ttemp = prev_y->next->next;
            temp = prev_x->next->next;
            prev_y->next = curr_x;
            curr_x->next = ttemp;

            prev_x->next = curr_y;
            curr_y->next = temp;
        }
    }*/
}

int main(){
    struct Node* head = NULL;
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    print(&head);
    swap(&head, 1, 3);
    print(&head);
    swap(&head, 1, 4);
    print(&head);
    swap(&head, 2, 1);
    print(&head);
    swap(&head, 3, 6);
    print(&head);
    swap(&head, 3, 9);
    print(&head);
    return 0;
}
