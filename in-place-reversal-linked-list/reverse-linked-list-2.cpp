// Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

// Example 1:


// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]
// Example 2:

// Input: head = [5], left = 1, right = 1
// Output: [5]
 

// Constraints:

// The number of nodes in the list is n.
// 1 <= n <= 500
// -500 <= Node.val <= 500
// 1 <= left <= right <= n
 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right){
            return head;
        }

        ListNode* d = new ListNode(0);
        d->next = head;
        ListNode* p = d;

        for(int i = 0; i < left - 1; ++i){
            p = p->next;
        }

        ListNode* c = p->next; // starts at 2, p starts at 1
        
        for(int i = 0; i < right - left; ++i){
            ListNode* t = c->next; // save 3 || 3 4 5 ||| save 4->5
            c->next = t->next; // sets 2 -> 4 5       ||| set 2 -> 5
            t->next = p->next; // sets 3 -> 2 4 5     ||| set 4 -> 3 2 5
            p->next = t; // sets 1 -> 3 2 4 5         ||| set 1 -> 4 3 2 5
        }

        return d->next;
    }
};

// gameplan:
// l and r are the sublists and are 1-indexed
// create a dummy node, d, with the value 0, set d_n = head;
// let's look for the start of the reversal of the sublist with a tracker p;
// start p at d, incase the sublist starts at head
// set p = p_n for all [0, l-1), since they're 1-indexed, we want p to be just before the element at l

// set a pointer c to be p_n, meaning the actual element at l

// for all [0, r-l), in here we just want to move the node after c to the front of the list
// [2] 3 4, where c = 2 turns to, 3 [2] 4, then 4 3 [2]
// we can call this node after c, t, so we set t = c_n
// 