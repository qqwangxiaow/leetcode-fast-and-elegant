//priority queue 注意大于size 要pop
//priority_queue<int,vector<int>,greater<int>>mypq;  pq默认大根堆 本题求最大k，要用小根堆 把最小堆都弹出去

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            mypq.push(nums[i]);
            if(mypq.size()>k)
                mypq.pop();
        }   
        kk=k;    
    }
    int add(int val) {
        mypq.push(val);
        if(mypq.size()>kk)
            mypq.pop();
        return mypq.top();
        
    }
private:
    priority_queue<int,vector<int>,greater<int>>mypq;
    int kk=0;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */