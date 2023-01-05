class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        returner = ListNode(-1)
        ptr = returner
        adder = 0
        while l1 is not None or l2 is not None:
            if l2 is None:
                if adder == 1:
                    l1.val += 1
                    adder = 0
                if l1.val > 9:
                    l1.val -= 10
                    adder = 1
                if returner.val == -1:
                    returner.val = l1.val
                else:
                    new = ListNode(l1.val)
                    ptr.next = new
                    ptr = new
                l1 = l1.next
            elif l1 is None:
                if adder == 1:
                    l2.val += 1
                    adder = 0
                if l2.val > 9:
                    l2.val -= 10
                    adder = 1
                if returner.val == -1:
                    returner.val = l2.val
                else:
                    new = ListNode(l2.val)
                    ptr.next = new
                    ptr = new
                l2 = l2.next
            else:
                val = l1.val + l2.val
                if adder == 1:
                    val += 1
                    adder = 0
                if val > 9:
                    val -= 10
                    adder = 1
                if returner.val == -1:
                    returner.val = val
                else:
                    new = ListNode(val)
                    ptr.next = new
                    ptr = new
                l1 = l1.next
                l2 = l2.next
        if adder == 1:
            new = ListNode(1)
            ptr.next = new
            ptr = new
        return returner
