//set
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>myset;
        for(auto each:nums1)
        {
            myset.insert(each);
        }
        set<int>ret;
        for(auto each:nums2)
        {
            if(myset.find(each)!=myset.end())
            {
                ret.insert(each);
            }
        }
        vector<int>res;
        for(auto each:ret)
        {
            res.push_back(each);
        }
        return res;
        
    }
};