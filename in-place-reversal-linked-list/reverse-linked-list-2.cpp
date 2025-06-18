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
 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right){
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        for(int i = 0; i < left - 1; i++){
            prev = prev->next;   // prev = 1
        }

        ListNode* curr = prev->next;  // curr = 2

        // moving the node after curr to the front of the list
        // 2 3 4
        // 3 2 4
        // 4 3 2
        // 1 3 2 4 5
        for(int i = 0; i < right - left; i++){
            ListNode* temp = curr->next;   // 4 -> 5
            curr->next = temp->next;   // curr-> next now makes it 2, 4, 5
            temp->next = prev->next;  // 3's next is now 245 making 3, 2, 4, 5
            prev->next = temp;    //    prev is 1 and we want the next to be 3 2 4 5
        }

        return dummy->next;




    }
};