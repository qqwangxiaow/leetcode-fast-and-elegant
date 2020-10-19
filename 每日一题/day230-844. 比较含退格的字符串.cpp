//双指针is better
//从尾部一个个比较 不需要空间
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        vector<int>v1=change(S);
        vector<int>v2=change(T);
        return v1==v2;
    }
    vector<int>change(string S)
    {
        vector<int>myvec;
        for(auto ch:S)
        {
            if(ch=='#')
            {
                if(!myvec.empty())
                    myvec.pop_back();
            }
            else
                myvec.push_back(ch);
        }
        return myvec;
    }
};