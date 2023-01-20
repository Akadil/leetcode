# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        temp, temp2 = head, head
        while n > 0:
            temp = temp.next
            n -= 1
        if temp is None:
            return head.next
        while temp.next is not None:
            temp, temp2 = temp.next, temp2.next
        temp2.next = temp2.next.next
        return head
