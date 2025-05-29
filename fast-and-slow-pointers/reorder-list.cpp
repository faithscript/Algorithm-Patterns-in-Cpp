// You are given the head of a singly linked-list. The list can be represented as:

// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.

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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* s = head;
        ListNode* f = head;

        while(f && f->next){
            s = s->next;
            f = f->next->next;
        } 
        ListNode* sec = reverse(s->next);
        s->next = nullptr;
        ListNode* fir = head;
        merge(fir, sec);
    }

    ListNode* reverse(ListNode* lst){
        ListNode* prev = nullptr;
        ListNode* curr = lst;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void merge(ListNode* first, ListNode* second){
        while(second){
            ListNode* curr = first->next;
            ListNode* temp = second->next;

            first->next = second;
            second->next = curr;
            first = curr;
            second = temp;   
        }

    }
};