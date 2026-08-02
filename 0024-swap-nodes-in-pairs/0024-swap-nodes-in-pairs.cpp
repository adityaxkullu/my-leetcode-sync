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
    ListNode* getPair(ListNode* curr) {
      int k = 2;

      while(curr != nullptr && k > 0) {
        curr = curr->next;
        k--;
      }
      return curr;
    }
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* groupPrev = &dummy;


        while(true) {
            ListNode* pair = getPair(groupPrev);

            if(pair == nullptr) {
                break;
            }

            ListNode* groupNext = pair->next;

            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while(curr != groupNext) {
                ListNode* next = curr->next;
                curr->next = prev;

                prev = curr;
                curr = next;
            }

            ListNode* temp = groupPrev->next;
            groupPrev->next = pair;
            groupPrev = temp;
        }

        return dummy.next;
   
    }
};