class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        biggest = 0
        stack = [] # (height, len)
        for num in heights:
            
            # Adding the new num to stack
            counter = 0
            while stack and num <= stack[-1][0]:
                trash = stack.pop()
                volume = trash[0] * (trash[1] + counter)
                if volume > biggest:
                    biggest = volume
                counter += trash[1]
            stack.append((num, counter + 1))
            
        # checking if I have new maximum
        counter = 0
        for i in range(len(stack) - 1, -1, -1):
            volume = stack[i][0] * (stack[i][1] + counter)
            if volume > biggest:
                biggest = volume
            counter += stack[i][1]
            
        return biggest
