class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        map<string, int>mymap;
        vector<string> ret;
        for (auto each : score) {
            ret.push_back(to_string(each));
        }
        sort(score.begin(), score.end(), greater<int>());
        for (int i = 0; i < score.size(); ++i) {
            mymap[to_string(score[i])] = i + 1;
        }
        for (auto &each : ret) {
            if (mymap[each] == 1) {
                each = "Gold Medal";
            } else if (mymap[each] == 2) {
                each = "Silver Medal";
            } else if (mymap[each] == 3) {
                each = "Bronze Medal";
            } else {
                each = to_string(mymap[each]);
            }
        }
        return ret;
    }
};