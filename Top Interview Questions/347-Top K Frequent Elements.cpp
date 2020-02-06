//map and priority_queue
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mymap;
        for(int i=0;i<nums.size();i++)
        {
            mymap[nums[i]]++;
        }
        vector<int>ret;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>mypq;
        for(auto it=mymap.begin();it!=mymap.end();it++)
        {
            mypq.push(make_pair(it->second,it->first));
            if(mypq.size()>k)
            {
                mypq.pop();
            }
        }
        while(!mypq.empty())   
        {
            ret.push_back(mypq.top().second);
            mypq.pop();
        }     
        return ret;
    }
};