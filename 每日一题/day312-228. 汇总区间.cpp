//注意溢出
//begin和end是下标，考虑最后一个情况
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
         vector<string>ret;
         int begin = 0, end = 0;
         for(int i = 0; i < nums.size(); ++i){
             if(i == nums.size() - 1 || nums[i+1]  > 1 + nums[i]){
                 end = i;
                 if(end != begin)
                    ret.push_back(to_string(nums[begin]) + "->" + to_string(nums[end]));
                 else
                    ret.push_back(to_string(nums[begin]));
                 begin = end + 1;
             }
         }
         return ret;
    }
};