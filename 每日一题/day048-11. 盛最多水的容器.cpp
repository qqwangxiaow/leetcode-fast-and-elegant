//two pointers
class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size()<2)
            return 0;
        int l=0,r=height.size()-1;
        int ret=0;
        while(l<r)
        {
            ret=max(ret,min(height[l],height[r])*(r-l));
            if(height[l]<height[r])
                l++;
            else
                r--;

        }
        return ret;
        
    }
};