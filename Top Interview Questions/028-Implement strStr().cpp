//brute force 
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle=="")
            return 0;
        int m=haystack.size(),n=needle.size();
        for(int i=0;i<m;i++)
        {
            int j=0;
            for(;j<n;j++)
            {
                if(haystack[i+j]!=needle[j])
                    break;
            }
            if(j==n)
            {
                return i;
            }
        }
        return -1;
    }
};