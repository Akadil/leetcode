class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        stack = []
        for c in tokens:
            if c in ('+', '-', '*', '/'):
                if c == '+':
                    stack.append(stack.pop() + stack.pop())
                elif c == '-':
                    stack.append(-1 * (stack.pop() - stack.pop()))
                elif c == '*':
                    stack.append(stack.pop() * stack.pop())
                elif c == '/': 
                    y = stack.pop()
                    x = stack.pop()
                    stack.append(int(float(x)/y))
            else:
                stack.append(int(c))
        return stack[0]
