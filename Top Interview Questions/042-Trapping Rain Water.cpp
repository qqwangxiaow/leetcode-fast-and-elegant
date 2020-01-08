//min(maxleft,maxright)-height[i]
//可以简化为双指针 一遍pass 见最后
class Solution {
public:
    int trap(vector<int>& height) {
        int ret=0;
        vector<int>fromleft(height.size(),0);
        vector<int>fromright(height.size(),0);
        for(int i=0;i<height.size();i++)
        {
            if(!i)
                fromleft[i]=height[i];
            else
                fromleft[i]=max(height[i],fromleft[i-1]);
        }
        for(int i=height.size()-1;i>=0;i--)
        {
            if(i==height.size()-1)
                fromright[i]=height[i];
            else
                fromright[i]=max(height[i],fromright[i+1]);
        }
        for(int i=0;i<height.size();i++)
        {
            ret+=min(fromleft[i],fromright[i]);
            ret-=height[i];
        }
        return ret;
        
    }
};

//一个坑一个坑的bound 小的就push 大的就计算bound
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>s;
        int ret=0,cur=0;
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
//双指针优化
class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,r=height.size()-1;
        int ret=0;
        int maxleft=0,maxright=0;
        while(l<r)
        {
            if(height[l]<height[r])
            {
                height[l]>maxleft?maxleft=height[l]:ret+=maxleft-height[l];
                ++l;
            }
            else
            {
                height[r]>maxright?maxright=height[r]:ret+=maxright-height[r];
                --r;
            }  
        }
        return ret;
    }
};