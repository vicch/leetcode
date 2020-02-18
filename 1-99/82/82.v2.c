#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int main()
{

}

/**
 * Re-structure the list by changing the values of node pointers, instead of
 * changing the values of node->next pointers.
 *
 * E.g. change x->y->z->... to x->z->...
 * (Memory content is represented as [<address>]:<value>)
 *
 * Before:
 * [1]:10  [2]:20  [3]:30  // node
 * [10]:x  [20]:y  [30]:z  // node->val
 * [11]:2  [21]:3  [31]:4  // node->next
 * 
 * Instead of:
 * [1]:10  [2]:20  [3]:30  // node
 * [10]:x  [20]:y  [30]:z  // node->val
 * [11]:3  [21]:3  [31]:4  // node->next
 *      ^-- Changed
 *
 * Change as:
 *             v-- Changed
 * [1]:10  [2]:30  [3]:30  // node
 * [10]:x  [20]:z  [30]:z  // node->val
 * [11]:2  [21]:4  [31]:4  // node->next
 */
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode** runner = &head;
    
    if (!head || !head->next) return head;
    
    while (*runner) {
        if((*runner)->next && (*runner)->next->val == (*runner)->val) {
            struct ListNode* temp = *runner;
            while (temp && (*runner)->val == temp->val)
                temp = temp->next;
            *runner = temp;
        } else
            runner = &((*runner)->next);
    }
    
    return head;
}