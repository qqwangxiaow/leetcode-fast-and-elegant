//关键是lambda 时候 s1+s2>s2+s1 这排序算法很好
//如果0很多要考虑去除
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>myvec;
        string ret;
        for(auto num:nums)
        {
            myvec.push_back(to_string(num));
        }
        sort(myvec.begin(),myvec.end(),[](string &s1,string &s2){return s1+s2>s2+s1;});
        for(auto each:myvec)
        {
            ret+=each;
        }
        if(ret[0]=='0')
            return "0";
        return ret;
    }
};