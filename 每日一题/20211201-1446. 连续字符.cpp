class Solution {
public:
    int maxPower(string s) {
        if (s.size() == 0) {
            return false;
        }
        int count = 1, ret = 1;
        char ch = s[0];
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == ch) {
                count++;
                ret = max(ret, count);
            } else {
                ch = s[i];
                count = 1;
            }
        }
        return ret;
    }
};