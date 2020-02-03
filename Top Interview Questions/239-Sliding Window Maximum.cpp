//用deque 双端队列更合适 将序号push进来 而且只用push更大的数的序号
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
            if(i-buffer.front()>=k-1)
                buffer.pop_front();          
        }
        return ret;
    }
};
//using multiset
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int last=k-1;
        multiset<int>myset;
        vector<int>ret;
        for(int i=0;i<k;i++)
        {
            myset.insert(nums[i]);
        }
        while(last<nums.size())
        {
            ret.push_back(*myset.rbegin());
            last++;
            if(last<nums.size())
            {
                myset.erase(myset.find(nums[last-k]));
                myset.insert(nums[last]);
            }
            
        }
        return ret;
    }
};