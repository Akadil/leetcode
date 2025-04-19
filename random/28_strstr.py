def strStr(haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """

        len_needle = len(needle)
        i_needle = 0
        i_haystack = 0

        # traverse through the haystack
        while i_haystack < len(haystack):

            if (haystack[i_haystack] == needle[i_needle]):
                i_needle += 1
            else:
                i_needle = 0
                if (haystack[i_haystack] == needle[i_needle]):
                    i_needle += 1

            
            if (i_needle == len_needle):
                return i_haystack + 1 - len_needle
            i_haystack += 1
        
        return -1

    
def strStr2(haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """

        len_haystack = len(haystack)
        len_needle = len(needle)
        # i_needle = 0
        i_haystack = 0

        # traverse through the haystack
        while i_haystack < len_haystack - len_needle:
            if (haystack[i_haystack : i_haystack + len_needle] == needle):
                return i_haystack
            i_haystack += 1
        
        return -1


def main():
    haystack = "mississippi"
    needle = "issip"

    result = strStr2(haystack, needle)

    print(f"The result is {result}\n{haystack}\n{needle}")


if __name__ == "__main__":
    main()