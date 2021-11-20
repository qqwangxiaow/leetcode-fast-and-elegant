//hash 注意只能是key 和 key + 1 的数字 所以简单
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mymap;
        int ret = 0;
        for (const auto& each : nums) {
            mymap[each]++;
        }
        for (auto [key, value] : mymap) {
            if (mymap.count(key + 1)) {
                ret = max(ret, value + mymap[key + 1]);
            }
        }
        return ret;
    }
};