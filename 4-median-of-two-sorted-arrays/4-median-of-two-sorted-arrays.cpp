class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()+nums2.size() == 1) return nums1.size()==1?nums1[0]:nums2[0];
        if((nums1.size()+nums2.size()) & 1) return                getKth(nums1.begin(),nums2.begin(),nums1.size(),nums2.size(),(nums1.size()+nums2.size())/2+1);
        double former = getKth(nums1.begin(),nums2.begin(),nums1.size(),nums2.size(),
                         (nums1.size()+nums2.size())/2);
        double latter = getKth(nums1.begin(),nums2.begin(),nums1.size(),nums2.size(),
                         (nums1.size()+nums2.size())/2+1);
        return (former+latter)/2;
    }
   
    
    double getKth(vector<int>::iterator it1, vector<int>::iterator it2, 
                  int len1, int len2, int k) {
        if(len1>len2) return getKth(it2,it1,len2,len1,k);
        if(len1==0) return *(it2+k-1);
        if(len2==0) return *(it1+k-1);
        if(k==1) return min(*it1,*it2);
        int m1 = min(len1,k/2);
        int m2 = k-m1;
        if(*(it1+m1-1)==*(it2+m2-1)) return *(it1+m1-1);
        if(*(it1+m1-1)<*(it2+m2-1)) return getKth(it1+m1,it2,len1-m1,len2,k-m1);
        return getKth(it1,it2+m2,len1,len2-m2,k-m2);
    }
   
};