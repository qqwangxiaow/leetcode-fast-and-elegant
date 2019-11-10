//奇数位排序 偶数位排序 set中一个就是一个组
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string>classes;
        for(auto &s:A)
        {
            string odd;
            string even;
            int d=0;
            for(auto &ch:s)
            {
                if(d)
                    odd+=ch;
                else
                    even+=ch;
                d=1-d;
            }
            sort(odd.begin(),odd.end());
            sort(even.begin(),even.end());
            classes.insert(odd+even);
        }
        return classes.size();
        
    }
    
};