class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ret=0;
        if(matrix.empty())
            return 0;
        vector<int>myvec(matrix[0].size()+1,0);
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]=='1')
                    myvec[j]++;
                else
                    myvec[j]=0;
            }
            ret=max(ret,maxwater(myvec));
        }
        return ret;
    }
    int maxwater(vector<int>&height){
        stack<int>s;
        int ret=0;
        for(int i=0;i<height.size();i++){
            while(!s.empty()&&height[s.top()]>height[i]){
                int temp=height[s.top()];
                s.pop();
                int left=s.empty()?-1:s.top();
                ret=max(ret,(i-left-1)*temp);
            }
            s.push(i);
        }
        return ret;
    }
};