//就三种情况 1.size不等 2.相等有重复 3.不等 交换位置相等
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size())
            return false;
        else if(A == B)
        {
            set<char> myset;
            for (int i = 0; i < A.size(); i++)
            {
                myset.insert(A[i]);
            }
            if (myset.size() < A.size())
                return true;
            else
                return false;    
        } else {
            vector<int> ret;
            for (int i=0; i<A.size(); i++)
            {
                if(A[i] != B[i])
                    ret.push_back(i);
            }
            if (ret.size() != 2)
            {
                return false;
            } else {
                swap(A[ret[0]], A[ret[1]]);
                if (A == B)
                    return true;
                else
                    return false;
            }
        }  
    }
};