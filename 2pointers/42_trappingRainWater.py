class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """

        l = 0
        r = len(height) - 1
        level = 0
        container = 0
        while l < r:
            if min(height[l], height[r]) < level:
                # print(container, l, r, height[l], height[r], level)
                if level > height[l]:
                    container += level - height[l]
                if level > height[r]:
                    container += level - height[r]
            else:
                level = min(height[l], height[r])
            if height[l] > height[r]:
                r -= 1
            else:
                l += 1
        return container
