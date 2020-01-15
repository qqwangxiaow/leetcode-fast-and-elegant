//维护一个递增stack
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n=heights.size();
        int ret=0,l,h;
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            while(!s.empty()&&heights[s.top()]>=heights[i])
            {
                h=heights[s.top()];
                s.pop();
                l=s.empty()?-1:s.top();
                ret=max(ret,h*(i-l-1));
                
            }
            s.push(i);
        }
        return ret;
        
    }
};