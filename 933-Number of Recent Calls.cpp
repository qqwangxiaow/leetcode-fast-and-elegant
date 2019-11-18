//using queue;
class RecentCounter {
public:
    RecentCounter() {  
    }
    int ping(int t) {
        myque.push(t);
        while(myque.front()<t-3000)
            myque.pop();
        return myque.size();

    }
private:
    queue<int>myque;
};