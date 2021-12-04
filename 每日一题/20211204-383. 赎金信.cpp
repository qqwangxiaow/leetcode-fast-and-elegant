class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int array[26] = {0};
        for (auto &ch : ransomNote) {
            array[ch - 'a']++;
        }
        for (auto &ch : magazine) {
            array[ch - 'a']--;
        }
        for (auto ch : array) {
            if (ch >
             0) {
                return false;
            }
        }
        return true;
    }
};