//思想用bit算每个字符的交集 保存到map 每个字符相同的只要算最长的
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int mask = 0;
        unordered_map<int, int>mymap;
        for (auto word : words) {
            mask = 0;
            for (auto ch : word) {
                mask |= 1 << (ch - 'a');
            }
            if (mymap.find(mask) == mymap.end() || mymap[mask] < word.size()) {
                mymap[mask] = word.size();
            }
        }
        int ret = 0;
        for (auto [mask1, _] : mymap) {
            for (auto [mask2, _] : mymap) {
                if ((mask1 & mask2) == 0) {
                    ret = max(ret, mymap[mask1] * mymap[mask2]);
                }
            } 
        }
        return ret;

    }
};