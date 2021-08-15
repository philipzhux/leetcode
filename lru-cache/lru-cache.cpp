class LRUCache {
public:
    LRUCache(int capacity) :capacity(capacity){
        count = 0;
    }
    
    int get(int key) {
        if(!hash_list.count(key)) return -1;
        //marked as most recently used
        int value = hash_list[key]->second;
        cache.erase(hash_list[key]);
        cache.push_back(make_pair(key,value));
        hash_list[key] = prev(cache.end());
        //return query result
        return value;
    }
    
    void put(int key, int value) {
        if(hash_list.count(key)) {
            //marked as most recently used and update value
            cache.erase(hash_list[key]);
            cache.push_back(make_pair(key,value));
            hash_list[key] = prev(cache.end());
            return;
        }
        if(count==capacity) {
            hash_list.erase(cache.front().first);
            cache.pop_front();
            count--;
        }
        count++;
        cache.push_back(make_pair(key,value));
        hash_list[key] = prev(cache.end());
    }
private:
    int count;
    int capacity;
    list<pair<int,int>> cache;
    //unordered_map<int,int> hash;
    unordered_map<int, list<pair<int,int>>::iterator> hash_list;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */