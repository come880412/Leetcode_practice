# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        recordNodeBack = head
        recordNodeFront = head
        recordCnt = 0
        
        while(recordNodeFront.next != None):
            recordNodeFront = recordNodeFront.next
            recordCnt += 1
            if(recordCnt > n):
                recordNodeBack = recordNodeBack.next
            
        if(recordCnt == 0): # Only 1 node
            return None
        elif(recordCnt < n):
            head = head.next
        else:
            if(recordNodeBack.next == None): # Deleted node is in the tail
                recordNodeBack = recordNodeBack.next
            else:
                recordNodeBack.next = recordNodeBack.next.next
        
        return head
            
            