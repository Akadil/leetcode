class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        f = 0
        e = len(numbers) - 1
        while f < e:
            if numbers[f] + numbers[e] < target:
                f += 1
            elif numbers[f] + numbers[e] > target:
                e -= 1
            else:
                return [f + 1, e + 1]
