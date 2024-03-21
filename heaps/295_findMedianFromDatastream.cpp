#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
public:
    MedianFinder() {
        // cout << "Quoi de neuf?!" << endl;
    }
    
    void addNum(int num) {
        // lower.push(num);
        if (lower.size() == higher.size()) {
            if (higher.empty() == false && num > higher.top())
                higher.push(num);
            else // num < lower.top() || (higher.top() > num > lower.top()) 
                lower.push(num);
        }
        else if (lower.size() > higher.size()) {
            if (lower.top() < num)
                higher.push(num);
            else {
                higher.push(lower.top());
                lower.pop();
                lower.push(num);
            }
        }
        else {  // lower.size() < higher.size()
            if (higher.top() > num)
                lower.push(num);
            else {
                lower.push(higher.top());
                higher.pop();
                higher.push(num);
            }
        }
    }
    
    double findMedian() {
        if (lower.size() > higher.size())
            return (lower.top());
        else if (lower.size() < higher.size())
            return (higher.top());
        else
            return ((double)(higher.top() + lower.top()) / 2);
    }

private:
    priority_queue<int>                             lower;  // maxHeap
    priority_queue<int, vector<int>, greater<int>>  higher; // minHeap
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main(void) {
    // Recreate the case:
    /*
        ["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
        [[],[1],[2],[],[3],[]]
    */
    /*
            ["MedianFinder","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian"]
            [[],[1],[],[2],[],[3],[],[4],[],[5],[],[6],[],[7],[],[8],[],[9],[],[10],[]]
    */




    MedianFinder* obj = new MedianFinder();
    // obj->addNum(1);
    // obj->addNum(2);
    // cout << obj->findMedian() << endl;
    // obj->addNum(3);
    // cout << obj->findMedian() << endl;

    obj->addNum(1);
    cout << obj->findMedian() << endl;
    obj->addNum(2);
    cout << obj->findMedian() << endl;
    obj->addNum(3);
    cout << obj->findMedian() << endl;
    obj->addNum(4);
    cout << obj->findMedian() << endl;
    obj->addNum(5);
    cout << obj->findMedian() << endl;
    obj->addNum(6);
    cout << obj->findMedian() << endl;
    obj->addNum(7);
    cout << obj->findMedian() << endl;
    obj->addNum(8);
    cout << obj->findMedian() << endl;
    obj->addNum(9);
    cout << obj->findMedian() << endl;
    obj->addNum(10);
    cout << obj->findMedian() << endl;



}