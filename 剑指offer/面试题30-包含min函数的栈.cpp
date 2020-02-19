//init minvalue=INT_MAX
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack():minvalue(INT_MAX){
    }
    void push(int x) {
        if(x<=minvalue)
        {
            s.push(minvalue);
            minvalue=x;
        }
        s.push(x);
    }
    
    void pop() {
        int tmp=s.top();
        s.pop();
        if(tmp==minvalue)
        {
            minvalue=s.top();
            s.pop();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int min() {
        return minvalue;  
    }
private:
    stack<int>s;
    int minvalue;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */