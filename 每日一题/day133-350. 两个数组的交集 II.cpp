class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mymap;
        for(auto num:nums1)
        {
            mymap[num]++;
        }
        vector<int>ret;
        for(int i=0;i<nums2.size();i++)
        {
            if(mymap[nums2[i]]>0)
            {
                ret.push_back(nums2[i]);
                mymap[nums2[i]]--;
            }
        }
        return ret;
    }
};