class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        returner = []
        for i in range(len(nums)):
            if i == 0:
                returner.append(1)
            else:
                returner.append(returner[i - 1] * nums[i - 1])
        suffix = 1
        for i in range(len(nums) - 1, -1, -1):
            returner[i] *=  suffix
            suffix = suffix * nums[i]
        return returner
