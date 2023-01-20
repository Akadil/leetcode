# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: None Do not return anything, modify head in-place instead.
        """

        if head.next is None:
            return 
        ptr_s, ptr_f = head, head.next
        while ptr_f and ptr_f.next:
            ptr_s = ptr_s.next
            ptr_f = ptr_f.next
            if ptr_f.next is None:
                break
            ptr_f = ptr_f.next
        prev = None
        while ptr_s:
            nxt = ptr_s.next
            ptr_s.next = prev
            prev = ptr_s
            ptr_s = nxt
        while head:
            nxt, nxt_f = head.next, ptr_f.next
            head.next = ptr_f
            ptr_f.next = nxt
            head, ptr_f = nxt,nxt_f
