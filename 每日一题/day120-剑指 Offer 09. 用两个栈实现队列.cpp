class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        s1.push(value);

    }
    
    int deleteHead() {
        int ret=-1;
        if(s2.empty()&&s1.empty())
            return ret;
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            
        }
        ret=s2.top();
        s2.pop();
        return ret;
    }
    stack<int>s1;
    stack<int>s2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */