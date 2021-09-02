class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        size_t size = nums1.size();
        size_t head = 0;
        vector<int> res(size);
        typedef pair<size_t,int> ntwo;
        auto comp = [](ntwo a,ntwo b){return a.second<b.second;};
        typedef priority_queue<ntwo,vector<ntwo>,decltype(comp)> PQ;
        PQ pq(comp);
        for(size_t i=0;i<size;i++) pq.push(make_pair(i,nums2[i]));
        sort(nums1.begin(),nums1.end());
        while(!pq.empty()){
            ntwo element = pq.top();
            pq.pop();
            if(element.second<nums1[size-1]) res[element.first] = nums1[--size];
            else res[element.first] = nums1[head++];
        }
        return res;
    }
};