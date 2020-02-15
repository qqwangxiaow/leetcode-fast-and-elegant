//all push to s2 if needed
class CQueue {
public:
    CQueue() {   
    }
    void appendTail(int value) {
        s1.push(value);
    }
    int deleteHead() {
        int ret=-1;
        if(!s2.empty())
        {
            ret=s2.top();
            s2.pop();
        }
        else if(!s1.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            ret=s2.top();
            s2.pop();
        }
        return ret;        
    }
private:
    stack<int>s1;
    stack<int>s2;
};
