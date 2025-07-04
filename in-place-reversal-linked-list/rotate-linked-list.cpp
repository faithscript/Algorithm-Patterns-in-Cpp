// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

// Example 1:


// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]
// Example 2:


// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]
 

// Constraints:

// The number of nodes in the list is n.
// 1 <= k <= n <= 5000
// 0 <= Node.val <= 1000
 

// Follow-up: Can you solve the problem in O(1) extra memory space?
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;

        int n = 1;
        ListNode* tail = head;
        while(tail->next){
            tail = tail->next;
            n++;
        }

        k %= n;
        if(k == 0) return head;
        
        tail->next = head;
        ListNode* tail2 = head;
        for(int i = 0; i < n - k - 1; ++i){
            tail2 = tail2->next;
        }

        ListNode* head2 = tail2->next;
        tail2->next = nullptr;

        return head2;

    }
};

// gameplan
// so we use a while(tail_n) to get the tail to the end and record the length;
// return head if !head or !head_n or k == 0
// normalize k
// if it's 0 return head again
// make the tail_n = head; to make it a cycle

// make a new pointer tail2 and start it at head
// this new tail will be n - k - 1 units away from the head
// then a new head, head2 starts at tail2_n
// then make the tail2_n nullptr;