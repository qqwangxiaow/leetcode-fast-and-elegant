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

//dp
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size()<=1) return 0;
        int curmax=0;
        int n=s.size();
        vector<int>dp(n,0);
        for(int i=1;i<n;i++)
        {
            
            if(s[i]==')')
            {
                if(s[i-1]=='(')
                {
                    dp[i]=(i-2)>=0?(dp[i-2]+2):2;
                    curmax=max(dp[i],curmax);
                }
                else 
                {
                    if(i-dp[i-1]-1>=0&&s[i-dp[i-1]-1]=='(')
                    {
                        dp[i]=dp[i-1]+2+((i-dp[i-1]-2)>=0?dp[i-dp[i-1]-2]:0);
                        curmax=max(dp[i],curmax);
                    }
                    
                }
            }
            
        }
        return curmax;
    }
};
//more concise
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size()<=1) return 0;
        int curmax=0;
        int n=s.size();
        vector<int>dp(n,0);
        for(int i=1;i<n;i++)
        {
            
            if(s[i]==')'&&i-dp[i-1]-1>=0&&s[i-dp[i-1]-1]=='(')
            {
                dp[i]=dp[i-1]+2+((i-dp[i-1]-2)>=0?dp[i-dp[i-1]-2]:0);
                curmax=max(dp[i],curmax);
            }
            
        }
        return curmax;
    }
};