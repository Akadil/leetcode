class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        l = 0
        r = len(height) - 1
        max_vol = 0
        while l < r:
            if min(height[l], height[r]) * (r - l) > max_vol:
                max_vol = min(height[l], height[r]) * (r - l)
            if height[r] > height[l]:
                l += 1
            else:
                r -= 1
        return max_vol
