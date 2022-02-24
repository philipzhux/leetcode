class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        auto it = digits.rbegin();
        int carry = (*it+1)/10;
        *it = (*it+1)%10;
        it++;
        int temp;
        while(it!=digits.rend() && carry) {
            temp = *it;
            *it = (temp+carry)%10;
            carry = (temp+carry)/10;
            it++;
        }
        if(carry) digits.insert(digits.begin(),carry);
        return digits;
    }
};