//idea from 84
//largestRectangleArea
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        vector<int>height(matrix[0].size()+1,0);
        int ret=0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]=='1')
                {
                    height[j]++;
                }
                else
                {
                    height[j]=0;
                }
            }
            ret=max(ret,largestRectangleArea(height));
            
        }  
        return ret;     
        
    }
    int largestRectangleArea(vector<int>& heights) {
        stack<int>s;
        int ret=0;
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