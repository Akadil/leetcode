class Solution(object):
    def carFleet(self, target, position, speed):
        """
        :type target: int
        :type position: List[int]
        :type speed: List[int]
        :rtype: int
        """
        counter = len(position)
        stack = zip(position, speed)
        stack.sort()
        t = float(target - stack[len(speed) - 1][0]) / stack[len(speed) - 1][1]
        for i in range(len(speed) - 2, -1, -1):
            new_t = float(target - stack[i][0]) / stack[i][1]
            if new_t <= t:
                counter -= 1
            else:
                t = new_t
        return counter
