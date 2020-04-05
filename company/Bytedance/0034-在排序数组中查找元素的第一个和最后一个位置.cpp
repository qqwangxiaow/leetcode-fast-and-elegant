//pay attention to end and !=target
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto f=lower_bound(nums.begin(),nums.end(),target);
        if(f==nums.end()||*f!=target)
            return {-1,-1};
        auto ff=upper_bound(nums.begin(),nums.end(),target);
        return {static_cast<int>(f-nums.begin()),static_cast<int>(ff-nums.begin()-1)};
    }
};