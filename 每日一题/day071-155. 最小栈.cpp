//minelement
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack():minelement(INT_MAX) {

    }
    void push(int x) {
        if(x<=minelement)
        {
            s.push(minelement);
            minelement=x;
        }
        s.push(x);

    }
    void pop() {
        if(s.top()==minelement)
        {
            s.pop();
            minelement=s.top();
            s.pop();
        }
        else
            s.pop();

    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minelement;

    }
private:
    int minelement;
    stack<int>s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */