//dp 一行一行计算 计算最左 计算最右然后面积
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        int m=matrix.size(),n=matrix[0].size(),maxarea=0;
        vector<int>left(n,0);
        vector<int>right(n,n);
        vector<int>height(n,0);
        for(int i=0;i<m;i++)
        {
            int cur_left=0,cur_right=n;
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='1')
                {
                    height[j]++;
                }
                else
                    height[j]=0;
            }
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='1')
                {
                    left[j]=max(left[j],cur_left);
                }
                else
                {
                    left[j]=0;
                    cur_left=j+1;
                }
            }
            for(int j=n-1;j>=0;j--)
            {
                if(matrix[i][j]=='1')
                {
                    right[j]=min(right[j],cur_right);
                }
                else
                {
                    right[j]=n;
                    cur_right=j;
                }
                
            }
            for(int j=0;j<n;j++)
            {
                maxarea=max(maxarea,height[j]*(right[j]-left[j]));
            }  
        }
        return maxarea;
    }
    
};

//using stack,like largest rectangle in histograms
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        int m=matrix.size(),n=matrix[0].size()+1;
        int ret=0,h=0,w=0;
        vector<int>height(n,0);
        for(int i=0;i<m;i++)
        {
            stack<int>s;
            for(int j=0;j<n;j++)
            {
                if(j<n-1)
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
                while(!s.empty()&&height[s.top()]>=height[j])
                {
                    h=height[s.top()],s.pop();
                    w=s.empty()?j:j-s.top()-1;
                    ret=max(ret,w*h);
                    
                }
                s.push(j);
            }
        
        }
        return ret;
    }
    
};