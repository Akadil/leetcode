#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int num = 0;
        int currSum = 0;

        // Get the first window
        for (unsigned int i = 0; i < min(k, (int)arr.size()); ++i) {
            currSum += arr[i];
        }
        if ((float)currSum / k >= threshold)
            num++;

        // Traverse through the vector
        for (unsigned int i = min(k, (int)arr.size()); i < arr.size(); ++i) {
            currSum -= arr[i - k];
            currSum += arr[i];

            if ((float)currSum / k >= threshold)
                num++;
        }
        return (num);
    }
};