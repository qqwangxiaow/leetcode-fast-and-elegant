//two pq
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(mypq1.empty()||num<mypq1.top())
        {
            mypq1.push(num);
        }
        else
        {
            mypq2.push(num);
        }
        int len1=mypq1.size(),len2=mypq2.size();
        while(len1-len2>1)
        {
            mypq2.push(mypq1.top());
            mypq1.pop();
            len1--;
            len2++;
        }
        while(len2-len1>0)
        {
            mypq1.push(mypq2.top());
            mypq2.pop();
            len2--;
            len1++;
        }

    }
    
    double findMedian() {
        if(mypq1.size()==mypq2.size())
        {
            return (double)(mypq1.top()+mypq2.top())/2.0;
        }
        else
        {
            return mypq1.top();
        }
    }
private:
    priority_queue<int>mypq1;
    priority_queue<int,vector<int>,greater<int>>mypq2;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */