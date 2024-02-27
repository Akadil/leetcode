#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MyHashSet {
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        if (contains(key) == false)
            hashSet.push_back(key);
    }
    
    void remove(int key) {
        vector<int>::iterator k = find(hashSet.begin(), hashSet.end(), key);
        if (k != hashSet.end()) {
            hashSet.erase(k);
        }
    }
    
    bool contains(int key) {
        return (find(hashSet.begin(), hashSet.end(), key) != hashSet.end());
    }

private:
    vector<int> hashSet;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */