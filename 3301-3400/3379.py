class Solution:
    def constructTransformedArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        results = list(range(n))
        # results = []

        for i in range(0, n):
            if nums[i] == 0:
                results[i] = 0
                # results.append(0)
            elif nums[i] > 0:
                # results[i] = nums[self._get_index_right_rotation(i, n, nums[i])]
                results[i] = nums[(i + nums[i]) % n]
                # results.append(nums[(i + nums[i]) % n])
            else:
                # results[i] = nums[self._get_index_left_rotation(i, n, abs(nums[i]))]
                results[i] = nums[(i - abs(nums[i])) % n]
                # results.append(nums[(i - abs(nums[i])) % n])
        return results


    # def _get_index_right_rotation(self, curr, size, step):
    #     """
    #         curr: current index in the array
    #         size: size of an array
    #         step: steps to rotate
    #     """
    #     return (curr + step) % size

    # def _get_index_left_rotation(self, curr, size, step):
    #     """
    #         curr: current index in the array
    #         size: size of an array
    #         step: steps to rotate
    #     """
    #     return (curr - step) % size