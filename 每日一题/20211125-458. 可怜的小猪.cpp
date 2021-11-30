//n只猪m轮  猪最多有(m+1)^n种状态 则信息熵为n*log(m+1)  
//k桶水有1桶有毒有k种状态，其信息熵为log(k)
//n*log(m+1)>=log(k)时 可能 有最优方案
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return ceil(log(buckets) / log(minutesToTest / minutesToDie + 1));
    }
};