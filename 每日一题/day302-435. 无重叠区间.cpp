//为什么要按照right排序呢？
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end(), [](const auto& v1,const auto&v2){
            return v1[1] < v2[1];
        });
        int right = intervals[0][1], count = 1, n = intervals.size();
        for(int i = 1; i < n; ++i){
            if(intervals[i][0] >= right){
                ++count;
                right = intervals[i][1];
            }
        }
        return n - count;
    }
};