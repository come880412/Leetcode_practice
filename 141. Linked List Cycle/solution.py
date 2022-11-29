# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution: # Tortoise and Hare Algorithm
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if head == None:
            return False
        turtle, rabbit = head, head.next
        
        if turtle.next == None:
            return False
        
        while rabbit:
            if turtle.val == rabbit.val and turtle.next == rabbit.next:
                return True
            
            else:
                turtle = turtle.next
                if rabbit.next:
                    rabbit = rabbit.next.next
                else:
                    break
        return False
