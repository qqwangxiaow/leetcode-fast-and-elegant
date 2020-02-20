//return l==poped.size()
//start from vector pushed
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>s;
        int l=0;
        for(int i=0;i<pushed.size();i++)
        {
            if(s.empty()||s.top()!=popped[l])
            {
                s.push(pushed[i]);
            }
            while(!s.empty()&&s.top()==popped[l])
            {
                s.pop();
                l++;
            }
        }
        return l==popped.size();
    }
};