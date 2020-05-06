//dp[i]=min(dp[i-1]+cost[1],dp[i-7]+cost[1],dp[i-30]+cost[2])
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        this->costs=costs;
        for (int d: days) {
            myset.insert(d);
        }
        memset(memo,-1,sizeof(memo));
        return dp(1);
    }
    int dp(int i)
    {
        if(i>365)
            return 0;
        if(memo[i]!=-1)
            return memo[i];
        if(myset.count(i))
        {
            memo[i]=min(dp(i+1)+costs[0],min(dp(i+7)+costs[1],dp(i+30)+costs[2]));
        }
        else
            memo[i]=dp(i+1);
        return memo[i];
    }
private:
    int memo[366];
    vector<int>costs;
    unordered_set<int>myset;
};