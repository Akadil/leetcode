class MedianFinder(object):

    def __init__(self):
        self.myList = []

    def addNum(self, num):
        """
        :type num: int
        :rtype: None
        """

        # identify the index to insert using bs
        l_index = 0
        r_index = len(self.myList)

        while (l_index < r_index):
            index = (l_index + r_index) / 2
            
            if num < self.myList[index]:
                r_index = index
            elif num > self.myList[index]:
                l_index = index + 1
            else:
                l_index = index + 1
                break
            
        # insert the element 

        self.myList.insert(l_index, num)
        

    def findMedian(self):
        """
        :rtype: float
        """
        myLen = len(self.myList)

        if (myLen % 2 == 0):
            return float(self.myList[int(myLen / 2)] + self.myList[int(myLen / 2 - 1)]) / 2
        else:
            return (self.myList[myLen / 2])
            
        


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()