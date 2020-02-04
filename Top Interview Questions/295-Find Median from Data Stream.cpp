//time for insert and delete are O(logn) 
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pq1.empty()||num<pq1.top())
            pq1.push(num);
        else
            pq2.push(num);
        if(pq1.size()>(pq2.size()+1))
        {
            pq2.push(pq1.top());
            pq1.pop();
        }
        else if(pq1.size()+1<pq2.size())
        {
            pq1.push(pq2.top());
            pq2.pop();
        }
    }
    
    double findMedian() {
        if(pq1.size()==pq2.size())
            return pq1.empty()?0:(pq1.top()+pq2.top())/2.0;
        else
            return pq1.size()>pq2.size()?pq1.top():pq2.top();
        
    }
private:
    priority_queue<int>pq1;
    priority_queue<int,vector<int>,greater<int>>pq2;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */