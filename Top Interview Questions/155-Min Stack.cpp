//注意<= 考虑重复最小值的情况 同时push进入两个元素 一个当前最小值 一个之前最小值
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {  
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
        int x=s.top();
        s.pop();
        if(x==minelement)
        {
            minelement=s.top();
            s.pop();   
        }
    }
    int top() {
        return s.top();   
    }  
    int getMin() {
        return minelement;   
    }
private:
    stack<int>s;
    int minelement=INT_MAX;
};
