from dataclasses import dataclass

class Solution:
    @dataclass
    class TrionicSubarray:
        l: int
        r: int 
        p: int 
        q: int

    def maxSumTrionic(self, nums: List[int]) -> int:
        max_sum = float('-inf')

        trionic = self._find_next_trionic(nums, 0)
        while trionic.r != len(nums):
            max_sum = max(max_sum, self._get_max_sum(nums, trionic))

            trionic = self._find_next_trionic(nums, trionic.q)
            if trionic is None:
                break

        return max_sum

    def _get_max_sum(self, nums: List[int], trionic: TrionicSubarray) -> int:
        """
            Given a trionic subarray, iterate through all possible valid 
            subarrays to find the maximum sum

            the function assumes that initial subarray is a valid trionic
            subarray
        """
        # Find the max value in the first increasing sequence
        ind = trionic.p - 1
        left_sum = float('-inf')
        temp = 0
        while (ind >= trionic.l):
            temp += nums[ind]
            left_sum = max(left_sum, temp)
            ind -= 1

        # Find the max value in the second increasing sequence
        ind = trionic.q + 1
        right_sum = float('-inf')
        temp = 0
        while (ind <= trionic.r):
            temp += nums[ind]
            right_sum = max(right_sum, temp)
            ind += 1

        # calculate the final subarray
        middle_sum = 0
        ind = trionic.p
        while (ind != trionic.q + 1):
            middle_sum += nums[ind]
            ind += 1
        return left_sum + middle_sum + right_sum


    def _find_next_trionic(self, nums: List[int], l: int) -> self.TrionicSubarray | None:
        while (l < len(nums) - 3):
            # find the beginning of increasing sequence 
            while (l + 1 != len(nums) and nums[l] >= nums[l + 1]):
                l += 1

            # find the beginning of descreasing sequence
            p = l
            while (p + 1 != len(nums) and nums[p] < nums[p + 1]):
                p += 1
            if l == p:
                continue

            # find the beginning of increasing sequence
            q = p
            while (q + 1 != len(nums) and nums[q] > nums[q + 1]):
                q += 1
            if q == p:
                l = q # update the left index 
                continue

            # find the end of increasing sequence
            r = q
            while (r + 1 != len(nums) and nums[r] < nums[r + 1]):
                r += 1
            if (r == q):
                l = q # update the left index
                continue
            return (self.TrionicSubarray(l=l, r=r, p=p, q=q))

        return None
