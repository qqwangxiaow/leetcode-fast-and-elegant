//it's better to use one queue
//pop should return element
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        int len=q.size();
        for(int i=0;i<len-1;i++)
        {
            q.push(q.front());
            q.pop();
        }

    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(!q.empty())
        {
            int ret=q.front();
            q.pop();
            return ret;
        }
        return -1;

    }
    
    /** Get the top element. */
    int top() {
        return q.front();

    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();

    }
private:
    queue<int>q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */