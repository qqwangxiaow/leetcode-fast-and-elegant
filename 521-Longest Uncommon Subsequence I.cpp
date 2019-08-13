/*傻子问题*/
class Solution {
public:
    int findLUSlength(string a, string b) {
        return a!=b?max(a.size(),b.size()):-1;
        
    }
};