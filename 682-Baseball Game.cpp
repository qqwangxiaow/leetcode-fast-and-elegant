//stack
class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>s;
        for(auto op:ops)
        {
            if(op=="+")
            {
                int top=s.pop();
                int newtop=top+s.top();
                s.push(top);
                s.push(newtop);
            }
            else if(op=="C")
            {
                s.pop();
            }
            else if(op=="D")
            {
                s.push(2*stack.top());
            }
            else 
            {
                s.push(stactic_cast<int>(op));
            }
        }
        int ret=0;
        for(int score:stack)
        {
            ret+=score;
        }
        return ret;
    }
};