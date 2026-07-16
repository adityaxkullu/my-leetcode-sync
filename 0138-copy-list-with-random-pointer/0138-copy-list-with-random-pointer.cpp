/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) {
            return nullptr;
        }

        Node* temp = head;

        // step1 insertion of copy node

        while(temp != nullptr) {
            // create copy node
            Node* copy = new Node(temp->val);

            // passing of addresses to avoid misplacing
            copy->next = temp->next;
            temp->next = copy;

            // updation of temp 
            temp = copy->next;
        }

        // step2 connect random pointers

        temp = head;

        while(temp != nullptr) {
            if(temp->random != nullptr) {
                temp->next->random = temp->random->next; // connection of random pointers
            }
            temp = temp->next->next; //updation of temp
        }

        // step3 separate both lists

        temp = head;
        Node* newHead = temp->next; // newHead store head of the copy list
        Node* copy = newHead; //copy traverses the nodes of copy list

        while(temp) {
            temp->next = temp->next->next;

            if(copy->next != nullptr) {
                copy->next = copy->next->next;
            }

            // updates temp and copy pointer
            temp = temp->next;
            copy = copy->next;
        }

        return newHead;

       
        
    }
};