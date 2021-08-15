class LFUCache {
public:
    LFUCache(int capacity): capacity(capacity){
        count=0;
        frequency_set[1]={};
        min_freq=1;
    }
    
    int get(int key) {
        if(!capacity) return -1;
        if(!locate.count(key)) return -1;
        int value = locate[key]->second;
        int freq = (get_freq[key]++);
        frequency_set[freq].erase(locate[key]);
        if(freq==min_freq && frequency_set[freq].empty()) min_freq++;
        freq++;
        if(!frequency_set.count(freq)) frequency_set[freq]={};
        frequency_set[freq].push_back(make_pair(key,value));
        locate[key] = prev(frequency_set[freq].end());
        return value;
    }
    
    void put(int key, int value) {
        if(!capacity) return;
        if(locate.count(key)) {
            int freq = (get_freq[key]++);
            frequency_set[freq].erase(locate[key]);
            if(freq==min_freq && frequency_set[freq].empty()) min_freq++;
            freq++;
            if(!frequency_set.count(freq)) frequency_set[freq]={};
            frequency_set[freq].push_back(make_pair(key,value));
            locate[key] = prev(frequency_set[freq].end());
            return;
        }
        if(capacity==count){
            int rm = frequency_set[min_freq].front().first;
            locate.erase(rm); get_freq.erase(rm);
            frequency_set[min_freq].pop_front();
            if(frequency_set[min_freq].empty()) min_freq=max(1,min_freq-1);
            count--;
        }
        count++;
        frequency_set[1].push_back(make_pair(key,value));
        locate[key] = prev(frequency_set[1].end());
        get_freq[key] = 1;
        min_freq = 1;
    }
private:
    unordered_map<int,list<pair<int,int>>::iterator> locate;
    unordered_map<int,list<pair<int,int>>> frequency_set;
    unordered_map<int,int> get_freq;
    int count,capacity,min_freq;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
     * int param_1 = obj->get(key);
 * obj->put(key,value);
 */