//Fisher-Yates shuffle algorithm
//swap nums[i] with random nums[i~len]
//because the sum of shuffle is N!
class Solution {
public:
    Solution(vector<int>& nums) {
        init=nums;
        cur=nums;
    }
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        cur=init;
        return cur;   
    }
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int len=cur.size();
        for(int i=0;i<len;i++)
        {
            int temp=rand()%(len-i)+i;
            swap(cur[i],cur[temp]);
        }
        return cur;  
    }
private:
    vector<int>init;
    vector<int>cur;
};
