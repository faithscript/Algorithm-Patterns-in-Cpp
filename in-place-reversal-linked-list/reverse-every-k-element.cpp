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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1){
            return head;
        }

        ListNode* d = new ListNode(0);
        ListNode* p = d;
        ListNode* c = head;

        while(c){
            ListNode* check = c;
            int cnt = 0;
            while(cnt < k && check){
                cnt++;
                check = check->next;
            }

            if(cnt < k){
                p->next = c;
                break;
            }

            ListNode* c2 = c;
            ListNode* p2 = nullptr;
            for(int i = 0; i < cnt; ++i){
                ListNode* N = c->next;
                c->next = p2;
                p2 = c;
                c = N; // c is at the start of the next interval, and p2 is at the beginning of the just finished interval
                // c2 is at the end of the just finished interval
            }

            p->next = p2;
            c2->next = c;
            p = c2;
        }
        return d->next;
    }
};

// game plan:
// if not head or not head_n or k == 1 return head base
// as usual set dummy as d, and a tracker, p starting from d since reversal always starts at p_n
// we start reversal at head so c = head
// now while c, we set the cnt to 0
// set a starting pointer that spans the interval as itv starting at curr then while cnt < k and itv, itv = itv_n and cnt++

// let's now make new reverse pointers, p2 as the new prev for reversal, then c2 to save curr

// for the range [0, cnt), save c_n as N, c_n = p2; p2 = c; c = N

// after this reversal, c is at the start of the next interval
// c2 was at start but now end so;
// c2_n = nullptr, fixed as c2_n = c;
// p2 was at end but nowstart, so p_n = p2;
// p has to be before the next interval, so p = c2

// since p is usually before the next interval, and c is usually at the start of the next, if we don't have a complete cnt = k; p_n = c and break

