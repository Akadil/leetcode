#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int maxSize = 0;
        int currSize = 1;
        int     prevNum = arr[0];
        int    isMore;

        // Identify the direction
        if (arr.size() == 1)
            return (1);
        else if (arr[1] > arr[0])
            isMore = 1;
        else
            isMore = 0;

        // Go through the values
        for (unsigned int i = 1; i < arr.size(); ++i) {
            if (isMore == 1 && arr[i] > arr[i - 1]) {
                isMore = 0;
                currSize++;
            } else if (isMore == 0 && arr[i] < arr[i - 1]) {
                isMore = 1;
                currSize++;
            }
            else {
                if (arr[i] < arr[i - 1]) {
                    isMore = 1;
                    currSize = 2;
                }
                else if (arr[i] > arr[i - 1]) {
                    isMore = 0;
                    currSize = 2;
                }
                else {
                    currSize = 1;
                    isMore = 2;
                }
            }
            maxSize = max(maxSize, currSize);
        }
        return (maxSize);
    }
};