// Excellent approach and beautiful code: 
    // https://leetcode.com/problems/lru-cache/discuss/45911/Java-Hashtable-+-Double-linked-list-(with-a-touch-of-pseudo-nodes)/233161


// My approach : not efficient, ques demands O(1) time complexity
class LRUCache {
public:
    unordered_map<int, pair<int, int>> m;
    int capacity, ctr;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        ctr = 1;
    }
    
    int get(int key) {
        if (m.find(key)!=m.end()) {
            m[key].second = ctr++;
            return m[key].first;    
        } 
        else return -1;
    }
    
    void put(int key, int value) {
        if (m.size() == capacity && m.find(key)==m.end()) {
            int least = ctr+1, keytoremove;
            for (auto ele : m) {
                if (ele.second.second < least) {
                    least = ele.second.second;
                    keytoremove = ele.first;
                }
            }
            m.erase(keytoremove);
        }
        
        m[key] = {value, ctr++};
    }
};