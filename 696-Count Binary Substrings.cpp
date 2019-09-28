//判断相等 pre记录之前重复了多少次 cur记录现在重复了多少次 pre>=cur 则count++;
class Solution {
public:
    int countBinarySubstrings(string s) {
        int count=0,pre=1,cur=1;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==s[i-1])
            {
                cur++;
            }
            else
            {
                pre=cur;
                cur=1;
            }
            if(pre>=cur)
            {
                count++;
            }
        }
        return count;
        
        
    }
};