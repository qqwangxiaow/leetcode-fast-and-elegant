class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int>ret;
        vector<pair<int,int>>myvec;
        map<int,int>mymap;
        for(auto num:arr)
            myvec.push_back({num,count_one(num)});
        sort(myvec.begin(),myvec.end(),[](const pair<int,int>&p1,const pair<int,int>&p2){
            return p1.second<p2.second||(p1.second==p2.second&&p1.first<p2.first);
        });
        for(auto one:myvec)
            ret.push_back(one.first);
        return ret;
    }
    int count_one(int n)
    {
        int count=0;
        while(n)
        {
            n&=(n-1);
            count++;
        }
        return count;
    }
};