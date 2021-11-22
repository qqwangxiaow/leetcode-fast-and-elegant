//Fisher-Yates shuffle algorithm
class Solution {
public:
    Solution(vector<int>& nums) {
        init = nums;
        cur = nums;
    }
    
    vector<int> reset() {
        cur = init;
        return cur;
    }
    
    vector<int> shuffle() {
        int len = cur.size();
        for (int i = 0; i < len; ++i) {
            int temp = rand() % (len -i) + i;
            swap(cur[i], cur[temp]);
        }
        return cur;
    }
private:
    vector<int> init;
    vector<int> cur;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */