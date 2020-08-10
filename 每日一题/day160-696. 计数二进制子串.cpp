//counts统计连续的1 或者 0的个数，然后相加min
class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int>counts;
        int ptr=0;
        while(ptr<s.size())
        {
            char ch=s[ptr];
            int count=1;
            while(ptr+1<s.size()&&s[ptr]==s[ptr+1])
            {
                ptr++;
                count++;
            }
            counts.push_back(count);
            ptr++;
        } 
        int ret=0;
        for(int i=1;i<counts.size();i++)
        {
            ret+=min(counts[i],counts[i-1]);
        }
        return ret;
    }
};