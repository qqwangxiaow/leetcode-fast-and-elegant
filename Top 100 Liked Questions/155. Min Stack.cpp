//pop twice when minvalue pop 
//push twice when minvalue push
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }   
    void push(int x) {
        if(x<=smin)
        {
            s.push(smin);
            smin=x;
        }
        s.push(x);      
    }
    void pop() {
        int temp=s.top();
        s.pop();
        if(temp==smin)
        {
            smin=s.top();
            s.pop();
        }   
    }  
    int top() {
        return s.top();
    } 
    int getMin() {
        return smin;      
    }
private:
    stack<int>s;
    int smin=INT_MAX;
};
