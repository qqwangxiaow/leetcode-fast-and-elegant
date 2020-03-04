//stringstream  << input  >> output
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss;
        string str;
        ss<<s;
        stack<string>stk;
        while(ss>>str)
        {
            stk.push(str);
        }
        string ret;
        while(!stk.empty())
        {
            ret+=stk.top();
            ret+=' ';
            stk.pop();
        }
        ret.pop_back();
        return ret;
    }
};