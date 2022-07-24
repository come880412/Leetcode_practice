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
    // Iterative version
//     ListNode* reverseList(ListNode* head) {
//         ListNode* next=NULL;
//         ListNode* prev=NULL;
        
//         while(head != nullptr){
//             next = head->next;
//             head->next = prev;
//             prev = head;
//             head = next;
//         }
//         head = prev;
        
//         return head;
//     }
    
    // recursive version
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        
        ListNode* next = head->next;
        head->next = nullptr;
        ListNode* prev = reverseList(next);
        next->next = head;
        
        return prev;
        
    }
};