// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

// Do not modify the linked list.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return nullptr;

        ListNode* s = head;
        ListNode* f = head;

        while(f && f->next){
            s = s->next;
            f = f->next->next;

            if(s == f){
                s = head;
                while(s != f){
                    s = s->next;
                    f = f->next;
                }
                return s;
            }
        }
        return nullptr;

        
    }
};
// [head, cycle start] = [meeting point, cycle start]