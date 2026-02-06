class Solution:
    def minRemoval(self, nums: List[int], k: int) -> int:
        """
            compare the values of all possible valid windows

            Start from the left most window and move right pointer until the window is 
            invalid. Once reached, compare to previous best value. Then continue 
            iteration
        """
        n = len(nums)
        nums.sort()

        r = 0
        result = n

        for l in range(n):
            # find the biggest valid window
            while r != n and nums[l] * k >= nums[r]:
                r += 1

            result = min(result, n - (r - l))
        
        return result

    def _minRemoval_attempt1(self, nums: List[int], k: int) -> int:
        """
            Remove min or max value depending on who is progressing more:

            if removing max element gives better ratio of next_max / min than removing 
            min element, then we remove the max element. Greedy algorithm

            Flaw of an algorithm: 
            Greedy algo gives a solution, but it's not the optimal one. It's possible
            that even if the ratio is better, it will remove too much elements which
            is not the problem statement (we have to remove min number of elem)

            Test it crashed:
            nums = [466,306,76,17,60,246,341,284]
            k = 2

        """
        if len(nums) == 1:
            return 0

        # Sort in order to track lowest and highest numbers
        nums.sort()

        # Iterate and move pointers
        l = 0
        r = len(nums) - 1

        while (l != r):
            if nums[l] * k >= nums[r]:
                break
            elif nums[r - 1] / nums[l] < nums[r] / nums[l + 1]:
                r -= 1
            else:
                l += 1
            
        # return the difference of original lenth and computed lenth
        return l - 0 + len(nums) - 1 - r


        