//height[l]<=height[r] 从小到大 一格一格的累计 two pointer
class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,r=height.size()-1;
        int maxleft=0,maxright=0;
        int ret=0;
        while(l<=r)
        {
            if(height[l]<=height[r])
            {
                if(maxleft<height[l])
                {
                    maxleft=height[l];
                }
                else
                {
                    ret+=maxleft-height[l];
                }
                l++;
            }
            else
            {
                if(maxright<height[r])
                {
                    maxright=height[r];
                    
                }
                else
                {
                    ret+=maxright-height[r];
                }
                r--;
            }
            
        }
        return ret;
    }
};