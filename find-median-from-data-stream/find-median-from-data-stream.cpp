class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(larger.empty()) smaller.push(num);
        else if(num>=larger.top()) larger.push(num);
        else smaller.push(num);
        if(smaller.size()-larger.size()==2) {
            int t = smaller.top();
            smaller.pop();
            larger.push(t);
            return;
        }
        if(larger.size()-smaller.size()==2) {
            int t = larger.top();
            larger.pop();
            smaller.push(t);
            return;
        }       
        
    }
    
    
    double findMedian() {
        if(larger.size() && larger.size()==smaller.size()) return double(larger.top()+smaller.top())/2;
        return ((larger.size()>smaller.size())?larger.top():smaller.top());
    }
private:
    priority_queue<int,vector<int>,greater<int>> larger;
    priority_queue<int,vector<int>,less<int>> smaller;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */