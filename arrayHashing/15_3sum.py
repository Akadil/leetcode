
class Solution(object):

    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        returner = []
        for i, num in enumerate(nums):
            if i > 0 and num == nums[i - 1]:
                continue
            f = i + 1
            e = len(nums) - 1
            while f < e:
                if num + nums[f] + nums[e] < 0:
                    f += 1
                elif num + nums[f] + nums[e] > 0:
                    e -= 1
                else:
                    returner.append([num, nums[f], nums[e]])
                    f += 1
                    while nums[f] == nums[f - 1] and f < e:
                        f += 1
        return returner


"""
code to beat 90%

        n = len(nums)
        result = []
        nums.sort()

        for i in range(n - 2):
            if nums[i] + nums[i+1] + nums[i+2] > 0:
                break
            if nums[i] + nums[n-2] + nums[n-1] < 0:
                continue
            if i > 0 and nums[i] == nums[i-1]:
                continue
            l = i + 1
            r = n - 1
            while l < r:
                tmp = nums[i] + nums[l] + nums[r]
                if tmp == 0:
                    result.append([nums[i], nums[l], nums[r]]) 
                    while l+1 < r and nums[l] == nums[l+1]:
                        l += 1
                    l += 1
                    while l < r-1 and nums[r] == nums[r-1]:
                        r -= 1
                    r -= 1
                elif tmp < 0:
                    l += 1
                else:
                    r -= 1
        return result

"""


"""
class Solution(object):
    def recursion(self, f, m, e, nums):
        returner = []
        while e - f > 1:
            if nums[f] + nums[m] + nums[e] == 0:
                returner.append([nums[f], nums[m], nums[e]])
                for elem in self.recursion(f + 1, f + 2, e, nums):
                    if elem not in returner:
                        returner.append(elem)
                for elem in self.recursion(f, f + 1, e - 1, nums):
                    if elem not in returner:
                        returner.append(elem)
                break
            elif nums[f] + nums[m] + nums[e] > 0:
                e -= 1
                m = f + 1
            else:
                if m + 1 == e:
                    f += 1
                    m = f + 1
                else:
                    m += 1

        return returner

    def threeSum(self, nums):
        :type nums: List[int]
        :rtype: List[List[int]]
        nums.sort()
        f = 0
        m = 1
        e = len(nums) - 1
        returner = []
        returner.extend(self.recursion(f, m, e, nums))
        return returner

"""
