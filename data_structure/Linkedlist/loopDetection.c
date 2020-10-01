#include <stdio.h>
#include <stdlib.h>


struct ListNode
{
    int val;
    struct ListNode *next;
};

int detectLoop(struct ListNode *head)
{
    struct ListNode *outer = head;
    int nodesTraversedByOuter = 0;
    // Traverse the Linked List.
    while (outer != NULL)
    {
        outer = outer->next;
        nodesTraversedByOuter++;
        struct ListNode *inner = head;
        int k = nodesTraversedByOuter;
        
        while (k > 0)
        {
            if (inner == outer)
            {
                return 1;
            }
            inner = inner->next;
            k--;
        }
    }
    return 0;
}

int main()
{
    struct ListNode *head = malloc(sizeof(struct ListNode));
    head->val = 2;
    struct ListNode *l1 = malloc(sizeof(struct ListNode));
    l1->val = 8;
    head->next = l1;
    struct ListNode *l2 = malloc(sizeof(struct ListNode));
    l2->val = 3;
    l1->next = l2;
    struct ListNode *l3 = malloc(sizeof(struct ListNode));
    l3->val = 5;
    l2->next = l3;
    struct ListNode *l4 = malloc(sizeof(struct ListNode));
    l4->val = 10;
    l3->next = l4;
    l4->next = l2;
    
    printf("%d", detectLoop(head));
    return 0;
}
