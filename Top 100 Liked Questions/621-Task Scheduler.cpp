//excellent approach
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mymap;
        int count=0;
        for(auto e:tasks)
        {
            mymap[e]++;
            count=max(count,mymap[e]);
        }
        int ans=(count-1)*(n+1);
        for(auto e:mymap)
        {
            if(e.second==count)
                ans++;
        }
        return max((int)tasks.size(),ans);
        
    }
};