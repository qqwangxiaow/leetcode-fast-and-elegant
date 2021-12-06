class Solution {
public:
    string truncateSentence(string s, int k) {
        stringstream ss(s);
        string temp, ret;

        while (k--) {
            ss >> temp;
            ret += temp;
            if (k > 0) {
                ret += " ";
            }
        }
        return ret;
    }
};