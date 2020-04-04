class Solution {
public:
    int trap(vector<int>& height) {
        int ret=0,cur=0;
        stack<int>s;
        while(cur<height.size())
        {
            while(!s.empty()&&height[cur]>height[s.top()])
            {
                int top=s.top();
                s.pop();
                if(s.empty())
                    break;
                int dis=cur-s.top()-1;
                int bounded_height=min(height[cur],height[s.top()])-height[top];
                ret+=dis*bounded_height;
            }
            s.push(cur++);
        }
        return ret;
    }
};