class Solution(object):
    def calPoints(self, operations):
        """
        :type operations: List[str]
        :rtype: int
        """
        
        myStack = []

        for elem in operations:
            if elem in ('+', 'D', 'C'):
                if elem == '+':
                    myStack.append(myStack[-1] + myStack[-2])
                elif elem == 'D':
                    myStack.append(2 * myStack[-1])
                else:
                    myStack.pop()
            else:
                myStack.append(int(elem))
        
        return sum(myStack)


"""
    @link       https://leetcode.com/problems/baseball-game/

    @results: 96% speed, 91% memory

"""