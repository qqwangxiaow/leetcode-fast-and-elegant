//increase stack
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>s;
        int ret=0;
        heights.push_back(0);
        for(int i=0;i<heights.size();i++)
        {
            while(!s.empty()&&heights[s.top()]>heights[i])
            {
                int height=heights[s.top()];
                s.pop();
                int l=s.empty()?-1:s.top();
                ret=max(ret,height*(i-l-1));         

            }
            s.push(i);
        }
        return ret;

    }
};