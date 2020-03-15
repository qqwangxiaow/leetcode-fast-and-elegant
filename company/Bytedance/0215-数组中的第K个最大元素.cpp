class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>mypq;
        for(auto num:nums)
        {
            mypq.push(num);
            if(mypq.size()>k)
            {
                mypq.pop();
            }
        }
        return mypq.top();
    }
};