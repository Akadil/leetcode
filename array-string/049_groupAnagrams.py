# In this problem was shown 3 solutions,
# solution 2 is the best in terms of time

class Solution(object):
    """def compareWord(self, str1, str2):

        # If they have  different sizes, immediately return 0
        if len(str1) != len(str2):
            return 0
        
        # traverse through each char of str1 and remove it from str2
        for char in str1:
            if char not in str2:
                return 0
            str2 = str2.replace(char, '', 1)

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
            if self.compareWord(container[i][0], word) != 0:
                return i
        return -1

    def groupAnagram3(self, strs):
        :type strs: List[str]
        :rtype: List[List[str]]
        returner = []
        
        # Go through each number
        for s in strs:
            ind = self.isExist(returner, s)
            
            # if it doesn't exist, then add
            if ind == -1:
                returner.append([s])
            # If exist, append to existed one
            else:
                returner[ind].append(s)
        return returner
    """

    def groupAnagrams2(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """

        # Change each string in strs with its sorted version
        srt=[''.join(sorted(i)) for i in strs]
        
        # Create a dictionary with key as sorted version and value as strings 
        cnt={} 
        for i, e in enumerate(srt):
            if e in cnt:
                cnt[e].append(strs[i])
            else:
                cnt[e]=[strs[i]]

        return list(cnt.values()) 

    def groupAnams(self, strs):

        # I am going to save strings as a values with keys represented
        # by how many chars does it have
        # ---------
        # key: [1: 'c', 1: 'a', 2: 't']
        # value: catt
        res = defaultdict(list)


        for s in strs:
            # Create a list of size 26 to count number of appearances of each letter
            count = [0] * 26
            for c in s:
                count[ord(c) - ord("a")] += 1
            res[tuple(count)].append(s)
        return res.values()
