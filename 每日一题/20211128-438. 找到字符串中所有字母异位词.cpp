//优化滑动窗口 算diff
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> pv(26,0);
        vector<int> ret;
        int diff = 0;
        if (s.size() < p.size())
            return ret;
        for (int i = 0; i < p.size(); i++) {
            pv[s[i] - 'a']++;
            pv[p[i] - 'a']--;
        }
        for (int i = 0; i < pv.size(); i++) {
            diff += pv[i] != 0 ? 1 : 0;
        }
        if (diff == 0) {
            ret.emplace_back(0);
        }
        int p_len = p.size();
        for (int i = 0; i + p_len < s.size(); i++) {
            if (pv[s[i] - 'a'] == 1) {
                diff--;
            } else if (pv[s[i] - 'a'] == 0) {
                diff++;
            }
            pv[s[i] - 'a']--;
            if(pv[s[i + p_len] - 'a'] == -1) {
                diff--;
            } else if (pv[s[i + p_len] - 'a'] == 0){
                diff++;
            }
            pv[s[i + p_len] - 'a']++;
            if (diff == 0) {
                ret.push_back(i + 1);
            }
        }
        return ret;
    }
};