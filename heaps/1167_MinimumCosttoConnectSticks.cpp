class Solution {
    public:
        int connectSticks(vector<int>& sticks) {
            // Edge case: if there are no sticks, return -1 (though problem constraints usually guarantee at least one stick)
            if (sticks.size() == 0)
                return -1;
    
            // Step 1: Initialize a min-heap (priority queue) to always get the smallest two sticks
            priority_queue<int, vector<int>, greater<int>> min_heap;
    
            // Step 2: Push all stick lengths into the min-heap
            for (int& stick : sticks) {
                min_heap.push(stick);
            }
    
            // Step 3: Initialize total cost
            int ans = 0;
    
            // Step 4: While there is more than one stick in the heap
            while (min_heap.size() > 1) {
                // Pop the two smallest sticks
                int a = min_heap.top(); min_heap.pop();
                int b = min_heap.top(); min_heap.pop();
    
                // The cost to connect them is their sum
                ans += a + b;
    
                // Push the resulting stick back into the heap
                min_heap.push(a + b);
            }
    
            // Step 5: Return the total cost to connect all sticks
            return ans;
        }
    };
    