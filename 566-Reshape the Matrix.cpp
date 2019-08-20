/*利用/和%计算坐标*/
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m=nums.size(),n=nums[0].size();
        if(r*c!=m*n)
            return nums;
        vector<vector<int>>ret(r,vector<int>(c,0));
        for(int i=0;i<r*c;i++)
        {
            ret[i/c][i%c]=nums[i/n][i%n];
            
        }
        return ret;
    
    }
};