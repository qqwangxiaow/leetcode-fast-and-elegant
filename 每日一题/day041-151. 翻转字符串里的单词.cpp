class Solution {
public:
    string reverseWords(string s) {
        string ret;
        stringstream ss(s);
        string temp;
        stack<string>stk;
        while(ss>>temp)
        {
            stk.push(temp);
        }
        while(!stk.empty())
        {
            ret+=stk.top();
            stk.pop();
            if(!stk.empty())
                ret+=" ";
        }
        return ret;
    }
};