//maintain a decreasing deque
class MaxQueue {
public:
    MaxQueue() {
    }
    
    int max_value() {
        if(d.empty())
            return -1;
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
        {
            d.pop_front();
        }
        return temp;

    }
private:
    queue<int>q;
    deque<int>d;
};
