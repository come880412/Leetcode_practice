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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* front = head;
        ListNode* back = head;
        int count = 0;
        
        if(head -> next == nullptr) return nullptr; // if num_size == 1
        
        else{
            while(back -> next != nullptr){
                if(count < n){
                    back = back -> next;
                    count += 1;
                }   
                else{
                    back = back -> next;
                    front = front -> next;
                }
            }
        }
        
        if(n == 1) front->next = nullptr; // delete the last val
        else if(count < n) head = head -> next;
        else front -> next = front -> next -> next;
        
        
        return head;
    }
};