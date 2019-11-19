//using stack,cal maxarea for heigts>= heights[i]
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
                h=heights[s.top()],s.pop();
                l=s.empty()?-1:s.top();
                ret=max(ret,h*(i-l-1));
            }
            s.push(i);
        }
        return ret;
    }
};

//for each i ,maxarea= (>=i)*len)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()==0)
            return 0;
        int n=heights.size();
        vector<int>lessfromleft(n,0);
        vector<int>lessfromright(n,0);
        int ret=0;
        lessfromleft[0]=-1;
        lessfromright[n-1]=n;
        for(int i=1;i<heights.size();i++)
        {
            int p=i-1;
            while(p>=0&&heights[p]>=heights[i])
            {
                p=lessfromleft[p];
            }
            lessfromleft[i]=p;
        }
        for(int i=heights.size()-2;i>=0;i--)
        {
            int p=i+1;
            while(p<heights.size()&&heights[p]>=heights[i])
            {
                p=lessfromright[p];
            }
            lessfromright[i]=p;
        }
        for(int i=0;i<heights.size();i++)
        {
            ret=max(ret,(lessfromright[i]-lessfromleft[i]-1)*heights[i]);
     
        }
        return ret;
        
    }
};