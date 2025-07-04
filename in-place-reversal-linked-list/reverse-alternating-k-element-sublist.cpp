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

    ListNode* d = new ListNode(0);
    d->next = head

    ListNode* p = dummy;
    ListNode* c = head;

    bool rev =  true;

    while(c){
      int cnt = 0;
      ListNode* check = c;
      while(check && cnt < k){
        cnt++;
        check = check->next;
      }

      if(cnt < k){
        if(rev){
          ListNode* p2 = nullptr;
          for(int i = 0; i < cnt; i++){
            ListNode* N = c->next;
            c->next = p2;
            p2 = c;
            c = N;
          }
          p->next = p2;
        }else{
          p->next = curr;
        }
        break;
      }

      if(rev){
          ListNode* c2 = c;
          ListNode* p2 = nullptr;
          for(int i = 0; i < k; i++){
            ListNode* N = c->next;
            c->next = p2;
            p2 = c;
            c = N;
          }
          p->next = p2;
          c2->next = c;
          prev = c2;
      }else{
        for(int i = 0; i < k; i++){
          p = c;
          c = c->next;
        }
      }
      rev = !rev;
    }

    return d->next


  }
};


