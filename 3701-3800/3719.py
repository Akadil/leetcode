class Solution:
    # Brute Force solution
    # 
    # Runtime: 54.9 %, Memory: 34.04%
    # 
    def longestBalanced_brute_force(self, nums: List[int]) -> int:
        n = len(nums)
        count = 0

        for l in range(n):
            r = l
            
            num_odd = set()
            num_even = set()
            
            for r in range(l, n):
                if nums[r] % 2 == 0:
                    num_even.add(nums[r])
                else:
                    num_odd.add(nums[r])

                if len(num_even) == len(num_odd):
                    count = max(count, r - l + 1)

        return count

    # Attempt to solve with prefix numbers. 
    # Failed. if 2 consecutive same numbers, the algo allows to delete one. e.g. nums =[6,6]
    # 
    # def longestBalanced(self, nums: List[int]) -> int:
    #     n = len(nums)
    #     count = 0

    #     even_prefix = self._get_prefix(nums, lambda x: x % 2 == 0, n)
    #     odd_prefix = self._get_prefix(nums, lambda x: x % 2 == 1, n)
    #     # print(f"DEBUG: Prefixes. \neven: {even_prefix}, \nodd: {odd_prefix}\n\n")

    #     for left in range(n):
    #         for right in range(left + 1, n + 1):
    #             even_count = even_prefix[right] - even_prefix[left]
    #             odd_count = odd_prefix[right] - odd_prefix[left]
                
    #             # print(f"DEBUG: [{l}, {r}] even: {even_count}, odd: {odd_count}")
    #             if even_count == odd_count:
    #                 count = max(count, right - left)

    #     return count
                

    # def _get_prefix(self, nums: List[int], is_desired: collection.abc.Callable, n: int) -> List[int]:
    #     """
    #         Build prefix array of distinct elements satisfying predicate.
    #     """
    #     answer = [0] * (n + 1)
    #     dist_numbers = set()

    #     for i in range(1, n + 1):
    #         if is_desired(nums[i - 1]):
    #             dist_numbers.add(nums[i - 1])
    #         answer[i] = len(dist_numbers)

    #     return answer
