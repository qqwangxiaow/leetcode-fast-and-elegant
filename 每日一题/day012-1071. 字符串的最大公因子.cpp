//为什么最大公约数就是解呢？
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2!=str2+str1)
            return "";
        return str1.substr(0,__gcd(static_cast<int>(str1.size()),static_cast<int>(str2.size())));
    }
};