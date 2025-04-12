class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        # Calculate accurance of each number
        container = {}
        for num in nums:
            if num not in container:
                container[num] = 1
            else:
                container[num] += 1
        # The problem is that it doesn't sorted
        # So we have to somehow sort it

        # This was my initial code. It beats 10% on time and 90% on memory
        """returner = {}
        ret_sort = [-10001] * k
        for key, value in container.items():
            if len(returner) < k:
                returner[key] = value
            else:
                for key_com, val_com in returner.items():
                    if val_com < value:
                        del returner[key_com]
                        returner[key] = value
                        key = key_com
                        value = val_com
                
                for key_com, val_com in returner.items():
                    if 
        return returner"""

        # I am gong to use Bucket list sorting
        # index shows frequences. For instance on count[0] we will store all numbers that have 0 frequence 
        # and value itself is numbers which have this frequency
        count = [[10000]] * (len(nums) + 1)
        for value in container:
            if count[container[value]] == [10000]:
                count[container[value]] = [value]
            else:
                count[container[value]].append(value)

        # then as said in bucketsort just take first elements from the end
        returner = []
        for i in range(len(count) - 1, -1, -1):
            if len(returner) == k:
                break
            else:
                if count[i] != [10000]:
                    returner += count[i]
        return returner
