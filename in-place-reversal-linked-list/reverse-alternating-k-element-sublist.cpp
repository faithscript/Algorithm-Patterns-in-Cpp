// Problem Statement
// Given the head of a LinkedList and a number ‘k’, reverse every alternating ‘k’ sized sub-list starting from the head.

// If, in the end, you are left with a sub-list with less than ‘k’ elements, reverse it too.

// Image
// Constraints:

// The number of nodes in the list is n.
// 1 <= k <= n <= 5000
// 0 <= Node.val <= 1000

using namespace std;

#include <iostream>

/*class ListNode {
public:
  int val = 0;
  ListNode *next;

  ListNode(int value) {
    this->val = value;
    next = nullptr;
  }
};*/

class Solution {
public:
  ListNode *reverse(ListNode *head, int k) {
    if(!head || k<=1){
      return head;
    }

    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* prev = dummy;
    ListNode* curr = head;

    bool reverse = true;

    while(curr){
      int cnt = 0;
      ListNode* interval = curr;
      while(interval && cnt < k){
        cnt++;
        interval = interval->next;
      }

      if(cnt < k){
        if(reverse){
          ListNode* revPrev = nullptr;
          for(int i = 0; i < cnt; i++){
            ListNode* nextN = curr->next;
            curr->next = revPrev;
            revPrev = curr;
            curr = nextN;
          }
          prev->next = revPrev;
        }else{
          prev->next = curr;
        }
        break;
      }

      if(reverse){
          ListNode* start = curr;
          ListNode* revPrev = nullptr;``
          for(int i = 0; i < k; i++){
            ListNode* nextN = curr->next;
            curr->next = revPrev;
            revPrev = curr;
            curr = nextN;
          }
          prev->next = revPrev;
          start->next = curr;
          prev = start;
      }else{
        for(int i = 0; i < k; i++){
          prev = curr;
          curr = curr->next;
        }
      }
      reverse = !reverse;
    }

    ListNode* ans = dummy->next;
    delete dummy;
    return ans;


  }
};
