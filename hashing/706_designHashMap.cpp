#include <utility>
#include <vector>

using namespace std;

/**
 * @brief   Design a HashMap without using any built-in hash table libraries.
 * 
 * @result  Not a proper one. I didn't use hashing, just a vector of pairs.
 */
class MyHashMap {
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        auto    to_put = getIter(key);
        
        if (to_put != hashSet.end()) {
            (*to_put).second = value;
        } else {
            std::pair myPair = std::make_pair(key, value);

            hashSet.push_back(myPair);
        }
    }
    
    int get(int key) {
        auto    to_get = getIter(key);
        
        if (to_get != hashSet.end()) {
            return ((*to_get).second);
        }
        return (-1);
    }
    
    void remove(int key) {
        auto    to_remove = getIter(key);

        if (to_remove != hashSet.end()) {
            hashSet.erase(to_remove);
        }
    }

    vector<std::pair<int, int>>::iterator getIter(int key) {
        for (auto iter = hashSet.begin(); iter < hashSet.end(); iter++) {
            if ((*iter).first == key)
                return (iter);
        }
        return (hashSet.end());
    }

private:
    vector<std::pair<int, int>> hashSet;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */