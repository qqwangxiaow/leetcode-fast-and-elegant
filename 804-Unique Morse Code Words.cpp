//set
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> d = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_set<string>myset;
        for(auto word:words)
        {
            string code;
            for(int i=0;i<word.size();i++)
            {
                code+=d[word[i]-'a'];
            }
            myset.insert(code);
        }
        return myset.size();
    }
};