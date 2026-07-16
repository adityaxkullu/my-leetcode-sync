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
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
        if(h1 == nullptr || h2 == nullptr) {
            return h1 == nullptr ? h2 : h1;
        }

        // case 1
        if(h1->val <= h2->val) {
            h1->next = mergeTwoLists(h1->next, h2);
            return h1;
        } else { //case 2
            h2->next = mergeTwoLists(h1, h2->next);
            return h2;
        }
        
    }
};