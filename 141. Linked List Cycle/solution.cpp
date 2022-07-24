/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *oneStep=head, *twoStep=head;
        
        if(head == nullptr)
            return false;
        while(twoStep -> next != nullptr && twoStep -> next -> next  != nullptr){
            oneStep = oneStep -> next;
            twoStep = twoStep -> next -> next;
            
            if(oneStep == twoStep)
                return true;
            
        }
        
        return false;
    }
};