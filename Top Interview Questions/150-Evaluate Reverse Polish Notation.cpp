//using stack<int>
//pay attention to x2 then x1
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(auto token:tokens)
        {
            if(token.size()>1||isdigit(token[0]))
                s.push(stoi(token));
            else
            {
                int x2=s.top();s.pop();
                int x1=s.top();s.pop();
                switch(token[0])
                {
                    case '+':x1+=x2;break;
                    case '-':x1-=x2;break;
                    case '*':x1*=x2;break;
                    case '/':x1/=x2;break;
                }        
                s.push(x1);
            }  
        }
        return s.top();
    }
};