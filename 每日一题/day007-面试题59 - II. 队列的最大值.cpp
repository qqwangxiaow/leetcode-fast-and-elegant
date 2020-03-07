//maintain increase deque
class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(d.empty())
            return -1;
        else
            return d.front();
    }
    
    void push_back(int value) {
        q.push(value);
        while(!d.empty()&&d.back()<value)
        {
            d.pop_back();
        }
        d.push_back(value);
    }
    
    int pop_front() {
        if(q.empty())
            return -1;
        int temp=q.front();
        q.pop();
        if(temp==d.front())
            d.pop_front();
        return temp;
    }
private:
    queue<int>q;
    deque<int>d;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */