// You are given the head of a linked list.

// Remove every node which has a node with a greater value anywhere to the right side of it.

// Return the head of the modified linked list.

 

// Example 1:


// Input: head = [5,2,13,3,8]
// Output: [13,8]
// Explanation: The nodes that should be removed are 5, 2 and 3.
// - Node 13 is to the right of node 5.
// - Node 13 is to the right of node 2.
// - Node 8 is to the right of node 3.
// Example 2:

// Input: head = [1,1,1,1]
// Output: [1,1,1,1]
// Explanation: Every node has value 1, so no nodes are removed.
 

// Constraints:

// The number of the nodes in the given list is in the range [1, 105].
// 1 <= Node.val <= 105

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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        ListNode* curr = head;

        while(curr){
            while(!st.empty() && curr->val > st.top()->val){
                st.pop();
            }
            st.push(curr);
            curr = curr->next;
        }

        // stack has the values but in reverse

        vector<ListNode*> nodes;
        while(!st.empty()){
            nodes.push_back(st.top());
            st.pop();
        }
        reverse(nodes.begin(), nodes.end());

        //reconnect the nodes;

        for(int i = 0; i < nodes.size() - 1; ++i){
            nodes[i]->next = nodes[i+1];
        }
        if(!nodes.empty()){
            nodes.back()->next = nullptr;
            return nodes[0];
        }

        return nullptr;
    }
};


class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        while(head){
            ListNode* nextN = head->next;
            head->next = prev;
            prev = head;
            head = nextN;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        ListNode* curr = head;

        int mx = INT_MIN;

        while(curr){
            if(curr->val >= mx){
                mx = curr->val;
                tail->next = curr;
                tail = curr;
            }
            curr = curr->next;
        }
        tail->next = nullptr;

        return reverse(dummy->next);
    }
};