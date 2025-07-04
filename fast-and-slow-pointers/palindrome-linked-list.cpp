// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
// Example 1:
// Input: head = [1,2,2,1]
// Output: true
// Example 2:

// Input: head = [1,2]
// Output: false
 
// Constraints:
// The number of nodes in the list is in the range [1, 105].
// 0 <= Node.val <= 9
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
    bool isPalindrome(ListNode* head) {
        if(!head) return true;

        ListNode* s = head;
        ListNode* f = head;

        while(f && f->next){
            s = s->next; f = f->next->next;
        }
        ListNode* sec = reverseList(s);
        ListNode* fir = head;

        while(sec){
            if(fir->val != sec->val) return false;
            fir = fir->next;
            sec = sec->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* lst){
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
};

// game plan is just to find the middle, reverse it, and compare values while the second list isn't null ptr cuz it's usually the smaller one
