#include <vector>
#include <iostream>

using namespace std;

class MinHeap {
public:
    MinHeap() {
        _array.push_back(0);
    }

    void push(int val) {
        _array.push_back(val);

        int i = _array.size() - 1;

        while (i > 1 && _array[i] < _array[i / 2]) {
            swap(_array[i], _array[i / 2]);
            i = i / 2;
        }
    }

    int pop() {
        if (_array.size() <= 1)
            return (-1);
        if (_array.size() == 2) {
            int val = _array[1];

            _array.pop_back();
            return (val);
        }

        int returner = _array[1];

        _array[1] = _array[_array.size() - 1];
        _array.pop_back();

        bubbleDown(1);
        return (returner);
    }

    int top() {
        if (_array.size() == 1)
            return (-1);
        
        return (_array[1]);
    }

    void heapify(const vector<int>& arr) {
        _array.clear();
        _array.push_back(0);

        _array.insert(_array.end(), arr.begin(), arr.end());
        for (int i = (_array.size() - 1) / 2; i >= 1; i--) {
            bubbleDown(i);
        }
    }

private:
    vector<int> _array;

    void bubbleDown(int i_pop) {
        int i_child;

        // bubble down till no child is smaller
        i_child = 2 * i_pop;
        while (i_child < _array.size()) {
            // Identify the smallest child
            if (i_child + 1 < _array.size() && _array[i_child] > _array[i_child + 1])
                i_child++;

            // stopping condition
            if (_array[i_pop] < _array[i_child])
                break;
            
            // Swap them
            swap(_array[i_pop], _array[i_child]);

            // Modify the pointers
            i_pop = i_child;
            i_child = i_pop * 2;
        }
    }
};











