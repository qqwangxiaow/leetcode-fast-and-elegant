//N+1number
\class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int>myset;
        for(int a:A)
        {
            if(myset.count(a))
                return a;
            myset.insert(a);
        }
        return -1;
    }
};