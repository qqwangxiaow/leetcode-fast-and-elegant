/*用一个逆序栈 然后map保存结果 */
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        unordered_map<int,int>mymap;
        for(auto each:nums2)
        {
            while(s.size()&&s.top()<each)
            {
                mymap[s.top()]=each;
                s.pop();
            }
            s.push(each);
        }
        vector<int>ret;
        for(auto each : nums1)
        {
            ret.push_back(mymap.count(each)?mymap[each]:-1);
            
        }
        return ret;
    }
};