#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> heap;
        
        // Add the stones inside of the heap
        for (unsigned int i = 0; i < stones.size(); ++i) {
            heap.push(stones[i]);
        }

        // destroy till one or zero stones left
        while (heap.size() > 1) {
            int stone1;
            int stone2;

            stone1 = heap.top();
            heap.pop();
            stone2 = heap.top();
            heap.pop();

            if (stone1 > stone2) {
                heap.push(stone1 - stone2);
            } else if (stone2 > stone1) {
                heap.push(stone2 - stone1);
            }
        }
        if (heap.size() == 0)
            return (0);
        return (heap.top());
    }

private:
};