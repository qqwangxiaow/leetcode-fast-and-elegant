//O(n)
class Solution {
public:
    bool validPalindrome(string s) {
        if(s.size()<=1)
            return true;
        int l=0,r=s.size()-1;
        if(ispalindrome(s,l,r))
            return true;
        while(l<r)
        {
            if(s[l]!=s[r])
            {
                return ispalindrome(s,l+1,r)||ispalindrome(s,l,r-1);
            }
            l++;
            r--;
        }
        return true;    
        
    }
    bool ispalindrome(string s,int l,int r)
    {
        while(l<r)
        {
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};