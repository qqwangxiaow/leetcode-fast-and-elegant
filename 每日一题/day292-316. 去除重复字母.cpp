//单调栈 记录是否访问过 时候后面还有
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>count(26, 0),visited(26, 0);
        for(auto ch : s){
            count[ch - 'a']++;
        }
        stack<char>stk;
        for(auto ch : s)
        {
            if(!visited[ch - 'a']){
                while(!stk.empty() && stk.top() > ch && count[stk.top() - 'a']){
                    visited[stk.top() - 'a'] = 0;
                    stk.pop();
                }
                stk.push(ch);
                visited[ch - 'a'] = 1;
            }
            count[ch - 'a']--;
        }
        string ret="";
        while(!stk.empty()){
            ret.push_back(stk.top());
            stk.pop();
        }
        reverse(ret.begin(),ret.end());
        return ret;
        
    }
};