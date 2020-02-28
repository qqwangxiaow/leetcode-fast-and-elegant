class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string>myvec;
        for(auto num:nums)
        {
            myvec.push_back(to_string(num));
        }
        sort(myvec.begin(),myvec.end(),[](string &s1,string &s2){
            return s1+s2<s2+s1;
        });
        string ret;
        for(auto each:myvec)
        {
            ret+=each;
        }
        return ret;
    }
};