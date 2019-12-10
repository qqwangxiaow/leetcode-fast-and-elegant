//using two heap
//first heap keep half max value,second keep half min value,if size() not balance , banlance
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {  
    }
    
    void addNum(int num) {
        if(firstQ.empty()||num<firstQ.top())
            firstQ.push(num);
        else
            secQ.push(num);
        if(firstQ.size()>(secQ.size()+1))
        
            secQ.push(firstQ.top
            firstQ.pop();
        }
        else if(firstQ.size()+1<secQ.size()) //pay attention!!! if(firstQ.size()<secQ.size()-1) will overflow
        {
            firstQ.push(secQ.top());
            secQ.pop();
        }
    }
    
    double findMedian() {
        if(firstQ.size()==secQ.size())
        {
            return firstQ.empty()?0:(firstQ.top()+secQ.top())/2.0;
        }
        else
        {
            return firstQ.size()>secQ.size()?firstQ.top():secQ.top();
        }
        
    }
private:
    priority_queue<int>firstQ;
    priority_queue<int,std::vector<int>,std::greater<int>>secQ;
};
