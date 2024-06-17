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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode *findMiddleNode(ListNode *head, ListNode *leftNode) {
        ListNode *slowNode = head;
        ListNode *fastNode = head;

        while (fastNode -> next && fastNode -> next -> next) {
            leftNode = leftNode -> next;
            slowNode = slowNode -> next;
            fastNode = fastNode -> next -> next;
        }
        leftNode -> next = nullptr;
        return slowNode;
    }

    TreeNode *buildBST(ListNode *head) {
        if (head == nullptr) return nullptr;
        ListNode dummy = ListNode(0, head);
        ListNode *middleNode = findMiddleNode(head, &dummy);

        TreeNode *root = new TreeNode(middleNode -> val);
        root -> left = buildBST(dummy.next);
        root -> right = buildBST(middleNode -> next);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        return buildBST(head);
    }
};