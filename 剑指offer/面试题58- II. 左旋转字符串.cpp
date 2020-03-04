class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(),s.end());
        reverse(s.begin(),s.end()-n);
        reverse(s.end()-n,s.end());
        return s;
    }
};