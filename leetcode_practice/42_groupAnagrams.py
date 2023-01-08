class Solution():
    def compareWord(self, str1, str2):

        # If they have  different sizes, immediately return 0
        if len(str1) != len(str2):
            return 0
        
        # traverse through each char of str1 and remove it from str2
        print(f'Beginning:{str1} and {str2}')
        for char in str1:
            if char not in str2:
                return 0
            print(f'char:{char} and str2:{str2}')
            str2 = str2.replace(str(char), '', 1)
            print(f'{str2}')
        print("\n\n")
        

        # If by the end of our operations there is something left in str2
        # then return 0
        if len(str2) != 0:
            return 0
        return 1

    # returns position of similar anogram
    # -1 if doesn't exist
    def isExist(self, container, word):

        # Go through each element and check it
        for i in range(len(container)):
            num = self.compareWord(container[i][0], word)
            # print(f'My ind is {num}')
            if num != 0:
                return i
        return -1

    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        returner = []
        
        # Go through each number
        for s in strs:
            ind = self.isExist(returner, s)
            # print(f'Current word is {s} and index is {ind}')

            # if it doesn't exist, then add
            if ind == -1:
                returner.append([s])
            # If exist, append to existed one
            else:
                returner[ind].append(s)
        return returner

sol = Solution()
print(sol.groupAnagrams(["eat","tea","tan","ate","nat","bat"]))
