//deque
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>buffer;
        vector<int>ret;
        for(int i=0;i<nums.size();i++)
        {
            while(!buffer.empty()&&nums[i]>=nums[buffer.back()])
                buffer.pop_back();
            buffer.push_back(i);
            if(i>=k-1)
                ret.push_back(nums[buffer.front()]);
            if(buffer.front()<=i-k+1)
                buffer.pop_front();
        }
        return ret;
    }
};