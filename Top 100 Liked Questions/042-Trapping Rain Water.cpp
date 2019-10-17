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
//dp计算leftmax跟rightmax leftmax指对i来说左边最大的height ，积水就是min（leftmax,rightmax）-height
class Solution {
public:
    int trap(vector<int>& height) {
        int r=height.size();
        if(height.empty())
            return 0;
        int ret=0;
        vector<int>leftmax(r,0);
        vector<int>rightmax(r,0);
        leftmax[0]=height[0];
        for(int i=1;i<r;i++)
        {
            leftmax[i]=max(height[i],leftmax[i-1]);
        }
        rightmax[r-1]=height[r-1];
        for(int i=r-2;i>=0;i--)
        {
            rightmax[i]=max(rightmax[i+1],height[i]);
        }
        for(int i=0;i<r;i++)
        {
            ret+=min(leftmax[i],rightmax[i])-height[i];
        }
        return ret;
    }
};