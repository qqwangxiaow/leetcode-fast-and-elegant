//找到bound 遍历右半部分 不大于最后一个根结点对值就是false
//if(l>=r) not r>=l
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.size()<2)
            return true;
        return helper(postorder,0,postorder.size()-1);
    }
    bool helper(vector<int>&postorder,int l,int r)
    {
        if(l>=r)
            return true;
        int bound=l;
        while(postorder[bound]<postorder[r])
        {
            bound++;
        }
        for(int i=bound;i<r;i++)
        {
            if(postorder[i]<postorder[r])
                return false;
        }
        return helper(postorder,l,bound-1)&&helper(postorder,bound,r-1);
    }
};