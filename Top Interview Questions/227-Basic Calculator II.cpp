//很不错的代码 如果是加减 直接push进+ 或者-
//刚开始op=‘+’
class Solution {
public:
    int calculate(string s) {
        stack<int>stk;
        int n=s.size(),num=0,ret=0;
        char op='+';
        for(int i=0;i<n;i++)
        {
            if(s[i]>='0')
                num=num*10+(s[i]-'0');
            if((s[i]<'0'&&s[i]!=' ')||i==n-1)
            {
                if(op=='+') stk.push(num);
                if(op=='-') stk.push(-num);
                if(op=='*'||op=='/')
                {
                    int temp=(op=='*')?stk.top()*num:stk.top()/num;
                    stk.pop();
                    stk.push(temp);
                }
                op=s[i];
                num=0;
            }
        }
        while(!stk.empty())
        {
            ret+=stk.top();
            stk.pop();
        }
        return ret;
        
        
    }
};