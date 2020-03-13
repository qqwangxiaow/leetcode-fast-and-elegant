class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>maxfromleft(n,0);
        vector<int>maxfromright(n,0);
        for(int i=0;i<n;i++)
        {
            if(i==0)
                maxfromleft[i]=height[i];
            else
            {
                maxfromleft[i]=height[i]>maxfromleft[i-1]?height[i]:maxfromleft[i-1];
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
                maxfromright[i]=height[i];
            else
            {
                maxfromright[i]=height[i]>maxfromright[i+1]?height[i]:maxfromright[i+1];
            }
        }
        int ret=0;
        for(int i=0;i<height.size();i++)
        {
            ret+=min(maxfromleft[i],maxfromright[i]);
            if(height[i])
                ret-=height[i];
        }
        return ret;
        
    }
};
//