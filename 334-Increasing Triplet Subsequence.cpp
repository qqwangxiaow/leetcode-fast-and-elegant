//the key is to maintain a subsequence 
//遇到比子序列最后一位大的元素，则可以将其加入子序列中
//若比子序列最后一位要小，则需要更新该子序列，使得子序列“尽量小”，例如子序列为[1,4]时，此时遇到元素2，那么需要将子序列更新为[1,2]，因为在子序列“尽量小”的情况下才更容易遇到递增元素；另一个例子是[4, 5], 遇到元素1,此时需要更新为[1,5]，可以发现这时候子序列并不严格对应最终的递增子序列，但是在只需要长度的情况下可以不用考虑子序列的元素情况。
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int small1=INT_MAX,small2=INT_MAX;
        for(auto num:nums)
        {
            if(small1>=num)
            {
                small1=num;
            }
            else if(small2>=num)
            {
                small2=num;
            }
            else
                return true;  
        }
        return false;
    }
};