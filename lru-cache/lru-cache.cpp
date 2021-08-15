class LRUCache {
public:
    LRUCache(int capacity) :capacity(capacity){
        count = 0;
    }
    
    int get(int key) {
        if(!hash.count(key)) return -1;
        //marked as most recently used
        cache.erase(hash_list[key]);
        cache.push_back(key);
        hash_list[key] = prev(cache.end());
        //return query result
        return hash[key];
    }
    
    void put(int key, int value) {
        if(hash.count(key)) {
            //marked as most recently used
            cache.erase(hash_list[key]);
            cache.push_back(key);
            hash_list[key] = prev(cache.end());
            //update value
            hash[key]=value;
            return;
        }
        if(count==capacity) {
            int rm = cache.front();
            cache.pop_front();
            hash.erase(rm);
            hash_list.erase(rm);
            count--;
        }
        count++;
        cache.push_back(key);
        hash[key] = value;
        hash_list[key] = prev(cache.end());
    }
private:
    int count;
    int capacity;
    list<int> cache;
    unordered_map<int,int> hash;
    unordered_map<int,list<int>::iterator> hash_list;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */