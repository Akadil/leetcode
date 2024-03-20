#include <queue>
#include <vector>
#include <iostream>

using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        for (unsigned int i = 0; i < nums.size(); ++i) {
            _heap.push(nums[i]);
        }
        while (_heap.size() > k) {
            _heap.pop();
        }
    }
    
    int add(int val) {
        _heap.push(val);
        
        if (_k < _heap.size()) {
            _heap.pop();
        }
        return (_heap.top());
    }

private:
    priority_queue<int, vector<int>, greater<int>> _heap;
    int                 _k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 
 ytre
 
 */