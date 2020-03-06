//while(l<r)
//l++ when ret.push
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>>ret;
        vector<int>temp;
        int l=1,r=2;
        while(l<r)
        {
            long tmp=(l+r)*(r-l+1)/2;
            if(tmp==target)
            {
                temp.clear();
                for(int i=l;i<=r;i++)
                {
                    temp.emplace_back(i);
                }
                ret.emplace_back(temp);
                l++;
            }
            else if(tmp<target)
                r++;
            else    
                l++;
        }    
        return ret;
    }
};