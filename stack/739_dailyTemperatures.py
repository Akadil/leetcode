class Solution(object):
    def dailyTemperatures(self, temperatures):
        """
        :type temperatures: List[int]
        :rtype: List[int]
        """
        res = [0]* len(temperatures)
        stack = []
        for i, num in enumerate(temperatures):
            while stack and temperatures[stack[-1]] < num:
                val = stack.pop()
                res[val] = i - val
            stack.append(i)
        return res
