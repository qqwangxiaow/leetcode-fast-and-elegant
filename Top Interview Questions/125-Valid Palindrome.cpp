//直接判断 一次循环 isalnum判断是否abc或者数字 toupper转大写 tolower转小写
class Solution {
public:
    bool isPalindrome(string s) {
        for(int i=0,j=s.size()-1;i<j;i++,j--)
        {
            while(!isalnum(s[i])&&i<j) i++;
            while(!isalnum(s[j])&&i<j) j--;
            if(toupper(s[i])!=toupper(s[j]))
                return false;
        }
        return true;
    }
};