class MinStack(object):

    def __init__(self):
        self.stack = []
        self.minstack = []

    def push(self, val):
        """
        :type val: int
        :rtype: None
        """
        self.stack.append(val)
        if len(self.minstack) == 0:
            self.minstack.append(val)
        else:
            # print(val, self.stack, self.minstack)
            self.minstack.append(min(val, self.minstack[len(self.minstack) - 1]))

    def pop(self):
        """
        :rtype: None
        """
        if len(self.stack) != 0:
            self.stack.pop()
            self.minstack.pop()
        
    def top(self):
        """
        :rtype: int
        """
        if len(self.stack) != 0:
            return self.stack[-1]

    def getMin(self):
        """
        :rtype: int
        """
        if len(self.stack) == 0:
            return None
        else:
            return self.minstack[-1]
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
