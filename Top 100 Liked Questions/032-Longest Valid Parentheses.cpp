//using stack and clean valid in stack then count
class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length(),maxlen=0;
        stack<int>stk;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                stk.push(i);
            }
            else 
            {
                if(!stk.empty())
                {
                    if(s[stk.top()]=='(')
                    {
                        stk.pop();
                    }
                    else
                    {
                        stk.push(i);
                    }
                }
                else
                {
                    stk.push(i);
                }
            }
        }
        if(stk.empty())
        {
            maxlen=n;
        }
        else
        {
            int a=n,b=0;
            while(!stk.empty())
            {
                b=stk.top();stk.pop();
                maxlen=max(maxlen,a-b-1);
                a=b;
            }
            maxlen=max(maxlen,a);
              
        }
        return maxlen;
    }
};
//clean version ,on the fly
class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length(),maxlen=0;
        stack<int>stk;
        stk.push(-1);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                stk.push(i);
            }
            else 
            {
                stk.pop();
                if(stk.empty())
                {
                    stk.push(i);
                }
                else
                {
                    maxlen=max(maxlen,i-stk.top());
                }
            
            }
        }
        return maxlen;
      
    }
};