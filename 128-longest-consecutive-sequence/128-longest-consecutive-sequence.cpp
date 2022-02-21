class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        int max = 0;
        int left, right;
        for(const auto & k: nums)
            set.insert(k);
        for(auto k: nums) {
            left = k;
            right = k;
            while(set.count(++right)) set.erase(right);
            while(set.count(--left)) set.erase(left);
            set.erase(k);
            max = std::max(right-left-1,max);
        }
        return max;
    }
};