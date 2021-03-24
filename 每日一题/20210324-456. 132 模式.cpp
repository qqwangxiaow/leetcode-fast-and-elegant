//维护一个栈，栈里面的数一定大于k，k也要尽可能大。
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int>stk;
        int k = INT_MIN;
        for(int i = nums.size() - 1; i >= 0; --i){
            if(nums[i] < k)
                return true;
            while(!stk.empty() && stk.top() < nums[i]){
                k = max(stk.top(), k);
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};