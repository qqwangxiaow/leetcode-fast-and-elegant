class Solution {
public:
    bool validPalindrome(string s) {
        if(s.size()<2)
            return true;
        int l=0,r=s.size()-1;
        if(isPalindrome(s,l,r))
            return true;
        while(l<r)
        {
            if(s[l]==s[r])
            {
                l++;
                r--;
            }
            else
            {
                return isPalindrome(s,l+1,r)||isPalindrome(s,l,r-1);
            }
        }
        return true;

    }
    bool isPalindrome(string s,int l,int r)
    {
        while(l<r)
        {
            if(s[l]!=s[r])
                return false;
            else
            {
                l++;
                r--;
            }
        }
        return true;
    }
};