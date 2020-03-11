//1.ret.push_back(num[buffer.front()]) not buffer.back()
//2.i-buffer.front()>=k-1 should pop_front()
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>buffer;
        vector<int>ret;
        for(int i=0;i<nums.size();i++)
        {
            while(!buffer.empty()&&nums[buffer.back()]<nums[i])
            {
                buffer.pop_back();
            }
            buffer.push_back(i);
            if(i>=k-1)
            {
                ret.push_back(nums[buffer.front()]);
            }
            if(i-buffer.front()>=k-1)
                buffer.pop_front();
        }
        return ret;
    }
};