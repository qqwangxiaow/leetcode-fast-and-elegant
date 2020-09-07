//这里是大根堆 保存count最大的
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mymap;
        for(auto num:nums)
        {
            mymap[num]++;
        }
        auto lambda=[](const pair<int,int>&p1,const pair<int,int>&p2){
            return p1.second<p2.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(lambda)>mypq(lambda);
        for(auto it=mymap.begin();it!=mymap.end();it++)
        {
            mypq.push(make_pair(it->first,it->second));
        }
        vector<int>ret;
        while(k--)
        {
            ret.push_back(mypq.top().first);
            mypq.pop();
        }
        return ret;
    }
};